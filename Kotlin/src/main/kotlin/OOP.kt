package org.example

class Pessoa constructor(var nome: String, var idade: Int = 30) {
    var cpf: String? = null
    lateinit var cidade: String

    constructor(nome: String, idade: Int, cpf: String) : this(nome, idade) {
        // Agora, é possível instanciar uma classe usando cpf ou não
        this.cpf = cpf
    }

    override fun toString(): String {
        return "${this.nome}, ${this.idade}, ${this.cpf}"
    }

    init {
        println("- Pessoa instanciada: ${this.nome}")
    }

    init {
        println("- Pessoa instanciada com CPF: ${this.cpf}")

        if(!this::cidade.isInitialized) {
            println("<!> Cidade não foi inicializada!")
        }
    }
}

fun main() {
    val p1 = Pessoa("Andre", 32)
    val p2 = Pessoa("Lucas", 20, "12345678901")

    println(p1)
    println(p2)

    val pessoaResponsavelPeloSetorDeAdministracao = Pessoa("Joao", 25, "14547678")
    with(pessoaResponsavelPeloSetorDeAdministracao) {
        // Podemos acessar usando this
        println("- Pessoa responsavel: ${this.nome}")

        // Ou podemos acessar so chamando o que queremos
        println("- Pessoa responsavel: ${nome}")

        println("- Pessoa responsavel: ${this}")
    }
}
