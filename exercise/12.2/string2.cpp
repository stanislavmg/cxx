#include "string2.h"

String2::String2()
{
	str = nullptr;
	len = 0;
}

String2::String2(const char *s)
{
	len = strlen(s);
	str = new char [len + 1];
	strcpy(str, s);
}

String2::String2(String2 &s)
{
	str = nullptr;
	*this = s;
}

String2::~String2()
{
	delete [] str;
}

void	String2::string_low()
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
}

void	String2::string_up()
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
}

int		String2::string_chr(char ch)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (ch == str[i])
			count++;
		i++;
	}
	return (count);
}


String2 &String2::operator+(String2 &s)
{
	char *tmp;
	
	len += strlen(s.str);
	tmp = new char [len + 1];
	strcpy(tmp, str);
	strcat(tmp, s.str);
	delete [] str;
	str = tmp;
	return (*this);
}

String2 &String2::operator+(const char *s)
{
	char *tmp;
	
	len += strlen(s);
	tmp = new char [len + 1];
	strcpy(tmp, str);
	strcat(tmp, s);
	delete [] str;
	str = tmp;
	return (*this);
}

String2 &String2::operator=(String2 &s)
{
	if (this == &s)
		return (*this);
	delete [] str;
	str = new char [s.len + 1];
	strcpy(str, s.str);
	len = s.len;
	return (*this);
}

String2 &String2::operator=(const char *s)
{
	delete [] str;
	len = strlen(s);
	str = new char [len + 1];
	strcpy(str, s);
	return (*this);
}

char	&String2::operator[](int i) const
{
	return (str[i]);
}


bool operator<(const String2 &s1, const String2 &s2)
{
	return (std::strcmp(s1.str, s2.str) < 0);
}

bool operator>(const String2 &s1, const String2 &s2)
{
	return (s1.str > s2.str);
}

bool operator==(const String2 &s1, const String2 &s2)
{
	return (std::strcmp(s1.str, s2.str) == 0);
}

std::ostream &operator<<(std::ostream &os, const String2 &s)
{
	os << s.str;
	return (os);
}

std::istream &operator>>(std::istream &is, String2 &s)
{
	char buf[1024];
	is.get(buf, 1024);
	if (is)
		s = buf;
	while (is && is.get() != '\n')
		continue ;
	return (is);
}
