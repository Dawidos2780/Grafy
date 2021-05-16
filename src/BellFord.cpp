#include "BellFord.hh"
#include "functions.hh"

#include <iostream>
#include <limits.h>

void printArr(int dist[], int n)
{
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
} // Wyświetlenie rozwiązania

void BellmanFord(int A[1000][1000], int src, int verticle, int edge)
{
    int dist[verticle];
  
    /* Ustawienie początkowych wartości odległośći na 'nieskończonność' */
    for (int i = 0; i < verticle; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;
  
    /* Sprawdzenie wag wszystkich wierzchołków połączonych z obenie badanym wierzchołkeim */
    for (int i = 1; i <= verticle - 1; i++) {
        for (int j = 0; j < edge; j++) {
            int u = i;
            int v = j;
            int weight = A[i][j];
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }
  
    /* Sprawdzenie, czy pojawił się ujemny cykl */
    for (int i = 0; i < edge; i++) {
        for (int j = 0; j < edge; j++) {
            int u = i;
            int v = j;
            int weight = A[i][j];
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                printf("Graf zawiera ujemny cykl");
                return;
            }
        }
    }
  
    //printArr(dist, verticle); // wyswietlenie rozwiązanie (odkomentować dla pojedyńczego grafu)
  
    return;
}