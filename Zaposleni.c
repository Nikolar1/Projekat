//
//  Zaposleni.c
//  BPumpa_ProjektniZad
//
//  Created by Milan, Milos, Nikola, Rastko and Aleksa on 02.06.17.
//  Copyright © 2017 Aleksa Vujnic. All rights reserved.
//

#include "Zaposleni.h"


void unesiZaposlenog() //Vujnic
{
    FILE * f = fopen(ZAP_NAZIV, "a+b");
    FILE * f1 = fopen(STZAP_NAZIV, "a+b");
    zaposleni temp;
    statusiZaposlenih temp1;

    printf("\tIme zaposlenog:\n ");
    scanf("\n%s",&temp.ime);

    printf("\tPrezime zaposlenog:\n");
    scanf("\n%s",&temp.prezime);

    printf("\tIdentifikacioni broj zaposlenog (jedinstven ceo broj) \n");
    scanf("\n%i",&temp.idBroj);
    temp1.idBroj = temp.idBroj;

    printf("\tKosristnicko ime zaposlenog:\n");
    scanf("\n%s",&temp.username);

    printf("\tPassword zaposlenog:\n");
    scanf("\n%s",&temp.password);

    UpisiVreme(temp.Zaposlenje);
    UpisiVreme(temp1.vremePromene);
    
    char s [] = "Nije dobio otkaz!";
    strcpy(temp.Otkaz, s);

    temp.idStatus = 0;
    temp1.idStatus = 0;

    fwrite(&temp, sizeof(zaposleni), 1, f);
    fwrite(&temp1, sizeof(statusiZaposlenih),1,f1);
    fclose(f);
    fclose(f1);
}

void unesiSefa()  //Vujnic
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
    scanf("\n%i",&temp.idBroj);
    temp1.idBroj = temp.idBroj;

    printf("\tKosristnicko ime sefa:\n");
    scanf("\n%s",&temp.username);

    printf("\tPassword sefa:\n");
    scanf("\n%s",&temp.password);

    UpisiVreme(temp.Zaposlenje);
    UpisiVreme(temp1.vremePromene);
    
    char s [] = "Nije dobio otkaz!";
    strcpy(temp.Otkaz, s);

    temp.idStatus = 1;
    temp1.idStatus = 1;

    fwrite(&temp, sizeof(zaposleni), 1, f);
    fwrite(&temp1, sizeof(statusiZaposlenih),1,f1);
    fclose(f);
    fclose(f1);
}

void dajOtkaz() //Vujnic
{
  FILE * f = fopen(ZAP_NAZIV, "r+b");
    if(f==NULL)
    {
        printf("GRESKA! Fajl ne postoji!");
    }
  FILE *f1 = fopen(STZAP_NAZIV, "a+b");
  printf("\nUnesite id zaposlenog kom zelite da date otkaz:\n");
  int tempid;
  scanf("%i",&tempid);
  zaposleni temp;
  statusiZaposlenih temp1;
  temp1.idStatus = 2;
  temp1.idBroj = tempid;
    UpisiVreme(temp1.vremePromene);
  while(fread(&temp,sizeof(zaposleni),1,f)!=0)
  {
    if(tempid == temp.idBroj)
    {
      temp.idStatus=2;
    UpisiVreme(temp.Otkaz);
      fwrite(&temp1,sizeof(statusiZaposlenih),1,f1);
        long pozicija = ftell(f);
        fseek(f,pozicija-sizeof(zaposleni),SEEK_SET);
      fwrite(&temp,sizeof(zaposleni),1,f);
      printf("Zaposlenom sa ID brojem %i uspesno je dat otkaz.\n",tempid);
      break;
    }
  }
    fclose(f);
    fclose(f1);
    printf("\nKraj rada funkcije.\n");
}

void proglasSefa() //Vujnic
{
  FILE * f = fopen(ZAP_NAZIV, "r+b");
    if(f==NULL)
    {
        printf("GRESKA! Fajl ne postoji!");
    }
  FILE *f1 = fopen(STZAP_NAZIV, "a+b");
  printf("\nUnesite id zaposlenog kog zelite da proglasite za sefa:\n");
  int tempid;
  scanf("%i",&tempid);
  zaposleni temp;
  statusiZaposlenih temp1;
  temp1.idStatus = 1;
  temp1.idBroj = tempid;
    UpisiVreme(temp1.vremePromene);
  while(fread(&temp,sizeof(zaposleni),1,f)!=0)
  {
    if(tempid == temp.idBroj)
    {
      temp.idStatus=1;
      fwrite(&temp1,sizeof(statusiZaposlenih),1,f1);
        long pozicija = ftell(f);
        fseek(f,pozicija-sizeof(zaposleni),SEEK_SET);
      fwrite(&temp,sizeof(zaposleni),1,f);
      printf("Zaposlenom sa ID brojem %i uspesno je proglasen za sefa.\n",tempid);
      break;
    }
  }
    fclose(f);
    fclose(f1);
    printf("\nKraj rada funkcije.\n");
}

