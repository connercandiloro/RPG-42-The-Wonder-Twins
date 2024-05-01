//Tanner Dunn - Inheritor of Suffering
#include "heroes_and_monsters.h"
Actor::Actor(int new_x, int new_y) : x(new_x), y(new_y){};
Actor::~Actor() = default;
//pure virtual move_location(int new_x, int new_y) = 0; already defined 
pair<int, int> Actor::get_location(){
	int pos1 = x;
	int pos2 = y;
	return make_pair(pos1, pos2);
}
void Actor::total_characters(){
	if(!is_called){
		cout << "No characters on the map" << endl;	
	}
	else{
		total++;
	}
	cout << "Total number of characters on the map: " << total << endl;
}
Stationary_Object::Stationary_Object(int x, int y) : Actor(x,y){};
void Stationary_Object::set_name(const string& new_name){object_name = new_name;}
string Stationary_Object::get_name(){return object_name;}
void Stationary_Object::move_location(int new_x, int new_y){throw out_of_range("Cannot move stationary object in the world");}
pair<int, int> Stationary_Object::get_location(){
	int pos1 = x;
	int pos2 = y;
	return make_pair(pos1, pos2);
}
Hero::Hero(int x, int y, int base_health) : Actor(x, y), HP(base_health){};
void Hero::set_name(const string& new_name){name = new_name;}
string Hero::get_name()const{return name;}
void Hero::set_DPS(int DPS){attack_damage = DPS;}
int Hero::get_DPS()const{return attack_damage;}
void Hero::set_HP(int new_HP){
	if(new_HP < 1){
		cout << "YOU DIED" << endl;
		HP = 0;
	}
	else{
		HP = new_HP;
	}
}
int Hero::get_HP()const{return HP;}
//pure virtual attack() = 0; already defined;
George_Washington::George_Washington(int x, int y) : Hero(x, y, 300){is_called = true;}
void George_Washington::attack(){
	int choice;
	cout << "Choose your attack!" << endl;
	cout << "1. Commander's Fleet" << endl;
	cout << "2. First President's Fists of Fury" << endl;
	cout << "3. Dollar Bill Beatdown" << endl;
	cin >> choice;
	switch(choice){
		case 1:
			cout << get_name() << " commands his feelt to attack the British!" << endl;
			set_DPS(50);
			cout << get_DPS() << " Damage Done!" << endl;
		break;
		case 2:
			cout << get_name() << " hurls a fury of fists at the British Soldiers!" << endl;
			set_DPS(40);
			cout << get_DPS() << " Damage Done!" << endl;
		break;
		case 3: 
			cout << get_name() << " summons a trillion dollar bills to attack the British!" << endl;
			set_DPS(35);
			cout << get_DPS() << " Damage Done!" << endl;
		break;
		default:
			cout << "Invalid Choice!" << endl;
		break;
	}	
}
void George_Washington::move_location(int new_x, int new_y) { 
	x = new_x;
	y = new_y;
}
pair<int, int> George_Washington::get_location(){
	int pos1 = x;
	int pos2 = y;
	return make_pair(pos1, pos2);
}
Benjamin_Franklin::Benjamin_Franklin(int x, int y) : Hero(x, y, 225){is_called = true;}
void Benjamin_Franklin::attack(){
	int choice;
	cout << "Choose your attack!" << endl;
	cout << "1. Bifocal Wisdom" << endl;
	cout << "2. Lightening Rod Spear" << endl;
	cout << "3. Franklin Stove Throw" << endl;
	cin >> choice;
	switch(choice){
		case 1:
			cout << get_name() << " fills the enemies mind with too much wisdom!" << endl;
			set_DPS(30);
			cout << get_DPS() << " Damage Done!" << endl;
		break;
		case 2:
			cout << get_name() << " throws an electric charged spear at the British Forces!" << endl;
			set_DPS(45);
			cout << get_DPS() << " Damage Done!" << endl;
		break;
		case 3: 
			cout << get_name() << " hurls a hot Franklin Stove burning the enemies!" << endl;
			set_DPS(50);
			cout << get_DPS() << " Damage Done!" << endl;
		break;
		default:
			cout << "Invalid Choice!" << endl;
		break;
	}	
}
void Benjamin_Franklin::move_location(int new_x, int new_y) { 
	x = new_x;
	y = new_y;
}
pair<int, int> Benjamin_Franklin::get_location(){
	int pos1 = x;
	int pos2 = y;
	return make_pair(pos1, pos2);
}
John_Adams::John_Adams(int x, int y) : Hero(x, y, 275){is_called = true;}
void John_Adams::attack(){
	int choice;
	cout << "Choose your attack!" << endl;
	cout << "1. Second President Staredown" << endl;
	cout << "2. Naval Fleet Fury" << endl;
	cout << "3. White House Slamdown" << endl;
	cin >> choice;
	switch(choice){
		case 1:
			cout << get_name() << " stares into the souls of the British and inflicts fear upon them!" << endl;
			set_DPS(30);
			cout << get_DPS() << " Damage Done!" << endl;
		break;
		case 2:
			cout << get_name() << " summons a naval fleet to fire cannon balls at the British Forces!" << endl;
			set_DPS(40);
			cout << get_DPS() << " Damage Done!" << endl;
		break;
		case 3: 
			cout << get_name() << " summons the white house to fall out of the sky onto the British Forces!" << endl;
			set_DPS(55);
			cout << get_DPS() << " Damage Done!" << endl;
		break;
		default:
			cout << "Invalid Choice!" << endl;
		break;
	}	
}
void John_Adams::move_location(int new_x, int new_y) { 
	x = new_x;
	y = new_y;
}
pair<int, int> John_Adams::get_location(){
	int pos1 = x;
	int pos2 = y;
	return make_pair(pos1, pos2);
}
James_Madison::James_Madison(int x, int y) : Hero(x, y, 200){is_called = true;}
void James_Madison::attack(){
	int choice;
	cout << "Choose your attack!" << endl;
	cout << "1. Founding Father's Fist of Death" << endl;
	cout << "2. Federalist Paper Flury" << endl;
	cout << "3. Bill of Rights Club" << endl;
	cin >> choice;
	switch(choice){
		case 1:
			cout << get_name() << " sends his fist flying into a British Soldier!" << endl;
			set_DPS(45);
			cout << get_DPS() << " Damage Done!" << endl;
		break;
		case 2:
			cout << get_name() << " summons the Federalist Papers in a storm that cuts the British Forces skin!" << endl;
			set_DPS(30);
			cout << get_DPS() << " Damage Done!" << endl;
		break;
		case 3: 
			cout << get_name() << " turns the bill of rights into a giant club to smash the British!" << endl;
			set_DPS(40);
			cout << get_DPS() << " Damage Done!" << endl;
		break;
		default:
			cout << "Invalid Choice!" << endl;
		break;
	}	
}
void James_Madison::move_location(int new_x, int new_y) { 
	x = new_x;
	y = new_y;
}
pair<int, int> James_Madison::get_location(){
	int pos1 = x;
	int pos2 = y;
	return make_pair(pos1, pos2);
}
Thomas_Jefferson::Thomas_Jefferson(int x, int y) : Hero(x, y, 300){is_called = true;}
void Thomas_Jefferson::attack(){
	int choice;
	cout << "Choose your attack!" << endl;
	cout << "1. Declarartion of Independence" << endl;
	cout << "2. Macaroni Machine" << endl;
	cout << "3. Religious Freedom Freestyle" << endl;
	cin >> choice;
	switch(choice){
		case 1:
			cout << get_name() << " exclaims the Declaration of Independence against the British striking fear into their hearts!" << endl;
			set_DPS(35);
			cout << get_DPS() << " Damage Done!" << endl;
		break;
		case 2:
			cout << get_name() << " throws the british into his macaroni machine!" << endl;
			set_DPS(50);
			cout << get_DPS() << " Damage Done!" << endl;
		break;
		case 3: 
			cout << get_name() << " exclaims that religious freedom will be a part of America once the British are gone causing dread among the troops!" << endl;
			set_DPS(40);
			cout << get_DPS() << " Damage Done!" << endl;
		break;
		default:
			cout << "Invalid Choice!" << endl;
		break;
	}	
}
void Thomas_Jefferson::move_location(int new_x, int new_y) { 
	x = new_x;
	y = new_y;
}
pair<int, int> Thomas_Jefferson::get_location(){
	int pos1 = x;
	int pos2 = y;
	return make_pair(pos1, pos2);
}
Colonist::Colonist(int x, int y) : Hero(x, y, 150){is_called = true;}
void Colonist::attack(){
	srand(time(nullptr));
	int random_attack_number = (rand() % 3) +1;
	switch(random_attack_number){
		case 1:
			cout << get_name() << " shoots his musket at the british!" << endl;
			set_DPS(35);
			cout << get_DPS() << " Damage Done!" << endl;
		break;
		case 2:
			cout << get_name() << " sets off a cannon towards the direction of the British!" << endl;
			set_DPS(40);
			cout << get_DPS() << " Damage Done!" << endl;
		break;
		case 3: 
			cout << get_name() << " runs up to the British and stabs them with their musket" << endl;
			set_DPS(35);
			cout << get_DPS() << " Damage Done!" << endl;
		break;
		default:
			cout << "Invalid Choice!" << endl;
		break;
	}	
}
void Colonist::move_location(int new_x, int new_y) { 
	x = new_x;
	y = new_y;
}
pair<int, int> Colonist::get_location(){
	int pos1 = x;
	int pos2 = y;
	return make_pair(pos1, pos2);
}
void Colonist::run_ai(){
	while(true)	{
		srand(time(nullptr));
		int random_number = (rand() % 4) +1;
		if(random_number == 1){
			int new_x = x - 1;
			move_location(new_x, y);
		}
		if(random_number == 2){
			int new_x = x + 1;
			move_location(new_x, y);
		}
		if(random_number == 3){
			int new_y = y - 1;
			move_location(x, new_y);
		}
		if(random_number == 4){
			int new_y = y + 1;
			move_location(x, new_y);
		}
		usleep(3'000'000);
	}
	//TODO create a function where it will check if the colonist is on the same space as the enemey and then attack it.
}















