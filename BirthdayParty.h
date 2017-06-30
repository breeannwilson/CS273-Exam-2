#ifndef _BIRTHDAY_PARTY_H_
#define _BIRTHDAY_PARTY_H_

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "Party.h"
#include "BirthdayPartyTicket.h"

// FIXME 2: Create BirthdayParty and BirthdayPartyTicket to host birthday parties!
// FIXME 3: Update PartyFactory::factory() to allow it to be the ONLY method for creating a BirthdayParty
/**
* BirthdayParty is derived from Party
*/
class BirthdayParty : public Party
{
private:
	std::list<std::string> room;	//list that contains the names of people in this party

	//constructor
	BirthdayParty() {}

	friend class PartyFactory;

public:

	//add a person to this party
	PartyTicket * add(std::string name) {
		//add name to the front of room
		room.push_front(name);

		//get iterator to the front of the room (this points to the recently added party goer)
		std::list<std::string>::iterator iterator = room.begin();

		//create a new birthday party ticket with its constructor
		PartyTicket * newticket = new BirthdayPartyTicket(this, iterator);

		//return this new party ticket
		return newticket;
	}

	//list all the names of the people currently at this party
	void list() {
		for (std::list<std::string>::iterator iterator = room.begin(); iterator != room.end(); iterator++) {
			std::cout << *iterator << std::endl;
			}
	}

	//remove someone (name) from this party, identified by his/her iterator "it"
	void remove(std::list<std::string>::iterator it) {
		room.erase(it);
	}


};

#endif
