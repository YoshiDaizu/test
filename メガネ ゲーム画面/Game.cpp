#pragma once
#include "Game.h"
#include "singleton.h"
#include "lib/framework.hpp"
//ゲーム画面：担当　久保田、三井

//画像や文字などをここに入れる。
Game::Game()
{
	//背景
	GameBackground = Texture("res/haikei.png");
	//メニュー
	GameList = Texture("res/menu.png");
	//

	//説明画面で使用する画像
	rule[Rule::FIFTHDRAW] = Texture("res/rules.png");
	rule[Rule::SECONDDRAW] = Texture("res/rules1.png");
	rule[Rule::THIRDDRAW] = Texture("res/rules2.png");
	rule[Rule::FOURTHDRAW] = Texture("res/rules3.png");
	rule[Rule::FIFTHDRAW] = Texture("res/rules4.png");

	//キャラクターがしゃべる時に下に出る吹き出しの画像
	balloon[Balloon::NORMAL_BALLOON] = Texture("res/balloon_normal.png");
	balloon[Balloon::PLEASURE_BALLOON] = Texture("res/balloon_pleasure.png");
	balloon[Balloon::SURPRISE_BALLOON] = Texture("res/balloon_surprise.png");
	balloon[Balloon::MAKEKAKU_BALLOON] = Texture("res/balloon_makekaku.png");
	balloon[Balloon::KATIKAKU_BALLOON] = Texture("res/balloon_katikaku.png");


	//キャラクターの背景
	character_background[Character_bg::NORMAL_BG] = Texture("res/bg_normal.png");
	character_background[Character_bg::PLEASURE_BG] = Texture("res/bg_pleasure.png");
	character_background[Character_bg::SURPRISE_BG] = Texture("res/bg_surprise.png");
	character_background[Character_bg::MAKEKAKU_BG] = Texture("res/bg_makekaku.png");
	character_background[Character_bg::KATIKAKU_BG] = Texture("res/bg_katikaku.png");

	//小鳥（自分）の画像
	kotori[Kotori::NORMAL] = Texture("res/Normal.png");			//通常時
	kotori[Kotori::PLEASURE] = Texture("res/Pleasure.png");		//敵の駒を取った時
	kotori[Kotori::SURPRISE] = Texture("res/Surprise.png");		//敵に駒を取られた時
	kotori[Kotori::MAKEKAKU] = Texture("res/makekaku.png");		//負けそうな時
	kotori[Kotori::KATIKAKU] = Texture("res/katikaku.png");		//勝てそうな時

	//有紗（敵）の画像
	arisa[Arisa::A_NORMAL] = Texture("res/secondplayer_Normal.png");		//通常時
	arisa[Arisa::A_PLEASURE] = Texture("res/secondplayer_Pleasure.png");	//敵の駒を取った時
	arisa[Arisa::A_SURPRISE] = Texture("res/secondplayer_Surprise.png");	//敵に駒を取られた時
	arisa[Arisa::A_MAKEKAKU] = Texture("res/secondplayer_makekaku.png");	//負けそうな時
	arisa[Arisa::A_KATIKAKU] = Texture("res/secondplayer_katikaku.png");	//勝てそうな時


	//音楽
	Crick = Media("res/crick.wav");					//クリック音
	GameBackSound = Media("res/Game.wav");			//本編のバックソング
	Menu = Media("res/Menu.wav");					//メニューのバックソング
	PieceMoved = Media("res/PieceMoved.wav");		//駒を動かすときの音
	PieceMoving = Media("res/PieceMoving.wav");		//駒を動かした後の音

}

//ここには処理するもの（計算や判定など）を基本的には入れていく。
void Game::Setup()
{
	//.txtのファイルをステージとして描画する
	std::ifstream* Mapfile = nullptr;

	const char* NewStage = "res/Stage.txt";

	Mapfile = new std::ifstream(NewStage);

	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int k = 0; k < MAP_WIDTH; k++)
		{
			*Mapfile >> Stage[i][k];
		}
	}

	

}

void Game::Update()
{

}

