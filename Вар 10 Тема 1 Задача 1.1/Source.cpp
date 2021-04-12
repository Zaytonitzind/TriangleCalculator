#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

void result(double triang[])
{
	cout << "Сторона равностороннего треугольника равна " << triang[0] << endl;
	cout << "Высота равностороннего треугольника равна " << triang[1] << endl;
	cout << "Площадь равностороннего треугольника равна " << triang[2] << endl;
	cout << "Радиус вписанной окружности равностороннего треугольника равна " << triang[3] << endl;
	cout << "Радиус описанной окружности равностороннего треугольника равна " << triang[4] << endl;
}

bool checker(double triangle[])
{
	if (triangle[0] != numeric_limits<double>::infinity() && triangle[0] <= numeric_limits<double>::epsilon())
		return false;
	else if (triangle[1] != numeric_limits<double>::infinity() && triangle[1] <= NULL)
		return false;
	else if (triangle[2] != numeric_limits<double>::infinity() && triangle[2] <= NULL)
		return false;
	else if (triangle[3] != numeric_limits<double>::infinity() && triangle[3] <= NULL)
		return false;
	else if (triangle[4] != numeric_limits<double>::infinity() && triangle[4] <= NULL)
		return false;
	else
		return true;
}

double side(double triangle[])
{
	if (triangle[1] != numeric_limits<double>::infinity())
		triangle[0] = sqrt((triangle[1] * 4) / sqrt(3));
	else if (triangle[2] != numeric_limits<double>::infinity())
		triangle[0] = (triangle[2] * 2) / sqrt(3);
	else if (triangle[3] != numeric_limits<double>::infinity())
		triangle[0] = (triangle[3] * 6) / sqrt(3);
	else if (triangle[4] != numeric_limits<double>::infinity())
		triangle[0] = (triangle[4] * 3) / sqrt(3);
	return triangle[0];
}
double area(double triangle[])
{
	triangle[1] = (pow(triangle[0], 2) * sqrt(3)) / 4;
	return triangle[1];
}
double height(double triangle[])
{
	triangle[2] = (triangle[0] * sqrt(3)) / 2;
	return triangle[2];
}
double innerRadius(double triangle[])
{
	triangle[3] = (triangle[0] * sqrt(3)) / 6;
	return triangle[3];
}
double externalRadius(double triangle[])
{
	triangle[4] = (triangle[0] * sqrt(3)) / 3;
	return triangle[4];
}

void menu()
{
	double triangle[5] = { numeric_limits<double>::infinity(), numeric_limits<double>::infinity(), numeric_limits<double>::infinity(), numeric_limits<double>::infinity(), numeric_limits<double>::infinity() };
	int number;
	cout << "==Равносторонний треугольник====================================\n";
	cout << "|| Введите номер элемента для вычислений остальных параметров ||\n";
	cout << "|| 1 - Сторона a                                              ||\n";
	cout << "|| 2 - Площадь S                                              ||\n";
	cout << "|| 3 - Выстота h                                              ||\n";
	cout << "|| 4 - Радиус вписанной окружности R1                         ||\n";
	cout << "|| 5 - Радиус описанной окружности R2                         ||\n";
	cout << "================================================================\n";
	cout << "Номер элемента: ";
	cin >> number;
	switch (number) {
	case 1:
		cout << "Введите сторону равностороннего треугольника ";
		cin >> triangle[0];
		break;
	case 2:
		cout << "Введите площадь равностороннего треугольника ";
		cin >> triangle[1];
		break;
	case 3:
		cout << "Введите высоту равностороннего треугольника ";
		cin >> triangle[2];
		break;
	case 4:
		cout << "Введите радиус вписанной окружности равностороннего треугольника ";
		cin >> triangle[3];
		break;
	case 5:
		cout << "Введите радиус описанной окружности равностороннего треугольника ";
		cin >> triangle[4];
		break;
	default:
		return;
		break;
	}
	if (checker(triangle) == false)
	{
		cout << "Введено некорректное значение" << endl;
		return;
	}
	triangle[0] != numeric_limits<double>::infinity() ? triangle[0] : side(triangle);
	triangle[1] != numeric_limits<double>::infinity() ? triangle[1] : area(triangle);
	triangle[2] != numeric_limits<double>::infinity() ? triangle[2] : height(triangle);
	triangle[3] != numeric_limits<double>::infinity() ? triangle[3] : innerRadius(triangle);
	triangle[4] != numeric_limits<double>::infinity() ? triangle[4] : externalRadius(triangle);
	result(triangle);
}

int main()
{
	setlocale(LC_ALL, "rus");
	menu();
	system("pause");
	return 0;
}
