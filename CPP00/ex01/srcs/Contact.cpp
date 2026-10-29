#include "Contact.hpp"

Contact::Contact()
{
}

Contact::Contact(const Contact &other)
    : c_firstname(other.c_firstname), c_lastname(other.c_lastname),
      c_nickname(other.c_nickname), c_phone_number(other.c_phone_number),
      c_secret(other.c_secret) {}

Contact::~Contact()
{
}

Contact &Contact::operator=(const Contact &other)
{
    if (this != &other)
	{
        c_firstname = other.c_firstname;
        c_lastname = other.c_lastname;
        c_nickname = other.c_nickname;
        c_phone_number = other.c_phone_number;
        c_secret = other.c_secret;
    }
    return *this;
}

void	Contact::setFirstName(std::string firstname)
{
	c_firstname = (firstname);
};

void	Contact::setLastName(std::string lastname)
{
	c_lastname = (lastname);
};

void	Contact::setNickname(std::string nickname)
{
	c_nickname = (nickname);
};

void	Contact::setPhoneNumber(std::string phone_number)
{
	c_phone_number = (phone_number);
};

void	Contact::setSecret(std::string secret)
{
	c_secret = (secret);
};

const std::string &Contact::getFirstName() const
{
    return (c_firstname);
}

const std::string &Contact::getLastName() const
{
    return (c_lastname);
}

const std::string &Contact::getNickname() const
{
    return (c_nickname);
}

const std::string &Contact::getPhoneNumber() const
{
    return (c_phone_number);
}

const std::string &Contact::getSecret() const
{
    return (c_secret);
}

void  Contact::printContact()
{
	std::cout << getFirstName() << std::endl;
	std::cout << getLastName() << std::endl;
	std::cout << getNickname() << std::endl;
	std::cout << getPhoneNumber() << std::endl;
	std::cout << getSecret() << std::endl;
}
