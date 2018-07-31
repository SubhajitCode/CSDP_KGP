.MODEL SMALL
.CODE
        MOV AH,1
        INT 33
        AND AL,0FH
        MOV CH,0
        MOV CL,AL
        JCXZ L2
L1:     MOV AH,1
        INT 33
        INC AL
        MOV DL,AL
        MOV AH,2
        INT 33
        LOOP L1
L2:     MOV AH,76
        INT 33
        END
        
