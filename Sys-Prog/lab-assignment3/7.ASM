.MODEL SMALL
.CODE
        MOV AH,1
        INT 33
        MOV DL,AL
        INT 33
        SUB AL,DL
        MOV CL,AL
        INC CL
        MOV CH,0
        JCXZ L2
        MOV AH,2
L1:    
        INT 33
        INC DL
        LOOP L1
L2:     MOV AH,76
        INT 33
        END
        
