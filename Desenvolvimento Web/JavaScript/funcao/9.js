function arredondarNota(nota){
    if(nota < 38){
        return nota
    }

    proxMult = nota
    if(nota % 5 == 0)
        return nota

    while(true){
        proxMult++

        if(proxMult % 5 == 0)
            break;
    }

    if(nota - proxMult < 3)
        return proxMult
    else
        return nota

}

console.log(arredondarNota(84))
console.log(arredondarNota(29))