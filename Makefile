CC=g++
CFLAGS= -std=c++11

all:
	$(CC) $(CFLAGS) g++ -std=c++11 main.cpp Unit.cpp State.cpp BaseAttack.cpp Soldier/Soldier.cpp Ability.cpp MagicAmenability.cpp Location.cpp Magic/Magic.cpp Magic/SpellCaster.cpp Magic/SpellBook.cpp Berserker/Berserker.cpp Berserker/BerserkerMagicAmenability.cpp Healer/Healer.cpp Wizard/Wizard.cpp Priest/Priest.cpp Priest/PriestAttack.cpp Werewolf/Werewolf.cpp Werewolf/WerewolfAbility.cpp Werewolf/WerewolfMagicAmenability.cpp Vampire/Vampire.cpp Vampire/VampireAttack.cpp Vampire/VampireAbility.cpp Necromancer/Necromancer.cpp Warlock/Warlock.cpp Deamon/Deamon.cpp Deamon/DeamonMagicAmenability.cpp -o battle
