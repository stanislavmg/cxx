#include "stack.hpp"
#include <iostream>

using namespace cnt;

int main(void)
{
	Stack<int>	s;

	for (int i = 0; i < 10; ++i){
		s.push(i);
	}
	std::cout << "max: " << s.findmax() << " min: " << s.findmin() << std::endl;
	s.pop();
	std::cout << "max: " << s.findmax() << " min: " << s.findmin() << std::endl;
	while(s.size()){
		std::cout << s.pop() << std::endl;
	}
	return 0;
}