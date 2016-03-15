#ifndef GAMEOBJMAN_H
#define GAMEOBJMAN_H

#include "AzulCore.h"

class GameObj;

class Graphics_Man
{

public:

	static Model * getModelSprite();
	static ShaderObject * getShaderSprite();
	static ShaderObject * getShaderSpriteBox();

private:
	static Graphics_Man * privInstance();
	Graphics_Man();
	~Graphics_Man();



	Model * pModelSprite;
	ShaderObject * pShaderObj_sprite;
	ShaderObject * pShaderObj_spriteLine;


};



#endif