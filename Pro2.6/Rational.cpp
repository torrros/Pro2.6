#include "Rational.h"
#include <iostream>
#include<sstream>
using namespace std;

Rational::Pair::Pair(int a, int b)
{
	seta(a);
	setb(b);
}

Rational::Pair::Pair(const Rational::Pair& p)
{
	*this = p;
}

Rational::Pair::operator string()const
{
	stringstream ss;
	ss << a << "/" << b;
	return ss.str();
}

Rational::Pair& ::Rational::Pair::operator=	(const Rational::Pair& p)
{
	a = p.a;
	b = p.b;
	return *this;
}

ostream& operator<<(ostream& os, const Rational::Pair& p)
{
	os << string(p);
	return os;
}

istream& operator>>(istream& is,  Rational::Pair& p)
{
	cout << " a - ";
	cin >> p.a;
	cout << " b - ";
	cin >> p.b;
	return is;
}

Rational::Pair operator-( const Rational::Pair& p1, const Rational::Pair& p2)
{
	return Rational::Pair(p1.a - p2.a, p1.b - p2.b);
}

Rational::Rational(Pair p)
{
	setpair(p);
}

Rational::Rational(const Rational& p)
{
	*this = p;
}

Rational& Rational::operator=(const Rational& p)
{
	pair = p.pair;
	return *this;
}

Rational::operator string()const
{
	stringstream ss;
	ss << pair.geta() << '/' << pair.getb();
	return ss.str();
}

istream& operator>>(istream& is, Rational& r)
{
	int a, b;
	cout << " a -  "; cin >> a;
	cout << " b -  "; cin >> b;
	r.pair = { a, b };
	return is;
}

ostream& operator<<(ostream& os, const Rational& r)
{
	os << string(r);
	return os;
}

Rational operator/ (const Rational& r1, const Rational& r2)
{
	return Rational{ (r1.pair.geta() * r2.pair.getb(), r1.pair.getb() * r2.pair.geta()) };
}

Rational operator+ (const Rational& r1, const Rational& r2)
{
	return Rational{ (r1.pair.geta() + r2.pair.getb(), r1.pair.getb() + r2.pair.geta()) };
}

Rational operator- (const Rational& r1, const Rational& r2)
{
	return Rational{ (r1.pair.geta() - r2.pair.getb(), r1.pair.getb() - r2.pair.geta()) };
}