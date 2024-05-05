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


/*int testInteger(int x) { return x; }

TEST(testInteger, basic_equality) {
	EXPECT_EQ(testInteger(5), 5);
}

TEST(getlocation, AllInheritanceFunctions) { //Replace with tests like washington, etc.
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
		
}*/

//Inheritance Tests Part 2:

TEST(HeroLocation, GetLoc_vs_Cstor) { //Default location check
	George_Washington gw(1,2); //NOTE: (x,y) in constructor for heroes
	//cout << "total characters = 1: " << gw.total << endl; //Totals not accesible (protected not public), need a getter if you want to check them.
	Benjamin_Franklin bf(2,3);
	John_Adams ja(3,4);
	James_Madison jm(4,5);
	Thomas_Jefferson tj(5,6);
	EXPECT_EQ(gw.get_location(), make_pair(1,2)); //NOTE: (x,y) in get_location.
	EXPECT_EQ(bf.get_location(), make_pair(2,3));
	EXPECT_EQ(ja.get_location(), make_pair(3,4));
	EXPECT_EQ(jm.get_location(), make_pair(4,5));
	EXPECT_EQ(tj.get_location(), make_pair(5,6)); 
	//All tests pass in this configuration.
}

TEST(HeroLocation, GetLoc_vs_MoveLoc) { //Set location check.
	George_Washington gw(1,2); //NOTE: (x,y) in constructor for heroes
	Benjamin_Franklin bf(2,3);
	John_Adams ja(3,4);
	James_Madison jm(4,5);
	Thomas_Jefferson tj(5,6);
	EXPECT_EQ(gw.get_location(), make_pair(1,2)); 
	EXPECT_EQ(bf.get_location(), make_pair(2,3));
	EXPECT_EQ(ja.get_location(), make_pair(3,4));
	EXPECT_EQ(jm.get_location(), make_pair(4,5));
	EXPECT_EQ(tj.get_location(), make_pair(5,6)); 
	
	gw.move_location(2,1); //NOTE: Set location uses yx, so this doesn't actually change anything.
	bf.move_location(3,2);
	ja.move_location(4,3);
	jm.move_location(5,4);
	tj.move_location(6,5);

	//Below tests fail because get_location and constructor use xy, while move_location uses yx.
	//FIXME: For best compatability with ncurses yx format, change all to yx. Regardless, must match to avoid incorrect behavior.
	EXPECT_EQ(gw.get_location(), make_pair(2,1)); 
	EXPECT_EQ(bf.get_location(), make_pair(3,2));
	EXPECT_EQ(ja.get_location(), make_pair(4,3));
	EXPECT_EQ(jm.get_location(), make_pair(5,4));
	EXPECT_EQ(tj.get_location(), make_pair(6,5)); 	

	
}

TEST(MonsterLocation, GetLoc_vs_Cstor) {
	King_George_III kg(1,2); //NOTE: Cstor uses xy.
	Robo_Shakespeare rs(2,3);
	Kraken kr(3,4);
	Red_Coat_General rg(4,5);
	Three_Musketeers tm(5,6);
	Red_Coats rc(6,7);
	EXPECT_EQ(kg.get_location(), make_pair(1,2)); //NOTE: get_loc uses xy
	EXPECT_EQ(rs.get_location(), make_pair(2,3));
	EXPECT_EQ(kr.get_location(), make_pair(3,4));
	EXPECT_EQ(rg.get_location(), make_pair(4,5));
	EXPECT_EQ(tm.get_location(), make_pair(5,6)); 
	EXPECT_EQ(rc.get_location(), make_pair(6,7));

}

