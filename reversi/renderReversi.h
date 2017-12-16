﻿#pragma once
#include <string>
#include <map>
#include "reversi.h"
#include "stone.h"

using namespace std;
class QGraphicsScene;
class QGraphicsTextItem;

class RenderReversi
{
private:
	const unsigned int kCellSize;

	QGraphicsScene* scene_;
	Reversi* reversi_;
	Vec2d render_pos_;
	Vec2d render_board_size_;

	QGraphicsTextItem* PaintText(string str, unsigned int pos_x, unsigned int pos_y);

	void PaintStone(pair<unsigned int, unsigned int> pos, STONE_COLOR color);
	void AddOutline(pair<unsigned int, unsigned int> board_size);
	void PaintBoard(Board* board);
	void PaintPlayerInfo(Player * player);
	void PaintGameResult(JudgeResult result);
	void PaintStoneCount(map<STONE_COLOR, unsigned int> stone_cnt_map);

public:
	RenderReversi(QGraphicsScene* scene, Reversi* reversi, Vec2d render_pos);
	void Rendering();

};