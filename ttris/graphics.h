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

//CONSTANTS
//Declare the frame buffer
uint8_t fbuff[6][84];

//Declare the spritemap graphics
uint8_t spritemap[2][84];

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