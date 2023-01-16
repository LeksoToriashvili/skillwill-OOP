/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;


// class Subject

class Abstracsubject{
    protected:
        string SubjectName;
        int CourceDuration;
        string StartDate;
    public:
        Abstracsubject(string SubjectName, int CourceDuration, string StartDate) {
            this-> SubjectName = SubjectName;
            this-> CourceDuration = CourceDuration;
            this-> StartDate = StartDate;
        }
        
        string getSubjectName() {
            return SubjectName;
        }
        
        int getCourceDuration() {
            return CourceDuration;
        }
        
        string getStartDate() {
            return StartDate;
        }
        
        void setSubjectName(string SubjectName) {
            this-> SubjectName = SubjectName;
        }
        
        void setCourceDuration(int CourceDuration) {
            this-> CourceDuration = CourceDuration;
        }
        
        void setStartDate(string StartDate) {
            this-> StartDate = StartDate;
        }
};

class SkillWillSubject: public Abstracsubject {
    public:
        SkillWillSubject(string SubjectName, int CourceDuration, string StartDate): Abstracsubject(SubjectName, CourceDuration, StartDate) {};
        
};

// class lecturer,

class AbstractLecturer {
    protected:
        string FirstName;
        string LastName;
        string SubjectName;
    public:
        AbstractLecturer(string FirstName, string LastName, string SubjectName) {
            this-> FirstName = FirstName;
            this-> LastName = LastName;
            this-> SubjectName = SubjectName;
        };
        
        string getFirstName() {
            return FirstName;
        }
        
        string getLastName() {
            return LastName;
        }
        
        string getSubjectName() {
            return SubjectName;
        }
        
        void setFirstName(string FirstName) {
           this-> FirstName = FirstName;
        }
        
        void setLastName(string Lastname) {
           this-> LastName = Lastname;
        }
        
        void setSubjectName(string SubjectName) {
           this-> SubjectName = SubjectName;
        }
        
        void conduqtingLecturer() {
            cout << " The lecturer conducts a lecture"<< endl;
        }
};

class SkillWillLecturer: public AbstractLecturer {
    public:
        string Chapter;
        string Level;
    
        SkillWillLecturer(string FirstName, string LastName, string SubjectName): AbstractLecturer(FirstName, LastName, SubjectName) {};
        
         void lecturerSkill(string Chapter, string Level) {
            this-> Chapter = Chapter;
            this-> Level = Level;
            cout << " Lecturer chapter is : " << Chapter << endl;
            cout << " Lecturer level is : " << Level << endl;
            cout << endl;
        }
        
        void lecturerInfo () {
            cout << " Lecturer first name is : " << FirstName << endl;
            cout << " Lecturer last name is : " << LastName << endl;
            cout << " Subject name is : " << SubjectName << endl;
            cout << endl;
        }
        
        void conduqtingLecturer(SkillWillSubject subject) {
            cout << " The direction of the lecture is " << subject.getSubjectName() << " and the start date is " << subject.getStartDate() << endl;
            lecturerInfo();
        }
};
// class student

class AbstractStudent {
    protected:
        string FirstName;
        string LastName;
        int Age;
        string Subject;
    public:
        AbstractStudent(string FirstName, string LastName, int Age, string Subject) {
            this-> FirstName = FirstName;
            this-> LastName = LastName;
            this-> Age = Age;
            this-> Subject = Subject;
        };
        
        string getFirstName() {
            return FirstName;
        }
        
        string getLastName() {
            return LastName;
        }
        
        int getAge() {
            return Age;
        }
        
        string getSubject() {
            return Subject;
        }
        
        void setFirstName(string FirstName) {
           this-> FirstName = FirstName;
        }
        
        void setLastName(string Lastname) {
           this-> LastName = Lastname;
        }
        
        void setAge(int Age) {
           this-> Age = Age;
        }
        
        void setSubject(string Subject) {
           this-> Subject = Subject;
        }
        
        void attendLecture() {
            cout << " The student attends the lecture" << endl;
        }
        
        void updateQuiz() {
            
        }
};

class SkillWillStudent: public AbstractStudent {
    public:
        char Section;
        int NumberOfCourse;
        int QuizScore;
        
        SkillWillStudent(string FirstName, string LastName, int Age, string Subject): AbstractStudent(FirstName, LastName, Age, Subject) {};
    
        void studentSkill(char Section, int NumberOfCourse, int QuizScore) {
            this-> Section = Section;
            this-> NumberOfCourse = NumberOfCourse;
            this-> QuizScore = QuizScore;
            cout << " The student section is : " << Section << endl;
            cout << " The student's course of study is : " << NumberOfCourse  << " month" << endl;
            cout << " The student's monthly quiz score is : " << QuizScore << endl;
            cout << endl;
        }
         
        void studentInfo() {
            cout << " Student first name is : " << FirstName << endl;
            cout << " Student last name is : " << LastName << endl;
            cout << " Student age is : " << Age << endl;
            cout << " Subject name is : " << Subject << endl;
            cout << endl;
        }
        
         void attendLecture(SkillWillSubject subject) {
            cout << " " << FirstName << " " << LastName << " attended " << subject.getSubjectName() << " lecture" << endl;
        }
        
        void updateQuiz(int newScore) {
            QuizScore += newScore;
            cout << " The final result of " << FirstName << " " << LastName << " quiz is : " << QuizScore << endl;
            cout << endl;
            
        }
};


int main()
{
    SkillWillSubject skillWillSubject("Web's", 7, "16.11.22");

    SkillWillStudent skillWillStudent("Levan", "mermanishvili", 33, "CPP");

    skillWillStudent.studentInfo();
    skillWillStudent.studentSkill('b', 7, 70);
    skillWillStudent.updateQuiz(60);
    skillWillStudent.updateQuiz(30);
    skillWillStudent.updateQuiz(200);

    

    SkillWillLecturer skillWillLecturer("Lika", "Sikharulia", "PHP");

    skillWillLecturer.lecturerInfo();


    skillWillLecturer.lecturerSkill("php", "Senior");

    skillWillLecturer.conduqtingLecturer(skillWillSubject);

    skillWillStudent.attendLecture(skillWillSubject);

    return 0;  
}

