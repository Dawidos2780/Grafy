#ifndef DIJKSTRA_HH
#define DIJKSTRA_HH

int minDistance(int dist[], bool sptSet[], int verticle);
void printSolution(int dist[], int verticle);
void min_weight(int dist[], int verticle);
void dijkstra(int A[1000][1000], int src, int verticle);


#endif