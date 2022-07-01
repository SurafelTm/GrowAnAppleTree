/**
 * \file Limb.cpp
 *
 * \author Amanuel
 */

#include "pch.h"
#include "Limb.h"
#include "ActualTree.h"
#include "Leaf.h"
#include "ActualFruit.h"

using namespace Gdiplus;
using namespace std;


/// starting width
const double StartingWidth = 1.0;

/// starting height
const double StartingHeight = 5.0;

CLimb::CLimb(CActualTree* tree, int depth) : CTreePartsDrawable(tree, depth), mWidth(StartingWidth), mHeight(StartingHeight)
{
}

void CLimb::Draw(Gdiplus::Graphics* graphics)
{
	float x = mPlacedPosition.X;
	float y = mPlacedPosition.Y;
	
	Pen pen(Color(139, 69, 19), (REAL)mWidth);
	pen.SetEndCap(LineCapRound);
	graphics->DrawLine(&pen, (REAL)x, (REAL)y,
		(REAL)(GetEndPoint().X), (REAL)(GetEndPoint().Y));
	for (auto part : mChildren)
	{
		part->Draw(graphics);
	}
}

void CLimb::Grow(int frameRate)
{
	double growRate = GetTree()->GetGrowRate();
	mHeight *= growRate;
	mWidth *= growRate;

	if (!mHasSpawned && mHeight > mSpawningLength)
	{
		Spawn();
		/*auto random = GetTree()->GetRandomGenerator();
		auto leaf = make_shared<CLeaf>(GetTree(), GetDepth() + 1);
		leaf->SetAngle(random->Random(-0.2, 0.2));
		AddChild(leaf);*/
		mHasSpawned = true;
	}

	for (auto part : mChildren)
	{
		part->Grow(frameRate);
	}
	
}

void CLimb::AddChild(std::shared_ptr<CTreePartsDrawable> part)
{
	mChildren.push_back(part);
	part->SetParentLimb(this);
	GetTree()->AddPart(part);
}

void CLimb::Place(Gdiplus::PointF offset, double rotate)
{
	CTreePartsDrawable::Place(offset, rotate);
	// Update our children
	for (auto part : mChildren)
	{
		part->Place(GetEndPoint(), mPlacedR);
	}
}

Gdiplus::PointF CLimb::GetEndPoint() const
{
	float x = mPlacedPosition.X;
	float y = mPlacedPosition.Y;
	double dx = cos(mPlacedR) * mHeight;
	double dy = sin(mPlacedR) * mHeight;

	return Gdiplus::PointF(REAL(x+dx), REAL(y+dy));
}

void CLimb::PluckFruit(std::shared_ptr<CActualFruit> fruit)
{
	auto loc = find(mChildren.begin(), mChildren.end(), fruit);
	mChildren.erase(loc);
}

void CLimb::Spawn()
{
	auto random = GetTree()->GetRandomGenerator();
	if (GetDepth() > 6 && random->Random(0, 1) < 0.7)
	{
		auto leaf = make_shared<CLeaf>(GetTree(), GetDepth()+1);
		leaf->SetAngle(random->Random(-0.2, 0.2));
		AddChild(leaf);
	}
	else
	{
		auto limb = make_shared<CLimb>(GetTree(), GetDepth() + 1);
		limb->SetAngle(random->Random(-0.2, 0.2));
		AddChild(limb);
	}

	/*if (GetDepth() > 8 && random->Random(0, 1) < 0.1)
	{
		auto fruit = make_shared<CActualFruit>(GetTree(), GetDepth() + 1);
		fruit->SetAngle(random->Random(-0.2, 0.2));
		AddChild(fruit);
	}
	else
	{
		auto limb = make_shared<CLimb>(GetTree(), GetDepth() + 1);
		limb->SetAngle(random->Random(-1.5, 1.5));
		AddChild(limb);
	}*/
	if (GetDepth() > 10)
	{
		if (random->Random(0, 1) < 0.1)
		{
			auto fruit = make_shared<CActualFruit>(GetTree(), GetDepth() + 1);
			fruit->SetSelf(fruit);
			fruit->SetAngle(random->Random(-0.2, 0.2));
			GetTree()->AddFruit(fruit);
			AddChild(fruit);
		}
		else
		{
			auto limb = make_shared<CLimb>(GetTree(), GetDepth() + 1);
			limb->SetAngle(random->Random(-1.5, 1.5));
			AddChild(limb);
		}
		
	}
	else
	{
		auto limb = make_shared<CLimb>(GetTree(), GetDepth() + 1);
		limb->SetAngle(random->Random(-1.5, 1.5));
		AddChild(limb);
	}
}
