#pragma once
#include "PathFindingList.h"
#include "Graph.h"

class Precedence
{
public:
	Precedence(NodeRecord prevNode, int prevCost) {}
	Precedence();
	~Precedence() {}

	int getPrevCost();
	NodeRecord getPrevNode();

private:
	int previousCost;
	NodeRecord previousNode;

};