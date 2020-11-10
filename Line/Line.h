
#ifndef LINE_H_
#define LINE_H_

#include <ostream>
#include <iostream>
using namespace std;


struct Point{
	double x;
	double y;

	Point(double a = 0, double b = 0){
		x = a;
		y = b;
	}

	void display(ostream& out){
		out << "(" << x << "," << y << ")";
	}
};


class Line{
	private:
		Point p1, p2;

	public:
		Line();
		Line(Point, Point);

		void setFirstPoint(Point);
		void setSecondPoint(Point);

		Point getFirstPoint() const;
		Point getSecondPoint() const;

		bool slope(double& m) const;
		bool yIntercept(double& b) const;

		bool isParallel(Line) const;
		bool isCollinear(Line) const;
		bool isPerpendicular(Line) const;

		Point intersect(Line) const;

		void display(ostream&) const;
};

#endif /* LINE_H_ */
