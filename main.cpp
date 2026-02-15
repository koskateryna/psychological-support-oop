#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include "header.h"
#include "template.h"
#define n 10
#define N 4

using namespace std;


User::User(){}
User::User(bool _isSpecialist) : isSpecialist(_isSpecialist) {}
User::User(string &name, int age, string &gender, string &phone, string &email, string &password): name(name), age(age), gender(gender), phone(phone), email(email), password(password) {}
User::User(const User &other): name(other.name), age(other.age), gender(other.gender),phone(other.phone), email(other.email), password(other.password) {}
//User::User(string a) {
//    string gender = "None"; string phone = "None"; string email = "None"; string password = "None";
//    setName(a); setAge(0); setGender(gender); setPhone(phone); setEmail(email); setPassword(password);
//}
User:: ~User() {}
string User::getName() const {return name;}
int User::getAge() const { return age; }
string User::getGender() const { return gender; }
string User::getPhone() const { return phone; }
string User::getEmail() const { return email; }
string User::getPassword() const { return password; }
bool User::getIsSpecialist() const {return isSpecialist;}
User& User::setName(string& newName) {
    name = newName;
    return *this;
}
User& User::setAge(int newAge) {
    if (newAge >= 0) {
        age = newAge;
    }
    else {
        cerr << "Incorrect age" << endl;
    }
    return *this;
}

User& User::setGender(string& newGender) {
    gender = newGender;
    return *this;
}

User& User::setPhone(string& newPhone) {
    phone = newPhone;
    return *this;
}

User& User::setEmail(string& newEmail) {
    email = newEmail;
    return *this;
}

User& User::setPassword(string& newPassword) {
    password = newPassword;
    return *this;
}

///////////// ОПЕРАТОР ВВЕДЕННЯ ВИВЕДЕННЯ //////////////
istream & operator >> (istream& is, User&c){
    cout << "    --- Enter name --- \n";
    is>>c.name;
    cout << "    --- Enter age --- \n";
    is>>c.age;
    cout << "    --- Enter gender --- \n";
    is>>c.gender;
    cout << "    --- Enter phone number --- \n";
    is>>c.phone;
    cout << "    --- Enter email --- \n";
    is>>c.email;
    cout << "    --- Enter password --- \n";
    is>>c.password;
    return is;
}
ostream & operator << (ostream& os, const User&c){
//    cout<<"\n    --- Your info --- \n";
//    os<<"     | "<<c.name<<endl;
//    os<<"     | "<<c.age <<endl;
//    os<<"     | "<<c.gender<<endl;
//    os<<"     | "<<c.phone<<endl;
//    os<<"     | "<<c.email<<endl;
//    os<<"     | "<<c.password<<endl;
    cout<<"\n    --- Your info --- \n";
    os<<"     | "<<c.name<<" "<<c.age<<" "<<c.gender<<" "<<c.phone<<" "<<c.email<<" "<<c.password<<" |"<<endl;
    return os;
}

bool User::operator==(const User& other) const {
    return (name == other.name && age == other.age &&
            gender == other.gender && phone == other.phone &&
            email == other.email && isSpecialist == other.isSpecialist);
}

bool User::operator!=(const User& other) const {
    return !(*this == other);
}

/////////// ОПЕРАТОР ПРИСВОЮВАННЯ /////////////////
const User & User::operator=(const User &c) {
    if(this!=&c) { //захист від самоприсвоювання
        name = c.name;
        age = c.age;
        gender = c.gender;
        phone = c.phone;
        email = c.email;
        password = c.password;
        isSpecialist = c.isSpecialist;
    }
    return *this;
}


NonSpecialist::NonSpecialist() :User() {}
NonSpecialist::NonSpecialist(string& name, int age,  string& gender, string& phone,  string& email, string& password): User(name, age, gender, phone, email, password) {}
NonSpecialist::NonSpecialist(const NonSpecialist& other): User(other) {}
NonSpecialist::NonSpecialist(bool _isSpecialist) : User(_isSpecialist) {}
NonSpecialist::~NonSpecialist() {}


