/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_ordenaca.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <aluzingu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:26:43 by aluzingu          #+#    #+#             */
/*   Updated: 2025/03/03 17:00:30 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void bubleSort(int *numeros, int len)
{
    int tmp;
    int i = 0;
    int j = 0;
    
    while (i < len)
    {
        j = i + 1;
        while (j < len)
        {
            if (numeros[i] > numeros[j])
            {
                tmp = numeros[i];
                numeros[i] = numeros[j];
                numeros[j] = tmp;
                i = -1;
                break;
            }
            j++;
        }
        i++;
    }
    
    i = 0;
    while (i < 5)
    {
        std::cout << numeros[i] << std::endl;
        i++;
    }
}

void selectionSort(int *numeros, int len)
{
    int i = 0;
    int indice = -1;
    int tmp;

    while (i < len)
    {
        indice = i;
        int j = i + 1;
        while (j < len)
        {
            if (numeros[j] < numeros[indice])
                indice = j;
            j++;
        }
        if (i != indice)
        {
            tmp = numeros[i];
            numeros[i] = numeros[indice];
            numeros[indice] = tmp;
        }
        i++;
    }

    i = 0;
    while (i < len)
    {
        std::cout << numeros[i] << std::endl;
        i++;
    }
}

void merge(int array[], int arrayLeft[], int arrayRight[], int leftSize, int rightSize)
{
    int i = 0;
    int l = 0;
    int r = 0;

    while (l < leftSize && r < rightSize)
    {
        if (arrayLeft[l] < arrayRight[r])
        {
            array[i] = arrayLeft[l];
            l++;
        }
        else
        {
            array[i] = arrayRight[r];
            r++;
        }
        i++;
    }
    while (l < leftSize)
    {
        array[i] = arrayLeft[l];
        l++;
        i++;
    }
    while (r < rightSize)
    {
        array[i] = arrayRight[r];
        r++;
        i++;
    }
}

void mergeSort(int numeros[], int len)
{
    if(len <= 1)
        return ;
    int leftSize = len / 2;
    int rightSize = len - leftSize;
    int arrayLeft[leftSize];
    int arrayRight[rightSize];
    int i = 0;
    int r = 0;

    while (i < len)
    {
        if (i < leftSize)
            arrayLeft[i] = numeros[i];
        else
        {
            arrayRight[r] = numeros[i];
            r++;
        }
        i++;
    }
    mergeSort(arrayLeft, leftSize);
    mergeSort(arrayRight, rightSize);
    merge(numeros, arrayLeft, arrayRight, leftSize, rightSize);
}



int main(void)
{
    int numeros[] = {7, 1, 2, 9, -1};

    int len =  sizeof(numeros) / sizeof(int);

    mergeSort(numeros, len);
    int i = 0;
    while (i < len)
    {
        std::cout << "Number: " << numeros[i] << std::endl;
        i++;
    }
    //bubleSort(numeros, len);
    
    return (0);
}

//https://www.youtube.com/watch?v=3j0SWDX4AtU