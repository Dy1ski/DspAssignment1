
// COS30008, Tutorial 3, 2018

#include "Polynomial.h"
#include <cmath>

using namespace std;

Polynomial::Polynomial()
{
	fDegree = 0;

	for (int i = 0; i < MAX_DEGREE; i++)
	{
		fCoeffs[i] = 0.0;
	}
}

Polynomial Polynomial::operator*(const Polynomial& aRight) const
{
	Polynomial Result;

	Result.fDegree = fDegree + aRight.fDegree;

	for (int i = 0; i <= fDegree; i++)
	{
		for (int j = 0; j <= aRight.fDegree; j++)
		{
			// aggregate (sum up) ith and jth coefficients
			Result.fCoeffs[i + j] += fCoeffs[i] * aRight.fCoeffs[j];
		}
	}

	return Result;
}

istream& operator>>(istream& aIStream, Polynomial& aObject)
{
	// read degree
	aIStream >> aObject.fDegree;

	// read coefficients (assume sound input)
	for (int i = 0; i <= aObject.fDegree; i++)
	{
		aIStream >> aObject.fCoeffs[i];
	}

	return aIStream;
}

ostream& operator<<(ostream& aOStream, const Polynomial& aObject)
{
	bool lMustAddPlus = false;

	for (int i = 0; i <= aObject.fDegree; i++)
	{
		if (aObject.fCoeffs[i] != 0.0)
		{
			if (lMustAddPlus)
				aOStream << " + ";

			aOStream << aObject.fCoeffs[i] << "x^" << i;
			lMustAddPlus = true;
		}
	}

	return aOStream;
}

double Polynomial::operator()(double aX) const
{
	double cResult = 0.0;
	Polynomial rPoly;
	for (int i = 0; i <= fDegree; i++)
	{
		cResult += fCoeffs[i] * pow(aX, i);
	
	}
	return cResult; // place value for now
}

Polynomial Polynomial::computeIndefiniteIntegral()const
{
	Polynomial Integal;
	Integal.fDegree = fDegree + 1;
	for (int i = 0; i <= Integal.fDegree; i++)
	{
		Integal.fCoeffs[i + 1] = fCoeffs[i] / (i + 1); // populating the array and assigning the value

	}

	return Integal;
}

double Polynomial::calculateDefiniteIntegral(double aXlow, double aXhigh) const
{
	Polynomial Definite;
	
	return ((((*this).computeIndefiniteIntegral().operator()(aXhigh)) - ((*this).computeIndefiniteIntegral().operator()(aXlow))));
}
