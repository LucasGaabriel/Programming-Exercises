
public class InformacoesIncompletasException extends Exception {
	InformacoesIncompletasException(String arquivo){
		super("O arquivo '" + arquivo + "' contém dados incompletos.");
	}

}
