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

	class Fixed
	{
		private:
			int number;
			static const int fractional_bits;
		public:
			Fixed();
			Fixed(const Fixed &other);
			~Fixed();
			Fixed &operator=(const Fixed &other);
			int getRawBits( void ) const;
			void setRawBits( int const raw );
	};
#endif
