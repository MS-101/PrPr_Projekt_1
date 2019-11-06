#include <stdio.h>

int vypis() {
    FILE *fr;
    if ((fr = fopen("autobazar.txt", "r")) == NULL) {
        printf("Neotvoreny subor\n");
        return 1;
    }

    char str[100];
    double num;
    while(fgets(str, 100, fr) > 1) {
        printf("meno a priezvisko: %s", str);
        fgets(str, 100, fr);
        printf("SPZ: %s", str);
        fgets(str, 100, fr);
        printf("typ auta: %s", str);
        fscanf(fr, "%lf\n", &num);
        printf("cena: %.2f\n", num);
        fgets(str, 100, fr);
        printf("datum: %s", str);
        printf("\n");
        fscanf(fr, "\n");
    }

    fclose(fr);

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

void zistiPredaj() {

}

int main() {
    while (1)  {
        switch (getchar()) {
            case 'v':
                vypis();
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
                return 0;
                break;
        }
    }
}
