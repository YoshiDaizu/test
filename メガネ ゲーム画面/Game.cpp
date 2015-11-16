#pragma once
#include "Game.h"
#include "singleton.h"
#include "lib/framework.hpp"
//�Q�[����ʁF�S���@�v�ۓc�A�O��

//�摜�╶���Ȃǂ������ɓ����B
Game::Game()
{
	//�w�i
	GameBackground = Texture("res/haikei.png");
	//���j���[
	GameList = Texture("res/menu.png");
	//

	//������ʂŎg�p����摜
	rule[Rule::FIFTHDRAW] = Texture("res/rules.png");
	rule[Rule::SECONDDRAW] = Texture("res/rules1.png");
	rule[Rule::THIRDDRAW] = Texture("res/rules2.png");
	rule[Rule::FOURTHDRAW] = Texture("res/rules3.png");
	rule[Rule::FIFTHDRAW] = Texture("res/rules4.png");

	//�L�����N�^�[������ׂ鎞�ɉ��ɏo�鐁���o���̉摜
	balloon[Balloon::NORMAL_BALLOON] = Texture("res/balloon_normal.png");
	balloon[Balloon::PLEASURE_BALLOON] = Texture("res/balloon_pleasure.png");
	balloon[Balloon::SURPRISE_BALLOON] = Texture("res/balloon_surprise.png");
	balloon[Balloon::MAKEKAKU_BALLOON] = Texture("res/balloon_makekaku.png");
	balloon[Balloon::KATIKAKU_BALLOON] = Texture("res/balloon_katikaku.png");


	//�L�����N�^�[�̔w�i
	character_background[Character_bg::NORMAL_BG] = Texture("res/bg_normal.png");
	character_background[Character_bg::PLEASURE_BG] = Texture("res/bg_pleasure.png");
	character_background[Character_bg::SURPRISE_BG] = Texture("res/bg_surprise.png");
	character_background[Character_bg::MAKEKAKU_BG] = Texture("res/bg_makekaku.png");
	character_background[Character_bg::KATIKAKU_BG] = Texture("res/bg_katikaku.png");

	//�����i�����j�̉摜
	kotori[Kotori::NORMAL] = Texture("res/Normal.png");			//�ʏ펞
	kotori[Kotori::PLEASURE] = Texture("res/Pleasure.png");		//�G�̋���������
	kotori[Kotori::SURPRISE] = Texture("res/Surprise.png");		//�G�ɋ�����ꂽ��
	kotori[Kotori::MAKEKAKU] = Texture("res/makekaku.png");		//���������Ȏ�
	kotori[Kotori::KATIKAKU] = Texture("res/katikaku.png");		//���Ă����Ȏ�

	//�L�сi�G�j�̉摜
	arisa[Arisa::A_NORMAL] = Texture("res/secondplayer_Normal.png");		//�ʏ펞
	arisa[Arisa::A_PLEASURE] = Texture("res/secondplayer_Pleasure.png");	//�G�̋���������
	arisa[Arisa::A_SURPRISE] = Texture("res/secondplayer_Surprise.png");	//�G�ɋ�����ꂽ��
	arisa[Arisa::A_MAKEKAKU] = Texture("res/secondplayer_makekaku.png");	//���������Ȏ�
	arisa[Arisa::A_KATIKAKU] = Texture("res/secondplayer_katikaku.png");	//���Ă����Ȏ�


	//���y
	Crick = Media("res/crick.wav");					//�N���b�N��
	GameBackSound = Media("res/Game.wav");			//�{�҂̃o�b�N�\���O
	Menu = Media("res/Menu.wav");					//���j���[�̃o�b�N�\���O
	PieceMoved = Media("res/PieceMoved.wav");		//��𓮂����Ƃ��̉�
	PieceMoving = Media("res/PieceMoving.wav");		//��𓮂�������̉�

}

//�����ɂ͏���������́i�v�Z�┻��Ȃǁj����{�I�ɂ͓���Ă����B
void Game::Setup()
{
	//.txt�̃t�@�C�����X�e�[�W�Ƃ��ĕ`�悷��
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

//�����ɂ͉�ʏ�ɕ`�悷����̂���{�I�ɂ͓���Ă����B
void Game::Draw()
{
	//�w�i
	drawTextureBox(-500, -500, 1000, 1000, 0, 0, 512, 512, GameBackground);

	//�����i�����̃L�����j�̕`����X�C�b�`�Ő؂�ւ����悤�ɂ���
	switch (MyCharacter)
	{
	case 0:
		//�ӂ�����
		drawTextureBox(250, -500, -750, 200, 0, 0, 256, 256, balloon[Balloon::NORMAL_BALLOON]);
		//�L�����N�^�[�w�i
		drawTextureBox(250, -530, 256, 256, 0, 0, 256, 256, character_background[Character_bg::NORMAL_BG]);
		//�L�����N�^�[�`��
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

	//�L�сi�G�L�����j�̕`����X�C�b�`�Ő؂�ւ����悤�ɂ���
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



	//�Տ��for���ŉ񂵂ĕ`��
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int k = 0; k < MAP_WIDTH; k++)
		{
			Vec2f MapPos = Vec2f(BLOCK_SIZE * k, BLOCK_SIZE * -i) - Mpos;

			switch (Stage[i][k])
			{
			case 0://�����Ȃ��}�X
				drawFillBox(MapPos.x(), MapPos.y(), BLOCK_SIZE, BLOCK_SIZE, Color::maroon);
				break;

			case 1://������}�X
				drawFillBox(MapPos.x(), MapPos.y(), BLOCK_SIZE, BLOCK_SIZE, Color::olive);
				break;

			case 2://�����̋����}�X
				drawFillBox(MapPos.x(), MapPos.y(), BLOCK_SIZE, BLOCK_SIZE, Color::olive);
				drawFillCircle(MapPos.x() + 38, MapPos.y() + 37, PIECE_SIZE, PIECE_SIZE, 100, Color::blue);
				break;

			case 3://�G�̋����}�X
				drawFillBox(MapPos.x(), MapPos.y(), BLOCK_SIZE, BLOCK_SIZE, Color::olive);
				drawFillCircle(MapPos.x() + 38, MapPos.y() + 37, PIECE_SIZE, PIECE_SIZE, 100, Color::red);
				break;
			}
		}
	}



	//�g
	drawLine(-500, 295, 500, 295, 3, Color::black);
	drawLine(-500, -305, 500, -305, 3, Color::black);
	drawLine(98, 295, 98, -305, 3, Color::black);
	//�L�����̏c��
	drawLine(-250, 500, -250, 295, 3, Color::black);
	drawLine(250, -500, 250, -305, 3, Color::black);
}

void Game::GameMenu()
{
	//���j���[
	drawTextureBox(100, -305, 400, 600, 0, 0, 512, 512, GameList);



}