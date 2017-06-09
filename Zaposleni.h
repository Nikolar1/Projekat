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

typedef struct Zaposleni
{
    int idBroj;
    char ime[STR_LEN];
    char prezime[STR_LEN];
    time_t Zaposlenje;
    time_t Otkaz;
    int idStatus;
} zaposleni;

typedef struct StatusiZaposlenih
{
    int idBroj;
    time_t vremePromene;
    int idStatus;
} statusiZaposlenih;

typedef struct Statusi
{
    int brStatus;
    char status[STR_LEN];
} statusi;

#endif /* Zaposleni_h */
