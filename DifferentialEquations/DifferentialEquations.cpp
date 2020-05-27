#include <iostream>
using namespace std;

class DifferentialEquations {
private:
	double func(double x, double y);
	double fiRk2(double x, double y, double h);
	double fiRk4(double x, double y, double h);
public:
	void calculateRk2(double x, double y, double h, int N);
	void calculateRk4(double x, double y, double h, int N);
	void calculateEulers(double x, double y, double h, int N);

};
double DifferentialEquations::func(double x, double y) {
	return (x * x + y);
}


double DifferentialEquations::fiRk2(double x, double y, double h) {
	double k[2];
	k[0] = func(x, y),
		k[1] = func(x + h, y + h * k[0]);
	return 0.5 * (k[0] + k[1]);
}

double DifferentialEquations::fiRk4(double x, double y, double h) {
	double k[4];
	k[0] = func(x, y),
		k[1] = func(x + 0.5 * h, y + 0.5 * h * k[0]),
		k[2] = func(x + 0.5 * h, y + 0.5 * h * k[1]),
		k[3] = func(x + h, y + h * k[2]);
	return (k[0] + 2.0 * k[1] + 2.0 * k[2] + k[3]) / 6.0;
}


void DifferentialEquations::calculateRk2(double x, double y, double h, int N) {

	for (int i = 0; i < N; ++i) {
		y += h * fiRk2(x, y, h);
		x += h;
		cout << "x = " << x << " y = " << y << endl;
	}
}

void DifferentialEquations::calculateRk4(double x, double y, double h, int N) {

	for (int i = 0; i < N; ++i) {
		y += h * fiRk4(x, y, h);
		x += h;
		cout << "x = " << x << " y = " << y << endl;
	}
}

void DifferentialEquations::calculateEulers(double x, double y, double h, int N) {

	for (int i = 0; i < N; i++) {
		y += h * func(x, y);
		x += h;
		cout << "x = " << x << " y = " << y << endl;
	}
}


int main() {
	cout << "Rownanie x * x + y" << endl << endl;

	double x, y, h;
	int N = 10;
	DifferentialEquations calc;
	cout << "Podaj x0: ";
	cin >> x;
	cout << "Podaj y0: ";
	cin >> y;
	cout << "Podaj h: ";
	cin >> h;
	cout << endl;


	cout << "Metoda Eulera: " << endl;
	calc.calculateEulers(x, y, h, N);
	cout << endl << "Metoda Rungego-Kutty (RK2): " << endl;
	calc.calculateRk2(x, y, h, N);
	cout << endl << "Metoda Rungego-Kutty (RK4): "<< endl;
	calc.calculateRk4(x, y, h, N);
}