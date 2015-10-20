/**
 * \file knob_ctl.hpp
 * \author Eric Mueller
 * \brief Header for knob controll. See knob_ctl.cpp for details.
 */

#ifndef KNOB_CTL_HPP
#define KNOB_CTL_HPP

#include <boost/gil/gil_all.hpp>

class knob_ctl_base {
public:
        knob_ctl_base() {};
        virtual ~knob_ctl_base() {};

        // we don't want want assignment or copy construction, just to keep
        // shit simple
        virtual knob_ctl_base& operator=(const knob_ctl_base&) final = delete;
        knob_ctl_base(const knob_ctl_base&) = delete;

        // move the cursor dx units to the right (or left if dx is negative)
        virtual void move_x(int dx) = 0;

        // move the cursor dy units up (or down if dy is negative)
        virtual void move_y(int dy) = 0;

        // clear the screen
        virtual void clear() = 0;

        unsigned get_width() const
        {
                return width_;
        }

        unsigned get_height() const
        {
                return height_;
        }

protected:
        knob_ctl_base(unsigned width, unsigned height)
                : width_(width), height_(height)
        {}

private:
        // how wide is the display? units are somewhat arbitrary
        const unsigned width_ = 0;

        // similarly for height
        const unsigned height_ = 0;
};

class knob_ctl_img : public knob_ctl_base
{
public:
        knob_ctl_img();
        ~knob_ctl_img() override;
        void move_x(int dx) override;
        void move_y(int dy) override;
        void clear() override;

        // write the current state out to a file
        void write_to(const std::string& fname);

private:

        // write a black pixel at the current location
        void write_pix();
        
        static constexpr unsigned WIDTH = 512;
        static constexpr unsigned HEIGHT = 512;
        boost::gil::rgb8_image_t img_;
        unsigned xloc_;
        unsigned yloc_;
};

class knob_ctl_hw : public knob_ctl_base
{
public:
        knob_ctl_hw();
        ~knob_ctl_hw() override;
        void move_x(int dx) override;
        void move_y(int dy) override;
        void clear() override;
private:
        
};

#endif // KNOB_CTL_HPP
