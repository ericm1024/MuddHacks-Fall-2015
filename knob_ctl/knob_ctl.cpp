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
#include <iostream>

using namespace boost::gil;

void knob_ctl_base::move_to(unsigned x, unsigned y)
{
        move_x(x - get_x());
        move_y(y - get_y());
}

knob_ctl_img::knob_ctl_img(unsigned width, unsigned height,
                           unsigned reset_x, unsigned reset_y)
        : knob_ctl_base(width, height, reset_x, reset_y),
          img_(get_width(), get_height()), xloc_(0), yloc_(0)
{
        clear();
}

knob_ctl_img::~knob_ctl_img()
{
}

void knob_ctl_img::move_x(int dx)
{
        int dif = dx > 0 ? 1 : -1;
        unsigned xfinal = xloc_ + dx;

        assert(xfinal < get_width());

        while (xloc_ != xfinal) {
                xloc_ += dif;
                write_pix();
        }
}

void knob_ctl_img::move_y(int dy)
{
        int dif = dy > 0 ? 1 : -1;
        unsigned yfinal = yloc_ + dy;

        assert(yfinal < get_height());

        while (yloc_ != yfinal) {
                yloc_ += dif;
                write_pix();
        }
}

void knob_ctl_img::clear()
{
        rgb8_pixel_t white_px(255, 255, 255);
        fill_pixels(view(img_), white_px);
        move_to(get_reset_x(), get_reset_y());
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
        v(xloc_, get_height() - (yloc_ + 1)) = black_px;
}
