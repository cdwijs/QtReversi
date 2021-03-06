﻿#include "cell.h"
#include "stone.h"

Cell::Cell(CELL_STATE state)
{
    cell_state_ = state;
    stone_ = nullptr;
    return;
}

void Cell::SetStone(STONE_COLOR color)
{
    stone_ = new Stone(color);
    cell_state_ = CELL_STATE::STONE;
    return;
}

CELL_STATE Cell::GetCellState()
{
    return cell_state_;
}

STONE_COLOR Cell::GetStoneColor()
{
    return stone_->GetStoneColor();
}
