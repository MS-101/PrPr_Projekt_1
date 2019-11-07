#include <stdio.h>

int vypis(FILE **fr) {
    if (*fr == NULL) {
        if ((*fr = fopen("autobazar.txt", "r")) == NULL) {
            printf("Neotvoreny subor\n");
            return 1;
        }
    } else {
        rewind(*fr);
    }
    //str obsahuje 51 znakov, lebo 51. znak je '/0' ak do neho naèítam záznam s 50 znakmi.
    char str[51];
    double num;
    while(fgets(str, 51, *fr) > 1) {
        if (str[strlen(str) - 1] == '\n') {
            str[strlen(str) - 1] = '\0';
        }
        printf("meno a priezvisko: %s\n", str);
        fgets(str, 8, *fr);
        fscanf(*fr, "\n");
        printf("SPZ: %s\n", str);
        fgets(str, 2, *fr);
        printf("typ auta: %s\n", str);
        fscanf(*fr, "%lf\n", &num);
        printf("cena: %.2f\n", num);
        fgets(str, 9, *fr);
        printf("datum: %d\n", str);
        printf("\n");
        fscanf(*fr, "\n");
    }
    return 0;
}

void odmena() {

}

void poleZaznamov() {

}

void spz() {

}

void maxPocetnost() {

}

void palindrom() {

}

int koniec(FILE **fr) {
    if (*fr != NULL) {
        if (fclose(*fr) == EOF) {
            return 1;
        }
    }
    return 0;
}

void zistiPredaj() {

}

int main() {
    FILE *fr = NULL;
    while (1)  {
        switch (getchar()) {
            case 'v':
                vypis(&fr);
                break;
            case 'o':
                odmena();
                break;
            case 'n':
                poleZaznamov();
                break;
            case 's':
                spz();
                break;
            case 'm':
                maxPocetnost();
                break;
            case 'p':
                palindrom();
                break;
            case 'z':
                zistiPredaj();
                break;
            case 'k':
                return koniec(&fr);
                break;
        }
    }
}
