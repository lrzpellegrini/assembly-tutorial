#include <stdio.h>

int main()
{
    int a = 10;
    int b = 12;

    // In assembly possiamo definire delle etichette con cui possiamo
    // saltare a parti di codice tramite JMP
    __asm {
        MOV EAX, a
        MOV EBX, b
        ADD EAX, EBX  // ADD bit a bit tra EAX e EBX
        JMP Fine
        MOV a, EAX   // Questa istruzione non verrà mai eseguita
    Fine:   
        MOV b, EAX
    }

    printf("a = %d\n", a);
    printf("b = %d\n", b);

    // Possiamo anche saltare a parti di codice in base a condizioni
    // Ad esempio, con CMP/JE. Ad esempio: implementiamo un if-else
    // per cui, se c e d sono uguali, memorizza 1 in 6, altrimenti 0

    int c = 11;
    int d = 10;
    int e;

    __asm {
        MOV EAX, c
        MOV EBX, d
        CMP EAX, EBX
        JNE NonUguale  // Jump Not Equal
        MOV e, 1
        JMP FineIf  // Attenzione, questo JMP è importante!
    NonUguale:
        MOV e, 0
    FineIf:
    }

    printf("e = %d\n", e);

    // Per esercitarvi potreste provare a implementare un if-else-if
    // con CMP/JE/JNE/JMP
    // Ad esempio: un if che salva in "e" 0 se a è minore di 5, 1 sa è compreso tra 5 e 9, 2 se è maggiore o uguale a 10
    // Si consiglia di fare riferimento alle slide per tutti i condition code!

    return 0;
}
