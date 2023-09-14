// Algoritmo per l'estrazione di radice

#include <stdio.h>

void main() {

	unsigned int Num = 2;
	unsigned int Radice;

	__asm {
		XOR EAX,EAX
		XOR EBX,EBX
		XOR ECX, ECX
		XOR EDX, EDX		
		MOV EAX, Num	
		MOV EBX, 0
		MOV EDX, 1
		ciclo:	SUB EAX, EDX
				ADD EDX, 2
				INC EBX
				CMP EAX, 0
				JGE ciclo
		MOV Radice, EBX
	}
	printf("Radice = %d\n", Radice);
}
