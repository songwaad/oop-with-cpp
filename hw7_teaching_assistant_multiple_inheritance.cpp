#include <iostream>
#include <string.h>

using namespace std;

class Date {
        int day;
        int month;
        int year;
    public:
        // default constructer
        Date() { set(1,1,1990); }
        // overloading constructer
        Date(int d, int m, int y) { set(d,m,y); }
        // destructer
        ~Date() { cout << "Bye Date" << endl;}

        // set
        void set(int d, int m, int y) { day = d; month = m; year = y; }
        void setDay(int d) { day = d; }
        void setMonth(int m) { month = m; }
        void setYear(int y) { year = y; }

        // get
        int getDay() { return day; }
        int getMonth() { return month; }
        int getYear() { return year; }

        // show
        void show() {
            cout << day << "/" << month << "/" << year << endl; 
        }
};

class Address {
        string house_num;
        string lane;
        string road;
        string subarea;
        string area;
        string province;
        int postal_code;
    public:
        // default constructer
        Address() { set("282","-","Ramkhamhaeng","Hua Mak","Bang Kapi","Bangkok",10240); }
        // overloading constructer
        Address(string h, string l, string r, string s, string a, string p, int c) {
            set(h, l, r, s, a, p, c);
        }
        // destructer
        ~Address() {
            cout << "Bye Address" << endl;
        }


        // set
        void set(string h, string l, string r, string s, string a, string p, int c) {
            house_num = h; lane = l; road = r;
            subarea = s; area = a; province = p; postal_code = c;
        }
        void setHouseNum(string h) { house_num = h; }
        void setLane(string l) { lane = l; }
        void setRoad(string r) { road = r; }
        void setSubArea(string s) { subarea = s; }
        void setArea(string a) { area = a; }
        void setProvince(string p) { province = p; }
        void setPostalCode(int c) { postal_code = c; }

        // get
        string getHouseNum() { return house_num; }
        string getLane() { return lane; }
        string getRoad() { return road; }
        string getSubArea() { return subarea; }
        string getArea() { return area; }
        string getProvince() { return province; }
        int getPostalCode() { return postal_code; }

        // show
        void show() {
            cout << house_num + " Soi " + lane + ", " + road + " Rd" << endl;
            cout << subarea + ", " + area + ", " + province + " " << postal_code << endl;
        }
};

class Person {
        char person_id[14];
        string fname;
        string lname;
        Date birthdate;
        Address address;
    public:
        // default constructer
        Person() {
            set((char*)"1000000000001", "firsname", "lastname", birthdate, address);
        }
        // overloading constructer
        Person(char* id, string fn, string ln, Date d, Address a) {
            set(id, fn, ln, d, a);
        }
        // overloading constructer
        Person(char* id) {
            set(id, "firsname", "lastname", birthdate, address);
        }
        // overloading constructer
        Person(char* id, string fn) {
            set(id, fn, "lastname", birthdate, address);
        }
        // overloading constructer
        Person(char* id, string fn, string ln) {
            set(id, fn, ln, birthdate, address);
        }
        // overloading constructer
        Person(Date d, Address a) {
            set((char*)"1000000000000", "firsname", "lastname", d, a);
        }
        // overloading constructer
        Person(Date d) {
            set((char*)"1000000000000", "firsname", "lastname", d, address);
        }
        // overloading constructer
        Person(Address a) {
            set((char*)"1000000000000", "firsname", "lastname", birthdate, a);
        }

        // destructer
        ~Person() {
            cout << "Bye Person" << endl;
        }


        // set
        void set(char* id, string fn, string ln, Date d, Address a) {
            strcpy(person_id, id);
            fname = fn;
            lname = ln;
            birthdate = d;
            address = a;
        }
        void setPersonID(char* id) { strcpy(person_id, id); }
        void setFName(string fn) { fname = fn; }
        void setLName(string ln) { lname = ln; }
        void setBirthdate(Date d) { birthdate = d; }
        void setAddress(Address a) { address = a; }

        // get
        char* getPersonID() { return person_id; }
        string getFName() { return fname; }
        string getLName() { return lname; }
        Date getBirthdate() { return birthdate; }
        Address getAddress() { return address; }

        //show
        void show() {
            cout << "\nPerson ID : " << person_id << endl;
            cout << "Firstname : " << fname << endl;
            cout << "Lastname : " << lname << endl;
            cout << "Birth date : "; birthdate.show();
            cout << "Address : "; address.show(); cout << endl; 
        }
};

class Student: virtual public Person {
    char student_id[11];
    string graduate;
    string faculty;
    string department;
    public:
    // default constructer
    Student() { set((char*)"1000000000", "Bachelor's degree", "Science", "Computer Science"); }

    // overloading contructer (+person)
    Student(char* id, string g, string f, string d, char* pid, string fn, string ln, Date date, Address ad): Person(pid, fn, ln, date, ad) {
        set(id, g, f, d);
    }

    // overloading contructer
    Student(char* id, string g, string f, string d) {
        set(id, g, f, d);
    }
    // overloading contructer
    Student(char* id, string g, string f) {
        set(id, g, f, "Computer Science");
    }
    // overloading contructer
    Student(char* id, string g) {
        set(id, g, "Science", "Computer Science");
    }
    // overloading contructer
    Student(char* id) {
        set(id, "Bachelor's degree", "Science", "Computer Science");
    }

