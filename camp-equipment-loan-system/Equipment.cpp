#include "Equipment.h"

// Equipment's constructor
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

void Equipment::setCondition(string condition)
{
	this->_condition = condition;
}

void Equipment::setStatus(string status)
{
	this->_status = status;
}
// end of Equipment


// Tent's constructor
Tent::Tent(string itemId, string itemName, string brand, string itemType,
	string dateOfPurchase, string condition, string status,
	string tentSize, string tentType, string numberOfDoors, string isDoubleLayer)
	: Equipment(itemId, itemName, brand, itemType,
		dateOfPurchase, condition, status)
{
	this->_tentSize		= tentSize;
	this->_tentType		= tentType;
	this->_numberOfDoors	= numberOfDoors;
	this->_isDoubleLayer	= isDoubleLayer;
}

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
// end of Tent


// Stove's constructor
Stove::Stove(string itemId, string itemName, string brand, string itemType,
	string dateOfPurchase, string condition, string status,
	string stoveType, string fuelType)
	: Equipment(itemId, itemName, brand, itemType,
		dateOfPurchase, condition, status)
{
	this->_stoveType	= stoveType;
	this->_fuelType	= fuelType;
}

string Stove::getStoveType()
{
	return this->_stoveType;
}

string Stove::getFuelType()
{
	return this->_fuelType;
}
// end of Stove


// Lantern's constructor
Lantern::Lantern(string itemId, string itemName, string brand, string itemType,
	string dateOfPurchase, string condition, string status,
	string lanternSize, string lanternType, string fuelType)
	: Equipment(itemId, itemName, brand, itemType,
		dateOfPurchase, condition, status)
{
	this->_lanternSize = lanternSize;
	this->_lanternType = lanternType;
	this->_fuelType	= fuelType;
}

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
// end of Lantern
