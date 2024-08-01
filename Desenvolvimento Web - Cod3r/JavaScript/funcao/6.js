function jurosSimples(capital_inicial, juros, tempo_aplicação){
    return (capital_inicial * (1 + juros * tempo_aplicação)).toFixed(2)
}

function jurosCompostos(capital_inicial, juros, tempo_aplicação){
    return (capital_inicial * (1 + juros)**tempo_aplicação).toFixed(2)
}

let capital_inicial = 100
let juros = 0.3
let tempo_aplicação = 12

console.log(jurosSimples(capital_inicial, juros, tempo_aplicação))
console.log(jurosCompostos(capital_inicial, juros, tempo_aplicação))