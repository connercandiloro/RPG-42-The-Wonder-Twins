// James Hernandez
#include "Thread_Lord.h"
#include <iostream>
#include <deque>
#include <thread>
#include <mutex>
#include <exception>

/*class Thread_safety { 

public: 
*/
//std::deque<char> deck;
//std::mutex lock_deque;
Thread_Safety:: Thread_Safety(){}
Thread_Safety:: ~Thread_Safety() {}

void Thread_Safety::in_char(const char &c) {
		std::lock_guard LG(lock_deque);
deck.push_back(c);
};

char  Thread_Safety:: out_char(){
		std::lock_guard LG(lock_deque);
if(deck.size() == 0) throw std:: invalid_argument("no movement in the deque");
char temp = deck.front();
deck.pop_front();
return temp;
}

//};
