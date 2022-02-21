#include <iostream>
#include "PathFindingList.h"

using namespace std;

int main(int arc, char** argv)
{
	/*
	int nodes;

	cin >> nodes;

	int graph[nodes][nodes] = {

	};
	*/

	int graph2[5][5] = {
	{NULL, 101, 102, 103, 104},
	{101, NULL, 1, 2, NULL},
	{102, 1,NULL,NULL,3 },
	{103, 2,NULL,NULL,4 },
	{104, NULL,3,4,NULL }
	};

	
	//vector<vector<NodeRecord>> nodesList;

	NodeRecord startRecord;
	startRecord.node = "start";
	startRecord.connexion;
	startRecord.costSoFar = 0;


	PathFindingList open = PathFindingList();
	PathFindingList close = PathFindingList();


	return 0;
}