Date::Date() : day(1), month(1), year(2023){};
Date::Date(int d, int m, int y) {
    if (0 < d && d <= 31) {
        day = d;
    } else {
        cout << "Uncorect day" << endl;
        day = 1;
    }
    if (0 < m && m <= 12) {
        month = m;
    } else {
        cout << "Uncorect month" << endl;
        month = 1;
    }

    if (y >= 2023) {
        year = y;
    } else {
        cout << "Uncorect year" << endl;
        year = 2023;
    }
};
Date::Date(const Date &date) {
    day = date.day;
    month = date.month;
    year = date.year;
}
Date::~Date(){}
int Date::GetDay() const { return day; }
int Date::GetMonth() const { return month; }
int Date::GetYear() const { return year; }
Date& Date::SetDay(int d) {
    if (0 < d && d <= 31) {
        day = d;
    } else {
        cout << "Uncorect day" << endl;
    }
    return *this;
}
Date& Date::SetMonth(int m) {
    if (0 < m && m <= 12) {
        month = m;
    } else {
        cout << "Uncorect month" << endl;
    }
    return *this;
}
Date& Date::SetYear(int y) {
    if (y >= 2023) {
        year = y;
    } else {
        cout << "Uncorect year" << endl;
    }
    return *this;
}
void Date::Info() const {
    cout << "Date:" << day << "." << month << "." << year << endl;
};
Date&Date::Change(int newd, int newm, int newy) {
    if (0 < newd && newd <= 31 ) {
        day = newd;
    } else {
        cout << "Uncorect day" << endl;
    }
    if (0 < newm && newm <= 12) {
        month = newm;
    } else {
        cout << "Uncorect month" << endl;
    }
    if (newy >= 2023) {
        year = newy;
    } else {
        cout << "Uncorect year" << endl;
    }
    return *this;
}

ostream& operator << (ostream& os, const Date& c) {
    os << "Date:" << c.day << "." << c.month << "." << c.year << endl;
    return os;
};
///////////// ОПЕРАТОР ІНКРЕМЕНТ ДЕКРЕМЕНТ //////////////
Date& Date::operator ++(){
    day++;
    if (day > 31) { day = 1; month++; }
    if (month > 12) { month = 1; year++; }
    return *this;
}
Date Date::operator ++(int) {
    Date temp = *this;
    ++(*this);
//    day++;
//    if (day > 31) { day = 1; month++; }
//    if (month > 12) { month = 1; year++; }
    return temp;
}
Date& Date::operator --(){
    day--;
    if (day < 1) { day = 31; month--; }
    if (month < 1) { month = 12; year--; }
    return *this;
}
Date Date::operator --(int) {
    Date temp = *this;
    --(*this);
//    day--;
//    if (day < 1) { day = 31; month--; }
//    if (month < 1) { month = 12; year--; }
    return temp;
}

Specialist::Specialist() :User(), degree("") {};
Specialist::Specialist(string& name, int age, string& gender, string& phone, string& email, string& password, string& newdegree) :User(name, age, gender, phone, email, password) {
    degree = newdegree;
}
Specialist::Specialist(bool _isSpecialist, string& _degree): User(_isSpecialist), degree(_degree) {}
Specialist::Specialist(const Specialist& spec): User(spec){
    degree=spec.degree;
}
Specialist::~Specialist() {}
string Specialist::GetDegree() const {
    return degree;
}
Specialist& Specialist::SetDegree(string& deg) {
    degree = deg;
    return *this;
}
string Specialist::AddArtical() const{
    cout << "Enter your article" << endl;
    string artical;
    cin >> artical;
    return artical;
}
string Specialist::ChangeArtical(string& artical) const {
    cout << "Enter your new article" << endl;
    cin >> artical;
    return artical;
}
void Specialist::Info() const {
    cout << "     | Name: " <<  getName() << endl << "     | Age: " << getAge() << endl << "     | Gender: " << getGender() << endl << "     | Degree:" << degree << endl;
}
void Specialist::ShortInfo() const {
    cout << "Name: " <<  getName() << endl  << "Degree:" << degree << endl;
}
void Specialist::DeleteArtical(string& artical) const {
    cout << "Your article is delete" << endl;
    artical = "";
}


