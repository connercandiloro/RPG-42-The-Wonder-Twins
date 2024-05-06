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
bool castle_harbor_scene = false;
bool outside_castle_scene = false;
bool castle_scene = false;

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

bool cutscene_check(Player* p) {
    if (!intro_scene) {
        cutscene_intro(p);
        intro_scene = true;
    }
    if (!harbor_scene and p->currmap->ID == 2) {
        cutscene_harbor(p);
        harbor_scene = true;
    }
    if (!castle_harbor_scene and p->currmap->ID == 4 and p->getx() > 62) {
        cutscene_castle_harbor2(p);
        castle_harbor_scene = true;
    }
    if (!outside_castle_scene and p->currmap->ID == 5) {
        cutscene_castle_outside(p);
        outside_castle_scene = true;
    }
    if (!castle_scene and p->currmap->ID == 6) {
        cutscene_castle(p);
        castle_scene = true;
        return true;
    }
    return false;
}

char printSprite_Davy(WINDOW* win, int y, int x) {
    mvwprintw(win, y, x + 3, "___");
    mvwprintw(win, y + 1, x + 2, "/O O\\");
    mvwprintw(win, y + 2, x + 2, "\\___/ ");
    mvwprintw(win, y + 3, x + 1, "\\_/ \\_/ ");
    wrefresh(win);
    return 'K';
}

void printSprite_DavyHP(Character* c) {
    string line = "HP: " + to_string(c->monsterclass->get_HP());
    mvwprintw(c->win, c->yPos + 2, c->xPos - 2, "%s", line.c_str());
    wrefresh(c->win);
}

char printSprite_Musketeers(WINDOW* win, int y, int x) {
    mvwprintw(win, y - 2, x + 2, "M");
    mvwprintw(win, y, x, "M");
    mvwprintw(win, y + 2, x + 2, "M");
    wrefresh(win);
    return 'M';
}

void printSprite_MusketeersHP(Character* c) {
    string line = "HP: " + to_string(c->monsterclass->get_HP());
    mvwprintw(c->win, c->yPos + 3, c->xPos, "%s", line.c_str());
    wrefresh(c->win);
}

void cutscene_intro(Player* p) {
    Textbox text;
    Character George(13, 39, 'G', p->getwin());
    Character Benjamin(7, 69, 'B', p->getwin());
    Character Jefferson(7, 59, 'J', p->getwin());
    Character Adams(7, 22, 'A', p->getwin());
    Character Madison(7, 32, 'M', p->getwin());
	text.print("music link placeholder");
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
    start_combat_intro(p->getwin());
    p->display();
    text.print("As the dust settles, George stand victorious.");
    Adams.moveChar(DOWN, 3, 150);
    Adams.moveChar(RIGHT, 18, 75);
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
    p->display();
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
    start_combat_harbor(p->getwin());
    p->setpos(George.yPos, George.xPos);
    p->display();
    text.print("Adams: Holy ****, it worked! The boat is ours!");
    text.print("George: No time to rest, to Great Britain!");
    George.moveChar(RIGHT, 3, 100);
    George.moveChar(UP, 8, 150);
    cutscene_ocean(p);
}

void cutscene_ocean(Player* p) {
    p->currmap = p->currmap->next;
    wclear(p->getwin());
    wborder(p->getwin(), (int)'|', (int)'|', (int)'-', (int)'-', (int)'+', (int)'+', (int)'+', (int)'+');
    wrefresh(p->getwin());
    Textbox text;
    text.print("As the ship pulls away from the dock, our heros set sail for Great Britain.");
    p->loadmap();
    text.print("The ship sails into the sunset, the sound of distant waves mixed with the murmurs of a crew both triumphant and incredulous at their newfound fortune.");
    Character George(12, 65, 'G', p->getwin());
    Character Benjamin(14, 36, 'B', p->getwin());
    Character Jefferson(10, 36, 'J', p->getwin());
    Character Adams(12, 30, 'A', p->getwin());
    text.print("The ship cuts through the ocean waves, propelled by the winds of destiny and the sheer audacity of its crew.");
    text.print("George Washington, at the helm with a makeshift tricorn hat perched jauntily atop his head, surveys the horizon with a determined gaze.");
    text.print("Adams: Umm, guys.");
    text.print("Adams: We forgot Madisson!");
    text.print("George: Who?");
    text.print("Adams: JAMES MADDISON, our mate.");
    text.print("George: Oh him, we'll get him a souviner.");
    text.print("Suddenly, a commotion erupts amongst the crew as a monstrous creature emerges from the depths.");
    text.print("An enormous, tentacled creature with a mustache that would rival any dapper gentleman jumps aboard the ship.");
    printSprite_Davy(p->getwin(), 10, 45);
    text.print("Adams: By the crown jewels, it's the Dreadful Davy Squidsworth!");
    text.print("George, undaunted, takes a swig from his tankard.");
    text.print("George: Prepare for battle lads. We shan't be deterred by a mere oversized calamari!");
    text.print("Davy: By his majesties 7 wives who are you and why are you on british sea.");
    text.print("Jefferson: No need to worry, we are just mere merchants here to-");
    text.print("George: To kill the king.");
    text.print("Davy: Huzaah, is that true? I simply can not allow it then.");
    text.print("Davy: I challenge you goodsirs to a duel.");
    p->currmap->scene_data.insert(make_pair(George.charLetter, make_pair(George.yPos, George.xPos)));
    p->currmap->scene_data.insert(make_pair(Benjamin.charLetter, make_pair(Benjamin.yPos, Benjamin.xPos)));
    p->currmap->scene_data.insert(make_pair(Jefferson.charLetter, make_pair(Jefferson.yPos, Jefferson.xPos)));
    p->currmap->scene_data.insert(make_pair(Adams.charLetter, make_pair(Adams.yPos, Adams.xPos)));
    start_combat_ocean(p->getwin());
    p->loadmap();
    printSprite_Davy(p->getwin(), 10, 45);
    text.print("Davy, defeated, begins to tear up.");
    text.print("Davy: Rahh, I lost my dignity, ahhh.");
    text.print("Adams: There there, calm down. Its not your fault that you lost its because that wretched King George failed to help you.");
    text.print("Davy: Hmm.. You're right, its unfair that it was all of you against me.");
    text.print("Adams: So how about a rematch after we speak to the king?");
    text.print("Davy: But wont you kill him, right?");
    text.print("Adams: No, I swear on George Washington's honor and intellect.");
    text.print("Davy: Fine, I'll take you to the king. Just to talk, understood?");
    text.print("Adams: Understood.");
    cutscene_castle_harbor(p);
}

