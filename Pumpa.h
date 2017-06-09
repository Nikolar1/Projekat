//
//  Pumpa.h
//  BPumpa_ProjektniZad
//
//  Created by Milos on 09.06.17.
//  Copyright © 2017 Milos Ancevski. All rights reserved.
//

#ifndef Pumpa_h
#define Pumpa_h

#include <stdio.h>
#include <stdlib.h>

typedef struct gorivo{
    int ID, Akcija;
    float Cena;
    char Ime[20];
    struct gorivo* Sledeci;
}Gorivo;

#endif /* Pumpa_h */
