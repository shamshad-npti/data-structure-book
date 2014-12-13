#include <bits/stdc++.h>
using namespace std;
class complex {
	double real;
	double imag;
public:
	complex() :
			real(0), imag(0) {
	}

	complex(double real) :
			imag(0) {
		this->real = real;
	}

	complex(double real, double imag) {
		this->real = real;
		this->imag = imag;
	}

	double abs() {
		return sqrt(real * real + imag + imag);
	}

	complex conj() {
		return complex(real, -imag);
	}
	complex operator +(complex c) {
		return complex(real + c.real, imag + c.imag);
	}

	complex operator -() {
		return complex(-real, imag);
	}

	complex operator -(complex c) {
		return (*this) + (-c);
	}

	complex operator *(complex c) {
		return complex(real * c.real - imag * c.imag,
				imag * c.real + c.imag * real);
	}

	complex operator /(complex c) {
		double a = c.real * c.real + c.imag * c.imag;
		complex d = (*this) * c.conj();
		d.real = d.real / a;
		d.imag = d.imag / a;
		return d;
	}

};
