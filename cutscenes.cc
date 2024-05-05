//JJKCurseLord: Samuel Goosey
#include "jjkcurselord.h"
#include "heroes_and_monsters.h"
#include <thread>
#include <chrono>
using std::vector, std::string, std::make_pair, std::to_string;

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

bool intro_scene = false;
bool harbor_scene = false;

Character::Character(int y, int x, char letter, WINDOW* w) : yPos(y), xPos(x), charLetter(letter), win(w) {
    display();
}

void Character::moveChar(int direction, int amount, int speed) {
    display();
    for (int i = 0; i < amount; i++) {
        wmove(stdscr, 29, 55);
        refresh();
        std::this_thread::sleep_for(std::chrono::milliseconds(speed));
        mvwaddch(win, yPos, xPos, ' ');
        wmove(stdscr, 29, 55);
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
    if (heroclass != nullptr) {
        if (heroclass->get_HP() < 0) {
            heroclass->set_HP(0);
        }
        string line = "HP: " + to_string(heroclass->get_HP());
        mvwprintw(win, yPos + 1, xPos - 3, "%s", line.c_str());
    }
    else {
        if (monsterclass->get_HP() < 0) {
            monsterclass->set_HP(0);
        }
        string line = "HP: " + to_string(monsterclass->get_HP());
        mvwprintw(win, yPos + 1, xPos - 3, "%s", line.c_str());
    }
    wrefresh(win);
}

void Character::display() {
    mvwaddch(win, yPos, xPos, charLetter);
    wrefresh(win);
}

void cutscene_check(Player* p) {
    if (!intro_scene) {
        cutscene_intro(p);
        intro_scene = true;
    }
    if (!harbor_scene and p->currmap->ID == 2) {
        cutscene_harbor(p);
        harbor_scene = true;
    }
}

void cutscene_intro(Player* p) {
    Textbox text;
    Character George(13, 39, 'G', p->getwin());
    Character Benjamin(7, 69, 'B', p->getwin());
    Character Jefferson(7, 59, 'J', p->getwin());
    Character Adams(7, 22, 'A', p->getwin());
    Character Madison(7, 32, 'M', p->getwin());

    text.print("In the shadowy confines of \"Thy ol' Kernel Kerney's Tavern,\" George Washington reclines amid his rambunctious comrades.");
    text.print("The pungent aroma of spilt ale permeates the air, mingling with the dense smoke wafting from hand-rolled tobacco.");
    text.print("As the laughter reaches a crescendo, the door bursts open dramatically, and in stumbles Egghead Humpty, gasping out between heaves.");
    Character Egghead(12, 85, 'E', p->getwin());
    Egghead.moveChar(LEFT, 7, 150);
    text.print("Egghead Humpty: The British! They have raised our taxes again!");
    text.print("George Washington: To hell with these tea shenanigans! I'll be damned if me or my kin ever pay tribute to fund some foreign countries wars.");
    text.print("Murmurs of agreement ripple through the tavern.");
    text.print("The crowd, now on edge, looks to George for a response.");
    text.print("\"And what's the plan, Washington?\" they chorus.");
    text.print("George stands, striking a pose of defiance.");
    George.moveChar(UP, 2, 150);
    George.moveChar(RIGHT, 5, 150);
    text.print("George: We pen a rousing declaration, rally the colonies, and wage war for freedom! A war to end the occupation!");
    text.print("Benjamin Franklin, ever the firebrand, leaps up, his chair clattering behind.");
    Benjamin.moveChar(UP, 1, 150);
    text.print("Benjamin: Hell yes, for our liberty!");
    text.print("Thomas Jefferson, skeptical, chimes in.");
    text.print("Jefferson: This is lunacy, George! Without a solid plan, we're doomed to failure.");
    text.print("George: You know what else is doomed? Your marriage prospects after im done with ye!");
    text.print("Jefferson, angered by George's insult, confronts him.");
    Jefferson.moveChar(LEFT, 5, 150);
    Jefferson.moveChar(DOWN, 1, 150);
    Jefferson.moveChar(LEFT, 5, 150);
    Jefferson.moveChar(DOWN, 1, 150);
    Jefferson.moveChar(LEFT, 5, 150);
    text.print("Jefferson: What have you say of my marriage prospects?");
    text.print("Jefferson: Have at thee!");
    p->currmap->scene_data.insert(make_pair(Egghead.charLetter, make_pair(Egghead.yPos, Egghead.xPos)));
    p->currmap->scene_data.insert(make_pair(Benjamin.charLetter, make_pair(Benjamin.yPos, Benjamin.xPos)));
    p->currmap->scene_data.insert(make_pair(Jefferson.charLetter, make_pair(Jefferson.yPos, Jefferson.xPos)));
    p->currmap->scene_data.insert(make_pair(Adams.charLetter, make_pair(Adams.yPos, Adams.xPos)));
    p->currmap->scene_data.insert(make_pair(Madison.charLetter, make_pair(Madison.yPos, Madison.xPos)));
    //start_combat_intro(p);
    p->display();
    text.print("As the dust settles, George stand victorious.");
    Adams.moveChar(DOWN, 3, 150);
    Adams.moveChar(RIGHT, 18, 150);
    text.print("Adams: Enough! I am aware your mother dropped you as child but thats no reason to act like children.");
    text.print("George: Agreed, we have no time for petty squabble.");
    text.print("Benjamin: Yeah, let's share some democracy with those red coats!");
    text.print("The tavern erupts with exictement.");
    text.print("\"YEAH!!!\"");
    text.print("...");
    text.print("... ...");
    text.print("... ... ...");
    text.print("Jefferson and Benjamin exchange looks, a mix of resignation and intrigue.");
    text.print("Jefferson: Ok, now what?");
    text.print("George: I want to give King George the American special!");
    text.print("Jefferson: Oh yeah, and how do you suppose we do so?");
    text.print("Adams, always one for bold strategies, makes a suggestion.");
    text.print("Adams: How about we hijack a ship and invade Britain?");
    text.print("Jefferson: That's impossible! sailing from-");
    text.print("George Washington interrupts with a fiery glare.");
    text.print("George: Shut up! \"Impossible\" is not in my vocabulary. Men, let us set sail!");
    p->currmap->scene_data['A'].first = Adams.yPos;
    p->currmap->scene_data['A'].second = Adams.xPos;
    text.delwin();
}

void cutscene_harbor(Player* p) {
    Textbox text;
    Character George(p->gety(), p->getx(), 'G', p->getwin());
    Character Benjamin(p->gety() + 2, p->getx() + 2, 'B', p->getwin());
    Character Jefferson(p->gety() + 4, p->getx() + 2, 'J', p->getwin());
    Character Adams(p->gety() - 2, p->getx() + 2, 'A', p->getwin());
    Character Madison(p->gety() - 4, p->getx() + 2, 'M', p->getwin());
    Character Readcoat1(10, 35, 'R', p->getwin());
    Character Readcoat2(10, 44, 'r', p->getwin());
    text.print("As our Founding Fathers arrive to the harbor, the air buzzes with anticipation and the scent of salt.");
    text.print("Dockworkers scurry about, their shouts mingling with the creaking of ropes and the slap of water against wooden hulls.");
    text.print("Amidst the chaos, the towering silhouette of a majestic ship looms large, its sleek form casting an imposing shadow over the bustling dockyard.");
    text.print("Guarded by a contingent of stern-faced Redcoats, it seems an impenetrable fortress, a challenge that awaits George Washington and his merry band of rebels.");
    text.print("George points excitedly at one of the ships.");
    text.print("George: Hmm, that ship be looking mighty fine, she might be the one!");
    text.print("Adams: You've said that about every ship today. Can you please just pick one?");
    text.print("George looks towards the most imposing vessel guarded by a squadron of Redcoats.");
    text.print("George: That one!");
    text.print("Jefferson: Uh, are you sure that one-?");
    text.print("George, full of fervor, and charges headlong towards the ship.");
    text.print("George: LEROY JENKINS!");
    George.moveChar(RIGHT, 33, 50);
    text.print("The Readcoats take notice of George.");
    text.print("Redcoats: HALT!");
    text.print("George: NAY! I will claim this vessel. For Democracy, for Freedom, for Harambe!");
    p->currmap->scene_data.insert(make_pair(Benjamin.charLetter, make_pair(Benjamin.yPos, Benjamin.xPos)));
    p->currmap->scene_data.insert(make_pair(Jefferson.charLetter, make_pair(Jefferson.yPos, Jefferson.xPos)));
    p->currmap->scene_data.insert(make_pair(Adams.charLetter, make_pair(Adams.yPos, Adams.xPos)));
    p->currmap->scene_data.insert(make_pair(Madison.charLetter, make_pair(Madison.yPos, Madison.xPos)));
    //start_combat_harbor(p);
    p->setpos(George.yPos, George.xPos);
    p->display();
    text.print("Adams: Holy ****, it worked! The Boat is ours!");
    text.print("George: No time to rest, To Great Britain!");
    p->currmap->prev->prev->scene_data.clear();
    p->display();
    text.delwin();
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