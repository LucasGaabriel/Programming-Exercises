.data
	a: .word 2
	b: .word -1

.text
	# Carrega variaveis
	lw $t0, a
	lw $t1, b
	
	# Multiplica as variaveis
	multu $t0, $t1
	
	# Imprime resultado da multiplicacao