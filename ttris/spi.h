#ifndef SPI_H
#define SPI_H

#include <avr/io.h>
#include <avr/interrupt.h>

//Define the SPI Pins to communicate with the screen
//Define the data direction registers
#define DDR_SPI         DDRB
#define DD_SCK          DDB5
#define DD_MISO         DDB4
#define DD_MOSI         DDB3
#define DD_SS           DDB2


//Define the port registers
#define PORT_SPI        PORTB
#define PORT_SCK        (1 << PB5)
#define PORT_MISO       (1 << PB4)
#define PORT_MOSI       (1 << PB3)
#define PORT_SS         (1 << PB2)

void spi_init_master (void);

#endif