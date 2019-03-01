#include "Equipment.h"
using namespace std;

// Equipment's constructor
Equipment::Equipment()
{

}

Equipment::Equipment(string itemId, string itemName, string brand, string itemType,
	string dateOfPurchase, string condition, string status)
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

int Equipment::getTotal()
{
	return this->totalOf;
}

string Equipment::getInfo()
{
	string info = _itemId + "|" + _itemName + "|" + _brand + "|" + _itemType + "|" + _dateOfPurchase; +"|" + _condition + "|" + _status + "\n";
	return info;
}

int Equipment::totalOf = 0;

bool Equipment::setCondition(string condition)
{
	if (condition.compare("good") || condition.compare("damaged") ||
		condition.compare("being repaired") || condition.compare("disposed"))
		return false;

	this->_condition = condition;

	return true;
}

bool Equipment::setStatus(string status)
{
	if (status.compare("out") || status.compare("in"))
		return false;
		
	this->_status = status;

	return true;
}

Equipment& Equipment::operator=(const Equipment & eq)
{
	if (this == &eq)
		return *this;

	this->_itemId = eq._itemId;
	this->_itemName = eq._itemName;
	this->_brand = eq._brand;
	this->_itemType = eq._itemType;
	this->_dateOfPurchase = eq._dateOfPurchase;
	this->_condition = eq._condition;
	this->_status = eq._status;

	return *this;
}
// end of Equipment


// Tent's constructor
Tent::Tent()
{

}

Tent::Tent(string itemId, string itemName, string brand, string itemType,
	string dateOfPurchase, string condition, string status,
	string tentSize, string tentType, string numberOfDoors, string isDoubleLayer, string colour)
	: Equipment(itemId, itemName, brand, itemType,
		dateOfPurchase, condition, status)
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

string Tent::getInfo()
{
	string info = _itemId + "|" + _itemName + "|" + _brand + "|" + _itemType + "|" + _dateOfPurchase; +"|" + _condition + "|" + _status
		+ _tentSize + "|" + _tentType + "|" + _numberOfDoors + "|" + _isDoubleLayer + "\n";
	return info;
}

Tent& Tent::operator=(const Tent & t)
{
	if (this == &t)
		return *this;

	this->_itemId		= t._itemId;
	this->_itemName		= t._itemName;
	this->_brand		= t._brand;
	this->_itemType		= t._itemType;
	this->_dateOfPurchase = t._dateOfPurchase;
	this->_condition	= t._condition;
	this->_status		= t._status;

	this->_tentSize = t._tentSize;
	this->_tentType = t._tentType;
	this->_numberOfDoors = t._numberOfDoors;
	this->_isDoubleLayer = t._isDoubleLayer;
	this->_colour = t._colour;

	return *this;
}
// end of Tent


// Stove's constructor
Stove::Stove()
{

}

Stove::Stove(string itemId, string itemName, string brand, string itemType,
	string dateOfPurchase, string condition, string status,
	string stoveType, string fuelType)
	: Equipment(itemId, itemName, brand, itemType,
		dateOfPurchase, condition, status)
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

string Stove::getInfo()
{
	string info = _itemId + "|" + _itemName + "|" + _brand + "|" + _itemType + "|" + _dateOfPurchase; +"|" + _condition + "|" + _status
		+ _stoveType + "|" + _fuelType + "\n";
	return info;
}

Stove& Stove::operator=(const Stove & st)
{
	if (this == &st)
		return *this;

	this->_itemId = st._itemId;
	this->_itemName = st._itemName;
	this->_brand = st._brand;
	this->_itemType = st._itemType;
	this->_dateOfPurchase = st._dateOfPurchase;
	this->_condition = st._condition;
	this->_status = st._status;

	this->_stoveType = st._stoveType;
	this->_fuelType = st._fuelType;

	this->totalOfStove++;

	return *this;
}
// end of Stove


// Lantern's constructor
Lantern::Lantern()
{

}

Lantern::Lantern(string itemId, string itemName, string brand, string itemType, string dateOfPurchase, string condition, string status,
	string lanternSize, string lanternType, string fuelType)
	: Equipment (itemId, itemName, brand, itemType, dateOfPurchase, condition, status)
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

string Lantern::getInfo()
{
	string info = _itemId + "|" + _itemName + "|" + _brand + "|" + _itemType + "|" + _dateOfPurchase; +"|" + _condition + "|" + _status
		+ _lanternSize + "|" + _lanternType + "|" + _fuelType + "\n";
	return info;
}

Lantern& Lantern::operator=(const Lantern & lan)
{
	if (this == &lan)
		return *this;

	this->_itemId = lan._itemId;
	this->_itemName = lan._itemName;
	this->_brand = lan._brand;
	this->_itemType = lan._itemType;
	this->_dateOfPurchase = lan._dateOfPurchase;
	this->_condition = lan._condition;
	this->_status = lan._status;

	this->_lanternSize = lan._lanternSize;
	this->_lanternType = lan._lanternType;
	this->_fuelType = lan._fuelType;

	this->totalOfLantern++;

	return *this;
}
// end of Lantern
