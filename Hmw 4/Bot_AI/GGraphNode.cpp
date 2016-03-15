#include "GGraphNode.h"

GGraphNode::~GGraphNode()
{
}

GGraphNode::GGraphNode(const int x, const int y, const int id)
{
	this->pos = new Vect((float)	x,(float)y,0.0f);
	this->id = id;

	Texture * text = new Texture("NavMeshNode.tga");
	Image * image = new Image(text, new Rect(0, 0, 64, 64));

	this->sprite = new GraphicsObject_Sprite(Graphics_Man::getModelSprite(),
		Graphics_Man::getShaderSprite(), image,
		new Rect(pos->X(), pos->Y(), 4, 4));
	Texture * text2 = new Texture("NavMeshNode.png");

	Image * image2 = new Image(text2, new Rect(0, 0, 64, 64));
	this->spritePath = new GraphicsObject_Sprite(Graphics_Man::getModelSprite(),
		Graphics_Man::getShaderSprite(), image2,
		new Rect(pos->X(), pos->Y(), 4, 4));

	Matrix world;
	Matrix RotZ;
	Matrix Scale;
	Matrix Trans;

	Scale.set(SCALE, 1.0f, 1.0f, 1.0f);
	RotZ.set(ROT_Z, 0.0f);
	Trans.set(TRANS, sprite->origPosX, sprite->origPosY, 0.0f);

	world = Scale * RotZ * Trans;
	sprite->SetWorld(world);
	spritePath->SetWorld(world);
}

Vect * GGraphNode::getPos()
{
	return pos;
}


int GGraphNode::getId() {
	return this->id;
}
void GGraphNode::render(Camera * pCam)
{
	sprite->Render(pCam);
}
