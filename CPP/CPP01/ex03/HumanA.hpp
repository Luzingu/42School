/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:31:18 by aluzingu          #+#    #+#             */
/*   Updated: 2025/01/09 13:31:19 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP
	
	#include "Weapon.hpp"

	class HumanA
	{
		private:
			std::string name;
			Weapon &weapon;
		public:
			HumanA(std::string _name, Weapon &_weapon);
			~HumanA(void);
			void attack();
	};
#endif
