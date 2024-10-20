#include <iostream>
#include <vector>
#include <algorithm>

std::string clear_str(std::string &s)
{
	std::string res;
	auto p = s.begin();

	while (p != s.end())
	{
		if (*p != ',' && *p != '.' && *p != ' ' && *p != '-' && *p != '\'' && *p != '\"')
			res.push_back(std::tolower(*p));
		p++;
	}
	return (res);
}


int main(void)
{
	std::string input;
	std::string t;
	int i;

	while (t != "q")
	{
		std::cout << "Enter word to check on palindrom or 'q' for exit:" << std::endl;
		std::getline(std::cin, t);
		input = clear_str(t);
		auto end = input.rbegin();
		auto start = input.begin();
		i = 0;
		while (++i < input.size())
		{
			if (*start != *end)
				break ;
			start++;
			end++;
		}
		if (i == input.size() && i != 1)
			std::cout << "It's a palindrom" << std::endl;
		else if (input != "q")
			std::cout << "Sorry it's not a palindrom" << std::endl;
		else
			std::cout << "Bye!" << std::endl;
		
	}
	return (0);
}