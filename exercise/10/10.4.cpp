#include <iostream>

class Move
{
private:
	double x;
	double y;
public:
	Move(double a = 0, double b = 0);
	void showmove(void);
	Move add(const Move &m) const;
};

Move::Move(double a, double b)
{
	x = a;
	y = b;
}

void Move::showmove(void)
{
	std::cout << "x = " << x
			<< " y = " << y << std::endl;
}

Move Move::add(const Move &m) const
{
	Move res(this->x + m.x, this->y + m.y);
	return (res);
}

int main(void)
{
	Move a(1, 2);
	Move b(1, 1);
	Move c;

	c.showmove();
	c = a.add(b);
	c.showmove();
	return (0);
}