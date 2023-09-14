// Ricerca di un carattere in una stringa

#include <stdio.h>

void main() {

	char Stringa[] = "Questa a una stringa";
	int Lunghezza = sizeof(Stringa) - 1;
	char Carattere = 'é';
	int Posizione;

	__asm {
		XOR EAX, EAX
		XOR EBX, EBX
		XOR ECX, ECX
		XOR EDX, EDX
		XOR EDI, EDI
		XOR ESI, ESI
		MOV CX, 0				; Posizione
		MOV EBX, Lunghezza
		ADD EBX, 1				; Lunghezza Stringa
		MOV DL, Carattere		; Carattere da Cercare nella Stringa
		ciclo : MOV AL, [Stringa] [ECX]
				CMP EDX, EAX
				JE Risultato
				INC ECX
				CMP ECX, EBX
				JNAE ciclo
		CMP ECX , EBX
		JAE NRIS
		
		Risultato : MOV Posizione, ECX
		NRIS : XOR ECX, ECX
				DEC ECX
				MOV Posizione, ECX
	}
	printf("Posizione = %d", Posizione);
}
