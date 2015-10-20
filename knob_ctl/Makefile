CXX=clang++
CXXFLAGS=-std=c++14 -Wall -Wextra -pedantic
LDFLAGS=-lpng
OBJS=knob_ctl.o number_writer.o

all: test $(OBJS)

clean:
	rm -f $(OBJS)

knob_ctl.o: knob_ctl.cpp knob_ctl.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

number_writer.o: number_writer.cpp number_writer.hpp knob_ctl.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

test: test.cpp $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)
