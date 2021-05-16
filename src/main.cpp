/* Dawid Szymczyna 252920 5.05.2021 Projekt 2 "Grafy" */
/* Program znajduje najkrótszą drogę w grafach, wytworzonych losowo. Użyte zostały metoda Dijkstry oraz Bellman'a-Ford'a, a do implementacji
grafów posłużyły lista oraz macierz sąsiedztwa. Wynikiem działanie programu są 4 pliki txt, gdzie zamieszczona jest wielkość grafu, zagęszczenie oraz
czas potrzebny na znalezienie drogi wsród 100 takich grafów. */

#include<bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cassert>
#include <math.h>
 
#include "BellFord.hh"
#include "Dijkstra.hh"
#include "N_List.hh"
#include "N_Matrix.hh"
#include "Test.hh"
#include "BellFord_List.hh"

using namespace std;

int main()
{
    //int rand_graph[verticle][verticle];
    //int verticle = 10;
    //double density = 0.25;
    //int  A[1000][1000];

    char typ = 'r';

/* Wszystkie dane oraz funkcje potrzebne do wykonania wczytania grafu z pliku i znalezienia drogi */

ifstream indata;
   int num, value = 0, val1, val2, weight;
   int i, j, v1, v2, edge, verticle = 1, source;
   Graph g(1000);
   int dist[1000], prev[1000];
   int A[1000][1000];


indata.open("graph.txt");
   if(!indata) {
      cerr << "Error: file could not be opened" << endl;
      exit(1);
   }

   while ( !indata.eof() ){
          
          // Macierz wypełniamy zerami


         // Odczytujemy kolejne definicje krawędzi

           indata >> val1 >> val2 >> weight;

        if( indata.eof() ) { break; }
           
           if(value == 0) { // Zczytanie pierwszej lini, w której znajduje się informacja o ilości wierzchołków, krawędzi oraz punkcie startowym
              edge = val1, verticle = val2, source = weight, value++; 

              for( i = 0; i < verticle; i++ )
                 for( j = 0; j < verticle; j++ ) A [ i ][ j ] = 0;

             }

            else{
                    A[val1][val2] = weight; // Macierz sąsiedztwa 

                
                    g.addEdge(val1, val2, weight);
                }
    }indata.clear();
    
     /* Wyświetl macierz */
         cout << "   ";
          for( i = 0; i < verticle; i++ ) cout << setw ( 3 ) << i;
          cout << endl << endl;
          for( i = 0; i < verticle; i++ )
          {
            cout << setw ( 3 ) << i;
            for( j = 0; j < verticle; j++ ) cout << setw ( 3 ) << ( int ) A [ i ][ j ];
              cout << endl;
          }

/* Działa */ dijkstra(A, source, verticle);
/* Działa */ dijkstra_L(g, dist, prev, source);
//g.displayEdges();

/* Utworzenie plików wynikowych txt, dla poszczególnych sposobów znajdowania drogi w grafie */

/* Działa */ //BellFord_Matrix();
/* Działa */ //dijkstra_Matrix();
/* Działa */ //BellFord_List();
/* Działa */ //Dijkstra_List();
   
   
    /*char type;
    cout << "podaj typ" << endl;
    cin >> type;

    switch(type)
    {
        case 'r':
        array_sort_test_scal(type);
        break;

        case 'l':
        array_sort_test_quick(type);
        break;

        case 's':
        array_sort_test_introspective(type);
        break;

        case 'e':
        return 0;
    }*/

    return 0;
}
