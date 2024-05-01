//Tanner Dunn - Inheritor of Suffering
#include "heroes_and_monsters.h"
Monster::Monster(int x, int y, int base_health) : Actor(x, y), HP(base_health){};
void Monster::set_DPS(int DPS){attack_damage = DPS;}
int Monster::get_DPS()const{return attack_damage;}
void Monster::set_HP(int new_HP){
	if(new_HP < 1){
		cout << "YOU DIED" << endl;
		HP = 0;
	}
	else{
		HP = new_HP;
	}
}
int Monster::get_HP()const{return HP;}
//pure virtual void attack() = 0; already defined
//pure virtual void run_ai() = 0; already defined
King_George_III::King_George_III(int x, int y) : Monster(x, y, 450){is_called = true;}
void King_George_III::attack(){
	srand(time(nullptr));
	int random_attack_number = (rand() % 3) +1;
	switch(random_attack_number){
		case 1:
			cout << "The King of Great Britian raises your taxes!" << endl;
			set_DPS(50);
			cout << get_DPS() << " Damage Done!" << endl;
		break;
		case 2:
			cout << "King George throws his crown at the Founding Fathers!" << endl;
			set_DPS(45);
			cout << get_DPS() << " Damage Done!" << endl;
		break;
		case 3: 
			cout << "King George begins to loose his grip on America and causes an earthquake from the madness!" << endl;
			set_DPS(40);
			cout << get_DPS() << " Damage Done!" << endl;
		break;
		default:
			cout << "Invalid Choice!" << endl;
		break;
	}	
}
void King_George_III::move_location(int new_x, int new_y) { 
	x = new_x;
	y = new_y;
}
pair<int, int> King_George_III::get_location(){
	int pos1 = x;
	int pos2 = y;
	return make_pair(pos1, pos2);
}
void King_George_III::run_ai(){
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
Henry_Clinton::Henry_Clinton(int x, int y) : Monster(x, y, 300){is_called = true;}
void Henry_Clinton::attack(){
	srand(time(nullptr));
	int random_attack_number = (rand() % 3) +1;
	switch(random_attack_number){
		case 1:
			cout << "Henry commands his troops to attack the Founding Fathers!" << endl;
			set_DPS(40);
			cout << get_DPS() << " Damage Done!" << endl;
		break;
		case 2:
			cout << "Henry reminds the Founding Fathers of their loss at Bunker Hill!" << endl;
			set_DPS(30);
			cout << get_DPS() << " Damage Done!" << endl;
		break;
		case 3: 
			cout << "Henry fires a shot from his musket hitting the Founding fathers dead on!" << endl;
			set_DPS(45);
			cout << get_DPS() << " Damage Done!" << endl;
		break;
		default:
			cout << "Invalid Choice!" << endl;
		break;
	}	
}
void Henry_Clinton::move_location(int new_x, int new_y) { 
	x = new_x;
	y = new_y;
}
pair<int, int> Henry_Clinton::get_location(){
	int pos1 = x;
	int pos2 = y;
	return make_pair(pos1, pos2);
}
void Henry_Clinton::run_ai(){
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
Cannon::Cannon(int x, int y) : Monster(x, y, 200){is_called = true;}
void Cannon::attack(){
	srand(time(nullptr));
	int random_attack_number = (rand() % 3) +1;
	switch(random_attack_number){
		case 1:
			cout << "A cannon ball is fired in the direction of the Founding Fathers!" << endl;
			set_DPS(40);
			cout << get_DPS() << " Damage Done!" << endl;
		break;
		case 2:
			cout << "The sound from the cannon firing deafens the Founding Fathers!" << endl;
			set_DPS(35);
			cout << get_DPS() << " Damage Done!" << endl;
		break;
		case 3: 
			cout << "The smoke from the cannon ball chokes the Founding Fathers!" << endl;
			set_DPS(30);
			cout << get_DPS() << " Damage Done!" << endl;
		break;
		default:
			cout << "Invalid Choice!" << endl;
		break;
	}	
}
void Cannon::move_location(int new_x, int new_y) { 
	x = new_x;
	y = new_y;
}
pair<int, int> Cannon::get_location(){
	int pos1 = x;
	int pos2 = y;
	return make_pair(pos1, pos2);
}
void Cannon::run_ai(){
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
Red_Coat_General::Red_Coat_General(int x, int y) : Monster(x, y, 275){is_called = true;}
void Red_Coat_General::attack(){
	srand(time(nullptr));
	int random_attack_number = (rand() % 3) +1;
	switch(random_attack_number){
		case 1:
			cout << "A Red Coat General uses his sword to stab one of the Founding Fathers!" << endl;
			set_DPS(45);
			cout << get_DPS() << " Damage Done!" << endl;
		break;
		case 2:
			cout << "A Red Coat General shoots his pistol at the Founding Fathers!" << endl;
			set_DPS(30);
			cout << get_DPS() << " Damage Done!" << endl;
		break;
		case 3: 
			cout << "A Red Coat General charges the Founding Fathers on their horse!" << endl;
			set_DPS(40);
			cout << get_DPS() << " Damage Done!" << endl;
		break;
		default:
			cout << "Invalid Choice!" << endl;
		break;
	}	
}
void Red_Coat_General::move_location(int new_x, int new_y) { 
	x = new_x;
	y = new_y;
}
pair<int, int> Red_Coat_General::get_location(){
	int pos1 = x;
	int pos2 = y;
	return make_pair(pos1, pos2);
}
void Red_Coat_General::run_ai(){
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
Red_Coat_Commander::Red_Coat_Commander(int x, int y) : Monster(x, y, 250){is_called = true;}
void Red_Coat_Commander::attack(){
	srand(time(nullptr));
	int random_attack_number = (rand() % 3) +1;
	switch(random_attack_number){
		case 1:
			cout << "A Red Coat Commander rallies the troops inflicting fear in the Founding Fathers" << endl;
			set_DPS(30);
			cout << get_DPS() << " Damage Done!" << endl;
		break;
		case 2:
			cout << "A Red Coat Commander instructs the troops where to attack!" << endl;
			set_DPS(45);
			cout << get_DPS() << " Damage Done!" << endl;
		break;
		case 3: 
			cout << "A Red Coat Commander fires their musket at the Founding Fathers!" << endl;
			set_DPS(40);
			cout << get_DPS() << " Damage Done!" << endl;
		break;
		default:
			cout << "Invalid Choice!" << endl;
		break;
	}	
}
void Red_Coat_Commander::move_location(int new_x, int new_y) { 
	x = new_x;
	y = new_y;
}
pair<int, int> Red_Coat_Commander::get_location(){
	int pos1 = x;
	int pos2 = y;
	return make_pair(pos1, pos2);
}
void Red_Coat_Commander::run_ai(){
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
Red_Coats::Red_Coats(int x, int y) : Monster(x, y, 200){is_called = true;}
void Red_Coats::attack(){
	srand(time(nullptr));
	int random_attack_number = (rand() % 3) +1;
	switch(random_attack_number){
		case 1:
			cout << "A Red Coat fire their musket at Founding Fathers!" << endl;
			set_DPS(35);
			cout << get_DPS() << " Damage Done!" << endl;
		break;
		case 2:
			cout << "A Red Coat waves the British Flag bringing dreas among the Founding Fathers!" << endl;
			set_DPS(45);
			cout << get_DPS() << " Damage Done!" << endl;
		break;
		case 3: 
			cout << "A Red Coat stabs one of the Founding Fathers with their musket!" << endl;
			set_DPS(40);
			cout << get_DPS() << " Damage Done!" << endl;
		break;
		default:
			cout << "Invalid Choice!" << endl;
		break;
	}	
}
void Red_Coats::move_location(int new_x, int new_y) { 
	x = new_x;
	y = new_y;
}
pair<int, int> Red_Coats::get_location(){
	int pos1 = x;
	int pos2 = y;
	return make_pair(pos1, pos2);
}
void Red_Coats::run_ai(){
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
