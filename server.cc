#include <array>
#include <boost/asio.hpp>
#include <ncurses.h>
#include <curses.h>
#include "/public/read.h"
#include <unistd.h>
#include <string> 
#include <ctime>

using namespace std;
using boost::asio::ip::tcp;

string make_daytime_string() {
	using namespace std;
	time_t now = time(0);
	return ctime(&now);
}

static void finish(int sig) {
    endwin();
      exit(0);
  }

class Game {
//TODO: Put all of our game code and all that in here
};

int main() {


	
	//I initiated all the ncurses stuff here will need to send Game to the client side to initiate the map and all that
	/*
	//TODO:: Remember ncurses doesn't let you cout anything.
    (void) signal(SIGINT, finish);
    (void) initscr();
    (void) scrollok(stdscr, TRUE);
    keypad(stdscr, TRUE);
    (void) nonl();
    (void) cbreak();
    (void) noecho();
	*/

	try {
		boost::asio::io_context io_context;
		tcp::endpoint endpoint(tcp::v4(), 2672);
		tcp::acceptor acceptor(io_context, endpoint);
		tcp::iostream stream;
		boost::system::error_code ec;
		acceptor.accept(stream.socket(),ec);
		string s;
		if (!ec) {
			//TODO: All of our repeating code in here to have it transfer between client and server.
			//Just like a cout and cin statement, EX: stream << Map; and stream >> playerMove;
		}
		
		else throw ec;
	}
	catch (exception &e) {
		cerr << e.what() << endl;
	}
}

