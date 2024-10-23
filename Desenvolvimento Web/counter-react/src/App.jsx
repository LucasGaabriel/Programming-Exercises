import React, { useState } from 'react';
import './App.css';

function App() {
  const [count, setCount] = useState(0);

  return (
    <div className="main">
      <h1 className="title">Counter</h1>
      <h3 className="counter">{count}</h3>
      <button className="btn" onClick={() => setCount(count + 1)}>Click</button>
    </div>
  )
}

export default App;
