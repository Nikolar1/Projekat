//
//  Zaposleni.c
//  BPumpa_ProjektniZad
//
//  Created by Milan, Milos, Nikola, Rastko and Aleksa on 02.06.17.
//  Copyright © 2017 Aleksa Vujnic. All rights reserved.
//

#include "Zaposleni.h"


void unesiZaposlenog()
{
    FILE * f = fopen(ZAP_NAZIV, "a+b");
    zaposleni temp;

    printf("\tIme zaposlenog:\n ");
    scanf("\n%s",&temp.ime);

    printf("\tPrezime zaposlenog:\n");
    scanf("\n%s",&temp.prezime);

    printf("\tIdentifikacioni broj zaposlenog (jedinstven ceo broj) \n");
    scanf("\n%s",&temp.idBroj);
    temp1.idBroj = temp.idBroj;

    printf("\tKosristnicko ime zaposlenog:\n");
    scanf("\n%s",&temp.username);

    printf("\tPassword zaposlenog:\n");
    scanf("\n%s",&temp.password);

    temp.Zaposlenje = time(NULL);
    temp1.vremePromene = time(NULL);
    //c_time_string = ctime(&current_time);

    temp.idStatus = 0;
    temp1.idStatus = 0;

    fwrite(&temp, sizeof(zaposleni), 1, f);
    fwrite(&temp1, sizeof(statusiZaposlenih),1,f1);
}

void napstatuse(){
  FILE *f1 = fopen(ST_NAZIV,"wb");
  statusi temp1;
  temp1.brStatus = 0;
  temp1.status[] = "Radnik";
  fwrite(temp1,sizeof(statusi),1,f1);
  temp1.brStatus = 1;
  temp1.status[] = "Sef";
  fwrite(temp1,sizeof(statusi),1,f1);
  temp1.brStatus = 2;
  temp1.status[] = "Obrisan";
  fwrite(temp1,sizeof(statusi),1,f1);
  fclose(f1);
}

void unesiSefa()
{
    FILE * f = fopen(ZAP_NAZIV, "a+b");
    FILE *f1 = fopen(STZAP_NAZIV, "a+b");
    zaposleni temp;
    statusiZaposlenih temp1;

    printf("\tIme sefa:\n ");
    scanf("\n%s",&temp.ime);

    printf("\tPrezime sefa:\n");
    scanf("\n%s",&temp.prezime);

    printf("\tIdentifikacioni broj sefa (jedinstven ceo broj) \n");
    scanf("\n%s",&temp.idBroj);
    temp1.idBroj = temp.idBroj;

    printf("\tKosristnicko ime sefa:\n");
    scanf("\n%s",&temp.username);

    printf("\tPassword sefa:\n");
    scanf("\n%s",&temp.password);

    temp.Zaposlenje = time(NULL);
    temp1.vremePromene = time(NULL);
    //c_time_string = ctime(&current_time);

    temp.idStatus = 1;
    temp1.idStatus = 1;

    fwrite(&temp, sizeof(zaposleni), 1, f);
    fwrite(&temp1, sizeof(statusiZaposlenih),1,f1);
}

void dajOtkaz()
{
  FILE * f = fopen(ZAP_NAZIV, "r+b");
  FILE *f1 = fopen(STZAP_NAZIV, "a+b");
  printf("\nUnesite id zaposlenog kom zelite da date otkaz:\n");
  int tempid;
  scanf("%i",&tempid);
  fseek(f,0,SEEK_SET);
  zaposleni temp;
  statusiZaposlenih temp1;
  temp1.idStatus = 2;
  temp1.idBroj = tempid;
  temp1.vremePromene = time(NULL);
  while(feof(f)!=0)
  {
    fread(&temp,sizeof(zaposleni),1,f);
    if(tempid == temp.idBroj)
    {
      temp.idStatus=2;
      fwrite(temp1,sizeof(statusiZaposlenih),1,f1);
      fseek(f,0-sizeof(zaposleni),SEEK_CUR);
      fwrite(&temp,sizeof(zaposleni),1,f);
      printf("Zaposlenom sa ID brojem %i uspesno je dat otkaz.\n",tempid);
      break;
    }
  }
  printf("\nKraj rada funkcije.\n")
}

void proglasSefa()
{
  FILE * f = fopen(ZAP_NAZIV, "r+b");
  FILE *f1 = fopen(STZAP_NAZIV, "a+b");
  printf("\nUnesite id zaposlenog kog zelite da proglasite za sefa:\n");
  int tempid;
  scanf("%i",&tempid);
  fseek(f,0,SEEK_SET);
  zaposleni temp;
  statusiZaposlenih temp1;
  temp1.idStatus = 1;
  temp1.idBroj = tempid;
  temp1.vremePromene = time(NULL);
  while(feof(f)!=0)
  {
    fread(&temp,sizeof(zaposleni),1,f);
    if(tempid == temp.idBroj)
    {
      temp.idStatus=1;
      fwrite(temp1,sizeof(statusiZaposlenih),1,f1);
      fseek(f,0-sizeof(zaposleni),SEEK_CUR);
      fwrite(&temp,sizeof(zaposleni),1,f);
      printf("Zaposlenom sa ID brojem %i uspesno je proglasen za sefa.\n",tempid);
      break;
    }
  }
  printf("\nKraj rada funkcije.\n")
}
