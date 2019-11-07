#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    while(fgets(str, 51, *fr) != NULL) {
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

int pocetDniVMesiaci(int mesiac, int rok) {
	switch(mesiac) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			return 31;
			break;
		case 4: case 6: case 9: case 11:
			return 30;
			break;
		case 2:
			if (rok % 4 == 0) {
				return 29;
			} else {
				return 28;
			}
			break;
	}
}

int pocetDniVRoku(int rok) {
	if (rok % 4 == 0) {
		return 366;
	} else {
		return 365;
	}
}

int pocetDni(char *datum) {
    int pocetDni, rok, mesiac, den, i;
    char rokStr[5], mesiacStr[3], denStr[3];
    for (i = 0; i < 4; i++) {
        rokStr[i] = datum[i];
    }
    rokStr[4] = '\0';
    mesiacStr[0] = datum[4];
    mesiacStr[1] = datum[5];
    mesiacStr[2] = '\0';
    denStr[0] = datum[6];
    denStr[1] = datum[7];
    denStr[2] = '\0';
    rok = atoi(rokStr);
    mesiac = atoi(mesiacStr);
    den = atoi(denStr);
    pocetDni = den;
    for (i = 1; i <= mesiac; i++) {
        pocetDni += pocetDniVMesiaci(i, rok);
    }
    for (i = 1; i <= rok; i++) {
        pocetDni += pocetDniVRoku(i);
    }
    return pocetDni;
}


void odmena(FILE **fr) {
    if (*fr != NULL) {
        #define ODMENA_STARE 5.1
        #define ODMENA_NOVE 2.3

        char aktualnyDatum[9], datum[9], menoPriezvisko[51], spz[8];
        int typAuta;
        double cena, odmena;

        scanf("%s", aktualnyDatum);
        rewind(*fr);
        while(fgets(menoPriezvisko, 51, *fr) != NULL) {
            if (menoPriezvisko[strlen(menoPriezvisko) - 1] == '\n') {
                menoPriezvisko[strlen(menoPriezvisko) - 1] = '\0';
            }
            fgets(spz, 8, *fr);
            fscanf(*fr, "%d\n", &typAuta);
            fscanf(*fr, "%lf\n", &cena);
            fgets(datum, 9, *fr);
            fscanf(*fr, "\n");
            if (pocetDni(aktualnyDatum) - pocetDni(datum) >= 365) {
                if (typAuta == 1) {
                    odmena = cena / 100 * ODMENA_NOVE;
                } else {
                    odmena = cena / 100 * ODMENA_STARE;
                }
                printf("%s %s %.2f\n", menoPriezvisko, spz, odmena);
            }

        }
    }
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
                odmena(&fr);
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
