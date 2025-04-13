# TP_Microcontroleur_Aserne_Farag
2 Le GPIO Expander et le VU-Metre
2.1 Configuration
  1. Quelle est la référence du GPIO Expander ? Vous aurez besoin de sa datasheet, téléchargez-la.
   R. La référence du GPIO Expander utilisé est MCP23S17. Il s'agit d'un expander de ports SPI 16 bits fabriqué par Microchip.
  2. Sur le STM32, quel SPI est utilisé ?
   R. Le module SPI utilisé sur le STM32 est SPI1.
   Il est connecté aux broches suivantes :
    SCK : PC10
    MISO : PC11
    MOSI : PB5
  3. Quels sont les paramètres à configurer dans STM32CubeIDE ?
    Les paramètres SPI configurés dans STM32CubeIDE sont :
    SPI Mode : Full-Duplex Master
    Data size : 4 bits
    Clock polarity (CPOL) : Low
    Clock phase (CPHA) : First edge
    NSS : Software
    Direction : 2-line full duplex
  3 Le CODEC Audio SGTL5000
  3.1 Configuration préalables
   Les broches utilisées pour la communication I2C sont :
    SCL : PB6
    SDA : PB7
Ces broches sont connectées au module I2C1 du STM32.
Elles sont configurées en mode Alternate Function Open-Drain, comme requis par le protocole I2C.
  3.2 Configuration du CODEC par l’I2C
1. À l’aide d’un oscilloscope, vérifiez la présence d’une horloge sur le signal
MCLK.
R. Nous avons malheureusement perdu la clé contenant la capture d'ecran.
