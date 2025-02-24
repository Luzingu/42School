/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:13:30 by aluzingu          #+#    #+#             */
/*   Updated: 2025/01/29 10:13:31 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

	#include "Animal.hpp"

	class Dog: public Animal
	{
		public:
			Dog();
			Dog(const Dog &copy);
			~Dog();
			Dog &operator=(const Dog &src);
			void makeSound(void) const;
	};
#endif
