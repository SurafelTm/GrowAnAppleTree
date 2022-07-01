/**
 * \file Limb.h
 *
 * \author Amanuel
 *
 * 
 */

#pragma once
#include <vector>
#include <memory>
#include "TreePartsDrawable.h"

class CActualFruit;

/**
* A class describing limbs
*/
class CLimb : public CTreePartsDrawable
{
	public:
		/// constructor
		CLimb(CActualTree* tree, int depth);

		/// default copy disabled
		CLimb(const CLimb&) = delete;

		/// default assignment disabled
		void operator=(const CLimb&) = delete;

		/**
		* Draw the drawable
		* \param graphics Graphics object to draw on
		*/
		virtual void Draw(Gdiplus::Graphics* graphics) override;

		/**
		* grow the part
		* \param frameRate
		*/
		virtual void Grow(int frameRate) override;

		/// add children to limb
		/// \param part
		void AddChild(std::shared_ptr<CTreePartsDrawable> part);

		virtual void Place(Gdiplus::PointF offset, double rotate) override;

		Gdiplus::PointF GetEndPoint() const;

		double GetSpawningLength() { return mSpawningLength; }

		/// accept visitor
		virtual void Accept(CTreeVisitor* visitor) override { visitor->VisitLimb(this); }

		/// remove harvested fruit
		/// \param fruit
		void PluckFruit(std::shared_ptr<CActualFruit> fruit);

	protected:
		/// spawn the limb
		void Spawn();

	private:
		/// children of limb
		std::vector<std::shared_ptr<CTreePartsDrawable>> mChildren;
		/// width
		double mWidth = 0.0;
		/// height
		double mHeight = 0.0;
		/// spawning length
		const double mSpawningLength = 6.6;
		/// spawned or not
		bool mHasSpawned = false;

		



};

