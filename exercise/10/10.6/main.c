#include "list.h"

int main(void)
{
	int i = -1;
	int arr[10] = {1, 2, 4, 5, 1, 6, 0, 2, 6, 9};
	List a(10);
	while (++i < 9)
		a.add((void *)(arr + i));
	a.isfull();
	a.add((void *)(arr + i));
	a.isfull();
	return (0);
}