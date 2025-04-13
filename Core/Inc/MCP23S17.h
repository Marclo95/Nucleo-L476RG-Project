#ifndef MCP23S17_H
#define MCP23S17_H

#include "stm32l4xx_hal.h"

#define MCP23S17_CS_GPIO_Port GPIOA
#define MCP23S17_CS_Pin       GPIO_PIN_4


// Adresse SPI du MCP23S17 (si A0–A2 = 0)
#define MCP23S17_ADDRESS  0x40

// Registres principaux
#define MCP23S17_IODIRA   0x00
#define MCP23S17_IODIRB   0x01
#define MCP23S17_GPIOA    0x12
#define MCP23S17_GPIOB    0x13
#define MCP23S17_IOCON    0x0A

// Prototype de la fonction
void MCP23S17_WriteRegister(uint8_t reg, uint8_t value);

#endif // MCP23S17_H
