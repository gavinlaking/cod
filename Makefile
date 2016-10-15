Target = cod
Sources = ./src/cursor.cpp ./src/cod.cpp
CXX = g++
CXXFLAGS = -O3
DESTPATH = ./bin/$(Target)

all: all_linux
all_linux:
	$(CXX) $(CXXFLAGS) $(Sources) -o $(DESTPATH)

clean: clean_linux
clean_linux:
	@$(RM) $(DESTPATH)

.PHONY: all clean clean_linux
