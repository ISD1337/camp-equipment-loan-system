#include "Equipment.h"
#include <iostream> // delete this
using namespace std;


// Equipment's constructor
Equipment::Equipment()
{

}

Equipment::Equipment(string itemId, string itemName, string brand, string itemType,
	string dateOfPurchase, string condition, string status, bool isBorrowed)
{
	this->_itemId			= itemId;
	this->_itemName			= itemName;
	this->_brand			= brand;
	this->_itemType			= itemType;
	this->_dateOfPurchase	= dateOfPurchase;
	this->_condition		= condition;
	this->_status			= status;

	this->totalOf++;
}

Equipment::Equipment(const Equipment &eq)
{
	this->_itemId			= eq._itemId;
	this->_itemName			= eq._itemName;
	this->_brand			= eq._brand;
	this->_itemType			= eq._itemType;
	this->_dateOfPurchase	= eq._dateOfPurchase;
	this->_condition		= eq._condition;
	this->_status			= eq._status;
}

Equipment::~Equipment()
{
	cout << "Destructor of Equipment is called " << _itemId << endl;
}

string Equipment::getItemId()
{
	return this->_itemId;
}

string Equipment::getItemName()
{
	return this->_itemName;
}

string Equipment::getBrand()
{
	return this->_brand;
}

string Equipment::getItemType()
{
	return this->_itemType;
}

string Equipment::getDateOfPurchase()
{
	return this->_dateOfPurchase;
}

string Equipment::getCondition()
{
	return this->_condition;
}

string Equipment::getStatus()
{
	return this->_status;
}

string Equipment::borrowed()
{
	return this->_isBorrowed;
}

int Equipment::getTotal()
{
	return this->totalOf;
}

int Equipment::totalOf = 0;

bool Equipment::setCondition(string condition)
{
	bool flag = false;

	if (condition.compare("good") || condition.compare("damaged") ||
		condition.compare("being repaired") || condition.compare("disposed"))
		flag = true;

	this->_condition = condition;

	return flag;
}

bool Equipment::setStatus(string status)
{
	bool flag = false;

	if (status.compare("out") || status.compare("in"))
		flag = true;
		
	this->_status = status;

	return flag;
}
 
void Equipment::setBorrowed(bool isBorrowed)
{
	this->_isBorrowed = isBorrowed;
}

void Equipment::operator=(const Equipment & eq)
{
	this->_itemId = eq._itemId;
	this->_itemName = eq._itemName;
	this->_brand = eq._brand;
	this->_itemType = eq._itemType;
	this->_dateOfPurchase = eq._dateOfPurchase;
	this->_condition = eq._condition;
	this->_status = eq._status;
}
// end of Equipment


// Tent's constructor
Tent::Tent()
{

}

Tent::Tent(string itemId, string itemName, string brand, string itemType,
	string dateOfPurchase, string condition, string status, bool isBorrowed,
	string tentSize, string tentType, string numberOfDoors, string isDoubleLayer, string colour)
	: Equipment(itemId, itemName, brand, itemType,
		dateOfPurchase, condition, status, isBorrowed)
{
	this->_tentSize			= tentSize;
	this->_tentType			= tentType;
	this->_numberOfDoors	= numberOfDoors;
	this->_isDoubleLayer	= isDoubleLayer;
	this->_colour			= colour;

	this->totalOfTent++;
}

Tent::Tent(const Tent &t)
	: Equipment(t)
{
	this->_tentSize			= t._tentSize;
	this->_tentType			= t._tentType;
	this->_numberOfDoors	= t._numberOfDoors;
	this->_isDoubleLayer	= t._isDoubleLayer;
	this->_colour			= t._colour;
}

Tent::~Tent()
{
	cout << "Destructor of Tent is called " << _itemId << endl;
}

int Tent::totalOfTent = 0;

string Tent::getTentSize()
{
	return this->_tentSize;
}

string Tent::getTentType()
{
	return this->_tentType;
}

string Tent::getNumberOfDoors()
{
	return this->_numberOfDoors;
}

string Tent::getIsDoubleLayer()
{
	return this->_isDoubleLayer;
}

string Tent::getColour()
{
	return _colour;
}

int Tent::getTotal()
{
	return totalOfTent;
}

void Tent::operator=(const Tent & t)
{
	this->_tentSize = t._tentSize;
	this->_tentType = t._tentType;
	this->_numberOfDoors = t._numberOfDoors;
	this->_isDoubleLayer = t._isDoubleLayer;
}
// end of Tent


// Stove's constructor
Stove::Stove()
{

}

Stove::Stove(string itemId, string itemName, string brand, string itemType,
	string dateOfPurchase, string condition, string status, bool isBorrowed,
	string stoveType, string fuelType)
	: Equipment(itemId, itemName, brand, itemType,
		dateOfPurchase, condition, status, isBorrowed)
{
	this->_stoveType	= stoveType;
	this->_fuelType		= fuelType;
}

Stove::Stove(const Stove &st)
	: Equipment(st)
{
	this->_stoveType	= st._stoveType;
	this->_fuelType		= st._fuelType;
}

Stove::~Stove()
{
	cout << "Destructor of Stove is called " << _itemId << endl;
}

int Stove::totalOfStove = 0;

string Stove::getStoveType()
{
	return this->_stoveType;
}

string Stove::getFuelType()
{
	return this->_fuelType;
}

int Stove::getTotal()
{
	return totalOfStove;
}

void Stove::operator=(const Stove & st)
{
	this->_stoveType = st._stoveType;
	this->_fuelType = st._fuelType;

	this->totalOfStove++;
}
// end of Stove


// Lantern's constructor
Lantern::Lantern()
{

}

Lantern::Lantern(string itemId, string itemName, string brand, string itemType, string dateOfPurchase, string condition, string status, bool isBorrowed,
	string lanternSize, string lanternType, string fuelType)
	: Equipment (itemId, itemName, brand, itemType, dateOfPurchase, condition, status, isBorrowed)
{
	this->_lanternSize	= lanternSize;
	this->_lanternType	= lanternType;
	this->_fuelType		= fuelType;
}

Lantern::Lantern(const Lantern &lan)
	: Equipment(lan)
{
	this->_lanternSize	= lan._lanternSize;
	this->_lanternType	= lan._lanternType;
	this->_fuelType		= lan._fuelType;
}

Lantern::~Lantern()
{
	cout << "Destructor of Lantern is called " << _itemId << endl;
}

int Lantern::totalOfLantern = 0;

string Lantern::getLanternSize()
{
	return this->_lanternSize;
}

string Lantern::getLanternType()
{
	return this->_lanternType;
}

string Lantern::getFuelType()
{
	return this->_fuelType;
}

int Lantern::getTotal()
{
	return totalOfLantern;
}

void Lantern::operator=(const Lantern & lan)
{
	this->_lanternSize = lan._lanternSize;
	this->_lanternType = lan._lanternType;
	this->_fuelType = lan._fuelType;

	this->totalOfLantern++;
}
// end of Lantern
