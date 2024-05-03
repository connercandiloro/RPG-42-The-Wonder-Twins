//Tanner Dunn - Inheritor of Suffering
#include "heroes_and_monsters.h"

Actor::Actor(int new_x, int new_y) : y(new_y), x(new_x){};
//pure virtual move_location(int new_x, int new_y) = 0; already defined 
pair<int, int> Actor::get_location(){
	int pos1 = x;
	int pos2 = y;
	return make_pair(pos1, pos2);
}
void Actor::move_location(int new_y, int new_x) { 
	y = new_y;	
	x = new_x;
}
void Actor::total_characters(){
	if(!is_called){
	//	cout << "No characters on the map" << endl;	
	}
	else{
		total++;
	}
//	cout << "Total number of characters on the map: " << total << endl;
}
Stationary_Object::Stationary_Object(int x, int y) : Actor(x,y){};
void Stationary_Object::set_name(const string& new_name){object_name = new_name;}
string Stationary_Object::get_name(){return object_name;}
pair<int, int> Stationary_Object::get_location(){
	int pos1 = x;
	int pos2 = y;
	return make_pair(pos1, pos2);
}
Hero::Hero(int x, int y, int base_health, int initiative) : Actor(x, y), HP(base_health), init(initiative){};
void Hero::set_name(const string& new_name){name = new_name;}
string Hero::get_name()const{return name;}
void Hero::set_DPS(int DPS){attack_damage = DPS;}
int Hero::get_DPS()const{return attack_damage;}
void Hero::set_HP(int new_HP){
	if(new_HP < 1){
	//	cout << "YOU DIED" << endl;
		HP = 0;
	}
	else{
		HP = new_HP;
	}
}
int Hero::get_initiative() const{return init;}
void Hero::set_initiative(int new_initiative){
	if (new_initiative > 0){
		init = new_initiative;
	}
}
int Hero::get_HP()const{return HP;}
//pure virtual attack() = 0; already defined;
George_Washington::George_Washington(int x, int y) : Hero(x, y, 300, 14){}
void George_Washington::attack(int x){
	switch(x){
		case 1:
		//	cout << get_name() << " commands his feelt to attack the British!" << endl;
			set_DPS(50);
		//	cout << get_DPS() << " Damage Done!" << endl;
		break;
		case 2:
		//	cout << get_name() << " hurls a fury of fists at the British Soldiers!" << endl;
			set_DPS(40);
		//	cout << get_DPS() << " Damage Done!" << endl;
		break;
		case 3: 
		//	cout << get_name() << " summons a trillion dollar bills to attack the British!" << endl;
			set_DPS(35);
		//	cout << get_DPS() << " Damage Done!" << endl;
		break;
		default:
		//	cout << "Invalid Choice!" << endl;
		break;
	}	
}
pair<int, int> George_Washington::get_location(){
	int pos1 = x;
	int pos2 = y;
	return make_pair(pos1, pos2);
}
Benjamin_Franklin::Benjamin_Franklin(int x, int y) : Hero(x, y, 225, 13){is_called = true;}
void Benjamin_Franklin::attack(int x){
	switch(x){
		case 1:
		//	cout << get_name() << " fills the enemies mind with too much wisdom!" << endl;
			set_DPS(30);
		//	cout << get_DPS() << " Damage Done!" << endl;
		break;
		case 2:
		//	cout << get_name() << " throws an electric charged spear at the British Forces!" << endl;
			set_DPS(45);
		//	cout << get_DPS() << " Damage Done!" << endl;
		break;
		case 3: 
		//	cout << get_name() << " hurls a hot Franklin Stove burning the enemies!" << endl;
			set_DPS(50);
		//	cout << get_DPS() << " Damage Done!" << endl;
		break;
		default:
		//	cout << "Invalid Choice!" << endl;
		break;
	}	
}
pair<int, int> Benjamin_Franklin::get_location(){
	int pos1 = x;
	int pos2 = y;
	return make_pair(pos1, pos2);
}
John_Adams::John_Adams(int x, int y) : Hero(x, y, 275, 9){is_called = true;}
void John_Adams::attack(int x){
		switch(x){
		case 1:
		//	cout << get_name() << " stares into the souls of the British and inflicts fear upon them!" << endl;
			set_DPS(30);
		//	cout << get_DPS() << " Damage Done!" << endl;
		break;
		case 2:
		//	cout << get_name() << " summons a naval fleet to fire cannon balls at the British Forces!" << endl;
			set_DPS(40);
		//	cout << get_DPS() << " Damage Done!" << endl;
		break;
		case 3: 
		//	cout << get_name() << " summons the white house to fall out of the sky onto the British Forces!" << endl;
			set_DPS(55);
		//	cout << get_DPS() << " Damage Done!" << endl;
		break;
		default:
		//	cout << "Invalid Choice!" << endl;
		break;
	}	
}
pair<int, int> John_Adams::get_location(){
	int pos1 = x;
	int pos2 = y;
	return make_pair(pos1, pos2);
}
James_Madison::James_Madison(int x, int y) : Hero(x, y, 200, 11){is_called = true;}
void James_Madison::attack(int x){
	switch(x){
		case 1:
		//	cout << get_name() << " sends his fist flying into a British Soldier!" << endl;
			set_DPS(45);
		//	cout << get_DPS() << " Damage Done!" << endl;
		break;
		case 2:
		//	cout << get_name() << " summons the Federalist Papers in a storm that cuts the British Forces skin!" << endl;
			set_DPS(30);
		//	cout << get_DPS() << " Damage Done!" << endl;
		break;
		case 3: 
		//	cout << get_name() << " turns the bill of rights into a giant club to smash the British!" << endl;
			set_DPS(40);
		//	cout << get_DPS() << " Damage Done!" << endl;
		break;
		default:
		//	cout << "Invalid Choice!" << endl;
		break;
	}	
}
pair<int, int> James_Madison::get_location(){
	int pos1 = x;
	int pos2 = y;
	return make_pair(pos1, pos2);
}
Thomas_Jefferson::Thomas_Jefferson(int x, int y) : Hero(x, y, 300, 10){is_called = true;}
void Thomas_Jefferson::attack(int x){
	switch(x){
		case 1:
		//	cout << get_name() << " exclaims the Declaration of Independence against the British striking fear into their hearts!" << endl;
			set_DPS(35);
		//	cout << get_DPS() << " Damage Done!" << endl;
		break;
		case 2:
		//	cout << get_name() << " throws the british into his macaroni machine!" << endl;
			set_DPS(50);
		//	cout << get_DPS() << " Damage Done!" << endl;
		break;
		case 3: 
		//	cout << get_name() << " exclaims that religious freedom will be a part of America once the British are gone causing dread among the troops!" << endl;
			set_DPS(40);
		//	cout << get_DPS() << " Damage Done!" << endl;
		break;
		default:
		//	cout << "Invalid Choice!" << endl;
		break;
	}	
}
pair<int, int> Thomas_Jefferson::get_location(){
	int pos1 = x;
	int pos2 = y;
	return make_pair(pos1, pos2);
}















