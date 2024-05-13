function fatorial(num){
    if(num == 0){
        console.log(1)
        return;
    }
    
    let result = num

    for(let i=1; i<num; i++){
        result *= i
    }

    console.log(result)
}

fatorial(0)
fatorial(1)
fatorial(2)
fatorial(5)
fatorial(10)