.386
.MODEL FLAT

ExitProcess PROTO NEAR32 stdcall, dwExitCode:DWORD

INCLUDE io.h            ; header file for input/output

cr      EQU     0dh     ; carriage return character
Lf      EQU     0ah     ; line feed

.STACK  4096            ; reserve 4096-byte stack

.DATA                   ; reserve storage for data
f1 byte ?,'*'
f2 byte ?,'='
p byte ?,?,'  ',0
crlf byte cr,lf,0
str1 byte 6 dup(?)

.CODE                           ; start of main program code
_start:
      mov bl,1
L1:   cmp bl,9
      jg L2
      mov dl,bl
      or dl,30h
      mov f1,dl
      mov cl,1
L3:   cmp cl,bl
      jg L4
      mov dl,cl
      or dl,30h
      mov f2,dl
      mov al,bl
      mul cl
      itoa str1,ax
      lea esi,str1
      mov dl,[esi+4]
      mov p,dl
      mov dl,[esi+5]
      mov p+1,dl
      output f1
      inc cl
      jmp L3
L4:   output crlf
      inc bl
      jmp L1
L2:

        INVOKE  ExitProcess, 0  ; exit with return code 0

PUBLIC _start                   ; make entry point public

END                             ; end of source code

