/*
Notas Disponíveis:
R$ 100
R$ 50
R$ 10
R$ 5
R$ 1.
*/

function montaString(notas100, notas50, notas10, notas5, notas1){
    let strResult = ""

    if(notas100 > 0){
        strResult += `${notas100} nota(s) de R$ 100. `
    }

    if(notas50 > 0){
        strResult += `${notas50} nota(s) de R$ 50. `
    }

    if(notas10 > 0){
        strResult += `${notas10} nota(s) de R$ 10. `
    }

    if(notas5 > 0){
        strResult += `${notas5} nota(s) de R$ 5. `
    }

    if(notas1 > 0){
        strResult += `${notas1} nota(s) de R$ 1. `
    }

    return strResult
}

function notasNecessarias(valor){
    let notas100 = 0
    let notas50 = 0
    let notas10 = 0
    let notas5 = 0
    let notas1 = 0

    while(valor >= 100){
        notas100 += 1
        valor -= 100
    }

    while(valor >= 50){
        notas50 += 1
        valor -= 50
    }

    while(valor >= 10){
        notas10 += 1
        valor -= 10
    }

    while(valor >= 5){
        notas5 += 1
        valor -= 5
    }

    while(valor >= 1){
        notas1 += 1
        valor -= 1
    }

    return montaString(notas100, notas50, notas10, notas5, notas1)
}

console.log(notasNecessarias(135))
console.log(notasNecessarias(23))
console.log(notasNecessarias(100))
console.log(notasNecessarias(3))
console.log(notasNecessarias(999))