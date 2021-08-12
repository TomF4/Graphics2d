#include "Map.h"
#include "ImageLoading.h"
#include "shaders/Shader.h"


int collisionMap[20][25] = {
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,8,8,8,8,8,8,8,8,8,8,8,8,8,0,0,0,0,0,0,0},
	{0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0},
	{0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0},
	{0,0,0,0,8,0,0,8,8,8,8,8,8,8,8,0,0,8,0,0,0,0,0,0,0},
	{0,0,0,0,8,0,0,8,0,0,0,0,0,0,8,0,0,8,0,0,0,0,0,0,0},
	{0,0,0,0,8,0,0,8,0,0,0,0,0,0,8,0,0,8,0,0,0,0,0,0,0},
	{0,0,0,0,8,0,0,8,8,8,8,8,8,8,8,0,0,8,0,0,0,0,0,0,0},
	{0,0,0,0,8,0,0,0,0,0,0,0,0,8,8,0,0,8,0,0,0,0,0,0,0},
	{0,0,0,0,8,0,0,0,0,0,0,0,0,8,8,0,0,8,0,0,0,0,0,0,0},
	{0,0,0,0,8,8,8,8,8,8,8,8,8,8,8,0,0,8,0,0,0,0,0,0,0},
	{0,0,0,0,8,8,8,8,8,8,8,8,8,8,8,0,0,8,0,0,0,0,0,0,0},
	{0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0},
	{0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0},
	{0,0,0,0,8,8,8,8,8,8,8,8,8,8,8,8,8,8,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};


Map::Map()
{
	LoadMap(map);
}

void Map::LoadMap(int arr[20][25])
{
	for (int row = 0; row < 20; row++)
	{
		for (int column = 0; column < 25; column++)
		{
			map[row][column] = arr[row][column];
		}
	}
}


std::vector<Sprite> Map::DrawMap()
{
	FreeImage_Initialise();
	float red[3] = {1,0,0};
	float blue[3] = {0,0,1};

	//Load the GLSL program 
	if (!shader.load("Basic", "./glslfiles/basicTexture.vert", "./glslfiles/basicTexture.frag"))
	{
		std::cout << "failed to load shader" << std::endl;
	}

	{
	puddle			.SetWidth(400.0f);
	puddle			.SetHeight(400.0f);
	puddle			.Init(shader, red, "textures/floor/puddle1.png", 1,1);
	grass			.SetWidth (400.0f);
	grass			.SetHeight(400.0f);
	grass			.Init     (shader, red,		 "textures/floor/grass.png",           1, 1);
	mainRoad		.SetWidth (400.0f);			 								      
	mainRoad		.SetHeight(400.0f);			 								      
	mainRoad		.Init     (shader, red,		 "textures/floor/main2.png",           1, 1);		
	leftWall		.SetWidth (400.0f);			 								      
	leftWall		.SetHeight(400.0f);			 								      
	leftWall		.Init     (shader, red,		 "textures/walls/leftWall.png",        1, 1);
	rightWall		.SetWidth (400.0f);			 								      
	rightWall		.SetHeight(400.0f);			 			
	rightWall		.Init     (shader, red,		 "textures/walls/rightWall.png",       1, 1);
	topWall			.SetWidth (400.0f);			 								      
	topWall			.SetHeight(400.0f);			 		
	topWall			.Init     (shader, red,		 "textures/walls/topWall.png",         1, 1);
	botWall			.SetWidth (400.0f);			 								      
	botWall			.SetHeight(400.0f);			
	botWall			.Init     (shader, red,		 "textures/walls/botWall.png",         1, 1);
	botRightCorner	.SetWidth (400.0f);			 
	botRightCorner	.SetHeight(400.0f);			 
	botRightCorner	.Init     (shader, red,		 "textures/corner/botRightCorner.png", 1, 1);
	botLeftCorner	.SetWidth (400.0f);			 									  
	botLeftCorner	.SetHeight(400.0f);			 	
	botLeftCorner	.Init     (shader, red,		 "textures/corner/botLeftCorner.png",  1, 1);
	topRightCorner	.SetWidth (400.0f);			 
	topRightCorner	.SetHeight(400.0f);		
	topRightCorner	.Init     (shader, red,		 "textures/corner/topRightCorner.png", 1, 1);
	topLeftCorner	.SetWidth (400.0f);			 
	topLeftCorner	.SetHeight(400.0f);		
	topLeftCorner	.Init     (shader, red,		 "textures/corner/topLeftCorner.png", 1, 1);
	startSprite.SetWidth(400.0f);
	startSprite.SetHeight(400.0f);
	startSprite.Init(shader, red, "textures/floor/start.png", 1, 1);	
	finish.SetWidth(400.0f);
	finish.SetHeight(400.0f);
	finish.Init(shader, red, "textures/floor/finish.png", 1, 1);
	}

	puddle        .setName("tar");
	startSprite         .setName("start");
	finish        .setName("finish");
	grass         .setName("grass");
	mainRoad      .setName("road");
	botWall       .setName("wall");
	leftWall      .setName("wall");
	topWall       .setName("wall");
	rightWall     .setName("wall");
	botRightCorner.setName("wall");
	botLeftCorner .setName("wall");
	topRightCorner.setName("wall");
	topLeftCorner .setName("wall");


	int type = 0;
	//track loop
	for (int row = 0; row < 20; row++)
	{
		for (int column = 0; column < 25; column++)
		{
			type = map[row][column];
	
			posX = column * 400.0f;
			posY = row    * 400.0f;
	
			switch (type)
			{
			case 0:
				puddle.SetXpos(posX);
				puddle.SetYpos(posY);
				trackMap.push_back(puddle);
				break;
			case 1:				
				grass.SetXpos(posX);
				grass.SetYpos(posY);
				trackMap.push_back(grass);
				break;
			case 2:
				mainRoad.SetXpos(posX);
				mainRoad.SetYpos(posY);
				trackMap.push_back(mainRoad);
				break;
			case 3:
				topWall.SetXpos(posX);
				topWall.SetYpos(posY);
				trackMap.push_back(topWall);
				break;
			case 4:
				leftWall.SetXpos(posX);
				leftWall.SetYpos(posY);
				trackMap.push_back(leftWall);
				break;
			case 5:
				botWall.SetXpos(posX);
				botWall.SetYpos(posY);
				trackMap.push_back(botWall);
				break;
			case 6:
				rightWall.SetXpos(posX);
				rightWall.SetYpos(posY);
				trackMap.push_back(rightWall);
				break;
			case 7:
				botRightCorner.SetXpos(posX);
				botRightCorner.SetYpos(posY);
				trackMap.push_back(botRightCorner);
				break;
			case 8:
				botLeftCorner.SetXpos(posX);
				botLeftCorner.SetYpos(posY);
				trackMap.push_back(botLeftCorner);
				break;
			case 9:
				topRightCorner.SetXpos(posX);
				topRightCorner.SetYpos(posY);
				trackMap.push_back(topRightCorner);
				break;
			case 10:
				topLeftCorner.SetXpos(posX);
				topLeftCorner.SetYpos(posY);
				trackMap.push_back(topLeftCorner);
				break;
			case 11:
				startSprite.SetXpos(posX);
				startSprite.SetYpos(posY);
				trackMap.push_back(startSprite);
				startingPosX = posX;
				startingPosY = posY;
				break;		
			case 12:
				finish.SetXpos(posX);
				finish.SetYpos(posY);
				trackMap.push_back(finish);
				break;

			}
		}
	}
	return trackMap;
}