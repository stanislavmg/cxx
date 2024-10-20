# include "vect.h"

int main(void)
{
	using VECTOR::Vector;
	std::ofstream log("log.txt");
	double dstep;
	double direction;
	unsigned long steps = 0;
	double target;
	Vector step;
	Vector result(0.0, 0.0);

	srand(time(0));
	std::cout << "Enter terget distance (q to quit):";
	while (std::cin >> target)
	{
		std::cout << "Enter step lenght: ";
		if (!(std::cin >> dstep))
			break;
		log << "Target Distance: " << target << ", Step Size: " << dstep << std::endl;
		while (result.magval() < target)
		{
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			log << steps << ": " << result << std::endl;
			steps++;
		}
		log << steps << ": " << result << std::endl;
		std::cout << "After " << steps << " steps, the subject "
				"has the following location:\n";
		std::cout << result << std::endl;
		result.polar_mode();
		std::cout << " or\n" << result << std::endl;
		std::cout << "Average outward distance per step = "
				<< result.magval() / steps << std::endl;
		steps = 0;
		result.reset(0.0, 0.0);
		std::cout << "Enter target distance (q to quit): ";
	}
	std::cout << "Bye!\n";
	std::cin.clear();
	while (std::cin.get() != '\n')
		continue;
	return (0);
}