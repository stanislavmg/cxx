#include "dma.h"

// abcDMA
abcDMA::abcDMA(const char *l = "null", int r = 0)
{
	label = new char [strlen(l) + 1];
	rating = r;
}

abcDMA::abcDMA(const abcDMA &d)
{
	label = new char [strlen(d.label) + 1];
	rating = d.rating;
}

abcDMA::~abcDMA()
{
	delete [] label;
}

abcDMA &abcDMA::operator=(const abcDMA &d)
{
	if (this == &d)
		return (*this);
	delete [] label;
	label = new char [strlen(d.label) + 1];
	strcpy(label, d.label);
	rating = d.rating;
	return (*this);
}

std::ostream &operator<<(std::ostream os, const abcDMA &d)
{
	os << "lable: " << d.label << std::endl;
	os << "rating: " << d.rating << std::endl;
	return (os);
}


// lacksDMA
lacksDMA::lacksDMA(const char *c = "blank", const char *l = "null", int r = 0) : abcDMA(l, r)
{
	strcpy(color, c);
}

lacksDMA::lacksDMA(const char *c, const abcDMA &ad)
{
	strcpy(color, c);
	abcDMA::operator=(ad);
}

std::ostream &operator<<(std::ostream os, const lacksDMA &ld)
{
	os << (const abcDMA &)ld;
	os << "color: " << ld.color << std::endl;
	return (os);
}

void View()
{
	std::cout << *this << std::endl;
}

// hasDMA
hasDMA(const char *s = "none", const char *l = "null", int r = 0)
{

}

hasDMA(const hasDMA *hd)
{

}

~hasDMA()
{

}

void View()
{

}

hasDMA &operator=(const hasDMA &hd)
{

}

std::ostream &operator<<(std::ostream os, const hasDMA &hd)
{

}
