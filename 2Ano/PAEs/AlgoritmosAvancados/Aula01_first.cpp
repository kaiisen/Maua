#include <iostream>
#include <math.h>

using namespace std;

int main() {
	cout<<"Informe os coeficientes: ";
	float a, b, c;
	cin>>a >>b >>c;
	float delta = pow(b,2) - 4*a*c;
	if (delta < 0)
		cout<<"Nao tem raizes reais!" <<endl;
	else {
		float x1 = (-b+sqrt(delta))/(2*a);
		float x2 = (-b-sqrt(delta))/(2*a);
		cout<<"x1 = " <<x1 <<", x2 = "<<x2 <<endl;
	}
	
	return 0;
}
