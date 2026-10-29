#ifndef __PHONEBOOK__
#define __PHONEBOOK__

#include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		PhoneBook(const PhoneBook &);
		~PhoneBook();
		PhoneBook &operator=(const PhoneBook &);

		void AddContact();
		void PrintContacts();
		Contact &getContact(int pos);
		const int &getNbContacts() const;

	private:
		int createContact(Contact &new_contact);
		Contact PB_contacts[8];
		int		nb_contact;

};

#endif
