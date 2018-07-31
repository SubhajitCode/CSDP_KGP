.MODEL SMALL
.CODE
        MOV AH,1
        INT 33
        AND AL,0FH
        MOV DL,'K'
        MOV AH,2
        MOV CH,0
        MOV CL,AL
L1:     INT 33
        LOOP L1
        MOV AH,76
        INT 33
        END
        
