// James Hernandez
#include <iostream>
#include <deque>
#include <threads>

struct Thread_Safety { 

Thread_Safety();
~Thread_Safety();
	
deque<char> deck;

void  in_char(const char &c) {
static mutex move_deq_mutex;
lock_guard LG(move_deq_mutex);
if(c == 'w') move_deq.push_back('w');
else if(c == 'a') move_deq.push_back('a');
else if(c == 'd') move_deq.push_back('d');
else if(c == 's') move_deq.push_back('s');
else throw invalid_arguement("invalid movement");
};

char out_char(){
static mutex interact_deq_mutex;
lock_guard LG(move_deq_mutex);
if(deck.size() == 0) throw invalid_arguement("no movement in the deque");
char temp = deck.front();
deck.pop_front();
return temp;
};

}
