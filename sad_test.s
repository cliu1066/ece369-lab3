windowSad:
	addi $sp, $sp, -4
	sw $ra, 0($sp)


	addi $t2, $0, 0		
	addi $t3, $0, 0		
	addi $t4, $0, 0		
	
loopRow:
	bge $t3, $s2, done
	addi $t2, $0, 0		
	
loopCol:
	bge $t2, $s3, nextRow
		
	mul $t0, $t3, $s3	
	add $t0, $t0, $t2	

	sll $t0, $t0, 2		
	add $t0, $t0, $a2
	lw $t5, 0($t0)		

	add $t6, $s4, $t3	
	add $t7, $s5, $t2	

	mul $t0, $t6, $s1	
	add $t0, $t0, $t7	

	sll $t0, $t0, 2		
	add $t0, $t0, $a1
	lw $t8, 0($t0)		

	sub $t9, $t5, $t8	
	bltz $t9, negSad
	b addSad

negSad:	sub $t9, $0, $t9
	
addSad:	add $t4, $t4, $t9	
	addi $t2, $t2, 1	
	b loopCol		 

nextRow:addi $t3, $t3, 1	
	b loopRow

done:	move $s7, $t4
	lw $ra, 0($sp)
	addi $sp, $sp, 4
	jr $ra

	