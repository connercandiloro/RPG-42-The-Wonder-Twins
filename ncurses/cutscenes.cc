#include "cutscenes.h"
#include "dialogue.h"
#include <thread>
#include <chrono>
#include <vector>
#include <string>
using std::vector, std::string, std::make_pair;

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

Character::Character(int y, int x, char letter, WINDOW* w) : yPos(y), xPos(x), charLetter(letter), win(w) {
    display();
}

void Character::moveChar(int direction, int amount, int speed) {
    display();
    for (int i = 0; i < amount; i++) {
        wmove(stdscr, 28, 55);
        refresh();
        std::this_thread::sleep_for(std::chrono::milliseconds(speed));
        mvwaddch(win, yPos, xPos, ' ');
        wmove(stdscr, 28, 55);
        switch(direction) {
            case UP:
                yPos--;
                break;
            case DOWN:
                yPos++;
                break;
            case LEFT:
                xPos--;
                break;
            case RIGHT:
                xPos++;
                break;
        };
        display();
    }
    //erases inputs made during cutscene
    flushinp();
}

void Character::display() {
    mvwaddch(win, yPos, xPos, charLetter);
    wrefresh(win);
}

void cutscene_check(Player* p) {

}

void cutscene_intro(Player* p) {
    Textbox text;
    Character George(13, 39, 'G', p->getwin());
    Character Hamiliton(7, 69, 'H', p->getwin());
    Character Jefferson(7, 59, 'J', p->getwin());
    Character Adams(7, 22, 'A', p->getwin());
    Character Madison(7, 32, 'M', p->getwin());

    text.print("In the shadowy confines of \"Thy ol' Kernel Keren's Tavern,\" George Washington reclines amid his rambunctious comrades.");
    text.print("The pungent aroma of spilt ale permeates the air, mingling with the dense smoke wafting from hand-rolled tobacco.");
    text.print("As the laughter reaches a crescendo, the door bursts open dramatically, and in stumbles Egghead Humpty, gasping out between heaves-");
    Character Egghead(12, 85, 'E', p->getwin());
    Egghead.moveChar(LEFT, 7, 250);
    text.print("Egghead Humpty: The British! They have raised our taxes again!");
    text.print("George: To hell with these tea shenanigans! I'll be damned if me or my kin ever pay tribute to fund some foreign countries wars.");
    text.print("*Murmurs of agreement ripple through the tavern.*");
    text.print("The crowd, now on edge, looks to him.");
    text.print("\"And what's the plan, Washington?\" they chorus.");
    text.print("George stands, striking a pose of defiance.");
    George.moveChar(UP, 1, 250);
    text.print("George: We pen a rousing declaration, rally the colonies, wage war for freedom! A war to end the occupation!");
    text.print("Hamilton, ever the firebrand, leaps up, his chair clattering behind.");
    Hamiliton.moveChar(UP, 1, 250);
    text.print("Hamilton: Hell yes, for our liberty!");
    text.print("Jefferson, skeptical, chimes in-");
    text.print("Jefferson: This is lunacy, George! Without a solid plan, we're doomed to failure.");
    text.print("George: You know what else is doomed? Your marriage prospects after im done with ye!");
    text.delwin();
    
    p->currmap->scene_data.insert(make_pair(Egghead.charLetter, make_pair(Egghead.yPos, Egghead.xPos)));
    p->currmap->scene_data.insert(make_pair(Hamiliton.charLetter, make_pair(Hamiliton.yPos, Hamiliton.xPos)));
    p->currmap->scene_data.insert(make_pair(Jefferson.charLetter, make_pair(Jefferson.yPos, Jefferson.xPos)));
    p->currmap->scene_data.insert(make_pair(Adams.charLetter, make_pair(Adams.yPos, Adams.xPos)));
    p->currmap->scene_data.insert(make_pair(Madison.charLetter, make_pair(Madison.yPos, Madison.xPos)));
}