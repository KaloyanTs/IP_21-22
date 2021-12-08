#include <iostream>
const unsigned ROWS = 128;
const unsigned COLUMNS = 128;

void readMatrix(int arr[][COLUMNS], unsigned r, unsigned c)
{
	std::cout << "Enter a matrix with size " << r << 'x' << c << ":\n";
	for (unsigned i = 0; i < r; ++i)
		for (unsigned j = 0; j < c; ++j)
			std::cin >> arr[i][j];
}

void printMatrix(const int arr[][COLUMNS], unsigned rows, unsigned cols)
{
	for (unsigned i = 0; i < rows; ++i)
	{
		for (unsigned j = 0; j < cols; ++j)
			std::cout << arr[i][j] << '\t';
		std::cout << '\n';
	}
}

int diagonalSum(const int arr[][COLUMNS], unsigned r, unsigned c)
{
	unsigned minDim = (r < c ? r : c), sum = 0;
	for (unsigned i = 0; i < c && i < minDim; ++i)
		sum += arr[i][i];
	return sum;
}

int revDiagProduct(const int arr[][COLUMNS], unsigned r, unsigned c)
{
	unsigned prod = 1, minDim = (r < c ? r : c);
	for (unsigned i = 0; i < minDim; ++i)
		prod *= arr[i][c - 1 - i];
	return prod;
}

int UnderDiagSum(const int arr[][COLUMNS], unsigned r, unsigned c)
{
	unsigned minDim = (r - 1 < c ? r - 1 : c), sum = 0;
	for (unsigned i = 0; i < c && i < minDim; ++i)
		sum += arr[i + 1][i];
	return sum;
}

int elementsUnderDiagSum(const int arr[][COLUMNS], unsigned r, unsigned c)
{
	int sum = 0;
	for (unsigned i = 1; i < r; ++i)
		for (unsigned j = 0; j < i; ++j)
			sum += arr[i][j];
	return sum;
}

void matrixSum(const int M1[][COLUMNS],
			   const int M2[][COLUMNS],
			   unsigned r,
			   unsigned c)
{
	for (unsigned i = 0; i < r; ++i)
	{
		for (unsigned j = 0; j < c; ++j)
			std::cout << (M1[i][j] + M2[i][j]) << '\t';
		std::cout << '\n';
	}
}

void Task1to4()
{
	int m[ROWS][COLUMNS];
	unsigned rows, cols;
	std::cout << "Enter the sizes of the matrix:\n";
	std::cin >> rows >> cols;
	readMatrix(m, rows, cols);
	printMatrix(m, rows, cols);
	std::cout << "The sum of the elements on the diagonal is: "
		<< diagonalSum(m, rows, cols) << '\n';
	std::cout << "The product of the elements on the secondary diagonal is: "
		<< revDiagProduct(m, rows, cols) << '\n';
	std::cout << "The sum of the elements under the diagonal is: "
		<< UnderDiagSum(m, rows, cols) << '\n';
	std::cout << "The sum of all elements under the diagonal is: "
		<< elementsUnderDiagSum(m, rows, cols) << '\n';
}

void Task5()
{
	int M1[ROWS][COLUMNS], M2[ROWS][COLUMNS];
	unsigned rows, cols;
	std::cout << "Enter the sizes of the matrices:\n";
	std::cin >> rows >> cols;
	readMatrix(M1, rows, cols);
	readMatrix(M2, rows, cols);
	std::cout << "The sum of the two matrices is:\n";
	matrixSum(M1, M2, rows, cols);
}

void showTranspose(const int arr[][COLUMNS], unsigned r, unsigned c)
{
	for (unsigned i = 0; i < c; ++i)
	{
		for (unsigned j = 0; j < r; ++j)
			std::cout << arr[j][i] << '\t';
		std::cout << '\n';
	}
}

void Task6()
{
	int m[ROWS][COLUMNS];
	unsigned rows, cols;
	std::cout << "Enter sizes of a matrix:\n";
	std::cin >> rows >> cols;
	readMatrix(m, rows, cols);
	std::cout << "Transposed matrix:\n";
	showTranspose(m, rows, cols);
}

