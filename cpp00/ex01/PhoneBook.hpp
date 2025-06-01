#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
	Contact contacts[8]; // Array to hold up to 8 contacts
	int currentIndex;    // Index for the next contact to be added
	int totalContacts;   // Total number of contacts added

	
public:
    PhoneBook();
    ~PhoneBook();
	void addContact();
	void searchContacts() const;
	void displayContact(int index) const;
    
};

#endif