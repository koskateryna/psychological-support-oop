#ifndef UNTITLED6_LAB_OOP_H
#define UNTITLED6_LAB_OOP_H
#endif //UNTITLED6_LAB_OOP_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <map>
#include <algorithm>
#define n 10
#define N 4

using namespace std;

class User {
private:
    string name;
    int age;
    string gender;
    string phone;
    string email;
    string password;
    bool isSpecialist;
public:
    User();
    User(bool _isSpecialist);
//    User(string a);
    User(string& name, int age, string& gender, string& phone,  string& email,string& password);
    User(const User& other);
    ~User();
    string getName() const;
    int getAge() const;
    string getGender() const;
    string getPhone() const;
    string getEmail() const;
    string getPassword() const;
    bool getIsSpecialist() const;
    User& setName(string& newName);
    User& setAge(int newAge);
    User& setGender(string& newGender);
    User& setPhone(string& newPhone);
    User& setEmail(string& newEmail);
    User& setPassword(string& newPassword);
    /////////////////// 3 /////////////////////
    bool operator==(const User& other) const;
    bool operator!=(const User& other) const;
    friend istream & operator >> (istream& is, User&c);
    friend ostream & operator << (ostream& os, const User&c);
    const User & operator = (const User&c);
};

class NonSpecialist : public User {
public:
    NonSpecialist();
    NonSpecialist(string& name, int age,  string& gender, string& phone,  string& email, string& password);
    NonSpecialist(const NonSpecialist& other);
    NonSpecialist(bool _isSpecialist);
    ~NonSpecialist();
};

class Specialist : public User {
    string degree;
public:
    Specialist();
    Specialist(string& name, int age, string& gender, string& phone, string& email, string& password, string& newdegree);
    Specialist(bool _isSpecialist, string& _degree);
    Specialist(const Specialist& spec);
    ~Specialist();
    string GetDegree() const;
    Specialist& SetDegree(string& deg);
    Specialist& setname(User&);
    string AddArtical() const;
    string ChangeArtical(string& artical) const;
    void Info() const;
    void ShortInfo() const;
    void DeleteArtical(string& artical) const;
    ////////////////////////////////////////////
    friend istream & operator >> (istream& is, Specialist&c);
    friend ostream & operator << (ostream& os, const Specialist&c);
    Specialist(string a);
    operator string();
};

class Date {
public:
    int day, month, year;
    Date();
    Date(int d, int m, int y);
    Date(const Date &date);
    ~Date();
    int GetDay() const;
    int GetMonth() const;
    int GetYear() const;
    Date &SetDay(int d);
    Date &SetMonth(int m);
    Date &SetYear(int y);
    void Info() const;
    Date&Change(int newd, int newm, int newy);
    ///////////////////////////////////////////
    friend ostream& operator << (ostream& os, const Date& c);
    Date& operator ++();
    Date operator ++(int);
    Date& operator --();
    Date operator --(int);
};

class Consultation {
    Specialist specialist;
    Date date;
    static int consulCount;
public:
    Consultation();
    Consultation(Specialist spec, Date dat);
    Consultation(const Consultation &consultation);
    ~Consultation();
    Specialist GetSpec();
    Date GetDate() const;
    Consultation &SetSpecialist(Specialist spec);
    Consultation &SetDate(Date dat);
    void Info() const;
    void displayMenu() const;
    ////////////////////////////////////////
    static int getConsulCount();
};


class Test{
    static string question[n];
protected:
    float point;
public:
    Test();
    ~Test();
    Test(float _point);
    Test(const Test&a);
    float getpoint() const;
    static string getquestion();
    string getname();
    Test& setpoint(float _point);
    Test& setname(float _name[], int size);
    float answer();
////////////////////////////////////////
    friend ostream & operator << (ostream& os, const Test&c);
    const Test& operator = (const Test&); //не буде плутанини з == //може бути перевантаж тільки функцією-членом класу
    bool operator == (const Test&) const;
    bool operator > (const Test&) const;
    bool operator < (const Test&) const;
    bool operator != (const Test&) const;
    Test& operator += (const Test&);
};

class Result_Good: public Test{
public:
    Result_Good();
    ~Result_Good();
    Result_Good(const Result_Good&a);
    Result_Good(float _point);
    bool setpoint(float _point);
    void suggest_help() const;
};

class Result_Bad: public Test{
public:
    Result_Bad();
    ~Result_Bad();
    Result_Bad(const Result_Bad&a);
    Result_Bad(float _point);
    bool setpoint(float _point);
    void suggest_help() const;
    void suggest_specialist() const;
};

class Help {
protected:
    string title;
    string content;
    string premium;
    string name;
    string premium_content[N];
public:
    Help();
    Help(const Help& other);
    Help(string& title, string& content, string& premium,  string& name);
    virtual ~Help();
    virtual void showHelp() const;
    string getTitle() const;
    string getContent() const;
    string getPremium() const;
    string getName() const;
    Help& setTitle( string& newTitle);
    Help& setContent( string& newContent);
    Help& setPremium( string& newPremium);
    Help& setName( string& newName);

    string & operator[](const int index);
    string operator()(int fist, int last);
    friend ostream & operator << (ostream& os, const Help&c);
};

class Meditation : public Help {
public:
    float time;
    Meditation();
    Meditation(const Meditation& other);
    Meditation( string& title, string& content, string& premium,  string& name, float time);
    void showHelp() const;
    ~Meditation();
    float getTime() const;
    Meditation& setTime(float newTime);
};

class ASMR : public Help {
public:
    float time;
    ASMR();
    ASMR(const ASMR& other);
    ASMR(string& title, string& content, string& premium, string& name, float time);
    void showHelp() const;
    ~ASMR();
    float getTime() const;
    ASMR& setTime(float newTime);
//    bool operator < (const ASMR&) const; //для map
};

class BreathingExercise : public Help {
public:
    float time;
    BreathingExercise();
    BreathingExercise(const BreathingExercise& other) ;
    BreathingExercise( string& title, string& content, string& premium,  string& name, float time);
    void showHelp() const;
    ~BreathingExercise();
    float getTime() const ;
    BreathingExercise& setTime(float newTime);
};

class Article : public Help {
public:
    float time;
    Article();
    Article(const Article& other);
    Article(string& title, string& content, string& premium, string& name, float time);
    void showHelp() const;
    ~Article();
    float getTime() const;
    Article& setTime(float newTime);
//    bool operator < (const Article&) const; //для map
};