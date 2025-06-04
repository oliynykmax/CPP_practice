#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
	Contact _contacts[8];
	int currentIndex;
	int totalContacts;
	std::string _truncate(const std::string& str) const;


public:
    PhoneBook();
    ~PhoneBook();
	void addContact();
	void searchContacts() const;
	void displayContact(int index) const;

};

#endif
