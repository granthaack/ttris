 #define F_CPU  16000000UL

#include <util/delay.h>
#include <avr/sleep.h>
#include <stdint.h>

#include "game.h"

int main(void)
{
	struct sprite tmino;
	tmino.x_map = 49;
	tmino.y_map = 9;
	tmino.x_pos = 15;
	tmino.y_pos = 0;
	tmino.x_ppos = 15;
	tmino.y_ppos = 0;
	tmino.wdth = 6;
	tmino.hght = 4;

/*
	struct string_sprite tetris;
	struct string_sprite sjsu;
	char tetris_s[] = "TETRIS";
	char sjsu_s[] = "SJSU GAMEDEV";
	tetris.str = tetris_s;
	tetris.x_pos = 0;
	tetris.y_pos = 48;
	sjsu.str = sjsu_s;
	sjsu.x_pos = 6;
	sjsu.y_pos = 48;
*/
	//Initialize the SPI bus
	spi_init_master();
	//Initialize the screen
	init_screen();
	blank_display();
	//draw a test pattern
	set_ddram_x_addr(10);
	set_ddram_y_addr(0/8);
	set_pixel(10, 2, BLACK);
	set_pixel(10, 3, BLACK);
	set_pixel(10, 4, BLACK);
	draw_sprite(&tmino);
	//draw_string(&tetris);
	//draw_string(&sjsu);
	//_delay_ms(10);
	while(!(tmino.coll & 0b00001000))
	{
		tmino.x_pos--;
		_delay_ms(50);
		draw_sprite(&tmino);
	}
	//End execution of code
	sleep_mode();
	return(0);
}