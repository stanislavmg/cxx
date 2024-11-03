/*

Первая строка входных данных содержит единственное число n 
(1≤n≤100000) — количество событий в логе.
Следующие n строк описывают времена событий. 
Каждая строка имеет формат HH:MM:SS, где HH — число от 00 до 23,
а MM и SS — числа от 00 до 59
Все записи чисел состоят ровно из двух цифр.

Формат вывода
Выведите одно целое число — минимальное количество дней, в течение которых записывался лог.

*/

#include <iostream>
#include <string>

static const int SEC_IN_HOUR = 3600;

size_t gettime(const std::string &input)
{
	size_t t;

	t = std::stoi(input) * SEC_IN_HOUR
			+ std::stoi(&input[3]) * 60
			+ std::stoi(&input[6]);
	return t;
}

int main(void)
{
	unsigned long long all_time = 0;
	int last_time = 0;
	int num_days = 0;
	int out = 0;
	int num;

	std::cin >> num;
	if (!num){
		std::cout << "0\n";
		return 0;
	}
	for (int i = 0; i < num; ++i){
		unsigned long long timestamp;
		std::string input;

		std::cin >> input;
		timestamp = gettime(input);
		if (!timestamp)
			num_days++;
		else if (!all_time)
			all_time = timestamp;
		else if(!(timestamp - last_time))
			all_time += SEC_IN_HOUR * 24;
		else
			all_time += timestamp - last_time;
		last_time = timestamp;
	}
	out = num_days + all_time / (SEC_IN_HOUR * 24);
	if (all_time % (SEC_IN_HOUR * 24))
		++out;
	std::cout << out << '\n';
	return 0;
}