#include <stdio.h>

int main()
{
    int a = 10;
    int b = 12;
    int c = 0;
    int d = 0;

    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("---------------------\n");

    // Possiamo eseguire PUSH e POP usando un registro o una variabile
    __asm {
        PUSH a
        PUSH b
        POP a
        POP b
    }

    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("---------------------\n");

    // Attenzione: PUSH e POP possono agire sia a 16 che a 32 bit
    // In questo caso "a" è a 32 bit, mentre AX e BX sono registri a 16 bit
    // Quindi il valore di "a" verrà caricato su AX e BX a blocchi da 16 bit
    // Che risultato vi aspettate?
    __asm {
        XOR EAX, EAX
        XOR EBX, EBX
        PUSH a
        POP AX
        POP BX
        MOV c, EAX
        MOV d, EBX
    }

    printf("a = %d\n", a);
    printf("c = %d\n", c);
    printf("d = %d\n", d);
    printf("---------------------\n");

    a = 12;
    c = 0;
    d = 0;

    __asm {
        XOR EAX, EAX
        XOR EBX, EBX
        PUSH a
        POP BX
        POP AX
        MOV c, EAX
        MOV d, EBX
    }

    printf("a = %d\n", a);
    printf("c = %d\n", c);
    printf("d = %d\n", d);

    return 0;
}