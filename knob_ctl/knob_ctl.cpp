/**
 * \file knob_ctl.cpp
 * \author Eric Mueller
 * \brief Implementation of knob control for Etch-A-Sketch. Contains a dummy
 * implementation (knob_ctl_img) that writes out images, and the hardware
 * implementation (knob_ctl_hw) that uses the actual Etch-A-Sketch.
 */

// bullshit for libpng compat
#define png_infopp_NULL ((png_infopp)NULL)
#define int_p_NULL ((int*)NULL)

#include "knob_ctl.hpp"
#include <boost/gil/extension/io/png_dynamic_io.hpp>

#include <algorithm>
#include <cassert>

using namespace boost::gil;

knob_ctl_img::knob_ctl_img()
        : knob_ctl_base(WIDTH, HEIGHT),
          img_(get_width(), get_height()), xloc_(0), yloc_(0)
{
        clear();
}

knob_ctl_img::~knob_ctl_img()
{
}

void knob_ctl_img::move_x(int dx)
{
        assert(dx + xloc_ < get_width());

        int dif = dx > 0 ? 1 : -1;
        unsigned xfinal = xloc_ + dx;

        while (xloc_ != xfinal) {
                xloc_ += dif;
                write_pix();
        }
}

void knob_ctl_img::move_y(int dy)
{
        assert(dy + yloc_ < get_height());

        int dif = dy > 0 ? 1 : -1;
        unsigned yfinal = yloc_ + dy;

        while (yloc_ != yfinal) {
                yloc_ += dif;
                write_pix();
        }
}

void knob_ctl_img::clear()
{
        rgb8_pixel_t white_px(255, 255, 255);
        fill_pixels(view(img_), white_px);
        xloc_ = 0;
        yloc_ = 0;
        write_pix();
}

void knob_ctl_img::write_to(const std::string& fname)
{
        png_write_view(fname, const_view(img_));
}

void knob_ctl_img::write_pix()
{
        rgb8_pixel_t black_px(0, 0, 0);
        auto v = view(img_);
        v(xloc_, yloc_) = black_px;
}

int main(int argc, char **argv)
{
        knob_ctl_img kc;

        kc.write_to("test_begin.png");
        kc.move_x(100);
        kc.move_y(100);
        kc.move_x(100);
        kc.move_y(100);
        kc.write_to("test_end.png");
}
