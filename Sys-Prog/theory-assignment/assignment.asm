.MODEL SMALL
.DATA
MSG1 DB 'ENTER A LINE OF TEXT',0DH,0AH,'$'
OUT1 DB 'SMALLEST UPPER CASE LETTER IS: $'
OUT2 DB 'LARGEST UPPER CASE LATTER IS : $'
OUT3 DB 'NO UPPER CASE LETTER$'
.CODE
MAIN:
        MOV AX,@DATA
        MOV DS,AX
        MOV AH,9
        LEA DX,MSG1
        INT 33
        MOV AH,1
        MOV BL,0
        MOV CL,127
L3:     INT 33
        CMP AL,0DH
        JE L1
        CMP AL,'a'
        JGE L3
        CMP AL,BL
        JNGE L2
        MOV BL,AL
L2:     CMP AL,CL
        JNLE L3
        MOV CL,AL
        JMP L3
L1:     CMP BL,0
        JNE L5
        MOV AH,9
        LEA DX,OUT3
        INT 21H
        JMP STOP
L5:     MOV AH,9
        LEA DX,OUT1
        INT 21H
        MOV AH,2
        MOV DL,CL
        INT 33
        MOV DL,0DH
        INT 33
        MOV DL,0AH
        INT 33
        MOV AH,9
        LEA DX,OUT2
        INT 21H
        MOV AH,2
        MOV DL,BL
        INT 33
        MOV DL,0DH
        INT 33
        MOV DL,0AH
        INT 33
STOP:        MOV AH,76
        INT 33
END MAIN


