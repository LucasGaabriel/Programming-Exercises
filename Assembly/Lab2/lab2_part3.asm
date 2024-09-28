.data
	var1: .word 35
	var2: .word 14
	var3: .word 1
	var4: .word 59
	
	primeiro: .byte 'L'
	ultimo: .byte 'C'

.text
	# Carrega os valores da memória para os registradores
	lw $t0, var1 # t0 = var1
	lw $t1, var2 # t1 = var2
	lw $t2, var3 # t2 = var3
	lw $t3, var4 # t3 = var4
	
	# Salva os valores na memória, trocando os registradores
	sw $t3, var1 # var1 = var4
	sw $t2, var2 # var2 = var3
	sw $t1, var3 # var3 = var2
	sw $t0, var4 # var4 = var1