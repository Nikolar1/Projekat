//
//  Zaposleni.h
//  BPumpa_ProjektniZad
//
//  Created by Milan, Milos, Nikola, Rastko and Aleksa on 02.06.17.
//  Copyright © 2017 Aleksa Vujnic. All rights reserved.
//

#ifndef Zaposleni_h
#define Zaposleni_h
#define STR_LEN 20
#define ZAP_NAZIV "zaposleni.dat"
#define STZAP_NAZIV "statusiZaposlenih.dat"
#define ST_NAZIV "status.dat"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Vreme.h"

typedef struct Zaposleni
{
    int idBroj;
    char ime[STR_LEN];
    char prezime[STR_LEN];
    char username[STR_LEN];
    char password[STR_LEN];
    char Zaposlenje[STR_LEN];
    char Otkaz[STR_LEN];
    int idStatus;
} zaposleni;

typedef struct StatusiZaposlenih
{
    int idBroj;
    char vremePromene[STR_LEN];
    int idStatus;
} statusiZaposlenih;

typedef struct Statusi
{
    int brStatus;
    char status[STR_LEN];
} statusi;

void unesiZaposlenog();
void unesiSefa();
void dajOtkaz();
void proglasSefa();
void ukloniSefa();
void ispisiZaposlenog(zaposleni);
void ispisiZaposlene();
void ispisiPromenu(statusiZaposlenih);
void ispisiPromene();
void inicijalizujStatus();

#endif /* Zaposleni_h */
