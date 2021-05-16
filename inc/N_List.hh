#pragma once

#ifndef N_LIST_HH
#define N_LIST_HH

#include "N_Matrix.hh"

#include<bits/stdc++.h>
#include <iostream>
#include <unistd.h>

using namespace std;
using namespace std::chrono;

int size_tab_L_D[] = {10, 50, 100, 500, 1000};
int A_L_D[1000][1000];

/* Element listy zapamiętujący wierzchołek docelowy oraz koszt */
typedef struct nodes {
   int dest;
   int cost;
}node;

/* Graf utworzony z takich elementów listy */
class Graph {
   int n;
   list<node> *adjList;
   private:
      void showList(int src, list<node> lt) {
         list<node> :: iterator i;
         node tempNode;

            /* Wyświetlenie elementu listy */
         for(i = lt.begin(); i != lt.end(); i++) {
            tempNode = *i;
            cout << "[" << src << "]->["<< tempNode.dest << "]" << "|"<< "(" << tempNode.cost<<")";
         }
         cout << endl;
      }
   public:
      Graph() {
         n = 0;
      }

      Graph(int nodeCount) {
         n = nodeCount;
         adjList = new list<node>[n];
      }

      void addEdge(int source, int dest, int cost) {
         node newNode;
         newNode.dest = dest;
         newNode.cost = cost;
         adjList[source].push_back(newNode);
      } // dodaj krawędz (element listy)

      void displayEdges() {
         for(int i = 0; i<n; i++) {
            list<node> tempList = adjList[i];
            showList(i, tempList);
         }
      } // pokazanie wierzchołków

      friend void dijkstra_L(Graph g, int *dist, int *prev, int start);
      friend void Make_List_D(Graph g, int verticle, int edge, int source);
};

void Make_List_D(int A_L_D[1000][1000], Graph g, int verticle, int edge, int source){
    int i, j, b = 0, v1, v2, w;

    srand(time(NULL));

  // Macierz wypełniamy zerami

  for( i = 0; i < verticle; i++ )
    for( j = 0; j < verticle; j++ ) A_L_D [ i ][ j ] = 0;

  // Odczytujemy kolejne definicje krawędzi

  for( i = 0; i < edge; i++ )
  {
     v1 = rand() % verticle;
     v2 = rand() % verticle;    // Wierzchołek startowy i końcowy krawędzi
     w = rand() % 10 + 1; 

     if(A_L_D [ v1 ][ v2 ] >= 1){
         v1 = 0; v2 = 0;
       while(A_L_D [ v1 ][ v2 ] != 1){
           if(A_L_D [ v1 ][ v2 ] == 1 && v2 < verticle) v2++;
           if(v2 >= verticle){
               v1++;
            v2 = 0;
           }
           else break;   
       }
     }
        A_L_D [ v1 ][ v2 ] = rand() % 10 + 1;
       //cout << A[v1][v2] << endl;
  }

  for( i = 0; i < verticle; i++ ){
      for(j = 0; j < verticle; j++){
          if(A_L_D[i][j] != 0) {
                g.addEdge(v1, v2, A_L_D [ i ][ j ]);
                b++;
              }
      }
  }
} // Utworzenie losowej listy

void dijkstra_L(Graph g, int *dist, int *prev, int start) {
   int n = g.n;

   for(int u = 0; u<n; u++) {
      dist[u] = 9999;   //'nieskończonność
      prev[u] = -1;
   }

   dist[start] = 0;   //odległość źródła od samego siebie
   set<int> S;
   list<int> Q;

   for(int u = 0; u<n; u++) {
      Q.push_back(u);
   }

   while(!Q.empty()) {
      list<int> :: iterator i;
      i = min_element(Q.begin(), Q.end());
      int u = *i;
      Q.remove(u);
      S.insert(u);
      list<node> :: iterator it;

      /* Sprawdzenie odległośći od każdego z sąsiadujących wierzchołków */
      for(it = g.adjList[u].begin(); it != g.adjList[u].end();it++) {
         if((dist[u]+(it->cost)) < dist[it->dest]) { //relax (u,v)
            dist[it->dest] = (dist[u]+(it->cost));
            prev[it->dest] = u;
         }
      }
   }
}

void Dijkstra_List()
{
        ofstream file;
        file.open("test_dijkstra_List1000.txt");
    for(int i = 0; i < 5; i++)
        {
            file << size_tab_L_D[i] << " " << endl;

            int source = rand() % size_tab_L_D[i]; // generowanie wierzchołka startowego

            double beg_tab[] = {number_of_edges(size_tab_L_D[i], 0.25), number_of_edges(size_tab_L_D[i], 0.50), number_of_edges(size_tab_L_D[i], 0.75), number_of_edges(size_tab_L_D[i], 1)};

            for(int j = 0; j < 4; j++)
            {
                file << beg_tab[j] << " ";

                auto start = high_resolution_clock::now();

                for(int k = 0; k < 100; k++)
                {
                    Graph g(1000);
                    int dist[1000], prev[1000];
                    
                    Make_List_D(A_L_D, g, size_tab_L_D[i], beg_tab[j], source);
                    usleep(1);
                    dijkstra_L(g, dist, prev, source); 
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
} // 100 grafów dla metody Dijkstry (lista sąsiedztwa)


#endif