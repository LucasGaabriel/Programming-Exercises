.data
	a: .word -2147483648
	b: .word -10
	newLine: .byte '\n'

.text
	lw $t0, a
	lw $t1, b
	
	addu $t2, $t0, $t1
	subu $t3, $t0, $t1
	
	# Imprime a soma
	li $v0, 1
	add $a0, $zero, $t2
	syscall 
	
	# Imprime um '\n'
	li $v0, 11
	lb $a0, newLine
	syscall 
	
	# Imprime a subtracao
	li $v0, 1
	add $a0, $zero, $t3
	syscall 
	
	# Encerra o programa
	li $v0, 10
	syscall