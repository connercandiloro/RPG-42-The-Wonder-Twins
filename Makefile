CC = g++
CCFLAGS = -Wall -Wextra -std=c++2a -fsanitize=address
LDFLAGS = -fsanitize=address -lasan -lncurses
MODULES = main.o ncurses/ncurses.so

a.out: $(MODULES)
	$(CC) $(MODULES) $(LDFLAGS)
main.o: main.cc
	$(CC) $(CCFLAGS) -c main.cc
clean:
	rm -f a.out core *.o