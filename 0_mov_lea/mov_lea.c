#include <stdio.h>

void printb(void *input);

int main()
{
    int a = 10;
    int b = 12;
    int Vec[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

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
    printf("---------------------\n");

    // Errore: non è possibile usare MOV per spostare un valore tra due locazioni di memoria
    // __asm {
    //     MOV a, b
    // }

    __asm {
        LEA EAX, a
        MOV b, EAX
    }

    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("&b = %d\n", &b);
    printf("---------------------\n");

    __asm {
        LEA ECX, Vec
        MOV DWORD PTR [ECX][2], 5
        MOV DWORD PTR [ECX][28], 63  // Provate a togliere DWORD PTR. Perchè la print di Vec[7] ha lo stesso risultato?
        MOV EAX, [ECX][2]
        MOV a, EAX
        // MOV a, [EAX][7]  // ERRORE: non è possibile usare MOV per spostare un valore tra due locazioni di memoria!
    }

    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("Vec[0] = %d\n", Vec[0]);
    printf("Vec[1] = %d\n", Vec[1]);
    printf("Vec[2] = %d\n", Vec[2]);
    printf("Vec[7] = %d\n", Vec[7]);
    printb(&Vec[0]);
    printf("\n");
    printb(&Vec[1]);
    printf("\n");
    printf("---------------------\n");

    return 0;
}

void printb(void *input)
{
    // Adattata da: https://stackoverflow.com/a/25502488
    unsigned int v = *(unsigned int*)input;
    unsigned int i, s = 1<<((sizeof(v)<<3)-1); // s = only most significant bit at 1
    int count = 0;
    for (i = s; i; i>>=1, count++)
    {
        if (count % 4 == 0 && count > 0)
            printf("|");
        printf("%d", v & i || 0 );
    }
}