package org.example

fun main() {
    val x = 90
    // Maneira tradicional do Java aceita pelo Kotlin
    if (x > 0 && x < 100){
        println("- Está dentro do intervalo")
    }
    // Maneira proposta pelo Kotlin
    if (x in 0..100){
        println("- Está dentro do intervalo (usando range)")
    }
}
