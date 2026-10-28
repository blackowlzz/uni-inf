// https://github.com/blackowlzz/uni-inf

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FINE_PARTITA 0
#define SASSO 1
#define CARTA 2
#define FORBICI 3
#define VITTORIA 1
#define PAREGGIO 0
#define SCONFITTA -1



void acquisisciMossa(int *Mossa) {
    printf("Inserisci una mossa: 1 = SASSO, 2 = CARTA, 3 = FORBICI \n");
    scanf("%d", Mossa);
    if (*Mossa < 0 || *Mossa > 3) {
        while (*Mossa < 0 || *Mossa > 3) {
            printf("Mossa non valida, riprova. \n");
            printf("Inserisci una mossa: 1 = SASSO, 2 = CARTA, 3 = FORBICI \n");
            scanf("%d", Mossa);
        }
    }
}

int determinaEsito(int giocatore, int cpu) {
    if (giocatore == SASSO) {
        if (cpu == FORBICI) {return VITTORIA;}
        else if (cpu == CARTA) {return SCONFITTA;}
        else {return PAREGGIO;}}
    else if (giocatore == CARTA) {
        if (cpu == FORBICI) {return SCONFITTA;}
        else if (cpu == CARTA) {return PAREGGIO;}
        else {return VITTORIA;}
    }
    else if (giocatore == FORBICI) {
        if (cpu == CARTA) {return VITTORIA;}
        else if (cpu == FORBICI) {return PAREGGIO;}
        else {return SCONFITTA;}
    }

    return PAREGGIO; //placeholder per il warn del compilatore, non raggiungibile dato che valido gli input
}

void aggiornaPunteggio(int esito, int *Vittorie, int *Pareggi, int *Sconfitte) {
    if (esito == VITTORIA) {(*Vittorie)++;}
    else if (esito == PAREGGIO) {(*Pareggi)++;}
    else {(*Sconfitte)++;}
}

int main() {
    int vittorie = 0, sconfitte = 0, pareggi = 0;
    srand(time(NULL));
    int mossa;
    do {
        acquisisciMossa(&mossa);
        if (mossa != FINE_PARTITA) {
            int mossaCPU = rand() % 3 + 1;
            int esito = determinaEsito(mossa, mossaCPU);
            aggiornaPunteggio(esito, &vittorie, &pareggi, &sconfitte);
            printf("Mossa = %d\n Mossa CPU = %d \n ", mossa, mossaCPU);
            switch (esito) {
                case VITTORIA:
                    printf("Vittoria! Il tuo punteggio per ora = vittorie: %d sconfitte: %d pareggi %d \n ", vittorie, sconfitte, pareggi);
                    break;
                case PAREGGIO:
                    printf("Pareggio! Il tuo punteggio per ora = vittorie: %d sconfitte: %d pareggi %d \n ", vittorie, sconfitte, pareggi);
                    break;
                case SCONFITTA:
                    printf("Sconfitta! Il tuo punteggio per ora = vittorie: %d sconfitte: %d pareggi %d \n ", vittorie, sconfitte, pareggi);
                    break;
                default:
                    printf("Errore! \n");
            }
        }
    }while (mossa != FINE_PARTITA);

    printf("Programma terminato, risultati:\n vittorie: %d sconfitte: %d pareggi %d \n ", vittorie, sconfitte, pareggi);

}
