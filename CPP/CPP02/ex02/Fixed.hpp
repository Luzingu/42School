/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:28:43 by aluzingu          #+#    #+#             */
/*   Updated: 2025/01/10 15:28:44 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
	
	#include <iostream>
	#include <cmath>

	class Fixed
	{
		private:
			int fixed_point_value;
    			static const int fractional_bits;
		public:
			Fixed();
			Fixed(const Fixed &other);
			~Fixed();
			Fixed(const int intValue);
			Fixed(const float floatValue);
			float toFloat( void ) const;
			int toInt( void ) const;
			int getRawBits( void ) const;
			void setRawBits( int const raw );
			Fixed &operator=(const Fixed &other);
			bool	operator>(Fixed fixed) const;
			bool	operator>=(Fixed fixed) const;
			bool	operator<(Fixed fixed) const;
			bool	operator<=(Fixed fixed) const;
			bool	operator==(Fixed fixed) const;
			bool	operator!=(Fixed fixed) const;
			float   operator+(Fixed fixed) const;
			float   operator-(Fixed fixed) const;
			float   operator*(Fixed fixed) const;
			float   operator/(Fixed fixed) const;
			Fixed 	operator++();
			Fixed 	operator--();
			Fixed 	operator++(int);
			Fixed 	operator--(int);
			static Fixed &min(Fixed &class1, Fixed &class2);
			static const Fixed &min(const Fixed &class1, const Fixed &class2);
			static Fixed &max(Fixed &class1, Fixed &class2);
			static const Fixed &max(const Fixed &class1, const Fixed &class2);
	};
	std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
#endif
