#include <iostream>
#include <initializer_list>

template <typename T>
std::initializer_list<T> average_list(std::initializer_list<T> list)
{
	return (list);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::initializer_list<T>& ilist)
{
    for (const auto& elem : ilist)
        os << elem << " ";
    return os;
}

int main(void)
{
	using namespace std;

	auto q = average_list({15.4, 10.7, 9.0});
	cout << q << endl;
	cout << average_list({20, 30, 19, 17, 45, 38}) << endl;
	auto ad = average_list<double>({'A', 70, 65.33});
	cout << ad << endl;
	return (0);
}