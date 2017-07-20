#ifndef GAME_H
#define GAME_H

#include "graphics.h"
#include <avr/eeprom.h>
#include <stdlib.h>

#define BOT_COLL_BIT 0b00000001
#define TOP_COLL_BIT 0b00000010
#define RGT_COLL_BIT 0b00000100
#define LFT_COLL_BIT 0b00001000
#define X_ORIGIN 60;
#define Y_ORIGIN 20;

//Check for collisions with walls and pieces
void check_collision(struct sprite* spr);
//Initialize the random number generator
void init_rand();
//Soft drop a tetrimino.
void soft_drop(struct sprite* spr);
//Hard drop a tetrimino until it collides
void hard_drop(struct sprite* spr);
//Spawn a new tetrimino
void spawn_new_tmino(struct sprite* spr);
#endif