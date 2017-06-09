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
  scanf("%s",temp.Ime[]);
  printf("%s\n", );
  printf("\tIdentifikacioni broj goriva (jedinstven ceo broj) \n");
  scanf("\n%s",&temp.ID);
  printf("\tUnesite cenu goriva \n");
  scanf("\n%s",&temp.Cena);
  printf("\tUnesite stanje goriva \n");
  scanf("\n%s",&temp.stanje);
  printf("\tUnesite akciju na gorivo \n");
  scanf("\n%s",&temp.akcija);
  FILE *f = fopen(GR_NAZIV,"a+b");
  fwrite(temp,sizeof(stanjegoriva),1,f);
  fclose(f);
}
