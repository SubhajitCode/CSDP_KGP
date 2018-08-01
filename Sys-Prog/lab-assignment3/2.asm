.MODEL SMALL
.CODE
        MOV CX,5
L1:     
        MOV AH,1
        INT 33
        INC AL        
        MOV AH,2
        MOV DL,AL
        INT 33
        LOOP L1
        MOV AH,76
        INT 33
        END
        
