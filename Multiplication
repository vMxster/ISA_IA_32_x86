// Moltiplicazione di due numeri mediante somme ripetute

#include <stdio.h>

void main() {

	unsigned short Num1 = 1;
	unsigned short Num2 = 5;
	unsigned int Prodotto;

	__asm {
		XOR EAX,EAX
		XOR EBX,EBX
		XOR ECX, ECX
		XOR EDX, EDX
		MOV AX, Num1
		MOV DX, AX
		MOV CX, Num2
		SUB CX, 1
		ciclo:	ADD AX,DX
				DEC CX
				CMP CX, 0
				JNE ciclo
		MOV DX,AX
		MOV Prodotto,EDX
	}
	printf("Prodotto = %u\n", Prodotto);
}
