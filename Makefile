CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Wextra

all: hallo summieren stichprobe stichprobe2

hallo: hallo.cc
	$(CXX) $(CXXFLAGS) -o hallo hallo.cc

summieren: summieren.cc
	$(CXX) $(CXXFLAGS) -o summieren summieren.cc

stichprobe: stichprobe.cc
	$(CXX) $(CXXFLAGS) -o stichprobe stichprobe.cc

stichprobe2: stichprobe2.cc
	$(CXX) $(CXXFLAGS) -o stichprobe2 stichprobe2.cc

clean:
	rm -f hallo summieren stichprobe stichprobe2 *.o

.PHONY: all clean
