function inverter(str){
    let strInversa = ""
    for(let i=str.length-1; i>=0; i--){
        strInversa += str[i]
    }
    return strInversa
}

console.log(inverter("Olá"))
console.log(inverter("Inverso"))
console.log(inverter("osrevni"))
console.log(inverter("Teste"))