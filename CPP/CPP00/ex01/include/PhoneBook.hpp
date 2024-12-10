#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "header.h"
#include "Contact.hpp"

class PhoneBook
{
	private:
		int index;
		void	ft_last_contact();
	
	public:
		Contact contacts[8];
		PhoneBook(void);
		~PhoneBook();
		void ft_add();
		void ft_search();
		void ft_exit();
		
};

#endif
