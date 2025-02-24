/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:13:06 by aluzingu          #+#    #+#             */
/*   Updated: 2025/01/29 10:13:07 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL
#define ANIMAL
	#include <iostream>

	class Animal
	{
		protected:
			std::string _type;
		public:
			Animal(void);
			Animal(const Animal &src);
			Animal &operator=(const Animal &src);
			virtual	~Animal(void);
			virtual void makeSound(void) const;
			std::string getType(void) const;
	};
#endif