void matrixMul(const int m1[][COLUMNS],
		   	   const int m2[][COLUMNS],
			   const unsigned m1rows,
			   const unsigned common,
			   const unsigned m2cols,
			   int res[][COLUMNS])
{
	for (unsigned row = 0; row < m1rows; ++row)
		for (unsigned col = 0; col < m2cols; ++col)
		{
			int tmp = 0;
			for (unsigned k = 0; k < common; ++k)
				tmp += m1[row][k] * m2[k][col];
			res[row][col] = tmp;
		}
}

void Task7()
{
	int M1[ROWS][COLUMNS];
	int M2[ROWS][COLUMNS];
	int Mult[ROWS][COLUMNS];
	unsigned rows, cols;
	unsigned m2cols;
	std::cout << "Enter sizes of first matrix:\n";
	std::cin >> rows >> cols;
	readMatrix(M1, rows, cols);
	std::cout << "Enter number of columns of second matrix:\n";
	std::cin >> m2cols;
	readMatrix(M2, cols, m2cols);
	matrixMul(M1, M2, rows, cols, m2cols, Mult);
	std::cout << "Their product is the matrix " << rows << 'x' << m2cols << ":\n";
	printMatrix(Mult, rows, m2cols);
}

bool isMagic(const int m[][COLUMNS], unsigned size)
{
	unsigned DiagSum = 0, rowSum = 0, colSum = 0, dim1 = 0;
	for (unsigned i = 0; i < size; ++i)
	{
		DiagSum += m[i][i];
		rowSum += m[size - 1 - i][i];	//моментно ползваме пром. за ред за обр. диагонал
	}
	colSum = rowSum;
	while (rowSum == DiagSum && colSum == DiagSum && dim1 < size)	//i-тата колона и ред
	{
		rowSum = colSum = 0;
		for (unsigned dim2 = 0; dim2 < size; ++dim2)
		{
			rowSum += m[dim1][dim2];
			colSum += m[dim2][dim1];
		}
		++dim1;
	}
	return (rowSum == DiagSum && colSum == DiagSum);
}

void Task8()
{
	int m[ROWS][COLUMNS];
	unsigned size;
	std::cout << "Enter size of square matrix:\n";
	std::cin >> size;
	readMatrix(m, size, size);
	std::cout << "The matrix is ";
	if (!isMagic(m, size))
		std::cout << "NOT ";
	std::cout << "a magic square.\n";
}

void spiralMatrix(unsigned rows, unsigned cols)
{
	int m[ROWS][COLUMNS];
	int rowCnt= 0, colCnt = cols - 1;
	unsigned num = 1, maxNum = rows * cols;
	int minRow = 0, maxRow = rows - 1;
	int minCol = 0, maxCol = cols - 1;
	do {
		while (rowCnt <= maxRow && num <= maxNum)
		{
			m[rowCnt++][colCnt] = num++;
		}
		--rowCnt;
		--colCnt;
		while (colCnt >= minCol && num <= maxNum)
		{
			m[rowCnt][colCnt--] = num++;
		}
		--rowCnt;
		++colCnt;
		while (rowCnt>= minRow && num <= maxNum)
		{
			m[rowCnt--][colCnt] = num++;
		}
		++rowCnt;
		++colCnt;
		while (colCnt <= maxCol-1 && num <= maxNum)
		{
			m[rowCnt][colCnt++] = num++;
		}
		++rowCnt;
		--colCnt;
		++minCol;
		--maxCol;
		++minRow;
		--maxRow;
	} while (minCol <= maxCol && minRow <= maxRow && num < maxNum);
	printMatrix(m, rows, cols);
}

void Task9()
{
	std::cout << "Enter sizes of matrix:\n";
	unsigned rows, cols;
	std::cin >> rows >> cols;
	spiralMatrix(rows, cols);
}

int main()
{
	//Task1to4();
	//Task5();	//сбор на матрици
	//Task6();	//транспониране
	//Task7();	//произведение на матрици
	//Task8();	//магически квадрат
	Task9();	//обхождане по спирала
	return 0;
}