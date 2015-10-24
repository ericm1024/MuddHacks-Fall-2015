/**
 * \file stepper_motor.hpp
 * \author Eric Mueller
 * \brief Class to control a stepper motor. Implementation from
 * https://learn.adafruit.com/adafruits-raspberry-pi-lesson-10-stepper-motors?view=all
 */

#ifndef STEPPER_MOTOR_HPP
#define STEPPER_MOTOR_HPP

#include <chrono>

class stepper_motor {
public:
        stepper_motor(unsigned a1_pin, unsigned a2_pin,
                      unsigned b1_pin, unsigned b2_pin);
        void step_forward(std::chrono::milliseconds delay) const;
        void step_back(std::chrono::milliseconds delay) const;
private:
        void set_step(bool a1, bool a2, bool b1, bool b2) const;
        const unsigned a1_pin_, a2_pin_, b1_pin_, b2_pin_;
};

#endif // STEPPER_MOTOR_HPP
