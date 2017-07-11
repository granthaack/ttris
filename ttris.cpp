#define F_CPU  16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

typedef unsigned char byte;

//Define the SPI Pins to communicate with the screen
//Define the data direction registers
#define DDR_SPI         DDRB
#define DD_SCK          DDB5
#define DD_MISO         DDB4
#define DD_MOSI         DDB3
#define DD_SS           DDB2
#define DD_DC           DDB1

//Define the port registers
#define PORT_SPI        PORTB
#define PORT_SCK        (1 << PB5)
#define PORT_MISO       (1 << PB4)
#define PORT_MOSI       (1 << PB3)
#define PORT_SS         (1 << PB2)
#define PORT_DC         (1 << PB1)

// Initialize SPI Master Device (with SPI interrupt)
void spi_init_master (void)
{
    // Set MOSI, SCK, SS as Output. Even though other SS pins will be used
    //during operation, if this SS pin is not initialized here, SPI will not
    //work. Apparently that's just how the microcontroller is built.
    DDRB=(1<<DD_MOSI)|(1<<DD_SCK)|(1<<DD_SS)|(1<<DD_DC);
    //Set the other SS pins as outputs and pull them high

    // Enable SPI, Set as Master
    // Prescaler: Fosc/16, Enable Interrupts
    //The MOSI, SCK pins are as per ATMega8
    SPCR=(1<<SPE)|(1<<MSTR)|(1<<SPR0);
}

//Function to send and receive data for both master and slave
byte spi_tranceiver(byte data)
{
    // Load data into the buffer
    SPDR = data;

    //Wait until transmission complete
    while(!(SPSR & (1<<SPIF)));

    // Return received data
    return(SPDR);
}

int main(void)
{
  return;
}
