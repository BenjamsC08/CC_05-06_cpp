#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	nb_contact = 0;
}

PhoneBook::PhoneBook(const PhoneBook &other)
{
	for (int i=0; i < 8; i++)
		PB_contacts[i] =other.PB_contacts[i];
}

PhoneBook::~PhoneBook()
{
}

PhoneBook &PhoneBook::operator=(const PhoneBook &other)
{
    if (this != &other)
	{
        for (int i=0; i < 8; i++)
	       PB_contacts[i] = other.PB_contacts[i];
    }
    return (*this);
}

int	only_space(std::string str)
{
	for (int i=0; str[i]; i++)
	{
		if (!std::isspace(str[i]))
			return (0);
	}
	return (1);
}

int	only_number(std::string str)
{
	for (int i=0; str[i]; i++)
	{
		if (!std::isdigit(str[i]))
			return (0);
	}
	return (1);
}

std::string	retry_entry(std::string type)
{
	std::string str;
	if (type != "phonenumber")
		std::cout << "Retry " << type << " (not empty) :"
			<< std::endl;
	else
		std::cout << "Retry " << type << " (only number) :"
			<< std::endl;
	std::getline(std::cin,str);
	if (str.empty() || only_space(str))
		return (std::string());
	if (type == "phonenumber" && !only_number(str))
		return (std::string());
	return(str);
}

int  PhoneBook::createContact(Contact &new_contact)
{
	Contact temp;
	std::string str;

	std::cout << "Enter firstname :" << std::endl;
	std::getline(std::cin,str);
	if (str.empty() || only_space(str))
		str = retry_entry("firstname");
	if (str.empty() || only_space(str))
		return (0);
	temp.setFirstName(str);
	std::cout << "Enter lastname :" << std::endl;
	std::getline(std::cin, str);
	if (str.empty() || only_space(str))
		str = retry_entry("lastname");
	if (str.empty() || only_space(str))
		return (0);
	temp.setLastName(str);
	std::cout << "Enter nickname :" << std::endl;
	std::getline(std::cin, str);
	if (str.empty() || only_space(str))
		str = retry_entry("nickname");
	if (str.empty() || only_space(str))
		return (0);
	temp.setNickname(str);
	std::cout << "Enter phonenumber :" << std::endl;
	std::getline(std::cin, str);
	if (str.empty() || !only_number(str))
		str = retry_entry("phonenumber");
	if (str.empty() || !only_number(str))
		return (0);
	temp.setPhoneNumber(str);
	std::cout << "Enter darkest secret :" << std::endl;
	std::getline(std::cin, str);
	if (str.empty() || only_space(str))
		str = retry_entry("secret");
	if (str.empty() || only_space(str))
		return (0);
	temp.setSecret(str);
	new_contact = temp;
	return (1);
}

void	PhoneBook::AddContact()
{
	static int i = nb_contact % 8;
	
	if (i == 8)
		i = 0;
	if (createContact(PB_contacts[i]))
	{
		if (nb_contact < 8)
			nb_contact++;
		i++;
	}
}

void	PrintData(std::string str)
{
	if(str.length() < 10)
	{
		for (int i=0;i + str.length() < 10; i++)
			std::cout << " ";
		std::cout << str << "|";
	}
	else if(str.length() == 10)
		std::cout << str << "|";
	else
		std::cout << str.substr(0,9) << ".|";
}

void	PhoneBook::PrintContacts()
{
	for (int i = 0; i < 47; i++)
		std::cout << "=";
	std::cout << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << "|" << i + 1 << "|";
		PrintData(PB_contacts[i].getFirstName());
		PrintData(PB_contacts[i].getLastName());
		PrintData(PB_contacts[i].getNickname());
		PrintData(PB_contacts[i].getPhoneNumber());
		std::cout << std::endl;
	}
	for (int i = 0; i < 47; i++)
		std::cout << "=";
	std::cout << std::endl;
}

Contact &PhoneBook::getContact(int pos)
{
	return (PB_contacts[pos - 1]);
}

const int &PhoneBook::getNbContacts() const
{
	return (nb_contact);
}
