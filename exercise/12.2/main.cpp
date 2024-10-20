#include "string2.h"

int main(void)
{
	String2 s1("hello, i'm s1");
	String2 s2(s1);
	String2 s3;

	s2 + " but in s2";
	s3 = "hello i'm s3 aaaaa";
	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
	std::cout << s3 << std::endl;
	s3.string_up();
	std::cout << "after string_up: " << s3 << std::endl;
	s3.string_low();
	std::cout << "after string_low: " << s3 << std::endl;
	std::cout << "char a in s3: " << s3.string_chr('a') << std::endl;
	std::cin >> s3;
	std::cout << "s3 after cin: " << s3 << std::endl;
	return (0);
}