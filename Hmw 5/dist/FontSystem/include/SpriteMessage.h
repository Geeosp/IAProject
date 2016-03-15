#ifndef SPRITEMESSAGE_H
#define SPRITEMESSAGE_H

#include "AzulCore.h"
#include "Font.h"
#include <vector>
#include <string>

class SpriteMessage
{

private:

	SpriteMessage(){};

	void addSprite(GraphicsObject_Sprite * _sprite);
	void createSprites(const std::string& msg);

	std::vector<GraphicsObject_Sprite*> message;

	Font * font;

	int msgLen;

public:
	SpriteMessage(Font * _font, const std::string& msg);

	~SpriteMessage()
	{
		clear();
	};

	void Update(const std::string& msg);

	void Render(Camera * camera, Rect * _destRect);

	void clear();



};




#endif