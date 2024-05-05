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

bool intro = false;

Character::Character(int y, int x, char letter, WINDOW* w) : yPos(y), xPos(x), charLetter(letter), win(w) {
    display();
}

Character::Character(int y, int x, char letter, WINDOW* w, Hero* newclass) : yPos(y), xPos(x), charLetter(letter), win(w), next(nullptr), getclass(newclass) {}

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
    if (getclass->get_HP() < 0) {
        getclass->set_HP(0);
    }
    string line = "HP: " + to_string(getclass->get_HP());
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

void start_combat_intro(Player* p) {
    WINDOW* win = p->getwin();
    Character* george = new Character(12, 27, 'G', win, new George_Washington(0, 0));
    Character* jeff = new Character(10, 57, 'J', win, new Thomas_Jefferson(0, 0));
    Character* ben = new Character(14, 57, 'B', win, new Benjamin_Franklin(0, 0));
    turn_order order;
    order.add(george);
    order.add(jeff);
    order.add(ben);
    Textbox text;
    text.print("Thomas Jefferson and Benjamin Franklin want to fight!");
    while (jeff->getclass->get_HP() > 0 or ben->getclass->get_HP() > 0) {
        Character* currChar = order.getfirst();
        do {
            wclear(win);
            wborder(win, (int)'|', (int)'|', (int)'-', (int)'-', (int)'+', (int)'+', (int)'+', (int)'+');
            george->display();
            george->printHP();
            jeff->display();
            jeff->printHP();
            ben->display();
            ben->printHP();
            wrefresh(win);
            if (currChar->charLetter == 'G') {
                int playerAtkChoice = text.print_select("Choose an attack:", "Command and Conquer", "Fists of Freedom", "Trillion Dollar Destruction");
                int playerTargetChoice = text.print_select("Choose a target:", "Jefferson", "Benjamin");
                while (playerTargetChoice == 1 and jeff->getclass->get_HP() == 0 or playerTargetChoice == 2 and ben->getclass->get_HP() == 0) {
                    text.print("The target's HP can't go any lower");
                    playerTargetChoice = text.print_select("Choose a target:", "Jefferson", "Benjamin");
                }
                if (playerAtkChoice == 1) {
                    text.print("George Washington commands his fleet to attack!");
                }
                else if (playerAtkChoice == 2) {
                    text.print("George Washington hurls a fury of fists!");
                }
                else if (playerAtkChoice == 3) {
                    text.print("George Washington summons a trillion dollar bills!");
                }
                if (playerTargetChoice == 1) {
                    george->getclass->attack(playerAtkChoice);
                    jeff->getclass->set_HP(jeff->getclass->get_HP() - george->getclass->get_DPS());
                    string line = "Thomas Jefferson was hit for " + to_string(george->getclass->get_DPS()) + " damage";
                    text.print(line);
                }
                else {
                    george->getclass->attack(playerAtkChoice);
                    ben->getclass->set_HP(ben->getclass->get_HP() - george->getclass->get_DPS());
                    string line = "Benjamin Franklin was hit for " + to_string(george->getclass->get_DPS()) + " damage";
                    text.print(line);
                }
            }
            else if (currChar->charLetter == 'J' and currChar->getclass->get_HP() > 0) {
                srand(time(nullptr));
                int attackchoice = rand() % 3 + 1;
                if (attackchoice == 1) {
                    text.print("Thomas Jefferson exclaims the Declaration of Independence against his opponent, striking fear into their hearts!");
                }
                else if (attackchoice == 2) {
                    text.print("Thomas Jefferson throws his opponent into his macaroni machine!");
                }
                else if (attackchoice == 3) {
                    text.print("Thomas Jefferson exclaims that religious freedom will be a part of America once the British are gone, causes dread within his opponet!");
                }
                jeff->getclass->attack(attackchoice);
                george->getclass->set_HP(george->getclass->get_HP() - jeff->getclass->get_DPS() / 2);
                string line = "You were hit for " + to_string(george->getclass->get_DPS() / 2) + " damage";
                text.print(line);
            }
            else if (currChar->charLetter == 'B' and currChar->getclass->get_HP() > 0) {
                srand(time(nullptr));
                int attackchoice = rand() % 3 + 1;
                if (attackchoice == 1) {
                    text.print("Benjamin Franklin fills his opponent's mind with too much wisdom!");
                }
                else if (attackchoice == 2) {
                    text.print("Benjamin Franklin throws an electric charged spear at his opponet!");
                }
                else if (attackchoice == 3) {
                    text.print("Benjamin Franklin hurls a hot Franklin Stove burning his opponet!");
                }
                ben->getclass->attack(attackchoice);
                george->getclass->set_HP(george->getclass->get_HP() - ben->getclass->get_DPS() / 3);
                string line = "You were hit for " + to_string(george->getclass->get_DPS() / 3) + " damage";
                text.print(line);
            }
            currChar = currChar->next;
        } while (currChar != order.getfirst());
        text.delwin();
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
    text.print("Adams: 'How about we hijack a ship and invade Britain?");
    text.print("Jefferson: That's impossible! sailing from-");
    text.print("George Washington interrupts with a fiery glare.");
    text.print("George: Shut up! \"Impossible\" is not in my vocabulary. Men, let us set sail!");
    p->currmap->scene_data['A'].first = Adams.yPos;
    p->currmap->scene_data['A'].second = Adams.xPos;
    text.delwin();
}

void cutscene_harbor(Player* p) {
    
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