#include <iostream>
#include <limits.h>
#include <stdio.h>
#include <stdbool.h>
#include <string>

// Number of vertices in the graph
#define V 9

int minDistance(int cost[], bool pathFindingList[])
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (pathFindingList[v] == false && cost[v] <= min)
            min = cost[v], min_index = v;

    return min_index;
}


void printSolution(int cost[], int shortest_path[], int target_vertex)
{
    printf("Target Vertex : %d \t Distance from vertex 0 : %d \t", target_vertex, cost[target_vertex]);
    printf("Shortest Path :");
    int k = V - 1;
    while (shortest_path[k] == INT_MAX)
        k--;
    for (int j = k; j >= 0; j--)
        printf(" %d ", shortest_path[j]);
    printf(" \n");
}


void dijkstra(int graph[V][V], int src)
{
    int cost[V];

    bool pathFindingList[V];

    for (int i = 0; i < V; i++)
        cost[i] = INT_MAX, pathFindingList[i] = false;
    cost[src] = 0;

    int precedence[200]; // The couple precedence list
    for (int l = 0; l < 200; l++)
        precedence[l] = INT_MAX;

    printf("DIJKSTRA ALGORITHM\n");
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in the first iteration.
        int u = minDistance(cost, pathFindingList);

        // Mark the picked vertex as processed
        pathFindingList[u] = true;

        // Update cost value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++)

            // Update cost[v] only if is not in pathFindingList, there is an edge from
            // u to v, and total weight of path from src to  v through u is
            // smaller than current value of cost[v]
            if (!pathFindingList[v] && graph[u][v] && cost[u] != INT_MAX
                && cost[u] + graph[u][v] < cost[v])
            {
                // write or overwrite distance from vertex 0 to vertex v
                cost[v] = cost[u] + graph[u][v];
                printf("Shortest path found in dijkstra iteration %d: origin_vertex=%d : current_vertex=%d distance_from_vertex_0=%d \n", count, u, v, cost[v]);
                // write u,v pair in the end of precedence matrix
                int a = 0;
                while (precedence[a] != INT_MAX)
                    a++;
                precedence[a] = u;
                precedence[a + 1] = v;
                //printf("u:%d v:%d precedence %d : %d \n", u, v, precedence[a], precedence[a+1]);
            }
    }
    printf("\nDIJKSTRA VERTEX PRECEDENCE\nOriginal vertex \t Next vertex\n");
    for (int x = 0; precedence[x] != INT_MAX; x++)
    {
        printf("%d <-------------------------- %d \n", precedence[x], precedence[x + 1]);
        x++;
    }
    printf("\nSHORTEST PATH\n");

    for (int vertex = 8; vertex > 0; vertex--)
    {
        // browse precedence list from bottom to up to read precedence couple
        // and store shortest path from target vertex to vertex 0 in shortest path list 
        int shortest_path[V];
        for (int y = 0; y < V; y++)
            shortest_path[y] = INT_MAX;

        int target_vertex = vertex;
        //printf("target vertex : %d\n", target_vertex);
        int current_vertex = target_vertex;
        int current_index_in_shortest_path = 0;

        // position the index at the end of the precedence list
        int p = 0;
        while (precedence[p] != INT_MAX)
            p++;
        p--;
        int current_index_in_precedence = p;
        // scan right to left the list jut for odd index, to find the current vertex
        while (current_vertex > 0)
        {
            //printf("current vertex search %d\n", current_vertex);
            while (precedence[current_index_in_precedence] != current_vertex)
                current_index_in_precedence = current_index_in_precedence - 2;

            //printf("shortest partial path %d,%d \n", precedence[current_index_in_precedence], precedence[current_index_in_precedence-1]);
            shortest_path[current_index_in_shortest_path] = precedence[current_index_in_precedence];
            current_index_in_shortest_path++;
            current_vertex = precedence[current_index_in_precedence - 1];
        }
        shortest_path[current_index_in_shortest_path] = 0;

        //for(int e=0; e < V; e++)
            //printf("Shortest Path for Vertex Number%d [%d]:%d\n", target_vertex, e, shortest_path[e]);

        // print the constructed distance array
        printSolution(cost, shortest_path, vertex);
    }
}


int main()
{
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    dijkstra(graph, 0);

    return 0;
}