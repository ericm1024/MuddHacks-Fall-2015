/**
 * \file stepper_motor.cpp
 * \author Eric Mueller
 */

#include "stepper_motor.hpp"
#include "../lib/libpi.h"

#include <thread>

using namespace std::this_thread;
using namespace std::chrono;

stepper_motor::stepper_motor(unsigned a1_pin, unsigned a2_pin,
                             unsigned b1_pin, unsigned b2_pin)
        : a1_pin_(a1_pin), a2_pin_(a2_pin), b1_pin_(b1_pin), b2_pin_(b2_pin)
{
        pi_gpio_fsel(a1_pin, GF_OUTPUT);
        pi_gpio_fsel(a2_pin, GF_OUTPUT);
        pi_gpio_fsel(b1_pin, GF_OUTPUT);
        pi_gpio_fsel(b2_pin, GF_OUTPUT);
}

void stepper_motor::step_forward(milliseconds delay) const
{
        set_step(1, 0, 1, 0);
        sleep_for(delay);
        set_step(0, 1, 1, 0);
        sleep_for(delay);
        set_step(0, 1, 0, 1);
        sleep_for(delay);
        set_step(1, 0, 0, 1);
        sleep_for(delay);
}

void stepper_motor::step_back(milliseconds delay) const
{
        set_step(1, 0, 0, 1);
        sleep_for(delay);
        set_step(0, 1, 0, 1);
        sleep_for(delay);
        set_step(0, 1, 1, 0);
        sleep_for(delay);
        set_step(1, 0, 1, 0);
        sleep_for(delay);
}

void stepper_motor::set_step(bool a1, bool a2, bool b1, bool b2) const
{
        pi_gpio_write(a1_pin_, a1);
        pi_gpio_write(a2_pin_, a2);
        pi_gpio_write(b1_pin_, b1);
        pi_gpio_write(b2_pin_, b2);
}
