#include "GGraphEdge.h"


GGraphEdge::GGraphEdge(GGraphNode* from, GGraphNode* to)
{
	this->from = from;
	this->to = to;
	


	Texture * text = new Texture("NavMeshNode.tga");
	Image * image = new Image(text, new Rect(0, 0, 64, 64));
	Vect vf = *from->getPos();
	Vect vt = *to->getPos();
	float size = 15;
	this->sprite = new GraphicsObject_Sprite(Graphics_Man::getModelSprite(),
		Graphics_Man::getShaderSprite(), image,
		new Rect(vf.X(), vf.Y(), size, 1));

		
	Matrix world;
	Matrix RotZ;
	Matrix Scale;
	Matrix Trans;
	
	Vect v = *to->getPos();
	v -= *from->getPos();
	float angle;
	 angle = v.getAngle(Vect(1,0,0));
	//angle = 0.0f;
	Scale.set(SCALE, 1.0f, 1.0f, 1.0f);
	RotZ.set(ROT_Z, angle);
	
	if (vt.X() - vf.X() == 0)//vertical
	{
		if (vt.Y() - vf.Y() > 0){
			Trans.set(TRANS, sprite->origPosX, sprite->origPosY + size/2, 0.0f);
		}
		else{
			Trans.set(TRANS, sprite->origPosX , sprite->origPosY - size/2, 0.0f);

		}
	
	}
	else if (vt.Y()-vf.Y()==0){//horizontal
		if (vt.X() - vf.X() > 0){
			Trans.set(TRANS, sprite->origPosX+size/2, sprite->origPosY, 0.0f);
		}
		else{
			Trans.set(TRANS, sprite->origPosX -size/2, sprite->origPosY, 0.0f);

		}

	}
	else{
		//diagonal
		float dx = size / 2;
		float dy = size / 2;
		if (vt.X() - vf.X() < 0) dx *= -1;
		if (vt.Y() - vf.Y() < 0) dy *= -1;
		
		Trans.set(TRANS, sprite->origPosX +dx, sprite->origPosY+dy, 0.0f);
	}
	
	world = Scale * RotZ * Trans;
	sprite->SetWorld(world);





}

float GGraphEdge::getWeight()
{
	return  (*to->getPos() - *from->getPos()).magSqr();
}
GGraphEdge::~GGraphEdge()
{
}
void GGraphEdge::render(Camera * pCam)
{
	sprite->Render(pCam);
}
