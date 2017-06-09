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
    scanf("%f",&p->Cena);
    printf("\nCena je uspesno izmenjena.\n");
}

void DodajAkciju(Gorivo* p){
    printf("\nZa koliko procenata zelite da snizite zenu goriva? ");
    scanf("%f",&p->Akcija);
    printf()
}
