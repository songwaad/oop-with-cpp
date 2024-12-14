#include <iostream>
#include <string.h>

using namespace std;

class Date {
        int day;
        int month;
        int year;
    public:
        Date() { set(1,1,1990); }
        Date(int d, int m, int y) { set(d,m,y); }
        ~Date() { cout << "Bye Date" << endl;}

        void set(int d, int m, int y) { day = d; month = m; year = y; }
        void setDay(int d) { day = d; }
        void setMonth(int m) { month = m; }
        void setYear(int y) { year = y; }

        int getDay() { return day; }
        int getMonth() { return month; }
        int getYear() { return year; }

        void show() { cout << day << "/" << month << "/" << year << endl; }

        void input(istream &is) {
            cout << "Birthdate" << endl;
            cout << "Enter Day : "; is >> day;
            cout << "Enter month : "; is >> month;
            cout << "Enter year : "; is >> year;
        }

};

//--------------------------------------------------------------

class Address {
        string house_num;
        string lane;
        string road;
        string subarea;
        string area;
        string province;
        int postal_code;
    public:
        Address() { set("282","-","Ramkhamhaeng","Hua Mak","Bang Kapi","Bangkok",10240); }
        Address(string h, string l, string r, string s, string a, string p, int c) {
            set(h, l, r, s, a, p, c);
        }
        ~Address() { cout << "Bye Address" << endl; }

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

        string getHouseNum() { return house_num; }
        string getLane() { return lane; }
        string getRoad() { return road; }
        string getSubArea() { return subarea; }
        string getArea() { return area; }
        string getProvince() { return province; }
        int getPostalCode() { return postal_code; }

        void show() {
            cout << house_num + " Soi " + lane + ", " + road + " Rd" << endl;
            cout << subarea + ", " + area + ", " + province + " " << postal_code << endl;
        }

        void input(istream &is) {
            cout << "Address" << endl;
            cout << "Enter house_num : "; is >> house_num;
            cout << "Enter lane : "; is >> lane;
            cout << "Enter road : "; is >> road;
            cout << "Enter subarea : "; is >> subarea;
            cout << "Enter area : "; is >> area;
            cout << "Enter province : "; is >> province;
            cout << "Enter postal_code : "; is >> postal_code;
        }
};

class Person {
        char person_id[14];
        string fname;
        string lname;
        Date birthdate;
        Address *address;
        int numAddress;

        void set(char* id, string fn, string ln, Date d, int k) {
            strcpy(person_id, id);
            fname = fn;
            lname = ln;
            birthdate = d;
            numAddress = k;
            address = new Address[numAddress];
        }
    public:
        Person() { set((char*)"1000000000001", "firsname", "lastname", birthdate, 1); }
        Person(char* id, string fn, string ln, Date d, int k) {
            set(id, fn, ln, d, k);
        }
        ~Person() { delete[] address; cout << "Bye Person" << endl; }
        
        void setPersonID(char* id) { strcpy(person_id, id); }
        void setFName(string fn) { fname = fn; }
        void setLName(string ln) { lname = ln; }
        void setBirthdate(Date d) { birthdate = d; }
        void setNumAddress(int i) { delete[] address; numAddress = i; address = new Address[numAddress]; }
        void setAddress(Address &a, int i) { address[i] = a; }

        char* getPersonID() { return person_id; }
        string getFName() { return fname; }
        string getLName() { return lname; }
        Date getBirthdate() { return birthdate; }
        Address getAddress(int i) { return address[i]; }
        int getNumAddress() { return numAddress; }

        void show() {
            cout << "\nPerson ID : " << person_id << endl;
            cout << "Firstname : " << fname << endl;
            cout << "Lastname : " << lname << endl;
            cout << "Birth date : "; birthdate.show();
            cout << "Num Address : " << numAddress << endl;
            for(int i=0; i<numAddress;i++) {
                cout << "Address " << i+1 << " : " ; address[i].show();
            }
        }

