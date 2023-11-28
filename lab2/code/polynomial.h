/*************************
 * Class Polynomial       *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#include <iostream>
#include <vector>
#include "expression.h"

class Polynomial : public Expression {
public:
	Polynomial(double d);
	Polynomial(const std::vector<double>& v);
	Polynomial(const Polynomial& p) = default;
	double operator()(double x) const;
	Polynomial& operator+=(const Polynomial& x);
	friend Polynomial operator+(Polynomial x, const Polynomial& y);
	const Polynomial operator+(double x);
	const double operator[](int i) const;
	double& operator[](int i);
	explicit virtual operator std::string() const override;

	Polynomial* clone() const override {
		return new Polynomial{ *this };
	}

private:
	std::vector<double> poly;
};

/*
 * std::vector should be used to store polinomial's coefficients
 */