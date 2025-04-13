#include "Led.h"

void LedInit(Led_t *led, GPIO_TypeDef *port, uint16_t pin, TIM_HandleTypeDef *htim, uint32_t timerChannel) {
    led->port = port;
    led->pin = pin;
    led->htim = htim;
    led->timerChannel = timerChannel;
    led->currentBrightness = 0;

    HAL_TIM_PWM_Start(led->htim, led->timerChannel); // Lance le PWM
}


void LedOn(Led_t *led) {
    LedSetBrightness(led, 255);
}

void LedOff(Led_t *led) {
    LedSetBrightness(led, 0);
}

void LedSetBrightness(Led_t *led, uint8_t brightness) {
    led->currentBrightness = brightness;
    __HAL_TIM_SET_COMPARE(led->htim, led->timerChannel, led->currentBrightness);
}

void LedPulse(Led_t *led) {
    static int increment = 1;
    led->currentBrightness += increment;
    if (led->currentBrightness >= 255) {
        led->currentBrightness = 255;
        increment = -1;
    } else if (led->currentBrightness <= 0) {
        led->currentBrightness = 0;
        increment = 1;
    }
    LedSetBrightness(led, led->currentBrightness);
}
