/********************************************************************************
 *                                                                              *
 *                   Architetture dei sistemi di Elaborazione                   *
 *                                                                              *
 ********************************************************************************

 Elaborato 3
 Descrizione: Dato un array di BYTE, invertire l’ordine dei bit all’interno
		dell’array.

 ********************************************************************************/


#include <stdio.h>

void main()
{
	#define MAX_LEN	100

// Input
	unsigned char vet[]={ 0x01,0x02,0x03 };			//  Array di BYTE
	unsigned int len=sizeof(vet)/sizeof(vet[0]);	//  Numero di byte in vet	
// Output
	unsigned char res[MAX_LEN];						//  Array di BYTE contenente il risultato 

// Blocco assembler
	__asm
	{
        XOR ECX, ECX                            // Inizializzo ECX a 0 (per la lunghezza del vettore)
        XOR EBX, EBX                            // Inizializzo EBX a 0 (per la lunghezza del vettore)
        XOR EDX, EDX                            // Inizializzo EDX a 0 (come appoggio)
        XOR EAX, EAX                            // Inizializzo EAX a 0 (come indice di origine)
        MOV ECX, len                            // Carico la lunghezza dell'array in ECX (numero di byte in vet)
        MOV EBX, ECX                            // Copio la lunghezza dell'array in EBX (numero di byte in vet, come contatore)

        l1: DEC EBX                             // Decremento EBX (sposto l'indice al byte precedente)
            PUSH ECX                            // Salvo ECX nello stack (per non andare a utilizzare altri registri come ESI e EDI)
            MOV ECX, 8                          // Carico in ECX 8 (numero di bit in un byte)
            MOV DL, vet[EAX]                    // Carico il byte sorgente nell'appoggio DL

        l2: SHR DL, 1                           // Sposto a DX (destra) di 1 bit l'appoggio DL (shift logico verso destra)(sposto bit meno significativo nel carry flag)
            RCL res[EBX], 1                     // Ruoto a SX (sinistra) di 1 bit il byte di destinazione (rotazione verso sinistra usando CF)(uso il bit che ho nel carry flag per costruire giá la soluzione)
            DEC CX                              // Decremento CX (contatore dei bit da 8 fino a 0)
            JNZ l2                              // Salto a "l2" se CX non è zero (ci sono ancora dei bit da invertire)

        INC EAX                                 // Incremento EAX (sposta l'indice al byte successivo)
        POP ECX                                 // Ripristino ECX dallo stack (per non andare a utilizzare altri registri come ESI e EDI)
        DEC CX                                  // Decremento CX  (contatore dei byte da len a 0)
        JNZ l1                                  // Salto a "l1" se CX non è zero (ci sono ancora dei byte da invertire)
    } 

// Stampa su video
	{	
		unsigned int i;
		for (i=0;i<len;i++)
			printf("res[%2d] = %10d (%08X)\n",i,res[i],res[i]);
	}
}
