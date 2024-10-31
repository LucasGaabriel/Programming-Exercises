package org.example

fun main() {
    var s: String? = null
    println(s?.length) // Se s é null, retorna null
    //println(s!!.length) // Força exceção se for null

    val p: String? = null
    p ?: println("- Variável é Nula") // Operador Elvis

    val str: String? = null
    str?.let { // Esse corpo só é executado se str for diferente de nulo
        println(it.length)
    }
}