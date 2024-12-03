#include <stdio.h>

int main()
{
    int a = 10;
    int b = 12;
    int c, d;

    // L'operazione MUL esegue la moltiplicazione SENZA SEGNO di due operandi.
    // Attenzione: un operando è sempre implicitamente il registro A (AL per 8 bit, AX per 16 bit, EAX per 32 bit).
    // Il risultato della moltiplicazione è memorizzato
    // 1. in AX se l'operando è di 8 bit
    // 2. in DX:AX se l'operando è di 16 bit (DX mantiente i bit più significativi)
    // 3. in EDX:EAX se l'operando è di 32 bit (EDX mantiente i bit più significativi)
    // Quindi si tratta di un'operazione particolarmente complicata da gestire
    // (probabilmente la più complicata tra quelle che vediamo).
    __asm {
        MOV EAX, a
        MOV EBX, b
        MUL EBX  // Moltiplicazione 32 bit -> risultato in EDX:EAX
        MOV c, EAX
        MOV d, EDX

    }

    printf("eax = %d\n", c);
    printf("edx = %d\n", d);
    printf("---------------------\n");

    // Attenzione: MUL non va bene per i numeri negativi (li tratta come se fossero senza segno)!
    __asm {
        MOV EAX, a
        MOV EBX, b
        NEG EAX  // Negazione di EAX
        MUL EBX  
        MOV c, EAX
        MOV d, EDX
    }

    printf("eax = %d\n", c);
    printf("edx = %d\n", d);
    printf("---------------------\n");

    // Per poter operare tra interi con segno, si può usare IMUL
    // Prima di eseguire: cosa vi aspettate dalle print sotto?
    __asm {
        MOV EAX, a
        MOV EBX, b
        NEG EAX
        IMUL EBX  // Moltiplicazione 32 bit -> risultato in EDX:EAX
        MOV c, EAX
        MOV d, EDX
    }

    printf("eax = %d\n", c);
    printf("edx = %d\n", d);
    printf("---------------------\n");

    // La divisione segue regole simili alla moltiplicazione.
    // L'operazione DIV esegue la divisione SENZA SEGNO di due operandi, mentre IDIV esegue la divisione CON SEGNO.
    // Nel registro A verrà sempre memorizzato il quoziente, mentre nel registro D il resto.
    // Unica eccezione: con operazioni a 8 bit, il dividendo è AX e il quoziente è memorizzato in AL e il resto in AH.
    // Negli altri casi, il dividendo è (E)DX:(E)AX e il quoziente è memorizzato in (E)AX e il resto in (E)DX.

    __asm {
        MOV EAX, 63
        XOR EDX, EDX  // Azzera EDX
        MOV EBX, 16
        DIV EBX  // Divisione 32 bit -> risultato in EAX (quoziente) e EDX (resto)
        MOV c, EAX
        MOV d, EDX
    }

    printf("eax = %d\n", c);
    printf("edx = %d\n", d);
    printf("---------------------\n");

    return 0;
}