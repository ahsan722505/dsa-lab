#include<iostream>
#include<math.h>

using namespace std;

class Polynomial{
	int *coefficients;
	int degree;
public:
	Polynomial()
	{
		degree = 0;
		coefficients = NULL;
	}
	Polynomial(int degree)
	{
		this->degree = degree;
		coefficients = new int[degree];
		for(int i=0; i<=degree; i++)
			coefficients[i] = 0;
	}

	Polynomial(int *coeff, int degree)
	{
		int i, j;
		this->degree = degree;
		coefficients = new int[degree];
		for(i=degree, j=0; i>=0; i--, j++)
			coefficients[i] = coeff[j];
	}

	Polynomial operator + (Polynomial &p)
	{
		int i;
		Polynomial *minP, *maxP, *res;
		if(degree < p.degree)
		{
			maxP = (&p);
			minP = this;
			res = new Polynomial(p.degree);
		}
		else
		{
			maxP = this;
			minP = (&p);
			res = new Polynomial(degree);
		}

		for(i=0; i <= maxP->degree; i++)
			res->coefficients[i] = maxP->coefficients[i];
		
		for(i=0; i <= minP->degree; i++)
			res->coefficients[i] += minP->coefficients[i];

		return *res;
	}
/*
	Polynomial subtract(Polynomial &p)
	{
		int i;
		bool isGreater = true;
		Polynomial *minP, *maxP, *res;
		if(degree < P.degree)
		{
			maxP = (&P);
			minP = this;
			res = new Polynomial(P.degree);
			isGreater = false;
		}
		else
		{
			maxP = this;
			minP = (&P);
			res = new Polynomial(degree);
		}

		for(i=0; i <= maxP.degree; i++)
			if( !isGreater && i > minP.degree )
				res.coefficients[i] = -maxP.coefficients[i];
			else
				res.coefficients[i] = maxP.coefficients[i];
		
		for(i=0; i <= minP.degree; i++)
			res.coefficients[i] -= minP.coefficients[i];

		return *res;
	}
*/
	Polynomial operator * (Polynomial &p)
	{
		Polynomial *res = new Polynomial(degree+p.degree+1);
		int i, j;
		for(i=degree; i>=0; i--)
			for(j=p.degree; j>=0; j--)
				res->coefficients[i+j] += coefficients[i] * p.coefficients[j];

		return *res;
	}

	int operator [] (int x)
	{
		int i, res = 0;
		for(i=0; i<=degree; i++)
			res += coefficients[i] * pow(x, i);
		return res;
	}

	friend istream& operator >> (istream &in, Polynomial &p)
	{
		cout << "Enter the Degree: ";
		in >> p.degree;
		cout << "Enter the coefficients(Highest Power First): ";
		p.coefficients = new int[p.degree];
		for(int i=p.degree; i>=0; i--)
			in >> p.coefficients[i];
		return in;
	}

	friend ostream& operator << (ostream &out, Polynomial &p)
	{
		out << "Polynomial: ";
		for(int i=p.degree; i>=0; i--)
		{
			if(p.coefficients[i] != 0)
			{	out << p.coefficients[i];
			if(i==1)
				out << "x";
			if(i!=1 && i!=0)
				out << "x^" << i;
			if(i!=0)
				out << " + "; }
		}

		out << '\n';
		return out;
	}

};

int main()
{
	int p1[4] = {2, 4, 0, 3};
	int p2[3] = {1, 3, 5};
	Polynomial P1(p1, 3), P2(p2, 2);
	//Polynomial P3;
	//cin >> P3;
	//cout << P3;
	cout << P1;
	cout << P2;
	Polynomial P3 = P1+P2;
	cout << "\nAddition:\n";
	cout << P3;
	P3 = P1*P2;
	cout << "\nMultiplication:\n";
	cout << P3;

	cout << "\nEvaluation:\n";
	int res = P1[2];
	cout << P1;
	cout << "\nValue of Polynomial at 2: " << res << '\n';
	
	return 0;
	
}