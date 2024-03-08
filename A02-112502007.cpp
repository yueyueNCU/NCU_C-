/*
Assignment 02
Name: 張新約
Student Number: 112502007
Course 2023-CE1002-資工一A
*/
#include<bits/stdc++.h>
using namespace std;
class Course{
    friend class Student;
    public:
        Course(string courseName,string time){
            (*this).courseName=courseName;
            (*this).time=time;
        }
        string getCourseName()const{
            return (*this).courseName;
        }
        string getTime()const{
            return (*this).time;
        }
        void setCourseName(string courseName){
            (*this).courseName=courseName;
        }
        void setwhichTime(string time){
            (*this).time=time;
        }
    private:
        string courseName;
        string time;
};
class Student{
    public:
        static bool comp(Course a,Course b){
            return a.getCourseName() < b.getCourseName();
        }
        Student(string name){
            (*this).name=name;
        }
        void addCourse(const Course& course){
            vec.push_back(course);
        }
        void Checkconflicts(){
            cout<<(*this).name<<"'s Conflicts:\n";
            map<string,vector<string>>ma;
            bool find=false;
            for(Course course:vec){
                ma[course.time].push_back(course.courseName);
            }
            for(auto const& [key,val]:ma){
                if((val).size()>1){
                    for(long unsigned int i=0;i<(val).size();i++){
                        cout<<"-"<<(val)[i]<<"\n";
                    }
                    find=true;
                }
            }
            if(!find){
                cout<<"none\n";
            }
        }
        void ListCourse(){
            cout<<(*this).name<<"'s Courses:\n";
            sort(vec.begin(),vec.end(),comp);
            for(Course course:vec){
                cout<<"-"<<course.courseName<<"\n";
            }
        }
        string getName(){
            return (*this).name;
        }
    private:
        string name;
        vector<Course> vec;
};
Student* find_stu(vector<Student>& Stud_v,string studentName){
    for(long unsigned int i=0;i<Stud_v.size();i++){
                if(Stud_v[i].getName()==studentName){
                    return &(Stud_v[i]);
                }
            }
    return NULL;
}
int main(){
    int num;
    string command;
    string studentName;
    vector<Course>Cour_v;
    vector<Student>Stud_v;
    cin>>num;
    for(int i=0;i<num;i++){
        string name,time;
        cin>>name>>time;
        Cour_v.push_back(Course(name,time));
    }
    while(cin>>command){
        if(command=="EnrollStudent"){
            int c_n;
            cin>>c_n>>studentName;
            Student student(studentName);
            for(int i=0;i<c_n;i++){
                string courseName;
                cin>>courseName;
                for(long unsigned int j=0;j<Cour_v.size();j++){
                    if(Cour_v[j].getCourseName()==courseName){
                        student.addCourse(Cour_v[j]);
                        break;
                    }
                }
            }
            Stud_v.push_back(student);
            cout<<studentName<<" Enroll Success.\n";
        }else if(command=="ListCourses"){
            cin>>studentName;
            Student *s=find_stu(Stud_v,studentName);
            if((s)==NULL){
                cout<<"Has no "<<studentName<<".\n";
            }else{
                (*s).ListCourse();
            }
        }else if(command=="CheckConflicts"){
            cin>>studentName;
            Student *s=find_stu(Stud_v,studentName);
            if((s)==NULL){
                cout<<"Has no "<<studentName<<".\n";
            }else{
                (*s).Checkconflicts();
            }
        }else if(command=="END"){
            break;
        }
    }
}