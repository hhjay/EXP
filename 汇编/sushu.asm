; Example assembly language program
; Author:  hhjay
; Date:    revised 06/2014

.386
.MODEL FLAT

ExitProcess PROTO NEAR32 stdcall, dwExitCode:DWORD

INCLUDE io.h            ; header file for input/output

cr      EQU     0dh     ; carriage return character
Lf      EQU     0ah     ; line feed

.STACK  4096            ; reserve 4096-byte stack

.DATA                   ; reserve storage for data
       flai     DWORD ?
       temp     DWORD ?
       crlf     BYTE "*",0
       eqll     BYTE "=",0
       prompt   BYTE "Enter a number to find all the prime factors",cr,Lf,0
       fl       DWORD ?
       value    BYTE 11 DUP(?),0
       char     BYTE 1 DUP(?)

 PUBLIC _start
.CODE                           ; start of main program code
_start:
       output  prompt
       input   value,11    ;n
       atod    value
       push    eax    ;n
       call    byteInput
       add     esp,4

       output  eqll

       push    eax
       call    findPfactor
       add     esp,4

        INVOKE  ExitProcess, 0  ; exit with return code 0


findPfactor PROC NEAR32         ;find the prime of factor
          push ebp
          mov  ebp,esp

          mov  eax,[ebp+8]
          mov  flai,eax
          mov  ecx,2
          mov  ebx,ecx
          doFind:
               mov ecx,ebx
               cmp ecx,flai     ;while()
               je  endFind      ;=
               doFactor:
                   mov temp,eax
                   cdq
                   idiv ecx
                   ;eax = eax/ecx
                   cmp edx,0
                   jne endFactor
                   ;dtoa value,ecx
                   ;output value
                   push ecx
                    output crlf
                   call byteInput
                   add esp,4
                   jmp  doFactor
               endFactor:
                    mov eax,temp
                    inc ebx
                    jmp doFind
          endFind:
          pop  ebp
          ret

findPfactor ENDP

byteInput PROC NEAR32
          push ebp
          mov  ebp,esp

          push ebx
          push eax
          push edx

          mov  fl,0
          mov  ebx,10
          mov  eax,[ebp+8]
          doWh:
              cdq
              idiv ebx
              push edx
              inc fl
              cmp eax,0
              je  enddoWh


              jmp doWh
          enddoWh:

          doPrint:

                 cmp fl,0
                 je  enddoPrint
                 dec fl
                 pop edx
                 mov char,dl
                 add char,'0'
                 output char
                 jmp doPrint
          enddoPrint:
          pop edx
          pop eax
          pop ebx
          pop ebp
          ret

byteInput ENDP

END                             ; end of source code