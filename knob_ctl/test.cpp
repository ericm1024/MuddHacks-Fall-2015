
#include "clock.hpp"
#include <iostream>

int main()
{
        knob_ctl_img kc(1350, 512, 20, 20);
        number_writer nw(kc, 100, 200, 24, 20);
        mudd_hacks::clock ck(nw);
        
        ck.run();
}
