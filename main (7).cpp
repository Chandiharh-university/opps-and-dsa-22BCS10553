#include <iostream>

using namespace std;

class Shape {
public:
    virtual double area() = 0; 
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() override { 
        return 3.14159 * radius * radius; 
    }
};

class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() override { 
        return width * height; 
    }
};

int main() {
    Circle circle(5);
    Rectangle rect(4, 6);

    cout << "Circle area: " << circle.area() << endl; 
    cout << "Rectangle area: " << rect.area() << endl; 

    return 0;
}