/**
 * \file number_writer.hpp
 * \author Eric Mueller
 * \brief Header for the nubmer writing code. Leverages knob_ctl.hpp
 */

#include "knob_ctl.hpp"
#include <cassert>

class number_writer {
public:
        // d{width,height} are the width and height of the digits to write
        // in the same units understood by knob_ctl. thickness is how
        // wide to draw th digits (think bubble letters)
        number_writer(knob_ctl_base& kc, unsigned dwidth,
                      unsigned dheight, unsigned thickness)
                : kc_(kc), w_(dwidth), h_(dheight), t_(thickness)
        {
                assert(thickness < dwidth/2);
        }

        // write a number between 0 and 9 to the knob controller
        // the knob is moved during this function call, but is returned
        // to its original location upon return
        void write(unsigned num);
private:
        knob_ctl_base& kc_;
        const unsigned w_;
        const unsigned h_;
        const unsigned t_;
};
