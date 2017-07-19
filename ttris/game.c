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
	
}