.data
	varA: .word 2147483648
	varB: .word -1

.text
	# Carrega variaveis
	lw $t0, varA
	lw $t1, varB
	
	# Divide as variaveis
	div $t0, $t0, $t1
	
	# Imprime resultado da multiplicacao