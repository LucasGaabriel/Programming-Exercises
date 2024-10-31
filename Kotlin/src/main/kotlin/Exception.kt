package org.example

fun main() {
    val x = 10
    val y = 2
    var z: Int

    try {
        z = x / y
    } catch (e: ArithmeticException) {
        println("- Ocorreu uma divisão por zero!")
    } catch (e: Exception) {
        println("- Alguma outra exceção ocorreu!")
    } finally {
        println("- Esse bloco é sempre executado")
    }
}
