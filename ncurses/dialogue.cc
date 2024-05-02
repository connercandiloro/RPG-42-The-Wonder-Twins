#include "dialogue.h"
#include <string>
using std::string, std::to_string;

Textbox::Textbox(const char npc, Player* newplayer) : win(newwin(5, 83, 26, 2)), p(newplayer) {
	clearwin();
	wrefresh(win);
    switch (npc) {
        default:
            break;
    }
}

void Textbox::clearwin() {

}

void Textbox::confirm() {

}