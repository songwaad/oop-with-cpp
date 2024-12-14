#include <iostream>
#include <string.h>
#include <cmath>
#include "Point#1.cpp"

using namespace std;

// ---------- HW 5 Class Circle ----------

class Circle {
    private:
        double raduis;
        char name[20];
        Point centerPoint;

    public:
        // default constructor
        Circle() { 
            set(1, (char*)"noname(C)"); 
            cout << name << " born" << endl;
        }
        // overloading constructor
        Circle(Point a, double r, char* n) {
            set(a,r,n);
            cout << name << " born" << endl;
        }
        // overloading constructor
        Circle(double r, char* n) { 
            set(r,n);
            cout << name << " born" << endl; 
        }
        // overloading constructor
        Circle(double r) { 
            set(r, (char*)"noname(C)");
            cout << name << " born" << endl; 
        }
        // overloading constructor
        Circle(char* n) { 
            set(1, n);
            cout << name << " born" << endl; 
        }
        // overloading constructor
        Circle(Point a) { 
            set(1, (char*)"noname(C)");
            centerPoint = a;
            cout << name << " born" << endl; 
        }

        // destructor
        ~Circle() {
            cout << "Endgame" << endl;
        }

        // set All
        void set(double r, char *n) {
            raduis = r;
            strcpy(name,n);
        }
        // set All
        void set(Point a, double r, char *n) {
            centerPoint = a;
            raduis = r;
            strcpy(name,n);
        }
        // set raduis
        void setRaduis(double r) { raduis = r; }
        // set Center Point
        void setCenterPoint(Point a) { centerPoint = a; }
        // set name
        void setName(char *n) { strcpy(name,n); }

        // get name
        char* getName() {
            return name;
        }
        // get radius
        double getRaduis() {
            return raduis;
        }
        // get centerPoint
        Point getCenterPoint() {
            return centerPoint;
        }

        // show
        void show();

        // function Check Point 
        // friend bool pointInCircle(Circle, Point);

};

// show
void Circle::show() {
    cout << "\nCircle Name : " << name << endl;
    cout << "Raduis : " << raduis << endl;
    cout << "Center Point : " << "(" << centerPoint.getX() << "," << centerPoint.getY() << ")" << endl;
};

// friend fucntion
bool pointInCircle(Circle a, Point b) {
    double distance = sqrt(
        pow(a.getCenterPoint().x - b.x , 2) +
        pow(a.getCenterPoint().y - b.y , 2)
    );

    if (distance <= a.getRaduis())
        return true;
    else
        return false;
}

// ---------- main ----------

int main() {
    Point a(10, 27, (char*)"A");
    Point b(2, 2, (char*)"B");
    a.show();
    b.show();

    cout << "\n----- Circle -----\n" << endl;
    Circle jude(sqrt(8), (char*)"Jude");
    Circle zidane(2.83);
    Circle madrid;
    Circle paperplanes(a);
    Circle beckham(b, 3, (char*)"beckham");

    // show
    jude.show();
    zidane.show();
    madrid.show();
    paperplanes.show();
    beckham.show();

    // check point
    cout << "\n----- Check Point -----\n" << endl;

    bool bb;
    bb = pointInCircle(jude, a);

    if (pointInCircle(jude, a))
        cout << a.getName() << " is in " << jude.getName() << "Circle" << endl;
    else if (bb == 0)
        cout << a.getName() << " is outside of " << jude.getName() << " Circle" << endl;

    // set
    cout << "\n----- set -----" << endl;

    jude.setRaduis(1.5);
    jude.setName((char*)"Bellingham");
    jude.show();
    b.setXY(7,8);
    jude.setCenterPoint(b);
    jude.show();

    beckham.set(b,10,(char*)"David");
    beckham.show();

    zidane.set(9,(char*)"Zinedine");
    zidane.show();

    // get
    cout << "\n----- get -----\n" << endl;
    cout << "Name : " << jude.getName() << endl; 
    cout << "Raduis : " << jude.getRaduis() << endl; 
    jude.getCenterPoint().show();
    
    return 0;
}