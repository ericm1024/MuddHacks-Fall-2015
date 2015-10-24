/**
 * \file clock.hpp
 * \author Eric Mueller
 * \brief Clock class for actually writing shit out
 */

#include "number_writer.hpp"

namespace mudd_hacks {

class clock {
public:
        clock(number_writer& nw);
        void run();
private:
        number_writer& nw_;
};

};
