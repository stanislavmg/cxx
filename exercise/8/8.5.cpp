#include <iostream>
#include <cstring>

template <typename T>
T max5(T arr[5]);
template <typename T>
T maxn(T *arr, int size);
template <>const char *maxn<const char *>(const char *arr[], int size);

int main(void)
{
	double arr1[5] = {1.2, 5.5, 2.2, 3.4, 9.0};
	int	arr2[7] = {2, 4 ,55, 3, 10, 1111, 234};
	char *arr3[4] = {"12345", "1234", "1", "1234567890"};

	std::cout << maxn(arr1, 5) << std::endl;
	std::cout << maxn(arr2, 7) << std::endl;
	std::cout << maxn(arr3, 4) << std::endl;
	return (0);
}

template <typename T>
T max5(T arr[5])
{
	int i;
	T res;

	i  = 0;
	res = arr[i];
	while(++i < 5)
	{
		if (res < arr[i])
			res = arr[i];
	}
	return (res);
}

template <typename T>
T maxn(T *arr, int size)
{
	int i;
	T res;

	i  = 0;
	res = arr[i];
	while (++i < size)
	{
		if (res < arr[i])
			res = arr[i];		
	}
	return (res);
}

template <> const char *maxn<const char *>(const char *arr[], int size)
{
	int i;
	size_t len;
	const char *res;

	i = 0;
	res = arr[i];
	len = strlen(arr[i]);
	while (++i < size)
	{
		if (len < strlen(arr[i]))
			res = arr[i];
	}
	return (res);
}

