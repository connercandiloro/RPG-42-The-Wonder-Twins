// James Hernandez
#include "Thread_Lord.h"
#include <iostream>
#include <deque>
#include <threads>
#include <mutex>

class Thread_Safety { 

deque<char> deck;
mutex lock_deque;

public: 
Thread_Safety();
~Thread_Safety();

void in_char(const char &c) {
lock_guard LG(lock_deque);
deck.push_back(c);
};

char  out_char(){
lock_guard LG(lock_deque);
if(deck.size() == 0) throw std::invalid_arguement("no movement in the deque");
char temp = deck.front();
deck.pop_front();
return temp;
};

}