void cutscene_castle_harbor(Player* p) {
    p->currmap = p->currmap->next;
    wclear(p->getwin());
    wborder(p->getwin(), (int)'|', (int)'|', (int)'-', (int)'-', (int)'+', (int)'+', (int)'+', (int)'+');
    wrefresh(p->getwin());
    Textbox text;
    text.print("Disembarking onto the rocky shores, George Washington leads his band of misfits towards the imposing castle gates, determination blazing in their eyes.");
    text.print("With nothing but their wits and a reckless courage, they press onward, ready for their final showdown with the tyrant who dares to oppress their land.");
    p->setpos(4, 50);
    p->display();
    Character Benjamin(4, 45, 'B', p->getwin());
    Character Jefferson(4, 40, 'J', p->getwin());
    Character Adams(4, 35, 'A', p->getwin());
    text.print("George: To end the British occupation for FREEDOM!");
    p->currmap->scene_data.insert(make_pair(Benjamin.charLetter, make_pair(Benjamin.yPos, Benjamin.xPos)));
    p->currmap->scene_data.insert(make_pair(Jefferson.charLetter, make_pair(Jefferson.yPos, Jefferson.xPos)));
    p->currmap->scene_data.insert(make_pair(Adams.charLetter, make_pair(Adams.yPos, Adams.xPos)));
    text.delwin();
    p->display();
}

void cutscene_castle_harbor2(Player* p) {
    Textbox text;
    text.print("As they approach the colossal iron doors barring their path, a foreboding sign looms overhead.");
    text.print("Warning of dire consequences for those who dare to trespass onto royal grounds.");
    text.print("George Washington presses on, undeterred by the warning.");
    text.print("George: I can't read, so this won't stop me!");
    text.delwin();
    p->display();
}

void cutscene_castle_outside(Player* p) {
    p->currmap->prev->scene_data.clear();
    Character Benjamin(p->gety() + 2, p->getx() + 4, 'B', p->getwin());
    Character Jefferson(p->gety() + 4, p->getx() + 4, 'J', p->getwin());
    Character Adams(p->gety() - 2, p->getx() + 4, 'A', p->getwin());
    Character Musketeer1(12, 47, 'M', p->getwin());
    Character Musketeer2(10, 49, 'M', p->getwin());
    Character Musketeer3(14, 49, 'M', p->getwin());
    Textbox text;
    text.print("Out brave heros make there way inside the castle walls.");
    text.print("There they are met by the formidable trio known as the Royal Musketeers.");
    text.print("Their sneering taunts echoing off the castle walls.");
    text.print("George: One, two, three. First we'll kill you, and then drink tea!");
    text.print("The 3 Musketeers want to battle!");
    p->currmap->scene_data.insert(make_pair(Benjamin.charLetter, make_pair(Benjamin.yPos, Benjamin.xPos)));
    p->currmap->scene_data.insert(make_pair(Jefferson.charLetter, make_pair(Jefferson.yPos, Jefferson.xPos)));
    p->currmap->scene_data.insert(make_pair(Adams.charLetter, make_pair(Adams.yPos, Adams.xPos)));
    start_combat_castle(p->getwin());
    p->display();
    text.print("You vanquished the Three Musketeers!");
    text.print("King George lies just ahead.");
    text.delwin();
    p->display();
}

void cutscene_castle(Player* p) {
    Textbox text;
    p->currmap->prev->scene_data.clear();
    Character George(p->gety(), p->getx(), 'G', p->getwin());
    Character Benjamin(p->gety() + 2, p->getx() + 4, 'B', p->getwin());
    Character Jefferson(p->gety() + 4, p->getx() + 4, 'J', p->getwin());
    Character Adams(p->gety() - 2, p->getx() + 4, 'A', p->getwin());
    Character KingGeorge(p->gety(), p->getx() + 40, 'K', p->getwin());
    text.print("Finally, the Founding Fathers stand before King George himself.");
    text.print("His arrogance palpable as he sneers.");
    text.print("King George: Fear me and my wrath!");
    text.print("Without hesitation, George Washington steps foward.");
    George.moveChar(RIGHT, 7, 100);
    text.print("He then raises his weapon and fires, silencing the tyrant forever.");
    text.print("BANG!");
    Character Bullet(George.yPos, George.xPos + 1, '.', p->getwin());
    Bullet.moveChar(RIGHT, 32, 25);
    KingGeorge.charLetter = ' ';
    KingGeorge.display();
    text.print("George: Alas, liberty restored!");
    text.print("George: Maybe the real liberty was the friends we made along the way.");
    text.print("Amidst laughter and camaraderie, they make their way back to their ship.");
    text.print("Sailing off into the sunset, leaving behind a land forever changed by their absurd and audacious quest for freedom.");
    text.print("The End");
    endwin();
}
