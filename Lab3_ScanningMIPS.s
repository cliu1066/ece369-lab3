lw $s0, 0($a0)		#frame height (frameRows)
lw $s1, 4($a0)		#frame width (frameCols)
lw $s2, 8($a0)		#window height (winRows)
lw $s3	12($a0)		#window width (winCols)
#a1 holds frame[0][0] (*frame)
#a2 holds window[0][0] (*window)
#s6 min sad
#s7 current sad
#v0 minSad row
#v1 minSad col

scanning:
addi $sp, $sp, -12
sw $a0, 8($sp)
sw $a1, 4($sp)
sw $a2, 0($sp)
addi $s4, $zero, 0	#current frame row (row)
addi $s5, $zero, 0	#current frame column (col)
jal windowSad
addi $s6, $s7, 0	#minSad = windowSad(),    s6 holds minSad, s7 holds currSad
addi $s5, $s5, 1	#col += 1
addi $t0, $zero, 1	#moveDown = 1

loop:
sub $t1, $s0, $s2
addi $t1, $t1, 1	#frameRows - winRows + 1
sub $t2, $s1, $s3
addi $t2, $t2, 1	#frameCols - winCols + 1
beq $s4, $t1, exit
beq $s5, $t2, exit	#while((row != frameRows - winRows + 1) && (col != frameCols - winCols + 1))
jal windowSad		#currSad = windowSad()

slt $t3, $s6, $s7	#minSad < currSad?
bne $t3, $zero, bright	#if (currSad <= minSad)
addi $s6, $s7, 0	#minSad = currSad
addi $v0, $s4, 0	#v0 = row
addi $v1, $s5, 0	#v1 = col

bright:			#reach bottom right corner
addi $t1, $t1, -1	#frameRows - winRows
addi $t2, $t2, -1	#frameCols - winCols
bne $s4, $t1, moveDown
beq $s5, $t2, exit


moveDown:
beq $t0, $zero, else	#if(moveDown)
bne $s4, $t1, firstColUp #if(row == frameRows - winRows)
addi $s5, $s5, 1	#col += 1
addi $t0, $zero, 0	#moveDown = false
j loop
	
firstColUp:
bne $s5, $zero, normalMoveDown	#else if (col == 0)?
addi $s4, $s4, 1	#row += 1
addi $t0, $zero, 0	#moveDown = false
j loop

normalMoveDown:
addi $s4, $s4, 1	#row += 1
addi $s5, $s5, -1	#col -= 1
j loop


else:
bne $s5, $t2, firstRowDown	#if (col == frameCols - winCols)
addi $s4, $s4, 1	#row += 1
addi $t0, $zero, 1	#moveDown = true
j loop

firstRowDown:
bne $s4, $zero, normalMoveUp #else if(row == 0)?
addi $s5, $s5, 2	#col += 1
addi $t0, $zero, 1	#moveDown = true
j loop

normalMoveUp:
addi $s4, $s4, -1	#row -= 1
addi $s5, $s5, 1	#col += 1
j loop

 

exit:  
slt $t3, $s6, $s7	#minSad < currSad?
bne $t3, $zero, finish	#if (currSad <= minSad)
addi $s6, $s7, 0	#minSad = currSad
addi $v0, $s4, 0	#v0 = row
addi $v1, $s5, 0	#v1 = col

finish:
jr $ra




