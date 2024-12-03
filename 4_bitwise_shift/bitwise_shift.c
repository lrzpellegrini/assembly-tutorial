#include <stdio.h>

void printb(void *input);

int main()
{
    int a = 10;
    int b = 12;
    int c;

    // Le operazioni bit a bit (bitwise) sono AND, OR, XOR
    // Ad esempio, con XOR
    __asm {
        MOV EAX, a
        MOV EBX, b
        XOR EAX, EBX  // XOR bit a bit tra EAX e EBX
        MOV c, EAX
    }

    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n", c);

    printb(&a);
    printf("\n");
    printb(&b);
    printf("\n");
    printb(&c);
    printf("\n---------------------\n");

    // Possiamo usare SHR/SHL per shiftare i bit
    // Nota: questo è lo shift senza segno (il più comune)
    // Esempio: extraiamo il colore rosso da un pixel e lo salviamo in un int (32 bit)
    unsigned int pixel = 0x003AF212; // 0000 0000 0011 1010 1111 0010 0001 0010
    unsigned int red;

    __asm {
        MOV EAX, pixel
        AND EAX, 0x00FF0000 // AND bit a bit tra EAX e 0x00FF0000
        SHR EAX, 16         // Shift right di 16 bit
        MOV red, EAX
    }

    printf("pixel = %x\n", pixel);  // Nota: grazie a printf possiamo stampare i numeri in esadecimale (con %x)
    printf("red = %x\n", red);
    
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