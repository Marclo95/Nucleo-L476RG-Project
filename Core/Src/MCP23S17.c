#include "MCP23S17.h"
#include "main.h" // pour les définitions de VU_nCS_GPIO_Port et VU_nCS_Pin

extern SPI_HandleTypeDef hspi3;  // SPI utilisé pour le MCP23S17

void MCP23S17_WriteRegister(uint8_t reg, uint8_t value)
{
    uint8_t txData[3];
    txData[0] = MCP23S17_ADDRESS;  // Opcode avec bit Write = 0
    txData[1] = reg;               // Registre cible
    txData[2] = value;             // Donnée à écrire

    // Mettre CS à l'état bas pour commencer la communication
    HAL_GPIO_WritePin(MCP23S17_CS_GPIO_Port, MCP23S17_CS_Pin, GPIO_PIN_RESET);

    // Transmettre les 3 octets (adresse + registre + valeur)
    HAL_SPI_Transmit(&hspi3, txData, 3, HAL_MAX_DELAY);

    // Remettre CS à l'état haut pour terminer la communication
    HAL_GPIO_WritePin(MCP23S17_CS_GPIO_Port, MCP23S17_CS_Pin, GPIO_PIN_SET);
}
