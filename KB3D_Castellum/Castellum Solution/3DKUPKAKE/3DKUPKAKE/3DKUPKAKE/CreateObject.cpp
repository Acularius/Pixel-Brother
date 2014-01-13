//Includes
#include "Object.h"
#include "DrawWindows.h"
#include "GlobalVars.h"
#include "Interactions.h"

//Prototypes
void SetAnimations(int a, int b, int c, int d);
void DefineObjects(int object, int y, int x);

//Variables
const int SPRITE_HEIGHT = 6;
const int SPRITE_WIDTH = 9;
int ani[4];

void SetAnimations( int a, int b, int c, int d)
{
	ani[0] = a;
	ani[1] = b;
	ani[2] = c;
	ani[3] = d;
}

void DefineObjects(int object, int y, int x)
{
	int index = (y*22)+x;
	SetAnimations(0,1,2,1);

	currentLevel.puzzleObject[index] = DefineObject(200,-2,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,0,0,0,0);
	currentLevel.puzzleObject[index].DrawSprite(currentLevel.puzzleObject[index],0);

	switch (object)
	{
	 case -16:
		SetAnimations(0,0,1,1);
		currentLevel.roomObject[index] = DefineObject(83,1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case -15:	//Ice
		currentLevel.roomObject[index] = DefineObject(105,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case -14:	//Cobblestone 4
		currentLevel.roomObject[index] = DefineObject(180,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case -13:	//Cobblestone 3
		currentLevel.roomObject[index] = DefineObject(179,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case -12:	//Cobblestone 2
		currentLevel.roomObject[index] = DefineObject(178,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case -11:	//Cobblestone 1
		currentLevel.roomObject[index] = DefineObject(177,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case -10:	//Bridge Left
		currentLevel.roomObject[index] = DefineObject(86,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case -9:	//Bridge Right
		currentLevel.roomObject[index] = DefineObject(87,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case -8:	//Bridge Middle
		currentLevel.roomObject[index] = DefineObject(88,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case -7:	//Bridge Horizontal Top
		currentLevel.roomObject[index] = DefineObject(89,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case -6:	//Bridge Horizontal Middle
		currentLevel.roomObject[index] = DefineObject(205,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case -5:	//Bridge Horizontal Bottom
		currentLevel.roomObject[index] = DefineObject(90,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case -4:	//Ladder Right
		currentLevel.roomObject[index] = DefineObject(197,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case -3:	//Ladder Left
		currentLevel.roomObject[index] = DefineObject(198,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case -2:	//Ladder Vertical
		currentLevel.roomObject[index] = DefineObject(153,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case -1:	//Blank Space
		currentLevel.roomObject[index] = DefineObject(200,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 0:		//Blank Space
		currentLevel.roomObject[index] = DefineObject(200,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 1:		//Chest Unlocked
		currentLevel.roomObject[index] = DefineObject(25,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 2:		//Chest Locked
		currentLevel.roomObject[index] = DefineObject(26,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 3:		//Chest Opened
		currentLevel.roomObject[index] = DefineObject(27,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 4:		//Horizontal Table Left
		currentLevel.roomObject[index] = DefineObject(28,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 5:		//Horizontal Table Middle
		currentLevel.roomObject[index] = DefineObject(29,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 6:		//Horizontal Table Right
		currentLevel.roomObject[index] = DefineObject(30,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 7:		//Vertical Table Top
		currentLevel.roomObject[index] = DefineObject(31,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 8:		//Vertical Table Middle
		currentLevel.roomObject[index] = DefineObject(32,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 9:		//Vertical Table Bottom
		currentLevel.roomObject[index] = DefineObject(33,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 10:	//Empty Chair
		currentLevel.roomObject[index] = DefineObject(34,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 11:	//Woman Seated Facing Left
		currentLevel.roomObject[index] = DefineObject(35,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 12:	//Woman Seated Facing Right
		currentLevel.roomObject[index] = DefineObject(36,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 13:	//Man Seated Facing Up
		currentLevel.roomObject[index] = DefineObject(37,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 14:	//Man Seated Facing Left
		currentLevel.roomObject[index] = DefineObject(38,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 15:	//Man Seated Facing Right
		currentLevel.roomObject[index] = DefineObject(39,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 16:	//Vertical Table on a Brick Wall
		currentLevel.roomObject[index] = DefineObject(40,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 17:	//Brick Wall
		currentLevel.roomObject[index] = DefineObject(41,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 18:	//Window on a Brick Wall
		currentLevel.roomObject[index] = DefineObject(42,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 19:	//Door Closed 
		currentLevel.roomObject[index] = DefineObject(43,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 20:	//Door Open
		currentLevel.roomObject[index] = DefineObject(44,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 21:	//Cave Door
		currentLevel.roomObject[index] = DefineObject(45,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 22:	//Fence Going Left
		currentLevel.roomObject[index] = DefineObject(46,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 23:	//Fence Going Up
		currentLevel.roomObject[index] = DefineObject(47,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 24:	//Fence Going Right
		currentLevel.roomObject[index] = DefineObject(48,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 25:	//Top of a Shaded Wall
		currentLevel.roomObject[index] = DefineObject(50,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 26:	//Brick Wall Right
		currentLevel.roomObject[index] = DefineObject(65,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 27:	//Brick Wall Left
		currentLevel.roomObject[index] = DefineObject(68,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 28:	//Brick Wall Bottom
		currentLevel.roomObject[index] = DefineObject(73,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 29:	//Brick top left inside corner
		currentLevel.roomObject[index] = DefineObject(67,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 30:	//Brick top right inside corner
		currentLevel.roomObject[index] = DefineObject(64,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 31:	//Brick bottom left inside corner
		currentLevel.roomObject[index] = DefineObject(69,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 32:	//Brick bottom right inside corner
		currentLevel.roomObject[index] = DefineObject(66,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 33:	//Brick top left outside corner
		currentLevel.roomObject[index] = DefineObject(74,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 34:	//Brick top right outside corner
		currentLevel.roomObject[index] = DefineObject(75,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 35:	//Brick bottom left outside corner
		currentLevel.roomObject[index] = DefineObject(76,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 36:	//Brick bottom right outside corner
		currentLevel.roomObject[index] = DefineObject(77,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 37:	//Brick Wall Door Facing Right
		currentLevel.roomObject[index] = DefineObject(70,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 38:	//Brick Wall Door Facing Left
		currentLevel.roomObject[index] = DefineObject(71,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 39:	//Brick Wall Door Facing Up
		currentLevel.roomObject[index] = DefineObject(72,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 40:	//Sign
		currentLevel.roomObject[index] = DefineObject(78,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 41:	//Bed Top
		currentLevel.roomObject[index] = DefineObject(79,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 42:	//Bed Bottom
		currentLevel.roomObject[index] = DefineObject(80,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 43:	//Tree
		currentLevel.roomObject[index] = DefineObject(91,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 44:	//Bush
		currentLevel.roomObject[index] = DefineObject(92,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 45:	//Pushing Block
		currentLevel.roomObject[index] = DefineObject(93,-2,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,0);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		currentLevel.puzzleObject[index] = DefineObject(93,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.puzzleObject[index].DrawSprite(currentLevel.puzzleObject[index],0);
		break;
    case 46:	//Church middle top
		currentLevel.roomObject[index] = DefineObject(109,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 47:	//Church middle empty
		currentLevel.roomObject[index] = DefineObject(110,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 48:	//Church middle cross
		currentLevel.roomObject[index] = DefineObject(111,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 49:	//Church middle door
		currentLevel.roomObject[index] = DefineObject(112,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 50:	//Church left top
		currentLevel.roomObject[index] = DefineObject(113,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 51:	//Church left middle
		currentLevel.roomObject[index] = DefineObject(114,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 52:	//Church right top
		currentLevel.roomObject[index] = DefineObject(115,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 53:	//Church right middle
		currentLevel.roomObject[index] = DefineObject(116,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 54:	//Church side bottom
		currentLevel.roomObject[index] = DefineObject(117,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 55: //Water Pattern 1
		SetAnimations(0,0,1,1);
		currentLevel.roomObject[index] = DefineObject(81,1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	/*case 56:	//Water Corner Top Left
		currentLevel.roomObject[index] = DefineObject(82,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 57:	//Water Corner Top Right
		currentLevel.roomObject[index] = DefineObject(83,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 58:	//Water Corner Bottom Left
		currentLevel.roomObject[index] = DefineObject(84,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 59:	//Water Corner Bottom Right
		currentLevel.roomObject[index] = DefineObject(85,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 60:	//VOID - CHANGE TO HOLE
		currentLevel.roomObject[index] = DefineObject(90,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;*/
	case 61:	//Brick Wall Full
		currentLevel.roomObject[index] = DefineObject(120,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 62:	//Brick Window Full
		currentLevel.roomObject[index] = DefineObject(121,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 63:	//Brick Door Full
		currentLevel.roomObject[index] = DefineObject(122,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 64:	//Mod Wall?
		currentLevel.roomObject[index] = DefineObject(123,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 65:	//Bookshelf
		currentLevel.roomObject[index] = DefineObject(147,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 66:	//Cliff face
		currentLevel.roomObject[index] = DefineObject(148,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 67:	//Cliff Left Angle Bottom
		currentLevel.roomObject[index] = DefineObject(149,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 68:	//Cliff Left Angle Top
		currentLevel.roomObject[index] = DefineObject(150,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 69:	//Cliff Right Angle Bottom
		currentLevel.roomObject[index] = DefineObject(151,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 70:	//Cliff Right Angle Top
		currentLevel.roomObject[index] = DefineObject(152,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 71:	//Cliff Right Side
		currentLevel.roomObject[index] = DefineObject(195,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 72:	//Barn 1
		currentLevel.roomObject[index] = DefineObject(154,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 73:	//Barn 2
		currentLevel.roomObject[index] = DefineObject(155,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 74:	//Barn 3
		currentLevel.roomObject[index] = DefineObject(156,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 75:	//Barn 4
		currentLevel.roomObject[index] = DefineObject(157,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 76:	//Barn 5
		currentLevel.roomObject[index] = DefineObject(158,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 77:	//Barn 6
		currentLevel.roomObject[index] = DefineObject(159,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 78:	//Barn 7
		currentLevel.roomObject[index] = DefineObject(160,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 79:	//Barn 8
		currentLevel.roomObject[index] = DefineObject(161,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 80:	//Barn 9
		currentLevel.roomObject[index] = DefineObject(162,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 81:	//Barn 10
		currentLevel.roomObject[index] = DefineObject(163,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 82:	//Barn 11
		currentLevel.roomObject[index] = DefineObject(164,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 83:	//Barn 12
		currentLevel.roomObject[index] = DefineObject(165,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 84:	//Barn 13
		currentLevel.roomObject[index] = DefineObject(166,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 85:	//Barn 14
		currentLevel.roomObject[index] = DefineObject(167,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 86:	//Barn 15
		currentLevel.roomObject[index] = DefineObject(168,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 87:	//Horse 1
		currentLevel.roomObject[index] = DefineObject(170,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 88:	//Horse 2
		currentLevel.roomObject[index] = DefineObject(171,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 89:	//Wood Wall top
		currentLevel.roomObject[index] = DefineObject(172,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 90:	//Wood Wall	left
		currentLevel.roomObject[index] = DefineObject(173,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 91:	//Wood Wall right
		currentLevel.roomObject[index] = DefineObject(174,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 92:	//Wood Wall bottom
		currentLevel.roomObject[index] = DefineObject(175,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 93:	//Wood corner 1
		currentLevel.roomObject[index] = DefineObject(176,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 94:	//Wood corner 2
		currentLevel.roomObject[index] = DefineObject(177,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 95:	//Wood corner 3
		currentLevel.roomObject[index] = DefineObject(178,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 96:	//Wood corner 4
		currentLevel.roomObject[index] = DefineObject(179,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 97:	//Dog
		currentLevel.roomObject[index] = DefineObject(181,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 101:	//Smashable Block
		currentLevel.roomObject[index] = DefineObject(182,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 102:	//Decorative Boulder
		currentLevel.roomObject[index] = DefineObject(183,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 103:	//Well
		currentLevel.roomObject[index] = DefineObject(101,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 104:	//Campfire
		currentLevel.roomObject[index] = DefineObject(184,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 105:	//Cliff Left Side
		currentLevel.roomObject[index] = DefineObject(185,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 106:	//Cliff Right Side
		currentLevel.roomObject[index] = DefineObject(186,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 107:	//Cliff Back Left Corner
		currentLevel.roomObject[index] = DefineObject(187,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 108:	//Cliff Back Right Corner
		currentLevel.roomObject[index] = DefineObject(188,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 109:	//Cliff Back Border
		currentLevel.roomObject[index] = DefineObject(189,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 110:	//Cliff Side Height
		currentLevel.roomObject[index] = DefineObject(190,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 111:	//Ladder Up
		currentLevel.roomObject[index] = DefineObject(204,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 112:	//Bridge Right
		currentLevel.roomObject[index] = DefineObject(180,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	/*case 113:	//Bridge Middle
		currentLevel.roomObject[index] = DefineObject(90,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;*/
	case 114:	//Indoor Cliff Top Left
		currentLevel.roomObject[index] = DefineObject(191,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 115:	//Indoor Cliff Left
		currentLevel.roomObject[index] = DefineObject(192,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 116:	//Indoor Cliff Bottom Left
		currentLevel.roomObject[index] = DefineObject(193,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 117:	//Indoor Cliff Top Right
		currentLevel.roomObject[index] = DefineObject(194,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 118:	//Indoor Cliff Right
		currentLevel.roomObject[index] = DefineObject(195,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 119:	//Indoor Cliff Bottom Right
		currentLevel.roomObject[index] = DefineObject(196,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 120:	//Indoor Cliff Ladder Right
		currentLevel.roomObject[index] = DefineObject(197,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 121:	//Indoor Cliff Ladder Left
		currentLevel.roomObject[index] = DefineObject(198,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	/*case 122:	//Roof Chimney
		currentLevel.roomObject[index] = DefineObject(199,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;*/
	case 123:	//Statue 1
		currentLevel.roomObject[index] = DefineObject(210,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 124:	//Statue 2
		currentLevel.roomObject[index] = DefineObject(211,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 125:	//Statue 3
		currentLevel.roomObject[index] = DefineObject(212,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 126:	//Statue 4
		currentLevel.roomObject[index] = DefineObject(213,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 127:	//Statue 5
		currentLevel.roomObject[index] = DefineObject(214,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 128:	//Statue 6
		currentLevel.roomObject[index] = DefineObject(215,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 129:	//Anvil
		SetAnimations(0,0,1,1);
		currentLevel.roomObject[index] = DefineObject(230,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 130:	//House
		currentLevel.roomObject[index] = DefineObject(135,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 131:	//House
		currentLevel.roomObject[index] = DefineObject(136,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 132:	//House
		currentLevel.roomObject[index] = DefineObject(137,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 133:	//House
		currentLevel.roomObject[index] = DefineObject(138,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 134:	//House
		currentLevel.roomObject[index] = DefineObject(139,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 135:	//House
		currentLevel.roomObject[index] = DefineObject(140,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 136:	//House
		currentLevel.roomObject[index] = DefineObject(141,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 137:	//House
		currentLevel.roomObject[index] = DefineObject(142,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 138:	//House
		currentLevel.roomObject[index] = DefineObject(143,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 139:	//House
		currentLevel.roomObject[index] = DefineObject(144,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 140:	//House
		currentLevel.roomObject[index] = DefineObject(145,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 141:	//House
		currentLevel.roomObject[index] = DefineObject(146,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 142:	//Alchemist Logo
		currentLevel.roomObject[index] = DefineObject(131,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 143:	//Survivalist Logo
		currentLevel.roomObject[index] = DefineObject(134,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 144:	//Locksmith Logo
		currentLevel.roomObject[index] = DefineObject(133,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 145:	//Bomb Crafter Logo
		currentLevel.roomObject[index] = DefineObject(132,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 146:	//Odd Corner Brick 
		currentLevel.roomObject[index] = DefineObject(5,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 147:	//Odd Corner Brick 
		currentLevel.roomObject[index] = DefineObject(6,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 148:	//Odd Corner Brick 
		currentLevel.roomObject[index] = DefineObject(7,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 149:	//Odd Corner Brick 
		currentLevel.roomObject[index] = DefineObject(8,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 150:	//Odd Corner Brick 
		currentLevel.roomObject[index] = DefineObject(9,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 151:	//Odd Corner Brick 
		currentLevel.roomObject[index] = DefineObject(10,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 152:	//Odd Corner Brick 
		currentLevel.roomObject[index] = DefineObject(11,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 153:	//Odd Corner Brick 
		currentLevel.roomObject[index] = DefineObject(12,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 154:	//Table Corner 1
		currentLevel.roomObject[index] = DefineObject(218,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 155:	//Table Corner 2
		currentLevel.roomObject[index] = DefineObject(219,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 156:	//TEST SPRITE 1
		SetAnimations(0,1,2,3);
		currentLevel.roomObject[index] = DefineObject(224,1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 157:	//TEST SPRITE 2
		currentLevel.roomObject[index] = DefineObject(225,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 158:	//TEST SPRITE 3
		currentLevel.roomObject[index] = DefineObject(226,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 159:	//TEST SPRITE 4
		currentLevel.roomObject[index] = DefineObject(227,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
//Chairs
                    
    case 98:	//Seat facing left
		currentLevel.roomObject[index] = DefineObject(34,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
    case 99:	//Seat facing right
		currentLevel.roomObject[index] = DefineObject(34,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 100:	//Seat facing up
		currentLevel.roomObject[index] = DefineObject(34,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;

	//Interactable Doors (301-400)

	case 301:	//D1
		currentLevel.roomObject[index] = DefineObject(71,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 302:	//D2
		currentLevel.roomObject[index] = DefineObject(70,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 303:	//D3
		currentLevel.roomObject[index] = DefineObject(70,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 304:	//D4
		currentLevel.roomObject[index] = DefineObject(71,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 305:	//D5
		currentLevel.roomObject[index] = DefineObject(72,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 306:	//D6
		currentLevel.roomObject[index] = DefineObject(140,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 307:	//D7
		currentLevel.roomObject[index] = DefineObject(43,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 308:	//D8
		currentLevel.roomObject[index] = DefineObject(72,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 309:	//D9
		currentLevel.roomObject[index] = DefineObject(45,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 310:	//D10
		currentLevel.roomObject[index] = DefineObject(202,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 311:	//Alchemist IN
		currentLevel.roomObject[index] = DefineObject(140,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 312:	//Alchemist OUT
		currentLevel.roomObject[index] = DefineObject(72,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 313:	//Survivalist IN
		currentLevel.roomObject[index] = DefineObject(140,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 314:	//Survivalist OUT
		currentLevel.roomObject[index] = DefineObject(72,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 315:	//Locksmith IN
		currentLevel.roomObject[index] = DefineObject(140,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 316:	//Locksmith OUT
		currentLevel.roomObject[index] = DefineObject(72,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 317:	//Bombshop IN
		currentLevel.roomObject[index] = DefineObject(140,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 318:	//Bombshop OUT
		currentLevel.roomObject[index] = DefineObject(72,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	
/*
	//Chests (501-600)

	case 501:	//Chest 1: Locked chest in playerhousebedroom1
		mapGrid[(x-2)/SPRT_WIDTH][(y-2)/SPRT_HEIGHT] = 501;
		if (chestsOpened[0] == 1){
			DrawSprite(8,2,x,y,false,false,0);
		}
		else DrawSprite(8,1,x,y,false,false,0);
		break;
	case 502: //Chest 2: Unlocked chest in playerhousebedroom3
		mapGrid[(x-2)/SPRT_WIDTH][(y-2)/SPRT_HEIGHT] = 502;
		if (chestsOpened[1] == 1){
			DrawSprite(8,2,x,y,false,false,0);
		}
		else DrawSprite(8,0,x,y,false,false,0);
		break;
	case 503: //Chest 3: Unlocked chest in 0,-1
		mapGrid[(x-2)/SPRT_WIDTH][(y-2)/SPRT_HEIGHT] = 503;
		if (chestsOpened[2] == 1){
			DrawSprite(8,2,x,y,false,false,0);
		}
		else DrawSprite(8,0,x,y,false,false,0);
		break;
	case 504: //Chest 4: Unlocked chest in 0,-1
		mapGrid[(x-2)/SPRT_WIDTH][(y-2)/SPRT_HEIGHT] = 504;
		if (chestsOpened[3] == 1){
			DrawSprite(8,2,x,y,false,false,0);
		}
		else DrawSprite(8,0,x,y,false,false,0);
		break;
	case 505:
		mapGrid[(x-2)/SPRT_WIDTH][(y-2)/SPRT_HEIGHT] = 505;
		if (chestsOpened[4] == 1){
			DrawSprite(8,2,x,y,false,false,0);
		}
		else DrawSprite(8,0,x,y,false,false,0);
		break;
	case 506:
		mapGrid[(x-2)/SPRT_WIDTH][(y-2)/SPRT_HEIGHT] = 506;
		if (chestsOpened[5] == 1){
			DrawSprite(8,2,x,y,false,false,0);
		}
		else DrawSprite(8,0,x,y,false,false,0);
		break;
*/
	//Signs (601-700)
					
	case 601:	//Sign 1: Your house
		currentLevel.roomObject[index] = DefineObject(78,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 602:	//Sign 2: Castletown ahead
		currentLevel.roomObject[index] = DefineObject(78,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;

	//NPCs (701 - 1000)

	case 701:	//NPC 1: King/Duke
		currentLevel.roomObject[index] = DefineObject(124,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 702:	//NPC 2: Blacksmith
		SetAnimations(0,0,1,1);
		currentLevel.roomObject[index] = DefineObject(228,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 703:	 //NPC 3: Conspicuous Stranger
		currentLevel.roomObject[index] = DefineObject(99,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 704:	//Lantern Man
		if (lantern)
		{
		DefineObjects(105, y, x);
		}
		else
		{
		currentLevel.roomObject[index] = DefineObject(99,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		}
		break;
	case 706:	//Bonfires
		SetAnimations(0,0,1,1);
		currentLevel.roomObject[index] = DefineObject(235,1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 708:	//Breakable Wall
		currentLevel.roomObject[index] = DefineObject(182,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
// Ladders UP
	case 800:	//Ladder 0
		currentLevel.roomObject[index] = DefineObject(204,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 801:	//Ladder 1
		currentLevel.roomObject[index] = DefineObject(204,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 802:	//Ladder 2
		currentLevel.roomObject[index] = DefineObject(204,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 803:	//Ladder 3
		currentLevel.roomObject[index] = DefineObject(204,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 804:	//Ladder 4
		currentLevel.roomObject[index] = DefineObject(204,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 805:	//Ladder 5
		currentLevel.roomObject[index] = DefineObject(204,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 806:	//Ladder 6
		currentLevel.roomObject[index] = DefineObject(204,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 807:	//Ladder 7
		currentLevel.roomObject[index] = DefineObject(204,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 808:	//Ladder 8
		currentLevel.roomObject[index] = DefineObject(204,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 809:	//Ladder 9
		currentLevel.roomObject[index] = DefineObject(204,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 810:	//Ladder 10
		currentLevel.roomObject[index] = DefineObject(204,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 811:	//Ladder 11
		currentLevel.roomObject[index] = DefineObject(204,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 812:	//Ladder 12
		currentLevel.roomObject[index] = DefineObject(204,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;

// Ladders DOWN
	case 813:	//Ladder top
		currentLevel.roomObject[index] = DefineObject(199,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case -801:	//Ladder 1
		currentLevel.roomObject[index] = DefineObject(199,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case -802:	//Ladder 2
		currentLevel.roomObject[index] = DefineObject(199,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case -803:	//Ladder 3
		currentLevel.roomObject[index] = DefineObject(199,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case -804:	//Ladder 4
		currentLevel.roomObject[index] = DefineObject(199,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case -805:	//Ladder 5
		currentLevel.roomObject[index] = DefineObject(199,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case -806:	//Ladder 6
		currentLevel.roomObject[index] = DefineObject(199,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case -807:	//Ladder 7
		currentLevel.roomObject[index] = DefineObject(199,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case -808:	//Ladder 8
		currentLevel.roomObject[index] = DefineObject(199,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case -809:	//Ladder 9
		currentLevel.roomObject[index] = DefineObject(199,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case -810:	//Ladder 10
		currentLevel.roomObject[index] = DefineObject(199,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case -811:	//Ladder 11
		currentLevel.roomObject[index] = DefineObject(199,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,object);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	case 999:	//Score
		currentLevel.roomObject[index] = DefineObject(200,-2,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,y*SPRITE_HEIGHT,x*SPRITE_WIDTH),0,0,y,x,0,999);
		currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		break;
	}
}