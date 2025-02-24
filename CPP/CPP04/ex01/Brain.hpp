/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:14:42 by aluzingu          #+#    #+#             */
/*   Updated: 2025/01/29 10:14:44 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

	#include <string>
	#include <iostream>

	class Brain
	{
		private:
			std::string _ideas[100];

		public:
			Brain();
			Brain(const Brain &copy);

			virtual ~Brain();
			Brain &operator=(const Brain &src);
			const std::string getIdea(size_t i)const;
			const std::string *getIdeaAddress(size_t i)const;
			void setIdea(size_t i, std::string idea);
	};
#endif
