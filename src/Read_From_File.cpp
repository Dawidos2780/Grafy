#include "Read_From_File.hh"
#include "functions.hh"

void scal(int *rand_array, int begining, int end)
{

    int pointer = (begining + end)/2; // pointer

    int i = begining;
    int j = pointer + 1;
    int k = begining;

    int temp[1000000];
    /* Tak długo jak dwie podzielone tablice mają jeszcze elementy porównuje je ze sobą, a następnie wpisuje do utworzonej z nich wspólneje tablicy */
    while(i <= pointer && j <= end)
    {
        if(rand_array[i] < rand_array[j])
        {
            temp[k++] = rand_array[i++];
        }
        else
        {
            temp[k++] = rand_array[j++];
        }
    }
    /* Jeżeli w tablicy lewej są jeszce jakieś elementy, co jest równoznaczne z tym, że znajdujące się tam elementy są większe od znajdujących sie w tablicy
    merge, to wpisuje je wszystkie do tej tablicy */
    while(i <= pointer)
    {
        temp[k++] = rand_array[i++];
    }
    /* Jeżeli w tablicy prawej są jeszce jakieś elementy, co jest równoznaczne z tym, że znajdujące się tam elementy są większe od znajdujących sie w tablicy
    merge, to wpisuje je wszystkie do tej tablicy */
    while(j <= end)
    {
        temp[k++] = rand_array[j++];
    }
    /* Przeniesienie tablicy z już posortowanymi elementami do tablicy wyjściowej */
    for(int i = begining; i <= end; i++)
    {
        rand_array[i] = temp[i];
    }

}

void sort_scal(int rand_array[], int begining, int size)
{

    if(begining >= size)
    {
        return;
    }

    int p = (begining + size)/2; // pointer
 
    sort_scal(rand_array, begining, p); /* stworzenie tablicy od początku do elementu p (będącego środkiem lub dla mod2(p) /= 0, będzie to [(size-1)/2 - 1)] */
    sort_scal(rand_array, p+1, size); /* stworzenie tablicy od elementu p+1 do końca tablicy */
    
    scal(rand_array, begining, size); /* Sortowanie utworzonych tablic */
        
}// wykonanie funkcji scalanie