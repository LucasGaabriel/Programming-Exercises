.data

.text
	# switch (k):
	# case 0: f = i + j; break; //L0
	# case 1: f = g + h; break; //L1
	# case 2: f = g - h; break; //L2
	# case 3: f = i - j; //L3

	li $s1, 3 # Valor de G
	li $s2, 4 # Valor de H
	li $s3, 7 # Valor de I
	li $s4, 15 # Valor de J
	li $s5, 0 #Valor de K
	li $t2, 4 # $t2 inicializa com 4

	# Busca e desloca de acordo com o valor de K
	sub $t2, $t2, 1
	beq $s5, $t2, L3
	sub $t2, $t2, 1
	beq $s5, $t2, L2
	sub $t2, $t2, 1
	beq $s5, $t2, L1
	sub $t2, $t2, 1
	beq $s5, $t2, L0
	j exit
	
L0: 	add $s0, $s3, $s4
	j exit
L1:	add $s0, $s1, $s2
	j exit
L2: 	sub $s0, $s1, $s2
	j exit
L3:	sub $s0, $s3, $s4
	j exit
	
exit: 	move $a0, $s0
	li $v0, 1
	syscall
	
	li $v0, 10
	syscall