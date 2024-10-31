package org.example

fun main() {
    var data = mutableListOf<Int>(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
    var temp: Any

    // Retorna true se a coleção tiver pelo menos 1 elemento dentro dela
    temp = data.any()
    println("- Possui algum elemento? $temp")

    // Retorna a quantidade de elementos na coleção
    temp = data.count()
    println("- Quantidade de elementos: $temp")

    // Obtendo o primeiro elemento da coleção (não remove o elemento da coleção)
    temp = data.first()
    println("- Primeiro elemento: $temp")

    // Obtendo os N primeiros elementos de uma coleção
    temp = data.take(3)
    println("- Os 3 primeiros elementos: $temp")

    // Obtendo o último elemento da coleção (não remove o elemento da coleção)
    temp = data.last()
    println("- Ultimo elemento: $temp")

    // Obtendo os N últimos elementos de uma coleção
    temp = data.takeLast(3)
    println("- Os 3 ultimos elementos: $temp")

    // Se a lista estiver vazia ao acessar um elemento,
    // é retornado uma exceção: NoSuchElementException
    // Para solucionar isso de maneira rápida (sem tratar a exceção)
    // podemos usar: firstOrNull ou lastOrNull
    var vazia = listOf<Int>()
    println("- Primeiro de lista vazia: ${vazia.firstOrNull()}")

    // Somando os valores da lista se ela for numérica
    temp = data.sum()
    println("- Soma dos elementos: $temp")

    // Calculando a média de uma coleção se ela for numérica
    temp = data.average()
    println("- Media: $temp\n")

    val nomes = listOf("Goku", "Gohan", "Trunks", "Vegeta")

    // Usando o método sumOf para definir uma regra para a soma
    // Aqui precisamos passar um predicado, onde é definido a regra
    // o it se refere ao próprio objeto que chama o método
    temp = nomes.sumOf {
        it.length
    }
    println("- Soma dos tamanhos: $temp")

    // O mesmo vale para minOf e maxOf
    temp = nomes.maxOf { it.length }
    println("- Maior nome: $temp")

    temp = nomes.minOf { it.length }
    println("- Menor nome: $temp\n")

    // Fazendo uma filtragem usando o método filter
    // Ex: selecionar todos os nomes com mais de 5 caracteres
    temp = nomes.filter { it.length > 5 }
    println("- Nomes com mais de 5 caracteres: $temp")

    // Podemos usar predicados com any e count também:
    temp = nomes.any { it.length > 5 }
    println("- Tem alguem com mais de 5 caracteres? $temp")

    temp = nomes.count { it.length > 5 }
    println("- Quantos nomes tem mais de 5 caracteres? $temp\n")

    // Podemos percorrer cada elemento da lista para aplicar alguma regra
    nomes.forEach { print("Tamanho de ${it}: ${it.length} | ") }
    println()

    // Também podemos combinar métodos
    nomes.filter { it.length > 5 }.forEach { print("Maiores que 5 $it | ") }
    println()

    temp = nomes.map { it.length }
    println("- Map de strings para tamanhos: $temp\n")

    data = mutableListOf(1, 2, 2, 2, 3, 1, 3, 4, 4, 5, 1, 1, 2, 6, 7, 10, 2, 28, 20)

    // Obtendo apenas os valores distintos de data
    temp = data.distinct()
    println("- Valores distintos: $temp")

    // Se a coleção for uma estrutura diferente, podemos usar o distinctBy e definir
    // e utilizar uma regra usando o predicado. Nesse casos, vamos distinguir os
    // nomes pelo tamanho:
    temp = nomes.distinctBy { it.length }
    println("- Nomes com tamanhos diferentes: $temp\n")

    temp = data.sorted()
    println("- Dados ordenados ascendente: $temp")

    temp = data.sortedDescending()
    println("- Dados ordenados descendente: $temp")

    temp = nomes.sortedBy { it.length }
    println("- Lista ordenada por tamanho: $temp")

    // Reverter uma coleção com reversed
    temp = data.reversed()
    println("- Dados invertidos: $temp")
}
