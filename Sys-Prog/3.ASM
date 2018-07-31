.MODEL SMALL
.CODE
        MOV AH,1
        INT 33
        AND AL,0FH
        MOV BL,AL
        MOV CX,9
L1:     
        ADD AL,BL
        LOOP L1
        MOV AH,2
        MOV DL,AL
        INT 33
        MOV AH,76
        INT 33
        END
        
