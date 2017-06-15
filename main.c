//
//  main.c
//  BPumpa_ProjektniZad
//
//  Created by Milan, Milos, Nikola, Rastko and Aleksa on 02.06.17.
//  Copyright © 2017 Aleksa Vujnic. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pumpa.h"
#include "Zaposleni.h"

int sesija;
char username[STR_LEN];
char password[STR_LEN];

<<<<<<< HEAD
void Welcome() //Radojcic
{
    inicijalizujStatus();
    printf("Dobrdosli. Program je uspesno pokrenut po prvi put.\n");
    printf("Unesite prvog korisnika / administratora:\n");
    unesiSefa();
}

int loginekran() //Ancevski
{
  FILE * f = fopen(ZAP_NAZIV, "rb");
  sesija = 3;
  while(sesija>2)
  {
=======
void Welcome()
{
    printf("\tDobrdosli. Program je uspesno pokrenut po prvi put./n");
    printf("\tUnesite prvog korisnika / administratora.\n");
    unesiSefa();
    printf("\tUnesite prvu vrstu goriva.\n");
    reggorivo();
    napstatuse();
}



int loginekran()
{
  FILE * f = fopen(ZAP_NAZIV, "rb");
  sesija = 3;
  while(sesija>2){
    int i = 0
>>>>>>> origin/master
    printf("Unesite korisnicko ime i lozinku:\n");
    printf("username:\n\t");
    scanf("%s",&username);
    printf("password:\n\t");
    scanf("%s",&password);
<<<<<<< HEAD
    zaposleni temp;
    fseek(f, 0, SEEK_SET);
    while(fread(&temp,sizeof(zaposleni),1,f)!=0)
    {
        if (strcmp(username, temp.username)==0)
        {
            
            if(strcmp(password, temp.password)==0)
            {
                sesija = temp.idStatus;
            }
        }
    }
      if(sesija>2)
          printf("GRESKA: Login neuspesan!!\n\n");
  }
    fclose(f);
    return sesija;
}

int menizaposleni() //Ancevski
{
    int izbor;
    do{
        printf("\nIzaberite opciju:\n");
        printf("\t 1. Registrujte gorivo\n");
        printf("\t 2. Promeni cenu goriva\n");
        printf("\t 3. Dodaj akciju na gorivo\n");
        printf("\t 4. Prodaj gorivo\n");
        printf("\t 5. Ispisi goriva\n");
        printf("\t 6. Ispisi statistiku prodaje\n");
        printf("\t 8. Kraj rada programa\n");
        scanf("%i",&izbor);
    }while(izbor<1 || izbor>8);
    return izbor;
}

int menisef() //Radojcic
{
  int izbor;
  do{
      printf("\nIzaberite oNpciju:\n");
      printf("\t 1. Dodaj novog zaposlenog\n");
      printf("\t 2. Daj otkaz zaposlenog\n");
      printf("\t 3. Proglasi radnika za sefa\n");
      printf("\t 4. Dodaj novog sefa\n");
      printf("\t 5. Ukloni sefa\n");
      printf("\t 6. Ispisi promene statusa zaposlenih\n");
      printf("\t 7. Ispisi podatke o zaposlenima\n");
      printf("\t 8. Kraj rada programa\n");
      scanf("%i",&izbor);
  }while(izbor<1 || izbor>8);
  return izbor;
}

int main(int argc, const char * argv[]) //Rastko
{
    FILE *f=fopen(ZAP_NAZIV,"rb");
    int status;
    if(f==NULL)
    {
        fclose(f);
      Welcome();
      status = 1;
    }
    else
    {
        fclose(f);
=======
    FILE * f = fopen(ZAP_NAZIV, "rb");
    zaposleni temp;
    while(fread(temp,sizeof(zaposleni),1,f)!=NULL){
      fread(temp,sizeof(zaposleni),1,f)
      if (strcmp(temp.username,user) == 0)
      {
        i=1;
        if(strcmp(temp.password,password) ==0){
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
      printf("\t 1. Registrujte gorivo\n");
      printf("\t 2. Promeni cenu goriva\n");
      printf("\t 3. Dodaj akciju na gorivo\n");
      printf("\t 4. Prodaj gorivo\n");
      printf("\t 5. Promeni stanje goriva\n");
      scanf("%i",&izbor);
  }while(izbor<1 || izbor>5);
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
>>>>>>> origin/master
      status = loginekran();
    }
    fclose(f);
    int izbor = 0;
<<<<<<< HEAD
    do
    {
    if(status==1){
      izbor = menisef();
      switch (izbor) {
        case 1:
              unesiZaposlenog();
        break;
        case 2:
              dajOtkaz();
        break;
        case 3:
              proglasSefa();
        break;
        case 4:
              unesiSefa();
        break;
        case 5:
              ukloniSefa();
        break;
        case 6:
              ispisiPromene();
        break;
        case 7:
              ispisiZaposlene();
        break;
      }
    }
    else if(status==0)
    {
      izbor = menizaposleni();
      switch (izbor) {
        case 1:
              registrujGorivo();
              break;
        case 2:
              promeniCenu();
              break;
        case 3:
              promeniPopust();
              break;
        case 4:
              prodajGorivo();
              break;
        case 5:
              ispisiGoriva();
              break;
        case 6:
              ispisiProdaje();
              break;
=======
    if(status=0){
      izbor = meniradnik();
      switch (izbor) {
        case 1:
        reggorivo()
        break;
        case 2:
        break;
        case 3:
        break;
        case 4:
        break;
        case 5;
        promenastanja()
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
>>>>>>> origin/master
      }
    }
    else
    {
<<<<<<< HEAD
      printf("\nNiste u mogucnosti da pristupite opcijama, dobili ste otkaz\n");
        break;
    }
    }while(izbor!=8);
=======
      printf("\t Niste u mogucnosti da pristupite opcijama dobili ste otkaz\n");
    }
>>>>>>> origin/master
    return 0;
}
