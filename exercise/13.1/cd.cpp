#include "cd.h"

Cd::Cd(const char *s1, const char *s2, int n, double x)
{
	performers = new char [strlen(s1) + 1];
	label = new char [strlen(s2) + 1];
	strcpy(performers, s1);
	strcpy(label, s2);
	selections = n;
	playtime = x;
}

Cd::Cd(const Cd &d)
{
	*this = d;
}

Cd::Cd()
{
	performers = nullptr;
	label = nullptr;
	selections = 0;
	playtime = 0.0;
}

Cd::~Cd()
{
	delete [] performers;
	delete [] label;
}

void Cd::Report() const
{
	std::cout << "Performers: " << performers << std::endl;
	std::cout << "Label: " << label << std::endl;
	std::cout << "Selections: " << selections << std::endl;
	std::cout << "Playtime: " << playtime << std::endl;
}

Cd &Cd::operator=(const Cd &d)
{
	if (this == &d)
		return (*this);
	delete [] performers;
	delete [] label;
	performers = new char [strlen(d.performers) + 1];
	label = new char [strlen(d.label) + 1];
	strcpy(performers, d.performers);
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
	return (*this);
}

Classic::Classic()
{
	name = nullptr;
}

Classic::Classic(const char *nm, const char *s1, const char *s2, int n, double x) : Cd(s1, s2, n, x)
{
	name = new char [strlen(nm) + 1];
	strcpy(name, nm);
}

Classic::~Classic()
{
	delete [] name;
}

void Classic::Report() const
{
	Cd::Report();
	std::cout << "Name: " << name << std::endl;
}

Cd &Classic::operator=(const Classic &d)
{
	if (this == &d)
		return (*this);
	Cd::operator=(d);
	delete [] name;
	name = new char [strlen(d.name) + 1];
	strcpy(name, d.name);
	return (*this);
}