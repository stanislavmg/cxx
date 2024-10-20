#ifndef WINE_H
#define WINE_H

#include <iostream>
#include <string>
#include <utility>

class Wine
{
private:
	std::string label;
	std::pair<std::valarray<int>, std::valarray<int> > storage;
	int	bottles_num;
public:
	Wine();
	~Wine();
};

#endif