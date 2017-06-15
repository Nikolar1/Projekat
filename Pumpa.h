//
//  Pumpa.h
//  BPumpa_ProjektniZad
//
//  Created by Aleksa on 02.06.17.
//  Copyright © 2017 Aleksa Vujnic. All rights reserved.
//

#ifndef Pumpa_h
#define Pumpa_h

#define STR_LEN 20
#define GORIVO_NAZIV "gorivo.dat"
#define PRODAJA_NAZIV "prodaja.dat"
#define ST_NAZIV "status.dat"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "Vreme.h"

typedef struct Gorivo
{
    int sifra;
    char naziv[STR_LEN];
    float cena;
    float kolicina;
    float popust;
} gorivo;

typedef struct Prodaja
{
    int sifra;
    time_t vremeProdaje;
    float kolicina;
    float zarada;
} prodaja;

void registrujGorivo();
void prodajGorivo(); //UPDATING
void promeniCenu(); //UPDATING
void promeniPopust(); //UPDATING
void ispisiGorivo(gorivo);
void ispisiGoriva();
void ispisiProdaju(prodaja);
void ispisiProdaje();

#endif /* Pumpa_h */
