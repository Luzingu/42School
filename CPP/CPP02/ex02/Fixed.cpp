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
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const int intValue)
{
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
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->fixed_point_value = other.fixed_point_value;
	return *this;
}

bool	Fixed::operator>(Fixed fixed) const
{
	return (this->toFloat() > fixed.toFloat());
}

bool	Fixed::operator>=(Fixed fixed) const
{
	return (this->toFloat() >= fixed.toFloat());
}

bool	Fixed::operator<(Fixed fixed) const
{
	return (this->toFloat() < fixed.toFloat());
}

bool	Fixed::operator<=(Fixed fixed) const
{
	return (this->toFloat() <= fixed.toFloat());
}

bool	Fixed::operator==(Fixed fixed) const
{
	return (this->toFloat() == fixed.toFloat());
}

bool	Fixed::operator!=(Fixed fixed) const
{
	return (this->toFloat() == fixed.toFloat());
}

float   Fixed::operator+(Fixed fixed) const
{
	return (this->toFloat() + fixed.toFloat());
}

float   Fixed::operator-(Fixed fixed) const
{
	return (this->toFloat() - fixed.toFloat());
}

float   Fixed::operator/(Fixed fixed) const
{
	return (this->toFloat() / fixed.toFloat());
}

float   Fixed::operator*(Fixed fixed) const
{
	return (this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator++()
{
	this->fixed_point_value++;
	return (*this);
}

Fixed Fixed::operator--()
{
	this->fixed_point_value--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	this->fixed_point_value++;
	return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	this->fixed_point_value--;
	return (tmp);
}

int Fixed::getRawBits(void) const
{
	return (this->fixed_point_value);
}

void Fixed::setRawBits(int const raw)
{
	this->fixed_point_value = raw;
}

Fixed &Fixed::min(Fixed &class1, Fixed &class2)
{
	if (class1.fixed_point_value < class2.fixed_point_value)
		return (class1);
	else
		return (class2);
} 

const Fixed &Fixed::min(const Fixed &class1, const Fixed &class2)
{
	if (class1.fixed_point_value < class2.fixed_point_value)
		return (class1);
	else
		return (class2);
}

Fixed &Fixed::max(Fixed &class1, Fixed &class2)
{
	if (class1.fixed_point_value > class2.fixed_point_value)
		return (class1);
	else
		return (class2);
}

const Fixed &Fixed::max(const Fixed &class1, const Fixed &class2)
{
	if (class1.fixed_point_value > class2.fixed_point_value)
		return (class1);
	else
		return (class2);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}