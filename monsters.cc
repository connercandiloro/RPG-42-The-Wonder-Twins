//Tanner Dunn - Inheritor of Suffering
#include "heroes_and_monsters.h"

Monster::Monster(int x, int y, int base_health, int initiative) : Actor(x, y), HP(base_health), init(initiative){};
void Monster::set_DPS(int DPS){attack_damage = DPS;}
int Monster::get_DPS()const{return attack_damage;}
void Monster::set_HP(int new_HP){
	if(new_HP < 1){
		//	cout << "YOU DIED" << endl;
		HP = 0;
	}
	else{
		HP = new_HP;
	}
}
int Monster::get_HP()const{return HP;}
int Monster::get_initiative() const{return init;}
void Monster::set_initiative(int new_initiative){
	if (new_initiative > 0){
		init = new_initiative;
	}
}
//pure virtual void attack() = 0; already defined
//pure virtual void run_ai() = 0; already defined
King_George_III::King_George_III(int x, int y) : Monster(x, y, 450, 15){is_called = true;}
void King_George_III::attack(){
	srand(time(nullptr));
	int random_attack_number = (rand() % 3) +1;
	switch(random_attack_number){
		case 1:
			//	cout << "The King of Great Britian raises your taxes!" << endl;
			set_DPS(50);
			//	cout << get_DPS() << " Damage Done!" << endl;
		break;
		case 2:
			//	cout << "King George throws his crown at the Founding Fathers!" << endl;
			set_DPS(45);
			//	cout << get_DPS() << " Damage Done!" << endl;
		break;
		case 3: 
			//	cout << "King George begins to loose his grip on America and causes an earthquake from the madness!" << endl;
			set_DPS(40);
			//	cout << get_DPS() << " Damage Done!" << endl;
		break;
		default:
			//	cout << "Invalid Choice!" << endl;
		break;
	}	
}
pair<int, int> King_George_III::get_location(){
	int pos1 = x;
	int pos2 = y;
	return make_pair(pos1, pos2);
}
void King_George_III::run_ai(){
	srand(time(nullptr));
	int random_number = (rand() % 4) +1;
	if(random_number == 1){
		int new_x = x - 1;
		move_location(y, new_x);
	}
	if(random_number == 2){
		int new_x = x + 1;
		move_location(y, new_x);
	}
	if(random_number == 3){
		int new_y = y - 1;
		move_location(new_y, x);
	}
	if(random_number == 4){
		int new_y = y + 1;
		move_location(new_y, x);
	}
}
Robo_Shakespeare::Robo_Shakespeare(int x, int y) : Monster(x, y, 300, 6){is_called = true;}
void Robo_Shakespeare::attack(){
	srand(time(nullptr));
	int random_attack_number = (rand() % 3) +1;
	switch(random_attack_number){
		case 1:
			//	cout << "Robo Shakespeare uses his metal fist to attack the Founding Fathers" << endl;
			set_DPS(40);
			//	cout << get_DPS() << " Damage Done!" << endl;
		break;
		case 2:
			//	cout << "Robo Shakespeare recites Macbeth at the top his lungs causing hearing loss!" << endl;
			set_DPS(30);
			//	cout << get_DPS() << " Damage Done!" << endl;
		break;
		case 3: 
			//	cout << "Robo Shakespeare uses a laser canon to shoot at the Founding Fathers!" << endl;
			set_DPS(45);
			//	cout << get_DPS() << " Damage Done!" << endl;
		break;
		default:
			//	cout << "Invalid Choice!" << endl;
		break;
	}	
}
pair<int, int> Robo_Shakespeare::get_location(){
	int pos1 = x;
	int pos2 = y;
	return make_pair(pos1, pos2);
}
void Robo_Shakespeare::run_ai(){
	srand(time(nullptr));
	int random_number = (rand() % 4) +1;
	if(random_number == 1){
		int new_x = x - 1;
		move_location(y, new_x);
	}
	if(random_number == 2){
		int new_x = x + 1;
		move_location(y, new_x);
	}
	if(random_number == 3){
		int new_y = y - 1;
		move_location(new_y, x);
	}
	if(random_number == 4){
		int new_y = y + 1;
		move_location(new_y, x);
	}
}
Kraken::Kraken(int x, int y) : Monster(x, y, 400, 12){is_called = true;}
void Kraken::attack(){
	srand(time(nullptr));
	int random_attack_number = (rand() % 3) +1;
	switch(random_attack_number){
		case 1:
			//	cout << "The kraken uses all 8 tentacles to attack the Founding Fathers!" << endl;
			set_DPS(40);
			//	cout << get_DPS() << " Damage Done!" << endl;
		break;
		case 2:
			//	cout << "The kraken slams his tentacle onto the ground!" << endl;
			set_DPS(35);
			//	cout << get_DPS() << " Damage Done!" << endl;
		break;
		case 3: 
			//	cout << "The kraken squirts ink on the Founding Fathers" << endl;
			set_DPS(30);
			//	cout << get_DPS() << " Damage Done!" << endl;
		break;
		default:
			//	cout << "Invalid Choice!" << endl;
		break;
	}	
}
pair<int, int> Kraken::get_location(){
	int pos1 = x;
	int pos2 = y;
	return make_pair(pos1, pos2);
}
void Kraken::run_ai(){
	srand(time(nullptr));
	int random_number = (rand() % 4) +1;
	if(random_number == 1){
		int new_x = x - 1;
		move_location(y, new_x);
	}
	if(random_number == 2){
		int new_x = x + 1;
		move_location(y, new_x);
	}
	if(random_number == 3){
		int new_y = y - 1;
		move_location(new_y, x);
	}
	if(random_number == 4){
		int new_y = y + 1;
		move_location(new_y, x);
	}
}
Red_Coat_General::Red_Coat_General(int x, int y) : Monster(x, y, 275, 4){is_called = true;}
void Red_Coat_General::attack(){	
	srand(time(nullptr));
	int random_attack_number = (rand() % 3) +1;
	switch(random_attack_number){
		case 1:
			//	cout << "A Red Coat General uses his sword to stab one of the Founding Fathers!" << endl;
			set_DPS(45);
			//	cout << get_DPS() << " Damage Done!" << endl;
		break;
		case 2:
			//	cout << "A Red Coat General shoots his pistol at the Founding Fathers!" << endl;
			set_DPS(30);
			//	cout << get_DPS() << " Damage Done!" << endl;
		break;
		case 3: 
			//	cout << "A Red Coat General charges the Founding Fathers on their horse!" << endl;
			set_DPS(40);
			//	cout << get_DPS() << " Damage Done!" << endl;
		break;
		default:
			//	cout << "Invalid Choice!" << endl;
		break;
	}	
}