TEST(MonsterLocation, GetLoc_vs_MoveLoc) {
	King_George_III kg(1,2);
	Robo_Shakespeare rs(2,3);
	Kraken kr(3,4);
	Red_Coat_General rg(4,5);
	Three_Musketeers tm(5,6);
	Red_Coats rc(6,7);
	EXPECT_EQ(kg.get_location(), make_pair(1,2)); 
	EXPECT_EQ(rs.get_location(), make_pair(2,3));
	EXPECT_EQ(kr.get_location(), make_pair(3,4));
	EXPECT_EQ(rg.get_location(), make_pair(4,5));
	EXPECT_EQ(tm.get_location(), make_pair(5,6)); 
	EXPECT_EQ(rc.get_location(), make_pair(6,7));

	kg.move_location(2,1); //NOTE: Set location uses yx, so this doesn't actually change anything.
	rs.move_location(3,2);
	kr.move_location(4,3);
	rg.move_location(5,4);
	tm.move_location(6,5);
	rc.move_location(7,6);

	EXPECT_EQ(kg.get_location(), make_pair(2,1)); //move_loc uses yx, FIXME like above. 
	EXPECT_EQ(rs.get_location(), make_pair(3,2));
	EXPECT_EQ(kr.get_location(), make_pair(4,3));
	EXPECT_EQ(rg.get_location(), make_pair(5,4));
	EXPECT_EQ(tm.get_location(), make_pair(6,5)); 
	EXPECT_EQ(rc.get_location(), make_pair(7,6));



}

bool checkIfAdj(pair<int, int> og, pair<int, int> mv) {
	int ogX = og.first, ogY = og.second, mvX = mv.first, mvY = mv.second; //xy format check
	if ((mvY == ogY - 1) && mvX == ogX) { //Above
		cout << "above" << endl;
		return true;
	}
	else if (mvY == ogY && (mvX == ogX - 1)) { //Left
		cout << "left" << endl;
		return true;
	}
	else if (mvY == ogY && (mvX == ogX + 1)) { //Right
		cout << "right" << endl;
		return true;
	}
	else if ((mvY == ogY + 1) && mvX == ogX) { //Down
		cout << "down" << endl;
		return true;
	}
	else {
		cout << "Diagnostic: " << endl;
		return false;
	}

}
//NOTE: Random number generation correctly generates adjacent spots.
TEST(MonsterLocation, MonsterAI) { 
	King_George_III kg(1,2);
	Robo_Shakespeare rs(2,3);
	Kraken kr(3,4);
	Red_Coat_General rg(4,5);
	Three_Musketeers tm(5,6);
	Red_Coats rc(6,7);
	EXPECT_EQ(kg.get_location(), make_pair(1,2)); 
	EXPECT_EQ(rs.get_location(), make_pair(2,3));
	EXPECT_EQ(kr.get_location(), make_pair(3,4));
	EXPECT_EQ(rg.get_location(), make_pair(4,5));
	EXPECT_EQ(tm.get_location(), make_pair(5,6)); 
	EXPECT_EQ(rc.get_location(), make_pair(6,7));

	kg.run_ai(); //FIXME: run_ai() reseeds every function call, time(nullptr) only refreshes once a second, so my advice would be to manually increment the seed with srand(aicounter), with a counter++ at the beginning of the ai functions. This guarantees a different seed every call.
	EXPECT_NE(kg.get_location(), make_pair(1,2));
	EXPECT_TRUE(checkIfAdj(make_pair(1,2), kg.get_location()));
	//cout << "new kg location, (1,2) -> (" << kg.get_location().first << "," << kg.get_location().second << ")" << endl;
	//usleep(1'500'000);
	rs.run_ai();
	EXPECT_NE(rs.get_location(), make_pair(2,3));
	EXPECT_TRUE(checkIfAdj(make_pair(2,3), rs.get_location()));
	//cout << "new rs location, (2,3) -> (" << rs.get_location().first << "," << rs.get_location().second << ")" << endl;
	//usleep(1'500'000);
	kr.run_ai();
	EXPECT_NE(kr.get_location(), make_pair(3,4));
	EXPECT_TRUE(checkIfAdj(make_pair(3,4), kr.get_location()));
	//cout << "new kr location, (3,4) -> (" << kr.get_location().first << "," << kr.get_location().second << ")" << endl;
	//usleep(1'500'000);
	rg.run_ai();
	EXPECT_NE(rg.get_location(), make_pair(4,5));
	EXPECT_TRUE(checkIfAdj(make_pair(4,5), rg.get_location()));
	//cout << "new rg location, (4,5) -> (" << rg.get_location().first << "," << rg.get_location().second << ")" << endl;
	//usleep(1'500'000);
	tm.run_ai();
	EXPECT_NE(tm.get_location(), make_pair(5,6));
	EXPECT_TRUE(checkIfAdj(make_pair(5,6), tm.get_location()));
	//cout << "new tm location, (5,6) -> (" << tm.get_location().first << "," << tm.get_location().second << ")" << endl;
	//usleep(1'500'000);
	rc.run_ai();
	EXPECT_NE(rc.get_location(), make_pair(6,7));
	EXPECT_TRUE(checkIfAdj(make_pair(6,7), rc.get_location()));
	//cout << "new rc location, (6,7) -> (" << rc.get_location().first << "," << rc.get_location().second << ")" << endl;
	//usleep(1'500'000);

}

