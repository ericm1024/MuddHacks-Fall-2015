/**
 * \file number_writer.cpp
 * \author Eric Mueller
 * \brief Number writing code. Lots of nasty constants
 */

#include "number_writer.hpp"

#include <cassert>
#include <algorithm>
#include <iostream>

struct x : detail::distance {
        x(int dist)
        {
                x_ = dist;
        }
};

struct y : detail::distance {
        y(int dist)
        {
                y_ = dist;
        }
};

void number_writer::write_sequence(write_seq_t seq)
{
        std::for_each(seq.begin(), seq.end(), [&](auto& i) {
                        kc_.move_xy(i.get());
                });
}

// I'm not proud of this
void number_writer::write(unsigned num)
{
        assert(num < 10);
        
        switch (num) {
        case 0:
                write_sequence(
                        {y(h_), x(w_), y(-h_), x(-w_),
                        x(t_), y(h_ - t_), x(w_ - 2*t_), y(-(h_ - 2*t_)),
                        x(-(w_ - 2*t_)), y(-t_), x(-t_)});
                break;

 
        case 1:
                write_sequence({y(h_), x(t_), y(-h_), x(-t_)});
                break;

        case 2:
                write_sequence({
                        y((h_ + t_)/2), x(w_ - t_), y((h_ - 3*t_)/2),
                        x(-(w_ - t_)), y(t_),
                        x(w_), y(-(h_ + t_)/2), x(-(w_ - t_)),
                        y(-(h_ - 3*t_)/2), x(w_ - t_), y(-t_), x(-w_)});
                break;

        case 3:
                write_sequence({y(t_), x(w_ - t_), y((h_ - 3*t_)/2),
                        x(-(w_ - t_)), y(t_), x(w_ - t_), y((h_ - 3*t_)/2),
                        x(-(w_ - t_)), y(t_),
                        x(w_), y(-h_), x(-w_)});
                break;

        case 4:
                write_sequence({x(w_ - t_), y((h_-t_)/2), x(-(w_-t_)),
                        y((h_+t_)/2), x(t_), y(-(h_-t_)/2), x(w_-2*t_),
                        y((h_-t_)/2), x(t_), y(-h_), x(-w_)});
                break;

        case 5:
                write_sequence({y(t_), x(w_-t_), y((h_-3*t_)/2), x(-(w_-t_)),
                        y((h_+t_)/2), x(w_), y(-t_), x(-(w_-t_)),
                        y(-(h_-3*t_)/2), x(w_-t_), y(-(h_+t_)/2), x(-w_)});
                break;

        case 6:
                write_sequence({y(h_), x(w_), y(-t_), x(-(w_-t_)),
                        y(-(h_-3*t_)/2), x(w_-t_), y(-(h_+t_)/2),
                        x(-w_), x(t_), y((h_-t_)/2), x(w_-2*t_),
                        y(-(h_-3*t_)/2), x(-(w_-2*t_)), y(-t_), x(-t_)});
                break;

        case 7:
                write_sequence({x(w_-t_), y(h_-t_), x(-(w_-t_)), y(t_),
                        x(w_), y(-h_), x(-w_)});
                break;

        case 8:
                write_sequence({y(h_), x(w_), y(-h_), x(-w_), x(t_),
                        y(h_-t_), x(w_-2*t_), y(-(h_-3*t_)/2), x(-(w_-2*t_)),
                        y(-t_), x(w_-2*t_), y(-(h_-3*t_)/2), x(-(w_-2*t_)),
                        y(-t_), x(-t_)});
                break;

        case 9:
                write_sequence({x(w_-t_), y(h_-t_), x(-(w_-2*t_)),
                        y(-(h_-3*t_)/2), x(w_-2*t_), y(-t_),
                        x(-(w_-t_)), y((h_+t_)/2), x(w_), y(-h_), x(-w_)});
                break;
        }
}
