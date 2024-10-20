#ifndef CD_H
#define CD_H

#include <iostream>
#include <cstring>

class Cd
{
private:
	char	*performers;
	char	*label;
	int		selections;
	double	playtime;
public:
	Cd(const char *s1, const char *s2, int n, double x);
	Cd(const Cd &d);
	Cd();
	virtual ~Cd();
	virtual void Report() const;
	Cd &operator=(const Cd &d);
};

class Classic : public Cd
{
private:
	char *name;
public:
	Classic();
	Classic(const char *nm, const char *s1, const char *s2, int n, double x);
	~Classic();
	virtual void Report() const;
	Cd &operator=(const Classic &d);
};

#endif