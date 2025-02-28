/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <aluzingu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:17:31 by aluzingu          #+#    #+#             */
/*   Updated: 2025/02/25 11:01:34 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP
    #include <iostream>
    #include <cstdlib>
    #include <exception>
    #include <stdexcept>
    

    template <typename T>

    class Array
    {
        private:
            unsigned int len;
        public:
            T *my_array;
            Array(void);
            Array(unsigned int n);
            Array(Array &src);
            ~Array();
            Array &operator=(Array &src);
            const T operator[](unsigned int n);
            unsigned int size();
    };
    
    #include "Array.tpp"

#endif