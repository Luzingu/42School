/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:29:45 by aluzingu          #+#    #+#             */
/*   Updated: 2025/01/09 17:29:47 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

	#include <iostream>

	class Harl
	{
		private:
			void debug( void );
			void info( void );
			void warning( void );
			void error( void );
		public:
			Harl(void);
			~Harl(void);
			void complain( std::string level );
	};
#endif