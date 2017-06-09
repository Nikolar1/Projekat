//
//  Zaposleni.c
//  BPumpa_ProjektniZad
//
//  Created by Milan, Milos, Nikola, Rastko and Aleksa on 02.06.17.
//  Copyright © 2017 Aleksa Vujnic. All rights reserved.
//

#include "Zaposleni.h"


void unesiZaposlenog()
{
    FILE * f = fopen(ZAP_NAZIV, "a+b");
    zaposleni temp;
    
    printf("\tIme zaposlenog:\n ");
    scanf("\n%s",&temp.ime);
    
    printf("\tPrezime zaposlenog:\n");
    scanf("\n%s",&temp.prezime);
    
    printf("\tIdentifikacioni broj zaposlenog (jedinstven ceo broj) \n");
    scanf("\n%s",&temp.idBroj);
    
    temp.Zaposlenje = time(NULL);
    //c_time_string = ctime(&current_time);
    
    temp.idStatus = 0;
    
    fwrite(&temp, sizeof(zaposleni), 1, f);
}

void unesiSefa()
{
    FILE * f = fopen(ZAP_NAZIV, "a+b");
    zaposleni temp;
    
    printf("\tIme sefa:\n ");
    scanf("\n%s",&temp.ime);
    
    printf("\tPrezime sefa:\n");
    scanf("\n%s",&temp.prezime);
    
    printf("\tIdentifikacioni broj sefa (jedinstven ceo broj) \n");
    scanf("\n%s",&temp.idBroj);
    
    temp.Zaposlenje = time(NULL);
    //c_time_string = ctime(&current_time);
    
    temp.idStatus = 1;
    
    fwrite(&temp, sizeof(zaposleni), 1, f);
}

