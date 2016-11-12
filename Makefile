Target = cod
Sources = ./src/buffer.cpp \
					./src/cursor.cpp \
					./src/keypress.cpp \
					./src/options.cpp \
					./src/render.cpp \
					./src/terminal.cpp \
					./src/cod.cpp

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
