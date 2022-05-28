#include<iostream>
#include<math.h>

using namespace std;
class Polynomial;
class Term{
    friend Polynomial;
    int exp,coef;
public:
    Term(){
        exp=0;
        coef=0;
    }
    Term(int exp,int coef){
        this->coef=coef;
        this->exp=exp;
    }
    void setCoef(int coef){
        this->coef=coef;
    }
    void setExp(int exp){
        this->exp=exp;
    }
    int getCoef(){
        return coef;
    }
    
};
class Polynomial{
    Term* termArray;
    int degree;
public:
    Polynomial(){
        degree=0;
        termArray=NULL;
    }
    Polynomial(int degree)
	{
		this->degree = degree;
        termArray=new Term[degree];
        for(int i=0; i< degree ; i++){
            termArray[i].setCoef(0);
            termArray[i].setExp(i);
        }
	}

    Polynomial(int *coeff, int degree)
	{
		int i, j;
		this->degree = degree;
        termArray=new Term[degree];
        for(int i=degree , j=0; i>= 0 ; i--,j++){
            termArray[i].exp=i;
            termArray[i].coef=coeff[j];
        }

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
            res->termArray[i].coef=maxP->termArray[i].coef;
		
		for(i=0; i <= minP->degree; i++)
            res->termArray[i].coef +=minP->termArray[i].coef;
		return *res;
	}
    Polynomial operator * (Polynomial &p)
	{
		Polynomial *res = new Polynomial(degree+p.degree+1);
		int i, j;
		for(i=degree; i>=0; i--)
			for(j=p.degree; j>=0; j--)
                res->termArray[i+j].coef += termArray[i].coef * p.termArray[j].coef;

		return *res;
	}
    int operator [] (int x)
	{
		int i, res = 0;
		for(i=0; i<=degree; i++)
            res+=termArray[i].coef * pow(x,i);
		return res;
	}
    friend istream& operator >> (istream &in, Polynomial &p)
	{
		cout << "Enter the Degree: ";
		in >> p.degree;
		cout << "Enter the coefficients(Highest Power First): ";
        p.termArray=new Term[p.degree];
        int temp;
		for(int i=p.degree; i>=0; i--){
            in >> temp;
            p.termArray[i].setCoef(temp);
        }
		return in;
	}
    friend ostream& operator << (ostream &out, Polynomial &p)
	{
		out << "Polynomial: ";
		for(int i=p.degree; i>=0; i--)
		{
			if(p.termArray[i].getCoef() != 0)
			{	out << p.termArray[i].getCoef();
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
	int p1[5] = {5, 9, 2, 4,6};
	int p2[4] = {1, 3, 5,9};
	Polynomial P1(p1, 4), P2(p2, 3);
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