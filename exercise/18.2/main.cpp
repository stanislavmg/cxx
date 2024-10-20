#include "cpmv.hpp"


int main(void)
{
	std::string test1("test1");
	std::string test2("test2");
	Cpmv a;
	Cpmv b(test1, test2);

	a.Display();
	b.Display();
	a = b + a;
	std::cout << "a after a = b + a" << std::endl;
	a.Display();
	std::cout << "b after a = b + a" << std::endl;
	b.Display();

	return 0;
}