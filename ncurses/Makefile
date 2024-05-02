CC = g++
CCFLAGS = -Wall -Wextra -std=c++2a -fsanitize=address
LDFLAGS = -shared
MODULES = player.o ui.o attributes.o

a.out: main.o ./ncurses.so
	$(CC) main.o ./ncurses.so -fsanitize=address -lasan -lncurses
main.o: main.cc
	$(CC) $(CCFLAGS) -c main.cc
ncurses.so: $(MODULES)
	$(CC) $(LDFLAGS) -o $@ $(MODULES) -lncurses
player.o: player.cc
	$(CC) $(CCFLAGS) -fPIC -c player.cc
ui.o: ui.cc
	$(CC) $(CCFLAGS) -fPIC -c ui.cc
attributes.o: attributes.cc
	$(CC) $(CCFLAGS) -fPIC -c attributes.cc
clean: 
	rm -f a.out core *.o