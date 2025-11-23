const data = require('./input.json');
console.log('data:', data)

function flattenTask(tasks, parentInfo) {
    const result = [];

    if (Array.isArray(tasks)) {
        for (const task of tasks) {
            console.log(task)
            const date = new Date(task?.dueDate)
            console.log(date)
            if (task?.title && !isNaN(date?.getTime())) {
                result.push({
                    ...task,
                    company: parentInfo.company,
                    team: parentInfo.team,
                    member: parentInfo.member
                }
                )
            }
        }
    }
    else if (tasks && typeof tasks === 'object') {
        const date = new Date(tasks.dueDate)
        if (tasks.title && !isNaN(date.getTime())) {
            result.push({
                ...tasks,
                company: parentInfo.company,
                team: parentInfo.team,
                member: parentInfo.member
            }
            )
        }
    }

    return result;
}

function manipulateData(data) {

    const result = [];

    data?.map(e =>
        e?.teams?.map(x =>
            x.members?.map(y => {
                result.push(...flattenTask(y.tasks, { company: e.name, team: x.name, member: y.name }))
            })))


    result.sort((a, b) => (new Date(a.dueDate) - new Date(b.dueDate) || b.priority - a.priority));

    const map = new Map();
    const finalResult = [];
    for (let i = 0; i < result.length; i++) {
        if (!map.has(result[i].id)) {
            map.set(result[i].id, result[i])
            finalResult.push(result[i]);
        }
    }

    return finalResult;
}

// Our code works fine for this input
console.log(manipulateData(data))



















// More professional senior level code given by ChatGPT

function flattenTasks(tasks, parent) {
    const result = [];

    // If it's null/undefined → skip
    if (!tasks) return result;

    // If tasks is an array → handle each item
    if (Array.isArray(tasks)) {
        for (const t of tasks) {
            result.push(...flattenTasks(t, parent)); // recursion
        }
        return result;
    }

    // If it's a single object
    if (typeof tasks === "object") {
        const date = new Date(tasks.dueDate);

        if (tasks.title && !isNaN(date.getTime())) {
            result.push({
                ...tasks,
                company: parent.company,
                team: parent.team,
                member: parent.member
            });
        }
    }

    return result;
}


function manipulateData(data) {
    const result = [];

    // Traversing companies → teams → members
    for (const company of data) {
        for (const team of company.teams || []) {
            for (const member of team.members || []) {
                result.push(
                    ...flattenTasks(member.tasks, {
                        company: company.name,
                        team: team.name,
                        member: member.name
                    })
                );
            }
        }
    }

    // Sort tasks
    result.sort((a, b) =>
        new Date(a.dueDate) - new Date(b.dueDate) ||
        b.priority - a.priority
    );

    // Dedupe by task id
    const final = Array.from(
        new Map(result.map(t => [t.id, t])).values()
    );

    return final;
}

module.exports = manipulateData;
