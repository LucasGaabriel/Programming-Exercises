const questions = document.querySelectorAll('.question');
const descriptions = document.querySelectorAll('.description');

function disableAllDescriptions() {
    descriptions.forEach((description) => {
        description.classList.add('deactivated');
    });
}

function disableAllDescriptionsExcept(d) {
    descriptions.forEach((description) => {
        if (description !== d)
            description.classList.add('deactivated');
    });
}

function showDescriptionAndDisableOthers(e) {
    const question = e.currentTarget;
    const description = question.nextElementSibling;

    disableAllDescriptionsExcept(description);

    description.classList.toggle('activated');
    description.classList.toggle('deactivated');
}

disableAllDescriptions();
questions.forEach(q => q.addEventListener('click', showDescriptionAndDisableOthers));