#include "Contact.hpp"

Contact::Contact() : _firstName(""), _lastName(""), _nickName(""),
                    _phoneNumber(""), _darkestSecret("") {}

Contact::~Contact() {}

void Contact::setFirstName(const std::string& fname) {
    _firstName = fname;
}

void Contact::setLastName(const std::string& lname) {
    _lastName = lname;
}

void Contact::setNickname(const std::string& nname) {
    _nickName = nname;
}

void Contact::setPhoneNumber(const std::string& phone) {
    _phoneNumber = phone;
}

void Contact::setDarkestSecret(const std::string& secret) {
    _darkestSecret = secret;
}

const std::string Contact::getFirstName() const {
    return _firstName;
}

const std::string Contact::getLastName() const {
    return _lastName;
}

const std::string Contact::getNickName() const {
    return _nickName;
}

const std::string Contact::getPhoneNumber() const {
    return _phoneNumber;
}

const std::string Contact::getDarkestSecret() const {
    return _darkestSecret;
}
