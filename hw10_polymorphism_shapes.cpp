#include <iostream>
using namespace std;
#include <cmath>

class Shape {
    public:
    virtual double area() = 0;
    virtual void show() = 0;
    virtual void input(istream& is) = 0;
    virtual ~Shape() {}
};

class TwoDimensional: public Shape {};
class ThreeDimensional: public Shape {
    public:
    virtual double volume() = 0;
};

class Rectangle:public TwoDimensional {
    double width;
    double length;
    public:
    Rectangle() { set(1,1); }
    Rectangle(double w, double h) { set(w,h); }
    ~Rectangle() { cout << "~Rectangle" << endl; }

    void set(double w, double l) { width = w; length = l; }
    void setWidth(double w) { width = w; }
    void setLength(double l) { length = l; }

    double getWidth() { return width; }
    double getLength() { return length; }

    void show() {
        cout << "\n Rectangle " << endl;
        cout << " Width : " << width << endl;
        cout << " Length : " << length << endl;
        cout << " Area : " << area() << endl;
    }

    void input(istream& is) {
        cout << "\n Rectangle " << endl;
        cout << " Width : "; is >> width;
        cout << " Length : "; is >> length;
    }

    double area() {
        return width*length;
    }
};

class Triangle:public TwoDimensional {
    double base;
    double height;
    public:
    Triangle() { set(1,1); }
    Triangle(double w, double h) { set(w,h); }
    ~Triangle() { cout << "~Triangle" << endl; }

    void set(double b, double h) { base = b; height = h; }
    void setBase(double b) { base = b; }
    void setHeight(double h) { height = h; }

    double getBase() { return base; }
    double getHeight() { return height; }

    void show() {
        cout << "\n Triangle " << endl;
        cout << " Base : " << base << endl;
        cout << " Height : " << height << endl;
        cout << " Area : " << area() << endl;
    }

    void input(istream& is) {
        cout << "\n Triangle " << endl;
        cout << " Base : "; is >> base;
        cout << " Height : "; is >> height;
    }

    double area() {
        return (1/2.0)*base*height;
    }
};

class Circle:public TwoDimensional {
    double radius;
    public:
    Circle() { setRadius(1); }
    Circle(double r) { setRadius(r); }
    ~Circle() { cout << "~Circle" << endl; }

    void setRadius(double r) { radius = r; }
    double getRadius() { return radius; }
    void show() {
        cout << "\n Circle " << endl;
        cout << " Radius : " << radius << endl;
        cout << " Area : " << area() << endl;
    }

    void input(istream& is) {
        cout << "\n Circle " << endl;
        cout << " Radius : "; is >> radius;
    }

    double area() {
        return 3.14 * radius * radius;
    }
};

class Cylinder:public ThreeDimensional {
    double radius;
    double height;
    public:
    Cylinder() { set(1,1); }
    Cylinder(double r, double h) { set(r,h); }
    ~Cylinder() { cout << "~Cylinder" << endl; }

    void set(double r, double h) { radius = r; height = h; }
    void setRadius(double r) { radius = r; }
    void setHeight(double h) { height = h; }

    double getRadius() { return radius; }
    double getHeight() { return height; }

    void show() {
        cout << "\n Cylinder " << endl;
        cout << " Radius : " << radius << endl;
        cout << " Height : " << height << endl;
        cout << " Area : " << area() << endl;
        cout << " Volume : " << volume() << endl;
    }

    void input(istream& is) {
        cout << "\n Cylinder " << endl;
        cout << " Radius : "; is >> radius;
        cout << " Height : "; is >> height;
    }

    double area() {
        return ( 2 * 3.14 * radius * height ) + ( 2 * 3.14 * radius * radius ) ;
    }

    double volume() {
        return 3.14 * radius * radius * height;
    }


};

class Sphere:public ThreeDimensional {
    double radius;
    public:
    Sphere() { setRadius(1); }
    Sphere(double r) { setRadius(r); }
    ~Sphere() { cout << "~Sphere" << endl; }

    void setRadius(double r) { radius = r; }

    double getRadius() { return radius; }

    void show() {
        cout << "\n Sphere " << endl;
        cout << " Radius : " << radius << endl;
        cout << " Area : " << area() << endl;
        cout << " Volume : " << volume() << endl;
    }

    void input(istream& is) {
        cout << "\n Sphere " << endl;
        cout << " Radius : "; is >> radius;
    }

    double area() {
        return 4 * 3.14 * pow(radius,2) ;
    }

    double volume() {
        return (4/3.0) * 3.14 * pow(radius,3) ;
    }
};

// i/o stream ----------------------------------------------

ostream& operator<<(ostream& os, Shape& s) {
    s.show();
    return os;
}

istream& operator>>(istream& is, Shape& s) {
    s.input(is);
    return is;
}

int main() {
    Shape *x[5];
    x[0] = new Rectangle(); 
    x[1] = new Triangle();
    x[2] = new Circle();
    x[3] = new Cylinder();
    x[4] = new Sphere();

    x[0]->show();
    x[1]->show();
    cout << *x[2];
    cout << *x[3];
    cout << *x[4];

    printf("\n\n AA ---------------\n\n");

    Cylinder d(10,2); d.show();
    Sphere e(10); e.show();
    Rectangle a(2,10); a.show();
    Triangle b(2,10); b.show();
    Circle c(10); c.show();

    printf("\n\n BB ---------------\n\n");

    x[4] = &a; cout << *x[4];
    x[3] = &b; cout << *x[3];
    x[2] = &c; cout << *x[2];
    x[1] = &d; cout << *x[1];
    x[0] = &e; cout << *x[0];

    printf("\n\n Input ---------------\n\n");

    /*cin >> *x[4];
    cin >> b;
    cin >> c;
    cin >> d;
    cin >> e;

    printf("\n\n Output ---------------\n\n");
    
    cout << a;
    cout << b;
    cout << c;
    cout << d;
    cout << e;*/

    printf("\n\n Call Area ---------------\n\n");
    
    for(int j=0; j<5; j++) {
        cout << "Area : " << x[j]->area() <<endl;
    }

    ThreeDimensional *y[2];
    y[0] = new Sphere();
    y[1] = new Cylinder();


    printf("\n\n Call Volume ---------------\n\n");

    for(int k=0; k<2; k++) {
        cout << "Volume : " << y[k]->volume() << endl;
    }


    printf("\n\n End ---------------\n\n");

    for (int i=0; i<5; i++) {
        delete x[i];
    }

}