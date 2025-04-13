#ifndef INC_LED_H_
#define INC_LED_H_

#include "stm32l4xx_hal.h"
#include "stm32l4xx_hal_tim.h"

typedef struct {
    GPIO_TypeDef *port;
    uint16_t pin;
    TIM_HandleTypeDef *htim;
    uint32_t timerChannel;
    uint8_t currentBrightness;
} Led_t;

void LedInit(Led_t *led, GPIO_TypeDef *port, uint16_t pin, TIM_HandleTypeDef *htim, uint32_t timerChannel);
void LedOn(Led_t *led);
void LedOff(Led_t *led);
void LedSetBrightness(Led_t *led, uint8_t brightness);
void LedPulse(Led_t *led);

#endif /* INC_LED_H_ */
