/**
 * \file TreePartsDrawable.h
 *
 * \author Amanuel
 *
 * 
 */

#pragma once
#include "TreeVisitor.h"

class CActualTree;
class CLimb;

const double PI = 3.14159265359;

/**
* A class to describe tree parts
*/
class CTreePartsDrawable
{
	public:
		/// virtual destructor
		virtual ~CTreePartsDrawable() {}

		/// Copy constructor/disabled
		CTreePartsDrawable(const CTreePartsDrawable&) = delete;

		/// Assignment operator/disabled
		void operator=(const CTreePartsDrawable&) = delete;

		/// get tree
		/// \return tree
		CActualTree* GetTree() { return mTree; }

		/// set parent limb
		/// \param limb
		void SetParentLimb(CLimb* limb) { mParent = limb; }

		/// get parent
		/// \return limb
		CLimb* GetParent() { return mParent; }
		/** 
		* Draw the drawable
		* \param graphics Graphics object to draw on 
		*/
		virtual void Draw(Gdiplus::Graphics* graphics) = 0;

		/**
		* grow the part
		* \param frameRate
		*/
		virtual void Grow(int frameRate) = 0;

		/** Set the angle relative to parent in radians
		* \param r angle in radians*/
		void SetAngle(double r) { mAngle = r; }

		/** Get the angle relative to parent in radians
		* \returns The angle in radians*/
		double GetAngle() const { return mAngle; }

		/** Set the drawable position
		* \param pos The new drawable position*/
		void SetPosition(Gdiplus::PointF pos) { mLocation = pos; }

		/** Get the drawable position
		 * \returns The drawable position*/
		Gdiplus::PointF GetPosition() const { return mLocation; }

		/// set depth
		/// \param depth
		void SetDepth(int depth) { mDepth = depth; }

		/// get depth
		/// \return depth
		int GetDepth() { return mDepth; }

		/**
		* place part relative to parent
		* \param offset
		* \param rotate
		*/
		virtual void Place(Gdiplus::PointF offset, double rotate);


		/// accept visitor
		virtual void Accept(CTreeVisitor* visitor) = 0;

	protected:
		/// constructor
		CTreePartsDrawable(CActualTree* tree, int depth) : mTree(tree), mDepth(depth) {}

		/**
		* Rotate point
		* \param point
		* \param angle
		* \return point
		*/
		Gdiplus::PointF RotatePoint(Gdiplus::PointF point, double angle);

		/// The actual postion in the drawing
		Gdiplus::PointF mPlacedPosition = Gdiplus::PointF(0.0, 0.0);

		/// The actual rotation in the drawing
		double mPlacedR = 0;

	private:
		/// position of the part
		Gdiplus::PointF mLocation = Gdiplus::PointF(0.0, 0.0);
		/// angle
		double mAngle = 0.0;
		/// depth
		int mDepth = 0;
		/// tree
		CActualTree* mTree = nullptr;
		/// parent limb
		CLimb* mParent = nullptr;
};

