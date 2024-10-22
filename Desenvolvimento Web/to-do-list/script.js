const completed_tasks = document.querySelector('#completed-tasks');
const total_tasks = document.querySelector('#total-tasks');
const base_list_item = document.querySelector('.todo').innerHTML;
document.querySelector('#list').innerHTML = '';

// Atualiza tasks completas e totais
function updateCompletedAndTotalTasks() {
    const list_todos = document.querySelectorAll('.todo');
    const total = list_todos.length;
    const completed = Array.from(list_todos).filter(todo => todo.querySelector('input').checked).length;

    total_tasks.textContent = total;
    completed_tasks.textContent = completed;
}

// Atualiza tasks completas ao clicar no checkbox
function atualizarTasks() {
    const list_todos = document.querySelectorAll('.todo');
    updateCompletedAndTotalTasks();

    list_todos.forEach(todo => {
        const checkbox = todo.querySelector('input');
        checkbox.addEventListener('change', () => {
            updateCompletedAndTotalTasks();
        });
    });
}

// Adicionar nova task
function habilitarBotaoNewTask() {
    const new_todo = document.querySelector("#new-todo")
    new_todo.querySelector("#btn-add").addEventListener("click", () => {
        const todo = document.createElement("li");
        todo.classList.add("todo");
        todo.innerHTML = base_list_item;

        const todo_description = new_todo.querySelector("#new-todo>input").value;
        if (todo_description === '' || todo_description === null) {
            return;
        }

        todo.querySelector(".form-control").textContent = todo_description
        document.querySelector("#todo-list").appendChild(todo);
        atualizarTasks();

        // Associa o botão de remover a cada nova task
        todo.querySelector(".btn-remove").addEventListener("click", () => {
            todo.remove();
            updateCompletedAndTotalTasks();
        });
    });
}

// Limpa todas as tasks completas
document.querySelector("#btn-clear-completed").addEventListener("click", () => {
    // Envia notificação de confirmação de exclusao das tasks completas
    if (!confirm("Você tem certeza que deseja excluir todas as tarefas completas?")) return;

    const list_todos = document.querySelectorAll('.todo');
    list_todos.forEach(todo => {
        if (todo.querySelector('input').checked) {
            todo.remove();
            updateCompletedAndTotalTasks();
        }
    });
});

habilitarBotaoNewTask();
atualizarTasks();