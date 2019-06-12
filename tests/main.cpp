#include <iostream>
#include "../src/matrix.cpp"

int		main(void)
{
	int		**a;
	int		**p;
	int		n, pow;

	std::cin >> n >> pow;
	a = new int*[n];
	p = new int*[n];

	for (int i = 0; i < n; i++)
	{
		a[i] = new int[n];
		p[i] = new int[n];
	}
	printf("Insert the matrix\n");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			std::cin >> a[i][j];

	p = geo::matrixPow(a, n, n, pow);
	printf("A ^ %d is:\n", pow);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			std::cout<<p[i][j]<<" ";
		std::cout<<"\n";
	}
	return (0);
}
