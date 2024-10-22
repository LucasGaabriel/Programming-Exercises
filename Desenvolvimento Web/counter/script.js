const buttons = document.querySelectorAll('button');
const counter = document.querySelector('#counter');

function changeCounter(event) {
    const button = event.currentTarget.textContent.toLowerCase();

    if (button === 'decrease') {
        counter.textContent--;
    } else if (button === 'increase') {
        counter.textContent++;
    } else {
        counter.textContent = 0;
    }

    // Change the color of the counter
    if (counter.textContent < 0) {
        counter.style.color = 'red';
    } else if (counter.textContent > 0) {
        counter.style.color = 'green';
    } else {    
        counter.style.color = 'black';
    }

}

buttons.forEach((button) => {
    button.addEventListener('click', changeCounter);
});