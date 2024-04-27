// James Hernandez
#include <iostream>
#include <deque>
#include <threads>

void  in_movement(const MOVE  &c) {
static mutex move_deq_mutex;
lock_guard LG(move_deq_mutex);
static deque<char> move_deq;
if(c == "UP") move_deq.push_back('w');
else if(c == "LEFT") move_deq.push_back('a');
else if(c == "RIGHT") move_deq.push_back('d');
else if(c == "DOWN") move_deq.push_back('s');
else throw invalid_arguement("invalid movement");
};

void  in_interaction(const interact &s){
static mutex interact_deq_mutex;
lock_gurad LG(interact_deq_mutex);
static deque<string> interact_deq;
if(s == "SPEAK") interact_deq.push_back("speak");
else if(s == "FIGHT") interact_deq.push_back("fight");
else if(s == "NEGOTIATE") interact_deq.push_back("negotiate");
else throw invalid_arguement("invalid interaction");
};

char out_movement() {
if(move_deq.size() == 0) throw invalid_arguement("no movement to be done");
char temp = move_deq.front();
move_deq.pop_front();
return temp;
};

string out_interaction(){
if(interact_deq.size() == 0) throw invalid_arguement("no interaction to be done");
string temp = interact_deq.front();
interact_deq.pop_front();
return temp;
};
