#include <iostream>
#include <set>
#include <iomanip>
#include "Magic/SpellCaster.hpp"
#include "Soldier/Soldier.hpp"
#include "Berserker/Berserker.hpp"
#include "Rogue/Rogue.hpp"
#include "Wizard/Wizard.hpp"
#include "Healer/Healer.hpp"
#include "Priest/Priest.hpp"
#include "Werewolf/Werewolf.hpp"
#include "Vampire/Vampire.hpp"
#include "Necromancer/Necromancer.hpp"
#include "Warlock/Warlock.hpp"
#include "Location.hpp"

# define SIZE 8

void showBattlefield (Location* battlefield[SIZE][SIZE]);
Location* battlefield[SIZE][SIZE];
std::string battlefieldMessege;

int main() {

	
	
	
	for ( int i = 0; i < SIZE; i++ ) {
		for ( int j = 0; j < SIZE; j++ ){
			battlefield[i][j] = new Location(i, j);
		}
	}

	Soldier* rian = new Soldier("rian", battlefield[0][0]);

	Soldier* sharp = new Soldier("sharp", battlefield[0][2]);
	
	Wizard* merlin = new Wizard("merlin", battlefield[4][3]);

	Healer* paracels =  new Healer("paracels", battlefield[3][4]);

	Priest* martin =  new Priest("martin", battlefield[2][2]);

	Werewolf* licantrop = new Werewolf("licantrop", battlefield[2][0]); // не кусать в состоянии человека

	Berserker* ingvar = new Berserker("ingvar", battlefield[7][7]);

	Vampire* vlad  = new Vampire("vlad", battlefield[7][4]);

	Necromancer* mistdweller = new Necromancer("mistdweller", battlefield[4][7]);

	Warlock* lillith = new Warlock("lillith", battlefield[0][7]);
	



	bool exitMarker = 0;
	Unit* unit_1;
	Unit* unit_2;
	Location* target;
	std::string userInput;
	battlefieldMessege = "make your move\n";
	

	std::vector<std::string> command;

	while( !exitMarker ) {
		unit_1 = NULL;
		unit_2 = NULL;
		target = NULL;
		command.clear();
		userInput.clear();

		showBattlefield(battlefield);
		std::cout<< " units can attack, move (x,y), readSpell, transform, byte and hex       ..or you can exit any time \n\n"<<std::endl;
		
	
		
		std::getline(std::cin, userInput);
		if (!std::cin){
            std::cin.clear();
            std::cin.get();
        }
        

		for ( int i = 0; i <10; i++ ) {
			std::cout<<'\n'<<std::endl;
		}
		
		
		for (int to = 0; to != std::string::npos; ) {
			to = userInput.find(' ');
			if (to == std::string::npos) {
				command.push_back(userInput);
			} else {
				command.push_back(userInput.substr(0, to));
				userInput = userInput.substr(to+1);
			}
			
		}
		if ( command[0] == "exit" ) {
			exitMarker = 1;
			continue;
		}

		if ( command.size() > 0 ) {
			for ( Unit* unit : Unit::unitList ) {
				if ( unit->getName() == command[0] ) {
					unit_1 = unit;
				}
			}	
			if ( unit_1 == NULL ) {
				battlefieldMessege = "no unit named '" + command[0] + "' on battlefield\n";
				continue;
			}
		}

		if ( command.size() > 2 ) {
			for ( Unit* unit : Unit::unitList ) {
				if ( unit->getName() == command[2] ) {
					unit_2 = unit;
				}
			}
			if (command[2].at(0) == '(') {
				target = battlefield[(int)command[2].at(1) - '0'][(int)command[2].at(3) - '0'];
			}
			if ( unit_2 == NULL && target == NULL) {
				battlefieldMessege = "no unit named '" + command[2] + "' on battlefield\n";
				continue;
			}
		}

		if ( command[1] == "attack" || command[1] == "hit") {
			unit_1->attack(unit_2);
		}  else if (command[1] == "readSpell") {
			((SpellCaster*)(unit_1))->readSpell();
		} else if (command[1] == "hexMagic" || command[1] == "hex") {
			((SpellCaster*)(unit_1))->hexMagic(unit_2);
		} else if (command[1] == "move") {
			unit_1->changeLocation(target);
		} else if (command[1] == "transform") {
			unit_1->ability->transform(unit_1);
		}  else if (command[1] == "byte") {
			unit_1->ability->byte(unit_1, unit_2);
		} else {
			battlefieldMessege = "no such action possible";
		}

		std::cout<< battlefieldMessege <<'\n'<<std::endl;
		battlefieldMessege = "";
		
	}


	return 0;
}

void showBattlefield (Location* battlefield[SIZE][SIZE]){
	int sellWidth = 15;
	std::string emptyLine("               |");
	
	std::cout<<'\n'<< "   | ";
	for ( int i = 0; i < SIZE; i++ ) {
		std::cout<<std::left<<"       "<<i<<"       |";
	}
	std::cout<<'\n'<< "   | ";
	for ( int j = 0; j < SIZE; j++ ){
			std::cout.width(sellWidth);
			std::cout<< std::left<< "_______________|";
		}
	std::cout<<'\n';
	for ( int i = 0; i < SIZE; i++ ) {
		std::cout<< "   | ";
		for ( int j = 0; j < SIZE; j++ ){
			std::cout.width(sellWidth);
			std::cout<<std::setw(sellWidth) <<std::left<<emptyLine;
		}
		std::cout<<'\n'<< "   | ";
		for ( int j = 0; j < SIZE; j++ ){
			std::cout.width(sellWidth);
			if ( battlefield[i][j]->getUnit() != NULL ) {


				std::cout<< std::left<< battlefield[i][j]->getUnit()->getName()<< std::right<<"|";
			} else {
				std::cout<< std::left<<emptyLine;
			}
		}
		std::cout<<'\n'<< " "<< i <<" | ";
		for ( int j = 0; j < SIZE; j++ ){
			std::cout.width(sellWidth);
			if ( battlefield[i][j]->getUnit() != NULL ) {
				std::string unitReport = battlefield[i][j]->getUnit()->state.getRole();
				std::cout<< std::right<< unitReport << std::right<<"|";
			} else {
				std::cout<< std::left<< emptyLine;
			}
		}
		std::cout<<'\n'<< "   | ";
		for ( int j = 0; j < SIZE; j++ ){
			std::cout.width(sellWidth);
			if ( battlefield[i][j]->getUnit() != NULL ) {
				std::string unitReport = "hp:"+ std::to_string(battlefield[i][j]->getUnit()->getHp()) + "/" + std::to_string(battlefield[i][j]->getUnit()->getMaxHp());
				std::cout<< std::right<< unitReport << std::right<<"|";
			} else {
				std::cout<< std::left<<emptyLine;
			}
		}
		std::cout<<'\n'<< "   | ";
		for ( int j = 0; j < SIZE; j++ ){
			std::cout.width(sellWidth);
			std::cout<< std::left<< emptyLine;
		}
		std::cout<<'\n'<< "   | ";
		for ( int j = 0; j < SIZE; j++ ){
			std::cout.width(sellWidth);
			std::cout<< std::left<< "_______________|";
		}
		
		std::cout<<std::endl;
	}
}