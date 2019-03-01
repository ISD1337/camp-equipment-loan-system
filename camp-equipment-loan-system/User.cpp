#include "User.h"
using namespace std;

// User's constructor
User::User(string userId, string username, string section,
	string dob, string address)
{
	this->_userId	= userId;
	this->_username	= username;
	this->_section	= section;
	this->_dob		= dob;
	this->_address	= address;
}

string User::getUserId()
{
	return this->_userId;
}

string User::getUsername()
{
	return this->_username;
}

string User::getSection()
{
	return this->_section;
}

string User::getPassword()
{
	return this->_dob;
}

string User::getAddress()
{
	return this->_address;
}

int User::getMaxItem()
{
	return MAX_ITEMS;
}

int User::getNumberOfItemAllowed()
{
	return items;
}

void User::returnItem()
{
	int n = this->items;
	if (n < this->MAX_ITEMS)
		this->items++;
}

void User::borrowItem()
{
	int n = this->items;
	if (n > 0)
		this->items--;
}
// end of User


// RoverScout's constructor
RoverScout::RoverScout(string userId, string username, string section,
	string dob, string address)
	: User(userId, username, section, dob, address)
{
	this->MAX_ITEMS = 5;
	this->items = this->MAX_ITEMS;
}
// end of RoverScout


// VentureScout's constructor
VentureScout::VentureScout(string userId, string username, string section,
	string dob, string address)
	: User(userId, username, section, dob, address)
{
	this->MAX_ITEMS = 3;
	this->items = this->MAX_ITEMS;
}
// end of VentureScout


// Scout's constructor
Scout::Scout(string userId, string username, string section,
	string dob, string address, string rank)
	: User(userId, username, section, dob, address) 
{
	this->_rank		= rank;
	this->MAX_ITEMS	= findMaxItems(rank);
	this->items		= this->MAX_ITEMS;
}

int Scout::findMaxItems(string rank)
{
	int max;
	if (rank.compare("Patrol Leader"))
		max = 3;
	else if (rank.compare("Assistant Patrol Leader"))
		max = 3;
	else if (rank.compare("Member"))
		max = 1;

	return max;
}

string Scout::getRank()
{
	return this->_rank;
}
// end of Scout


int Scouter::findMaxItems()
{
	int max = 5;
	return max;
}
// end of Scouter

