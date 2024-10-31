package org.example

fun main() {
    var sal: Double = 10.0 // Se não colocar o .0 retorna erro
    var num: Float = 10f // Se não colocar o f retorna erro
    var num2: Long = 100L // Para usar Long precisa do L

    println(sal)
    println(num)
    println(num2)

    println("${8.toFloat()}")

    val x: Float = 8f
    val y: Int
    y = x.toInt()

    println("${y}")
}
