/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <aluzingu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:45:11 by aluzingu          #+#    #+#             */
/*   Updated: 2025/02/24 18:15:24 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

    #include <iostream>
    
    template <typename T>
    void swap(T &x, T &y)
    {
        T tmp;
        tmp = x;
        x = y;
        y = tmp;
    }
    
    template <typename T>
    T min(T x, T y)
    {
        if (x < y)
            return (x);
        return (y);
    }

    template <typename T>
    T max(T x, T y)
    {
        if (x > y)
            return (x);
        return (y);
    }
    
#endif