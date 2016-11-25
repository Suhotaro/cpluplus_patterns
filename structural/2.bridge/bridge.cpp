#include <iostream>
#include <list>
#include <memory>

using namespace std;

class DrawingAPI; /* Implementor */
class DrawingAPI1; /* ConcreteImplementor 1 */
class DrawingAPI2; /* ConcreteImplementor 2 */

class Shape; /* Abstraction */
class CircleShape; /* Refined Abstraction */

class DrawingAPI {
public:
    virtual ~DrawingAPI() {}
    virtual void drawCircle(double x, double y, double radius) = 0;
};

class DrawingAPI1 : public DrawingAPI {
public:
    void drawCircle(double x, double y, double radius) {
    	printf("API1: circle at %f:%f radius %f\n", x, y, radius);
    }
};

class DrawingAPI2: public DrawingAPI {
public:
    void drawCircle(double x, double y, double radius) {
    	printf("API2: circle at %f:%f radius %f\n", x, y, radius);
    }
};

class Shape {
protected:
	DrawingAPI *drawing_api;
	Shape(DrawingAPI *drawing_api_) : drawing_api(drawing_api_) {}

public:
	virtual ~Shape() { if(drawing_api) delete drawing_api; }
	virtual void draw() = 0;
	virtual void resizeByPercentage(double pct) = 0;
};

class CircleShape : public Shape {
	double x, y, radius;
public:
	CircleShape(double x_, double y_, double radius_, DrawingAPI *drawing_api) :
		x(x_), y(y_), radius(radius_), Shape(drawing_api) {}

	virtual void draw() { drawing_api->drawCircle(x, y, radius); }
	virtual void resizeByPercentage(double pct) { radius *= (1.0 + pct/100); }
};

int main()
{
	Shape *shapes[2] = {new CircleShape(1, 2, 3, new DrawingAPI1()), new CircleShape(5, 6, 7, new DrawingAPI2())};

	for (auto *shape : shapes)
	{
		shape->resizeByPercentage(2.5);
		shape->draw();
	}

    return 0;
}
