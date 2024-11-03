/*
В коде сторонней библиотеки обнаружился баг. Вместо отсортированного массива строк 
библиотека возвращает массив случайно упорядоченных строк. К счастью, в каждую строку 
в случайной позиции библиотека записывает порядковый индекс – позицию, где строка 
должна быть в выходном массиве, например, "str2ing".

Ваша задача обработать баг библиотеки и написать функцию, которая:
- извлечёт индекс из строки;
- с помощью индекса расположит строку в нужной позиции.
Формат ввода

Ввод:
str3
1smth
bla2bla

Вывод:
smth
blabla
str

Примечания
- Индексы всегда начинаются с 1;
- последовательность индексов неразрывна, то есть не может быть последовательности [1,2,5];
- в каждой строке существует лишь одна последовательность чисел, то есть не может быть "st2ri3ng";
- на вход подаётся не более 10000 строк длиной не более чем 10000 символов.

*/

#include <iostream>
#include <map>
#include <string>
#include <cctype>

int get_index(std::string &s)
{
	int index = 0;
	int num = 0;
	int i = 0;

	while (num < s.size() && !std::isdigit(s[num]))
		num++;
	while (num + i < s.size() && std::isdigit(s[num + i]))
		++i;
	if (!i)
		return -1;
	index = std::stoi(s.substr(num, i));
	s.erase(num, i);
	return index;
}

int main(void)
{
	std::string input;
	std::map<int, std::string> m;

	while (1){
		std::getline(std::cin, input);
		if (input.empty())
			break ;
		int i = get_index(input);
		if (i == -1)
			break ;
		m.insert(std::make_pair(i, input));
	}
	for (auto i = m.begin(); i != m.end(); ++i){
		std::cout << i->second << '\n';
	}
	return 0;
}