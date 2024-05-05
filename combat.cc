//JJKCurseLord: Samuel Goosey
#include "jjkcurselord.h"
#include "heroes_and_monsters.h"

Character::Character(int y, int x, char letter, WINDOW* w, Hero* newclass) : yPos(y), xPos(x), charLetter(letter), next(nullptr), win(w), heroclass(newclass), monsterclass(nullptr) {}

Character::Character(int y, int x, char letter, WINDOW* w, Monster* newclass) : yPos(y), xPos(x), charLetter(letter), next(nullptr), win(w), heroclass(nullptr), monsterclass(newclass) {}

void displayOrder(Character* c) {
    if (c->charLetter == 'K') {
        mvwprintw(c->win, c->yPos, c->xPos - 8, "Turn >");
    }
    else {
        mvwprintw(c->win, c->yPos, c->xPos - 7, "Turn >");
    }
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

void start_combat_intro(WINDOW* win) {
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

void start_combat_harbor(WINDOW* win) {
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

void start_combat_ocean(WINDOW* win) {
    Character* george = new Character(3, 27, 'G', win, new George_Washington(0, 0));
    Character* jeff = new Character(9, 27, 'J', win, new Thomas_Jefferson(0, 0));
    Character* ben = new Character(15, 27, 'B', win, new Benjamin_Franklin(0, 0));
    Character* adams = new Character(21, 27, 'A', win, new John_Adams(0, 0));
    turn_order order;
    order.add(george);
    order.add(jeff);
    order.add(ben);
    order.add(adams);
    Textbox text;
    text.print("Davy the Dapper Kraken challenges you to a duel!");
    Character* davy = new Character(12, 57, printSprite_Davy(win, 10, 54), win, new Kraken(0, 0));
    davy->monsterclass->set_HP(800);
    order.add(davy);
    while (davy->monsterclass->get_HP() > 0) {
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
            adams->display();
            adams->printHP();
            printSprite_Davy(win, 10, 54);
            printSprite_DavyHP(davy);
            if (currChar->charLetter == 'G') {
                int playerAtkChoice = text.print_select("Choose an attack:", "Command and Conquer", "Fists of Freedom", "Trillion Dollar Destruction");
                if (playerAtkChoice == 1) {
                    text.print("George Washington commands his fleet to attack!");
                }
                else if (playerAtkChoice == 2) {
                    text.print("George Washington hurls a fury of fists!");
                }
                else if (playerAtkChoice == 3) {
                    text.print("George Washington summons a trillion dollar bills!");
                }
                george->heroclass->attack(playerAtkChoice);
                davy->monsterclass->set_HP(davy->monsterclass->get_HP() - george->heroclass->get_DPS());
                string line = "Davy was hit for " + to_string(george->heroclass->get_DPS()) + " damage";
                text.print(line);
            }
            else if (currChar->charLetter == 'J') {
                int playerAtkChoice = text.print_select("Choose an attack:", "Independence Day", "Macaroni Mayhem", "Religious Revolution");
                if (playerAtkChoice == 1) {
                    text.print("Thomas Jefferson exclaims the Declaration of Independence against the opponent striking fear into their hearts!");
                }
                else if (playerAtkChoice == 2) {
                    text.print("Thomas Jefferson throws the enemy into his macaroni machine!");
                }
                else if (playerAtkChoice == 3) {
                    text.print("Thomas Jefferson exclaims that religious freedom will be a part of America once the British are gone causing dread among the enemy!");
                }
                jeff->heroclass->attack(playerAtkChoice);
                davy->monsterclass->set_HP(davy->monsterclass->get_HP() - jeff->heroclass->get_DPS());
                string line = "Davy was hit for " + to_string(jeff->heroclass->get_DPS()) + " damage";
                text.print(line);
            }
            else if (currChar->charLetter == 'B') {
                int playerAtkChoice = text.print_select("Choose an attack:", "Knowledge Blast", "Franklin Spear", "Sizzling Surprise");
                if (playerAtkChoice == 1) {
                    text.print("Benjamin Franklin fills the enemies mind with too much wisdom!");
                }
                else if (playerAtkChoice == 2) {
                    text.print("Benjamin Franklin throws an electric charged spear at the British Forces!");
                }
                else if (playerAtkChoice == 3) {
                    text.print("Benjamin Franklin hurls a hot Franklin Stove burning the enemies!");
                }
                ben->heroclass->attack(playerAtkChoice);
                davy->monsterclass->set_HP(davy->monsterclass->get_HP() - ben->heroclass->get_DPS());
                string line = "Davy was hit for " + to_string(ben->heroclass->get_DPS()) + " damage";
                text.print(line);
            }
            else if (currChar->charLetter == 'A') {
                int playerAtkChoice = text.print_select("Choose an attack:", "Liberty Glare", "Naval Assault", "Bring the House Down");
                if (playerAtkChoice == 1) {
                    text.print("John Adams stares into the souls of his enemy and inflicts fear upon them!");
                }
                else if (playerAtkChoice == 2) {
                    text.print("John Adams summons a naval fleet to fire cannon balls at the opponent!");
                }
                else if (playerAtkChoice == 3) {
                    text.print("John Adams summons the white house to fall out of the sky onto the enemy!");
                }
                adams->heroclass->attack(playerAtkChoice);
                davy->monsterclass->set_HP(davy->monsterclass->get_HP() - adams->heroclass->get_DPS());
                string line = "Davy was hit for " + to_string(adams->heroclass->get_DPS()) + " damage";
                text.print(line);
            }
            else if (currChar->charLetter == 'K') {
                srand(time(nullptr));
                int attackchoice = rand() % 4 + 1;
                davy->monsterclass->attack();
                if (davy->monsterclass->get_DPS() == 40) { 
                    text.print("Davy flails all 8 tentacles rapidily!");
                }
                else if (davy->monsterclass->get_DPS() == 35) { 
                    text.print("Davy slams his tentacle onto the ground, causing shockwaves!");
                }
                else if (davy->monsterclass->get_DPS() == 30) { 
                    text.print("Davy squirts ink all over the place!");
                }
                if (attackchoice == 1) {
                    george->heroclass->set_HP(george->heroclass->get_HP() - davy->monsterclass->get_DPS());
                    string line = "George Washington was hit for " + to_string(davy->monsterclass->get_DPS()) + " damage";
                    text.print(line);
                }
                else if (attackchoice == 2) {
                    jeff->heroclass->set_HP(jeff->heroclass->get_HP() - davy->monsterclass->get_DPS());
                    string line = "Thomas Jefferson was hit for " + to_string(davy->monsterclass->get_DPS()) + " damage";
                    text.print(line);
                }
                else if (attackchoice == 3) {
                    ben->heroclass->set_HP(ben->heroclass->get_HP() - davy->monsterclass->get_DPS());
                    string line = "Benjamin Franklin was hit for " + to_string(davy->monsterclass->get_DPS()) + " damage";
                    text.print(line);
                }
                else if (attackchoice == 4) {
                    adams->heroclass->set_HP(adams->heroclass->get_HP() - davy->monsterclass->get_DPS());
                    string line = "John Adams was hit for " + to_string(davy->monsterclass->get_DPS()) + " damage";
                    text.print(line);
                }
            }

            currChar = currChar->next;
        } while (currChar != order.getfirst() and davy->monsterclass->get_HP() > 0);
    }
}

void start_combat_castle(WINDOW* win) {
    Character* george = new Character(3, 27, 'G', win, new George_Washington(0, 0));
    Character* jeff = new Character(9, 27, 'J', win, new Thomas_Jefferson(0, 0));
    Character* ben = new Character(15, 27, 'B', win, new Benjamin_Franklin(0, 0));
    Character* adams = new Character(21, 27, 'A', win, new John_Adams(0, 0));
    turn_order order;
    order.add(george);
    order.add(jeff);
    order.add(ben);
    order.add(adams);
    Textbox text;
    text.print("The 3 Musketeers want to battle!");
    Character* musketeers = new Character(12, 54, printSprite_Musketeers(win, 12, 54), win, new Three_Musketeers(0, 0));
    musketeers->monsterclass->set_HP(1200);
    Character* musketeer1 = new Character(12, 54, 'M', win, new Three_Musketeers(0, 0));
    Character* musketeer2 = new Character(12, 54, 'M', win, new Three_Musketeers(0, 0));
    Character* musketeer3 = new Character(12, 54, 'M', win, new Three_Musketeers(0, 0));
    order.add(musketeer1);
    order.add(musketeer2);
    order.add(musketeer3);
    while (musketeers->monsterclass->get_HP() > 0) {
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
            adams->display();
            adams->printHP();
            printSprite_Musketeers(win, 12, 54);
            printSprite_MusketeersHP(musketeers);
            if (currChar->charLetter == 'G') {
                int playerAtkChoice = text.print_select("Choose an attack:", "Command and Conquer", "Fists of Freedom", "Trillion Dollar Destruction");
                if (playerAtkChoice == 1) {
                    text.print("George Washington commands his fleet to attack!");
                }
                else if (playerAtkChoice == 2) {
                    text.print("George Washington hurls a fury of fists!");
                }
                else if (playerAtkChoice == 3) {
                    text.print("George Washington summons a trillion dollar bills!");
                }
                george->heroclass->attack(playerAtkChoice);
                musketeers->monsterclass->set_HP(musketeers->monsterclass->get_HP() - george->heroclass->get_DPS());
                string line = "The 3 Muskeeters were hit for " + to_string(george->heroclass->get_DPS()) + " damage";
                text.print(line);
            }
            else if (currChar->charLetter == 'J') {
                int playerAtkChoice = text.print_select("Choose an attack:", "Independence Day", "Macaroni Mayhem", "Religious Revolution");
                if (playerAtkChoice == 1) {
                    text.print("Thomas Jefferson exclaims the Declaration of Independence against the opponent striking fear into their hearts!");
                }
                else if (playerAtkChoice == 2) {
                    text.print("Thomas Jefferson throws the enemy into his macaroni machine!");
                }
                else if (playerAtkChoice == 3) {
                    text.print("Thomas Jefferson exclaims that religious freedom will be a part of America once the British are gone causing dread among the enemy!");
                }
                jeff->heroclass->attack(playerAtkChoice);
                musketeers->monsterclass->set_HP(musketeers->monsterclass->get_HP() - jeff->heroclass->get_DPS());
                string line = "The 3 Muskeeters were hit for " + to_string(jeff->heroclass->get_DPS()) + " damage";
                text.print(line);
            }
            else if (currChar->charLetter == 'B') {
                int playerAtkChoice = text.print_select("Choose an attack:", "Knowledge Blast", "Franklin Spear", "Sizzling Surprise");
                if (playerAtkChoice == 1) {
                    text.print("Benjamin Franklin fills the enemies mind with too much wisdom!");
                }
                else if (playerAtkChoice == 2) {
                    text.print("Benjamin Franklin throws an electric charged spear at the British Forces!");
                }
                else if (playerAtkChoice == 3) {
                    text.print("Benjamin Franklin hurls a hot Franklin Stove burning the enemies!");
                }
                ben->heroclass->attack(playerAtkChoice);
                musketeers->monsterclass->set_HP(musketeers->monsterclass->get_HP() - ben->heroclass->get_DPS());
                string line = "The 3 Muskeeters were hit for " + to_string(ben->heroclass->get_DPS()) + " damage";
                text.print(line);
            }
            else if (currChar->charLetter == 'A') {
                int playerAtkChoice = text.print_select("Choose an attack:", "Liberty Glare", "Naval Assault", "Bring the House Down");
                if (playerAtkChoice == 1) {
                    text.print("John Adams stares into the souls of his enemy and inflicts fear upon them!");
                }
                else if (playerAtkChoice == 2) {
                    text.print("John Adams summons a naval fleet to fire cannon balls at the opponent!");
                }
                else if (playerAtkChoice == 3) {
                    text.print("John Adams summons the white house to fall out of the sky onto the enemy!");
                }
                adams->heroclass->attack(playerAtkChoice);
                musketeers->monsterclass->set_HP(musketeers->monsterclass->get_HP() - adams->heroclass->get_DPS());
                string line = "The 3 Muskeeters were hit for " + to_string(adams->heroclass->get_DPS()) + " damage";
                text.print(line);
            }
            else if (currChar->charLetter == 'M') {
                srand(time(nullptr));
                int attackchoice = rand() % 4 + 1;
                musketeers->monsterclass->attack();
                if (musketeers->monsterclass->get_DPS() == 30) { 
                    text.print("One of the musketeers stabs at the Founding Fathers!");
                }
                else if (musketeers->monsterclass->get_DPS() == 45) { 
                    text.print("All three musketeers fire at the Founding Fathers at once!");
                }
                else if (musketeers->monsterclass->get_DPS() == 40) { 
                    text.print("Two of the musketeers jump the Founding Fathers!");
                }
                if (attackchoice == 1) {
                    george->heroclass->set_HP(george->heroclass->get_HP() - musketeers->monsterclass->get_DPS());
                    string line = "George Washington was hit for " + to_string(musketeers->monsterclass->get_DPS()) + " damage";
                    text.print(line);
                }
                else if (attackchoice == 2) {
                    jeff->heroclass->set_HP(jeff->heroclass->get_HP() - musketeers->monsterclass->get_DPS());
                    string line = "Thomas Jefferson was hit for " + to_string(musketeers->monsterclass->get_DPS()) + " damage";
                    text.print(line);
                }
                else if (attackchoice == 3) {
                    ben->heroclass->set_HP(ben->heroclass->get_HP() - musketeers->monsterclass->get_DPS());
                    string line = "Benjamin Franklin was hit for " + to_string(musketeers->monsterclass->get_DPS()) + " damage";
                    text.print(line);
                }
                else if (attackchoice == 4) {
                    adams->heroclass->set_HP(adams->heroclass->get_HP() - musketeers->monsterclass->get_DPS());
                    string line = "John Adams was hit for " + to_string(musketeers->monsterclass->get_DPS()) + " damage";
                    text.print(line);
                }
            }
            currChar = currChar->next;
        } while (currChar != order.getfirst() and musketeers->monsterclass->get_HP() > 0);
    }
}