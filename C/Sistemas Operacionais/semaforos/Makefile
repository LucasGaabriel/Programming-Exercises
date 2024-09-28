# Trabalho #2 - Sincronização
# Sistemas Operacionais
#
# -- Alunos --
# Daniel Siqueira de Oliveira
# Heitor Felix Lopes
# Lucas Gabriel de Oliveira Costa

# Names of the Programs
PROGRAM1=Parte1
PROGRAM2=Parte2

# Compilation and linking
all: Parte1 Parte2

Parte1:
	@ gcc main.c -o $(PROGRAM1)
	@ echo "Compiled $(PROGRAM1)"
	
Parte2:
	@ gcc Funcionarios.c MonitorBanheiro.c -o $(PROGRAM2)
	@ echo "Compiled $(PROGRAM2)"

clean:
	@ rm -rf $(PROGRAM1) $(PROGRAM2)
	@ echo "Removed $(PROGRAM1) and $(PROGRAM2)"