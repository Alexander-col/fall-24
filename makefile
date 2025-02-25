CXX = g++
CXXFLAGS = -std=c++17 -g -Wall -O2

PROG ?= main
# OBJS = Main.o File.o 
OBJS = MyTests.o Folder.o File.o 
# OBJS = Book.o Textbook.o Manual.o Novel.o  main.o


all: $(PROG)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(PROG): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

clean:
	rm -rf $(EXEC) *.o *.out main 

rebuild: clean all