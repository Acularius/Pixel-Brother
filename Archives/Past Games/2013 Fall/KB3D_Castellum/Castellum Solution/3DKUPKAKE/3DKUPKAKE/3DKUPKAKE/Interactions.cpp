//Includes
#include "Interactions.h"
#include "ImportMaps.h"
#include "DrawWindows.h"
#include "GlobalVars.h"
#include "CreateObject.h"
#include <Windows.h>
//#include "Inventory.h"

//Variables
const int SPRITE_WIDTH = 9;
const int SPRITE_HEIGHT = 6;
bool lantern = false;
bool hammer = false;
int finalstep;
int progress = 0;
int totalfloors = 100;

void Interaction(int obj, int index)
{
	
	switch(obj)
	{
	case 301: //Player Bedroom 1
		printf("\a");
		Player.SetX(14 * SPRITE_WIDTH);
		Player.SetY(6 * SPRITE_HEIGHT);
		Player.SetDirection(2);
		destroy_win(Player.objectWindow);

		Player.objectWindow = create_win(6,9,Player.GetY(),Player.GetX());
		Player.DrawSprite(Player,0);
		currentLevel.ImportMap(0,0,"playerhouseentrance");
		break;

	case 302: //Player Entrance
		printf("\a");
		Player.SetX(12 * SPRITE_WIDTH);
		Player.SetY(5 * SPRITE_HEIGHT);
		Player.SetDirection(3);
		destroy_win(Player.objectWindow);

		Player.objectWindow = create_win(6,9,Player.GetY(),Player.GetX());
		Player.DrawSprite(Player,0);
		currentLevel.ImportMap(0,0,"playerhousebedroom1");
		break;

	case 303: //Player Bedroom 3
		printf("\a");
		Player.SetX(18 * SPRITE_WIDTH);
		Player.SetY(5 * SPRITE_HEIGHT);
		Player.SetDirection(3);
		destroy_win(Player.objectWindow);

		Player.objectWindow = create_win(6,9,Player.GetY(),Player.GetX());
		Player.DrawSprite(Player,0);
		currentLevel.ImportMap(0,0,"playerhouseentrance");
		break;

	case 304: //Player Entrance
		printf("\a");
		Player.SetX(8 * SPRITE_WIDTH);
		Player.SetY(4 * SPRITE_HEIGHT);
		Player.SetDirection(2);
		destroy_win(Player.objectWindow);

		Player.objectWindow = create_win(6,9,Player.GetY(),Player.GetX());
		Player.DrawSprite(Player,0);
		currentLevel.ImportMap(0,0,"playerhousebedroom3");
		break;

	case 305: //Player Entrance
		printf("\a");
		Player.SetX(7 * SPRITE_WIDTH);
		Player.SetY(5 * SPRITE_HEIGHT);
		Player.SetDirection(0);
		destroy_win(Player.objectWindow);

		Player.objectWindow = create_win(6,9,Player.GetY(),Player.GetX());
		Player.DrawSprite(Player,0);
		roomX = 2;
		roomY = 1;
		currentLevel.ImportMap(2,1,"NULL");
		break;

	case 306: //2,1 to Player House
		printf("\a");
		Player.SetX(16 * SPRITE_WIDTH);
		Player.SetY(7 * SPRITE_HEIGHT);
		Player.SetDirection(1);
		destroy_win(Player.objectWindow);

		Player.objectWindow = create_win(6,9,Player.GetY(),Player.GetX());
		Player.DrawSprite(Player,0);
		currentLevel.ImportMap(0,0,"playerhouseentrance");
		break;

	case 307: //Player Entrance
		printf("\a");
		Player.SetX(10 * SPRITE_WIDTH);
		Player.SetY(6 * SPRITE_HEIGHT);
		Player.SetDirection(1);
		destroy_win(Player.objectWindow);

		Player.objectWindow = create_win(6,9,Player.GetY(),Player.GetX());
		Player.DrawSprite(Player,0);
		currentLevel.ImportMap(0,0,"playerhousebedroom2");
		break;

	case 308: //Player Bedroom 2
		printf("\a");
		Player.SetX(11 * SPRITE_WIDTH);
		Player.SetY(2 * SPRITE_HEIGHT);
		Player.SetDirection(0);
		destroy_win(Player.objectWindow);

		Player.objectWindow = create_win(6,9,Player.GetY(),Player.GetX());
		Player.DrawSprite(Player,0);
		currentLevel.ImportMap(0,0,"playerhouseentrance");
		break;

	case 309:	//Cave Entrance
		if (lantern)
		{
		printf("\a");
		currentLevel.ToggleLights();
		Player.SetX(8 * SPRITE_WIDTH);
		Player.SetY(9 * SPRITE_HEIGHT);
		Player.SetDirection(1);
		destroy_win(Player.objectWindow);

		Player.objectWindow = create_win(6,9,Player.GetY(),Player.GetX());
		Player.DrawSprite(Player,0);
		currentLevel.ImportMap(2,1,"FLOOR 0");
		}
		else
		{
		Player.SetDirection(3);
		Player.DrawSprite(Player,0);
		DrawMessage(-1,-1,40,8,"Nervous Man: Wait! You can't go in  there, it's too dark.");
		DrawMessage(-1,-1,40,8,"Nervous Man: Here, take my lantern. I'm too scared to go in anyways.");
		DrawMessage(-1,-1,40,8,"You obtained LANTERN!");
		lantern = true;
		}
		break;

	case 310:	//Cave Exit
		printf("\a");
		currentLevel.ToggleLights();
		Player.SetX(10 * SPRITE_WIDTH);
		Player.SetY(3 * SPRITE_HEIGHT);
		Player.SetDirection(0);
		destroy_win(Player.objectWindow);

		Player.objectWindow = create_win(6,9,Player.GetY(),Player.GetX());
		Player.DrawSprite(Player,0);
		currentLevel.ImportMap(1,1,"NULL");
		break;

	case 311:	//Alchemist IN
		DrawMessage(-1,-1,40,8,"The Alchemist seems to have spilled something corrosive on the door knob...");
		//printf("\a");
		//Player.SetX(9 * SPRITE_WIDTH);
		//Player.SetY(6 * SPRITE_HEIGHT);
		//Player.SetDirection(1);
		//destroy_win(Player.objectWindow);

		//Player.objectWindow = create_win(6,9,Player.GetY(),Player.GetX());
		//Player.DrawSprite(Player,0);
		//currentLevel.ImportMap(1,1,"Alchemist");
		break;

	case 312:	//Alchemist OUT
		printf("\a");
		Player.SetX(18 * SPRITE_WIDTH);
		Player.SetY(3 * SPRITE_HEIGHT);
		Player.SetDirection(0);
		destroy_win(Player.objectWindow);

		Player.objectWindow = create_win(6,9,Player.GetY(),Player.GetX());
		Player.DrawSprite(Player,0);
		currentLevel.ImportMap(2,1,"NULL");
		break;

	case 313:	//Survivalist IN
		DrawMessage(-1,-1,40,8,"There's a sign on the door saying   'Out adventuring'...");
		//printf("\a");
		//Player.SetX(9 * SPRITE_WIDTH);
		//Player.SetY(6 * SPRITE_HEIGHT);
		//Player.SetDirection(1);
		//destroy_win(Player.objectWindow);

		//Player.objectWindow = create_win(6,9,Player.GetY(),Player.GetX());
		//Player.DrawSprite(Player,0);
		//currentLevel.ImportMap(1,1,"Survivalist");
		break;

	case 314:	//Survivalist OUT
		//printf("\a");
		//Player.SetX(15 * SPRITE_WIDTH);
		//Player.SetY(8 * SPRITE_HEIGHT);
		//Player.SetDirection(0);
		//destroy_win(Player.objectWindow);

		//Player.objectWindow = create_win(6,9,Player.GetY(),Player.GetX());
		//Player.DrawSprite(Player,0);
		//currentLevel.ImportMap(2,1,"NULL");
		break;

	case 315:	//Locksmith IN
		DrawMessage(-1,-1,40,8,"The Locksmith seems to have locked  himself in...");
		//printf("\a");
		//Player.SetX(9 * SPRITE_WIDTH);
		//Player.SetY(6 * SPRITE_HEIGHT);
		//Player.SetDirection(1);
		//destroy_win(Player.objectWindow);

		//Player.objectWindow = create_win(6,9,Player.GetY(),Player.GetX());
		//Player.DrawSprite(Player,0);
		//currentLevel.ImportMap(1,1,"Locksmith");
		break;

	case 316:	//Locksmith OUT
		printf("\a");
		Player.SetX(12 * SPRITE_WIDTH);
		Player.SetY(3 * SPRITE_HEIGHT);
		Player.SetDirection(0);
		destroy_win(Player.objectWindow);

		Player.objectWindow = create_win(6,9,Player.GetY(),Player.GetX());
		Player.DrawSprite(Player,0);
		currentLevel.ImportMap(2,1,"NULL");
		break;

	case 317:	//Bombcrafter IN
		DrawMessage(-1,-1,40,8,"Nobody seem's to be in...");
		/*printf("\a");
		Player.SetX(9 * SPRITE_WIDTH);
		Player.SetY(6 * SPRITE_HEIGHT);
		Player.SetDirection(1);
		destroy_win(Player.objectWindow);
		Player.objectWindow = create_win(6,9,Player.GetY(),Player.GetX());
		Player.DrawSprite(Player,0);
		currentLevel.ImportMap(1,1,"Bombcrafter");
		break;*/
		//Inventory();
		break;

	case 318:	//Bombcrafter OUT
		printf("\a");
		Player.SetX(3 * SPRITE_WIDTH);
		Player.SetY(3 * SPRITE_HEIGHT);
		Player.SetDirection(0);
		destroy_win(Player.objectWindow);

		Player.objectWindow = create_win(6,9,Player.GetY(),Player.GetX());
		Player.DrawSprite(Player,0);
		currentLevel.ImportMap(2,1,"NULL");
		break;
		
	//Ladders UP
	case 800: //Floor 0
		printf("\a");
		Player.SetX(1 * SPRITE_WIDTH);
		Player.SetY(1 * SPRITE_HEIGHT);
		Player.SetDirection(0);
		destroy_win(Player.objectWindow);

		Player.objectWindow = create_win(6,9,Player.GetY(),Player.GetX());
		Player.DrawSprite(Player,0);
		currentLevel.ImportMap(0,0,"FLOOR 1");
		break;

	case 801: //Floor 1
		progress = 1;
		printf("\a");
		Player.SetX(9 * SPRITE_WIDTH);
		Player.SetY(5 * SPRITE_HEIGHT);
		Player.SetDirection(0);
		destroy_win(Player.objectWindow);

		Player.objectWindow = create_win(6,9,Player.GetY(),Player.GetX());
		Player.DrawSprite(Player,0);
		currentLevel.ImportMap(0,0,"FLOOR 2");
		break;

	case 802: //Floor 2
		progress = 2;
		printf("\a");
		Player.SetX(1 * SPRITE_WIDTH);
		Player.SetY(1 * SPRITE_HEIGHT);
		Player.SetDirection(0);
		destroy_win(Player.objectWindow);

		Player.objectWindow = create_win(6,9,Player.GetY(),Player.GetX());
		Player.DrawSprite(Player,0);
		currentLevel.ImportMap(0,0,"FLOOR 3");
		break;

	case 803: //Floor 3
		progress = 3;
		printf("\a");
		Player.SetX(17 * SPRITE_WIDTH);
		Player.SetY(1 * SPRITE_HEIGHT);
		Player.SetDirection(0);
		destroy_win(Player.objectWindow);

		Player.objectWindow = create_win(6,9,Player.GetY(),Player.GetX());
		Player.DrawSprite(Player,0);
		currentLevel.ImportMap(0,0,"FLOOR 4");
		break;

	case 804: //Floor 4
		progress = 4;
		printf("\a");
		Player.SetX(2 * SPRITE_WIDTH);
		Player.SetY(9 * SPRITE_HEIGHT);
		Player.SetDirection(0);
		destroy_win(Player.objectWindow);

		Player.objectWindow = create_win(6,9,Player.GetY(),Player.GetX());
		Player.DrawSprite(Player,0);
		currentLevel.ImportMap(0,0,"FLOOR 5");
		break;

	case 805: //Floor 
		progress = 5;
		printf("\a");
		Player.SetX(18 * SPRITE_WIDTH);
		Player.SetY(3 * SPRITE_HEIGHT);
		Player.SetDirection(0);
		destroy_win(Player.objectWindow);

		Player.objectWindow = create_win(6,9,Player.GetY(),Player.GetX());
		Player.DrawSprite(Player,0);
		currentLevel.ImportMap(0,0,"FLOOR 7");
		break;

	 case 806: //Floor 6
		progress = 6;
		printf("\a");
		Player.SetX(18 * SPRITE_WIDTH);
		Player.SetY(3 * SPRITE_HEIGHT);
		Player.SetDirection(0);
		destroy_win(Player.objectWindow);
		Player.objectWindow = create_win(6,9,Player.GetY(),Player.GetX());
		Player.DrawSprite(Player,0);
		currentLevel.ImportMap(0,0,"FLOOR 7");
		break;
  
	 case 807: //Floor 7
		progress = 7;
		printf("\a");
		Player.SetX(3 * SPRITE_WIDTH);
		Player.SetY(9 * SPRITE_HEIGHT);
		Player.SetDirection(0);
		destroy_win(Player.objectWindow);
		Player.objectWindow = create_win(6,9,Player.GetY(),Player.GetX());
		Player.DrawSprite(Player,0);
		currentLevel.ImportMap(0,0,"FLOOR 8");
		break;

	 case 808: //Floor 8
		progress = 8;
		printf("\a");
		Player.SetX(1 * SPRITE_WIDTH);
		Player.SetY(6 * SPRITE_HEIGHT);
		Player.SetDirection(0);
		destroy_win(Player.objectWindow);
		Player.objectWindow = create_win(6,9,Player.GetY(),Player.GetX());
		Player.DrawSprite(Player,0);
		currentLevel.ImportMap(0,0,"FLOOR 9");
		break;
  
	 case 809: //Floor 9
		progress = 9;
		printf("\a");
		Player.SetX(19 * SPRITE_WIDTH);
		Player.SetY(5 * SPRITE_HEIGHT);
		Player.SetDirection(0);
		destroy_win(Player.objectWindow);
		Player.objectWindow = create_win(6,9,Player.GetY(),Player.GetX());
		Player.DrawSprite(Player,0);
		currentLevel.ImportMap(0,0,"FLOOR 10");
		break;

	 case 810: //Floor 10
		progress = 10;
		printf("\a");
		Player.SetX(2 * SPRITE_WIDTH);
		Player.SetY(8 * SPRITE_HEIGHT);
		Player.SetDirection(0);
		destroy_win(Player.objectWindow);

		Player.objectWindow = create_win(6,9,Player.GetY(),Player.GetX());
		Player.DrawSprite(Player,0);
		currentLevel.ImportMap(0,0,"FLOOR 11");
		break;

	 case 811: //Floor 11
		progress = 11;
		printf("\a");
		Player.SetX(1 * SPRITE_WIDTH);
		Player.SetY(9 * SPRITE_HEIGHT);
		Player.SetDirection(0);
		destroy_win(Player.objectWindow);

		Player.objectWindow = create_win(6,9,Player.GetY(),Player.GetX());
		Player.DrawSprite(Player,0);
		finalstep = Step;
		currentLevel.ImportMap(0,0,"TEMP 5");
		break;
	case 812: //Floor 12
		progress = 12;
		printf("\a");
		Player.SetX(18 * SPRITE_WIDTH);
		Player.SetY(9 * SPRITE_HEIGHT);
		Player.SetDirection(0);
		destroy_win(Player.objectWindow);

		Player.objectWindow = create_win(6,9,Player.GetY(),Player.GetX());
		Player.DrawSprite(Player,0);
		finalstep = Step;
		currentLevel.ImportMap(0,0,"TEMP 7");
		break;
//Ladders DOWN
	case -800: //Floor 0
		printf("\a");
		Player.SetX(1 * SPRITE_WIDTH);
		Player.SetY(1 * SPRITE_HEIGHT);
		Player.SetDirection(0);
		destroy_win(Player.objectWindow);

		Player.objectWindow = create_win(6,9,Player.GetY(),Player.GetX());
		Player.DrawSprite(Player,0);
		currentLevel.ImportMap(0,0,"FLOOR 0");
		break;

	case 813: //Top
		printf("\a");
		Player.SetX(10 * SPRITE_WIDTH);
		Player.SetY(7 * SPRITE_HEIGHT);
		Player.SetDirection(1);
		destroy_win(Player.objectWindow);

		Player.objectWindow = create_win(6,9,Player.GetY(),Player.GetX());
		Player.DrawSprite(Player,0);
		currentLevel.ImportMap(0,9,"0,10");
		break;

	//case -802: //Floor 2
	//	printf("\a");
	//	Player.SetX(1 * SPRITE_WIDTH);
	//	Player.SetY(1 * SPRITE_HEIGHT);
	//	Player.SetDirection(0);
	//	destroy_win(Player.objectWindow);

	//	Player.objectWindow = create_win(6,9,Player.GetY(),Player.GetX());
	//	Player.DrawSprite(Player,0);
	//	currentLevel.ImportMap(0,0,"FLOOR 2");
	//	break;

	//case -803: //TEMP 3
	//	printf("\a");
	//	Player.SetX(19 * SPRITE_WIDTH);
	//	Player.SetY(3 * SPRITE_HEIGHT);
	//	Player.SetDirection(0);
	//	destroy_win(Player.objectWindow);

	//	Player.objectWindow = create_win(6,9,Player.GetY(),Player.GetX());
	//	Player.DrawSprite(Player,0);
	//	currentLevel.ImportMap(0,0,"TEMP 3");
	//	break;

	//case -804: //TEMP 4
	//	printf("\a");
	//	Player.SetX(1 * SPRITE_WIDTH);
	//	Player.SetY(9 * SPRITE_HEIGHT);
	//	Player.SetDirection(0);
	//	destroy_win(Player.objectWindow);

	//	Player.objectWindow = create_win(6,9,Player.GetY(),Player.GetX());
	//	Player.DrawSprite(Player,0);
	//	currentLevel.ImportMap(0,0,"TEMP 4");
	//	break;

	//case -805: //TEMP 5
	//	printf("\a");
	//	Player.SetX(14 * SPRITE_WIDTH);
	//	Player.SetY(3 * SPRITE_HEIGHT);
	//	Player.SetDirection(0);
	//	destroy_win(Player.objectWindow);

	//	Player.objectWindow = create_win(6,9,Player.GetY(),Player.GetX());
	//	Player.DrawSprite(Player,0);
	//	currentLevel.ImportMap(0,0,"TEMP 5");
	//	break;

	//case -806: //TEMP 6
	//	printf("\a");
	//	Player.SetX(19 * SPRITE_WIDTH);
	//	Player.SetY(8 * SPRITE_HEIGHT);
	//	Player.SetDirection(0);
	//	destroy_win(Player.objectWindow);

	//	Player.objectWindow = create_win(6,9,Player.GetY(),Player.GetX());
	//	Player.DrawSprite(Player,0);
	//	currentLevel.ImportMap(0,0,"TEMP 6");
	//	break;
	// NPC's
	case 702: //Blacksmith
		if (hammer)
			DrawMessage(-1,-1,40,8,"Blacksmith: That hammer will break  down most cracked walls.");
		else
		{
		DrawMessage(-1,-1,40,8,"Blacksmith: You there! You don't    seem to have a hammer.");
		DrawMessage(-1,-1,40,8,"Blacksmith: There's no way you'll   make it through the tower without   one.");
		DrawMessage(-1,-1,40,8,"Blacksmith: I'm not using this one  anymore, maybe you can put it to    good use.");
		DrawMessage(-1,-1,40,8,"You obtained HAMMER!");
		hammer = true;
		}
		break;
	case 704: //Lantern Man
		if (lantern)
			DrawMessage(-1,-1,40,8,"Nervous Man: Good Luck!");
		else
		{
		DrawMessage(-1,-1,40,8,"Nervous Man: Wait! You can't go in  there, it's too dark.");
		DrawMessage(-1,-1,40,8,"Nervous Man: Here, take my lantern. I'm too scared to go in anyways.");
		DrawMessage(-1,-1,40,8,"You obtained LANTERN!");
		lantern = true;
		}
		break;
	case 708: //Breakable Wall
		if (hammer)
		{
			DrawMessage(-1,-1,40,8,"You broke the wall down with your   hammer!");
			currentLevel.roomObject[index].SetObjIndex(0);
			currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],0);
		}
		else
			DrawMessage(-1,-1,40,8,"This wall is cracked, you could     probably knock it down if you had   the correct tool. Maybe you should  look around town.");
		break;
	case 701: //King
		DrawMessage(-1,-1,40,8,"Duke: Congratulations on making it  though the Castellum!");
		DrawMessage(-1,-1,40,8,"Duke: I hereby present you with yourcertificate of Adventurity, you may now venture beyond the town walls.");
		DrawMessage(-1,-1,40,8,"Duke: Go forth Adventurer! The worldawaits!");
		DrawMessage(-1,-1,40,8,"Congratulations! You complete in ?? steps.");
		DrawMessage(-1,-1,40,8,"Press 'I' then 'Esc' to exit.");
		break;
	}
}

