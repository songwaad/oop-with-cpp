#include <iostream>
using namespace std;

// function template
template<class T>
T findMax(T a, T b, T c) {
    T max = a;
    if (b>max) max = b;
    if (c>max) max = c;
    return max;
}

// class template
template<class B>
class MaxMin {
    B data[3];
    public:
    MaxMin() { 
        cout << "Hello MaxMin" << endl;
        for(int i=0; i<3; i++) { data[i] = i+1; } }
    MaxMin(B arr[3]) { setData(arr); }
    ~MaxMin() { cout << "Bye bye MaxMin" << endl; }

    void setData(int i, B bb) { data[i] = bb; }
    void setData(B arr[3]) {
        for(int i=0; i<3; i++)
        data[i] = arr[i];
    }
    B getData(int i) { return data[i]; }

    B findMax() {
        B max = data[0];
        for(int i=1; i<3; i++) {
            if(data[i]>max) {
                max = data[i];
            }
        }
        return max;
    }
    
    B findMin() {
        B min = data[0];
        for(int i=1; i<3; i++) {
            if(data[i]<min) {
                min = data[i];
            }
        }
        return min;
    }

    void show() {
        for(int i=0; i<3; i++) {
            cout << "[" << data[i] << "] ";
        } cout << endl;
    };
};

// Main
int main() {
    cout << "--- Function Template ---" << endl;

    int a[3] = {5,2,8};
    float b[3] = {23.1, 1.234, 8.234};
    char c[3] = { 'H', 'A', 'J'};
    string d[3] = { "Jude", "Jones", "BB"};

    cout << "Max of Array A : " << findMax(a[0],a[1],a[2]) << endl;    
    cout << "Max of Array B : " << findMax(b[0],b[1],b[2]) << endl;
    cout << "Max of Array C : " << findMax(c[0],c[1],c[2]) << endl;
    cout << "Max of Array D : " << findMax(d[0],d[1],d[2]) << endl;
    cout << "-------------------------\n" << endl;

    MaxMin<int> w; w.show();
    cout << "Max : " << w.findMax() << endl;
    cout << "Min : " << w.findMin() << "\n" << endl;
    
    MaxMin<float> x(b); x.show();
    cout << "Max : " << x.findMax() << endl;
    cout << "Min : " << x.findMin() << "\n" << endl;

    MaxMin<char> y(c); y.show();
    cout << "Max : " << y.findMax() << endl;
    cout << "Min : " << y.findMin() << "\n" << endl;

    MaxMin<string> z(d); z.show();
    cout << "Max : " << z.findMax() << endl;
    cout << "Min : " << z.findMin() << "\n" << endl;


    
}