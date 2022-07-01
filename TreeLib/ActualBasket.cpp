#include "pch.h"
#include "ActualBasket.h"
#include "TreeImage.h"

using namespace std;
using namespace Gdiplus;

CActualBasket::CActualBasket()
{
	mFullImage = make_shared<CTreeImage>(L"images/basket.png");
	mFrontBasket = make_shared<CTreeImage>(L"images/basket-front.png");
}

void CActualBasket::SetBasketLocation(int x, int y)
{
	mPosition = PointF(float(x), float(y));
}

void CActualBasket::DrawBasket(Gdiplus::Graphics* graphics)
{
	mFullImage->DrawStaticImage(graphics, mPosition, 0.0);
}

void CActualBasket::AddToBasket(std::vector<std::shared_ptr<CFruit>> fruit)
{
}

void CActualBasket::EmptyBasket()
{
}
