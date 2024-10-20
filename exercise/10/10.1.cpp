#include <iostream>
#include <string>

class Bank
{
private:
	std::string name_;
	std::string num_;
	int			balance_;
public:
	Bank();
	Bank(std::string name, std::string num, int balance);
	void show(void);
	void add(int money);
	void get(int money);
};

Bank::Bank(std::string name, std::string num, int balance)
{
	name_ = name;
	num_ = num;
	balance_ = balance;
}

Bank::Bank()
{
	name_ = "no name";
	num_ = "0";
	balance_ = 0;
}

void Bank::show(void)
{
	std::cout << name_ << std::endl;
	std::cout << num_ << std::endl;
	std::cout << balance_ << std::endl;
}

void Bank::add(int money)
{
	if (money < 0)
		std::cout << "Incorrect amount to withdraw\n" << std::endl;
	else
		balance_ += money;
}

void Bank::get(int money)
{
	if (money < 0 || money > balance_)
		std::cout << "Incorrect amount to withdraw\n" << std::endl;
	else
		balance_ -= money;
}

int main(void)
{
	Bank m1("John Brener", "009223577890", 23456);
	Bank m2;
	m1.show();
	m2.show();
	m1.get(10000);
	m1.add(100);
	m1.show();
	return (0);
}
