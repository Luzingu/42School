/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <aluzingu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:28:17 by aluzingu          #+#    #+#             */
/*   Updated: 2025/02/25 11:05:58 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>

Array<T>::Array():len(0), my_array(NULL)
{

}
template <typename T>
Array<T>::Array(unsigned int n):len(n)
{
    this->my_array = new T[n]();
}

template <typename T>
Array<T>::Array(Array<T> &src)
{
    this->len = src.len;
    this->my_array = new T[this->len]();
    int i = 0;
    while (i < this->len)
    {
        this->my_array[i] = src.my_array[i];
        i++;
    }
}
template <typename T>
Array<T>::~Array()
{
    delete[] this->my_array;
}

template <typename T>
Array<T> &Array<T>::operator=(Array<T> &src)
{
    if (*this != src)
    {
        if (this->my_array)
            delete[] my_array;
        this->len = src.len;
        this->my_array = new T[src.len]();
        int i = 0;
        while (i < this->len)
        {
            this->my_array[i] = src.my_array[i];
            i++;
        }
    }
    return (*this);
}

template <typename T>
const T Array<T>::operator[](unsigned int n)
{
    if (n >= this->len)
        throw std::out_of_range("valor fora do intervalo");
    return this->my_array[n];
}

template <typename T>

unsigned int Array<T>::size()
{
    return (this->len);
}
