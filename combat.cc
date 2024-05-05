//JJKCurseLord: Samuel Goosey
#include "jjkcurselord.h"
#include "heroes_and_monsters.h"

Character::Character(int y, int x, char letter, WINDOW* w, Hero* newclass) : yPos(y), xPos(x), charLetter(letter), next(nullptr), win(w), heroclass(newclass), monsterclass(nullptr) {}

Character::Character(int y, int x, char letter, WINDOW* w, Monster* newclass) : yPos(y), xPos(x), charLetter(letter), next(nullptr), win(w), heroclass(nullptr), monsterclass(newclass) {}

void displayOrder(Character* c) {
    mvwprintw(c->win, c->yPos, c->xPos - 7, "Turn >");
}

void start_combat_intro(Player* p) {
    WINDOW* win = p->getwin();
    Character* george = new Character(12, 27, 'G', win, new George_Washington(0, 0));
    Character* jeff = new Character(9, 57, 'J', win, new Thomas_Jefferson(0, 0));
    Character* ben = new Character(15, 57, 'B', win, new Benjamin_Franklin(0, 0));
    turn_order order;
    order.add(george);
    order.add(jeff);
    order.add(ben);
    Textbox text;
    text.print("Thomas Jefferson and Benjamin Franklin want to fight!");
    while (jeff->heroclass->get_HP() > 0 or ben->heroclass->get_HP() > 0) {
        Character* currChar = order.getfirst();
        do {
            wclear(win);
            wborder(win, (int)'|', (int)'|', (int)'-', (int)'-', (int)'+', (int)'+', (int)'+', (int)'+');
            displayOrder(currChar);
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
                while ((playerTargetChoice == 1 and jeff->heroclass->get_HP() == 0) or (playerTargetChoice == 2 and ben->heroclass->get_HP() == 0)) {
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
                    george->heroclass->attack(playerAtkChoice);
                    jeff->heroclass->set_HP(jeff->heroclass->get_HP() - george->heroclass->get_DPS());
                    string line = "Thomas Jefferson was hit for " + to_string(george->heroclass->get_DPS()) + " damage";
                    text.print(line);
                }
                else {
                    george->heroclass->attack(playerAtkChoice);
                    ben->heroclass->set_HP(ben->heroclass->get_HP() - george->heroclass->get_DPS());
                    string line = "Benjamin Franklin was hit for " + to_string(george->heroclass->get_DPS()) + " damage";
                    text.print(line);
                }
            }
            else if (currChar->charLetter == 'J' and currChar->heroclass->get_HP() > 0) {
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
                jeff->heroclass->attack(attackchoice);
                george->heroclass->set_HP(george->heroclass->get_HP() - jeff->heroclass->get_DPS() / 2);
                string line = "You were hit for " + to_string(george->heroclass->get_DPS() / 2) + " damage";
                text.print(line);
            }
            else if (currChar->charLetter == 'B' and currChar->heroclass->get_HP() > 0) {
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
                ben->heroclass->attack(attackchoice);
                george->heroclass->set_HP(george->heroclass->get_HP() - ben->heroclass->get_DPS() / 3);
                string line = "You were hit for " + to_string(george->heroclass->get_DPS() / 3) + " damage";
                text.print(line);
            }
            currChar = currChar->next;
        } while (currChar != order.getfirst());
        text.delwin();
    }
}