pair<int, int> Red_Coat_General::get_location(){
	int pos1 = x;
	int pos2 = y;
	return make_pair(pos1, pos2);
}
void Red_Coat_General::run_ai(){
	srand(time(nullptr));
	int random_number = (rand() % 4) +1;
	if(random_number == 1){
		int new_x = x - 1;
		move_location(y, new_x);
	}
	if(random_number == 2){
		int new_x = x + 1;
		move_location(y, new_x);
	}
	if(random_number == 3){
		int new_y = y - 1;
		move_location(new_y, x);
	}
	if(random_number == 4){
		int new_y = y + 1;
		move_location(new_y, x);
	}
}
Three_Musketeers::Three_Musketeers(int x, int y) : Monster(x, y, 250, 7){is_called = true;}
void Three_Musketeers::attack(){
	srand(time(nullptr));
	int random_attack_number = (rand() % 3) +1;
	switch(random_attack_number){
		case 1:
			//	cout << "The first musketeer stabs one of the Founding Fathers!" << endl;
			set_DPS(30);
			//	cout << get_DPS() << " Damage Done!" << endl;
		break;
		case 2:
			//	cout << "All three musketeers attack the Founding Fathers at once!" << endl;
			set_DPS(45);
			//	cout << get_DPS() << " Damage Done!" << endl;
		break;
		case 3: 
			//	cout << "The second musketeer shoots the Founding Fathers!" << endl;
			set_DPS(40);
			//	cout << get_DPS() << " Damage Done!" << endl;
		break;
		default:
			//	cout << "Invalid Choice!" << endl;
		break;
	}	
}
pair<int, int> Three_Musketeers::get_location(){
	int pos1 = x;
	int pos2 = y;
	return make_pair(pos1, pos2);
}
void Three_Musketeers::run_ai(){
	srand(time(nullptr));
	int random_number = (rand() % 4) +1;
	if(random_number == 1){
		int new_x = x - 1;
		move_location(y, new_x);
	}
	if(random_number == 2){
		int new_x = x + 1;
		move_location(y, new_x);
	}
	if(random_number == 3){
		int new_y = y - 1;
		move_location(new_y, x);
	}
	if(random_number == 4){
		int new_y = y + 1;
		move_location(new_y, x);
	}	
}
Red_Coats::Red_Coats(int x, int y) : Monster(x, y, 200, 1){is_called = true;}
void Red_Coats::attack(){
	srand(time(nullptr));
	int random_attack_number = (rand() % 3) +1;
	switch(random_attack_number){
		case 1:
			//	cout << "A Red Coat fire their musket at Founding Fathers!" << endl;
			set_DPS(35);
			//	cout << get_DPS() << " Damage Done!" << endl;
		break;
		case 2:
			//	cout << "A Red Coat waves the British Flag bringing dreas among the Founding Fathers!" << endl;
			set_DPS(45);
			//	cout << get_DPS() << " Damage Done!" << endl;
		break;
		case 3: 
			//	cout << "A Red Coat stabs one of the Founding Fathers with their musket!" << endl;
			set_DPS(40);
			//	cout << get_DPS() << " Damage Done!" << endl;
		break;
		default:
			cout << "Invalid Choice!" << endl;
		break;
	}	
}
pair<int, int> Red_Coats::get_location(){
	int pos1 = x;
	int pos2 = y;
	return make_pair(pos1, pos2);
}
void Red_Coats::run_ai(){
	srand(time(nullptr));
	int random_number = (rand() % 4) +1;
	if(random_number == 1){
		int new_x = x - 1;
		move_location(y , new_x);
	}
	if(random_number == 2){
		int new_x = x + 1;
		move_location(y, new_x);
	}
	if(random_number == 3){
		int new_y = y - 1;
		move_location(new_y, x);
	}
	if(random_number == 4){
		int new_y = y + 1;
		move_location(new_y, x);
	}
}
