#ifndef CPMV_H
#define CPMV_H
#include <iostream>
#include <string>

class Cpmv
{
private:
	struct Info
	{
		std::string qcode;
		std::string zcode;
	    Info() : qcode("default_qcode"), zcode("default_zcode") {}
    	Info(const std::string& q, const std::string& z) : qcode(q), zcode(z) {}
	};
	Info info;
public:
	Cpmv() : info() {}
	Cpmv(std::string q, std::string z) : info(q, z) {}
	Cpmv(const Cpmv &cp);
	Cpmv(Cpmv &&mv);
	~Cpmv();
	Cpmv &operator=(const Cpmv &cp);
	Cpmv &operator=(Cpmv &&mv);
	Cpmv operator+(const Cpmv &obj) const;
	void Display() const;
};
#endif