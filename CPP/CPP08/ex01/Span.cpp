/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <aluzingu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:21:47 by aluzingu          #+#    #+#             */
/*   Updated: 2025/02/27 16:06:40 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): N(0)
{

}

Span::Span(unsigned int _N) : N(_N)
{

}

Span::~Span()
{

}

Span::Span(const Span &src): N(src.N)
{
    this->span.insert(src.span.begin(), src.span.end());
}

Span &Span::operator=(const Span &src)
{
    if (this != &src)
        this->span = src.span;
    return (*this);
}

const char *Span::StorageSpan::what() const throw()
{
    return ("The span is out of storage!");
}

const char *Span::AllReadyExist::what() const throw()
{
    return ("The number is alredy in span!");
}

const char *Span::InsuficentNumber::what() const throw()
{
    return ("The span haven't enought numbers.");
}

void Span::addNumber(int number)
{
    if (this->N <= this->span.size())
        throw Span::StorageSpan();
    if(this->span.find(number) != this->span.end())
        throw Span::AllReadyExist();  
    this->span.insert(number);
}

void Span::addNumbers(std::set<int>::iterator begin, std::set<int>::iterator end)
{
    if ((std::distance(begin, end) + this->span.size()) > this->N)
        throw Span::StorageSpan();
    std::set<int>::iterator it = begin;
    while (it != end)
    {
        if (this->span.find(*it) != this->span.end())
            throw Span::AllReadyExist();
        it++;
    }
    this->span.insert(begin, end);
}

unsigned int Span::shortestSpan()
{
    unsigned int shortest_span;
    shortest_span = std::numeric_limits<unsigned int>::max();

    std::set<int>::iterator it = this->span.begin();
    std::set<int>::iterator next = it;
    next++;
    while (next != this->span.end())
    {
        shortest_span = std::min(shortest_span, static_cast<unsigned int>(*next - *it)); 
        it++;
        next++;
    }
    return (shortest_span);
}

unsigned int Span::longestSpan()
{
    if (this->span.size() <= 1)
        throw Span::InsuficentNumber();
    std::set<int>::iterator begin = this->span.begin();
    std::set<int>::iterator end = this->span.end();
    end--;
    return (*end - *begin);
}