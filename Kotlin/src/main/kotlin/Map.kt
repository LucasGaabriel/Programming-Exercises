package org.example

fun main() {
    var map1: MutableMap<String, Int>
    var map2 = mutableMapOf<String, Float>()

    var map3 = mutableMapOf(Pair("Goku", 10), Pair("Gohan", 9), Pair("Pam", 7))
    var map4: MutableMap<String, Any> = mutableMapOf(Pair("A", 10), Pair("B", true))

    println("- map3: $map3")
    println("- map4: $map4\n")

    var notas = mutableMapOf<String, Int>(Pair("Goku", 10), Pair("Gohan", 9), Pair("Pam", 7))
    println("- Notas da turma: $notas")

    // Atualizando a nota de Gohan
    notas.set("Gohan", 8)

    // Adicionando novo Par:
    notas.set("Vegeta", 6) // método 1
    notas["Chichi"] = 10   // método 2
    println("- Notas atualizadas: $notas\n")

    println("- Todos os pares: ${notas.entries}")
    println("- Todas as chaves: ${notas.keys}")
    println("- Todos os valores: ${notas.values}\n")

    notas.remove("Vegeta")
    notas.remove("Piccolo")
    println("- Notas: $notas")

    println("Contém Freeza? ${notas.contains("Freeza")}")

    notas.clear()
    println("- Notas: $notas")
}
