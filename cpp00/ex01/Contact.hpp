#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
public:
    Contact();
    ~Contact();

    void setFirstName(const std::string& _firstName);
    void setLastName(const std::string& _lastName);
    void setNickname(const std::string& _nickName);
    void setPhoneNumber(const std::string& _phoneNumber);
    void setDarkestSecret(const std::string& _darkestSecret);

    const std::string getFirstName() const;
    const std::string getLastName() const;
    const std::string getNickName() const;
    const std::string getPhoneNumber() const;
    const std::string getDarkestSecret() const;

private:
    std::string _firstName {};
    std::string _lastName {};
    std::string _nickName {};
    std::string _phoneNumber {};
    std::string _darkestSecret {};
};

#endif
