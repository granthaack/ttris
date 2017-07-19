#include "spi.h"

// Initialize SPI Master Device (with SPI interrupt)
void spi_init_master (void)
{
	// Set MOSI, SCK, SS as Output
	DDR_SPI=(1<<DD_MOSI)|(1<<DD_SCK)|(1<<DD_SS);

	// Enable SPI, Set as Master
	// Prescaler: Fosc/16, Enable Interrupts
	SPCR=(1<<SPE)|(1<<MSTR)|(1<<SPR0);
}