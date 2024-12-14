#include <iostream>
using namespace std;

// ex4 ----------------------------
/*int judeThrow(int i) {
    try {
        throw i;
    } catch (int j) {
        cout << "Jude cash : " << j << endl; 
    }
}

int zidanThrow(int i) {
    try {
        throw i;
    } catch (int j) {
        cout << "Zidane cash" << endl; 
        j++; judeThrow(j);
    }
}

int bambamThrow(int i) {
    try {
        throw i;
    } catch (int j) {
        cout << "Bambam cash" << endl;
        j++; zidanThrow(j); 
    }
}*/

int judeThrow(int i) {
    throw i;
}

int zidanThrow(int i) {
    judeThrow(i);
}

int bambamThrow(int i) {
    zidanThrow(i); 
}

// ex5 ----------------------------
class Animal {
    string name;
    public:
    Animal() { name = "Zidane"; }
    Animal(string n) { name = n; }
    ~Animal() { cout << "Animal Die" << endl; }

    void setName(string n) { name = n; }
    string getName() { return name; }
    void show() { cout << "Animal" << " Name : " << name << endl; }

    virtual void f1() throw(string) {
        throw (string)"Animal";
    }
};

class Bird : public Animal {
    int type;
    public:
    Bird() { type = 1;  }
    Bird(string n, int t) { type = t; }
    ~Bird() { cout << "Bird Die" << endl; }

    void setTybe(int t) { type = t; }
    int getTybe() { return type; }
    void show() {
        cout << "Bird" << endl;
        cout << "Name : " << getName() << endl;
        cout << "Type : " << type << endl;
    }

    void f1() throw(string) {
        throw (string)"Bird";
    }
};

// ex3 ----------------------------

void ex3() throw(Animal) {
    Bird b;
    throw b;
}

// ex6 ----------------------------
class JudeException : public exception {
     virtual const char* what() const throw() {
        return "Jude Exception";
     }
};

int main() {

    cout << "// ex1 + ex2 ----------------------" << endl;
    try {
        //int a = 2;
        //double a = 2.53;
        //char a = 'A';
        //char *a = new char; *a = 'A';
        string a = "Jude Bellingham";
        throw a;
    } catch (int i) {
        cout << "(int)Exception : " << i << endl;
    } catch (double d) {
        cout << "(double)Exception : " << d << endl;
    } catch (...) {
        cout << "Exception : other " << endl;
    }

    cout << "// ex3 ----------------------------" << endl;
    try {
        ex3();
        cout << "Hello" << endl;
    } catch (Animal) {
        cout << "Exception : Animal " << endl;
    } catch (Bird) {
        cout << "Exception : Bird " << endl;
    } catch (...) {
        cout << "Other Exception" << endl;
    }

    cout << "// ex4 ----------------------------" << endl;
    try {
        //bambamThrow(3);
        //zidanThrow(2);
        judeThrow(1);
    } catch (int i) {
        cout << "Exception : " << i << endl;
    } catch (double d) {
        cout << "Exception : " << d << endl;
    } catch (string s) {
        cout << "Exception : " << s << endl;
    }  catch (...) {
        cout << "Other Exception" << endl;
    }

    cout << "// ex5 ----------------------------" << endl;
    Animal *bb = new Bird();
    try {
        bb->f1();
        cout << "Hello" << endl;
    } catch (int i) {
        cout << "Exception : " << i << endl;
    } catch (double d) {
        cout << "Exception : " << d << endl;
    } catch (string s) {
        cout << "Exception : " << s << endl;
    }  catch (...) {
        cout << "Other Exception" << endl;
    }

    cout << "// ex6 ----------------------------" << endl;
    JudeException jude;
    try {
        throw jude;
    } catch (exception &ex) {
        cout << "Exception : " << ex.what() << endl;
    }
}