        Person& operator=(const Person &p) {
            cout << "***assigment operator[Person] is call***" << endl;
            if(this==&p) return *this;

            strcpy(person_id, p.person_id);
            fname = p.fname;
            lname = p.lname;
            birthdate = p.birthdate;
            
            delete[] address;
            if(p.numAddress!=0) {
                numAddress = p.numAddress;
                address = new Address[numAddress];
                for(int i=0; i<numAddress; i++) {
                    address[i] = p.address[i];
                }
            } else numAddress = 0;

            return *this;
        }

        Person(const Person &p) {
            cout << "**copy constructor[Person] is call**" << endl;

            strcpy(person_id, p.person_id);
            fname = p.fname;
            lname = p.lname;
            birthdate = p.birthdate;
            
            if(p.numAddress!=0) {
                numAddress = p.numAddress;
                address = new Address[numAddress];
                for(int i=0; i<numAddress; i++) {
                    address[i] = p.address[i];
                }
            } else numAddress = 0;
        }

        void input(istream &is) {
            cout << "Person" << endl;
            cout << "Enter Person ID (13) : "; is >> person_id;
            cout << "Enter Firstname : "; is >> fname ;
            cout << "Enter Lastname : "; is >> lname ;
            birthdate.input(is);

            cout << "Enter Address (Num) : "; is >> numAddress;
            delete[] address;
            address = new Address[numAddress];

            for(int i=0; i<numAddress; i++) {
                 cout << i+1 << " "; address[i].input(is);
            }
        }    
};

class Student: virtual public Person {
    char student_id[11];
    string graduate;
    string faculty;
    string department;
    string *club;
    int numClub;

    void set(char* id, string g, string f, string d, int k) {
        strcpy(student_id, id);
        graduate = g;
        faculty = f;
        department = d;
        numClub = k;
        club = new string[numClub];
        for(int i=0; i<numClub; i++) {
            setClub(i, "Music");
        }
    }

    public:

    Student() { set((char*)"1000000000", "Bachelor's degree", "Science", "Computer Science",1); }
    Student(char* id, string g, string f, string d, int i,
    char* pid, string fn, string ln, Date date, int k)
    :Person(pid, fn, ln, date, k) {
        set(id, g, f, d, i);
    }
    Student(char* id, string g, string f, string d, int i) {
        set(id, g, f, d, i);
    }
    ~Student() { delete[] club; cout << "Bye Student" << endl;}

    void setStudentID(char* id) { strcpy(student_id, id); }
    void setGraduate(string g) { graduate = g; }
    void setFaculty(string f) { faculty = f; }
    void setDepartment(string d) { department = d; }
    void setNumClub(int i) {
        delete[] club;
        numClub = i;
        club = new string[numClub];
        for(int i=0; i<numClub; i++) {
            setClub(i, "Music");
        }
    }
    void setClub(int i, string c) { club[i] = c; }

    char* getStudentID() { return student_id; }
    string getGraduate() { return graduate; }
    string getFaculty() { return faculty; }
    string getDepartment() { return department; }
    int getNumClub() { return numClub; }
    string getClub(int i) { return club[i]; }
    
    void show() {
        Person::show();
        cout << "\nStudent ID : " << student_id << endl;
        cout << "Graduate : " << graduate << endl;
        cout << "Faculty : " << faculty << endl;
        cout << "Department : " << department << endl; 
        cout << "Num Club : " << numClub << endl;
        for(int i=0; i<numClub; i++) {
            cout << "Club " << i+1 << " : " << club[i] << endl;
        }
    }

    Student& operator=(const Student &stud) {
        cout << "***assigment operator[Student] is call***" << endl;
        if(this==&stud) return *this;

        Person::operator=(stud);

        strcpy(student_id,stud.student_id);
        graduate = stud.graduate;
        faculty = stud.faculty;
        department = stud.department;
    
        delete[] club;
        if(stud.numClub!=0) {
            numClub = stud.numClub;
            club = new string[numClub];
            for(int i=0; i< numClub; i++) {
                club[i] = stud.club[i];
            }
        } else { numClub = 0; }
        return *this;
    }

