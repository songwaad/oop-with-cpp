#include <iostream>
#include <string.h>

using namespace std;

class Rectangle {
    private:
        static int num;
        double width;
        double length;
        char name[20];

    public:

        // default constructor
        Rectangle() {
            num++;
            set(1,1,(char*)"No Name");
            cout << "Hello " << name << endl;
        }

        // overloading constructor
        Rectangle(double w,double l) {
            num++;
            set(w,l,(char*)"No Name");
            cout << "Hello " << name << endl;
        }

        // overloading constructor
        Rectangle(double w,double l,char* n) {
            num++;
            set(w,l,strcpy(name,n));
            cout << "Hello " << name << endl;
        }

        // destructor
        ~Rectangle() {
            num--;
            cout << "\n"<< name << " Dead" << endl;
            cout << "n : " << num << endl;
        }

        // area function
        double findArea() {
            return width * length;
        }

        // circum function
        double findCircum() {
        return (width + length) * 2;
        }

        // set ค่าทั้งหมด
        void set(double w, double l, char* n) {
            width = w;
            length = l;
            strcpy(name,n);
        }

        // set width
        void setWidth(double w) {
            width = w;
        }

        // set length
        void setLength(double l) {
            length = l;
        }

        // set name
        void setName(char* n) {
            strcpy(name,n);
        }

        // get width
        double getWidth() {
            return width;
        }

        // get length
        double getLength() {
            return length;
        }

        // get name
        char* getName() {
            return name;
        }

        // show
        void show();

        // static function
        static int count() {
            return num;
        }

        // ---------- ex8 ---------- //

        // ++ prefix
        Rectangle operator++() {
            length++;
            return *this;
        }
        // ++ postfix
        Rectangle operator++(int) {
            width++;
            return *this;
        }

        // friend
        // -- pretfix
        friend Rectangle operator--(Rectangle &a) {
            (a.length<=1)? a.length = 1: a.length--;
            return a;
        }

        // -- postfix
        friend Rectangle operator--(Rectangle &a, int) {
            (a.width<=1)? a.width = 1: a.width--;
            return a;
        }

        // operator compare

        bool operator>(Rectangle &a) {
            return (findArea()>a.findArea())? true: false;
        }

        bool operator>=(Rectangle &a) {
            return (findArea()>=a.findArea())? true: false;
        }

        bool operator<(Rectangle &a) {
            return (findArea()<a.findArea())? true: false;
        }

        bool operator<=(Rectangle &a) {
            return (findArea()<=a.findArea())? true: false;
        }

        bool operator!=(Rectangle &a) {
            return (findArea()!=a.findArea())? true: false;
        }

        // subscript operator []
        double operator [] (int a) {
            return findArea()+a;
        }

        // call operator ()

        double operator ()() {
            width = 1;
            length = 1;
            return findArea();
        }

        double operator ()(double w) {
            width += w;
            length += w;
            return findArea();
        }

        double operator ()(double w,double x) {
            width += w*x;
            length += w*x;
            return findArea();
        }
        


};

void Rectangle::show() {
    cout << "\nName : " << name << endl;
    cout << "Width : " << width << endl;
    cout << "Length : " << length << endl;
    cout << "Area : " << findArea() << endl;
    cout << "Circum : " << findCircum() << endl;
};

int Rectangle:: num;

int main() {

    Rectangle jude; jude.setName((char*)"Jude");
    Rectangle bebe(10,10);
    Rectangle guler(5,5,(char*)"guler");
    
    guler.show();
    jude.show();

    cout << "\n----- ++ -- -----" << endl;

    bebe = jude++; jude.show(); bebe.show();
    bebe = ++jude; jude.show(); bebe.show();

    jude--; jude.show(); 
    --jude; jude.show();

    bebe = jude--; jude.show(); bebe.show();
    bebe = --jude; jude.show();

    bebe.setName((char*)"bebe"); bebe.show();

    cout << "\n----- Compare 1 -----" << endl;
    cout << "Jude > Guler : " << (jude > guler) << endl;
    cout << "Jude >= Guler : " << (jude >= guler) << endl;
    cout << "Jude < Guler : " << (jude < guler) << endl;
    cout << "Jude <= Guler : " << (jude <= guler) << endl;
    cout << "Jude != Guler : " << (jude != guler) << endl;

    cout << "\n----- Compare 2 -----" << endl;

    cout << "Jude > bebe : " << (jude > bebe) << endl;
    cout << "Jude >= bebe : " << (jude >= bebe) << endl;
    cout << "Jude < bebe : " << (jude < bebe) << endl;
    cout << "Jude <= bebe : " << (jude <= bebe) << endl;
    cout << "Jude != bebe : " << (jude != bebe) << endl;

    cout << "\n----- Subscript -----" << endl;
    jude.show();
    cout << "Area Add 5 : " << jude[5];

    cout << "\n\n----- Call -----" << endl;
    jude.show();
    jude(5); // width and length + 5
    jude.show();

    jude(); // width and length = 1
    jude.show();
    
    jude(5,2); // width and length + (5*2)
    jude.show();


    cout << "\n----- End -----" << endl;

    
}