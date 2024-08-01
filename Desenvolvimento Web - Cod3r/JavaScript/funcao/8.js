function resultadoJogo(pontuacoes_str){
    let pontuacoes = pontuacoes_str.split(" ").map(val => Number(val))

    let maiorPontuacao = pontuacoes[0]
    let piorPontuacao = pontuacoes[0]
    let piorPontuacao_idx = -1
    let bateuRecorde = 0

    for(let i in pontuacoes){
        if(i == 0) continue
        
        if(pontuacoes[i] > maiorPontuacao){
            maiorPontuacao = pontuacoes[i]
            bateuRecorde++
        }

        if(pontuacoes[i] < piorPontuacao){
            piorPontuacao = pontuacoes[i]
            piorPontuacao_idx = i
        }

    }

    return [bateuRecorde, parseInt(piorPontuacao_idx) + 1]
}

console.log(resultadoJogo("10 20 20 8 25 3 0 30 1"))