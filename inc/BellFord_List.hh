#ifndef BELLFORD_LIST_HH
#define BELLFORD_LIST_HH

#include <limits.h>
#include <iostream>

using namespace std;
using namespace std::chrono;

int size_tab_L[] = {10, 50, 100, 500, 1000};
int A_L[1000][1000];

/* Element listy, który zwierać bedzie wierzchołek startowy, końcowy i wage krawędzi ich łączącej */
struct Edge {
    int src, dest, weight;
};
  
/* Graf utworzony z uprzednio zczytanych elementów listy */
struct Graph_L {
    // V - wierzchołki, E - krawędzie
    int V, E;

    struct Edge* edge;
};

struct Graph_L* createGraph_L(int V, int E)
{
    struct Graph_L* graph = new Graph_L;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
} // graf mający odpowiednią ilość krawędzi i wierzchołków

void printA(int dist[], int n)
{
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}// Wyświetl rozwiązanie

void Make_List(int A[1000][1000], int verticle, int edge, struct Graph_L* graph){
    int i, j, b = 0, v1, v2, w, source;

    srand(time(NULL));

  // Macierz wypełniamy zerami

  for( i = 0; i < verticle; i++ )
    for( j = 0; j < verticle; j++ ) A [ i ][ j ] = 0;

  // Odczytujemy kolejne definicje krawędzi

  for( i = 0; i < edge; i++ )
  {
     v1 = rand() % verticle;
     v2 = rand() % verticle;    // Wierzchołek startowy i końcowy krawędzi
     w = rand() % 10 + 1; 

     if(A [ v1 ][ v2 ] >= 1){
         v1 = 0; v2 = 0;
       while(A [ v1 ][ v2 ] != 1){
           if(A [ v1 ][ v2 ] == 1 && v2 < verticle) v2++;
           if(v2 >= verticle){
               v1++;
            v2 = 0;
           }
           else break;   
       }
     }
        A [ v1 ][ v2 ] = rand() % 10 + 1;
       //cout << A[v1][v2] << endl;
  }

  for( i = 0; i < verticle; i++ ){
      for(j = 0; j < verticle; j++){
          if(A[i][j] != 0) {
                graph->edge[b].src = i;
                graph->edge[b].dest = j;
                graph->edge[b].weight = w;
                b++;
              }
      }
  }
} // Tworzenie losowej listy, która nie zawiera powtarzających się elementów

void BellmanFord_L(struct Graph_L* graph, int src)
{
    int V = graph->V;
    int E = graph->E;
    int dist[V];
  
    /* Ustwanie wszystki odległości na 'nieskończoność' */
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0; // oległość od źródła
  
    /* Sprawdzenie wag wszystkich wierzchołków połączonych z obenie badanym wierzchołkeim */
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }
  
    /* Sprawdzenie, czy pojawił się ujemny cykl */
    for (int i = 0; i < E; i++) {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("Graf zawiera ujemny cykl");
            return;
        }
    }
  
    //printA(dist, V); // Wyświetlenie wyniku (odkomentować dla pojedyńczego grafu)
  
    return;
} // Znajdowanie nakrótszej drogi przy użyciu metody Bell'a-Ford'a

void BellFord_List()
{
        ofstream file;
        file.open("test_BellFord_List.txt");
    for(int i = 0; i < 5; i++)
        {
            file << size_tab_L[i] << " " << endl;

            int source = rand() % size_tab_L[i]; // generowanie wierzchołka startowego

            double beg_tab[] = {number_of_edges(size_tab_L[i], 0.25), number_of_edges(size_tab_L[i], 0.50), number_of_edges(size_tab_L[i], 0.75), number_of_edges(size_tab_L[i], 1)};

            for(int j = 0; j < 4; j++)
            {
                file << beg_tab[j] << " ";

                auto start = high_resolution_clock::now();

                for(int k = 0; k < 100; k++)
                {
                    struct Graph_L* graph = createGraph_L(size_tab_L[i], beg_tab[j]);
                    
                    Make_List(A_L, size_tab_L[i], beg_tab[j], graph);
                    
                    BellmanFord_L(graph, 0); 
                }
                
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                cout << "czas" << duration.count() << endl;
                file << duration.count() << " ";
                file << endl;
            }
             file << endl;
        }
    file.close();
    cout << "Zakonczono wpisywanie do pliku" << endl;
} // 100 grafów dla metody Bellman'a-Ford'a (lista sąsiedztwa)

#endif