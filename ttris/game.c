#include "game.h"

void check_collision(struct sprite* spr)
{
	//Clear all the collisions since they will be recalculated
	spr->coll ^= spr->coll;
	
	//SCREEN COLLISIONS
	//If sprite has collided with the left of the screen
	if(spr->x_pos <= 0)
	{
		//Set the 4th collision bit
		spr->coll |= 0b00001000;
	}

	//If sprite has collided with the top of the screen
	if(spr->y_pos <= 0)
	{
		//Set the 2nd collision bit
		spr->coll |= 0b00000010;
	}
	
	//If sprite has collided with the right of the screen
	if(((spr->x_pos)+spr->wdth) >= 83)
	{
		//Set the 3rd collision bit
		spr->coll |= 0b00000100;
	}

	//If sprite has collided with the bottom of the screen
	if(((spr->y_pos)+spr->hght) >= 47)
	{
		//Set the 1st collision bit
		spr->coll |= 0b00000001;
	}
	
	//PIECE COLLISIONS
	//Check if sprite has left collided with another piece if it hasn't already collided with a wall
	if(!(spr->coll & 0b00001000))
	{
			//Scan the sprite column by column
			bool spr_px = 0;
			bool fbf_px = 0;
			for(uint8_t x = 0; x < spr->wdth; x++)
			{
				for(uint8_t y = 0;  y < spr->hght; y++)
				{
					//Get the current sprite pixel from the spritemap
					spr_px = read_pixel((spr->x_map+x), (spr->y_map+y), spritemap);
					//Get the current fbuff pixel directly to the left of the current sprite pixel in the fbuff
					fbf_px = read_pixel((spr->x_pos + x - 1), (spr->y_pos + y), fbuff);
					//If the pixel to the left of an active sprite pixel in the fbuff is 1 AND it's not a sprite pixel, there is a collision
					if(fbf_px && spr_px && (!(read_pixel((spr->x_map + x - 1), (spr->y_map+y), spritemap))))
					{
						//Set the 4th collision bit and break the loop
						spr->coll |= 0b00001000;
						break;
					}
				}
				//If a left collision has been detected, don't look for any more left collisions
				if(spr->coll & 0b00001000)
				{
					break;
				}
			}
	}

	//Check if sprite has right collided with another piece if it hasn't already collided with a wall
	if(!(spr->coll & 0b00000100))
	{
			//Scan the sprite column by column
			bool spr_px = 0;
			bool fbf_px = 0;
			for(uint8_t x = 0; x < spr->wdth; x++)
			{
				for(uint8_t y = 0;  y < spr->hght; y++)
				{
					//Get the current sprite pixel from the spritemap
					spr_px = read_pixel((spr->x_map+x), (spr->y_map+y), spritemap);
					//Get the current fbuff pixel directly to the right of the current sprite pixel in the fbuff
					fbf_px = read_pixel((spr->x_pos + x + 1), (spr->y_pos + y), fbuff);
					//If the pixel to the right of an active sprite pixel in the fbuff is 1 AND it's not a sprite pixel, there is a collision
					if(fbf_px && spr_px && (!(read_pixel((spr->x_map + x + 1), (spr->y_map+y), spritemap))))
					{
						//Set the 3rd collision bit and break the loop
						spr->coll |= 0b00000100;
						break;
					}
				}
				//If a right collision has been detected, don't look for any more right collisions
				if(spr->coll & 0b00000100)
				{
					break;
				}
			}
	}

	//Check if sprite has top collided with another piece if it hasn't already collided with a wall
	if(!(spr->coll & 0b00000010))
	{
		//Scan the sprite column by column
		bool spr_px = 0;
		bool fbf_px = 0;
		for(uint8_t x = 0; x < spr->wdth; x++)
		{
			for(uint8_t y = 0;  y < spr->hght; y++)
			{
				//Get the current sprite pixel from the spritemap
				spr_px = read_pixel((spr->x_map+x), (spr->y_map+y), spritemap);
				//Get the current fbuff pixel directly above of the current sprite pixel in the fbuff
				fbf_px = read_pixel((spr->x_pos + x), (spr->y_pos + y - 1), fbuff);
				//If the pixel above an active sprite pixel in the fbuff is 1 AND it's not a sprite pixel, there is a collision
				if(fbf_px && spr_px && (!(read_pixel((spr->x_map + x), (spr->y_map+y-1), spritemap))))
				{
					//Set the 2nd collision bit and break the loop
					spr->coll |= 0b00000010;
					break;
				}
			}
			//If a top collision has been detected, don't look for any more top collisions
			if(spr->coll & 0b00000010)
			{
				break;
			}
		}
	}

	//Check if sprite has bottom collided with another piece if it hasn't already collided with a wall
	if(!(spr->coll & 0b00000001))
	{
		//Scan the sprite column by column
		bool spr_px = 0;
		bool fbf_px = 0;
		for(uint8_t x = 0; x < spr->wdth; x++)
		{
			for(uint8_t y = 0;  y < spr->hght; y++)
			{
				//Get the current sprite pixel from the spritemap
				spr_px = read_pixel((spr->x_map+x), (spr->y_map+y), spritemap);
				//Get the current fbuff pixel directly below the current sprite pixel in the fbuff
				fbf_px = read_pixel((spr->x_pos + x), (spr->y_pos + y + 1), fbuff);
				//If the pixel below an active sprite pixel in the fbuff is 1 AND it's not a sprite pixel, there is a collision
				if(fbf_px && spr_px && (!(read_pixel((spr->x_map + x), (spr->y_map+y+1), spritemap))))
				{
					//Set the 1st collision bit and break the loop
					spr->coll |= 0b00000001;
					break;
				}
			}
			//If a left collision has been detected, don't look for any more left collisions
			if(spr->coll & 0b00000001)
			{
				break;
			}
		}
	}
}

