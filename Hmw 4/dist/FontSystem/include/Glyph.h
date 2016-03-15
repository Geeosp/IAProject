#ifndef GLYPH_H
#define GLYPH_H

#include <stdlib.h> 

class Glyph 
{

public:

	Glyph();

	Glyph(char * _key, char * _x, char * _y, char * _width, char * _height);

	~Glyph();


	int key;
	int x;
	int y;
	int width;
	int height;


};

#endif