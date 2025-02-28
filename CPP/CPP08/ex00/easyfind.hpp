/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <aluzingu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:04:19 by aluzingu          #+#    #+#             */
/*   Updated: 2025/02/27 12:08:45 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASY_FIND_HPP
#define EASY_FIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <algorithm>
#include <stdexcept>
#include <iterator>

class NotFoundException: public std::exception
{
    public:
        const char *what() const throw()
        {
            return ("Number Not Found");
        }
};

template <typename T>
typename T::iterator easyfind(T &container, int number)
{
    typename T::iterator it = std::find(container.begin(), container.end(), number);

    if (it == container.end())
        throw NotFoundException();
    return (it);
}
#endif