#include "../include/PhoneBook.hpp"

int main()
{
	std::string comand;
	PhoneBook phone_book;

	while (comand != "EXIT")
	{
		std::cout << "Enter Comand (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, comand);
		if (comand == "ADD")
			phone_book.ft_add();
		else if(comand == "SEARCH")
			phone_book.ft_search();
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return (0);
		}
	}	
	return (0);
}