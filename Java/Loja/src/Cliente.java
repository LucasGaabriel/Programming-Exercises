public class Cliente {
    String cpf;
    String nome;
    String telefone;

    public Cliente(String cpf, String nome, String telefone){
        this.cpf = cpf;
        this.nome = nome;
        this.telefone = telefone;
    }

    public String toString() {
        return "Cliente{" +
                "CPF='" + cpf + '\'' +
                ", Nome='" + nome + '\'' +
                ", Telefone='" + telefone + '\'' +
                '}';
    }

}
