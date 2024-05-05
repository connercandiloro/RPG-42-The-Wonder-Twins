CC = g++
CCFLAGS = -Wall -Wextra -std=c++2a -fsanitize=address
MODULES = main.o player.o ui.o attributes.o cutscenes.o  combat.o dialogue.o heroes.o monsters.o
LDFLAGS = -fsanitize=address -lasan -lncurses

a.out: $(MODULES)
	$(CC) $(MODULES) $(LDFLAGS)
main.o: main.cc
	$(CC) $(CCFLAGS) -c main.cc
player.o: player.cc
	$(CC) $(CCFLAGS) -c player.cc
ui.o: ui.cc
	$(CC) $(CCFLAGS) -c ui.cc
attributes.o: attributes.cc
	$(CC) $(CCFLAGS) -c attributes.cc
cutscenes.o: cutscenes.cc
	$(CC) $(CCFLAGS) -c cutscenes.cc
combat.o: combat.cc
	$(CC) $(CCFLAGS) -c combat.cc
dialogue.o: dialogue.cc
	$(CC) $(CCFLAGS) -c dialogue.cc
heroes.o: heroes.cc
	$(CC) $(CCFLAGS) -c heroes.cc
monsters.o: monsters.cc
	$(CC) $(CCFLAGS) -c monsters.cc
clean: 
	rm -f a.out *.o