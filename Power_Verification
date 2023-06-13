// Dato un numero, dire se è una potenza di due

#include <stdio.h>

void main() {

	unsigned int Num = 3;
	unsigned int Ris;

	__asm {
		XOR EAX, EAX
		XOR EBX, EBX
		XOR ECX, ECX
		XOR EDX, EDX
		XOR EDI, EDI
		XOR ESI, ESI
		MOV EAX, Num
		ciclo:	TEST EAX, 01h
				JNZ UNO
				SHR EAX, 1
				INC EDX
				CMP EDX, 31
				JE UNO
				JMP ciclo
		UNO :	CMP EAX, 1
				JE RisPot 	
				MOV Ris, 0
		RisPot : MOV Ris, 1
	}
	printf("Ris = %d", Ris);
}
