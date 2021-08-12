//
//#include "Game.h"
//
//
//void Game::textInit() {
//	float red[3] = { 1,0,0 };
//	ControllsText.SetWidth(200.f);
//	ControllsText.SetHeight(200.f);
//	ControllsText.Init(shader, red, "textures/Controlls2.png", 1, 1);
//
//	number1.SetWidth(200.f);
//	number1.SetHeight(200.f);
//	number1.Init(shader, red, "textures/number1.png", 1, 1);
//	number2.SetWidth(200.f);
//	number2.SetHeight(200.f);
//	number2.Init(shader, red, "textures/number2.png", 1, 1);
//	number3.SetWidth(200.f);
//	number3.SetHeight(200.f);
//	number3.Init(shader, red, "textures/number3.png", 1, 1);
//
//	gameOver.SetWidth(222.f * (64 / 64));
//	gameOver.SetHeight(222.f);
//	gameOver.Init(shader, red, "textures/gameOver.png", 1, 1);
//
//	blind.SetWidth(5000.f);
//	blind.SetHeight(5000.f);
//	blind.Init(shader, red, "textures/floor/blind.png", 1, 1);
//
//	tutorialText.SetWidth(400.f);
//	tutorialText.SetHeight(400.f);
//	tutorialText.Init(shader, red, "textures/tutorialText.png", 1, 1);
//}
//
//
//void Game::renderTrack(){
//	glm::mat4 TrackMatrix;
//	for (int i = 0; i < track.size(); i++)
//	{
//		TrackMatrix = glm::translate(ViewMatrix, glm::vec3(track[i].GetXPos(), track[i].GetYPos(), 0.0f));
//		track[i].Render(shader, TrackMatrix, ProjectionMatrix);
//	}
//}
//void Game::renderControlls(){
//	ControllsText.Render(shader, ControllsTextMatrix, ProjectionMatrix);
//}