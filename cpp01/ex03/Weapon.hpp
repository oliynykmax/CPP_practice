#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
	public:
	std::string getType() const;
	void setType(std::string newType);
	Weapon(std::string type);
	~Weapon();
	private:
	std::string type;
};

#endif
