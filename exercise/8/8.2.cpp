#include <iostream>
#include <string>

struct CandyBar
{
	std::string name;
	float		weight;
	int			kcal;
};

void	print_cb(CandyBar &node);
void	init_cb(CandyBar &node, const char *i_name, float i_weight, int i_kcal);

int main(void)
{
	CandyBar	test;

	init_cb(test, "Nesquick", 2.8, 1000);
	print_cb(test);
	return 0;
}

void	init_cb(CandyBar &node, const char *i_name, float i_weight, int i_kcal)
{
	node.name = i_name;
	node.weight = i_weight;
	node.kcal = i_kcal;
}

void	print_cb(CandyBar &node)
{
	std::cout << "Name=" << node.name << '\n'
		<< "Weight=" << node.weight << '\n'
		<< "Kcal=" << node.kcal << std::endl;
}
