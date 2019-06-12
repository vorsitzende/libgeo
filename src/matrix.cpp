#include <matrix.hpp>

namespace	geo{

	int		**matrixPow(int **matrix, const int r, const int c, int pow)
	{
		//matrix to store temporal values and its dinami allocation
		int **temp = new int*[r];
		for (int i = 0; i < r; i++)
			temp[i] = new int[c];
		//matrix to operate with temporal values and its dinamic allocation
		int **mirrow = new int*[r];
		for (int j = 0; j < r; j++)
			mirrow[j] = new int[c];

		//a for to write from original matrix in the temp mirrow matrix,
		//we will multply the mirror matrix.
		for (int i = 0; i < r ; i++)
			for(int j = 0; j < c; j++)
			{
				mirrow[i][j] = matrix[i][j];
				temp[i][j] = 0;
			}

		//multiplication function
		if(pow == 1)
			return (matrix);
		else
		{
			for (int z = 1; z < pow; z++)
			{
				for (int i = 0; i < r; i++)
				{
					for (int j = 0; j < c; j++)
					{
						int sum = 0;
						for (int k = 0; k < r; k++)
							sum += mirrow[i][k] * matrix[k][j];
						temp[i][j] = sum;
					}
				}

				//copying new matrix in the mirrow matrix
				for (int tmp = 0; tmp < r; tmp++)
					for (int tmp1 = 0; tmp1 < c; tmp1++)
						mirrow[tmp][tmp1] = temp[tmp][tmp1];
			}
		}
		delete temp;
		return (mirrow);
	}
}
