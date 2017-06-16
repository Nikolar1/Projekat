//
//  Vreme.c
//  BPumpa_ProjektniZad
//
//  Created by Aleksa on 06.06.17.
//  Copyright © 2017 Aleksa Vujnic. All rights reserved.
//

#include "Vreme.h" //Rastko


void UpisiVreme(char * vremestr) //Rastko
{
    time_t current_time;
    struct tm * time_info;
    time(&current_time);
    time_info = localtime(&current_time);
    strftime(vremestr,STR_LEN*sizeof(char), "%X %x", time_info);
}
