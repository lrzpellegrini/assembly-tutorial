#include <stdio.h>


int myFunction(int a, int b)
{
    return a * (b + 1);
}


int strangeFunction()
{
    __asm {
        MOV EAX, 5
    }
}

int main()
{
    int a = 10;
    int b = 12;

    // È possibile eseguire una chiamata di funzione in maniera relativamente semplice con l'istruzione CALL
    // Ad esempio, possiamo chiamare la funzione myFunction definita sopra
    // e memorizzare il risultato in una variabile

    // Nota: dobbiamo eseguire la push dei parametri prima di chiamare la funzione
    // e pulire lo stack dopo la chiamata
    // Nota 2: il risultato della funzione è memorizzato in eax

    __asm
    {
        // Push dei parametri
        PUSH b
        PUSH a

        // Chiamata della funzione
        CALL myFunction

        // Pulizia dello stack (equivalente a 2 POP da 32 bit in questo caso)
        ADD ESP, 8

        // Memorizzazione del risultato in a
        MOV a, EAX
    }

    // Qual è il codice disassemblato della chiamata a questa printf?
    // Perchè esegue 2 PUSH prima della chiamata?
    printf("a = %d\n", a);  

    // Provate a chiamare strangeFunction e a stampare il risultato
    // Come mai funziona?

    return 0;
}
