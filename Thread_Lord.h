#pragma once

class Thread_Safety {

deque<char> deck;
mutex lock_deque;

public:
Thread_Safety();
~Thread_Safety();

void  in_char(const char &c);
char  out_char(); 
}

