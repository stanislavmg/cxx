#include <string>
#include <iostream>
#include <cstring>

class Person
{
private:
	static const int LIMIT = 20;
	std::string lname;
	char fname[LIMIT];
public:
	Person() { lname = ""; fname[0] = 0;}
	Person(const std::string & ln, const char * fn = "Heyyou");
	void Show(void) const;
	void FormalShow(void) const;
};

Person::Person(const std::string & ln, const char *fn)
{
	lname = ln;
	strlcpy(fname, fn, LIMIT);
}

void Person::Show(void) const
{
	std::cout << lname << '\n'
			<< fname << std::endl;
}

void Person::FormalShow(void) const
{
	std::cout << fname << '\n'
			<< lname << std::endl;
}

int main(void)
{
	Person m1;
	Person m2("Ivan", "Ivanov");
	m1.Show();
	m2.Show();
	m2.FormalShow();
	return (0);
}