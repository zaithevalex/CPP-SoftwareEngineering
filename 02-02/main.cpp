#include <iostream>
#include <cmath>

const double EPS = 0.000001;

enum wordNumbers {
	ZERO = 0,
	ONE = 1,
	TWO = 2,
	MANYROOTS = -1
};

// This function using for examination of value, which < EPS;
int compare(double x);

// This function solves a line equation;
void line_equation(double a, double b, double c, double &pX11, int &pRoots1);

// This function solves a square equation;
void square_equation(double a, double b, double c, double &pX1, double &pX2, int &pRoots);

// This function substitute results in switch(case);
void forSwitch(int roots, double x1, double x2);

// This function checks params a, b, c. If NAN - finished;
void determineNumber(double &a, double &b, double &c);

int main() {
    double a = NAN, b = NAN, c = NAN, x1 = 0, x2 = 0;
	int roots = 0;
	determineNumber(a, b, c);
	square_equation(a, b, c, x1, x2, roots);
	forSwitch(roots, x1, x2);
}

int compare(double x) {
	if (std::fabs(x) < EPS)
		return 1;
	return 0;
}

void line_equation(double b, double c, double &pX11, int &pRoots1) {
	if (compare(b) == 0){
		pRoots1 = 1;
		if (compare(c) == 0)
			pX11 = -c / b;
		else
			pX11 = 0;
	}
	else if (compare(c) == 0)
		pRoots1 = 0;
}

void square_equation(double a, double b, double c, double &pX1, double &pX2, int &pRoots) {
	if (compare(a) == 1 && compare(b) == 1 && compare(c) == 1){
        pRoots = MANYROOTS;
		return;
    }

    if (compare(a) == 0) {
    	double D = b * b - 4 * a * c, sqrtD = std::sqrt(D), twoA = 2 * a;
        if (D > 0){
        	pRoots = TWO;
            pX1 = (-b - sqrtD)/twoA;
            pX2 = (-b + sqrtD)/twoA;
        }
        else
            if (compare(D) == 1){
            	pRoots = ONE;
                pX1 = -b/twoA;
            }
            else if (D < 0)
            	pRoots = ZERO;
    }
    else {
    	line_equation(b, c, pX1, pRoots);
	}
}

void forSwitch(int roots, double x1, double x2) {
	switch(roots) {
		case ZERO:
			std::cout << "no roots" << std::endl;
			break;
		case ONE:
			std::cout << "one root: " << x1 << std::endl;
			break;
		case TWO:
			std::cout << "two roots: " << x1 << " " << x2 <<  std::endl;
			break;
		case MANYROOTS:
			std::cout << "infinity roots" << std::endl;
			break;
	}
}

void determineNumber(double &a, double &b, double &c) {
    std::cout << "Hello! This program can decide a square equation. Input parameters a, b, c in a space:" << std::endl;
    std::cin >> a >> b >> c;
    if (!(std::isnan(a) == 0 && std::isnan(b) == 0 && std::isnan(c) == 0)) {
		std::cout << "error: not a numbers" << std::endl;
		exit(1);
	}
}