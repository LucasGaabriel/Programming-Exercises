package org.example

fun main() {
    val str = "Desenvolvimento Mobile"
    val idx = 3
    println("- Tamanho: ${str.length}")
    println("- Posicao [$idx]: ${str[idx]}")
    println("- Substring de 3 a 7: ${str.substring(3, 7)}")
    println("- Substring de 3 pra frente: ${str.substring(3)}")
    println("- Trocando nomes: ${str.replace("Mobile", "Móvel", ignoreCase = true)}")
    println("- Quebrando a string: ${str.split(" ")}")
    println()

    println(str.uppercase())
    println(str.lowercase())
    println("   Teste String. ".trim(' '))
}
