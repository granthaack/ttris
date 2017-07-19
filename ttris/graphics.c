#include "graphics.h"

//Define the fbuff
uint8_t fbuff[6][84] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

//Define the spritemap graphics
uint8_t spritemap[2][84] = {0x00, 0x6e, 0x8a, 0xea, 0x8a, 0xee, 0x00, 0x64, 0x84, 0xe4, 0x84, 0x84, 0x00, 0x6e, 0x82, 0xee, 0xa8, 0xee, 0x00, 0xae, 0xa2, 0xee, 0xa2, 0xae, 0x00, 0xea, 0x4a, 0x4e, 0x42, 0xe2, 0x00, 0x2e, 0x28, 0x2e, 0xa2, 0x6e, 0x00, 0xae, 0xa8, 0xce, 0xaa, 0xae, 0x00, 0x8e, 0x82, 0x82, 0x82, 0xe2, 0x00, 0xae, 0xea, 0xee, 0xaa, 0xae, 0x00, 0xae, 0xea, 0xee, 0xe2, 0xae, 0x00, 0x44, 0xaa, 0xae, 0xaa, 0x4a, 0x00, 0xcc, 0xaa, 0xec, 0x8a, 0x8e, 0x00, 0x46, 0xa8, 0xa8, 0xe8, 0x6e, 0x00, 0xcc, 0xaa, 0xea, 0xca, 0xae, 0x00, 0x46, 0x48, 0x44, 0x02, 0x4e, 0x00, 0xee, 0x24, 0x64, 0x04, 0x44, 0x00, 0xaa, 0xaa, 0x0a, 0xaa, 0x46, 0x00, 0xaa, 0x4a, 0xea, 0x44, 0xa4, 0x00, 0x0a, 0x0a, 0x0e, 0x0e, 0x4a, 0x00, 0x4a, 0x4a, 0x04, 0x0a, 0x0a, 0x00, 0xea, 0xea, 0xe4, 0xe4, 0xe4, 0x00, 0x0e, 0x02, 0x04, 0x08, 0x0e, 0x00, 0x06, 0x06, 0x1e, 0x1e, 0x18, 0x18, 0x00, 0x18, 0x18, 0x1e, 0x1e, 0x06, 0x06, 0xc0, 0xc6, 0xf6, 0xf6, 0xc6, 0xc6, 0x06, 0xc6, 0xc6, 0xc0, 0xc6, 0xf6, 0xf6, 0x06, 0x1e, 0x1e, 0x00, 0x1e, 0x1e, 0x1e, 0x1e, 0x00, };

void send_byte(uint8_t data, bool dc)
{
	// Load data into the buffer
	SPDR = data;

	//If DC is high, pull the pin high
	if(dc)
	{
		PORT_SPI |= (PORT_DC);
	}

	//Wait until transmission complete
	while(!(SPSR & (1<<SPIF)));

	//Pull DC low again if it was set high
	if(dc)
	{
		PORT_SPI &= ~(PORT_DC);
	}
	return;
}

void init_screen(void)
{
	DDR_SPI|=((1<<DD_DC)|(1<<DD_RST));
	//Toggle the reset pin then set it high
	PORT_SPI |= (PORT_RST);
	PORT_SPI &= ~(PORT_RST);
	PORT_SPI |= (PORT_RST);

	//send a byte to init function set
	send_byte(0b00100001, COMM);
	//send byte to init Vop
	send_byte(0b10010000, COMM);
	//send byte to select normal instruction set
	send_byte(0b00100000, COMM);
	//send byte to set screen to normal mode
	send_byte(0b00001100, COMM);
	//set x DDRAM address to 0
	send_byte(0b10000000, COMM);
	//set y DDRAM address to 0
	send_byte(0b01000000, COMM);
}

//Sets the x address in the screen's ddram
void set_ddram_x_addr(uint8_t x)
{
	send_byte((x | 0b10000000), COMM);
}

//Sets the y address in the screen's ddram. Note that this takes the address of the 
//BYTE of ddram you want to modify, not the index of the pixel you want to modify.
void set_ddram_y_addr(uint8_t y)
{
	send_byte((y | 0b01000000), COMM);
}