TEST(HeroName, GetName_vs_Cstor) { //Should these be set by default?

}

TEST(HeroName, GetName_vs_SetName) {
}

TEST(MonsterName, GetName_vs_Cstor) { //Should be empty?
}

TEST(MonsterName, GetName_vs_SetName) { //Can these be set?
}


TEST(ActorInfo, TotalCharacters) {
//FIXME: Total characters inaccessible (protected, no getter), cannot verify, function may or may not work
}

TEST(HeroInit, InitCstor) {
}

TEST(HeroInit, GetSetInit) {
}

TEST(MonsterInit, InitCstor) {
}

TEST(MonsterInit, GetSetInit) {
}

TEST(HeroAttack, HeroAttack) { //Takes argument
}

TEST(MonsterAttack, MonsterAttack) { //Takes random number
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

	/*
	const int runNum = 100;

	for (int i = 0; i < runNum; i++) {
		pair<int, int> oldPos = kg.get_location();
		kg.run_ai();
		usleep(1'500'000);

		pair<int, int> newPos = kg.get_location();
		EXPECT_NE(newPos, oldPos);
		EXPECT_TRUE(checkIfAdj(oldPos, newPos));	

	}
	
	for (int i = 0; i < runNum; i++) {
		pair<int, int> oldPos = rs.get_location();
		rs.run_ai();
		pair<int, int> newPos = rs.get_location();
		EXPECT_NE(newPos, oldPos);
		EXPECT_TRUE(checkIfAdj(oldPos, newPos));	

	}
	for (int i = 0; i < runNum; i++) {
		pair<int, int> oldPos = kr.get_location();
		kr.run_ai();
		pair<int, int> newPos = kr.get_location();
		EXPECT_NE(newPos, oldPos);
		EXPECT_TRUE(checkIfAdj(oldPos, newPos));	

	}
	for (int i = 0; i < runNum; i++) {
		pair<int, int> oldPos = rg.get_location();
		rg.run_ai();
		pair<int, int> newPos = rg.get_location();
		EXPECT_NE(newPos, oldPos);
		EXPECT_TRUE(checkIfAdj(oldPos, newPos));	

	}
	for (int i = 0; i < runNum; i++) {
		pair<int, int> oldPos = tm.get_location();
		tm.run_ai();
		pair<int, int> newPos = tm.get_location();
		EXPECT_NE(newPos, oldPos);
		EXPECT_TRUE(checkIfAdj(oldPos, newPos));	

	}
	for (int i = 0; i < runNum; i++) {
		pair<int, int> oldPos = rc.get_location();
		rc.run_ai();
		pair<int, int> newPos = rc.get_location();
		EXPECT_NE(newPos, oldPos);
		EXPECT_TRUE(checkIfAdj(oldPos, newPos));	

	}*/

