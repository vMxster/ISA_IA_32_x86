/********************************************************************************
 *                                                                              *
 *                   Architetture dei sistemi di Elaborazione                   *
 *                                                                              *
 ********************************************************************************

 Elaborato 2
 Descrizione: Dato in input un numero naturale n, restituire i primi n termini
			  della successione di Fibonacci.

 ********************************************************************************/


#include <stdio.h>

void main()
{
	//Variabili
	int n=0;						//Numero di termini da restituire
	int successione[50];			//Vettore in cui mettere i primi n termini
									//della successione di Fibonacci

	//Blocco Assembler
    __asm
    {
        XOR eax, eax                        // Azzera il registro EAX(equivalente a mov eax, 0)
        XOR ebx, ebx                        // Azzera il registro EBX(equivalente a mov ebx, 0)
        XOR ecx, ecx                        // Azzera il registro ECX(equivalente a mov ecx, 0)
        XOR edx, edx                        // Azzera il registro EDX(equivalente a mov edx, 0)

        CMP [n], 0                          // Confronta il valore in [n] con 0
        jl l1                               // Salta a l1 se [n] è inferiore a 0 (Jump if Less)
        mov[successione], 0                 // Memorizza 0 in [successione] se [n] è maggiore o uguale a 0

        l1:                                 // Etichetta l1
        CMP [n], 1                          // Confronta il valore in [n] con 1
        jl l2                               // Salta a l2 se [n] è inferiore a 1 (Jump if Less)
        mov[successione + 4], 1             // Memorizza 1 in [successione + 4] se [n] è maggiore o uguale a 1

        l2:                                 // Etichetta l2
        mov ecx, 2                          // Memorizza il valore 2 nel registro ECX (equivalente a mov ecx, 2)

        calcola_fibonacci:                  // Etichetta calcola_fibonacci
        cmp ecx, [n]                        // Confronta il valore in ECX con il valore in [n]
        jg fine                             // Salta a fine se ECX è maggiore di [n] (Jump if Greater)
        mov ebx, [successione][eax * 4]     // Memorizza il valore in [successione][eax * 4] nel registro EBX (Termine Fibonacci in i-2)
        INC eax                             // Incrementa il valore in EAX di 1 per il calcolo di Fibo(i-1)
        mov edx, [successione][eax * 4]     // Memorizza il valore in [successione][eax * 4] nel registro EDX (Termine Fibonacci in i-1)
        add ebx, edx                        // Somma i valori in EBX ed EDX e memorizza il risultato in EBX (Termine Fibonacci in i)
        mov[successione][ecx * 4], ebx      // Memorizza il valore in EBX in [successione][ecx * 4]
        inc ecx                             // Incrementa il valore in ECX di 1
        jmp calcola_fibonacci               // Salta a calcola_fibonacci

        fine :                              // Etichetta fine (Termine Programma)
    }


	//Stampa su video
	{
		int i;
		for(i=0;i<=n;i++)
		{
			printf("%d\n",successione[i]);
		}
	}
}
