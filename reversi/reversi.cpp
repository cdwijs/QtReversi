﻿#include "reversi.h"
#include "board.h"
#include "human.h"

bool Reversi::waiting_human_input = false;

Reversi::Reversi()
{
	Initialize();
	return;
}

Reversi::~Reversi()
{

}

void Reversi::Initialize()
{
	board_ = new Board();
	player_list_.push_back(new Human(STONE_COLOR::BLACK));
	player_list_.push_back(new Human(STONE_COLOR::WHITE));

	// create player loop: black->white->black->white->...
	for (vector<Player*>::iterator i = player_list_.begin(); i != player_list_.end() - 1; i++)
		(*i)->SetNextPlayer(*(i + 1));
	(*(player_list_.end() - 1))->SetNextPlayer(*player_list_.begin());

	now_player_ = *player_list_.begin();
}

//call before player input
void Reversi::PreProcess()
{
	now_player_->AskPutStonePosition();	// Ask player about put position
	return;
}

// call after player input
void Reversi::PostProcess(Vec2d put_pos)
{
	// put & reverse
	board_->PutStone(put_pos, now_player_->GetPlayerColor());
	now_player_ = now_player_->GetNextPlayer();
	return;
}

Board* Reversi::GetBoardPtr()
{
	return board_;
}

void Reversi::SetWaitingFlag(bool flag)
{
	waiting_human_input = flag;
	return;
}
