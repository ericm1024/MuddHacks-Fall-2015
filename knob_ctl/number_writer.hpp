/**
 * \file number_writer.hpp
 * \author Eric Mueller
 * \brief Header for the nubmer writing code. Leverages knob_ctl.hpp
 */

#include "knob_ctl.hpp"
#include <utility>
#include <initializer_list>

namespace detail {

struct distance {
        std::pair<int,int> get() const
        {
                return std::pair<int,int>(x_, y_);
        }
protected:
        int x_ = 0;
        int y_ = 0;
};

}; // namespace detail

class number_writer {
public:
        // d{width,height} are the width and height of the digits to write
        // in the same units understood by knob_ctl. thickness is how
        // wide to draw th digits (think bubble letters)
        number_writer(knob_ctl_base& kc, unsigned dwidth,
                      unsigned dheight, unsigned thickness, unsigned space)
                : kc_(kc), w_(dwidth), h_(dheight), t_(thickness),
                  s_(space)
        {
                assert(thickness < dwidth/2);
        }

        // write a number between 0 and 9 to the knob controller
        // the knob is moved during this function call, but is returned
        // to its original location upon return
        void write(unsigned num);

        // clear the display
        void clear();
private:
        using write_seq_t = std::initializer_list<detail::distance>;
        
        void write_sequence(write_seq_t seq);
        
        knob_ctl_base& kc_;
        const int w_;
        const int h_;
        const int t_;
        const int s_;
};
