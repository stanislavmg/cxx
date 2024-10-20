#include "cow.h"

int main(void)
{
	Cow n1;
	Cow n2("Mary", "Football", 123.2);
	Cow n3(n2);

	n1.ShowCow();
	n2.ShowCow();
	n3.ShowCow();
	return (0);
}