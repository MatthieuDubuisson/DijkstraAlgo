#pragma once
#include <string>
#include <vector>
#include "Precedence.h"
#include <iostream>

//structure to manipulate nodes
struct NodeRecord
{
	char node;
	Precedence precedence;
	int costSoFar;
	bool operator==(NodeRecord other) { return(node == other.node && costSoFar == other.costSoFar); }
};


class PathFindingList 
{
public:
	PathFindingList() {}
	~PathFindingList() {}

	void AddNode(NodeRecord node)
	{
		nodes.push_back(node);
		length++;
		//fonction trier
	}

	void RemoveNode()
	{
		nodes.pop_back();
		length--;
	}

	NodeRecord GetSmallestElement()
	{
		int smallestCost = 100;
		NodeRecord returnedNode;
		for (int i = 0; i < nodes.size(); i++) {
			int cost = nodes[i].costSoFar;
			if (cost < smallestCost) {
				smallestCost = cost;
				returnedNode = nodes[i];
			}
		}
		return returnedNode;
	}

	bool FindNode(NodeRecord node)
	{
		if (find(nodes.begin(), nodes.end(), node) != nodes.end())
		{
			return true;
		}

		else
		{
			return false;
		}
	}

	void printArray()
	{
		for (int i = 0; i < nodes.size(); i++)
		{
			std::cout << i << " " << nodes[i].costSoFar;
		}
	}

private:
	std::vector<NodeRecord> nodes;
	int length = 0;

};