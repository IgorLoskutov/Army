#include<iostream>
#include"SpellBook.hpp"
#include<map>

std::map<int, Spell> spellbook = {	
	{1,	{"fireball", 		"wizard", 	-10, 5}},
	{2,	{"iceball", 		"wizard", 	-15, 7}},
	{3,	{"firestorm",		"wizard", 	-35, 20}},
	{4,	{"remedy"	, 		"healer", 	15,	 7}},
	{5,	{"magicpill", 		"healer", 	25,  12}},
	{6,	{"summon Deamon",	"warlock", 	0,  30}},
	
};



