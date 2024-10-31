package org.example

fun soma(numA: Int, numB: Int = 10): Int {
    return numA + numB
}

fun quadrado(v: Float) = v * v

fun semRetorno() {
    println("Essa função não tem retorno")
}

fun semRetornoUnit(): Unit {
    println("Essa função também não tem retorno")
}

fun saudacao() {
    println("Ola, usuário!")
}

fun saudacao(nome: String) {
    println("Ola, $nome!")
}

fun saudacao(nome: String, local: String) {
    println("Ola, $nome! Hoje está 23º em $local")
}

fun media(vararg valores: Float): Float {
    var soma = 0f
    for (v in valores) {
        soma += v
    }
    return soma / valores.size
}

// Utilizando Any
fun imprime(a: Any) {
    println("- Valor passado: $a")
}

// Utilizando Generics
fun <T> imprimeT(a: T) {
    println("- Valor passado: $a")
}

fun imprimeTipo(vararg valores: Any) {
    for (v in valores) {
        if (v is Int) println("- Tipo inteiro: $v")
        else if (v is Float) println("- Tipo float: $v")
        else if (v is Double) println("- Tipo double: $v")
        else if (v is String) println("- Tipo string: $v")
        else println("- Outro tipo: $v")
    }
}

fun criaUsuario(): Nothing {
    TODO("Precisamos implementar essa função")
    // Vai subir a exceção kotlin.NotImplementedError
}

fun main() {
    semRetorno()
    semRetornoUnit()
    println()

    println(soma(3, 5))
    println(soma(3))
    println()

    println(quadrado(5f))
    println()

    saudacao()
    saudacao("Lucas")
    saudacao("Lucas", "Vitória")
    println()

    println(media(5.6f, 8.9f, 4.7f, 9.8f))
    println()

    imprime(5 * 5)
    imprimeT(5 * 5)
    println()

    imprimeTipo(5.6f, "Olá", 19, 'A', 13L, 94.2)
    println()

    criaUsuario()
}