//Specialist::Specialist(User a): User(&a), degree("None") {}
//Specialist::Specialist(NonSpecialist a) : User(&a), degree("None") {}

////////////// ПЕРЕТВОРЕННЯ ТИПІВ //////////////////////
Specialist::Specialist(string a) {
    string gender = "None"; string phone = "None"; string email = "None"; string password = "None"; degree = "None";
    setName(a); setAge(0); setGender(gender); setPhone(phone); setEmail(email); setPassword(password);
}
Specialist::operator string() {
    return getName();
}

istream & operator >> (istream& is, Specialist&c){
    cout << "    --- Enter degree --- \n";
    is>>c.degree;
    return is;
}

ostream & operator << (ostream& os, const Specialist&c){
    os<<"     | "<<c.degree<<endl;
    return os;
}

Consultation::Consultation() {
    specialist = Specialist();
    date = Date();
    consulCount++;
}
Consultation::Consultation(Specialist spec, Date dat) {
    specialist = spec;
    date = dat;
}
Consultation::Consultation(const Consultation &consultation) {
    specialist = consultation.specialist;
    date = consultation.date;
}
Consultation::~Consultation(){}
Specialist Consultation::GetSpec() { return specialist; }
Date Consultation::GetDate() const { return date; }
int Consultation::consulCount = 0;
int Consultation::getConsulCount() { return consulCount; }
Consultation& Consultation::SetSpecialist(Specialist spec) {
    specialist = spec;
    return *this;
}
Consultation& Consultation::SetDate(Date dat) {
    date = dat;
    return *this;
}
void Consultation::Info() const{
    cout << "Specialist: ";
    specialist.getName();
    specialist.Info();
    cout << "Date: ";
    date.Info();
}
void Consultation::displayMenu() const {
    cout << "1. Registration" << endl;
    cout << "2. Changing account data" << endl;
    cout << "3. Login to the account" << endl;
    cout << "4. Test" << endl;
    cout << "5. Practice" << endl;
    cout << "0. Exit" << endl;
    cout << "Choose an option: ";
}

string Test::question[n]={
        "\n1. You could not get rid of uncontroled anxiety and anxious thoughts.",
        "2. You were so restless that they could not sit still.",
        "3. You were easily irritated or felt anger.",
        "4. You felt a strong fear that something terrible might happen.",
        "5. You felt depression, sadness and hopelessness for a long time.",
        "6. Had difficulty falling asleep, or slept too much.",
        "7. You felt tired or had no energy.",
        "8. You felt had no appetite or overate.",
        "9. It was difficult for you to concentrate on most classes.",
        "10. You felt bad about yourselves (considered yourselves a failure).",};
Test::Test(): point(0) {}
Test::~Test() {}
Test::Test(float _point): point(_point) {}
Test::Test(const Test&a): point(a.point) {}
float Test::getpoint() const {return point;}
string Test::getquestion() { return question[n];}
Test& Test::setpoint(float _point) {
    if (_point >= 0 && _point <= 20) {
        point = _point;
        return *this;
    } else
        cout << " // Invalid value of point //" << endl;
}

ostream & operator << (ostream& os, const Test&c){
    return os << "    --- ( point: " << c.point << " ) ---\n"<<endl;
}

