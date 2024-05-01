// James Hernandez
#include <iostream>
#include <deque>
#include <threads>

class Thread_Safety { 

deque<char> deck;

public: 
Thread_Safety();
~Thread_Safety();

mutex lock_deque;

void  in_char(const char &c) {
lock_guard LG(lock_deque);
if(c == 'w') deck.push_back('w');
else if(c == 'a') deck.push_back('a');
else if(c == 'd') deck.push_back('d');
else if(c == 's') deck.push_back('s');
else throw invalid_arguement("invalid movement");
};

char out_char(){
lock_guard LG(lock_deque);
if(deck.size() == 0) throw invalid_arguement("no movement in the deque");
char temp = deck.front();
deck.pop_front();
return temp;
};

}
