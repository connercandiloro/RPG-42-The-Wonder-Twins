//Luke Olson Gtesting
#include <iostream>
#include "heroes_and_monsters.h"
#include <gtest/gtest.h> //Compile with -lgtest, \g++ test.cc heroes.cc monsters.cc -lgtest
using namespace std;
//Main test in googletest/docs/primer.md info.

/*
***Inheritance Test Results***
Tested essentially everything I could, if you want a retest at a later date ask.

THINGS TO CHANGE:
Location Functions: 
- Switch order of x and y's to work with ncurses (y,x) format.
- For future, consider changing cout statements so it works in final game (pass on the awesome lines to the integrator or whoever makes the game.)
- Move location functions to actor superclass, because all heroes and monsters have exactly the same function.
- George_Washington, Benjamin Franklin, etc should not be of abstract types (run_ai pure virtual from hero).
-- Suggestion: Make run_ai only a feature on the monsters, as they are the only ones that need to roam around.
   This does not need to be a part of the hero class, so just have the run_ai function return like it says in the README.
   Input will be handled by another function, so run_ai doesn't need to worry about that.
   If you want generic colonists to have AI, then include it as well.
-- Colonist currently has run_ai implemented, so code compiles.
- run_ai colonist implementation does not work, currently in infinite loop with delay. Should only randomly generate one movement, then stop/exit function. run_ai is designed to be called itself multiple times, so it only has to result in one random movement.
- Combat speed variable for heroes and monsters necessary to determine turn order.
- get_DPS() returns random values if no set_DPS(int) called before it, no default value set for attack damage so returns anything in memory, set this to some value like 1.
 - should set_DPS() allow you to set negative values? Probably should have a minimum of 0 dps.

THINGS THAT WORK:
- get_location() and move_location() code itself is functional (see CHANGE section for reccomended relocation).
- get_HP() and set_HP() work.
*/


int testInteger(int x) { return x; }

TEST(testInteger, basic_equality) {
	EXPECT_EQ(testInteger(5), 5);
}

TEST(get_location, AllInheritanceFunctions) { //Replace with tests like washington, etc.
	//George_Washington gw(12,12);
	pair <int,int> posXY(7,7);
	Colonist cl(6,7);
	//Thomas_Jefferson tj(13,13);
	//Benjamin_Franklin bf(10,10);
	//James_Madison jm(9,9);
	//John_Adams ja(8,8);

	//EXPECT_EQ(testInteger(5), 5);
	EXPECT_EQ(cl.get_location(), make_pair(6,7));
	cl.move_location(1776, 1796);
	EXPECT_EQ(cl.get_location(), make_pair(1776, 1796));
	//EXPECT_EQ(gw.get_location(), posXY);
	EXPECT_EQ(cl.get_HP(), 150); //Colonist default hp is 150.
	cl.set_HP(2);
	EXPECT_EQ(cl.get_HP(), 2);
	cout << "colonist current location: " << cl.get_location().first << " " << cl.get_location().second << endl;
	//cl.run_ai();
	cout << "colonist new current location: " << cl.get_location().first << " " << cl.get_location().second << endl;
	cout << "colonist dps: " << cl.get_DPS() << endl; //Totally random, initialize attack_damage in hero and monster class with = 0 or = 1 or something.
	cl.set_DPS(-11);
	EXPECT_EQ(cl.get_DPS(), -11);
		
}


/*TEST(userMove, EdgeTests) {

}

TEST(userMove, BadTests) {

}*/

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);

	cout << RUN_ALL_TESTS() << endl;

}

/*string userMove() {
	char key = '\0';
	while (true) {
		cin >> key;
		if (!cin) {
			cout << "wrong key, use WASD, x to exit." << endl;
		}
		key = toupper(key);
		if (key == 'W')
			cout << "move up" << endl;
		else if (key == 'A') {
			cout << "move left" << endl;
		}
		else if (key == 'S') 
			cout << "move down" << endl;
		else if (key == 'D')
			cout << "move right" << endl;
		else if (key == 'X') {
			cout << "quiting time" << endl;
		}
	}

}*/

