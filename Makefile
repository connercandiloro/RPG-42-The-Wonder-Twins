CC = g++
CCFLAGS = -Wall -Wextra -std=c++2a 
MODULES = Thread_Lord.o main.o player.o ui.o attributes.o cutscenes.o  combat.o dialogue.o heroes.o monsters.o 
LDFLAGS = -fsanitize=address -lasan -lncurses

a.out: $(MODULES)
	$(CC) $(MODULES) -o $@ $(LDFLAGS)
Thread_Lord.o: Thread_Lord.cc
	$(CC) $(CCFLAGS) -c $< -o $@
main.o: main.cc
	$(CC) $(CCFLAGS) -c $< -o $@
player.o: player.cc
	$(CC) $(CCFLAGS) -c $< -o $@
ui.o: ui.cc
	$(CC) $(CCFLAGS) -c $< -o $@
attributes.o: attributes.cc
	$(CC) $(CCFLAGS) -c $< -o $@
cutscenes.o: cutscenes.cc
	$(CC) $(CCFLAGS) -c $< -o $@
combat.o: combat.cc
	$(CC) $(CCFLAGS) -c $< -o $@
dialogue.o: dialogue.cc
	$(CC) $(CCFLAGS) -c $< -o $@
heroes.o: heroes.cc
	$(CC) $(CCFLAGS) -c $< -o $@
monsters.o: monsters.cc
	$(CC) $(CCFLAGS) -c $< -o $@
#client.o: client.cc
#	$(CC) $(CCFLAGS) -c client.cc
#server.o: server.cc
#	$(CC) $(CCFLAGS) -c server.cc client.o server.o

clean: 
	rm -f a.out *.o
