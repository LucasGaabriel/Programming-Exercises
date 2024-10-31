package org.example

fun somaTres(num: Int, somaDois: (a: Int, b: Int) -> Int) {
    val res = num + somaDois(10, 20)
    println("- Resultado: $res")
}

fun main() {
    val funcLam = { a: Int, b: Int ->
        val soma = a + b
        soma // Retorno da Função
    }
    println("- Soma de 5 e 6: ${funcLam(5, 6)}")

    val funcLam2 = {
        val a = 2
        println("- Essa é uma funcao lambda sem parametro! Ela tem uma variavel a = $a")
    }
    funcLam2()

    val funcLam3 = { a: Int, b: Int ->
        val soma = a + b
        soma
    }
    somaTres(10, funcLam3)

    // Lambda aninhado
    somaTres(10) { a: Int, b: Int ->
        val soma = a + b
        soma
    }
}
