#ifndef WALLFACTORY_H
#define WALLFACTORY_H

#include "Wall.h"
#include "Texture.h"
#include "Image.h"


class WallFactory
{
private:
	WallFactory();
	~WallFactory();

	static WallFactory * Instance();

	Texture * textImage;
	Image * wallImage;
	

public:

	static Wall * CreateWall(const float _x, const float _y, const float _w, const float _h, const float _angle);

};




#endif