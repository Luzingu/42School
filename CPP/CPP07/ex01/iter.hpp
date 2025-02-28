/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <aluzingu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:22:24 by aluzingu          #+#    #+#             */
/*   Updated: 2025/02/25 19:35:34 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

    #include <iostream>
    template <typename T, typename Func>
    
    void iter(T *array, int len, Func function)
    {
        int i = 0;
    
        while (i < len)
        {
            function(array[i]);
            i++;
        }
    }

    template <typename T>
    void printValue(const T& valor)
    {
        std::cout << valor << std::endl;
    }

#endif