    // destructer
    ~Student() {
        cout << "Bye Student" << endl;
    }

    // set
    void set(char* id, string g, string f, string d) {
        strcpy(student_id, id);
        graduate = g;
        faculty = f;
        department = d;
    }
    void setStudentID(char* id) { strcpy(student_id, id); }
    void setGraduate(string g) { graduate = g; }
    void setFaculty(string f) { faculty = f; }
    void setDepartment(string d) { department = d; }

    // get
    char* getStudentID() { return student_id; }
    string getGraduate() { return graduate; }
    string getFaculty() { return faculty; }
    string getDepartment() { return department; }
    
    // show
    void show() {
        cout << "Student ID : " << student_id << endl;
        cout << "Graduate : " << graduate << endl;
        cout << "Faculty : " << faculty << endl;
        cout << "Department : " << department << endl; 
    }

};

class Teacher: virtual public Person {
    char teacher_id[11];
    string faculty;
    string department;
    public:
    // default constucter
    Teacher() { set((char*)"1000000000", "Science", "Computer Science"); }

    // overloading contructer (+person)
    Teacher(char* id, string f, string d, char* pid, string fn, string ln, Date date, Address ad): Person(pid, fn, ln, date, ad) {
        set(id, f, d);
    }

    // overloading contructer
    Teacher(char* id, string f, string d) {
        set(id, f, d);
    }
    // overloading contructer
    Teacher(char* id, string f) {
        set(id, f, "Computer Science");
    }
    // overloading contructer
    Teacher(char* id) {
        set(id, "Science", "Computer Science");
    }

    // destructer
    ~Teacher() {
        cout << "Bye Teacher" << endl;
    }

    // set
    void set(char* id, string f, string d) {
        strcpy(teacher_id, id);
        faculty = f;
        department = d;
    }
    void setTeacherID(char* id) { strcpy(teacher_id, id); }
    void setFaculty(string f) { faculty = f; }
    void setDepartment(string d) { department = d; }
    // get
    char* getTeacherID() { return teacher_id; }
    string getFaculty() { return faculty; }
    string getDepartment() { return department; }
    // show
    void show() {
        cout << "\nTeacher ID : " << teacher_id << endl;
        cout << "Faculty : " << faculty << endl;
        cout << "Department : " << department << endl; 
    }

};

// TeachingAssistant -------------------------------------------

class TeachingAssistant: public Student , public Teacher {
    string *subject;
    int nSub;
    public:
    // default constructer
    TeachingAssistant(){
        nSub = 1;
        subject = new string[nSub];
        setSub(1,"Object Oriented Programming");
    }

    // overloading constructer
    TeachingAssistant(char* pid, string fn, string ln, Date date, Address ad, 
    char* studid, string studgad, string studfac, string studdep, 
    char* tid, string tfac, string tdep, 
    int n, string sub[]) : 
    Person(pid, fn, ln, date, ad),
    Student(studid, studgad, studfac, studdep),
    Teacher(tid, tfac, tdep) {
        nSub = n;
        subject = new string[nSub];
        for(int i=0; i < nSub; i++) {
            subject[i] = sub[i];
        }
    }

    ~TeachingAssistant() {
        delete[] subject;
        cout << "Bye TeachingAssistant" << endl;
    }

    // set
    void setSub(int i, string sub) {
        nSub = i;
        subject[nSub-1] = sub;
    }

    void setNumSub(int i) {
        delete[] subject;
        subject = new string[i];
    }

    // get
    string getSubject(int i) { return subject[i-1]; }
    int getNumSubject() { return nSub; }

    // show
    void show() {
        Person::show();
        Student::show();
        Teacher::show();
        showSub();
    }

    void showSub() {
        for (int i = 0; i < nSub; i++) {
            cout << "Subject : " << subject[i] << endl;
         }
    }
};

// Main -----------------------------------------------------

int main() {
    TeachingAssistant ta;
    Date birthdate(14,02,1980);
    Address address("20/1", "Rama XII", "Marry", "Chalong", "Mueang", "Phuket", 83130);

    ta.show();

    printf("\n-----set-----\n\n");
    ta.setNumSub(3);
    ta.setSub(1,"Storytelling");
    ta.setSub(2,"Python Programming");
    ta.setSub(3,"Data Vizualization");
    ta.showSub();
    ta.show();

    printf("\n-----get-----\n\n");
    cout << "Num Subject : " << ta.getNumSubject() << endl;
    for(int i = 1; i <= ta.getNumSubject(); i++) {
        cout << "Subject : " << ta.getSubject(i) << endl;
    }
    
    string sub[3] = {"Calculas I","Calculas II","Calculas III"};

    printf("\n-----BB-----\n\n");

    TeachingAssistant bb((char*)"8888888888888","Zinedine","Zidane",birthdate, address, 
    (char*)"7777777777", "Master's degree", "Science", "Chemistry",
    (char*)"2222222222", "Science", "Mathemetics", 3, sub);

    bb.show();

    return 0;
}