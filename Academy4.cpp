#include <iostream>
#include <string>

using namespace std;

// აბსტრაქტული ლექტორის კლასი 
class AbstratctLecturer {
    public:
        // აბსტრაქტული ატრიბუტები
        int Chapter = 1;
        int Level = 1;
        string Name;
        string Surname;
        string Subject;

        // ლექტორის კონსტრუქტორი, გადაეცემა 3 პარამეტრი
        AbstratctLecturer(string Name, string Surname, string Subject) {
            this-> Name = Name;
            this-> Surname = Surname;
            this-> Subject = Subject;
        };

        //დასწრება
        void abstractAttended(){
            cout << "ლექტორი ატარებს ლექციას" << endl;
        };
};

// აბსტრაქტული სტუდენტის კლასი 
class AbstractStudent {
    public:
        // აბსტრაქტული ატრიბუტები
        int CurseN = 1;
        int Degree = 0;
        int Points = 0; 
        string Name;
        string Surname;
        int Age;
        string Subject;
        string Section;

        // სტუდენტის კონსტრუქტორი, გადაეცემა 5 პარამეტრი
        AbstractStudent(string Name, string Surname, int Age, string Subject, string Section) {
            this-> Name = Name;
            this-> Surname = Surname;
            this-> Age = Age;
            this-> Subject = Subject;
            this-> Section = Section;
        };

        void abstractAttended(){
            cout << "სტუდენტი ესწრება ლექცას" << endl;
        };
};

// აბსტრაქტული საგნის კლასი
class AbstractSubject {
    public:
        string Sub;
        int Length;
        string StartingDate;

    // საგნის კონსტრუქტორი, გადაეცემა 3 პარამეტრი
        AbstractSubject(string Sub, int Length, string StartingDate) {
            this-> Sub = Sub;
            this-> Length = Length;
            this-> StartingDate = StartingDate;
        };
};

// სქილვილის საგანი
class SkillwillSubject: public AbstractSubject {
    public:
        // საგნისთვის დამახასიატებელი ატრიბუტები
        int lastChapter = 1;

        // ლექტორისთვის დამახასიათებელი ატრიბუტები
        SkillwillSubject(string Sub, int Length, string StartingDate): AbstractSubject(Sub, Length, StartingDate){};
    
    void printAll() {
            cout << "Subject: " << Sub << endl;
            cout << "Length: " << Length << endl;
            cout << "StartingDate: " << StartingDate << endl;
            cout << "lastChapter: " << lastChapter << endl;
            cout << endl;
        };
};   

// სქილვილის ლექტორი
class SkillwillLecturer: public AbstratctLecturer, public SkillwillSubject {
    public:
        // ლექტორის კონსტრუქტორი, გადაეცემა 3 პარამეტრი
        SkillwillLecturer(string Name, string Surname, string Subject): AbstratctLecturer( Name, Surname, Subject){};
    
    void printAll() {
            cout << "Name: " << Name << endl;
            cout << "Surname: " << Surname << endl;
            cout << "Subject: " << Subject << endl;
            cout << "Chapter: " << Chapter << endl;
            cout << "Level: " << Level << endl;
            cout << endl;
        };
    void lectureIsInProgress(){
        cout << Sub << " ასწავლის "<< Name << " "<< Surname << StartingDate << "-დან" << endl;

    };
};

// სქილვილის სტუდენტი
class SkillwillStudent: public AbstractStudent {
    public:
        // სტუდენტისთვის კონსტრუქტორი, გადაეცემა 5 პარამეტრი
        SkillwillStudent(string Name, string Surname, int Age, string Subject, string Section): AbstractStudent(Name, Surname, Age, Subject, Section){};

    // მეთოდი, რომელსაც გამოაქვს სტუდენტის ყველა მონაცემი
    void printAll() {
            cout << "Name: " << Name << endl;
            cout << "Surname: " << Surname << endl;
            cout << "Age: " << Age << endl;
            cout << "Subject: " << Subject << endl;
            cout << "Section: " << Section << endl;
            cout << "CurseN: " << CurseN << endl;
            cout << "Degree: " << Degree << endl;
            cout << "Points: " << Points << endl;
            cout << endl;
        };
    
    //დასწრება
    void Attended(){
        cout << Name << " " << Surname << " " << "დაესწრო" << " " << Subject << "-ის" << " " << "ლექციას" << endl;
    };

    void updateQuizPoint(int newQuizPoints){
        Points += newQuizPoints;
        cout << "ქვიზში " << Name << " " << Surname << " აიღო " << newQuizPoints <<  " ქულა" << endl;
        cout << "სტუდენტის ჯამური ქულაა: " << Points << endl;
    };
};


int main()
{
    SkillwillStudent student1("BaCho", "Sulava", 35, "Python", "a");
    
    SkillwillSubject subject1("C++", 7, "01.02.2023");

    SkillwillLecturer lecturer1("BaCho", "Sulava", "Python");
    lecturer1.lectureIsInProgress();

    

    return 0;
}