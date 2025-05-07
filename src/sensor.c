#include <stdio.h>
#include <stdlib.h>
#include "lib/sensor.h"
#include "pico/stdlib.h"
#include "hardware/adc.h"

void init_temp_sensor()
{
    adc_init();
    adc_set_temp_sensor_enabled(true);
}
float temperature_read()
{
    adc_select_input(temp_sensor);
    uint16_t raw_value = adc_read();
    const float conversion_factor = 3.3f / (1 << 12);
    return  27.0f - ((raw_value * conversion_factor) - 0.706f) / 0.001721f;
}