    Student(const Student &stud):Person(stud) {
        cout << "**copy constructor[Srudent] is call**" << endl;

        //Person::operator=(stud);

        strcpy(student_id,stud.student_id);
        graduate = stud.graduate;
        faculty = stud.faculty;
        department = stud.department;
    
        if(stud.numClub!=0) {
            numClub = stud.numClub;
            club = new string[numClub];
            for(int i=0; i< numClub; i++) {
                club[i] = stud.club[i];
            }
        } else { numClub = 0; }
    }

    void input(istream &is) {
        Person::input(is);
        cout << "Student" << endl;
        cout << "Enter student_id : "; is >> student_id;
        cout << "Enter graduate : "; is >> graduate;
        cout << "Enter faculty : "; is >> faculty;
        cout << "Enter department : "; is >> department;
        cout << "Enter Num Club : "; is >> numClub;

        delete[] club;
        club = new string[numClub];
        for(int i=0; i< numClub; i++) {
            cout << "Enter Num Club " << i+1 << " : "; is >> club[i];
        }
    }
};

class Teacher: virtual public Person {
    char teacher_id[11];
    string faculty;
    string *department;
    
    public:
    Teacher() { 
        department = new string();
        set((char*)"1000000000", "Science", "Computer Sciebce"); }

    Teacher(char* id, string f, string dep, 
    char* pid, string fn, string ln, Date date, int k)
    :Person(pid, fn, ln, date, k) { 
        department = new string();
        set(id, f, dep); }

    Teacher(char* id, string f, string dep ) { set(id, f, dep); }
    ~Teacher() { delete department; cout << "Bye Teacher" << endl; }

    void set(char* id, string f, string dep) {
        strcpy(teacher_id, id);
        faculty = f;
        *department = dep;
    }
    void setTeacherID(char* id) { strcpy(teacher_id, id); }
    void setFaculty(string f) { faculty = f; }
    void setDepartment(string d) { *department = d; }

    char* getTeacherID() { return teacher_id; }
    string getFaculty() { return faculty; }
    string getDepartment() { return *department; }

    void show() {
        Person::show();
        showTecher();
    }

    void showTecher() {
        cout << "\nTeacher ID : " << teacher_id << endl;
        cout << "Faculty : " << faculty << endl;
        cout << "Department : " << *department << endl;
    }

    void input(istream &is) {
        Person::input(is);
        inputTeacher(is);
    }

    void inputTeacher(istream &is) {
        cout << "Teacher" << endl;
        cout << "Enter teacher_id : "; is >> teacher_id;
        cout << "Enter faculty : "; is >> faculty;
        cout << "Department : "; is >> *department;
    }

    Teacher& operator=(const Teacher &t) {
        cout << "***assigment operator[Teacher] is call***" << endl;
        if(this==&t) return *this;

        Person::operator=(t);

        strcpy(teacher_id,t.teacher_id);
        faculty = t.faculty;
        *department = *t.department;
        return *this;
    }

    Teacher(const Teacher &t):Person(t) {
        cout << "**copy constructor[Teacher] is call**" << endl;

        strcpy(teacher_id,t.teacher_id);
        faculty = t.faculty;
        *department = *t.department;
    }
};


class TeachingAssistant: public Student , public Teacher {
    string *subject;
    int nSub;

    public:
    TeachingAssistant() {
        nSub = 1;
        subject = new string[nSub];
        setSub(0,"Object Oriented Programming");
    }
    TeachingAssistant(char* pid, string fn, string ln, Date date, int k, 
    char* studid, string studgad, string studfac, string studdep, int j,
    char* tid, string tfac, string dep,
    int n, string sub[])
    :Person(pid, fn, ln, date, k) ,
    Student(studid, studgad, studfac, studdep, j) ,
    Teacher(tid, tfac, dep) {
        nSub = n;
        subject = new string[nSub];
        for(int i=0; i < nSub; i++) {
            subject[i] = sub[i];
        }
    }

    ~TeachingAssistant() { delete[] subject; cout << "Bye TeachingAssistant" << endl; }

    void setSub(int i, string sub) { subject[i] = sub; }
    void setNumSub(int i) {
        delete[] subject;
        nSub = i;
        subject = new string[nSub];
        for(int j = 0; j < nSub; j++) {
            setSub(i,"Object Oriented Programming");
        }
    }

