#ifndef STATE_HPP
#define STATE_HPP

#include <iostream>
//#include <vector>
//#include <set>

class State{
/*protected: 
	static set::set<std::string*> natures = {"magic", "creature"}; 
	static set::set<std::string*> statuses = {"dead", "alive"};
	static set::set<std::string*> roles = {"deamon", "vampire", "soldier",
											"berserk", "werevolf", "wizard",
										"healer", "priest", "warlock", "necromancer"};*/
public:
	std::string* nature;
	std::string* status;
	std::string* role;

	State();
	State(std::string&, std::string&, std::string&);
	~State();

	const std::string& getNature() const;
	const std::string& getStatus() const;
	const std::string& getRole() const;

};

std::ostream& operator<<(std::ostream& out, State& state);
/*

"Soldier","Rogue","Berserker [Берсерк] : на берсеркера не действует магия
- Vampire [Вампир] : при атаке / контратаке потребляет часть жизненных сил противника
- Werewolf [Оборотень] : умеет превращаться в волка (в состоянии волка имеет более высокий показатель жизненных сил и атаки, но получает больший урон от магии)

Юниты, способные к магии:
- Wizard [Волшебник] : атакует боевыми заклинаниями (лечебные заклинания имеют только половину силы)
- Healer [Целитель] : владеет целебными заклинаниями (боевые заклинания имеют только половину силы)
- Priest [Священник] : владеет целебными заклинаниями (боевые заклинания имеют только половину силы), наносит x2 урон нежити (Vampire, Necromancer)
- Warlock [Чернокнижник] : призывает демонов (класс Demon немного расширяет класс Soldier)
- Necromancer [Некромант] следит за всеми кого атаковал, в случае смерти атакованого юнита, получает часть его жизненных сил
*/


#endif // STATE_HPP