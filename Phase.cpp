#include<iostream>
#include<cstring>
using namespace std;
bool isValidCourseCode(string str);
bool isValidCourseName(string str);
bool isValidCreditHours(int integer);
bool isValidSemester(int value);
void AddCourse(string validcode,string validcourse,int validcredits,int validsemester);
int main()
{
  
    //course code
  string courseCode;
  cout<<"Enter CouseCode:";
  getline(cin,courseCode);
  bool ifValidCourseCode=isValidCourseCode(courseCode);
  if(ifValidCourseCode==true)
   {
        cout<<"Course is valid:"<<endl;
   }
    else
    {
     cout<<"Course is invalid:"<<endl;
    }
    //coursename

    string CourseName;
    cout<<"Enter Course Name :";
    getline(cin,CourseName);
    bool flag=isValidCourseName(CourseName);
    if(flag==true)
   {
        cout<<"CourseName is valid:"<<endl;
   }
    else
    {
     cout<<"CourseName is invalid:"<<endl;
    }
    //credits
    int CreditHours;
    cout<<"Enter CreditHours:";
    cin>>CreditHours;
    bool credit=isValidCreditHours(CreditHours);
    if(credit==true)
   {
        cout<<"CreditHours are valid:"<<endl;
   }
    else
    {
     cout<<"CreditHours are invalid:"<<endl;
    }
    //semester
    int Semester;
    cout<<"Enter Semester :";
    cin>>Semester;
    bool semester=isValidSemester(Semester);
    if(semester==true)
   {
        cout<<"Semster Number  is valid:"<<endl;
   }
    else
    {
     cout<<"Semster Number  is invalid:"<<endl;
    }
 return 0; 
}
//functions
//course code;
bool isValidCourseCode(string str)
{
    bool flag;
    int b=str.length();
    if(b==5)
    {
        if((str[0]<='Z'&&str[0]>='A')&&( (str[1]<='Z'&&str[1]>='A')))
        {
            if((str[2]<='9'&&str[2]>='0')&&( (str[3]<='9'&&str[3]>='0'))&&( (str[4]<='9'&&str[4]>='0')))
            {
             flag=true;
            }
        }
    }
    else
    {
        flag=false;
    }
    return flag;
}
//coursename
bool isValidCourseName(string str)
{
    int b=str.length();
    bool flag;
    if(b<=50)
    {
        for(int i=0;i<b;i++)
        {
    if((str[i]>='A'&&str[i]<='Z')||(str[i]>='a'&&str[i]<='z')||(str[i]>=' '))
    {
        flag=true;
    }
    else
    {
      flag=false;
      break;
    }
        }
    }
    else
    {
        flag=false;
    }
    
    return flag;
}
//credits
bool isValidCreditHours(int integer)
{
    int b=sizeof(integer);
    bool flag;
    if(integer>=1&&integer<=3)
    {
        flag=true;
    }
    else
    {
      flag=false;
    }
    return flag;
}
//semester
bool isValidSemester(int value)
{
    bool flag;
    if(value>=1&&value<=8)
    {
        flag=true;
    }
    else
    {
      flag=false;
    }
    return flag;
}