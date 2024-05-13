function inverso(x){
    if(typeof(x) == "boolean"){
        console.log(!x)
    }
    else if(typeof(x) == "number"){
        console.log(-x)
    }
    else {
        console.log(`Boolean ou Number esperado. O valor recebido é do tipo '${typeof x}'`)
    }
}

inverso(1)
inverso(true)
inverso(false)
inverso("a")
inverso("Hello")
inverso('a')
inverso(Math.PI)