//JJKCurseLord: Samuel Goosey
#include "jjkcurselord.h"
#include <thread>
#include <chrono>
using std::vector, std::string, std::make_pair, std::to_string;

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

bool intro = false;

Character::Character(int y, int x, char letter, WINDOW* w) : yPos(y), xPos(x), charLetter(letter), win(w) {
    display();
}

Character::Character(int y, int x, char letter, WINDOW* w, int h) : yPos(y), xPos(x), charLetter(letter), win(w), next(nullptr), hp(h) {}

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

void Character::printHP() {
    if (hp < 0) {
        hp = 0;
    }
    string line = "HP: " + to_string(hp);
    mvwprintw(win, yPos + 1, xPos - 3, "%s", line.c_str());
    wrefresh(win);
}

void Character::display() {
    mvwaddch(win, yPos, xPos, charLetter);
    wrefresh(win);
}

void cutscene_check(Player* p) {
    if (!intro) {
        cutscene_intro(p);
        intro = true;
    }
}

//not the final combat loop, just a visualize representation of how it will work
void start_combat_intro(Player* p) {
    WINDOW* win = p->getwin();
    Character* george = new Character(12, 27, 'G', win, 80);
    Character* jefferson = new Character(10, 57, 'J', win, 50);
    Character* colonist = new Character(14, 57, 'C', win, 30);
    turn_order order;
    order.add(george);
    order.add(jefferson);
    order.add(colonist);
    Textbox text;
    text.print("Thomas Jefferson wants to fight!");
    while (jefferson->hp > 0 or colonist->hp > 0) {
        Character* currChar = order.getfirst();
        do {
            wclear(win);
            wborder(win, (int)'|', (int)'|', (int)'-', (int)'-', (int)'+', (int)'+', (int)'+', (int)'+');
            george->display();
            george->printHP();
            jefferson->display();
            jefferson->printHP();
            colonist->display();
            colonist->printHP();
            wrefresh(win);
            if (currChar->charLetter == 'G') {
                bool playerAtkChoice = text.print_select("Choose an attack:", "1. Freedom Punch", "2. Liberty Kick");
                bool playerTargetChoice = text.print_select("Choose a target:", "Jefferson", "Drunken Colonist");
                if (playerTargetChoice) {
                    if (playerAtkChoice) {
                        jefferson->hp -= 25;
                        text.print("George used Freedom Punch on Jefferson for 25 damage");
                    }
                    else {
                        jefferson->hp -= 20;
                        text.print("George used Liberty Kick on Jefferson for 20 damage");
                    }
                }
                else {
                    if (playerAtkChoice) {
                        colonist->hp -= 25;
                        text.print("George used Freedom Punch on Drunken Colonist for 25 damage");
                    }
                    else {
                        colonist->hp -= 20;
                        text.print("George used Liberty Kick on Drunken Colonist for 20 damage");
                    }
                }
            }
            else if (currChar->charLetter == 'J' and currChar->hp > 0) {
                int attack = rand();
                if (attack % 2 == 0) {
                    george->hp -= 10;
                    text.print("Jefferson used Founding Father Flick on George for 10 damage");
                }
                else {
                    george->hp -= 15;
                    text.print("Jefferson used American Haymaker on George for 15 damage");
                }
            }
            else if (currChar->charLetter == 'C' and currChar->hp > 0) {
                int attack = rand();
                if (attack % 2 == 0) {
                    george->hp -= 5;
                    text.print("Colonist used Revolution Revolt on George for 5 damage");
                }
                else {
                    text.print("The Colonist is too drunk to move");
                }
            }
            currChar = currChar->next;
        } while (currChar != order.getfirst());
        text.delwin();
    }
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
    Egghead.moveChar(LEFT, 7, 150);
    text.print("Egghead Humpty: The British! They have raised our taxes again!");
    text.print("George: To hell with these tea shenanigans! I'll be damned if me or my kin ever pay tribute to fund some foreign countries wars.");
    text.print("*Murmurs of agreement ripple through the tavern.*");
    text.print("The crowd, now on edge, looks to him.");
    text.print("\"And what's the plan, Washington?\" they chorus.");
    text.print("George stands, striking a pose of defiance.");
    George.moveChar(UP, 2, 150);
    George.moveChar(RIGHT, 5, 150);
    text.print("George: We pen a rousing declaration, rally the colonies, wage war for freedom! A war to end the occupation!");
    text.print("Hamilton, ever the firebrand, leaps up, his chair clattering behind.");
    Hamiliton.moveChar(UP, 1, 150);
    text.print("Hamilton: Hell yes, for our liberty!");
    text.print("Jefferson, skeptical, chimes in-");
    text.print("Jefferson: This is lunacy, George! Without a solid plan, we're doomed to failure.");
    text.print("George: You know what else is doomed? Your marriage prospects after im done with ye!");
    text.print("Jefferson, angered by George's insult, confronts him");
    Jefferson.moveChar(LEFT, 5, 150);
    Jefferson.moveChar(DOWN, 1, 150);
    Jefferson.moveChar(LEFT, 5, 150);
    Jefferson.moveChar(DOWN, 1, 150);
    Jefferson.moveChar(LEFT, 5, 150);
    text.print("Jefferson: What have you say of my marriage prospects?");
    text.print("Jefferson: Have at thee!");
    p->currmap->scene_data.insert(make_pair(Egghead.charLetter, make_pair(Egghead.yPos, Egghead.xPos)));
    p->currmap->scene_data.insert(make_pair(Hamiliton.charLetter, make_pair(Hamiliton.yPos, Hamiliton.xPos)));
    p->currmap->scene_data.insert(make_pair(Jefferson.charLetter, make_pair(Jefferson.yPos, Jefferson.xPos)));
    p->currmap->scene_data.insert(make_pair(Adams.charLetter, make_pair(Adams.yPos, Adams.xPos)));
    p->currmap->scene_data.insert(make_pair(Madison.charLetter, make_pair(Madison.yPos, Madison.xPos)));
    start_combat_intro(p);
    p->display();
    text.print("As the dust settles, George stand victorious");
    Adams.moveChar(DOWN, 3, 150);
    Adams.moveChar(RIGHT, 18, 150);
    text.print("Adams: Enough! I am aware your mother dropped you as child but thats no reason to act like children.");
    text.print("George: Agreed, we have no time for petty squabble");
    text.print("Hamilton: Yeah, let's share some democracy with those red coats!");
    p->currmap->scene_data['A'].first = Adams.yPos;
    p->currmap->scene_data['A'].second = Adams.xPos;
}

turn_order::turn_order() : first(nullptr) {}

Character* turn_order::getfirst() {
    return first;
}

void turn_order::add(Character* c) {
    if (first == nullptr) {
        first = c;
        first->next = first;
    }
    else {
        Character* temp = first;
        while (temp->next != first) {
            temp = temp->next;
        }
        temp->next = c;
        c->next = first;
    }
}