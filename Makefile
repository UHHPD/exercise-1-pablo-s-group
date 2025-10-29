CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Wextra

all: hallo summieren stichprobe

hallo: hallo.cc
	$(CXX) $(CXXFLAGS) -o hallo hallo.cc

summieren: summieren.cc
	$(CXX) $(CXXFLAGS) -o summieren summieren.cc

stichprobe: stichprobe.cc
	$(CXX) $(CXXFLAGS) -o stichprobe stichprobe.cc

clean:
	rm -f hallo summieren stichprobe *.o

.PHONY: all clean
