/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <aluzingu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:29:24 by aluzingu          #+#    #+#             */
/*   Updated: 2025/02/27 18:07:12 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

    #include <iostream>
    #include <set>
    #include <vector>
    #include <algorithm>
    #include <stdexcept>
    #include <limits>
    #include <ctime>

    class Span
    {
        private:
            const unsigned int N;
            std::set<int> span;

        public:
            Span();
            Span(unsigned int _N);
            ~Span();
            Span(const Span &src);
            Span &operator=(const Span &src);
            void addNumber(int number);
            void addNumbers(std::set<int>::iterator begin, std::set<int>::iterator end);
            unsigned int shortestSpan(void);
            unsigned int longestSpan(void);
            class AllReadyExist : public std::exception
            {
                public:
                    const char *what() const throw();
            };

            class StorageSpan : public std::exception
            {
                public:
                    const char *what() const throw();
            };
            
            class InsuficentNumber : public std::exception
            {
                public:
                    const char *what() const throw();
            };
    };
#endif