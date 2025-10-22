CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Wextra

all: hallo summieren

hallo: hallo.cc
	$(CXX) $(CXXFLAGS) -o hallo hallo.cc

summieren: summieren.cc
	$(CXX) $(CXXFLAGS) -o summieren summieren.cc

clean:
	rm -f hallo summieren *.o

.PHONY: all clean
