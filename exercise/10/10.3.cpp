#include <iostream>
#include <string>

struct customer
{
	char fullname[35];
	double payment;
};

class Stack
{
private:
	static const int	SIZE_STACK = 10;
	customer 			*new_list[SIZE_STACK];
	int 				top;
	double 				sum;
public:
	Stack(){new_list[0] = NULL; sum = 0.0; top = 0;}
	void pop(customer &node);
	void push(void);
	void show(void);
};

void Stack::pop(customer &node)
{
	if (top >= SIZE_STACK)
		std::cout << "Stack is full" << std::endl;
	else
	{
		new_list[top] = &node;
		top++;
	}
}

void Stack::push(void)
{
	if (!top)
		std::cout << "Stack is empty" << std::endl;
	else
	{
		top--;
		sum += new_list[top]->payment;
		new_list[top] = NULL;
	}
}

void Stack::show(void)
{
	int i;
	
	i = -1;
	while (++i < top)
	{
		std::cout << new_list[i]->fullname << '\n'
				<< "payment = " << new_list[i]->payment << std::endl;
	}
	std::cout << "Sum = " << sum << std::endl;
}

int main(void)
{
	customer arr[3] = {{"A", 100.0}, {"B", 200.0}, {"C", 300.0}};
	Stack stack_a;

	stack_a.pop(arr[0]);
	stack_a.pop(arr[1]);
	stack_a.pop(arr[2]);
	stack_a.show();
	stack_a.push();
	stack_a.show();

	return (0);
}