///////////////////// АРИФМЕТИЧНІ + ПОРІВНЯННЯ /////////////////
const Test& Test::operator = (const Test&с){
    if (this !=&с) //захист від самоприсвоювання
        point=с.point;
    else point=0;
    return *this;
}
bool Test:: operator==(const Test&c) const{
    return point==c.point;
}
Test& Test::operator+=(const Test&с) {
    point+=с.point;
    return *this;
}
bool Test:: operator<(const Test&с) const{
    return point<с.point;
}
bool Test:: operator>(const Test&c) const{
    return point>c.point;
}
bool Test::operator!=(const Test &c) const {
    return !(point==c.point);
}

float Test::answer() {
    int _answer;
    float half_p = 0.5, one_p = 1, two_p = 2;
    point=0;
    for (int i = 0; i < n; i++) {
        cout<<question[i]<<endl;
        tryAgain:
        cin>>_answer;
        switch (_answer) {
            case 1: point=point; break;
            case 2: point=point+half_p; break;
            case 3: point=point+one_p; break;
            case 4: point=point+two_p; break;
            default: {
                cout << "Unknown! Try again." << endl;
                goto tryAgain;
            }
        }
    }
    return point;
}

Result_Good::Result_Good(): Test() {}
Result_Good::~Result_Good() {}
Result_Good::Result_Good(const Result_Good&a): Test(a) {}
Result_Good::Result_Good(float _point): Test(_point) {}
bool Result_Good::setpoint(float _point){
    if (_point>5){
        point=_point;
        return true;
    }
    return false;
}
void Result_Good::suggest_help() const {}


Result_Bad::Result_Bad(): Test() { }
Result_Bad::~Result_Bad() {}
Result_Bad::Result_Bad(const Result_Bad&a): Test(a)  {}
Result_Bad::Result_Bad(float _point): Test(_point) {}
bool Result_Bad::setpoint(float _point){
    if (_point<=5){
        point=_point;
        return true;
    }
    return false;
}
void Result_Bad::suggest_help() const {}
void Result_Bad::suggest_specialist() const {}


Help::Help() : title(""), content(""), premium(""), name("") {}
Help::Help(const Help& other) : title(other.title), content(other.content), premium(other.premium), name(other.name) {}
Help::Help(string& title, string& content, string& premium,  string& name): title(title), content(content), premium(premium), name(name) {}
Help::~Help() {}
void Help::showHelp() const {
    cout << "Default Help: " << title << " - " << content << " (Premium: " << premium << ", Name: " << name << ")" << endl;
}
string Help::getTitle() const { return title; }
string Help::getContent() const { return content; }
string Help::getPremium() const { return premium; }
string Help::getName() const { return name; }
Help& Help::setTitle(string& newTitle) { title = newTitle; return *this; }
Help& Help::setContent(string& newContent) { content = newContent; return *this; }
Help& Help::setPremium(string& newPremium) { premium = newPremium; return *this; }
Help& Help::setName(string& newName) { name = newName; return *this; }

///////////// ОПЕРАТОР ІНДЕКСАЦІЇ //////////////
string & Help::operator[](const int index) {
    if (index >= 0 && index < N)
        return premium_content[index];
    else {
        premium_content[index]="empty";
        return premium_content[index];
    }
}
///////////// ОПЕРАТОР ФУНКЦІЇ //////////////
string Help::operator()(int first, int last){
    string t;
    for (int i = first; i <= last; ++i) {
        if (i >= 1 && i <= N) {
            t += premium_content[i-1];
        } else {
            t += "    --- Invalid selection ---\n";
        }
    }
    return t;
}

ostream & operator << (ostream& os, const Help&c){
    for (int i = 0; i < N; i++) {
        os<<c.premium_content[i];
    }
    return os;
}


