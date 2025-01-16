/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:30:55 by aluzingu          #+#    #+#             */
/*   Updated: 2025/01/09 13:30:57 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

	#include <iostream>

	class Weapon
	{
		private:
			std::string type;
		public:
			Weapon(std::string _type);
			~Weapon(void);
			const std::string getType();
			void	setType(std::string _type);
	};
#endif
