#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H

#include "Item.h"
#include "Vect.h"
#include "Texture.h"
#include "Image.h"


class ItemFactory
{
private:
	ItemFactory();
	~ItemFactory();

	static ItemFactory * Instance();

	Texture * healthText;
	Image * healthImage;

	Texture * laserAmmoText;
	Image * laserAmmoImage;

	Texture * rifleAmmoText;
	Image * rifleAmmoImage;

	Item * healthItem(Vect &pos);
	Item * laserItem(Vect &pos);
	Item * rifleItem(Vect &pos);


public:

	static Item * CreateItem(ITEM_TYPE _type, Vect& _pos);




};




#endif