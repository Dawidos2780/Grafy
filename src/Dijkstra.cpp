#include "Dijkstra.hh"
#include "BellFord.hh"
#include "functions.hh"

#include <cmath>
#include <limits.h>
#include <bits/stdc++.h>

int minDistance(int dist[], bool sptSet[], int verticle)
{
    int min = INT_MAX, min_index;
  
    for (int v = 0; v < verticle; v++){
        if (sptSet[v] == false && dist[v] <= min){
            min = dist[v], min_index = v;
        }
    }
  
    return min_index;
} // sprawdzenie minimalnej wartości

void printPath(int parent[], int j)
{
      
    // Base Case : If j is source
    if (parent[j] == 0)
        return;
  
    printPath(parent, parent[j]);
  
    printf("%d ", j);
} // wyświetlenie najkrutszej drogi krok po krku

void min_weight(int dist[], int verticle)
{
    int max = dist[0];
    if(max == 0) max = dist[1];

    for (int i = 0; i < verticle; i++){
        if(max > dist[i] && dist[i] != 0){
            max = dist[i];
            printf("\nShorthest Distance from Source\n");
            printf("%d \t\t %d\n", i, dist[i]);
        }
    }

} // znaleznienie najkrótszej z wyznaczonych dróg

void printSolution(int dist[], int verticle, int parent[], int src)
{

    printf("Vertex\t Distance\tPath");
    for (int i = 1; i < verticle; i++)
    {
        printf("\n%d -> %d \t\t %d\t\t%d ", src, i, dist[i], src);
        printPath(parent, i);
    }

} // Wyświetl liste wag przejść

void dijkstra(int A[1000][1000], int src, int verticle)
{
    //if(src == 0) src = rand() % verticle;
    std::cout << "src " << src << std::endl;

    int dist[verticle]; // najkrótsza droga
  
    bool sptSet[verticle]; 

    int parent[verticle]; // zapamietanie drogi krok po kroku

/* Każda z odelgłośći ustawiona początkowo na 'nieskończoność */
    for (int i = 0; i < verticle; i++){
        parent[0] = -1;
        dist[i] = INT_MAX, sptSet[i] = false;
    } 

    dist[src] = 0; // odległość wierzchołka do samego siebie
  
    /* Znajdowanie najrótszej dorgi ze źródła do wierzchołka docelowego */
    for (int count = 0; count < verticle - 1; count++) {

        int u = minDistance(dist, sptSet, verticle); // najkrótsza droga

        sptSet[u] = true;

        for (int v = 0; v < verticle; v++){

            if (!sptSet[v] && A[u][v] && dist[u] != INT_MAX && dist[u] + A[u][v] < dist[v]){
                dist[v] = dist[u] + A[u][v];
                 parent[v] = u;
            }
        }
    }

    min_weight(dist, verticle);

    printSolution(dist, verticle, parent, src); // wyswietlenie rozwiązanie (odkomentować dla pojedyńczego grafu)
    
} // Wyszukanie najkrótszej drogi pomiędzy dwoma elementami przy użyciu algorymu Djikstry (Macierz sąsiedztwa)