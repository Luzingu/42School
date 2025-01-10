/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:31:42 by aluzingu          #+#    #+#             */
/*   Updated: 2025/01/09 13:31:44 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

	#include "Weapon.hpp"

	class HumanB
	{
		private:
			std::string name;
			Weapon *weapon;
		public:
			HumanB(std::string _name);
			~HumanB();
			void	setWeapon(Weapon &_weapon);
			void	attack();
	};
#endif