Meditation::Meditation() : Help(), time(0.0f) {}
Meditation::Meditation(const Meditation& other) : Help(other), time(other.time) {}
Meditation::Meditation(string& title, string& content, string& premium,  string& name, float time):Help(title, content, premium, name), time(time) {}
void Meditation::showHelp() const {
    cout << "Meditation Help: " << title << " - " << content << " (Premium: " << premium << ", Name: " << name << ", Time: " << time << " minutes)" << endl;
}
Meditation::~Meditation() {}
float Meditation::getTime() const { return time; }
Meditation& Meditation::setTime(float newTime) { time = newTime; return *this; }


ASMR::ASMR() : Help(), time(0.0f) {}
ASMR::ASMR(const ASMR& other) : Help(other), time(other.time) {}
ASMR::ASMR(string& title,  string& content, string& premium, string& name, float time): Help(title, content, premium, name), time(time) {}
void ASMR::showHelp() const {
    cout << "ASMR Help: " << title << " - " << content << " (Premium: " << premium << ", Name: " << name << ", Time: " << time << " minutes)" << endl;
}
ASMR::~ASMR() {}
float ASMR::getTime() const { return time; }
ASMR& ASMR::setTime(float newTime) { time = newTime; return *this; }
//bool ASMR:: operator<(const ASMR& с) const {
//    return time < с.time;
//}

BreathingExercise::BreathingExercise() : Help(), time(0.0f) {}
BreathingExercise::BreathingExercise(const BreathingExercise& other) : Help(other), time(other.time) {}
BreathingExercise::BreathingExercise(string& title, string& content, string& premium,  string& name, float time): Help(title, content, premium, name), time(time) {}
void BreathingExercise::showHelp() const {
    cout << "Breathing Exercise Help: " << title << " - " << content << " (Premium: " << premium << ", Name: " << name << ", Time: " << time << " minutes)" << endl;
}
BreathingExercise::~BreathingExercise() {}
float BreathingExercise::getTime() const { return time; }
BreathingExercise& BreathingExercise::setTime(float newTime) { time = newTime; return *this; }


Article::Article() : Help(), time(0.0f) {}
Article::Article(const Article& other) : Help(other), time(other.time) {}
Article::Article(string& title, string& content, string& premium, string& name, float time): Help(title, content, premium, name), time(time) {}
void Article::showHelp() const {
    cout << "Article Help: " << title << " - " << content << " (Premium: " << premium << ", Name: " << name << ", Time: " << time << " minutes)" << endl;
}
Article::~Article() {}
float Article::getTime() const { return time; }
Article& Article::setTime(float newTime) { time = newTime; return *this; }
//bool Article:: operator<(const Article& с) const {
//    return time < с.time;
//}

/////////////////////////// ШАБЛОНИ /////////////////////////////////////////
template<typename T>
Statistic<T>::Statistic(int _size):size(_size){
    if (size!=0) data = new T[size];
    else data=0;
}

template<typename T>
Statistic<T>::Statistic(const Statistic<T> &a) {
    size=a.size;
    if (size!=0){
        data=new T[size];
        for (int i = 0; i < size; ++i) {
            data[i]=a.data[a];
        }
    } else data=0;
}

template<typename T>
Statistic<T>::~Statistic() { delete[] data;}

template<typename T>
int Statistic<T>::getsize() const { return size;}

template<typename T>
const Statistic<T>& Statistic<T>::operator = (const Statistic<T>&a){
    if (this != &a) {
        delete[] data;
        size = a.size;
        data = new T[size];
        for (int i = 0; i < size; ++i) {
            data[i] = a.data[i];
        }
    }
    return *this;
}

template<typename T>
T& Statistic<T>::operator[](int index) {
    if (index<0 || index >=size){
        cout<< "\nInvalid value"<<endl;
        exit(1);
    }
    return data[index];
}

//template<typename T1>
//ostream& operator<<(ostream& os, const Statistic<T1>&c) {
//    for (int i = 0; i < c.size; ++i) {
//        os << c.data[i] <<  "; ";
//    }
//    return os;
//}


