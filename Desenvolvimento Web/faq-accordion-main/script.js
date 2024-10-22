const questions = document.querySelectorAll('.question');
const descriptions = document.querySelectorAll('.description');

function disableAllDescriptions() {
    descriptions.forEach((description) => {
        description.classList.add('deactivated');
    });
}

function disableAllDescriptionsExcept(d) {
    descriptions.forEach((description) => {
        if (description !== d) {
            const icon = description.previousElementSibling.children[0];
            description.classList.remove('activated');
            description.classList.add('deactivated');
            icon.src = 'assets/images/icon-plus.svg';
        }
    });
}

function toggleIcon(question) {
    const icon = question.children[0]
    let attr = icon.getAttribute('src');
    attr = attr == 'assets/images/icon-plus.svg' ? 'assets/images/icon-minus.svg' : 'assets/images/icon-plus.svg';
    icon.src = attr
}

function showDescriptionAndDisableOthers(e) {
    const question = e.currentTarget;
    const description = question.nextElementSibling;

    disableAllDescriptionsExcept(description);
    toggleIcon(question);

    description.classList.toggle('activated');
    description.classList.toggle('deactivated');
}

disableAllDescriptions();
questions.forEach(q => q.addEventListener('click', showDescriptionAndDisableOthers));