void start_combat_harbor(Player* p) {
    WINDOW* win = p->getwin();
    Character* george = new Character(9, 27, 'G', win, new George_Washington(0, 0));
    Character* jeff = new Character(15, 27, 'J', win, new Thomas_Jefferson(0, 0));
    Character* bigredcoat = new Character(9, 57, 'R', win, new Red_Coats(0, 0));
    Character* lilredcoat = new Character(15, 57, 'r', win, new Red_Coats(0, 0));
    turn_order order;
    order.add(george);
    order.add(jeff);
    order.add(bigredcoat);
    order.add(lilredcoat);
    Textbox text;
    text.print("Thomas Jefferson and Benjamin Franklin want to fight!");
    while (bigredcoat->monsterclass->get_HP() > 0 or lilredcoat->monsterclass->get_HP() > 0) {
        Character* currChar = order.getfirst();
        do {
            wclear(win);
            wborder(win, (int)'|', (int)'|', (int)'-', (int)'-', (int)'+', (int)'+', (int)'+', (int)'+');
            displayOrder(currChar);
            george->display();
            george->printHP();
            jeff->display();
            jeff->printHP();
            bigredcoat->display();
            bigredcoat->printHP();
            lilredcoat->display();
            lilredcoat->printHP();
            wrefresh(win);
            if (currChar->charLetter == 'G') {
                int playerAtkChoice = text.print_select("Choose an attack:", "Command and Conquer", "Fists of Freedom", "Trillion Dollar Destruction");
                int playerTargetChoice = text.print_select("Choose a target:", "Big Redcoat", "Little Redcoat");
                while ((playerTargetChoice == 1 and bigredcoat->monsterclass->get_HP() == 0) or (playerTargetChoice == 2 and lilredcoat->monsterclass->get_HP() == 0)) {
                    text.print("The target's HP can't go any lower");
                    playerTargetChoice = text.print_select("Choose a target:", "Big Redcoat", "Little Redcoat");
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
                    george->heroclass->attack(playerAtkChoice);
                    bigredcoat->monsterclass->set_HP(bigredcoat->monsterclass->get_HP() - george->heroclass->get_DPS());
                    string line = "Big Redcoat was hit for " + to_string(george->heroclass->get_DPS()) + " damage";
                    text.print(line);
                }
                else {
                    george->heroclass->attack(playerAtkChoice);
                    lilredcoat->monsterclass->set_HP(lilredcoat->monsterclass->get_HP() - george->heroclass->get_DPS());
                    string line = "Little Redcoat was hit for " + to_string(george->heroclass->get_DPS()) + " damage";
                    text.print(line);
                }
            }
            else if (currChar->charLetter == 'J') {
                int playerAtkChoice = text.print_select("Choose an attack:", "Independence Day", "Macaroni Mayhem", "Religious Revolution");
                int playerTargetChoice = text.print_select("Choose a target:", "Big Redcoat", "Little Redcoat");
                while ((playerTargetChoice == 1 and bigredcoat->monsterclass->get_HP() == 0) or (playerTargetChoice == 2 and lilredcoat->monsterclass->get_HP() == 0)) {
                    text.print("The target's HP can't go any lower");
                    playerTargetChoice = text.print_select("Choose a target:", "Big Redcoat", "Little Redcoat");
                }
                if (playerAtkChoice == 1) {
                    text.print("Thomas Jefferson exclaims the Declaration of Independence against the British striking fear into their hearts!");
                }
                else if (playerAtkChoice == 2) {
                    text.print("Thomas Jefferson throws the british into his macaroni machine!");
                }
                else if (playerAtkChoice == 3) {
                    text.print("Thomas Jefferson exclaims that religious freedom will be a part of America once the British are gone causing dread among the troops!");
                }
                if (playerTargetChoice == 1) {
                    jeff->heroclass->attack(playerAtkChoice);
                    bigredcoat->monsterclass->set_HP(bigredcoat->monsterclass->get_HP() - jeff->heroclass->get_DPS());
                    string line = "Big Redcoat was hit for " + to_string(jeff->heroclass->get_DPS()) + " damage";
                    text.print(line);
                }
                else {
                    jeff->heroclass->attack(playerAtkChoice);
                    lilredcoat->monsterclass->set_HP(lilredcoat->monsterclass->get_HP() - jeff->heroclass->get_DPS());
                    string line = "Little Redcoat was hit for " + to_string(jeff->heroclass->get_DPS()) + " damage";
                    text.print(line);
                }
            }
            else if (currChar->charLetter == 'R' and bigredcoat->monsterclass->get_HP() > 0) {
                srand(time(nullptr));
                int attackchoice = rand();
                bigredcoat->monsterclass->attack();
                if (bigredcoat->monsterclass->get_DPS() == 35) {
                    text.print("Big Redcoat fires their musket at Founding Fathers!");
                }
                else if (bigredcoat->monsterclass->get_DPS() == 45) {
                    text.print("Big Redcoat waves the British Flag bringing unfathomable anger among the Founding Fathers!");
                }
                else if (bigredcoat->monsterclass->get_DPS() == 40) {
                    text.print("Big Redcoat stabs one of the Founding Fathers with their musket!");
                }
                if (attackchoice % 2 == 0) {
                    george->heroclass->set_HP(george->heroclass->get_HP() - bigredcoat->monsterclass->get_DPS());
                    string line = "George Washington was hit for " + to_string(bigredcoat->monsterclass->get_DPS()) + " damage";
                    text.print(line);
                }
                else {
                    jeff->heroclass->set_HP(jeff->heroclass->get_HP() - bigredcoat->monsterclass->get_DPS());
                    string line = "Thomas Jefferson was hit for " + to_string(bigredcoat->monsterclass->get_DPS()) + " damage";
                    text.print(line);
                }
            }
            else if (currChar->charLetter == 'r' and lilredcoat->monsterclass->get_HP() > 0) {
                srand(time(nullptr));
                int attackchoice = rand();
                lilredcoat->monsterclass->attack();
                if (lilredcoat->monsterclass->get_DPS() == 35) {
                    text.print("Little Redcoat fires their musket at Founding Fathers!");
                }
                else if (lilredcoat->monsterclass->get_DPS() == 45) {
                    text.print("Little Redcoat waves the British Flag bringing unfathomable anger among the Founding Fathers!");
                }
                else if (lilredcoat->monsterclass->get_DPS() == 40) {
                    text.print("Little Redcoat stabs one of the Founding Fathers with their musket!");
                }
                if (attackchoice % 2 == 0) {
                    george->heroclass->set_HP(george->heroclass->get_HP() - lilredcoat->monsterclass->get_DPS());
                    string line = "George Washington was hit for " + to_string(lilredcoat->monsterclass->get_DPS()) + " damage";
                    text.print(line);
                }
                else {
                    jeff->heroclass->set_HP(jeff->heroclass->get_HP() - lilredcoat->monsterclass->get_DPS());
                    string line = "Thomas Jefferson was hit for " + to_string(lilredcoat->monsterclass->get_DPS()) + " damage";
                    text.print(line);
                }
            }
            currChar = currChar->next;
        } while (currChar != order.getfirst());
        text.delwin();
    }
}