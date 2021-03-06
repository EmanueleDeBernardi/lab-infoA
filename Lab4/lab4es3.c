/*
 
 ESERCIZIO 3 (abaco ricorsivo)
 Scrivere un programma che permetta di visualizzare un qualsiasi numero come un abaco:
 eg. 1345
 o
 ooo
 oooo
 ooooo
 
 Il programma continua a chiedere input fino all’inserimento di 0.
 La scomposizione in abaco deve essere eseguita mediante funzione RICORSIVA.
 */

#include <stdio.h>
void print_unario(int n);
void print_unario_rec(int n);
void abaco_rec(int n);
void abaco_iter_rev(int n);
void abaco_rec_rev(int n);
void abaco_iter(int n);

int main(int argc, const char * argv[]) {
    int n;
    do {
        printf("\nInserire numero da scomporre (0 per terminare):\n");
        scanf("%d", &n);
        if (n != 0) {
            printf("Abaco iterativo:\n");
            abaco_iter(n);
            printf("Abaco ricorsivo:\n");
            abaco_rec(n);
            printf("\nAbaco ricorsivo ordine inverso:\n");
            abaco_rec_rev(n);
        }
    } while (n != 0);
    return 0;
}


void abaco_rec(int n){
    if (n<=0) return;
    else{
        abaco_rec(n/10);
        print_unario_rec(n%10);
        return;
    }
}

/* per invertire l'ordine di stampa dei valori mi basta spostare la printf da prima a dopo la chiamata ricorsiva*/
void abaco_rec_rev(int n){
    if (n<=0) return;
    else{
        print_unario_rec(n%10);
        return abaco_rec_rev(n/10);
    }
}



void abaco_iter(int n){
    int dec; //fattore  utilizzato per eseguire modulo e divisione (potenza di 10)
    dec = 1; //inizializzo a 10^0
    int val;
    /* la prima iterazione serve per trovare la minima potenza di 10 maggiore di n */
    while(n%dec != n){
        dec *= 10;
    }
    /* la seconda iterazione scorre le cifre dal decimale più significativo e le stampa in unario */
    while (dec >= 1) {
        val = n%(dec*10)/dec; // isolo la cifra sfruttando modulo e divisione intera
        print_unario(val);
        dec /= 10;
    }
    return;
}

void abaco_iter_rev(int n){
    while (n>0) {
        print_unario(n%10);
        n /= 10;
    }
}

void print_unario(int n){
    int i;
    for (i=0; i<n; i++) {
        printf("o");
    }
    printf("\n");
}

/* OPZIONALE: versione ricorsiva della stampa */
void print_unario_rec(int n){
    if(n==0)
        printf("\n");
    else{
        printf("o");
        print_unario_rec(n-1);
    }
    return;
}
