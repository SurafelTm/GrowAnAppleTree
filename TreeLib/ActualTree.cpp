#include "pch.h"
#include "ActualTree.h"
#include "Fruit.h"
#include "TreePartsDrawable.h"
#include "ActualFruit.h"
#include "Limb.h"
#include "FruitVisitor.h"

using namespace std;
using namespace Gdiplus;

const double GrowthRate = 0.4;


CActualTree::CActualTree()
{
	mRoot = make_shared<CLimb>(this, 1);
	mLeaf = make_shared<CTreeImage>(L"images/leaf3.png");
	mFruit = make_shared<CTreeImage>(L"images/orange.png");
}

void CActualTree::SetRootLocation(int x, int y)
{
	mRoot->SetPosition(PointF(float(x), float(y)));
	mLocation = PointF(float(x), float(y));
}

void CActualTree::DrawTree(Gdiplus::Graphics* graphics)
{
	mRoot->Place(PointF(0.0, 0.0), -PI / 2 + mAngleOffset);
	mRoot->Draw(graphics);
}

void CActualTree::SetTreeFrame(int frame)
{
	if (frame < mCurrentFrame)
	{
		Reset();
	}

	while (mCurrentFrame < frame) {
		mCurrentFrame++;
		mRoot->Grow(frame);    // Grow by one frame
	}
}

void CActualTree::SetWindSpeed(double speed)
{
	if (speed > mWindSpeed)
	{
		mAngleOffset += PI / 8;
	}
	else if (speed < mWindSpeed)
	{
		mAngleOffset -= PI / 8;
	}
	else
	{
		mAngleOffset = 0.0;
	}
	mWindSpeed = speed;
}

void CActualTree::SetSeed(int seed)
{
	mSeed = seed;
	mRandom.Seed(mSeed);
	SetTreeFrame(mCurrentFrame);
}

int CActualTree::GetSeed()
{
	return mSeed;
}

std::vector<std::shared_ptr<CFruit>> CActualTree::Harvest()
{
	mHarvestedFruits.clear();
	for (auto fruit : mTreeFruits)
	{
		mHarvestedFruits.push_back(fruit);
		fruit->GetParent()->PluckFruit(fruit);
	}
	mTreeFruits.clear();
	return mHarvestedFruits;
}

double CActualTree::GetGrowRate() const
{
	double delta = 1.0 / mFrameRate;
	return pow((1.0 + GrowthRate), delta);
}

void CActualTree::Reset()
{
	mRoot = make_shared<CLimb>(this, 1);
	mRoot->SetPosition(mLocation);
	mRandom.Reset();
	mCurrentFrame = 0;
}

void CActualTree::AddPart(std::shared_ptr<CTreePartsDrawable> part)
{
	mTreeParts.push_back(part);
}

void CActualTree::AddFruit(std::shared_ptr<CActualFruit> fruit)
{
	mTreeFruits.push_back(fruit);
}

void CActualTree::Accept(CTreeVisitor* visitor)
{
	for (auto part : mTreeParts)
	{
		part->Accept(visitor);
	}
}


