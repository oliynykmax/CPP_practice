#include <iostream>
#include <string>

int main()
{
	std::string msg = "HI THIS IS BRAIN";
	std::string *stringPTR = &msg;
	std::string &stringREF = msg;
	std::cout << "Address of msg: " << &msg << std::endl;
	std::cout << "Address of stringPTR: " << stringPTR << std::endl;
	std::cout << "Address of stringREF: " << &stringREF << std::endl;
	std::cout << "Value of msg: " << msg << std::endl;
	std::cout << "Value of *stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value of stringREF: " << stringREF << std::endl;
}
