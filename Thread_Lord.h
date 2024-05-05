#pragma once
#include<deque>
#include<mutex>

class Thread_Safety {

	std::deque<char> deck;
	std::mutex lock_deque;

public:
Thread_Safety();
~Thread_Safety();

void  in_char(const char &c);
char  out_char(); 
};

