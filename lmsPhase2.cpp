#include <iostream>
#include <cstring>
#include <conio.h>
#include <iomanip>
#include <fstream>
using namespace std;
bool isValidCourseCode(string str);
bool isValidCourseName(string str);
bool isValidCreditHours(int integer);
bool isValidSemester(int value);
void AddCourse(string validcode, string validcourse, int validcredits, int validsemester, string name[], string course[], int credits[], int semester1[], int size);
void EditCourse(string validcode, string validcourse, int validcredits, int validsemester, string name[], string course[], int credits[], int semester1[], int size);
void DeleteCourse(string validcode, string validcourse, int validcredits, int validsemester, string name[], string course[], int credits[], int semester1[], int size);
void ViewCourses(string validcode, string validcourse, int validcredits, int validsemester, string name[], string course[], int credits[], int semester1[], int size);
void ViewSemesterCourses(string validcode, string validcourse, int validcredits, int validsemester, string name[], string course[], int credits[], int semester1[], int size);
bool saveCourses(string name[], string course[], int credits[], int semester1[], int size);
bool loadCourses(string name[], string course[], int credits[], int semester1[], int size);
bool loadUsers(string users1[], string passwords1[], int size);
int main()
{
    string users[5] = {"", "", "", "", ""};
    string passwords[5] = {"", "", "", "", ""};
    string name[5] = {"", "", "", "", ""};
    string course[5] = {"", "", "", "", ""};
    int credits[5] = {0, 0, 0, 0, 0};
    int semester1[5] = {0, 0, 0, 0, 0};
    char input;
    string courseCode;
    string CourseName;
    int CreditHours;
    int Semester;
    bool flag;
    bool ifValidCourseCode;
    bool credit;
    bool semester;
    bool savecourses;
    bool loadcourse;
    string usernames;
    string passwordsname;
    bool authorization;
    do
    {
        cin.ignore(2, '\n');
        authorization = loadUsers(users, passwords, 5);
        cout << "**  Welcome to University Learning Management System **" << endl;
        cout << "Dear User, current software is intended for authorized users only." << endl;
        cout << "Login to the system to get access. \n"
             << endl;
        cout << "Username:";
        getline(cin, usernames);
        cout << "Password:";
        getline(cin, passwordsname);
        for (int i = 0; i < 5; i++)
        {
            if (usernames == users[i] && passwordsname == passwords[i])
            {
                loadcourse = loadCourses(name, course, credits, semester1, 5);
                if (loadcourse == true)
                {
                    cout << "Previously Data Loaded..." << endl;
                }
                cout << "Choose the following option" << endl;
                do
                {
                    cout << "1 Add Course" << endl;
                    cout << "2 Update Course" << endl;
                    cout << "3 Delete Course" << endl;
                    cout << "4 View All Courses" << endl;
                    cout << "5 View Courses of a Semester" << endl;
                    cout << "6 Logout of the system\n";
                    cout << "7 Exit Program" << endl;
                    cout << "" << endl;
                    cout << "Choose the option:";
                    cin >> input;
                    switch (input)
                    {
                    case '1':
                        cout << "               ... Add a Course .." << endl;
                        cout << "Enter CourseCode:";
                        cin.ignore(2, '\n');
                        getline(cin, courseCode);
                        cout << "Enter CourseName:";
                        getline(cin, CourseName);
                        cout << "Enter CreditHours:";
                        cin >> CreditHours;
                        cout << "Enter Semester:";
                        cin >> Semester;
                        flag = isValidCourseName(CourseName);
                        ifValidCourseCode = isValidCourseCode(courseCode);
                        credit = isValidCreditHours(CreditHours);
                        semester = isValidSemester(Semester);
                        if (flag == true && ifValidCourseCode == true && credit == true && semester == true)
                        {
                            AddCourse(courseCode, CourseName, CreditHours, Semester, name, course, credits, semester1, 5);
                        }
                        break;
                    case '2':
                        cout << "               ... Edit the Course .." << endl;
                        cout << "Enter the courseCode:";
                        cin.ignore(2, '\n');
                        getline(cin, courseCode);
                        EditCourse(courseCode, CourseName, CreditHours, Semester, name, course, credits, semester1, 5);
                        break;
                    case '3':
                        cout << "               ... Delete the Course .." << endl;
                        cout << "Enter the courseCode:";
                        cin.ignore(2, '\n');
                        getline(cin, courseCode);
                        DeleteCourse(courseCode, CourseName, CreditHours, Semester, name, course, credits, semester1, 5);
                        break;
                    case '4':
                        cout << "               ... View all Course .." << endl;
                        ViewCourses(courseCode, CourseName, CreditHours, Semester, name, course, credits, semester1, 5);
                        break;
                    case '5':
                        cout << "               ... View Semesters .." << endl;
                        //semester
                        cout << "Enter Semester:";
                        cin >> Semester;
                        ViewSemesterCourses(courseCode, CourseName, CreditHours, Semester, name, course, credits, semester1, 5);
                        break;
                    case '6':
                        cout << "Logout Successfully!\n";
                        break;
                    case '7':
                        savecourses = saveCourses(name, course, credits, semester1, 5);
                        if (savecourses == true)
                        {
                            cout << "Data Saved..." << endl;
                        }
                        else
                            cout << "No Data Is Added.." << endl;
                            cout << "Program Closed Successfully!." << endl;
                        return 0;
                    default:
                        cout << "Invalid Choice:" << endl;
                        break;
                    }

                } 
            
        
                while (input != '6');
        }
    else
    {
        cout<<"You have entered Wrong credientials.\n";
        cout<<"Press any key to try again\n";
        getch();
        break;
    }
    
        }
            
        }
     
    while (input != '7');
    return 0;
}
bool isValidCourseCode(string str)
{
    bool flag;
    int z = str.length();
    if (z == 5)
    {
        if ((str[0] <= 'Z' && str[0] >= 'A') && ((str[1] <= 'Z' && str[1] >= 'A')))
        {
            if ((str[2] <= '9' && str[2] >= '0') && ((str[3] <= '9' && str[3] >= '0')) && ((str[4] <= '9' && str[4] >= '0')))
            {
                flag = true;
            }
        }
    }
    else
    {
        flag = false;
    }
    return flag;
}
bool isValidCourseName(string str)
{
    int z = str.length();
    bool flag;
    if (z <= 50)
    {
        for (int i = 0; i < z; i++)
        {
            if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= ' '))
            {
                flag = true;
            }
            else
            {
                flag = false;
                break;
            }
        }
    }
    else
    {
        flag = false;
    }

    return flag;
}
bool isValidCreditHours(int integer)
{
    int z = sizeof(integer);
    bool flag;
    if (integer >= 1 && integer <= 3)
    {
        flag = true;
    }
    else
    {
        flag = false;
    }
    return flag;
}
//semester
bool isValidSemester(int value)
{
    bool flag;
    if (value >= 1 && value <= 8)
    {
        flag = true;
    }
    else
    {
        flag = false;
    }
    return flag;
}
void AddCourse(string validcode, string validcourse, int validcredits, int validsemester, string name[], string course[], int credits[], int semester1[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (name[i] == "")
        {
            name[i] = validcode;
            course[i] = validcourse;
            credits[i] = validcredits;
            semester1[i] = validsemester;
            break;
        }
    }
    cout << "Course Added Successfully!!!" << endl;
}
void EditCourse(string validcode, string validcourse, int validcredits, int validsemester, string name[], string course[], int credits[], int semester1[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (validcode == name[i])
        {
            cout << "Enter CourseCode:";
            getline(cin, validcode);
            cout << "Enter CourseName:";
            getline(cin, validcourse);
            cout << "Enter CreditHours:";
            cin >> validcredits;
            cout << "Enter Semester:";
            cin >> validsemester;
            name[i] = validcode;
            course[i] = validcourse;
            credits[i] = validcredits;
            semester1[i] = validsemester;
            break;
        }
    }
    cout << "Course updated Successfully!!!" << endl;
}
void DeleteCourse(string validcode, string validcourse, int validcredits, int validsemester, string name[], string course[], int credits[], int semester1[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (validcode == name[i])
        {
            name[i] = "";
            course[i] = "";
            credits[i] = 0;
            semester1[i] = 0;
            break;
        }
    }
    cout << "Course deleted Successfully!!!" << endl;
}
void ViewCourses(string validcode, string validcourse, int validcredits, int validsemester, string name[], string course[], int credits[], int semester1[], int size)
{
    cout << setw(25) << left << "CourseCode" << setw(35) << left << "Name" << setw(25) << left << "CreditHours" << setw(15) << left << "Semester" << endl;
    for (int i = 0; i < size; i++)
    {
        if (name[i] != "")
        {
            cout << setw(25) << left << name[i] << setw(35) << left << course[i] << setw(25) << left << credits[i] << setw(15) << left << semester1[i] << endl;
        }
    }
    getch();
}
void ViewSemesterCourses(string validcode, string validcourse, int validcredits, int validsemester, string name[], string course[], int credits[], int semester1[], int size)
{
    cout << setw(25) << left << "CourseCode" << setw(35) << left << "Name" << setw(25) << left << "CreditHours" << endl;
    for (int i = 0; i < size; i++)
    {
        if (semester1[i] == validsemester)
        {
            cout << setw(25) << left << name[i] << setw(35) << left << course[i] << setw(25) << left << credits[i] << endl;
        }
    }
    getch();
}
bool saveCourses(string name[], string course[], int credits[], int semester1[], int size)
{
    bool flag = false;
    ofstream saveC;
    saveC.open("Courses.txt");
    for (int i = 0; i < size; i++)
    {
        if (name[i] != "")
        {
            saveC << name[i] << endl;
            saveC << course[i] << endl;
            saveC << credits[i] << endl;
            saveC << semester1[i] << endl;
            flag = true;
        }
    }
    saveC.close();
    return flag;
}
bool loadCourses(string name[], string course[], int credits[], int semester1[], int size)
{
    bool flag = false;
    ifstream loadC;
    loadC.open("Courses.txt");
    for (int i = 0; i < size; i++)
    {
        if (name[i] == "")
        {
            loadC >> name[i];
            loadC >> course[i];
            loadC >> credits[i];
            loadC >> semester1[i];
            flag = true;
        }
    }
    loadC.close();
    return flag;
}
bool loadUsers(string users1[], string passwords1[], int size)
{
    bool flag = false;
    ifstream loadU;
    loadU.open("Users.txt");
    for (int i = 0; i < size; i++)
    {
        if (users1[i] == "")
        {
            getline(loadU, users1[i]);
            getline(loadU, passwords1[i]);
            flag = true;
        }
    }
    loadU.close();
    return flag;
}
