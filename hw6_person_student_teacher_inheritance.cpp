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

class Student: public Person {
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
        cout << "\nStudent ID : " << student_id << endl;
        cout << "Graduate : " << graduate << endl;
        cout << "Faculty : " << faculty << endl;
        cout << "Department : " << department << endl; 
    }

};

class Teacher: public Person {
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

// ----------------- Main ---------------------

int main() {
    printf("\n----- Person -----\n\n");

    // declare variable
    Date judeBirthdate(29,06,2003);
    Date karimBirthdate;
    Address judeAddress("20/2", "Yard 24", "Phetkasem", "Dok mai", "Prawet","Bangkok", 10250);
    Address karimAddress;
    Person jude((char*)"219008831990", "Jude", "Bellingham", judeBirthdate, judeAddress);
    Person karim;
    jude.show();
    karim.show();

    // set
    karim.setFName("Karim");
    karim.setLName("Benzema");
    karim.setPersonID((char*)"7008920012390");

    karimAddress.setHouseNum("99/2");
    karimAddress.setLane("Mundo 2");
    karimAddress.setRoad("Sukhumvit");
    karimAddress.setSubArea("Khwaeng Khlong Tan Nuea");
    karimAddress.setArea("Watthana");
    karimAddress.setProvince("Bangkok");
    karim.setAddress(karimAddress);
    
    karimBirthdate.setDay(14);
    karimBirthdate.setMonth(02);
    karimBirthdate.setYear(1893);
    karim.setBirthdate(karimBirthdate);
    karim.show();

    judeAddress.set("80", "CR 7", "Sukhumvit", "Chalong", "Mueng", "Phuket", 80201);
    judeBirthdate.set(19,01,1980);
    jude.set((char*)"1234567890123", "Zinedine", "Zidane", judeBirthdate, judeAddress);
    jude.show();

    // get
    printf("\n----- get -----\n\n");
    cout << "Person ID : " << karim.getPersonID() << endl;
    cout << "Firstname : " << karim.getFName() << endl;
    cout << "Lastname : " << karim.getLName() << endl;
    cout << "Birthdate : "; karim.getBirthdate().show();
    cout << "Address : "; karim.getAddress().show();

    cout << "\nBirthdate : " << karimBirthdate.getDay() << "/" << karimBirthdate.getMonth() << "/" << karimBirthdate.getYear() << endl;

    cout << "Address : " << karimAddress.getHouseNum() << " " << karimAddress.getLane() << ", " << karimAddress.getRoad() << " Rd" << endl;
    cout << karimAddress.getSubArea() << ", " << karimAddress.getArea() << ", " << karimAddress.getProvince() << ", " << karimAddress.getPostalCode() << endl; 


    printf("\n----- Student -----\n\n");
    // ----- Declare Variable ----- //

    // Student judeStud((char*)"6605001234","Bachelor's degree","Science","Physics");
    // Student bebe;
    // judeStud.Person::set((char*)"219008831990", "Jude", "Bellingham", judeBirthdate, judeAddress);

    Student judeStud((char*)"6605001234","Bachelor's degree","Science","Physics",(char*)"3209006675290", "Jude", "Bellingham", judeBirthdate, judeAddress);

    // Show
    judeStud.show();
    // bebe.show();
    judeStud.Person::show();

    // set
    judeStud.setStudentID((char*)"6405009999");
    judeStud.setGraduate("Master's degree");
    judeStud.setFaculty("Economics");
    judeStud.setDepartment("Finance");

    judeStud.setPersonID((char*)"6507001111");
    judeStud.setFName("Bebe");
    judeStud.setLName("Bamboo");
    judeStud.setAddress(karimAddress);
    judeStud.setBirthdate(karimBirthdate);

    judeStud.show();
    judeStud.Person::show();

    // get
    
    cout << "Student ID : " << judeStud.getStudentID() << endl;
    cout << "Firstname : " << judeStud.getFName() << endl;
    cout << "Lastname : " << judeStud.getLName() << endl;
    cout << "Graduate : " << judeStud.getGraduate() << endl;
    cout << "Faculty : " << judeStud.getFaculty() << endl;
    cout << "Department : " << judeStud.getDepartment() << endl;
    cout << "Birthdate : "; judeStud.getBirthdate().show();
    cout << "Address : "; judeStud.getAddress().show();

    printf("\n----- Teacher -----\n\n");
    // ----- Declare Variable ----- //
    
    //Teacher zidane((char*)"1005001234","Economics","Finance");
    //Teacher pep;
    //zidane.Person::set((char*)"779008831990", "Zinedine", "Zidane", judeBirthdate, judeAddress);
    
    Teacher zidane((char*)"1005001234","Economics","Finance",(char*)"779008831990", "Zinedine", "Zidane", judeBirthdate, judeAddress);

    // Show
    zidane.show();
    //pep.show();
    zidane.Person::show();

    // set
    zidane.setTeacherID((char*)"6405009999");
    zidane.setFaculty("Science");
    zidane.setDepartment("Biology");

    zidane.setPersonID((char*)"90988221172836");
    zidane.setFName("Pep");
    zidane.setLName("Guardiola");
    zidane.setAddress(karimAddress);
    zidane.setBirthdate(karimBirthdate);

    zidane.show();
    zidane.Person::show();

    // get
    
    cout << "Teacher ID : " << zidane.getTeacherID() << endl;
    cout << "Firstname : " << zidane.getFName() << endl;
    cout << "Lastname : " << zidane.getLName() << endl;
    cout << "Faculty : " << zidane.getFaculty() << endl;
    cout << "Department : " << zidane.getDepartment() << endl;
    cout << "Birthdate : "; zidane.getBirthdate().show();
    cout << "Address : "; zidane.getAddress().show();

    printf("\n ---- End ---- \n");
    return 0;
}