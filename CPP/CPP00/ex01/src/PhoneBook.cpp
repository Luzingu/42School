#include "../include/PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->index = 0;
}

PhoneBook::~PhoneBook(void)
{
	
}

void PhoneBook::ft_add(void)
{
	if(this->index == 8)
	{
		int 	i;
		i = 0;
		while (i < (this->index - 1))
		{
			contacts[i] = contacts[i + 1];
			i++;
		}
		this->index = 7;
	}
	contacts[this->index].fill_contact();
	this->index++;
}

void PhoneBook::ft_search(void)
{
	int i;

	i = 0;
	 std::cout << std::setw(10) << std::right << "Index"
              << " | " << std::setw(10) << std::right << "First Name"
              << " | " << std::setw(10) << std::right << "Last Name"
              << " | " << std::setw(10) << std::right << "Nick Name"
              << std::endl;
	std::cout << std::endl;
	while (i < this->index)
	{
		contacts[i].print_contact(i);
		std::cout << std::endl;
		i++;
	}
	if(this->index > 0)
	{
		std::string letra;

		std::cout << "Search contact by Index: ";
		std::getline(std::cin, letra);
		if (std::cin.eof())
			return ;
		if(!(letra[0] >=48 && letra[0] <= 57) || letra.size() > 1)
			i = -1;
		else
			i = (int) letra[0] - 48;
		if (i >= this->index || i < 0)
			std::cout << "Index Nof Found!" << std::endl;
		else
			contacts[i].print_contact_detail();
	}
}