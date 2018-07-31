.MODEL SMALL
.CODE
        MOV AH,1
        INT 33
        MOV AH,2
        MOV DL,AL
        MOV CX,10
L1:     INT 33
        LOOP L1
        MOV AH,76
        INT 33
        END
        
