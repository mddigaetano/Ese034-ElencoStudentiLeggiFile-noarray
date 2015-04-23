#include <stdio.h>
#include <stdlib.h>

// Definisci le costanti
#define MAX_STRLEN 30

// Definisci il tipo di dato struct s_studente
struct s_studente{
    char nome[MAX_STRLEN+1];
    char cognome[MAX_STRLEN+1];
    unsigned int eta;
    char classe[MAX_STRLEN+1];
};

// Definisci studente come struct s_studente
typedef struct s_studente studente;

int main(int argc, char** argv) {
    // Dichiara le variabili locali
    studente alunno;
    int i; char NomeFile[MAX_STRLEN+1];
    FILE *pfile;
    
    // Codice per la richiesta del nome del file
    printf("Inserisci il nome del file da leggere: ");
    scanf("%s", NomeFile);
    
    // Codice per l'apertura del file, la lettura e la stampa a schermo
    if(pfile=fopen(NomeFile, "rb")){
        fread(&alunno,sizeof(studente),1,pfile);
        while(!(feof(pfile))){
            printf("\n%s; %s; %d; %s\n", alunno.nome, alunno.cognome, alunno.eta, alunno.classe);
            fread(&alunno,sizeof(studente),1,pfile);
        }
    }
    else{
        printf("Impossibile aprire il file");
    }
    return (EXIT_SUCCESS);
}