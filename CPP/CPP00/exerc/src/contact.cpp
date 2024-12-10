#include "../header/header.hpp"

class Contact
{
	public:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;

	void fill_contact(void)
	{
		std::cout << "First Name: ";
		std::getline(std::cin, this->first_name);
		std::cout << "Last Name: ";
		std::getline(std::cin, this->last_name);
		std::cout << "Nick Name: ";
		std::getline(std::cin, this->nickname);
		std::cout << "Phone Number: ";
		std::getline(std::cin, this->phone_number);
		std::cout << "Darkest Secret: ";
		std::getline(std::cin, this->darkest_secret);
	}

	void print_contact(int index)
	{
		std::cout << std::setw(11);
		std::cout << index;
		std::cout << "|";
		std::cout << std::setw(11);
		std::cout << this->first_name.substr(0, 8) << ".";
		std::cout << "|";
		std::cout << std::setw(11);
		std::cout << this->last_name.substr(0, 8) << ".";
		std::cout << "|";
		std::cout << std::setw(11);
		std::cout << this->nickname.substr(0, 8) << ".";
	}

	void	print_contact_detail()
	{
		std::cout << "Contact Detail: " << std::endl;
		std::cout << "First Name: " << this->first_name << std::endl;
		std::cout << "Last Name: " << this->last_name << std::endl;
		std::cout << "Nick Name: " << this->nickname << std::endl;
		std::cout << "Phone Number: " << this->phone_number << std::endl;
		std::cout << "Darkest Secret: " << this->darkest_secret << std::endl;
	}
};