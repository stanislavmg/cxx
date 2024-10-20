#include <string>
#include <iostream>

void	string_up(std::string &str);

int main(void)
{
	std::string str;

	while (1)
	{
		std::cout << "Enter a string (q to quit) : " << std::endl;
		std::getline(std::cin, str);
		if (str == "q")
		{
			std::cout << "Bye!" << std::endl;
			break ;
		}
		string_up(str);
		std::cout << str << std::endl;
	}
	return 0;
}

void	string_up(std::string &str)
{
	int	i;

	i = -1;
	while (str[++i])
		str[i] = toupper(str[i]);
}