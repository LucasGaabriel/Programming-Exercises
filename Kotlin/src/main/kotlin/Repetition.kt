package org.example

fun main() {
    for (i in 1..10) {
        print("$i ")
    }
    println()

    for (i in 1..10 step 2) {
        print("$i ")
    }
    println()

    for (i in 20 downTo 0 step 2) {
        print("$i ")
    }
    println()

    val str = "Desenvolvimento Mobile"
    for (s in str)
        print("$s ")
}