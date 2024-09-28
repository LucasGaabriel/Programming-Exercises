.data
	a: .word -2147483648
	b: .word -10


.text
	
	lw $t0, a
	lw $t1, b
	
	sub $t2, $t0, $t1
	
	# Imprime inteiro
	li $v0, 1
	add $a0, $zero, $t2
	syscall 
	
	# Encerra o programa
	li $v0, 10
	syscall
