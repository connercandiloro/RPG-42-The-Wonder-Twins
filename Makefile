CCFLAGS = -Wall -Wextra -std=c++2a -fsanitize=address

a.out: main.o jjkcurselord.o attributes.o
	g++ $(CCFLAGS) main.o jjkcurselord.o attributes.o -lncurses
main.o: main.cc
	g++ $(CCFLAGS) -c main.cc
jjkcurselord.o: jjkcurselord.cc
	g++ $(CCFLAGS) -c jjkcurselord.cc
attributes.o: attributes.cc
	g++ $(CCFLAGS) -c attributes.cc
clean: 
	rm -f a.out core *.o