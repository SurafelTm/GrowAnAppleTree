#include "pch.h"
#include "TreeImageDrawable.h"
#include "TreeImage.h"
#include "ActualTree.h"

CTreeImageDrawable::CTreeImageDrawable(CActualTree* tree, int depth, std::shared_ptr<CTreeImage> image):
	CTreePartsDrawable(tree, depth), mImage(image)
{
}

void CTreeImageDrawable::Draw(Gdiplus::Graphics* graphics)
{
	mImage->Draw(graphics, mPlacedR, mSize, mPlacedPosition.X, mPlacedPosition.Y, mAngleOffset);
}
