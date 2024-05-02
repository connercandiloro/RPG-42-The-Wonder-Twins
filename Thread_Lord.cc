// James Hernandez
#include <iostream>
#include <deque>
#include <threads>

class Thread_Safety { 

deque<int> deck;
mutex lock_deque;

public: 
Thread_Safety();
~Thread_Safety();

void in_char(int c) {
lock_guard LG(lock_deque);
deck.push_back(c);
};

int  out_char(){
lock_guard LG(lock_deque);
if(deck.size() == 0) throw invalid_arguement("no movement in the deque");
int temp = deck.front();
deck.pop_front();
return temp;
};

}
