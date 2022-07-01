/**
 * \file ActualTree.h
 *
 * \author Amanuel
 *
 * 
 */

#pragma once
#include "Tree.h"
#include "PseudoRandom.h"
#include "TreeImage.h"

class CTreePartsDrawable;
class CTreeVisitor;
class CActualFruit;

/**
* A class to describe tree and make object of
*/
class CActualTree : public CTree
{
	public:
		/// Constructor
		CActualTree();

		/// Destructor
		virtual ~CActualTree() {}

		/// Copy constructor/disabled
		CActualTree(const CActualTree&) = delete;

		/// Assignment operator/disabled
		void operator=(const CActualTree&) = delete;

		/**
		* Set the position for the root of the tree
		* \param x X location (pixels)
		* \param y Y location (pixels)
		*/
		virtual void SetRootLocation(int x, int y) override;

		/**
		* Draw the tree at the currently specified location
		* \param graphics GDI+ Graphics object
		*/
		virtual void DrawTree(Gdiplus::Graphics* graphics) override;

		/**
		* Set the current tree frame
		* \param frame Frame number
		*/
		virtual void SetTreeFrame(int frame) override;

		/**
		* Set  the wind speed
		* \param speed Wind speed in miles per hour
		*/
		virtual void SetWindSpeed(double speed) override;

		/**
		* Set the tree seed
		* \param seed An integer number. Each number makes a different tree
		*/
		virtual void SetSeed(int seed) override;

		/**
		 * Get the current tree seed
		 * \return Tree seed integer
		 */
		virtual int GetSeed() override;

		/**
		 * Harvest all of the fruit
		 * \return Vector of objects of type CFruit
		 */
		virtual std::vector<std::shared_ptr<CFruit>> Harvest() override;

		/// get frame rate
		/// \return frame rate
		int GetFrameRate() const { return mFrameRate; }

		int GetCurrentFrame() { return mCurrentFrame; }

		void SetCurrentFrame(int frame) { mCurrentFrame = frame; }

		/// get grow rate
		/// \return grow rate
		double GetGrowRate() const;

		/// reset 
		void Reset();

		/// get random generator
		CPseudoRandom* GetRandomGenerator() { return &mRandom; }

		/// get leaf
		/// \return leaf
		std::shared_ptr<CTreeImage> GetLeaf() { return mLeaf; }
		/// get fruit
		/// \return fruit image
		std::shared_ptr<CTreeImage> GetFruit() { return mFruit; }
		/// add part to list
		/// \param part
		void AddPart(std::shared_ptr<CTreePartsDrawable> part);
		/// add fruit
		/// \param fruit
		void AddFruit(std::shared_ptr<CActualFruit> fruit);
		
		/// accept visitor
		virtual void Accept(CTreeVisitor* visitor);

	private:
		/// seed
		int mSeed = 1234;
		/// root location
		Gdiplus::PointF mLocation = Gdiplus::PointF(0.0, 0.0);
		/// windspeed
		double mWindSpeed = 0.0;
		/// angle offset due to wind
		double mAngleOffset = 0.0;
		/// current frame
		int mCurrentFrame = 0;
		/// frame rate
		int mFrameRate = 30;
		/// root tree part drawable
		std::shared_ptr<CTreePartsDrawable> mRoot;
		/// list of tree parts
		std::vector<std::shared_ptr<CTreePartsDrawable>> mTreeParts;
		/// random number generator
		CPseudoRandom mRandom;
		/// leaf image
		std::shared_ptr<CTreeImage> mLeaf;
		/// fruit image
		std::shared_ptr<CTreeImage> mFruit;
		/// fruits in the tree
		std::vector<std::shared_ptr<CActualFruit>> mTreeFruits;
		/// fruits harvested
		std::vector<std::shared_ptr<CFruit>> mHarvestedFruits;
};

