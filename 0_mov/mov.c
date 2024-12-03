#include <stdio.h>

int main()
{
    int a = 10;
    int b = 12;

    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("---------------------\n");

    __asm {
        MOV eax, a
        MOV b, eax
    }

    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("---------------------\n");

    __asm {
        MOV b, 60
    }

    printf("a = %d\n", a);
    printf("b = %d\n", b);

    // Errore: non è possibile usare MOV per spostare un valore tra due locazioni di memoria
    // __asm {
    //     MOV a, b
    // }

    return 0;
}