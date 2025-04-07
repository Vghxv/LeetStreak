GXX = clang++
CXX_STANDARD = -std=gnu++20
CXXFLAGS = -g -lgtest -lgtest_main -pthread
FILE = $(F)
BASE_NAME = $(notdir $(FILE))
TARGET = ../bin/$(basename $(BASE_NAME))

all: run

build: $(FILE) | bin
	$(GXX) $(CXX_STANDARD) $(FILE) $(CXXFLAGS) -o $(TARGET) 

bin:
	mkdir -p bin

run: build
	./$(TARGET)

clean:
	rm -f $(TARGET)
