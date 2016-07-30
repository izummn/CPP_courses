#include <stdio.h>
#include <math.h>
#include <assert.h>

const int SQEQ_INF = -1;
const double EPSILON = 0.01;


bool IsZero(double temp)
{
	return fabs(temp) <= EPSILON;
}

bool InputParametrs(double* a, double* b, double* c)
{
	printf("Equation ax^2 + bx + c = 0 \n Enter a, b, c: ");
	scanf_s("%lg %lg %lg", &a, &b, &c);
	return true;
}

void OutputResult(int nSolutions, double* x1, double* x2)
{
	if (nSolutions == 0)
	{
		printf("No solution.\n");
		return;
	}

	if (nSolutions == SQEQ_INF)
	{
		printf("Decisions are infinitely.\n");
		return;
	}

	printf("Number of solution: %d \n", nSolutions);
	printf("x1 = %lg x2 = %lg \n", *x1, *x2);
}

//ax2 + bx + c = 0

int SqEquation(double a, double b, double c, double* x1, double* x2)
{
	assert(x1);
	assert(x2);
	assert(x1 != x2);

	if (IsZero(a) && IsZero(b) && IsZero(c)) return SQEQ_INF;

	if (IsZero(a) && !IsZero(b))
	{
		*x1 = -c / b;
		return 1;
	}

	if (IsZero(a) && IsZero(b)) return 0;

	double d = b*b - 4*a*c;

	if (d < 0.) return 0;

	*x1 = (-b + sqrt(d)) / (2 * a);
	*x2 = (-b - sqrt(d)) / (2 * a);
	return 2;
}

void SqEquationTest(double a, double b, double c)
{
	printf("\n\n");
	double x1 = 0., x2 = 0.;
	int nRoots = SqEquation(a, b, c, &x1, &x2);
	OutputResult(nRoots, &x1, &x2);
}

void SqEquationTest(double a, double b, double c, bool flag)
{
	printf("\n\n");
	double x1 = 0., x2 = 0.;
	int nRoots = SqEquation(a, b, c, NULL, &x2);
	OutputResult(nRoots, &x1, &x2);
}

void StartTest()
{
	SqEquationTest(5, 92, 1);
	SqEquationTest(0, 0, 0);
	SqEquationTest(3, 3, 9);
	SqEquationTest(4, 20, 9);
	SqEquationTest(1, 4, 4);
	SqEquationTest(0, -3, -4);
	SqEquationTest(0, 0, 4);
	SqEquationTest(1, 1, 1);
	SqEquationTest(1, 1, 1, true);
}


int main()
{
	StartTest();
	return 0;
}