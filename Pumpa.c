//
//  Pumpa.c
//  BPumpa_ProjektniZad
//
//  Created by Milos,Nikola on 09.06.17.
//  Copyright © 2017 Milos Ancevski. All rights reserved.
//

#include "Pumpa.h"
#define MAX_PROC 100.0

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
