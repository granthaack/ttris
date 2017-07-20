#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <stdbool.h>
#include <stdint.h>
#include "spi.h"

//MACROS	
#define BLACK 1
#define WHITE 0

#define DATA 1
#define COMM 0

#define DD_DC           DDB1
#define DD_RST          DDB0

#define PORT_DC         (1 << PB1)
#define PORT_RST        (1 << PB0)

//Tetrimino Sprite Definitions
//J piece
//Down
#define J_D_H 4
#define J_D_W 6
#define J_D_X 1
#define J_D_Y 13
//Left
#define J_L_H 6
#define J_L_W 4
#define J_L_X 18
#define J_L_Y 13
//Up
#define J_U_H 4
#define J_U_W 6
#define J_U_X 13
#define J_U_Y 13
//Right
#define J_R_H 6
#define J_R_W 4
#define J_R_X 20
#define J_R_Y 13

//L Piece
//Up
#define L_U_H 4
#define L_U_W 6
#define L_U_X 25
#define L_U_Y 13
//Left
#define L_L_H 6
#define L_L_W 4
#define L_L_X 32
#define L_L_Y 13
//Down
#define L_D_H 4
#define L_D_W 6
#define L_D_X 37
#define L_D_Y 13
//Right
#define L_R_H 6
#define L_R_W 4
#define L_R_X 44
#define L_R_Y 13

//T Piece
//Right
#define T_R_H 4
#define T_R_W 6
#define T_R_X 49
#define T_R_Y 13
//Down
#define T_D_H 6
#define T_D_W 4
#define T_D_X 68
#define T_D_Y 13
//Left
#define T_L_H 4
#define T_L_W 6
#define T_L_X 49
#define T_L_Y 13
//Up
#define T_U_H 6
#define T_U_W 4
#define T_U_X 63
#define T_U_Y 13

//I Piece
//Right
#define I_R_H 8
#define I_R_W 2
#define I_R_X 73
#define I_R_Y 13
//Up
#define I_U_H 2
#define I_U_W 8
#define I_U_X 76
#define I_U_Y 13

//Z Piece
//Right
#define Z_R_H 6
#define Z_R_W 4
#define Z_R_X 11
#define Z_R_Y 18
//Up
#define Z_U_H 4
#define Z_U_W 6
#define Z_U_X 1
#define Z_U_Y 18

//S Piece
//Right
#define S_R_H 6
#define S_R_W 4
#define S_R_X 25
#define S_R_Y 18
//Up
#define S_U_H 4
#define S_U_W 6
#define S_U_X 17
#define S_U_Y 20

//O Piece
//Up
#define O_U_H 4
#define O_U_W 4
#define O_U_X 76
#define O_U_Y 16

//CONSTANTS
//Declare the frame buffer
uint8_t fbuff[6][84];

//Declare the spritemap graphics
uint8_t spritemap[3][84];

//STRUCTS
typedef struct sprite
{
	//The x and y coordinates of where the sprite appears on the spritemap
	uint8_t x_map;
	uint8_t y_map;
	//The x and y coordinates of where the sprite will be drawn on the screen. 
	//(0,0) of the sprite is the sprite's upper left hand corner
	uint8_t x_pos;
	uint8_t y_pos;
	//The x and y coordinates of the sprite on the previous frame. This is here
	//to make sprite animation possible
	uint8_t x_ppos;
	uint8_t y_ppos;
	//The width and height of the sprite
	uint8_t wdth;
	uint8_t hght;
	//The collision byte. Bit 1 = collide bottom, bit 2 = collide top, 
	//bit 3 = collide right, bit 4 = collide left
	//Note that these directions are defined for a screen in landscape mode
	//with the origin in the upper left hand corner
	uint8_t coll;
};

typedef struct string_sprite
{
	uint8_t x_pos;
	uint8_t y_pos;
	char* str;
};

//FUNCTIONS
//Send data to the screen
void send_byte(uint8_t data, bool dc);
//Initialize the screen into the proper mode
void init_screen(void);
//Sets the x address in the screen's ddram
void set_ddram_x_addr(uint8_t x);
//Sets the y address in the screen's ddram. Note that this takes the address of the
//BYTE of ddram you want to modify, not the index of the pixel you want to modify.
void set_ddram_y_addr(uint8_t y);
//This function sets pixels in the display. Instead of changing the frame
//buffer and sending the whole buffer to the screen, this function only changes
//the necessary pixels on the display. Note that the x and y address of the current
void set_pixel(uint8_t x, uint8_t y, bool color);
//Blank one frame of the display
void blank_display();
//This function can read pixels in the spritemap or fbuff
bool read_pixel(uint8_t x, uint8_t y, uint8_t arr[][84]);
//Remove the sprite from the screen
void clear_sprite(struct sprite* spr);
//Draw a sprite on the screen
void draw_sprite(struct sprite* spr);
//Get the y coordinate of a char on the spritemap
int get_sprite_char_y_map(char c);
//Get the x coordinate of a char on the spritemap
int get_sprite_char_x_map(char c);
//Draw a string on the screen
void draw_string(struct string_sprite* str);

#endif