template<typename T>
Statistic<T>& Statistic<T>::operator += (const Statistic<T>&c){
    for (int i = 0; i < size; i++)
        data[i] += c.data[i];
    return *this;
}

template<typename T>
Statistic<T>& Statistic<T>::operator /= (const Statistic<T>&c){
    for (int i = 0; i < size; i++)
        data[i] /= c.data[i];
    return *this;
}

template<typename T>
bool Statistic<T>::operator<(const Statistic<T> &c) {
    return data<c.data;
}

template<typename T>
bool Statistic<T>::operator>(const Statistic<T> &c) {
    return data>c.data;
}

template<typename T>
T Statistic<T>:: maxel() {
    T max=data[0];
    for (int i = size - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (max< data[j + 1]) {
                max = data[j + 1];
            }
        }
    }
    return max;
}

template<typename T>
T Statistic<T>::average(){
    T res=0;
    for (int i = 0; i < size; ++i) {
        res += data[i];
    }
    res/=size;
    return res;
}
///////////////////////// СПЕЦІАЛІЗАЦІЯ /////////////////////////////
Statistic<char*>::Statistic(int _size) {
    size = _size;
    if (size != 0) {
        data = new char*[size];
        for (int i = 0; i < size; i++)
            data[i] = NULL;
    }
    else
        data = NULL;
}

Statistic<char*>::Statistic(const Statistic<char*> &a) {
    size=a.getsize();
    if (size==0){
        data = NULL;
        return;
    }
    data=new char*[size];
    for (int i = 0; i < size; i++){
        if (a.data[i]!=NULL){
            data[i]=new char [strlen(a.data[i])+1];
            strcpy(data[i],a.data[i]);
        }
        else
            data[i] = NULL;
    }
}

Statistic<char*>::~Statistic() {
    for (int i = 0; i < size; ++i)
        delete [] data[i];
    delete [] data;
}

int Statistic<char*>::getsize() const { return size; }

const Statistic<char*>& Statistic<char*>::operator = (const Statistic<char*>&a){
    if(this==&a) return *this;
    for (int i = 0; i < size; ++i)
        delete [] data[i];
    delete [] data;
    size = a.size;
    if(size==0){
        data=NULL;
        return *this;
    }
    data = new char*[size];
    for (int i = 0; i < size; ++i)
        if (a.data[i]!=NULL){
            data[i]=new char [strlen(a.data[i])+1];
            strcpy(data[i],a.data[i]);
        }
        else
            data[i] = NULL;
    return *this;
}

char*& Statistic<char*>::operator[](int index) {
    if(index<0 || index >=size){
        cout<< "\nInvalid value"<<endl;
        exit(1);
    }
    return data[index];
}

//ostream& operator<<(ostream& os, const Statistic<char*>&c) {
//    for (int i = 0; i < c.size; ++i) {
//        os << c.data[i] << "; ";
//    }
//    return os;
//}

template<typename InputIt, typename T>
InputIt find(InputIt first, InputIt last, const T& value){
    for (; first!=last; ++first)
        if (*first == value) return first;
    return last;
}

