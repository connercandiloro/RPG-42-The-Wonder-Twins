#pragma once
enum MOVE{UP, DOWN, LEFT, RIGHT};

struct Thread_Safety {

Thread_Safety();
~Thread_Safety();

void  in_char(const MOVE  &c);
char  out_char(); 
}

