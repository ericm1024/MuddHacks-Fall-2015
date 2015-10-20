/**
 * \file number_writer.cpp
 * \author Eric Mueller
 * \brief Number writing code. Lots of nasty constants
 */

#include "number_writer.hpp"

// I'm not proud of this
void number_writer::write(unsigned num)
{
        assert(num < 10);
        
        switch (num) {
        case 0:
                // draw the outer ring of the 0
                kc_.move_y(h_);
                kc_.move_x(w_);
                kc_.move_y(-h_);
                kc_.move_x(-w_);

                // draw the inner ring
                kc_.move_x(t_);
                kc_.move_y(h_ - t_);
                kc_.move_x(w_ - 2*t_);
                kc_.move_y(-(h_ - 2*t_));
                kc_.move_x(-(w_ - 2*t_));
                kc_.move_y(-t_);
                kc_.move_x(-t_);
                break;

        case 1:
                break;

        case 2:
                break;

        case 3:
                break;

        case 4:
                break;

        case 5:
                break;

        case 6:
                break;

        case 7:
                break;

        case 8:
                break;

        case 9:
                break;
        }
}
