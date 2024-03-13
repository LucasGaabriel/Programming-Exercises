public class ValorNaoNumericoException extends Exception {
    ValorNaoNumericoException(String nomeArquivo, String conteudoLinha){
        super("O arquivo '" + nomeArquivo + "' contém uma linha com valores não numéricos: '" + conteudoLinha + "'.");
    }
}
