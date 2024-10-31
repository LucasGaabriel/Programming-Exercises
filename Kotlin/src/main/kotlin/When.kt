package org.example

fun main() {
    val mes = 1
    when(mes){
        1 -> {
            println("Janeiro")
        }
        2 -> {
            println("Fevereiro")
        }
        else -> {
            println("Outro mês")
        }
    }

    val mesStr = when(mes){
        1 -> "Janeiro"
        2 -> "Fevereiro"
        else -> "Outro mês"
    }
    println(mesStr)

    val valido = when(mes){
        in 1 .. 12 -> true
        else -> false
    }
    println(valido)
}
