#include <stdio.h>

int main()
{
    int a = 10;
    int b = 12;

    // Le operazioni SUM e SUB eseguono la classica somma e sottrazione tra due valori
    // rappresentati in complemento a due. Il risultato è salvato nel primo operando.
    __asm {
        MOV EAX, a
        MOV EBX, b
        ADD EAX, EBX
        MOV a, EAX
        SUB EBX, EAX
        MOV b, EBX
    }

    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("---------------------\n");

   // L'operazione NEG opera il complemento a due del valore contenuto in un registro.
   // Ovvero trasforma 5 in -5 e viceversa.

    __asm {
        MOV EAX, a
        NEG EAX
        MOV a, EAX
    }

    printf("a = %d\n", a);
    printf("---------------------\n");

    return 0;
}