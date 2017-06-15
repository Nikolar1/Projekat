//
//  Vreme.c
//  BPumpa_ProjektniZad
//
//  Created by Aleksa on 06.06.17.
//  Copyright © 2017 Aleksa Vujnic. All rights reserved.
//

#include "Vreme.h"  //Rastko

void ispisiDatum(time_t mytime)
{
    mytime = time(NULL);
    //printf(ctime(&mytime));
    struct tm *timeInfo;
    timeInfo = localtime(&mytime);
    
    printf("Dan:  %i Mesec: %i Godina: %i\n", timeInfo->tm_wday, timeInfo->tm_mon, timeInfo->tm_year + 1900);
}


void ispisiVreme(time_t mytime) //Rastko
{
    mytime = time(NULL);
    //printf(ctime(&mytime));
    struct tm *timeInfo;
    timeInfo = localtime(&mytime);
    
    printf("Sati: %i Minute: %i Sekunde: %i \n", timeInfo->tm_hour, timeInfo ->tm_min, timeInfo->tm_sec);
}

