#include <iostream>
#include <cstring>

class Plorg
{
private:
	static const int SIZE = 19;
	char name[SIZE];
	int ci;
public:
	Plorg(const char *nm = "Plorga", int index = 50);
	void show(void);
};

Plorg::Plorg(const char *nm, int index)
{
	strlcpy(name, nm, SIZE);
	ci = index;
}

void Plorg::show(void)
{
	std::cout << "name = " << name
			<< "\ncontentment index = " << ci << std::endl;
}

int main(void)
{
	Plorg m1;
	Plorg m2("IVAN IVANOV", 100);
	m1.show();
	m2.show();
	return (0);
}