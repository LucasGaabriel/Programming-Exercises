const colors = [
    "aqua", "black", "blue", "fuchsia", "gray",
    "green", "lime", "maroon", "navy", "olive", 
    "purple", "red", "silver", "teal", "white", "yellow"
]

function changeColor() {
    const color = document.getElementById('color');
    const body = document.body;

    let randomColor = colors[Math.floor(Math.random() * colors.length)];

    // Capitalize the first letter
    randomColor = randomColor.charAt(0).toUpperCase() + randomColor.slice(1);

    color.innerHTML = randomColor;
    color.style.color = randomColor;
    body.style.backgroundColor = randomColor;
}

changeColor();
const btn = document.getElementById('btn');
btn.addEventListener('click', changeColor);