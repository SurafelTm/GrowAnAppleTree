#include "pch.h"
#include "TreePartsDrawable.h"

using namespace Gdiplus;

/**
 * Place this drawable relative to its parent
 *
 * This works hierarchically from top item down.
 * \param offset Parent offset
 * \param rotate Parent rotation
 */
void CTreePartsDrawable::Place(Gdiplus::PointF offset, double rotate)
{
	// Combine the transformation we are given with the transformation
	// for this object.
	mPlacedPosition = !mParent ? offset + mLocation : offset;
	mPlacedR = mAngle + rotate;
}


/** Rotate a point by a given angle.
* \param point The point to rotate
* \param angle An angle in radians
* \returns Rotated point
*/
Gdiplus::PointF CTreePartsDrawable::RotatePoint(Gdiplus::PointF point, double angle)
{
	double cosA = cos(angle);
	double sinA = sin(angle);

	return Gdiplus::PointF(REAL(cosA * point.X + sinA * point.Y),
		REAL(-sinA * point.X + cosA * point.Y));
}
