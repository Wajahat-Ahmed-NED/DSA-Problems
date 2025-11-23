// function Todo() {
//     const [input, setInput] = useState("");
//     const [items, setItems] = useState([]);

//     const add = () => {
//         setItems([...items, input]);
//         setInput("");
//     };

//     return (
//         <>
//             <input value={input} onChange={e => setInput(e.target.value)} />
//             <button onClick={add}>Add</button>
//             <ul>
//                 {items.map((t, i) => <li key={i}>{t}</li>)}
//             </ul>
//         </>
//     );
// }

import React, { useState } from 'react';

function Todo() {
    const [input, setInput] = useState("");
    const [items, setItems] = useState([]);
    const add = () => {
        setItems([...items, input]);
        setInput("");
    }

    return (
        <>
            <input value={input} onChange={(e) => setInput(e.target.value)}></input>
            <button onClick={add}>Add</button>
            <ul>
                {
                    items?.map((x, i) => <li key={i}>{x}</li>)
                }
            </ul>
        </>
    )
}

export default Todo;