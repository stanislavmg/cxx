#ifndef STRING2_H
#define STRING2_H

#include <iostream>
#include <cstring>
#include <cstdlib>

class String2
{
private:
	char *str;
	size_t len;
public:
	String2();
	String2(const char *s);
	String2(String2 &s);
	~String2();
	size_t	string_len(void) const {return (len);}
	void	string_low();
	void	string_up();
	int		string_chr(char ch);

	String2 &operator+(String2 &s);
	String2 &operator+(const char *s);
	String2 &operator=(String2 &s);
	String2 &operator=(const char *s);
	char	&operator[](int i) const;

	friend bool 		operator<(const String2 &s1, const String2 &s2);
	friend bool 		operator>(const String2 &s1, const String2 &s2);
	friend bool 		operator==(const String2 &s1, const String2 &s2);
	friend std::ostream &operator<<(std::ostream &os, const String2 &s);
	friend std::istream &operator>>(std::istream &is, String2 &s);

};

#endif