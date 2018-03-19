#include <iostream>

#include "Polynomial.h"

using namespace std;

void tests()
{
	Polynomial A;

	while (cin >> A)
	{
		cout << "A = " << A << endl;

		cout << "Indefinite integral of A = " << A.computeIndefiniteIntegral() << endl;

		double xlow;
		double xhigh;

		cin >> xlow >> xhigh;

		cout << "Definite integral of A(xlow=" << xlow << ", xhigh=" << xhigh << ") = "
			<< A.calculateDefiniteIntegral(xlow, xhigh) << endl;
	}
}


int main()
{

	Polynomial A;
	cout << "Specify polynomial:" << endl;
	cin >> A;
	cout << "A = " << A << endl;

	double x;
	cout << "Specify value of x:" << endl;
	cin >> x;

	cout << "A(x) = " << A(x) << endl;

	cout << "Indefinite integral of A = "
		<< A.computeIndefiniteIntegral() << endl;

	cout << "Definite integral of A(xlow=0,xhigh=12.0) = "
		<< A.calculateDefiniteIntegral(0, 12.0) << endl;

	//    tests();

	return 0;
}
