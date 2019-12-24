//
//  isWord.c
//  Matala3
//
//  Created by Maks Moroshek on 11/24/19.
//  Copyright © 2019 Maks Moroshek. All rights reserved.
//

#include "isWord.h"
#include <stdbool.h>

bool isWord (char s[]){
    return (!strcmp(s,"CAT") |
            !strcmp(s,"SMART")|
    !strcmp(s,"CATS") |
    !strcmp(s,"TRAM") |
    !strcmp(s,"TRAMS") |
    !strcmp(s,"TAME") |
    !strcmp(s,"CAR") |
    //!strcmp(s,"CARS") |
    !strcmp(s,"RAT") |
    !strcmp(s,"RATS") |
    !strcmp(s,"RAMP") |
    !strcmp(s,"ART") |
    !strcmp(s,"CART") |
    !strcmp(s,"STAMP") |
    !strcmp(s,"TAKEN") |
    !strcmp(s,"MEN") |
    !strcmp(s,"MAKE") |
    !strcmp(s,"TAKE") |
    !strcmp(s,"ATE") |
    !strcmp(s,"SELL") |
            !strcmp(s,"RAKE")|
            !strcmp(s,"STEEL") |
            !strcmp(s,"START")|
            !strcmp(s,"KARATE")|
            !strcmp(s,"RATE"));
}

