#include <iostream>
#include <cstring>

struct stringy
{
	char *str;
	int ct;
};

void set(stringy &node, char *s2);
template <typename T>
void show(T &node, int count = 1);
template <> void show<stringy>(stringy &node, int count);

int main(void)
{
	stringy beany;
	char testing[] = "Reallty isn't what it used to be.";
	set(beany, testing);
	show(beany);
	show(beany, 2);
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);
	show(testing, 3);
	show("Done!");
	return (0);
}

template <typename T>
void show(T &node, int count)
{
	while (count--)
		std::cout << node << std::endl;
}

template <> void show<stringy>(stringy &node, int count)
{
	while (count--)
		std::cout << node.str << std::endl;	
}


void set(stringy &node, char *s2)
{
	node.ct = strlen(s2);
	node.str = new char[node.ct + 1];
	strcpy(node.str, s2);
}