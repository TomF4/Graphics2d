//#pragma once
//#include "Sprite.h"
//#include "Map.h"
//#include "shaders\Shader.h"
//#include "Map.h"
//#include "MapFiles.h"
//#include "Player.h"
//
//
//extern glm::mat4 ViewMatrix;  // matrix for the modelling and viewing
//extern glm::mat4 ProjectionMatrix;
//
//extern int screenWidth;
//extern int screenHeight;
//
//extern float l;
//extern float r;
//extern float t;
//extern float b;
//
//class Game
//{
//	
//private:
//	Sprite ControllsText;
//	Sprite gameOver;
//	Sprite win;
//	Sprite blind;
//
//	Sprite number1;
//	Sprite number2;
//	Sprite number3;
//	Shader shader;
//
//	Sprite tutorialText;
//
//	glm::mat4 ControllsTextMatrix = glm::translate(ViewMatrix, glm::vec3(l + 125, b - 125, 0.0));
//
//	Map map;
//	std::vector<Sprite> track;
//
//public:
//	void textInit();
//
//	void renderTrack();
//	void renderControlls();
//
//	void trackLoad(int mapArray[20][25]){
//		map.LoadMap(mapArray);
//		track = map.DrawMap();
//	}
//};