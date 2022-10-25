#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max_row 20
#define max_column 20

main()
{
	int column, row, i, j;
	int a[max_row][max_column], sum_matrix[max_row][max_column], p[max_row];
	int min, x;


	while (1)
	{
		min = 3827477;

		printf("Enter number of rows (0 to exit): ");
		scanf_s("%d", &row);

		if (row == 0)
			break;

		printf("Enter number of columns: ");
		scanf_s("%d", &column);

		srand(time(NULL));

		printf("\n");

		for (i = 0; i < row; i++)
		{
			for (j = 0; j < column; j++)
			{
				a[i][j] = rand() % 10;
			}
		}

		for (j = 0; j < column; j++)
		{
			sum_matrix[0][j] = a[0][j];
		}

		for (i = 1; i < row; i++)
		{
			for (j = 0; j < column; j++)
			{
				if (((j > 0) && (sum_matrix[i - 1][j - 1] < sum_matrix[i - 1][j]) && (sum_matrix[i - 1][j - 1] < sum_matrix[i - 1][j + 1])) || (j == column - 1 && (sum_matrix[i - 1][j - 1] < sum_matrix[i - 1][j])))
				{
					sum_matrix[i][j] = sum_matrix[i - 1][j - 1] + a[i][j];
				}
				else if (((j < column - 1) && (sum_matrix[i - 1][j + 1] < sum_matrix[i - 1][j]) && (sum_matrix[i - 1][j + 1] < sum_matrix[i - 1][j - 1])) || (j == 0 && (sum_matrix[i - 1][j + 1] < sum_matrix[i - 1][j])))
				{
					sum_matrix[i][j] = sum_matrix[i - 1][j + 1] + a[i][j];
				}
				else
				{
					sum_matrix[i][j] = sum_matrix[i - 1][j] + a[i][j];
				}
			}
		}

		for (i = 0; i < row; i++)
		{
			for (j = 0; j < column; j++)
			{
				if (i == row - 1)
				{
					if (sum_matrix[i][j] < min)
					{
						min = sum_matrix[i][j];
						x = j;
					}
				}
			}
		}


		if (row > column || row == column)
		{
			j = x;

			i = row - 1;

			while (i > 0)
			{
				p[i] = j + 1;

				if (((j > 0) && (sum_matrix[i - 1][j - 1] < sum_matrix[i - 1][j]) && (sum_matrix[i - 1][j - 1] < sum_matrix[i - 1][j + 1])) || (j == column - 1 && (sum_matrix[i - 1][j - 1] < sum_matrix[i - 1][j])))
					j = j - 1;

				else if (((j < column - 1) && (sum_matrix[i - 1][j + 1] < sum_matrix[i - 1][j]) && (sum_matrix[i - 1][j + 1] < sum_matrix[i - 1][j - 1])) || (j == 0 && (sum_matrix[i - 1][j + 1] < sum_matrix[i - 1][j])))
					j = j + 1;

				i = i - 1;
			}

			p[0] = j + 1;
		}

		if (row < column)
		{
			j = x;

			i = row - 1;

			while (i > 0)
			{
				p[i] = j + 1;

				if (((j > 0) && (sum_matrix[i - 1][j - 1] < sum_matrix[i - 1][j]) && (sum_matrix[i - 1][j - 1] < sum_matrix[i - 1][j + 1])) || (j == column - 1 && (sum_matrix[i - 1][j - 1] < sum_matrix[i - 1][j])))
					j = j - 1;

				else if (((j < column - 1) && (sum_matrix[i - 1][j + 1] < sum_matrix[i - 1][j]) && (sum_matrix[i - 1][j + 1] < sum_matrix[i - 1][j - 1])) || (j == 0 && (sum_matrix[i - 1][j + 1] < sum_matrix[i - 1][j])))
					j = j + 1;

				i = i - 1;
			}

			p[0] = j + 1;
		}

		for (i = 0; i < row; i++)
		{
			for (j = 0; j < column; j++)
			{
				if (j + 1 == p[i])
				{
					printf("[%d]\t", a[i][j]);
				}
				else
				{
					printf(" %d \t", a[i][j]);
				}
			}

			printf("\n");
		}

		printf("\nSum of weights: %d", min);

		printf("\n\n");
	}


	printf("\n\n");
	system("pause");

}

//Sude Çakmak
//152120201044