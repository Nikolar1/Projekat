//
//  main.c
//  BPumpa_ProjektniZad
//
//  Created by Milan, Milos, Nikola, Rastko and Aleksa on 02.06.17.
//  Copyright © 2017 Aleksa Vujnic. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Pumpa.h"
#include "Zaposleni.h"

int sesija;
char user[STR_LEN];
char password[STR_LEN];

int meni()
{
    int izbor;
    do{
        printf("Izaberite opciju:\n");
        printf("\t 1. Dodaj novog radnika.\n");
        printf("\t 2. Daj otkaz radniku\n");
        printf("\t 3. Proglasi radnika za sefa\n");
        printf("\t 4. Dodaj novog sefa\n");
        printf("\t 5. Ukloni sefa\n");
        printf("\t 6. Ispisi statistiku svih radnika\n");
        printf("\t 7. Dodaj gorivo (TNG/BMB 95/Evrodizel)\n");
        printf("\t 8. Promeni cenu goriva\n");
        printf("\t 9. Dodaj akciju na gorivo\n");
        printf("\t10. Prodaj gorivo\n");
        scanf("%i",&izbor);
    }while(izbor<1 || izbor>16);
    return izbor;
}

void Welcome()
{
    printf("\tDobrdosli. Program je uspesno pokrenut po prvi put./n");
    printf("\tUnesite prvog korisnika / administratora.\n");

}

int loginekran()
{
    printf("Unesite korisnicko ime i lozinku:\n");
    printf("username:\n\t");
    scanf("%s",&user);
    printf("password:\n\t");
    scanf("%s",&password);
    FILE * f = fopen(ZAP_NAZIV, "rb");
    return sesija;
}



int main(int argc, const char * argv[]) {


    return 0;
}
