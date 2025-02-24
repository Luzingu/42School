/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:26:42 by aluzingu          #+#    #+#             */
/*   Updated: 2025/01/29 10:26:47 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

	#include "Animal.hpp"
	#include "Brain.hpp"

	class Dog: public Animal
	{
		private:
			Brain* _brain;
		public:
			Dog();
			Dog(const Dog &copy);
			~Dog();
			Dog &operator=(const Dog &src);
			void makeSound(void) const;
			void getIdeas(void)const;
			void setIdea(size_t i, std::string idea);
	};
#endif
