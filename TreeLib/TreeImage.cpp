#include "pch.h"
#include "TreeImage.h"

using namespace std;
using namespace Gdiplus;

/// Constant ratio to convert radians to degrees
const double RtoD = 57.295779513;

CTreeImage::CTreeImage(const std::wstring name)
{
	mImage = shared_ptr<Bitmap>(Bitmap::FromFile(name.c_str()));
	if (mImage->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += name;
		AfxMessageBox(msg.c_str());
	}
}

void CTreeImage::Draw(Gdiplus::Graphics* graphics, double angle, double scale, double x, double y, double angleOffset)
{
	angle = angle + angleOffset;
	auto state = graphics->Save();
	graphics->TranslateTransform((float)x, (float)y);
	graphics->RotateTransform((float)(angle * RtoD));
	graphics->ScaleTransform((float)scale, (float)scale);
	graphics->DrawImage(mImage.get(), -(int)mImage->GetWidth() / 2,
		-(int)mImage->GetHeight(),
		mImage->GetWidth(), mImage->GetHeight());
	graphics->Restore(state);
}

void CTreeImage::DrawStaticImage(Gdiplus::Graphics* graphics, PointF position, double angle)
{
	auto state = graphics->Save();
	graphics->TranslateTransform((float)position.X, (float)position.Y);
	graphics->RotateTransform((float)(-angle * RtoD));
	graphics->DrawImage(mImage.get(), -(int)mImage->GetWidth() / 2, -(int)mImage->GetHeight(),
		mImage->GetWidth(), mImage->GetHeight());
	graphics->Restore(state);
}
