package org.example

fun main() {
    var set1: MutableSet<Int>
    var set2 = mutableSetOf<Int>()
    var set3 = mutableSetOf("Vitoria", "Colatina", "Pancas", "Vitoria")
    var set4: MutableSet<Any> = mutableSetOf(1, 2, "A", true)

    println("- set3: $set3")
    println("- set4: $set4")

    set3.add("Cariacica")
    set3.remove("Pancas")
    println("- set3: $set3")
    println("- Numero de elementos set3: ${set3.size}")

    val resp = set3.contains("Pancas")
    println("- Contém Pancas?: $resp")
}