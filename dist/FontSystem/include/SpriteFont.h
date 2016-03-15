#ifndef SPRITEFONT_H
#define SPRITEFONT_H

#include "AzulCore.h"
#include "SpriteMessage.h"


class SpriteFont
{
public:
	
	SpriteFont(const std::string& message, float x, float y, float scaleX, float scaleY);
	~SpriteFont();

	void Update(const std::string& message, float x, float y, float scaleX, float scaleY);

	void Render(Camera * camera);

private:
	SpriteMessage * msg;
	Font * font;
	Rect * destRect;

};



#endif