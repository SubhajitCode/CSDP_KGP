.MODEL SMALL
.CODE
        MOV AH,1
        INT 33
        AND AL,0FH
        MOV BL,AL
        MOV BH,AL
        INT 33
        AND AL,0FH
	MOV AH,2
        MOV CX,9
L1:     ADD BH,BL
        LOOP L1
        ADD AL,BH
        MOV DL,AL
        INT 33
        MOV AH,76
        INT 33
        END
        
