/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:28:51 by aluzingu          #+#    #+#             */
/*   Updated: 2025/01/10 15:28:52 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractional_bits = 8;

Fixed::Fixed():fixed_point_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int intValue)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixed_point_value = intValue * (1 << this->fractional_bits);
}

Fixed::Fixed(float floatValue)
{
    this->fixed_point_value = roundf(floatValue * (1 << this->fractional_bits));
}

float Fixed::toFloat(void) const
{
    return ((float)this->fixed_point_value / (float)(1 << this->fractional_bits));
}

int Fixed::toInt( void ) const
{
	return this->fixed_point_value / ( 1 << this->fractional_bits);
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->fixed_point_value = other.fixed_point_value;
	}
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed_point_value);
}

void Fixed::setRawBits(int const raw)
{
	this->fixed_point_value = raw;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}