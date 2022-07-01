/**
 * \file TreeVisitor.h
 *
 * \author Amanuel
 *
 * 
 */

#pragma once

class CActualFruit;
class CLimb;
class CLeaf;

/**
* a class representing base visitor
*/
class CTreeVisitor
{
	public:	

		virtual ~CTreeVisitor() {}

		/** Visit an actual fruit object
		 * \param fruit */
		virtual void VisitFruit(CActualFruit* fruit) {}

		/** Visit a limb object
		* \param limb */
		virtual void VisitLimb(CLimb* limb) {}

		/** Visit a leaf object
		* \param leaf */
		virtual void VisitLeaf(CLeaf* leaf) {}
};

