/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 22:43:52 by apaz-mar          #+#    #+#             */
/*   Updated: 2026/04/29 23:10:02 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
    this->_data = NULL;
    this->_size = 0;
}

template <typename T>
Array<T>::~Array()
{
    delete[] this->_data;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
    this->_data = new T[n]();
    this->_size = n;
}

template <typename T>
Array<T>::Array(const Array<T>& other) : _data(NULL), _size(0)
{
    *this = other;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
    if (this != &other)
    {
        delete[] this->_data;

        this->_size = other._size;
        this->_data = new T[this->_size]();

        for (unsigned int i = 0; i < this->_size; i++)
            this->_data[i] = other._data[i];
    }
    return (*this);
}

template <typename T>
unsigned int Array<T>::size() const
{
    return (this->_size);
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= this->_size)
        throw std::exception();
    return(this->_data[index]);
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
    if (index >= this->_size)
        throw std::exception();
    return(this->_data[index]);
}