void ukloniSefa() //Vujnic
{
    FILE * f = fopen(ZAP_NAZIV, "r+b");
    if(f==NULL)
    {
        printf("GRESKA! Fajl ne postoji!");
    }
    FILE *f1 = fopen(STZAP_NAZIV, "a+b");
    printf("\nUnesite id sefa kom zelite da oduzmete status sefa:\n");
    int tempid;
    scanf("%i",&tempid);
    zaposleni temp;
    statusiZaposlenih temp1;
    temp1.idStatus = 0;
    temp1.idBroj = tempid;
    UpisiVreme(temp1.vremePromene);
    while(fread(&temp,sizeof(zaposleni),1,f)!=0)
    {
        if(tempid == temp.idBroj)
        {
            temp.idStatus=0;
            fwrite(&temp1,sizeof(statusiZaposlenih),1,f1);
            long pozicija = ftell(f);
            fseek(f,pozicija-sizeof(zaposleni),SEEK_SET);
            fwrite(&temp,sizeof(zaposleni),1,f);
            printf("Zaposlenom sa ID brojem %i uspesno je dodat status radnika.\n",tempid);
            break;
        }
    }
    fclose(f);
    fclose(f1);
    printf("\nKraj rada funkcije.\n");
}

void ispisiZaposlenog(zaposleni zap) //Vracar
{
  FILE *f = fopen(ST_NAZIV, "rb");
    if(f==NULL)
    {
        printf("GRESKA! Fajl ne postoji!");
    }
    statusi temp;
  while(fread(&temp,sizeof(statusi),1,f)!=0)
  {
    if(temp.brStatus==zap.idStatus)
    {
      printf("\nZaposleni ID broja %i je %s:",zap.idBroj,temp.status);
      break;
    }
  }

  printf("\nIme:\n ");
  printf("\t%s",zap.ime);

  printf("\nPrezime:\n");
  printf("\t%s",zap.prezime);

  printf("\nKosristnicko ime:\n");
  printf("\t%s",zap.username);

  printf("\nPassword:\n");
  printf("\t%s",zap.password);
    
    printf("\nVreme zasnivanja radnog odnosa:\n");
    printf("\t%s",zap.Zaposlenje);
    
    printf("\nVreme prestanka radnog odnosa:\n");
    printf("\t%s",zap.Otkaz);

  printf("\n\n");
    fclose(f);
}

void ispisiZaposlene() //Vracar
{
  FILE * f = fopen(ZAP_NAZIV, "rb");
    if(f==NULL)
    {
        printf("GRESKA! Fajl ne postoji!");
    }
  zaposleni temp;
  while(fread(&temp,sizeof(zaposleni),1,f)!=0)
  {
    ispisiZaposlenog(temp);
  };
    fclose(f);
}

void ispisiPromenu(statusiZaposlenih stzap) //Vracar
{
  FILE *f = fopen(ST_NAZIV, "rb");
    if(f==NULL)
    {
        printf("GRESKA! Fajl ne postoji!");
    }
  fseek(f,0,SEEK_SET);
    statusi temp;
  while(fread(&temp,sizeof(statusi),1,f)!=0)
  {
    if(temp.brStatus==stzap.idStatus)
    {
      printf("\nZaposleni ID broja %i postao je %s:",stzap.idBroj, temp.status);
      break;
    }
  }

  printf("\nVreme:\n");
  printf("\t%s",stzap.vremePromene);
  
    fclose(f);

  printf("\n\n");
}

void ispisiPromene() //Vracar
{
  FILE * f = fopen(STZAP_NAZIV, "rb");
    if(f==NULL)
    {
        printf("GRESKA! Fajl ne postoji!");
    }
  statusiZaposlenih temp;
  while(fread(&temp,sizeof(statusiZaposlenih),1,f)!=0)
  {
    ispisiPromenu(temp);
  };
    fclose(f);
}

void inicijalizujStatus() //Radojcic
{
    FILE *f1 = fopen(ST_NAZIV,"wb");
    statusi temp1;
    temp1.brStatus = 0;
    char *s =  "Radnik";
    strcpy(temp1.status, s);
    fwrite(&temp1,sizeof(statusi),1,f1);
    temp1.brStatus = 1;
    s =  "Sef";
    strcpy(temp1.status, s);
    fwrite(&temp1,sizeof(statusi),1,f1);
    temp1.brStatus = 2;
    s =  "Obrisan";
    strcpy(temp1.status, s);
    fwrite(&temp1,sizeof(statusi),1,f1);
    fclose(f1);
}
