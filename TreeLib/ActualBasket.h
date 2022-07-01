#pragma once
#include <vector>
#include <memory>
#include "Basket.h"

class CTreeImage;

/**
 * Class the represents a basket that can hold fruit.
 *
 */
class CActualBasket : public CBasket
{
	public:
		/// Constructor
		CActualBasket();

		/// Destructor
		virtual ~CActualBasket() {}

		/// Copy constructor/disabled
		CActualBasket(const CActualBasket&) = delete;

		/// Assignment operator/disabled
		void operator=(const CActualBasket&) = delete;

		/**
		* Set the position for the basket.
		* \param x X location (pixels)
		* \param y Y location (pixels)
		*/
		virtual void SetBasketLocation(int x, int y);

		/**
		* Draw the basket at the currently specified location
		* \param graphics GDI+ Graphics object
		*/
		virtual void DrawBasket(Gdiplus::Graphics* graphics);

		/**
		 * Add fruit to the basket
		 * \param fruit Vector of fruit objects
		 */
		virtual void AddToBasket(std::vector < std::shared_ptr<CFruit>> fruit);

		/**
		 * Empty all fruit from the basket
		 */
		virtual void EmptyBasket();

	private:
		/// position
		Gdiplus::PointF mPosition = Gdiplus::PointF(0.0, 0.0);
		/// image basket
		std::shared_ptr<CTreeImage> mFullImage;
		/// front only
		std::shared_ptr<CTreeImage> mFrontBasket;
		/// fruits
		std::vector<std::shared_ptr<CFruit>> mHarvestedFruits;
	

};
