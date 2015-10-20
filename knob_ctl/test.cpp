
#include "number_writer.hpp"

int main()
{
        knob_ctl_img kc;
        number_writer nw(kc, 50, 50, 6);

        kc.move_y(-kc.get_height() + 20);
        kc.move_x(20);

        nw.write(0);
        kc.write_to("test_one_zero.png");
}
