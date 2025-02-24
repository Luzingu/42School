/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:13:31 by aluzingu          #+#    #+#             */
/*   Updated: 2025/01/27 11:13:32 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

	#include "ClapTrap.hpp"

	class ScavTrap: virtual public ClapTrap
	{
		private:
			bool guarding_gate;
		public:
			ScavTrap(void);
			ScavTrap(std::string _name);
			virtual ~ScavTrap();
			ScavTrap (const ScavTrap &src);
			ScavTrap &operator=(const ScavTrap &src);
			void attack(const std::string& target);
			void guardGate(void);
	};

#endif
