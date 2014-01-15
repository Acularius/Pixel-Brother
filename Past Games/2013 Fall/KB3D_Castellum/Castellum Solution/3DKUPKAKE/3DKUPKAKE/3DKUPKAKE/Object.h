#include <curses.h>
#include <Windows.h>

#ifndef OBJECT
#define OBJECT

class Object
{ 
private:
    int spriteIndex;
	int objIndex;
    int imageIndex;
    int hspeed;
    int vspeed;
	int direction; 
	//	for direction   1
	//				  3   2
	//					0
	int position[2];//x y coordinates
public:
	WINDOW *objectWindow;
	int animations[4];
	
	void SetSpriteIndex(int s){ spriteIndex = s; }
	void SetImageIndex(int i){ imageIndex = i; }
	void SetDirection(int d){ direction = d; }
	void SetObjIndex(int o){ objIndex = o; }
	void SetHSpeed(int h){ hspeed = h; }
	void SetVSpeed(int v){ vspeed = v; }
	void SetX(int x){ position[1] = x; }
	void SetY(int y){ position[0] = y; }

	int GetSpriteIndex(){ return spriteIndex; }
	int GetImageIndex(){ return imageIndex; }
	int GetDirection(){ return direction; }
	int GetObjIndex(){ return objIndex; }
	int GetVSpeed(){ return vspeed; }
	int GetHSpeed(){ return hspeed; }
	int GetX(){ return position[1]; }
	int GetY(){ return position[0]; }

	//Functions for the Object Class
	void SetSprite(int spr, int img, int ani[4], WINDOW *local_win);
	void SetSpeed(int v, int h);
	void SetDirection(int dir, int y, int x);
	int DrawSprite(Object local_object, int animationIndex);
	int DrawLayerSprite(Object local_object, int animationIndex);
};

	int distance(int x1, int y1, int x2, int y2);
	Object boulderXY(int x, int y);
	Object boulderXYS(int x, int y, int v, int h);

	Object DefineObject(int spr, int img, int ani[4], WINDOW *local_win, int v, int h, int y, int x, int dir, int object);

#endif