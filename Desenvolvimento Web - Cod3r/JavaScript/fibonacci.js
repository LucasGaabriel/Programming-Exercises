function pertenceFibonacci(numero){
    if(numero < 0)
        return false
    
    let fib = [0, 1]

    for(let i=2; fib[fib.length-1] < numero; i++){
        fib[i] = fib[i-1] + fib[i-2]
    }

    if(fib.includes(numero))
        return true
    else
        return false
}

console.log(pertenceFibonacci(0))
console.log(pertenceFibonacci(1))
console.log(pertenceFibonacci(13))
console.log(pertenceFibonacci(14))
console.log(pertenceFibonacci(35))
console.log(pertenceFibonacci(610))
console.log(pertenceFibonacci(986))