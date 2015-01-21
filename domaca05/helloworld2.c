#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_DLZKA_SLOVA 100
#define SEP_ADR " "

struct polozka {
    char meno[MAX_DLZKA_SLOVA];
    char adresa[MAX_DLZKA_SLOVA];
    char datNar[MAX_DLZKA_SLOVA];
    struct polozka *dalsi;
};

void odallocuj(struct polozka *zoznam) {
    struct polozka *pomocna = zoznam;
    while (pomocna != NULL) {
        zoznam = zoznam->dalsi;
        free(pomocna);
        pomocna = zoznam;
    }
}

void vymazJTy(int j, struct polozka *zoznam) {
    int i;
    struct polozka *pomocna;

    for (i = 0; i < j; i++) {
        pomocna = zoznam;
        if (pomocna == NULL) {
            perror("Polozka so zadanym indexom neexistuje!");
            return;
        }
        zoznam = zoznam->dalsi;
    }
    zoznam = zoznam->dalsi;
}

void vypisPresovcanov(struct polozka *zoznam) {
    struct polozka *pomocna = zoznam;
    char adr[MAX_DLZKA_SLOVA];
    char *token;

    while (pomocna != NULL) {
        strcpy(pomocna->adresa, adr);

        token = strtok(adr, SEP_ADR);
        printf("%s\n", token);
/*  token = strtok(NULL, SEP_ADR);*/
        token = strtok(NULL, SEP_ADR);

        if (strcmp(token, "Presov") == 0)
            printf("%s : %s : %s", pomocna->meno, pomocna->adresa, pomocna->datNar);

        pomocna = pomocna->dalsi;
    }
}

void vypisPolozky(struct polozka *zoznam) {
    struct polozka *pomocna = zoznam;
    while (pomocna != NULL) {
        printf("%s : %s : %s\n", pomocna->meno, pomocna->adresa, pomocna->datNar);
        pomocna = pomocna->dalsi;
    }
}

int main(void) {
	File *subor;
    char riadok[MAX_DLZKA_SLOVA];
    struct polozka *zoznam = NULL;
    struct polozka *pomocna = NULL;

    subor = fopen("adresy", "r");

    while (fgets(riadok, MAX_DLZKA_SLOVA, subor) != NULL) {
        pomocna = malloc(sizeof(struct polozka));

        if (pomocna == NULL) {
            perror("Canot alocate memory!");
            return -1;
        } else {
            strcpy(pomocna->meno, riadok);

            fgets(riadok, MAX_DLZKA_SLOVA, stdin);
            strcpy(pomocna->adresa, riadok);

            fgets(riadok, MAX_DLZKA_SLOVA, stdin);
            strcpy(pomocna->datNar, riadok);

            fgets(riadok, MAX_DLZKA_SLOVA, stdin); /*prazdny riadok*/

            pomocna->dalsi = zoznam;
            zoznam = pomocna;
        }
    }

    fclose(subor);

    vypisPolozky(zoznam);
/* vypisPresovcanov(zoznam);*/
    vymazJTy(1, zoznam);
    vypisPolozky(zoznam);
    odallocuj(zoznam);

    return 0;
}

