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
            set(0,0,(char*)"No Name");
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

    cout << "n : " << Rectangle::count() << endl;

    Rectangle a(12.5,27.8,(char*)"A");
    cout << "n : " << Rectangle::count() << endl;

    Rectangle b(3,5);
    cout << "n : " << Rectangle::count() << endl;

    Rectangle c;
    cout << "n : " << Rectangle::count() << endl;

    a.show();
    {
        b.show();
    }

    c.show();
    c.setWidth(5); c.setLength(10); c.setName((char*)"Bellingham");

    cout << "\nName : " << c.getName() << endl;
    cout << "Area : " << c.getWidth() * c.getLength() << endl;
    cout << "Area : " << c.findArea() << endl;
    cout << "Circum : " << c.findCircum() << endl;

    return 0;
}