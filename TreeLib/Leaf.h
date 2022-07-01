/**
 * \file Leaf.h
 *
 * \author Amanuel
 *
 * 
 */

#pragma once
#include "TreeImageDrawable.h"

class CLeaf : public CTreeImageDrawable
{
	public:
		/// constructor
		CLeaf(CActualTree* tree, int depth);
		virtual ~CLeaf() {}
		virtual void Grow(int frameRate) override;
		/// accept visitor
		virtual void Accept(CTreeVisitor* visitor) override { visitor->VisitLeaf(this); }
};

