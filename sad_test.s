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
		
# Compute window index: t0 = (t3 * s3 + t2) * 4 + a2
mul  $t0, $t3, $s3        # t0 = pr * winCols
add  $t0, $t0, $t2        # t0 = pr * winCols + pc
sll  $t0, $t0, 2          # t0 *= 4 (word offset)
add  $t0, $t0, $a2        # t0 = &window[pr][pc]
lw   $t5, 0($t0)          # t5 = windowVal

# Compute frame index: t0 = ((s4 + t3) * s1 + (s5 + t2)) * 4 + a1
add  $t6, $s4, $t3        # t6 = row + pr
mul  $t0, $t6, $s1        # t0 = (row + pr) * frameCols
add  $t7, $s5, $t2        # t7 = col + pc
add  $t0, $t0, $t7        # t0 = linear index in frame
sll  $t0, $t0, 2          # t0 *= 4 (word offset)
add  $t0, $t0, $a1        # t0 = &frame[row+pr][col+pc]
lw   $t8, 0($t0)          # t8 = frameVal
	

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

	