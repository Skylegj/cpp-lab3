/********************************
* Автор: Чеботников Александр   *
* Задание: Циклы с ветвлениями  *
* Вариант: 30                   *
********************************/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
  const double PI = 3.141592653589793;

  double pipeLength;
  double pipeDiameter;
  double waterDensity;
  double kinematicViscosity;

  double speed;
  double reynoldsNumber;
  double frictionCoefficient;
  double pressureLoss;
  double volumeFlow;
  double requiredPower;

  int speedCount;

  cout << "l (m) = ";
  cin >> pipeLength;

  cout << "d (m) = ";
  cin >> pipeDiameter;

  cout << "rho (kg/m^3) = ";
  cin >> waterDensity;

  cout << "nu (m^2/s) = ";
  cin >> kinematicViscosity;

  cout << "Speed count = ";
  cin >> speedCount;

  cout << "w (m/s) Re lambda dp (Pa) P (W)" << endl;

  for (int speedIndex = 0; speedIndex < speedCount; ++speedIndex) {
	cout << "w (m/s) = ";
	cin >> speed;

    reynoldsNumber = speed * pipeDiameter / kinematicViscosity;

    if (reynoldsNumber < 2300.0) {
      frictionCoefficient = 64.0 / reynoldsNumber;
    } else if (reynoldsNumber >= 4000.0) {
      frictionCoefficient = 0.3164 / pow(reynoldsNumber, 0.25);
    } else {
      cout << "Unsupported transition regime" << endl;
      continue;
    }

    pressureLoss = frictionCoefficient * pipeLength / pipeDiameter * waterDensity * speed * speed / 2.0;

    volumeFlow = PI * pipeDiameter * pipeDiameter * speed / 4.0;
    requiredPower = pressureLoss * volumeFlow;

    cout << speed << " "
         << reynoldsNumber << " "
         << frictionCoefficient << " "
         << pressureLoss << " "
         << requiredPower << endl;
  }

  return 0;
}