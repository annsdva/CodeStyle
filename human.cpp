#include <iostream>
#include <string> 
#include "math.h"
using namespace std;

#define M_PI 3.14159265358979323846
#define R 6371302

class Human {
private:
	int age_m;
	double xPos;
	double yPos;

public:
	void setAge(int age) {
		age_m = age;
	}

	int getAge() {
		return age_m;
	}

	void setPosX(double x) {
		xPos = x;
	}

	void setPosY(double y) {
		yPos = y;
	}

	double getPosX() {
		return xPos;
	}

	double getPosY() {
		return yPos;
	}
};

class Walking{
private:
	float c = 0;
	double speed[1000];
	double direction[1000];

public:
	
	double makeWayX(double x, double y, int i, double alpha, double s, double d) {
		if (i == 1) {
			speed[0] = 0.0;
			direction[0] = 0.0;
		}
		
		speed[i] = alpha * speed[i - 1] + (1 - alpha) * s + sqrt((1 - pow(alpha, 2)) * speed[i - 1]);
		direction[i] = alpha * direction[i - 1] + (1 - alpha) * d + sqrt((1 - pow(alpha, 2)) * direction[i - 1]);
		double mx = x + speed[i - 1] * cos(direction[i - 1]);
		
		return mx;

	}

	double makeWayY(double x, double y, int i, double alpha, double s, double d) {
		if (i == 1) {
			speed[0] = 0.0;
			direction[0] = 0.0;
		}

		speed[i] = alpha * speed[i - 1] + (1 - alpha) * s + sqrt((1 - pow(alpha, 2)) * speed[i - 1]);
		direction[i] = alpha * direction[i - 1] + (1 - alpha) * d + sqrt((1 - pow(alpha, 2)) * direction[i - 1]);
		double my = y + speed[i - 1] * sin(direction[i - 1]);
		
		return my;
	}

	void calcDistane(double x, double y, double nx, double ny) {
		double lat1 = x * M_PI / 180;
		double lat2 = nx * M_PI / 180;
		double long1 = y * M_PI / 180;
		double long2 = ny * M_PI / 180;

		double cl1 = cos(lat1);
		double cl2 = cos(lat2);
		double sl1 = sin(lat1);
		double sl2 = sin(lat2);
		double delta = long2 - long1;
		double cdelta = cos(delta);
		double sdelta = sin(delta);

		double yD = sqrt(pow(cl2 * sdelta, 2) + pow(cl1 * sl2 - sl1 * cl2 * cdelta, 2));
		double xD = sl1 * sl2 + cl1 * cl2 * cdelta;

		double bigRound = atan2(yD, xD);
		c += (bigRound * R) / 1000;
	}

	float getWay() {
		return c;
	}
	
};


int main() {
	Human adam, x, y;
	Walking c, dlx, dly;
	double xi, yi, nxi, nyi;
	double a, b;
	int steps;
	int age;

	cout << "Enter your age: ";
	cin >> age;
	adam.setAge(age);

	cout << "Where are you now? " << "\n";
	cout << "x: ";
	cin >> a;
	cout << "y: ";
	cin >> b;

	x.setPosX(a);
	y.setPosY(b);

	cout << "How long do you want to go? (Enter the number of steps)" << "\n";
	cin >> steps;
	
	for (int i = 1; i < steps + 1; i++) {

		double alpha = rand() % 2;
		double s = rand() % 12 + 4;
		double d = rand() % 360;

		xi = x.getPosX();
		yi = y.getPosY();
		nxi = dlx.makeWayX(xi, yi, i, alpha, s, d);
		nyi = dly.makeWayY(xi, yi, i, alpha, s, d);
			
		c.calcDistane(xi, yi, nxi, nyi);

		x.setPosX(nxi);
		y.setPosY(nyi);
		
		cout << "Your position x: " << x.getPosX() << " y: " << y.getPosY() << "\n";
		cout << "You walked " << c.getWay() << " kilometers" << "\n" << "\n";
	}
	
	return 0;
}