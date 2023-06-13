// Somma e media degli elementi in un vettore

#include <stdio.h>

void main() {

	int Vettore[] = { 1,2,3,4,5,6,7,8,9,10,1,2,3,-1,-2,-3 };
	unsigned int Lung = sizeof(Vettore) / sizeof(int);
	int Somma;
	int Media;

	__asm {
		XOR EAX,EAX
		XOR EBX, EBX
		XOR ECX, ECX
		XOR EDX, EDX
		XOR EDI, EDI
		XOR ESI, ESI
		MOV ECX, Lung
		somma : MOV EAX, [Vettore][EDX*4]
				ADD EBX, EAX
				INC EDX
				CMP ECX, EDX
				JNE somma
		MOV ECX, Lung
		MOV EAX, EBX
		XOR EDX, EDX
		CDQ
		IDIV ECX
		MOV Somma, EBX
		MOV Media, EAX
	}

	printf("Somma %d", Somma);
	printf("Media %d", Media);
}
