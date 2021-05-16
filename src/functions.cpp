#include "functions.hh"

#include <iostream>
#include <string>

void generate_array(int rand_array[], int size, int begining)
{

    int random = size + (rand()%100) + 1;

    if(begining != -1)
    {
        int i;

        for( i=0;i<begining;i++)
            rand_array[i] = i;
        for( i=begining;i<size;i++)
        {
            
            rand_array[i] = (rand()%random) + 1;
        }
            
    }

    else
    {
        for(int i=0;i<size;i++)
    {
        rand_array[i] = size - i;
    }
    }


}

void display_array(int * rand_array, int size)
{
    for(int i = 0; i < size; i++)
        std::cout << rand_array[i] << " ";

    std::cout << " " << std::endl;

}
