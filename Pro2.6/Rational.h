#pragma once
#include <string>
using namespace std;

class Rational
{
	public:
		class Pair
		{
			int a;
			int b;
		public:
			Pair(int a = 0, int b = 0);
			Pair(const Pair&);
			Pair& operator=(const Pair&);

			int geta() const { return a; }
			int getb() const { return b; }
			void seta(int) { this->a = a; }
			void setb(int) { this->b = b; }
			
			operator string () const;
			friend istream& operator>>(istream& is, Pair&);
			friend ostream& operator<<(ostream& os, const Pair&);
			friend Pair operator-(const Pair& p1, const Pair& p2);

		};
private:
	Pair pair;
public:
	Rational(Pair p = Pair(0, 0));
	Rational(const Rational& r);
	Rational& operator=(const Rational& p);
	
	Pair getpair () const { return pair; }
	void setpair (Pair pair)	{ this->pair = pair; }
	

	operator string() const;
	friend ostream& operator<<(ostream& out, const Rational& r);
	friend istream& operator>>(istream& in, Rational& r);
	
	friend Rational operator+(const Rational& r1, const Rational& r2);
	friend Rational operator/(const Rational& r1, const Rational& r2);
	friend Rational operator-(const Rational& r1, const Rational& r2);
};

