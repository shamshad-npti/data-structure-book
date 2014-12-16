#include <bits/stdc++.h>
using namespace std;
namespace rtl {
class rational {
	int n;
	int d;
	int gcd(int a, int b) {
		int c;
		if (a < b) {
			c = a;
			a = b;
			b = c;
		}
		while (b != 0) {
			c = a % b;
			a = b;
			b = c;
		}
		return a;
	}

	int lcm(int a, int b) {
		return a / gcd(a, b) * b;
	}

	void reduce() {
		int g;
		if (n != 0 && (g = gcd(abs(n), d)) != 1) {
			this->n = n / g;
			this->d = d / g;
		}
	}
public:

	rational() :
			n(1), d(1) {
	}

	rational(int n) :
			n(n), d(1) {
	}

	rational(int n, int d) {
		if (d == 0)
			throw "not a rational number";
		if (d < 0) {
			d = -d;
			n = -n;
		}
		this->n = n;
		this->d = d;
		reduce();
	}

	rational(const rational &r) {
		this->n = r.n;
		this->d = r.d;
	}

	bool operator ==(rational r) {
		return this->n == r.n && this->d == r.d;
	}

	bool operator !=(rational r) {
		return !(*this == r);
	}

	bool operator >(rational r) {
		int l = lcm(this->d, r.d);
		return this->d / l * this->n > r.d / l * r.n;
	}

	bool operator >=(rational r) {
		return !(*this < r);
	}

	bool operator <(rational r) {
		int l = lcm(this->d, r.d);
		return this->d / l * this->n < r.d / l * r.n;
	}

	bool operator <=(rational r) {
		return !(*this > r);
	}

	rational operator+(rational r) {
		int l = lcm(this->d, r.d);
		return rational(l / this->d * this->n + l / r.d * r.n, l);
	}

	rational operator-() {
		return rational(-n, d);
	}

	rational operator-(rational r) {
		return (*this) + (-r);
	}

	rational operator*(rational r) {
		int g1 = gcd(this->n, r.d);
		int g2 = gcd(this->d, r.n);
		return rational((this->n / g1) * (r.n / g2),
				(this->d / g2) * (r.d / g1));
	}

	rational operator/(rational r) {
		rational r1;
		r1.d = r.n;
		r1.n = r.d;
		return *this * r1;
	}

	operator double() {
		return 1.0 * n / d;
	}

};
}
