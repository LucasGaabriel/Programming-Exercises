package org.example

fun main() {
    // IMUTÁVEIS
    val lst1: List<Int> // Declara uma lista de inteiros
    val lst2 = listOf<Float>() // Cria uma lista de float vazia
    val lst3 = listOf(1, 2, 3, 4) // Cria uma lista inferindo o tipo a partir dos dados
    val lst4: List<Any> = listOf(1, 2f, '3', "Mobile") // Declara e instancia a lista

    // MUTÁVEIS
    val mut_lst1: MutableList<Int> // Declara uma lista mutável de inteiros
    val mut_lst2 = mutableListOf<Int>() // Cria uma lista mutável de inteiros vazia
    val mut_lst3 = mutableListOf(1, 2, 3, 4) // Cria uma lista mutável inferindo o tipo a partir dos dados
    val mut_lst4: MutableList<Int> = mutableListOf(1, 2, 3, 4) // Declara e instancia a lista mutável

    val list = mutableListOf<Int>(1, 2, 3, 4)
    println("- Posicao 0: ${list[0]}")
    println("- Tamanho: ${list.size}\n")

    list.add(20)
    list.add(30)
    println("- Print: $list\n")

    list.remove(30) // remove o elemento
    list.removeAt(0) // remove a posição
    println("- Print: $list\n")

    println("- Contem 2? ${list.contains(2)}\n")

    list.clear()
    println("- Print: $list")
}
