#pragma once
#include <memory>
#include <string>


/**
 * Class that represents an image used by our system.
 */
class CTreeImage
{
public:
	CTreeImage(const std::wstring name);

	/// Default constructor/disabled
	CTreeImage() = delete;

	/// Copy constructor/disabled
	CTreeImage(const CTreeImage&) = delete;

	/// Destructor
	virtual ~CTreeImage() {}

	void Draw(Gdiplus::Graphics* graphics, double angle, double scale, double x, double y, double angleOffset);

	void DrawStaticImage(Gdiplus::Graphics* graphics, Gdiplus::PointF position, double angle);

private:
	std::shared_ptr<Gdiplus::Bitmap> mImage; ///< The part image

};