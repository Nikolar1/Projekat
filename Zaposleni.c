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

    printf("\tKosristnicko ime zaposlenog:\n");
    scanf("\n%s",&temp.username);

    printf("\tPassword zaposlenog:\n");
    scanf("\n%s",&temp.password);

    temp.Zaposlenje = time(NULL);
    //c_time_string = ctime(&current_time);

    temp.idStatus = 0;

    fwrite(&temp, sizeof(zaposleni), 1, f);
}

void napstatuse(){
  FILE *f1 = fopen(ST_NAZIV,"wb");
  statusi temp1;
  temp1.brStatus = 0;
  temp1.status[] = "Radnik";
  temp1.brStatus = 1;
  temp1.status[] = "Sef";
  temp1.brStatus = 2;
  temp1.status[] = "Obrisan";
  fwrite(temp1,sizeof(statusi),1,f1);
  fclose(f1);
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

    printf("\tKosristnicko ime sefa:\n");
    scanf("\n%s",&temp.username);

    printf("\tPassword sefa:\n");
    scanf("\n%s",&temp.password);

    temp.Zaposlenje = time(NULL);
    //c_time_string = ctime(&current_time);

    temp.idStatus = 1;

    fwrite(&temp, sizeof(zaposleni), 1, f);
}
