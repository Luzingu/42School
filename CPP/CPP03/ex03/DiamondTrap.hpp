/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <aluzingu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:13:08 by aluzingu          #+#    #+#             */
/*   Updated: 2025/02/26 10:43:23 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_TRAP
#define DIAMOND_TRAP

	#include "ScavTrap.hpp"
	#include "FragTrap.hpp"

	class DiamondTrap: public ScavTrap, public FragTrap
	{
		private:
			std::string name;
		public:
			DiamondTrap();
			DiamondTrap(const DiamondTrap &copy);
			DiamondTrap(std::string _name);
			virtual ~DiamondTrap();
			DiamondTrap &operator=(const DiamondTrap &src);
			void attack(const std::string &target);
			void whoAmI(void);
	};
#endif
