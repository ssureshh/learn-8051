START: CPL P1.0
       ACALL WAIT  
       CPL P1.0
       CPL P1.3
       ACALL WAIT
       CPL P1.3  
       SJMP START
WAIT:MOV R4,#0x05
WAIT1:MOV R3,#0x00
WAIT2:MOV R2,#0x00
WAIT3:DJNZ R2,WAIT3
       DJNZ R3,WAIT2
       DJNZ R4,WAIT1
       RET