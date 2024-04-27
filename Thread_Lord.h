#pragma once
enum MOVE{UP, DOWN, LEFT, RIGHT}
enum interact{FIGHT, SPEAK, NEGOTIATE}


struct Thread_Safety {


Thread_Safety();
~Thread_Safety();


void  in_movement(const MOVE  &c);
void  in_interaction(const interact &s); 
char out_movement();
string out_interaction();

}
