Target = cod
Sources = ./src/cursor.cpp \
					./src/buffer.cpp \
					./src/keypress.cpp \
					./src/options.cpp \
					./src/terminal.cpp \
					./src/cod.cpp

# CXX = clang++-3.9
CXX = g++
CXXFLAGS = -O3 -Wall
DESTPATH = ./bin/$(Target)

all: all_linux
all_linux:
	$(CXX) $(CXXFLAGS) $(Sources) -o $(DESTPATH)

clean: clean_linux
clean_linux:
	@$(RM) $(DESTPATH)

.PHONY: all clean clean_linux
