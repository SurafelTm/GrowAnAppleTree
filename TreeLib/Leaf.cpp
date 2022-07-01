/**
 * \file Leaf.cpp
 *
 * \author Amanuel
 */

#include "pch.h"
#include "Leaf.h"
#include "ActualTree.h"

CLeaf::CLeaf(CActualTree* tree, int depth) :
	CTreeImageDrawable(tree, depth, tree->GetLeaf())
{
	SetAngleOffset(PI / 2);
}

void CLeaf::Grow(int frameRate)
{
	double growRate = GetTree()->GetGrowRate();
	SetSize(GetSize() * growRate);
}
