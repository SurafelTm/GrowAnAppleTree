/**
 * \file ActualFruit.cpp
 *
 * \author Amanuel
 */

#include "pch.h"
#include "ActualFruit.h"
#include "ActualTree.h"


CActualFruit::CActualFruit(CActualTree* tree, int depth) : CTreeImageDrawable(tree, depth, tree->GetFruit())
{
	SetAngleOffset(-PI / 2);
}

void CActualFruit::Grow(int frameRate)
{
	SetSize(GetSize() * GetTree()->GetGrowRate());
}

void CActualFruit::Place(Gdiplus::PointF offset, double rotate)
{
	mPlacedPosition = offset;
	mPlacedR = 0.0;
}

void CActualFruit::SetBasketPosition(int x, int y)
{
}

void CActualFruit::DrawInBasket(Gdiplus::Graphics* graphics, int x, int y)
{
}
