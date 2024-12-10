#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "header.h"

class Contact
{
	public:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
		void fill_contact(void);
		void print_contact(int index);
		void	print_contact_detail(void);
		std::string truncate(const std::string& str);
		Contact(void);
		~Contact(void);
};

#endif