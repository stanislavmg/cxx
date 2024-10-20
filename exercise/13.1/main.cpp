#include "cd.h"

void Bravo(const Cd &disk)
{
	disk.Report();
}

int main(void)
{
	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Piano Sonatat in B flat, Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17);

	Cd *pcd = &c1;
	std::cout << "Using object directly:\n";
	c1.Report();
	c2.Report();
	pcd->Report();
	pcd = &c2;
	pcd->Report();
	std::cout <<"Calling a function with a Cd reference argument:\n";
	Bravo(c1);
	Bravo(c2);
	std::cout << "Testing assigment: ";
	Classic copy;
	copy = c2;
	copy.Report();
	return (0);
}