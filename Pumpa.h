//
//  Pumpa.h
//  BPumpa_ProjektniZad
//
//  Created by Milos,Nikola on 09.06.17.
//  Copyright © 2017 Milos Ancevski. All rights reserved.
//

#ifndef Pumpa_h
#define Pumpa_h
#define GR_NAZIV "gorivo.dat"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stanjegoriva{
    int ID;
    float Cena;
    char Ime[20];
    float akcija;
    float stanje;
}stanjegoriva;

#endif /* Pumpa_h */
