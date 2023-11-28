/*********************************************************
 * Class Polynomial member functions implementation       *
 * TNG033: Lab 2                                          *
 **********************************************************/

#include "polynomial.h"
#include <cmath>
#include <format>

// ADD implementation of the member functions for class Polynomial
Polynomial::Polynomial(double d) { poly.push_back(d); }
Polynomial::Polynomial(const std::vector<double>& v): poly{v}{}
double Polynomial::operator()(double x) const {
	double sum = 0.0;
	for (int i = 0; i < std::size(poly); i++) {
		sum += poly[i] * std::pow(x, i);
	}
	return sum;
}

//Kolla här
Polynomial& Polynomial::operator+=(const Polynomial& x) {
	for (int i = 0; i < std::size(poly); i++) {
		if (i <= std::ssize(poly)) {
			poly[i] += x.poly[i];
		}
		else {
			poly[i] += x.poly[i];
		}
	}
	return *this;
}
Polynomial operator+(Polynomial x, const Polynomial& y) {
	x += y;
	return x;
}
const Polynomial Polynomial::operator+(double x) {
	poly[0] += x;
	return *this;
}
const double Polynomial::operator[](int i) const {
	return poly[i];
}
double& Polynomial::operator[](int i) {
	return poly[i];
}
Polynomial::operator std::string() const {
	std::string result;
	for (int i = 0; i < std::ssize(poly); i++) {
		if (i == 0) {
			 result += std::format("{:.2f}", poly[i]);
		}
		else {
			char sign = '+';
			if (poly[i] < 0) {
				sign = '-';
			}
			result += std::format("{} {:.2f} * X^{}", sign, std::abs(poly[i]), i);
		}
	}
	return result;
}