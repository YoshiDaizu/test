#pragma once
#include "lib/framework.hpp"
//�^�C�g����ʁF�S���@�v�ۓc�A�O��

//�Ց�̃}�X���Ƃ��̃}�X�̃T�C�Y����ы�̃T�C�Y
enum Map{
	MAP_HEIGHT = 8,				//�}�b�v�̏c�̃}�X��
	MAP_WIDTH = 8,				//�}�b�v�̉��̃}�X��
	BLOCK_SIZE = 75,			//�}�X�̃T�C�Y
	PIECE_SIZE = 30				//��̃T�C�Y
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

//�Q�[���{�҂̏���
class Game{

private:
	//�����ɂ̓e�N�X�`���[�ȂǁA�ォ��ς��Ȃ����̂̐錾�H������B
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
	//�����ɂ͏������čs�����̂����Ă����B
	//�N���X�̃C���X�^���X���H
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