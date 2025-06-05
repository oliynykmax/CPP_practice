#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char **argv)
{
	if (argc != 4)
		return 1;
	std::string file_name = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	if (file_name.empty() || s1.empty()){
		std::cerr << "Error: Invalid input" << std::endl;
		return 1;
	}
	std::ifstream input(file_name);
	if (!input.is_open()){
		std::cerr << "Error: Could not open input file" << std::endl;
		return 1;
	}
	std::ofstream output(file_name + ".replace");
    if (!output.is_open()) {
        std::cerr << "Error: Could not create output file" << std::endl;
        return 1;
    }
	std::string line;
	while(std::getline(input, line))
	{
		size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos) {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length();
        }
        output << line << std::endl;
	}
	return 0;
}