void Switch(int &x, int &y, Object &player_object)
{
	if (player_object.GetX()/SPRITE_WIDTH == 21 && (GetAsyncKeyState(VK_RIGHT) && 0x8000))//Right
	{
		roomX += 1;
		Player.SetX(0);
		destroy_win(Player.objectWindow);
		Player.objectWindow = create_win(6,9,Player.GetY(),Player.GetX());
		Player.DrawSprite(Player,0);
		currentLevel.ImportMap(roomX,roomY,"NULL");
	}

	if (player_object.GetX()/SPRITE_WIDTH == 0 && (GetAsyncKeyState(VK_LEFT) && 0x8000))//Left
	{
		roomX -= 1;
		Player.SetX(21 * SPRITE_WIDTH);
		destroy_win(Player.objectWindow);
		Player.objectWindow = create_win(6,9,Player.GetY(),Player.GetX());
		Player.DrawSprite(Player,0);
		currentLevel.ImportMap(roomX,roomY,"NULL");
	}

	if (player_object.GetY()/SPRITE_HEIGHT == 10 && (GetAsyncKeyState(VK_DOWN) && 0x8000))//Down
	{
		roomY += 1;
		Player.SetY(0);
		destroy_win(Player.objectWindow);
		Player.objectWindow = create_win(6,9,Player.GetY(),Player.GetX());
		Player.DrawSprite(Player,0);
		currentLevel.ImportMap(roomX,roomY,"NULL");
	}

	if (player_object.GetY()/SPRITE_HEIGHT == 0 && (GetAsyncKeyState(VK_UP) && 0x8000))//Up
	{
		roomY -= 1;
		Player.SetY(10 * SPRITE_HEIGHT);
		destroy_win(Player.objectWindow);
		Player.objectWindow = create_win(6,9,Player.GetY(),Player.GetX());
		Player.DrawSprite(Player,0);
		currentLevel.ImportMap(roomX,roomY,"NULL");
	}
}