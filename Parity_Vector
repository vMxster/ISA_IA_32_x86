// Paritá Elementi di un Vettore

#include <stdio.h>

void main() {

	unsigned char Vettore[] = { 3,7,3,7,5 };
	unsigned int Lung = sizeof(Vettore) / sizeof(Vettore[0]);
	int Ris;

	__asm {
		XOR EAX,EAX
		XOR EBX, EBX
		XOR ECX, ECX
		XOR EDX, EDX
		XOR EDI, EDI
		XOR ESI, ESI
		MOV ECX, Lung
		ciclo:	MOV AL, [Vettore][EDX]
				ADD BL,AL
				INC EDX
				CMP ECX, EDX
				JNE ciclo
		XOR EAX, EAX
		XOR ECX, ECX
		XOR EDX, EDX
		AND BL,1
		MOV Ris, EBX
	}

	printf("Ris %d", Ris);
}
