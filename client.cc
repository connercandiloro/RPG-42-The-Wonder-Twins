#include "/public/read.h"
#include <boost/asio.hpp>
#include <cstdlib>
#include <curses.h>
#include <ncurses.h>
#include <string> 
#include <iostream>
#include <cstdint>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;
using boost::asio::ip::tcp;

static void finish(int sig) {
	endwin();
	exit(0);
}

int main(int argc, char* argv[]) {

	try {
		/*
		TODO: If we want to have the user input the ip address and port number use this.
		 if (argc != 3) {
             cerr << "Usage: <client> <ip> <port>\n";
        }
		*/

		tcp::iostream stream("localhost", "2672");
//	TODO: And this is the other part of the above TODO	tcp::iostream stream(to_string(argc), to_string(argc));

		if (!stream) { // connection failed
			cout << "ERROR! " << stream.error().message() << endl;
		}
		while (true) {
			//TODO: All of are client side things need to be done here. So stream >> objects and stream << key strokes(char's);
		}

	}
	catch (exception &e) {
		cout << "Exception: " << e.what() << endl;
		exit(EXIT_FAILURE);
	}
}

