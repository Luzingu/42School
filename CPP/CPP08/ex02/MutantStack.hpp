/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <aluzingu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:56:25 by aluzingu          #+#    #+#             */
/*   Updated: 2025/02/28 11:23:34 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

    #include <iostream>
    #include <stack>
    #include <deque>
    
    template <typename T>
        
    class MutantStack : public std::stack<T>
    {
        public:
            typedef typename std::deque<T>::iterator iterator;
            typedef typename std::deque<T>::const_iterator const_iterator;
            typedef typename std::deque<T>::reverse_iterator reverse_iterator;
            typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;
            
            iterator begin()
            {
                return this->c.begin();
            }
            iterator end()
            {
                return this->c.end();
            }
            const_iterator begin() const
            {
                return this->c.begin();
            }
            const_iterator end() const
            {
                return this->c.end();
            }
            reverse_iterator rbegin()
            {
                return this->c.rbegin();
            }
            reverse_iterator rend()
            {
                return this->c.rend();
            }
            const_reverse_iterator rbegin() const
            {
                return this->c.rbegin();
            }
            const_reverse_iterator rend() const
            {
                return this->c.rend();
            }
    };

#endif