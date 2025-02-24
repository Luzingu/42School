/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:16:19 by aluzingu          #+#    #+#             */
/*   Updated: 2025/01/29 10:16:20 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP
	
	#include "Animal.hpp"
	#include "Brain.hpp"
	
	class Cat: public Animal
	{
		private:
			Brain* _brain;

		public:
			Cat();
			Cat(const Cat &copy);
			~Cat();
			Cat &operator=(const Cat &src);
			void makeSound(void)const;
			void getIdeas(void)const;
			void setIdea(size_t i, std::string idea);
	};

#endif
