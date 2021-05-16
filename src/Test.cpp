#include "Test.hh"

#include "Dijkstra.hh"
#include "BellFord.hh"
#include "functions.hh"
#include "N_Matrix.hh"

#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

int size_tab[] = {10, 50, 100, 500, 1000};
int  A[1000][1000];
char typ = 'r';
    //cout << edge << endl;

    //graph(A, verticle, density, typ);

void dijkstra_Matrix()
{
        ofstream file;
        file.open("test_dijksra_Matrix.txt");
    for(int i = 0; i < 5; i++)
        {
            file << size_tab[i] << " " << endl;

            int source = rand() % size_tab[i]; // generowanie wierzchołka startowego

            double beg_tab[] = {number_of_edges(size_tab[i], 0.25), number_of_edges(size_tab[i], 0.50), number_of_edges(size_tab[i], 0.75), number_of_edges(size_tab[i], 1)};

            for(int j = 0; j < 4; j++)
            {
                file << beg_tab[j] << " ";

                auto start = high_resolution_clock::now();

                for(int k = 0; k < 100; k++)
                {
                     int rand_array[size_tab[i]];

                    graph(A, size_tab[i], beg_tab[j], typ);
                //display_array(rand_array, size_tab[i]);
                    //std::cout << "posortowana" << std::endl;
                    dijkstra(A, source, size_tab[i]); 
                //display_array(rand_array, size_tab[i]);
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
} // 100 grafów dla Dijkstry (Macierz sąsiedztwa)

void BellFord_Matrix()
{
        ofstream file;
        file.open("test_BellFord_Matrix.txt");
    for(int i = 0; i < 5; i++)
        {
            file << size_tab[i] << " " << endl;

            int source = rand() % size_tab[i]; // generowanie wierzchołka startowego

            double beg_tab[] = {number_of_edges(size_tab[i], 0.25), number_of_edges(size_tab[i], 0.50), number_of_edges(size_tab[i], 0.75), number_of_edges(size_tab[i], 1)};

            for(int j = 0; j < 4; j++)
            {
                file << beg_tab[j] << " ";

                auto start = high_resolution_clock::now();

                for(int k = 0; k < 100; k++)
                {
                     int rand_array[size_tab[i]];

                    graph(A, size_tab[i], beg_tab[j], typ);
                //display_array(rand_array, size_tab[i]);
                    //std::cout << "posortowana" << std::endl;
                    BellmanFord(A, source, size_tab[i], beg_tab[j]); 
                //display_array(rand_array, size_tab[i]);
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
} // 100 grafów dla Bell-Forda (Macierz sąsiedztwa)
