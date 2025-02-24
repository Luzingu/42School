/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:10:27 by aluzingu          #+#    #+#             */
/*   Updated: 2025/01/27 11:10:28 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_H
#define FRAG_TRAP_H
	#include "ClapTrap.hpp"
	
	class FragTrap: public ClapTrap
	{
		private:

		public:
			FragTrap();
			FragTrap(const FragTrap &copy);
			FragTrap(std::string name);
			virtual ~FragTrap();
			FragTrap &operator=(const FragTrap &src);
			void highFiveGuys(void);
	};
#endif
