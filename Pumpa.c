//
//  Pumpa.c
//  BPumpa_ProjektniZad
//
//  Created by Aleksa on 02.06.17.
//  Copyright © 2017 Aleksa Vujnic. All rights reserved.
//

#include "Pumpa.h"

void registrujGorivo() //Radojcic
{
    FILE * f = fopen(GORIVO_NAZIV, "a+b");
    gorivo temp;

    printf("\n\nNaziv goriva: ");
    scanf("%s",&temp.naziv);

    printf("Sifra goriva (jedinstven ceo broj):  ");
    scanf("%i",&temp.sifra);

    printf("Cena goriva:  ");
    scanf("%f",&temp.cena);

    printf("Inicijalna kolicina goriva (u litrima):  ");
    scanf("%f",&temp.kolicina);

    printf("Inicijalni popust na gorivo (u procentima):  ");
    float p;
    scanf("%f",&p);

    printf("\n");
    temp.popust = (100-p)/100;

    fwrite(&temp, sizeof(gorivo), 1, f);
    fclose(f);
}

void prodajGorivo() //Ancevski
{
  FILE * f = fopen(GORIVO_NAZIV, "r+b");
  FILE *f1 = fopen(PRODAJA_NAZIV, "a+b");
    if(f==NULL)
    {
        printf("GRESKA! Fajl ne postoji!");
    }
  printf("\nUnesite sifru goriva koje zelite da prodate:  ");
  int tempid;
  scanf("%i",&tempid);
  printf("Unesite kolicinu goriva (u litrima):");
  float tempkol;
  scanf("%f", &tempkol);
  gorivo temp;
  prodaja temp1;
  temp1.sifra = tempid;
    UpisiVreme(temp1.vremeProdaje);
  while(fread(&temp,sizeof(gorivo),1,f)!=0)
  {
    if(tempid == temp.sifra)
    {
      if(temp.kolicina < tempkol)
      {
        printf("\n\tNema dovoljno goriva na stanju.");
        break;
      }
      temp1.kolicina = tempkol;
      temp1.zarada = temp.cena * temp.popust * tempkol;
      printf("\nUkupno za naplatu: %.2f",temp1.zarada);
      fwrite(&temp1,sizeof(prodaja),1,f1);
        temp.kolicina = temp.kolicina - tempkol;
        long pozicija = ftell(f);
        fseek(f,pozicija-sizeof(gorivo),SEEK_SET);
      fwrite(&temp,sizeof(gorivo),1,f);
      printf("\nTransakcija izvrsena!");
      break;
    }
  }
    fclose(f);
    fclose(f1);
    printf("\nKraj rada funkcije.\n");
}

void promeniCenu() //Ancevski
{
  FILE * f = fopen(GORIVO_NAZIV, "r+b");
    if(f==NULL)
    {
        printf("GRESKA! Fajl ne postoji!");
    }
  printf("\nUnesite sifru goriva kom zelite da promenite cenu:\n");
  int tempid;
  scanf("%i",&tempid);
  gorivo temp;
  while(fread(&temp,sizeof(gorivo),1,f)!=0)
  {
    if(tempid == temp.sifra)
    {
      float cena;
      printf("Unesite novu cenu goriva:");
      scanf("%f",&cena);
      temp.cena = cena;

        long pozicija = ftell(f);
        fseek(f,pozicija-sizeof(gorivo),SEEK_SET);
        fwrite(&temp,sizeof(gorivo),1,f);

      printf("Gorivu sa sifrom %i uspesno je promenjena cena na %.2f.\n",tempid,cena);
      break;
    }
  }
    fclose(f);
    printf("\nKraj rada funkcije.\n");
}

void promeniPopust() //Radojcic
{
  FILE * f = fopen(GORIVO_NAZIV, "r+b");
    if(f==NULL)
    {
        printf("GRESKA! Fajl ne postoji!");
    }
  printf("\nUnesite sifru goriva kom zelite da promenite popust:\n");
  int tempid;
  scanf("%i",&tempid);
  gorivo temp;
  while(fread(&temp,sizeof(gorivo),1,f)!=0)
  {
    if(tempid == temp.sifra)
    {
      float popust;
      printf("Unesite novu akciju na gorivo (u procentima):");
      scanf("%f",&popust);
      temp.popust = (100-popust)/100;
        long pozicija = ftell(f);
        fseek(f,pozicija-sizeof(gorivo),SEEK_SET);
      fwrite(&temp,sizeof(gorivo),1,f);
      printf("Gorivu sa sifrom %i uspesno je promenjena akcija na %.2f procenata.\n",tempid,popust);
      break;
    }
  }
    fclose(f);
    printf("\nKraj rada funkcije.\n");
}

void dodajGorivo() //Ancevski
{
    FILE * f = fopen(GORIVO_NAZIV, "r+b");
    if(f==NULL)
    {
        printf("GRESKA! Fajl ne postoji!");
    }
    printf("\nUnesite sifru goriva koje zelite da dodate na pumpu:\n");
    int tempid;
    scanf("%i",&tempid);
    gorivo temp;
    while(fread(&temp,sizeof(gorivo),1,f)!=0)
    {
        if(tempid == temp.sifra)
        {
            float kolicina;
            printf("Unesite koliko goriva dodajete u litrima:");
            scanf("%f",&kolicina);
            temp.kolicina = temp.kolicina + kolicina;
            long pozicija = ftell(f);
            fseek(f,pozicija-sizeof(gorivo),SEEK_SET);
            fwrite(&temp,sizeof(gorivo),1,f);
            printf("Gorivo sa sifrom %i uspesno je povecano na %.2f litara.\n",tempid,temp.kolicina);
            break;
        }
    }
    fclose(f);
    printf("\nKraj rada funkcije.\n");
}

void ispisiGorivo(gorivo gor) //Vracar
{
  printf("\nSifra: ");
  printf("%i",gor.sifra);

  printf("\nNaziv goriva: ");
  printf("%s",gor.naziv);

  printf("\nCena: ");
  printf("%.2f",gor.cena);

  printf("\nPopust (koeficijent): ");
  printf("%.2f",gor.popust);

  printf("\nKolicina (litri): ");
  printf("%.2f",gor.kolicina);

  printf("\n");
}

void ispisiGoriva() //Vracar
{
  FILE * f = fopen(GORIVO_NAZIV, "rb");
    if(f==NULL)
    {
        printf("GRESKA! Fajl ne postoji!");
    }
  gorivo temp;
  while(fread(&temp,sizeof(gorivo),1,f)!=0)
  {
    //fread(&temp,sizeof(gorivo),1,f);
    ispisiGorivo(temp);
  };
    fclose(f);
}

void ispisiProdaju(prodaja prod) //Vracar
{
    printf("\nSifra:\n ");
    printf("\t%i",prod.sifra);

    printf("\nKolicina (u litrima):\n");
    printf("\t%.2f",prod.kolicina);

    printf("\nZarada:\n");
    printf("\t%.2f",prod.zarada);

    printf("\nVreme prodaje:\n");
    printf("\t%s",prod.vremeProdaje);

    printf("\n\n");
}

void ispisiProdaje()  //Vracar
{
    FILE * f = fopen(PRODAJA_NAZIV, "rb");
    if(f==NULL)
    {
        printf("GRESKA! Fajl ne postoji!");
    }
    prodaja temp;
    while(fread(&temp,sizeof(prodaja),1,f)!=0)
    {
        ispisiProdaju(temp);
    };
    fclose(f);
}
