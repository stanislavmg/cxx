#include <iostream>

int sum_values(){
	return (0);
}
template <typename T, typename ... Args>
int sum_values(T val, Args... args){
	return (val + sum_values(args...));
}

int main(void){
	int sum;

	sum = sum_values(129, 0, 90, 100);
	std::cout << "sum = " << sum << std::endl;
	return (0);
}