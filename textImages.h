#pragma once

#include "Sprite.h"

class textImages
{

public :
	Shader shader;
	float width  = 200.f;
	float height = 200.f;
	Sprite controllsText;

	Sprite finishText;
	Sprite gameOverText;

	Sprite startCountdown1;
	Sprite startCountdown2;
	Sprite startCountdown3;

	void textImageInit() {
		float red[] = { 0,0,0 };

		controllsText.SetWidth(200.f);
		controllsText.SetHeight(200.f);
		controllsText.Init(shader, red, "textures/Controlls2.png", 1, 1);

		startCountdown1.SetWidth(200.f);
		startCountdown1.SetHeight(200.f);
		startCountdown1.Init(shader, red, "textures/number1.png", 1, 1);
		startCountdown2.SetWidth(200.f);
		startCountdown2.SetHeight(200.f);
		startCountdown2.Init(shader, red, "textures/number2.png", 1, 1);
		startCountdown3.SetWidth(200.f);
		startCountdown3.SetHeight(200.f);
		startCountdown3.Init(shader, red, "textures/number3.png", 1, 1);

		finishText.SetWidth(200.f);
		finishText.SetHeight(200.f);
		finishText.Init(shader, red, "textures/gameOver.png", 1, 1);

		gameOverText.SetWidth(200.f);
		gameOverText.SetHeight(200.f);
		gameOverText.Init(shader, red, "textures/gameOver.png", 1, 1);
	}
};