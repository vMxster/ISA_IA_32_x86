/*********************************************************************************
 *                                                                               *
 *                   Architetture dei sistemi di Elaborazione                    *
 *                                                                               *
 *********************************************************************************

 Elaborato 1
 Descrizione:	Data una stringa C (terminata dal carattere nullo), contenente una
            frase (ossia parole separate da spazi e/o segni di punteggiatura),
            trovare la parola piú lunga e la parola piú corta. In caso di parole
            di uguale lunghezza, considerare la prima da sinistra.
            Le due parole vanno copiate in due array di caratteri come stringhe
            C (terminate dal carattere nullo).
            I segni di punteggiatura da considerare sono: ".,;:'?!"

 **********************************************************************************/


#include <stdio.h>

#define MAX_LEN 100

int main()
{
    char frase[MAX_LEN] = "parola due";
    char parolaMax[MAX_LEN + 1];
    char parolaMin[MAX_LEN + 1];

    __asm
    {
        XOR EAX, EAX                                // Azzera il registro EAX (Appoggio Carattere, Spazio e Punteggiatura)
        XOR ECX, ECX                                // Azzera il registro ECX (Contatore Parola Corrente e Contatore nei Cicli l)
        XOR EDX, EDX                                // Azzera il registro EDX (Contatore Parola MAX)
        XOR EBX, EBX                                // Azzera il registro EBX (Contatore Parola MIN)
        XOR EDI, EDI                                // Azzera il registro EDI (Puntatore a frase)
            LEA EDI, frase                          // Carica l'indirizzo di memoria di "frase" (chiamata, da me, anche stringa madre per facilitá) nel registro EDI

        split_words :                           // Ciclo per Dividere le Parole dalla Stringa Madre
            MOV AL, [EDI]                           // Carica il byte puntato da EDI nel registro AL
            CMP AL, 0                               // Confronta AL con 0 (fine stringa)
            JE endWord                              // Salta a "endWord" se AL è uguale al Terminatore di Stringa \0
            CMP AL, ' '                             // Confronta AL con lo spazio
            JE endWord                              // Salta a "endWord" se AL è uguale a uno spazio
            CMP AL, '.'                             // Confronta AL con il punto
            JE endWord                              // Salta a "endWord" se AL è uguale a un punto
            CMP AL, ','                             // Confronta AL con la virgola
            JE endWord                              // Salta a "endWord" se AL è uguale a una virgola
            CMP AL, ';'                             // Confronta AL con il punto e virgola
            JE endWord                              // Salta a "endWord" se AL è uguale a un punto e virgola
            CMP AL, ':'                             // Confronta AL con i due punti
            JE endWord                              // Salta a "endWord" se AL è uguale a due punti
            CMP AL, '\''                            // Confronta AL con l'apostrofo
            JE endWord                              // Salta a "endWord" se AL è uguale a un apostrofo
            CMP AL, '?'                             // Confronta AL con il punto interrogativo
            JE endWord                              // Salta a "endWord" se AL è uguale a un punto interrogativo
            CMP AL, '!'                             // Confronta AL con il punto esclamativo
            JE endWord                              // Salta a "endWord" se AL è uguale a un punto esclamativo

            INC EDI                                 // Incrementa EDI (puntatore alla stringa)
            INC ECX                                 // Incrementa ECX (contatore lunghezza parola corrente)
            JMP split_words                         // Salta a "split_words" (per dividere le singole parole dalla stringa madre)

        endWord :                               // Dopo aver trovato una Parola nella Stringa Madre, guardo se posso aggiornare parola Max o Min
            CMP ECX, 0                              // Confronta ECX con 0 (nessun carattere)
            JE next_word                            // Salta a "next_word" se ECX è uguale a 0
            CMP ECX, EDX                            // Confronta ECX con EDX (lunghezza parola massima)
            JA update_max                           // Salta a "update_max" se ECX è maggiore di EDX
            CMP ECX, EBX                            // Confronta ECX con EBX (lunghezza parola minima)
            JB update_min                           // Salta a "update_min" se ECX è minore di EBX

        next_word :                             // Dopo aver memorizzato oppure non avviene nessun aggiornamento in Parola MAX e MIN, si passa alla prossima parola della stringa madre
            MOV AL, [EDI]                           // Carica il byte puntato da EDI nel registro AL
            CMP AL, 0                               // Confronta AL con 0 (fine stringa)
            JE done                                 // Salta a "done" se AL è uguale al Terminatore di Stringa \0
            INC EDI                                 // Incrementa EDI (puntatore alla stringa)
            XOR ECX, ECX                            // Azzera il registro ECX (reset per conteggio nuova parola)
            JMP split_words                         // Salta a "split_words" (per dividere le singole parole dalla stringa madre)

        update_max :                            // Ciclo Principale per Memorizzare parolaMax
            MOV EDX, ECX                            // Copia ECX in EDX (lunghezza parola massima)
            SUB EDI, EDX                            // Sottrae EDX da EDI (per riportare il puntatore all'inizio della parola divisa dalla stringa madre)
            XOR ECX, ECX                            // Azzera il registro ECX
        l1 :                                    // Ciclo per Memorizzare un Byte alla volta la parolaMax
            MOV AL, [EDI]                           // Carica il byte puntato da EDI nel registro AL
            MOV parolaMax[ECX], AL                  // Copia AL nell'array "parolaMax"
            INC ECX                                 // Incrementa ECX
            INC EDI                                 // Incrementa EDI (avanza il puntatore)
            CMP ECX, EDX                            // Confronta ECX con EDX (puntatore deve arrivare alla fine della parola)
            JNE l1                                  // Salta a "l1" se ECX non è uguale a EDX
            CMP EBX, 0                              // Confronta EBX con 0 (nessuna parola/carattere in parolaMin)
            JE update_min                           // Salta a "update_min" se EBX è uguale a 0
            JMP next_word                           // Salta a "next_word"

        update_min :                            // Ciclo Principale per Memorizzare la parolaMin
            MOV EBX, ECX                            // Copia ECX in EBX (lunghezza parola minima)
            SUB EDI, EBX                            // Sottrae EBX da EDI (puntatore all'inizio della parola da memorizzare)
            XOR ECX, ECX                            // Azzera il registro ECX
        l2 :                                    // Ciclo per Memorizzare un Byte alla volta la parolaMin
            MOV AL, [EDI]                           // Carica il byte puntato da EDI nel registro AL
            MOV parolaMin[ECX], AL                  // Copia AL nell'array "parolaMin"
            INC ECX                                 // Incrementa ECX
            INC EDI                                 // Incrementa EDI
            CMP ECX, EBX                            // Confronta ECX con EBX
            JNE l2                                  // Salta a "l2" se ECX non è uguale a EBX
            JMP next_word                           // Salta a "next_word"

        done :
            XOR ECX, ECX                            // Azzera il registro ECX (contatore per il ciclo successivo)
            LEA EDI, parolaMax                      // Carica l'indirizzo di memoria di parolaMax nel registro EDI
        l3:                                     // Ciclo per arrivare a Posizione ECX di parolaMax per inserire \0
            INC EDI                                 // Incrementa l'indirizzo di memoria di parolaMax
            INC ECX                                 // Incrementa il contatore ECX
            CMP ECX, EDX                            // Confronta il contatore ECX con il valore di EDX
            JNE l3                                  // Salta a l3 se il contatore ECX non è uguale a EDX
            MOV parolaMax[ECX], 0                   // Memorizza \0 nell'elemento di parolaMax indicizzato da ECX
            LEA EDI, parolaMin                      // Carica l'indirizzo di memoria di parolaMin nel registro EDI
            XOR ECX, ECX                            // Azzera nuovamente il registro ECX (contatore per il ciclo successivo)
        l4:                                     // Ciclo per arrivare a Posizione ECX di parolaMin per inserire \0
            INC EDI                                 // Incrementa l'indirizzo di memoria di parolaMin
            INC ECX                                 // Incrementa l'indirizzo di memoria di parolaMin
            CMP ECX, EBX                            // Confronta il contatore ECX con il valore di EBX
            JNE l4                                  // Salta a l4 se il contatore ECX non è uguale a EBX
            MOV parolaMin[ECX], 0                   // Memorizza \0 nell'elemento di parolaMin indicizzato da ECX
    }

    printf("%s\n%s\n%s\n", frase, parolaMax, parolaMin);
    return 0;
}
