/**
 * \file clock.cpp
 * \author Eric Mueller
 * \brief Clock implementation.
 */

#include "clock.hpp"

#include <chrono>
#include <ctime>
#include <thread>

using namespace std;
using namespace chrono;

namespace mudd_hacks {

clock::clock(number_writer& nw)
        : nw_(nw)
{}

void clock::run()
{
        auto write_2dig_number = [&](int x) {
                nw_.write(x/10);
                nw_.write(x%10);
        };
        
        for (;;) {
                time_t t = time(nullptr);
                tm *lt = localtime(&t);
                system_clock::time_point after, before = system_clock::now();

                write_2dig_number(lt->tm_hour%12);
                write_2dig_number(lt->tm_min);
                
                after = system_clock::now();
                if (after - before < minutes(1))
                        this_thread::sleep_for(after - before);

                nw_.clear();
        }
}

};
