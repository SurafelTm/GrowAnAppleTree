/**
 * \file FruitVisitor.h
 *
 * \author Amanuel
 *
 * 
 */

#pragma once
#include "TreeVisitor.h"
#include "ActualFruit.h"

class CActualFruit;
class CLimb;
class CLeaf;


/**
* a class representing fruit visitor
*/
class CFruitVisitor : public CTreeVisitor
{
public:
	/// destructor
	virtual ~CFruitVisitor() {}

	/** Visit an actual fruit object
	 * \param fruit */
	virtual void VisitFruit(CActualFruit* fruit) { mIsFruit = true; mActualFruit = fruit; }

	/// getter for mIsFruit
	/// \return mIsfruit
	bool IsFruit() { return mIsFruit; }

	std::shared_ptr<CActualFruit> GetFruit() { return mActualFruit->GetSelf(); }

	/// reset
	void Reset() { mIsFruit = false; }

private:
	/// is fruit
	bool mIsFruit = false;

	/// fruit
	CActualFruit* mActualFruit = nullptr;

};

