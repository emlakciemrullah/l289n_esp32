#ifndef L298N_H
#define L298N_H

#include "driver/gpio.h"
#include <stdio.h>

#define IO_SET_1 1
#define IO_SET_2 2

#define DIRECTION_1 1
#define DIRECTION_2 2

typedef struct motor_t {
    int io_set,
        direction,
        enx;
} motor_t;

typedef struct pin_configuration_t {
    int i1_pin, i2_pin, i3_pin, i4_pin,
        ena_pin, enb_pin;
} pin_configuration_t;

static inline void go_go_motor(motor_t motor, pin_configuration_t pin_configuration){
    if(motor.io_set == IO_SET_1){
        switch(motor.direction){
            case DIRECTION_1:
                gpio_set_level((gpio_num_t)pin_configuration.i1_pin, 1);
                gpio_set_level((gpio_num_t)pin_configuration.i2_pin, 0);
                gpio_set_level((gpio_num_t)pin_configuration.ena_pin, motor.enx);
            break;

            case DIRECTION_2:
                gpio_set_level((gpio_num_t)pin_configuration.i1_pin, 0);
                gpio_set_level((gpio_num_t)pin_configuration.i2_pin, 1);
                gpio_set_level((gpio_num_t)pin_configuration.ena_pin, motor.enx);
            break;
        }
    }
    else{
        switch(motor.direction){
            case DIRECTION_1:
                gpio_set_level((gpio_num_t)pin_configuration.i3_pin, 1);
                gpio_set_level((gpio_num_t)pin_configuration.i4_pin, 0);
                gpio_set_level((gpio_num_t)pin_configuration.enb_pin, motor.enx);
            break;

            case DIRECTION_2:
                gpio_set_level((gpio_num_t)pin_configuration.i3_pin, 0);
                gpio_set_level((gpio_num_t)pin_configuration.i4_pin, 1);
                gpio_set_level((gpio_num_t)pin_configuration.enb_pin, motor.enx);
            break;
        }
    }
}

#endif
