 #define F_CPU  16000000UL

#include <util/delay.h>
#include <avr/sleep.h>
#include <stdint.h>

#include "game.h"

int main(void)
{
	struct sprite tmino;
	tmino.x_pos = X_ORIGIN;
	tmino.y_pos = Y_ORIGIN;
	tmino.x_ppos = X_ORIGIN;
	tmino.y_ppos = Y_ORIGIN;

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
	//Initialize the random number generator
	init_rand();
	//White out the display
	blank_display();
	/*
	set_ddram_x_addr(10);
	set_ddram_y_addr(0/8);
	set_pixel(10, 2, BLACK);
	set_ddram_x_addr(10);
	set_ddram_y_addr(0/8);
	set_pixel(10, 3, BLACK);
	set_ddram_x_addr(10);
	set_ddram_y_addr(0/8);
	set_pixel(10, 4, BLACK);
	*/
	spawn_new_tmino(&tmino);
	//draw_string(&tetris);
	//draw_string(&sjsu);
	//_delay_ms(10);
	
	while(1)
	{
		if(!(tmino.coll & LFT_COLL_BIT))
		{
			soft_drop(&tmino);
		}
		else
		{
			spawn_new_tmino(&tmino);
		}
	}
	//End execution of code
	sleep_mode();
	return(0);
}