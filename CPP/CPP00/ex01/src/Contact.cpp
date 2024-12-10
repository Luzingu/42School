#include "../include/Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void Contact::fill_contact(void)
{
	std::cout << "First Name: ";
	std::getline(std::cin, this->first_name);
	if(std::cin.eof())
		return ;
	std::cout << "Last Name: ";
	std::getline(std::cin, this->last_name);
	if(std::cin.eof())
		return ;
	std::cout << "Nick Name: ";
	std::getline(std::cin, this->nickname);
	if(std::cin.eof())
		return ;
	std::cout << "Phone Number: ";
	std::getline(std::cin, this->phone_number);
	if(std::cin.eof())
		return ;
	std::cout << "Darkest Secret: ";
	std::getline(std::cin, this->darkest_secret);
}

void Contact::print_contact(int index)
{

	std::cout << std::setw(10) << std::right << index
      << " | " << std::setw(10) << std::right << this->truncate(this->first_name)
      << " | " << std::setw(10) << std::right << this->truncate(this->last_name)
      << " | " << std::setw(10) << std::right << this->truncate(this->nickname);
}

std::string Contact::truncate(const std::string& str)
{
    return str.size() > 10 ? str.substr(0, 9) + "." : str;
}

void	Contact::print_contact_detail(void)
{
	std::cout << "Contact Detail: " << std::endl;
	std::cout << "First Name: " << Contact::first_name << std::endl;
	std::cout << "Last Name: " << Contact::last_name << std::endl;
	std::cout << "Nick Name: " << Contact::nickname << std::endl;
	std::cout << "Phone Number: " << Contact::phone_number << std::endl;
	std::cout << "Darkest Secret: " << Contact::darkest_secret << std::endl;
}