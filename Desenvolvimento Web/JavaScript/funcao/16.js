function calculadora(op1, operacao, op2){
    switch(operacao){
        case "+":
            console.log(op1+op2)
            break;
        case "-":
            console.log(op1-op2)
            break;
        case "*":
            console.log(op1*op2)
            break;
        case "/":
            console.log(op1/op2)
            break;
        default:
            console.log("Operação Inválida.")
    }
}

calculadora(25, '+', 15)
calculadora(7, "/", 14)
calculadora(9, "*", 9)
calculadora(10, "-", 15)
calculadora(9, "^", 3)