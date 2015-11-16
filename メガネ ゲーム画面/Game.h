#pragma once
#include "lib/framework.hpp"
//タイトル画面：担当　久保田、三井

//盤台のマス数とそのマスのサイズおよび駒のサイズ
enum Map{
	MAP_HEIGHT = 8,				//マップの縦のマス数
	MAP_WIDTH = 8,				//マップの横のマス数
	BLOCK_SIZE = 75,			//マスのサイズ
	PIECE_SIZE = 30				//駒のサイズ
};


enum Balloon{
	NORMAL_BALLOON,
	PLEASURE_BALLOON,
	SURPRISE_BALLOON,
	MAKEKAKU_BALLOON,
	KATIKAKU_BALLOON
};


enum Character_bg{
	NORMAL_BG,
	PLEASURE_BG,
	SURPRISE_BG,
	MAKEKAKU_BG,
	KATIKAKU_BG
};

enum Kotori{
	NORMAL,
	PLEASURE,
	SURPRISE,
	MAKEKAKU,
	KATIKAKU
};

enum Arisa{
	A_NORMAL,
	A_PLEASURE,
	A_SURPRISE,
	A_MAKEKAKU,
	A_KATIKAKU
};

enum Rule
{
	FIRSTDRAW,
	SECONDDRAW,
	THIRDDRAW,
	FOURTHDRAW,
	FIFTHDRAW
};

//ゲーム本編の処理
class Game{

private:
	//ここにはテクスチャーなど、後から変えないものの宣言？をする。
	//Font GameFont = ("res/meiryo.ttc");

	Texture GameBackground;
	Texture GameList;
	
	Texture rule[5];
	Texture balloon[5];
	Texture character_background[5];
	Texture kotori[5];
	Texture arisa[5];

	Media Crick;
	Media GameBackSound;
	Media Menu;
	
	Media PieceMoved;
	Media PieceMoving;

public:
	//ここには処理して行くものを入れていく。
	//クラスのインスタンス化？
	Game();
	
	Vec2f Mpos = Vec2f(500, -220);

	void Setup();
	void Update();
	void Draw();
	void GameMenu();
	int Stage[MAP_HEIGHT][MAP_WIDTH];
	int MyCharacter = 0;
	int Enemy = 0;
};