int main() {
    bool _isSpecialist;
    User user1, user2;
    cin>>user1;
    cout << "    --- Are you a specialist? (1 - yes, 0 - no) --- " << endl;
    cin >> _isSpecialist;
    user2=user1;
    if (_isSpecialist){
        Specialist specialist;
        cin>>specialist;
//        cout<<user1;
//        cout<<specialist;
//        cout<<user2; cout<<specialist;
    }
    else{
        NonSpecialist nonSpecialist(_isSpecialist);
//        cout<<user1;
//        cout<<user2;
    }
    cout << "    --- Login is successful! --- " << endl;

    float _point1, _point2;
    cout << "\n     | Answer for each question | " << endl;
    cout << "    | 1 - Totally agree          | " << endl;
    cout << "    | 2 - Particularly agree     | " << endl;
    cout << "    | 3 - Particularly disagree  | " << endl;
    cout << "    | 4 - Totally disagree       | " << endl;

    Test t1;
    _point1 = t1.answer();
    t1.setpoint(_point1);
    Result_Bad res_bad1;
    Result_Good res_good1;

    if (res_bad1.setpoint(_point1)){
        Consultation cons1;
        cout << "\n    --- Result is BAD! ---" << endl;
        cout << t1;
    }
    else if (res_good1.setpoint(_point1)){
        cout << "\n    --- Result is GOOD! ---" << endl;
        cout << t1;
    }
    else
        cout << " Invalid value for result." << endl;

    Test t2; Result_Bad res_bad2; Result_Good res_good2;
    _point2 = t2.answer();
    t2.setpoint(_point2);
    if (res_bad1.setpoint(_point2)){
        Consultation cons2;
        cout << "\n    --- Result is BAD! ---" << endl;
        cout << t2;
    }
    else if (res_good1.setpoint(_point2)){
        cout << "\n    --- Result is GOOD! ---" << endl;
        cout << t2;
    }
    else
        cout << " Invalid value for result." << endl;

/*
    cout << "    --- Comparing tests points --- " <<endl;
    if(t1<t2) {
        cout<<"    --- < ---   "<<endl;
    }
    else if(t1>t2)
        cout<<"    --- > ---    "<<endl;
    else if(t1==t2)  {
        cout<<"    --- The same --- "<<endl;
    }
    else cout<<"    --- Can't answer --- "<<endl;


    cout << "\n    --- Your summary points for tests this week --- " <<endl;
    t1+=t2;
    cout << t1;

    Help help;
    BreathingExercise breath;
    Meditation meditation;
    ASMR asmr;
    Article article;
    cout << "      | List of Categories | " << endl;
    cout << "    | 1 - Articles            | " << endl;
    cout << "    | 2 - ASMR recordings     | " << endl;
    cout << "    | 3 - Meditations         | " << endl;
    cout << "    | 4 - Breathing Exercises | " << endl;
    cout << "    | 0 - Exit                | " << endl;
    cout << "    --- Choose a practice (enter a number from 1 to 4) --- \n";
    int choice;
    while(true) {
        tryAgain:
        cin >> choice;
        if (choice == 0) {
            break;
        }
        switch (choice) {
            case 1:
                article.showHelp();
                break;
            case 2:
                asmr.showHelp();
                break;
            case 3:
                meditation.showHelp();
                break;
            case 4:
                breath.showHelp();
                break;
            default: {
                cout << "Invalid practice number!" << endl;
                goto tryAgain;
            }
        }
    }

    Help help_pr;
    int first, last;
    help_pr[0]="    *** Premium Article content ***\n";
    help_pr[1]="    *** Premium ASMR content ***\n";
    help_pr[2]="    *** Premium Meditations content ***\n";
    help_pr[3]="    *** Premium Breathing content ***\n";
    //cout<<help_pr;

    while (true) {
        cout << "\n    --- Choose a practice where to start Premium content (0 - to stop) ---\n ";
        cin >> first;
        if (first == 0) break;
        cout << "    --- Choose a practice where to end Premium content --- \n";
        cin >> last;
        if (first <= 0 || first > N || last <= 0 || last > N || first > last) {
            cout << "Invalid practice number!" << endl;
        } else {
            cout<<help_pr(first,last);
        }
    }

    cout << "\n    | Total consultation: " << Consultation::getConsulCount() <<" |\n"<< endl;

    Date one(31, 12, 2023);
    cout << "  Your old date 1:  " << one;
    one++;
    cout << "  Your new date 1:  " << one;
    cout << "  Your next date 1: " << ++one;
    cout<<""<<endl;
    Date two(12, 02, 2024);
    cout << "  Your old date 2:  " << two;
    two--;
    cout << "  Your new date 2:  " << two;
    cout << "  Your next date 2: " << --two;

    string newName = "Jane Smith";
    Specialist newSpecialist;
    newSpecialist = newName;
    cout << "\n    --- New Specialist with new name --- " << endl;
    newSpecialist.Info();
    string name = newSpecialist;
    cout << "    --- New Specialist's name: " << name <<"\n"<< endl;
*/

    User user3;
    cin>>user3;
    cout << "    --- Are you a specialist? (1 - yes, 0 - no) --- " << endl;
    cin >> _isSpecialist;
    if (_isSpecialist){
        Specialist specialist;
        cin>>specialist;
    }
    else{
        NonSpecialist nonSpecialist(_isSpecialist);
    }

    vector<User> user;
    user.push_back(user1);
    user.push_back(user1);
    user.push_back(user3);

    vector<User>::const_iterator it;
    for (it = user.begin(); it != user.end(); ++it) {
        cout << *it << " ";
    }

//    for (auto it = user.begin(); it != user.end(); ++it) {
//        cout << *it << " ";
//    }

// for (auto it = MAP_NAME.begin(); it != MAP_NAME.end(); ++it) {
//        cout << it->first << ": " << it->second <<endl;
//    }

//    int arr[] = {32, 71, 12, 45, 26, 80, 53, 33};
//    vector<int> myvector(arr, arr+7);
//    sort(myvector.begin(), myvector.end());
//    for (vector<int>::iterator i=myvector.begin(); i!=myvector.end(); ++i)
//        cout<<*i<<endl;


    double _point3 = 12.1;

    Statistic<int> intStat1;
    intStat1[0]=_point1;
    intStat1[1]=_point2;
    intStat1[2]=_point3;

    Statistic<double> doubleStat1(3);
    doubleStat1[0]=_point1;
    doubleStat1[1]=_point2;
    doubleStat1[2]=_point3;

    Statistic<char*> charStat1(3);
    charStat1[0] = "Mr.Smith";
    charStat1[1] = "Miss.Olsen";
    charStat1[2] = "Miss.Watson";

    cout << "\n    --- Your Statistic ---" << endl;
    cout <<" (int) | "<< intStat1 <<"|"<< endl;
    cout << "    | Max 1:     " <<intStat1.maxel()<<endl;
    cout << "    | Average 1: " <<intStat1.average()<<endl;
    cout<<"   ---"<<endl;
    cout <<" (double) | "<<doubleStat1<<"|"<<endl;
    cout << "    | Max 2:     " <<doubleStat1.maxel()<<endl;
    cout << "    | Average 2: " <<doubleStat1.average()<<endl;
    cout<<"   ---"<<endl;
    cout <<" (char*) | "<< charStat1<<"|"<<endl;

    cout << "\n    | Total consultation: " << Consultation::getConsulCount() <<" |"<< endl;

    cout << "\n    --- Our Content ---" << endl;

    multimap< int, string> conteiner;
    conteiner.insert(make_pair( 10, "Article 1"));
    conteiner.insert(make_pair(10, "Article 2"));
    conteiner.insert(make_pair(9, "Breathing Exercise 1"));
    conteiner.insert(make_pair(10, "Breathing 2 Exercise"));
    conteiner.insert(make_pair(5, "ASMR 1"));
    conteiner.insert(make_pair(5, "ASMR 2"));
    conteiner.insert(make_pair(4, "Meditation 1"));
    conteiner.insert(make_pair(8, "Meditation 2"));

    for (const auto& pair : conteiner) {
        cout<<"    | "<<pair.second<<" | Number of likes: "<<pair.first<<endl;
    }

    int likes;
    while (true) {
        cout<<"\n    --- Enter the number of likes you want to count ---"<<endl;
        cin>>likes;
        if (likes == 0) break;
        else
            cout<<"    --- The number of ratings "<<likes<<" occurred | "<<conteiner.count(likes)<<" | times in the multimap ---\n";
    }

    return 0;
}

