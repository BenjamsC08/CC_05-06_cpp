#ifndef __CONTACT__
#define __CONTACT__

#include <iostream> 
#include <string> 

class Contact
{
	public:
		Contact();
		Contact(const Contact &);
		~Contact();
		Contact &operator=(const Contact &);

		const std::string &getFirstName() const ;
		const std::string &getLastName() const ;
		const std::string &getNickname() const ;
		const std::string &getPhoneNumber() const ;
		const std::string &getSecret() const ;
		void printContact();

		void setFirstName(std::string firstname);
		void setLastName(std::string lastname);
		void setNickname(std::string nickname);
		void setPhoneNumber(std::string phone_number);
		void setSecret(std::string secret);
	private:
		std::string c_firstname;
		std::string c_lastname;
		std::string c_nickname;
		std::string c_phone_number;
		std::string c_secret;
};

#endif
