CC = g++
CCFLAGS = -Wall -Wextra -std=c++2a -fsanitize=address -fPIC -c
LDFLAGS = -shared -lncurses
MODULES = jjkcurselord.o attributes.o

ncurses.so: $(MODULES)
	$(CC) $(LDFLAGS) -o $@ $(MODULES)
jjkcurselord.o: jjkcurselord.cc
	$(CC) $(CCFLAGS) jjkcurselord.cc
attributes.o: attributes.cc
	$(CC) $(CCFLAGS) attributes.cc
clean: 
	rm -f a.out core *.o *.so