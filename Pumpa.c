//
//  Pumpa.c
//  BPumpa_ProjektniZad
//
//  Created by Milos,Nikola on 09.06.17.
//  Copyright © 2017 Nikola Radojci. All rights reserved.
//

#include "Pumpa.h"


void PromeniCenu(Gorivo* p){
    printf("\nStara cena goriva je: %f.\n\nUnesite novu cenu: ",p->Cena);
    scanf("")
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
}
