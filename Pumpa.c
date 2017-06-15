//
//  Pumpa.c
//  BPumpa_ProjektniZad
//
//  Created by Milos,Nikola on 09.06.17.
//  Copyright © 2017 Nikola Radojcic. All rights reserved.
//

#include "Pumpa.h"
<<<<<<< HEAD

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
  printf("\nUnesite sifru goriva koje zelite da prodate:  ");
  int tempid;
  scanf("%i",&tempid);
  printf("Unesite kolicinu goriva (u litrima):");
  float tempkol;
  scanf("%f", &tempkol);
  fseek(f,0,SEEK_SET);
  gorivo temp;
  prodaja temp1;
  temp1.sifra = tempid;
  temp1.vremeProdaje = time(NULL);
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
  printf("\nUnesite sifru goriva kom zelite da promenite cenu:\n");
  int tempid;
  scanf("%i",&tempid);
  fseek(f,0,SEEK_SET);
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
  printf("\nUnesite sifru goriva kom zelite da promenite popust:\n");
  int tempid;
  scanf("%i",&tempid);
  fseek(f,0,SEEK_SET);
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

void ispisiGorivo(gorivo gor) //Vracar
{
    //printf("\nGorivo:%s sifra:%i cena po litru:%.2f koef. popusta:%.2f preostalo:%.2f litara",gor.naziv,gor.sifra,gor.cena,gor.popust,gor.kolicina);
    
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
  fseek(f,0,SEEK_SET);
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
    ispisiDatum(prod.vremeProdaje);
    ispisiVreme(prod.vremeProdaje);
    
    printf("\n\n");
}

void ispisiProdaje()  //Vracar
{
    FILE * f = fopen(PRODAJA_NAZIV, "rb");
    fseek(f,0,SEEK_SET);
    prodaja temp;
    while(fread(&temp,sizeof(prodaja),1,f)!=0)
    {
        //fread(&temp,sizeof(prodaja),1,f);
        ispisiProdaju(temp);
    };
    fclose(f);
=======
#define MAX_PROC 100.0

void PromeniCenu(Gorivo* p){
stanjegoriva Dizel, Benzin, TNG;

void PromeniCenu(stanjegoriva* p){
    printf("\nStara cena goriva je: %f.\n\nUnesite novu cenu: ",p->Cena);
    scanf("%f",&p->Cena);
    printf("\nCena je uspesno izmenjena.\n");
}

void DodajAkciju(stanjegoriva* p){
    printf("\nZa koliko procenata zelite da snizite zenu goriva? ");
    scanf("%f",&p->akcija);
    printf("\nAkcija je uspesno izmenjena.\n");
}

void EvidencijaProdaje(char ImeGoriva[], float Litri,float Cena,float Akcija,float Ukupno,float Uplaceno,float Povracaj){
    FILE* f;
    f = fopen("EvidencijaProdaje.txt","a");
    fprintf(f,"\r\n==========\r\n");
    fprintf(f,"\n%s%f","Gorivo:",ImeGoriva);
    fprintf(f,"\n%s%f","Litara:",Litri);
    fprintf(f,"\n%s%f","Cena:",Cena);
    fprintf(f,"\n%s%f","Akcija:",Akcija);
    fprintf(f,"\n%s%f","Za uplatu:",Ukupno);
    fprintf(f,"\n%s%f","Uplaceno:",Uplaceno);
    fprintf(f,"\n%s%f\n","Povracaj:",Povracaj);
    fclose(f);
}

void Prodaja(stanjegoriva* p){
    float Litri,Cena,Ukupno,Uplaceno,Povracaj;
    printf("Koliko litara goriva zelite prodati: ");
    scanf("%f",&Litri);
    Cena = (p->Cena) * Litri;
    printf("\nCena: %.2f",Cena);
    printf("\nAkcija: %f",p->akcija);
    Ukupno = (MAX_PROC - p->akcija) * Cena;
    printf("\nZa uplatu: %f",Ukupno);
    printf("\nKoliko dinara je uplaceno: ");
    scanf("%f",&Uplaceno);
    Povracaj = Uplaceno - Ukupno;
    printf("\nPovracaj: %f",Povracaj);
    EvidencijaProdaje(p->Ime,Litri,Cena,p->akcija,Ukupno,Uplaceno,Povracaj);
    p->stanje -= Litri;
    printf("\nLitara na stanju: %f\n",p->stanje);
}

void reggorivo(){
  printf("\tUnesite naziv novog goriva\n");
  stanjegoriva temp;
  scanf("%s",&temp.Ime[]);
  printf("\tIdentifikacioni broj goriva (jedinstven ceo broj) \n");
  scanf("%d",&temp.ID);
  printf("\tUnesite cenu goriva \n");
  scanf("%f",&temp.Cena);
  printf("\tUnesite stanje goriva \n");
  scanf("%f",&temp.stanje);
  printf("\tUnesite akciju na gorivo \n");
  scanf("%f",&temp.akcija);
  FILE *f = fopen(GR_NAZIV,"a+b");
  fwrite(&temp,sizeof(stanjegoriva),1,f);
  fclose(f);
}

void promenastanja(){
  printf("\tUnesite naziv goriva kojem zelite da menjate stanje\n");
  char naziv[STR_LEN];
  scanf("%s",&naziv);
  int temporary = 1;
  stanjegoriva temp;
  FILE *f = fopen(GR_NAZIV,"rb");
  while (fread(&temp,sizeof(stanjegoriva),1,f)!=NULL){
    fread(temp,sizeof(stanjegoriva),1,f);
    if(strcmp(temp.ime,naziv)==0){
      temporary=0;
      break;
    }
  }
  if(temporary==1){
    printf("\tOdabrali ste nepostojece gorivo\n");
  }
  else{
    printf("Unesite novo stanje goriva\n");
    scanf("%f",temp.stanje);
    fseek(f,0-sizeof(stanjegoriva),SEEK_CUR);
    fwrite(&temp,sizeof(stanjegoriva),1,f);
  }
>>>>>>> origin/master
}