//ここには画面上に描画するものを基本的には入れていく。
void Game::Draw()
{
	//背景
	drawTextureBox(-500, -500, 1000, 1000, 0, 0, 512, 512, GameBackground);

	//小鳥（自分のキャラ）の描画をスイッチで切り替えれるようにした
	switch (MyCharacter)
	{
	case 0:
		//ふきだし
		drawTextureBox(250, -500, -750, 200, 0, 0, 256, 256, balloon[Balloon::NORMAL_BALLOON]);
		//キャラクター背景
		drawTextureBox(250, -530, 256, 256, 0, 0, 256, 256, character_background[Character_bg::NORMAL_BG]);
		//キャラクター描画
		drawTextureBox(250, -530, 256, 256, 0, 0, 256, 256, kotori[Kotori::NORMAL]);
		break;

	case 1:
		drawTextureBox(250, -500, -750, 200, 0, 0, 256, 256, balloon[Balloon::PLEASURE_BALLOON]);
		drawTextureBox(250, -530, 256, 256, 0, 0, 512, 512, character_background[Character_bg::PLEASURE_BG]);
		drawTextureBox(250, -500, 256, 256, 0, 0, 256, 256, kotori[Kotori::PLEASURE]);
		break;

	case 2:
		drawTextureBox(250, -500, -750, 200, 0, 0, 256, 256, balloon[Balloon::SURPRISE_BALLOON]);
		drawTextureBox(250, -530, 256, 256, 0, 0, 512, 512, character_background[Character_bg::SURPRISE_BG]);
		drawTextureBox(250, -500, 256, 256, 0, 0, 256, 256, kotori[Kotori::SURPRISE]);
		break;

	case 3:
		drawTextureBox(250, -500, -750, 200, 0, 0, 256, 256, balloon[Balloon::MAKEKAKU_BALLOON]);
		drawTextureBox(250, -530, 256, 256, 0, 0, 512, 512, character_background[Character_bg::MAKEKAKU_BG]);
		drawTextureBox(250, -500, 256, 256, 0, 0, 256, 256, kotori[Kotori::MAKEKAKU]);
		break;

	case 4:
		drawTextureBox(250, -500, -750, 200, 0, 0, 256, 256, balloon[Balloon::KATIKAKU_BALLOON]);
		drawTextureBox(250, -530, 256, 256, 0, 0, 512, 512, character_background[Character_bg::KATIKAKU_BG]);
		drawTextureBox(250, -500, 256, 256, 0, 0, 256, 256, kotori[Kotori::KATIKAKU]);
		break;

	}

	//有紗（敵キャラ）の描画をスイッチで切り替えれるようにした
	switch (Enemy)
	{
	case 0:
		drawTextureBox(-250, 300, 750, 200, 0, 0, 256, 256, balloon[Balloon::NORMAL_BALLOON]);
		drawTextureBox(-250, 270, -256, 256, 0, 0, 256, 256, character_background[Character_bg::NORMAL_BG]);
		drawTextureBox(-250, 270, -256, 256, 0, 0, 256, 256, arisa[Arisa::A_NORMAL]);
		break;

	case 1:
		drawTextureBox(-250, 300, 750, 200, 0, 0, 256, 256, balloon[Balloon::PLEASURE_BALLOON]);
		drawTextureBox(-250, 270, -256, 256, 0, 0, 512, 512, character_background[Character_bg::PLEASURE_BG]);
		drawTextureBox(-250, 270, -256, 256, 0, 0, 256, 256, arisa[Arisa::A_PLEASURE]);
		break;

	case 2:
		drawTextureBox(-250, 300, 750, 200, 0, 0, 256, 256, balloon[Balloon::SURPRISE_BALLOON]);
		drawTextureBox(-250, 270, -256, 256, 0, 0, 512, 512, character_background[Character_bg::SURPRISE_BG]);
		drawTextureBox(-250, 270, -256, 256, 0, 0, 256, 256, arisa[Arisa::A_SURPRISE]);
		break;

	case 3:
		drawTextureBox(-250, 300, 750, 200, 0, 0, 256, 256, balloon[Balloon::MAKEKAKU_BALLOON]);
		drawTextureBox(-250, 270, -256, 256, 0, 0, 512, 512, character_background[Character_bg::MAKEKAKU_BG]);
		drawTextureBox(-250, 270, -256, 256, 0, 0, 256, 256, arisa[Arisa::A_MAKEKAKU]);
		break;

	case 4:
		drawTextureBox(-250, 300, 750, 200, 0, 0, 256, 256, balloon[Balloon::KATIKAKU_BALLOON]);
		drawTextureBox(-250, 270, -256, 256, 0, 0, 512, 512, character_background[Character_bg::KATIKAKU_BG]);
		drawTextureBox(-250, 270, -256, 256, 0, 0, 256, 256, arisa[Arisa::A_KATIKAKU]);
		break;
	}



	//盤上をfor文で回して描画
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int k = 0; k < MAP_WIDTH; k++)
		{
			Vec2f MapPos = Vec2f(BLOCK_SIZE * k, BLOCK_SIZE * -i) - Mpos;

			switch (Stage[i][k])
			{
			case 0://動けないマス
				drawFillBox(MapPos.x(), MapPos.y(), BLOCK_SIZE, BLOCK_SIZE, Color::maroon);
				break;

			case 1://動けるマス
				drawFillBox(MapPos.x(), MapPos.y(), BLOCK_SIZE, BLOCK_SIZE, Color::olive);
				break;

			case 2://自分の駒がいるマス
				drawFillBox(MapPos.x(), MapPos.y(), BLOCK_SIZE, BLOCK_SIZE, Color::olive);
				drawFillCircle(MapPos.x() + 38, MapPos.y() + 37, PIECE_SIZE, PIECE_SIZE, 100, Color::blue);
				break;

			case 3://敵の駒がいるマス
				drawFillBox(MapPos.x(), MapPos.y(), BLOCK_SIZE, BLOCK_SIZE, Color::olive);
				drawFillCircle(MapPos.x() + 38, MapPos.y() + 37, PIECE_SIZE, PIECE_SIZE, 100, Color::red);
				break;
			}
		}
	}



	//枠
	drawLine(-500, 295, 500, 295, 3, Color::black);
	drawLine(-500, -305, 500, -305, 3, Color::black);
	drawLine(98, 295, 98, -305, 3, Color::black);
	//キャラの縦線
	drawLine(-250, 500, -250, 295, 3, Color::black);
	drawLine(250, -500, 250, -305, 3, Color::black);
}

void Game::GameMenu()
{
	//メニュー
	drawTextureBox(100, -305, 400, 600, 0, 0, 512, 512, GameList);



}