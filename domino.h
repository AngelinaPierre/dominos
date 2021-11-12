/**
 * @file domino.h
 * @author Angelina Pierre (gaptp95@gmail.com)
 * @brief Library of the domino's game 
 * @version 0.1
 * @date 2021-11-12
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#ifndef DOMINO_H
#define DOMINO_H

#include <stdlib.h>
#include <stdio.h>

#define NUMBER_tiles 28
#define MAX_HAND 6

typedef struct tiles { // tiles = pedras
    int left; // after ordenated top
    int right;
}tp_tiles;

void view_tile(tp_tiles tile){
    printf("[|%d|\n|%d|]",tile.left,tile.right);
}



#endif