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

void  in_char(int c) {
lock_guard LG(lock_deque);
if(c == 'w' || c ==  'a' || c == 'd' || c == 's' ) deck.push_back(c);
else if(c == KEY_UP || c == KEY_DOWN || c == KEY_UP || c == KEY_LEFT) deck.push_back(c);
else throw invalid_arguement("invalid movement");
};

int  out_char(){
lock_guard LG(lock_deque);
if(deck.size() == 0) throw invalid_arguement("no movement in the deque");
char temp = deck.front();
deck.pop_front();
return temp;
};

}
