#include <iostream>
#include <string.h>

using namespace std;

class Point {
    private:
        static int n;
        double x;
        double y;
        string name1;
        char name2[20];
        
    public:

        // default constructor
        Point() {
            n++;
            set(0,0,"No Name",(char*)"No Name");
            cout << "Hello " << name1 << endl;
        }
        // overloading constructor 
        Point(double a) {
            n++;
            set(a,0,"No Name",(char*)"No Name");
            cout << "Hello " << name1 << endl;
        }

        // overloading constructor
        Point(double a,double b) {
            n++;
            set(a,b,"No Name",(char*)"No Name");
            cout << "Hello " << name1 << endl;
        }

        // overloading constructor
        Point(double a,double b,string n1) {
            n++;
            set(a,b,n1,(char*)"No Name");
            cout << "Hello " << name1 << endl;
        }

        // overloading constructor
        Point(double a,double b,string n1,char* n2) {
            n++;
            set(a,b,n1,strcpy(name2, n2));
            cout << "\nHello " << name1 << endl;
        }

        // destructor
        ~Point() {
            n--;
            cout << name1 << " Dead" << endl;
            cout << "n : " << n << endl;
        }

        // set ค่าทั้งหมด
        void set(double a, double b, string n1, char* n2) {
            x = a;
            y = b;
            name1 = n1;
            strcpy(name2,n2);
        }

        // set x
        void setX(double a) {
            x = a;
        }

        // set y
        void setY(double b) {
            y = b;
        }

        // set name1
        void setName1(string n1) {
            name1 = n1;
        }

        // set name2
        void setName2(char* n2) {
            strcpy(name2, n2);
        }

        // get x
        double getX() {
            return x;
        }

        // get y
        double getY() {
            return y;
        }

        // get name1
        string getName1() {
            return name1;
        }

        // get name2
        char* getName2() {
            return name2;
        }

        // static function 
        static int count() {
            return n;
        }
        
        // show
        void show();
};

void Point::show() {
    cout << "\nName 1 : " << name1 << endl;
    cout << "Name 2 : " << name2 << endl;
    cout << "x : " << x << endl;
    cout << "y : " << y << endl;
};

int Point:: n;

int main() {
    /*Point myPoint;
    myPoint.set(1.2, 2, "My Point" , (char*)"Beckham");
    myPoint.show();

    myPoint.setX(10);
    myPoint.setY(12.7);
    myPoint.setName1("Your Point");
    myPoint.setName2((char*)"Jude Bellingham");

    myPoint.show();

    cout << "\nName 1 : " << myPoint.getName1() << endl;
    cout << "Name 2 : " << myPoint.getName2() << endl;
    cout << "x+y : " << myPoint.getX() + myPoint.getY() << endl;*/
    
    cout << "n : " << Point::count() << endl;

    Point aPoint, bPoint(1.3), cPoint(3,5.6);
    {
        Point iPoint(10.23,7,"I Point"),jPoint(10.23,7,"J Point");
        cout << "n : " << Point::count() << endl;
    }
    
    Point zPoint(2,5,"Z Point",(char*)"Bellingham");
    cout << "n : " << Point::count() << endl;
    
    return 0;
}