    string getSubject(int i) { return subject[i]; }
    int getNumSubject() { return nSub; }

    void show() {
        Student::show();
        showTecher();
        cout << "Num Subject : " << nSub << endl;
        for (int i = 0; i < nSub; i++) {
            cout << "Subject : " << subject[i] << endl;
         }
    }

    TeachingAssistant& operator=(TeachingAssistant &ta) {
        cout << "***assigment operator[TA] is call***" << endl;
        if(this==&ta) return *this;

        Student::operator=(ta);
        //Teacher::operator=(ta);
        Teacher::set(ta.getTeacherID(), ta.Teacher::getFaculty(), ta.Teacher::getDepartment());


        delete[] subject;
        if (ta.nSub != 0) {
            nSub = ta.nSub;
            subject = new string[nSub];
            for (int i = 0; i < nSub; i++) {
                subject[i] = ta.subject[i];
            }
        } else { nSub = 0; }

        return *this;
    }

    TeachingAssistant(const TeachingAssistant &ta):Student(ta),Teacher(ta) {
        cout << "**copy constructor[TA] is call**" << endl;

        if (ta.nSub != 0) {
            nSub = ta.nSub;
            subject = new string[nSub];
            for (int i = 0; i < nSub; i++) {
                subject[i] = ta.subject[i];
            }
        } else { nSub = 0; }
    }

    void input(istream& is) {
        Student::input(is);
        inputTeacher(is);
        cout << "Enter Subject(Num) : "; is >> nSub;
        if(nSub!=0) {
            delete[] subject;
            subject = new string[nSub];
            for(int i=0; i < nSub; i++) {
                cout << "Enter Subect " << i+1 << " : "; is >> subject[i]; 
            }
        }
    }
};

// ostream & istream operator -----------------------------------------------------

ostream& operator<<(ostream &os, Date &d) {
    d.show();
    return os;
}

istream& operator>>(istream &is, Date &d) {
    d.input(is);
    return is;
}

ostream& operator<<(ostream &os, Address &add) {
    add.show();
    return os;
}

istream& operator>>(istream &is, Address &add) {
    add.input(is);
    return is;
}

ostream& operator<<(ostream &os, Person &p) {
    p.show();
    return os;
};

istream& operator>>(istream &is, Person &p) {
    p.input(is);
    return is;
};

ostream& operator<<(ostream &os, Student &s) {
    s.show();
    return os;
}

istream& operator>>(istream &is, Student &s) {
    s.input(is);
    return is;
}

ostream& operator<<(ostream &os, Teacher &t) {
    t.show();
    return os;
}

istream& operator>>(istream &is, Teacher &t) {
    t.input(is);
    return is;
}

ostream& operator<<(ostream& os,TeachingAssistant &ta) {
    ta.show();
    return os;
}

istream& operator>>(istream& is,TeachingAssistant &ta){
    ta.input(is);
    return is;
}

// Main -----------------------------------------------------

int main() {
    Date birthdate(14,02,1980);
    Address address("20/1", "Rama XII", "Marry", "Chalong", "Mueang", "Phuket", 83130);
    string sub[3] = {"Calculas I","Calculas II","Calculas III"};

    //Person p; p.show();
    //cin >> p; cout << p;

    //Student stud; //stud.show();
    //cin >> stud; cout << stud;

    Teacher t; t.show();
    cin >> t; cout << t;

    //TeachingAssistant ta; // ta.show();
    //cin >> ta; cout << ta;

    /*TeachingAssistant jude((char*)"8888888888888","Jude","Bellingham",birthdate, 2, 
    (char*)"7777777777", "Master's degree", "Science", "Chemistry", 3,
    (char*)"2222222222", "Science", 2, 3, sub);
    jude.setAddress(address,0);
    jude.setBirthdate(birthdate);*/

    // jude.show();

    //ta = jude;
    //TeachingAssistant ta(jude);
    //cout << ta;
    //cout << ta << jude;

    //p = jude;
    //Person p(jude);
    //cout << p;

    //Student stud(jude);
    //stud = jude;
    //cout << stud;

    //Teacher t(jude);
    //t = jude;
    //cout << t;

    printf("\n----- End -----\n");

}