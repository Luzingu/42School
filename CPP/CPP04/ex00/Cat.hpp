/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:13:14 by aluzingu          #+#    #+#             */
/*   Updated: 2025/01/29 10:13:15 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP
	
	#include "Animal.hpp"
	
	class Cat: public Animal
	{
		public:
			Cat();
			Cat(const Cat &copy);
			~Cat();
			Cat &operator=(const Cat &src);
			void makeSound(void)const;
	};

#endif