//initialize the random number generator
void init_rand()
{
	uint32_t state;
	static uint32_t EEMEM sstate;
	//If eeprom is unwritten, initialize it with something
	if (state == 0xffffffUL)
	{
		state = 0xdebc0decUL;
	}
	srand(state);
	eeprom_write_dword(&sstate, rand());
}

void soft_drop(struct sprite* spr)
{
	spr->x_pos -= 2;
	draw_sprite(spr);
	return;
}

void spawn_new_tmino(struct sprite* spr)
{
	//Reset the coordinates without allowing the draw_frame function to erase the old piece
	spr->x_pos = X_ORIGIN;
	spr->y_pos = Y_ORIGIN;
	spr->x_ppos = X_ORIGIN;
	spr->y_ppos = Y_ORIGIN;
	//Clear the collision data
	spr->coll ^= spr->coll;
	//Get a random number between 0 and 6 with bitmasking and casting
	uint8_t r_piece = 0;
	r_piece = rand();
	r_piece = r_piece & 0x0F;
	if(r_piece > 6)
	{
		r_piece -= 9;
	}
	//Use it to choose a new piece to drop
	switch(r_piece)
	{
		//Drop a J piece
		case(0):
		{
			spr->hght = J_R_H;
			spr->wdth = J_R_W;
			spr->x_map = J_R_X;
			spr->y_map = J_R_Y;
			break;
		};
		//Drop a L piece
		case(1):
		{
			spr->hght = L_L_H;
			spr->wdth = L_L_W;
			spr->x_map = L_L_X;
			spr->y_map = L_L_Y;
			break;
		};
		//Drop a T piece
		case(2):
		{
			spr->hght = T_U_H;
			spr->wdth = T_U_W;
			spr->x_map = T_U_X;
			spr->y_map = T_U_Y;
			break;
		};
		//Drop a I piece
		case(3):
		{
			spr->hght = I_U_H;
			spr->wdth = I_U_W;
			spr->x_map = I_U_X;
			spr->y_map = I_U_Y;
			break;
		};
		//Drop an S piece
		case(4):
		{
			spr->hght = S_R_H;
			spr->wdth = S_R_W;
			spr->x_map = S_R_X;
			spr->y_map = S_R_Y;\
			break;
		};
		//Drop a Z piece
		case(5):
		{
			spr->hght = Z_R_H;
			spr->wdth = Z_R_W;
			spr->x_map = Z_R_X;
			spr->y_map = Z_R_Y;
			break;
		};
		//Drop an O piece
		case(6):
		{
			spr->hght = O_U_H;
			spr->wdth = O_U_W;
			spr->x_map = O_U_X;
			spr->y_map = O_U_Y;
			break;
		};
	}
}