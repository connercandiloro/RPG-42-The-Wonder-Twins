//Luke Olson Gtesting
#include <iostream>
#include <gtest/gtest.h> //Compile with -lgtest
using namespace std;
//Main test in googletest/docs/primer.md info.

string userMove() {
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



}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	cout << RUN_ALL_TESTS() << endl;

}

