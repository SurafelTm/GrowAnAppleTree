/**
 * \file TreeImageDrawable.h
 *
 * \author Amanuel
 *
 * 
 */

#pragma once
#include <memory>
#include "TreePartsDrawable.h"

class CTreeImage;

class CTreeImageDrawable : public CTreePartsDrawable
{
	public:
		/// constructor
		CTreeImageDrawable(CActualTree* tree, int depth, std::shared_ptr<CTreeImage> image);
		virtual ~CTreeImageDrawable(){}

		/// disable copy
		CTreeImageDrawable(const CTreeImageDrawable&) = delete;
		/// disable assignment
		void operator=(const CTreeImageDrawable&) = delete;
		/**
		* Draw the drawable
		* \param graphics Graphics object to draw on
		*/
		virtual void Draw(Gdiplus::Graphics* graphics) override;

		/**
		* grow the part
		* \param frameRate
		*/
		virtual void Grow(int frameRate) = 0;
		double GetSize() { return mSize; }
		void SetSize(double size) { mSize = size; }
		std::shared_ptr<CTreeImage> GetImage() { return mImage; }
		void SetAngleOffset(double offset) { mAngleOffset = offset; }
		double GetAngleOffset() { return mAngleOffset; }
	private:
		double mSize = 0.1;
		std::shared_ptr<CTreeImage> mImage;
		double mAngleOffset = 0.0;
};

