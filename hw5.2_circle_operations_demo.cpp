#include <iostream>
#include <string.h>

using namespace std;

class Circle;
class Point {
    private:
        static int n;
        double x;
        double y;
        char name[20];
        
    public:

        // default constructor
        Point() {
            n++;
            set(0,0,(char*)"No Name");
            cout << "Hello " << name << endl;
        }

        // overloading constructor 
        Point(double a) {
            n++;
            set(a,0,(char*)"No Name");
            cout << "Hello " << name << endl;
        }

        // overloading constructor
        Point(double a,double b) {
            n++;
            set(a,b,(char*)"No Name");
            cout << "Hello " << name << endl;
        }

        // overloading constructor
        Point(double a,double b,char* n2) {
            n++;
            set(a,b,strcpy(name, n2));
            cout << "Hello " << name << endl;
        }

        // overloading constructor
        Point(char* n2) {
            n++;
            set(0,0,strcpy(name, n2));
            cout << "Hello " << name << endl;
        }

        // destructor
        ~Point() {
            n--;
            cout << "Bye Bye" << endl;
        }

        // set ค่าทั้งหมด
        void set(double a, double b, char* n2) {
            x = a;
            y = b;
            strcpy(name,n2);
        }

        // set x
        void setX(double a) {
            x = a;
        }

        // set XY
        void setXY(double a,double b ) {
            x = a;
            y = b;
        }

        // set y
        void setY(double b) {
            y = b;
        }

        // set name
        void setName(char* n2) {
            strcpy(name, n2);
        }

        // get x
        double getX() {
            return x;
        }

        // get y
        double getY() {
            return y;
        }

        // get name2
        char* getName() {
            return name;
        }

        // static function 
        static int count() {
            return n;
        }
        
        // show
        void show();

        // dot(Point&)
        double dot(Point &b) {
            return ( b.getX() * x ) + ( b.getY() * y ) ;
        }

        //midPoint1
        //void midPoint(Point &a, Point &b) {
        //    x = (a.getX() + b.getX()) / 2;
        //    y = (a.getY() + b.getY()) / 2;
        // }

        //midPoint2
        Point midPoint(Point &a, Point &b) {
            x = (a.getX() + b.getX()) / 2;
            y = (a.getY() + b.getY()) / 2;

            // Point c;
            // c.setX(x); c.setY(y); return c;
            // return Point(x,y);
            return *this;
        }

        // friend fucntion
        friend bool pointInCircle(Circle, Point);

        
};

void Point::show() {
    cout << "\nName : " << name << endl;
    cout << "x : " << x << endl;
    cout << "y : " << y << endl;
};

int Point:: n;        

// ---------- main ----------

/* 
int main() {

    Point jude(2,3,(char*)"Jude");
    Point jota(7,8,(char*)"Jota");
    Point mid("Mid");
    Point a;

    jude.show();
    jota.show();
    mid.show();

    cout << "\n---------- dot ----------\n" << endl;

    cout << jude.getName() << " dot " << jota.getName() << " : " << jude.dot(jota) << endl;

    a = mid.midPoint(jude, jota);

    cout << "\n---------- a ----------" << endl;
    a.show();
    
    cout << "\n---------- Mid ----------" << endl;
    mid.show();
    cout << "\n---------- Dead ----------" << endl;
    return 0;
}

*/