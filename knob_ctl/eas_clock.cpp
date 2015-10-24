#include "clock.hpp"
#include "../lib/libpi.h"

/* pin assignments for the x motor */
#define X_MOT_A1_PIN 5
#define X_MOT_A2_PIN 6
#define X_MOT_B1_PIN 19
#define X_MOT_B2_PIN 26

/* pin assignments for the y motor */
#define Y_MOT_A1_PIN 21
#define Y_MOT_A2_PIN 12
#define Y_MOT_B1_PIN 20
#define Y_MOT_B2_PIN 16

/* pin assignments for the clear motor */
#define C_MOT_A1_PIN 4
#define C_MOT_A2_PIN 17
#define C_MOT_B1_PIN 22
#define C_MOT_B2_PIN 27

/* 4x this time in ms is taken for each step */
#define STEP_DELAY_MS std::chrono::milliseconds(5)

/* how mant steps to move when clearing the Etch-A-Sketch */
#define CLEAR_STEPS 110

/* width of the clock digits in steps */
#define WIDTH_STEPS 40

/* height of the clock digits in steps */
#define HEIGHT_STEPS 60

/* thickness of the bubble letters */
#define THICKNESS_STEPS 10

/* spacing between the clock digits */
#define SPACING_STEPS 15

int main()
{
        pi_mem_setup();
//        stepper_motor x_motor(X_MOT_A1_PIN, X_MOT_A2_PIN,
//                              X_MOT_B1_PIN, X_MOT_B2_PIN);

        stepper_motor y_motor(Y_MOT_A1_PIN, Y_MOT_A2_PIN,
                              Y_MOT_B1_PIN, Y_MOT_B2_PIN);


        for (;;)
                y_motor.step_forward(STEP_DELAY_MS);
        
//        stepper_motor clear_motor(C_MOT_A1_PIN, C_MOT_A2_PIN,
//                                  C_MOT_B1_PIN, C_MOT_B2_PIN);

//        knob_ctl_hw kc(x_motor, y_motor, clear_motor,
//                       STEP_DELAY_MS, CLEAR_STEPS);

//        number_writer nw(kc, WIDTH_STEPS, HEIGHT_STEPS,
//                         THICKNESS_STEPS, SPACING_STEPS);

//        mudd_hacks::clock ck(nw);
//        ck.run();
}
