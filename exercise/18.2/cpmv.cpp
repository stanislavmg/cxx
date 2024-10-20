#include "cpmv.hpp"

Cpmv::Cpmv(const Cpmv &cp)
{
	*this = cp;
	std::cout << "Copy construction" << std::endl;
}

Cpmv::Cpmv(Cpmv &&mv)
{
	*this = mv;
	std::cout << "Move copy construction" << std::endl;
}

Cpmv::~Cpmv() {
}

Cpmv &Cpmv::operator=(const Cpmv &cp)
{
	info.qcode = cp.info.qcode;
	info.zcode = cp.info.zcode;
	std::cout << "Copy operator=()" << std::endl;
	return (*this);
}

Cpmv &Cpmv::operator=(Cpmv &&mv)
{
	if (this == &mv)
		return (*this);
	info = std::move(mv.info);
	std::cout << "Move operator=()" << std::endl;
	return (*this);
}

Cpmv Cpmv::operator+(const Cpmv &obj) const
{
	return (Cpmv(info.qcode + obj.info.qcode, info.zcode + obj.info.zcode));
}

void Cpmv::Display() const
{
	std::cout << "info.qcode: " << info.qcode << std::endl;
	std::cout << "info.zcode: " << info.zcode << std::endl;
}
