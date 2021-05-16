#include "N_Matrix.hh"

#include<bits/stdc++.h>

using namespace std;


int number_of_edges(int verticle, double density)
{
   
    double calc = (density * verticle*(verticle - 1));
    int edge = int (calc);


    return edge;
}


void graph(int A[1000][1000], int verticle, double density, char type)
{
    int edge = number_of_edges(verticle, density);

   int i, j, v1, v2;
    //char ** A;

    srand(time(NULL));

  // Macierz wypełniamy zerami

  for( i = 0; i < verticle; i++ )
    for( j = 0; j < verticle; j++ ) A [ i ][ j ] = 0;

  // Odczytujemy kolejne definicje krawędzi

  for( i = 0; i < edge; i++ )
  {
     v1 = rand() % verticle;
     v2 = rand() % verticle;    // Wierzchołek startowy i końcowy krawędzi
     
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

     switch(type)
    {
        case 'r':
        A [ v1 ][ v2 ] = rand() % 10 + 1; // Krawędź v1->v2 obecna
        break;

        case 'l':
        A [ v1 ][ v2 ] = rand() % 21 + (-10); // Krawędź v1->v2 obecna
        if(A [ v1 ][ v2 ] == 0) A [ v1 ][ v2 ]++;
        A [ v2 ][ v1 ] = A [ v1 ][ v2 ];
        break;
    }
  }


    /* Wyświetl macierz */
     /* cout << "   ";
  for( i = 0; i < verticle; i++ ) cout << setw ( 3 ) << i;
  cout << endl << endl;
  for( i = 0; i < verticle; i++ )
  {
    cout << setw ( 3 ) << i;
    for( j = 0; j < verticle; j++ ) cout << setw ( 3 ) << ( int ) A [ i ][ j ];
    cout << endl;
  }
*/ // wyswietlenie rozwiązanie (odkomentować dla pojedyńczego grafu)

} // Tworzenie losowego grafu, z wyborem wykorzystywanego algorytmu
