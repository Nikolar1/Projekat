//
//  Pumpa.c
//  BPumpa_ProjektniZad
//
//  Created by Milos,Nikola on 09.06.17.
//  Copyright © 2017 Milos Ancevski. All rights reserved.
//

#include "Pumpa.h"
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

void Prodaja(){
	stanjegoriva temp = PretragaGoriva();
	FILE* f;
    f = fopen("EvidencijaProdaje.dat","ab");
	fwrite(&temp.Ime,sizeof(char),strlen(temp.Ime),f); //upis imena u fajl
    float f1,f2;
	do{
    printf("Koliko litara goriva zelite prodati: ");
    scanf("%f",&f1);
	if(f1<temp.stanje){
		printf("\nNemate dovoljno goriva na stanju. Imate samo %f litara. Pokusajte ponovo.\n",temp.stanje);
	}
	}while(f1<temp.stanje);
    temp.stanje -= f1;
	fwrite(&f1,sizeof(float),1,f); //upis litara u fajl
    f1 *= temp.Cena;
	fwrite(&f1,sizeof(float),1,f); //upis cene pre akcije u fajl
	fwrite(&temp.akcija,sizeof(float),1,f); //upis akcije u fajl
    printf("\nCena: %.2f",f1);
    printf("\nAkcija: %f",temp.akcija);
    f1 *= ((MAX_PROC - temp.akcija)/MAX_PROC);
    printf("\nZa uplatu: %f",f1);
	fwrite(&f1,sizeof(float),1,f); //upis cene posle akcije u fajl
	do{
		printf("\nKoliko dinara je uplaceno: ");
		scanf("%f",&f2);
		if(f2<f1){
			printf("\nNije uplaceno dovoljno novca. Pokusajte ponovo.\n");
		}
	}while(f2<f1);
	fwrite(&f2,sizeof(float),1,f); //upis uplacene kolicine novca u fajl
    f2 -= f1;
    printf("\nPovracaj: %f",f2);
	fwrite(&f2,sizeof(float),1,f); //upis kolicine novca koju treba vratiti u fajl
    printf("\nLitara na stanju: %f\n",temp.stanje);
	fclose(f);
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

stanjegoriva PretragaGoriva(){
  do{
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
  fclose(f);
	}while(temporary!=0);
  return temp;
}

void promenastanja(){
	stanjegoriva temp = PretragaGoriva();
    printf("Unesite novo stanje goriva\n");
    scanf("%f",temp.stanje);
    fseek(f,0-sizeof(stanjegoriva),SEEK_CUR);
    fwrite(&temp,sizeof(stanjegoriva),1,f);
  }
}
