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

void Welcome()
{
    printf("\tDobrdosli. Program je uspesno pokrenut po prvi put./n");
    printf("\tUnesite prvog korisnika / administratora.\n");
    unesiSefa();
}



int loginekran()
{
  FILE * f = fopen(ZAP_NAZIV, "rb");
  sesija = 3;
  while(sesija>2){
    int i = 0
    printf("Unesite korisnicko ime i lozinku:\n");
    printf("username:\n\t");
    scanf("%s",&user);
    printf("password:\n\t");
    scanf("%s",&password);
    FILE * f = fopen(ZAP_NAZIV, "rb");
    zaposleni temp;
    while(fread(temp,sizeof(zaposleni),1,f)!=NULL){
      fread(temp,sizeof(zaposleni),1,f)
      if (temp.username[]==user[])
      {
        i=1;
        if(temp.password[]==password[]){
          sesija = temp.idStatus;
        }
      }
    }
    if (i==1)
    {
      printf("Pogresna lozinka");
    }
    else{
      printf("Nepostojece korisnicko ime");
    }
  }
    return sesija;
}

int menisef(){
  int izbor;
  do{
      printf("Izaberite opciju:\n");
      printf("\t 1. Dodaj novog radnika.\n");
      printf("\t 2. Daj otkaz radniku\n");
      printf("\t 3. Proglasi radnika za sefa\n");
      printf("\t 4. Dodaj novog sefa\n");
      printf("\t 5. Ukloni sefa\n");
      printf("\t 6. Ispisi statistiku svih radnika\n");
      scanf("%i",&izbor);
  }while(izbor<1 || izbor>6);
  return izbor;
}

int meniradnik(){
  int izbor;
  do{
      printf("Izaberite opciju:\n");
      printf("\t 1. Registrujte gorivo TNG\n");
      printf("\t 2. Registrujte gorivo Dizel.\n");
      printf("\t 3. Registrujte gorivo Benzin\n");
      printf("\t 4. Promeni cenu goriva TNG\n");
      printf("\t 5. Promeni cenu goriva Dizel\n");
      printf("\t 6. Promeni cenu goriva Benzin\n");
      printf("\t 7. Dodaj akciju na gorivo\n");
      printf("\t10. Prodaj gorivo\n");
      scanf("%i",&izbor);
  }while(izbor<1 || izbor>10);
  return izbor;
}

int main(int argc, const char * argv[]) {
    FILE *f=fopen(ZAP_NAZIV,rb);
    zaposleni temporary;
    int status;
    if(fread(temporary,sizeof(zaposleni),1,f)==NULL){
      Welcome();
      status = 1;
    }
    else{
      status = loginekran();
    }
    fclose(f);
    int izbor = 0;
    if(status=0){
      izbor = meniradnik();
      switch (izbor) {
        case 1:
        break;
        case 2:
        break;
        case 3:
        break;
        case 4:
        break;
        case 5:
        break;
        case 6:
        break;
        case 7:
        break;
        case 8:
        break;
        case 9:
        break;
        case 10:
        break;
      }
    }
    else if(status=1)
    {
      izbor = menisef();
      switch (izbor) {
        case 1:
        break;
        case 2:
        break;
        case 3:
        break;
        case 4:
        break;
        case 5:
        break;
        case 6:
        break;
      }
    }
    else
    {
      printf("\t Niste u mogucnosti da pristupite opcijama dobili ste otkaz\n");
    }
    return 0;
}
