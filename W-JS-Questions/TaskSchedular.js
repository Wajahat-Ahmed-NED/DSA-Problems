class TaskSchedular {
    constructor(concurrency = 2) {
        this.concurrency = Number(concurrency);
        this.runningTasks = 0;
        this.__waitingQueue = []
    }
    getNextTask() {
        if (this.runningTasks < this.concurrency && this.__waitingQueue.length > 0) {
            const nextTask = this.__waitingQueue.shift();
            nextTask();
        }
    }
    addTask(task) {
        return new Promise((resolve, reject) => {
            const __taskRunner = async () => {
                this.runningTasks += 1;
                try {
                    const result = await task();
                    console.log(result);
                    resolve(result)
                } catch (error) {
                    console.log(error)
                    reject(error)
                }
                finally {
                    this.runningTasks -= 1;
                    this.getNextTask();
                }
            }

            if (this.runningTasks < this.concurrency) {
                __taskRunner()
            }
            else {
                this.__waitingQueue.push(__taskRunner)
            }
        })
    }


}


const schedular = new TaskSchedular(4);
schedular.addTask(
    () => new Promise(res => setTimeout(() => res("timeout 1"), 5000))
)
schedular.addTask(
    () => new Promise(res => setTimeout(() => res("timeout 2"), 5000))
)
schedular.addTask(
    () => new Promise(res => setTimeout(() => res("timeout 3"), 5000))
)
schedular.addTask(
    () => new Promise(res => setTimeout(() => res("timeout 4"), 5000))
)