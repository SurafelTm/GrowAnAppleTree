/**
 * \file ActualFruit.h
 *
 * \author Amanuel
 *
 * 
 */

#pragma once
#include "Fruit.h"
#include "TreeImageDrawable.h"

/**
* A class to describe actual fruit
*/
class CActualFruit : public CTreeImageDrawable, public CFruit
{
	public:
		/// constructor
		CActualFruit(CActualTree* tree, int depth);
		virtual ~CActualFruit() {}
		virtual void Grow(int frameRate) override;
		void Place(Gdiplus::PointF offset, double rotate) override;
		/**
		* Set the position of the fruit in the basket
		*
		* This position is relative to the basket, so
		* it will be added to the basket location passed
		* to DrawInBasket when we draw it
		* \param x X position in pixels
		* \param y Y position in pixels
		*/
		virtual void SetBasketPosition(int x, int y) override;

		/**
		 * Draw the fruit in the basket
		 * \param graphics The graphics object to draw on
		 * \param x X location of the basket
		 * \param y Y location of the basket
		 */
		virtual void DrawInBasket(Gdiplus::Graphics* graphics, int x, int y) override;

		/// accept visitor
		virtual void Accept(CTreeVisitor* visitor) { visitor->VisitFruit(this); }

		void SetSelf(std::shared_ptr<CActualFruit> self) { mSelf = self; }
		std::shared_ptr<CActualFruit> GetSelf() { return mSelf.lock(); }
	private:
		std::weak_ptr<CActualFruit> mSelf;
};

