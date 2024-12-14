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
            // cout << "Hello " << name << endl;
        }

        // overloading constructor
        Rectangle(double w,double l) {
            num++;
            set(w,l,(char*)"No Name");
            // cout << "Hello " << name << endl;
        }

        // overloading constructor
        Rectangle(double w,double l,char* n) {
            num++;
            set(w,l,strcpy(name,n));
            // cout << "Hello " << name << endl;
        }

        // destructor
        ~Rectangle() {
            num--;
            // cout << "\n"<< name << " Dead" << endl;
            // cout << "n : " << num << endl;
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

        // set width,height
        void set(double w, double l) {
            width = w;
            length = l;
            strcpy(name,"No Name");
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
    cout << "Name : " << name << endl;
    cout << "Width : " << width << endl;
    cout << "Length : " << length << endl;
    cout << "Area : " << findArea() << endl;
    cout << "Circum : " << findCircum() << "\n\n";
};

int Rectangle:: num;

// --------------- week4 ---------------

class MyRect {
    private:
        int row, col;
        Rectangle **a;

        void set(int r, int c);
        void clear();

    public:
        MyRect() { row = 0; col = 0; a = 0; };
        MyRect(int r, int c) { set(r,c); };
        ~MyRect() { clear(); };
        
        void showAll();
        void reset(int r, int c);

        // setRect function
        void setRect(int r, int c, Rectangle b) {
            a[r][c] = b;
        }
        void setRect(int r, int c, double w, double h) {
            a[r][c].set(w,h);
        }
        void setRect(int r, int c, double w, double h, char* n) {
            a[r][c].set(w,h,n);
        }

        // getRect function
        Rectangle getRect(int r, int c) {
            return a[r][c];
        }

        // showRect function
        void showRect(int r, int c) {
            cout << "Rectangle [" << r << "][" << c << "]" << endl;
            a[r][c].show();
        }
};

// set function
void MyRect::set(int r, int c) {
    row = r; col = c;
    a = new Rectangle* [row];
    for(int i = 0; i < row; i++) {
        a[i] = new Rectangle[col];
    }
};

// showAll function
void MyRect::showAll() {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cout << "Rectangle [" << i << "][" << j << "]" << endl;
            a[i][j].show();
        }
    }
};

// clear function
void MyRect::clear() {
    if (row!=0) {
        for(int i = 0; i < row; i++) {
            delete[] a[i];
        } delete[] a;
    }
};

// reset function
void MyRect::reset(int r, int c) {
    clear();
    set(r, c);
};

// --------------- main ---------------

int main() {
    Rectangle a(2, 5, (char*)"Zidane");
    Rectangle b(12.8, 20, (char*)"Bellingham");
    Rectangle c(34, 8);
    MyRect x(2,3);

    x.setRect(0, 0, a);
    x.setRect(0, 1, b);
    x.setRect(0, 2, c);
    x.setRect(1, 0, 20, 10);
    x.setRect(1, 1, 2, 3, (char*)"Jones");

    cout << "--------- Show Rect [0,2] ---------" << "\n\n";
    x.showRect(0,2);

    cout << "------------ Show All ------------" << "\n\n";
    x.showAll();

    cout << "------------- reset -------------" << "\n\n";
    x.reset(2,2);
    x.showAll();

    cout << "------------- getRect -------------" << "\n\n";
    x.setRect(1, 0, b);
    Rectangle d = x.getRect(1,0);
    Rectangle e = x.getRect(1,1);
    d.show();
    e.show();
    return 0;
}