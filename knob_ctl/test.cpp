
#include "number_writer.hpp"
#include <iostream>

int main()
{
        knob_ctl_img kc(1350, 512, 20, 20);
        number_writer nw(kc, 100, 200, 24);

        for (unsigned i = 0; i < 10; ++i) {
                nw.write(i);
                kc.move_x(120);
        }
        kc.write_to("test_one_zero.png");
}