//This function sets pixels in the display. Instead of changing the frame
//buffer and sending the whole buffer to the screen, this function only changes
//the necessary pixels on the display. Note that the x and y address of the current
void set_pixel(uint8_t x, uint8_t y, bool color)
{
	//if out of bounds
	if(x > 83 || y > 47)
	{
		return;
	}

	//Which byte to manipulate
	uint8_t i = y/8;
	//Which bit in the byte to manipulate
	uint8_t pos = y%8;
	//Positioning the byte for masking or oring
	uint8_t flag = 0x01;
	flag = flag << pos;

	//If setting it black, bitwise or
	if(color)
	{
		//write the changes to the internal fbuff
		fbuff[i][x] = fbuff[i][x] | flag;

		/*
		//update the y address
		uint8_t sendy = i | 0b01000000;
		send_byte(sendy, COMM);
		//update the x address
		uint8_t sendx = x | 0b10000000;
		send_byte(sendx, COMM);
		*/
		//Send the updated byte to the screen
		send_byte(fbuff[i][x], DATA);

	}

	//If setting it white, mask and bitwise and
	else
	{
		flag = ~flag;
		fbuff[i][x] = fbuff[i][x] & flag;
		/*
		//update the y address
		uint8_t sendy = i | 0b01000000;
		send_byte(sendy, COMM);
		//update the x address
		uint8_t sendx = x | 0b10000000;
		send_byte(sendx, COMM);
		*/
		//Send the updated byte to the screen
		send_byte(fbuff[i][x], DATA);
	}
}

void blank_display()
{
	uint16_t i = 505;
	do 
	{
		send_byte(0, DATA);
		--i;

	} while (i);
}

//This function can read pixels in the spritemap or fbuff
bool read_pixel(uint8_t x, uint8_t y, uint8_t arr[][84])
{
	//Which byte to check
	uint8_t i = y/8;
	//Which bit in the byte to check
	uint8_t pos = y%8;
	//Positioning the bit for checking
	uint8_t flag = 0x01;
	flag = flag << pos;

	//If there is a bit at that position, this will return true (pixel is black).
	//If there is no bit, this will return false (pixel is white)
	return arr[i][x] & flag;
}

//Remove the sprite from the screen
void clear_sprite(struct sprite* spr)
{
	for(uint8_t y = 0; y < spr->hght; y++)
	{
		set_ddram_y_addr(((spr->y_ppos + y)/8));
		for(uint8_t x = 0; x < spr->wdth; x++)
		{
			set_ddram_x_addr(spr->x_ppos + x);
			if(read_pixel(spr->x_map + x, spr->y_map + y, spritemap))
			{
				set_pixel(spr->x_ppos + x, spr->y_ppos + y, WHITE);
			}
		}
	}
}

void draw_sprite(struct sprite* spr)
{
	clear_sprite(spr);
	for(uint8_t y = 0; y < spr->hght; y++)
	{
		set_ddram_y_addr(((spr->y_pos + y)/8));
		for(uint8_t x = 0; x < spr->wdth; x++)
		{
			set_ddram_x_addr(spr->x_pos + x);
			if(read_pixel(spr->x_map + x, spr->y_map + y, spritemap))
			{
				set_pixel(spr->x_pos + x, spr->y_pos + y, BLACK);
			}
			//else
			//{
			//	set_pixel(spr->x_pos + x, spr->y_pos + y, WHITE);
			//}
		}
	}
	spr->x_ppos = spr->x_pos;
	spr->y_ppos = spr->y_pos;
	//Check to see if the sprite is now colliding with something
	check_collision(spr);

}

int get_sprite_char_y_map(char c)
{
	if (((c >= '0') && (c <= '9')) || ((c >= 'A') && (c <= 'D')))
	{
		return 0;
	}

	if((c >= 'E') && (c <= 'R'))
	{
		return 4;
	}

	if((c >= 'S') && (c <= 'Z'))
	{
		return 8;
	}
	if(c == ' ')
	{
		return 13;
	}
	else
	{
		return 0;
	}
}

int get_sprite_char_x_map(char c)
{
	if((c >= '0') && (c <= '9'))
	{
		return ((c-'0')*6);
	}

	if((c >= 'A') && (c <= 'D'))
	{
		return ((c-'A'+10)*6);
	}

	if((c >= 'E') && (c <= 'R'))
	{
		return ((c-'E')*6);
	}

	if((c >= 'S') && (c <= 'Z'))
	{
		return ((c-'S')*6);
	}
	if(c == ' ')
	{
		return 43;
	}
	else
	{
		return 0;
	}
}

void draw_string(struct string_sprite* str)
{
	struct sprite c;
	c.x_pos = str->x_pos;
	c.wdth = 6;
	c.hght = 4;
	for(int i = 0; str->str[i] != '\0'; i++)
	{
		c.x_map = get_sprite_char_x_map(str->str[i]);
		c.y_map = get_sprite_char_y_map(str->str[i]);
		c.y_pos = ((str->y_pos - (i*4))-4);
		draw_sprite(&c);
	}
}