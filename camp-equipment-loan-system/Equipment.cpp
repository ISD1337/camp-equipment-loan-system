#include "Equipment.h"


Equipment::Equipment(string _itemID, string _itemName, string _brand, string _itemType,
	string _dataOfPurchase, string _condition, string _status)
{
	itemID			= _itemID;
	itemName		= _itemName;
	brand			= _brand;
	itemType		= _itemType;
	dataOfPurchase	= _dataOfPurchase;
	condition		= _condition;
	status			= _status;
}
