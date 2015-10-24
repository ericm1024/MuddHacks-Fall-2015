CXX=clang++
CXXFLAGS=-std=c++14 -Wall -Wextra -pedantic
LDFLAGS=-lpng
OBJS=knob_ctl.o number_writer.o stepper_motor.o clock.o ../lib/libpi.o

all: test eas_clock

clean:
	rm -f $(OBJS)

knob_ctl.o: knob_ctl.cpp knob_ctl.hpp stepper_motor.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

number_writer.o: number_writer.cpp number_writer.hpp knob_ctl.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clock.o: clock.cpp clock.hpp number_writer.hpp knob_ctl.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

stepper_motor.o: stepper_motor.cpp stepper_motor.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

eas_clock: eas_clock.cpp $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

test: test.cpp $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)
