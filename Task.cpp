#include <iostream>
#include <iomanip>
#include <cstring>
#include <conio.h>
using namespace std;
bool isvalidcoursecode(string cs)
{
    int csl;
    csl = cs.length();
    bool flag = true;
    int i;
    if (csl == 5)
    {
        for (i = 0; i < 2; i++)
        {
            if (!(cs[i] >= 'A' && cs[i] <= 'z'))
            {
                flag = false;
            }
            if (flag == false)
            {
                cout << "You have entered invalid input in first two character " << endl;
            }
            for (i = 2; i < 5; i++)
            {
                if (!(cs[i] >= '0' && cs[i] <= '9'))
                {
                    flag = false;
                }
            }
            if (flag == false)
            {
                cout << "You have entered invalid input in last three characters " << endl;
            }
        }
    }
    else
    {
        cout << "The Length of coursecode is inappropriate. " << endl;
    }

    return flag;
}
bool isvalidcoursename(string cn)
{
    int cnl;
    cnl = cn.length();
    bool flag;
    flag = true;
    if (cnl < 50)
    {
        for (int i = 0; i < cnl; i++)
        {
            if (!((cn[i] >= 'A' && cn[i] <= 'z') || cn[i] == ' '))
            {
                flag = false;
            }
            if (flag == false)
            {
                cout << "You have entered invalid intiger or symbol " << endl;
            }
        }
    }
    else
    {
        cout << "You have exceeded the limit of 50 characters " << endl;
    }
    return flag;
}
int main()
{
    int input, i, csl, credithour[5], semester[5], cnl, updatesemester, updatecredithour, usersemester;
    string coursecode[5], cs, coursename[5], cn, usercoursecode, updatecoursecode, updatecoursename;
    cs = "null";
    bool checkcoursecode, checkcoursename, findcoursecode, checkupdatecoursecode, checkupdatecoursename, findsemester;
    findcoursecode = true;
    for (i = 0; i < 5; i++)
    {
        semester[i] = 0;
    }
    for (i = 0; i < 5; i++)
    {
        credithour[i] = 0;
    }
    do
    {
        cout << "** Welcome to University Learning Management System **" << endl;
        cout << "Choose the following option" << endl;
        cout << "1 \t Add course" << endl;
        cout << "2 \t Update course" << endl;
        cout << "3 \t Delete course" << endl;
        cout << "4 \t View all courses" << endl;
        cout << "5 \t View courses of Semester" << endl;
        cout << "0 \t Exit" << endl;
        cout << "\n Choose the option: ";
        cin >> input;
        switch (input)
        {
        case 1:
        {
            system("CLS");
            for (int i = 0; i < 5; i++)
            {
                coursecode[i] = "null";
            }
            cout << "Enter the details of the course : ";

            for (i = 0; i < 5; i++)
            {
                if (coursecode[i] == "null")
                {
                    cin >> coursecode[i];
                    cs = coursecode[i];
                    checkcoursecode = isvalidcoursecode(cs);
                    if (checkcoursecode == false)
                    {
                        cout << " **Invalid course code** " << endl;
                    }

                    cin >> credithour[i];
                    if (credithour[i] == 0 || credithour[i] > 3)
                    {
                        cout << " **Invalid credithour** " << endl;
                    }
                    cin >> semester[i];

                    cin.ignore(50, '\n');
                    getline(cin, coursename[i]);
                    cn = coursename[i];
                    checkcoursename = isvalidcoursename(cn);
                    if (checkcoursename == false)
                    {
                        cout << " **Invalid course name** " << endl;
                        cout << endl;
                    }
                    cout << "Course has been added successfully! " << endl;
                    break;
                }
            }
            system("CLS");
            break;
        }
        case 2:
        {
            system("CLS");
            cout << "Enter the coursecode to update : ";
            cin >> usercoursecode;
            for (i = 0; i < 5; i++)
            {
                if (usercoursecode == coursecode[i])
                {
                    cout << "Enter the new coursecode : ";
                    cin >> updatecoursecode;
                    cs = updatecoursecode;
                    checkupdatecoursecode = isvalidcoursecode(cs);
                    if (checkcoursecode == false)
                    {
                        cout << " **Invalid course code** " << endl;
                    }
                    coursecode[i] = updatecoursecode;

                    cin >> updatecredithour;
                    if (updatecredithour == 0 || updatecredithour > 3)
                    {
                        cout << " **Invalid credithour** " << endl;
                    }
                    credithour[i] = updatecredithour;

                    cin >> updatesemester;
                    semester[i] = updatesemester;

                    cin.ignore(50, '\n');
                    getline(cin, updatecoursename);
                    cn = updatecoursename;
                    checkupdatecoursename = isvalidcoursename(cn);
                    if (checkcoursename == false)
                    {
                        cout << " **Invalid course name** " << endl;
                        cout << endl;
                    }
                    coursename[i] = updatecoursename;
                    cout << "Course has been changed successfully! " << endl;
                    cout << endl;
                    findcoursecode = true;
                    break;
                }
                else
                {
                    findcoursecode = false;
                }
            }
            if (findcoursecode == false)
            {
                cout << " **No coursecode found** " << endl;
            }
            break;
            system("CLS");
        }
        case 3:
        {
            system("CLS");
            cout << "Enter the course to delete : ";
            cin >> usercoursecode;
            for (i = 0; i < 5; i++)
            {
                if (usercoursecode == coursecode[i])
                {
                    coursecode[i] = "null";
                    credithour[i] = 0;
                    semester[i] = 0;
                    coursename[i] = "null";
                    findcoursecode = true;
                    break;
                }
                else
                {
                    findcoursecode = false;
                }
            }
            if (findcoursecode == false)
            {
                cout << " **No coursecode found** " << endl;
            }
            else
            {
                cout << "Course has been deleted successfully" << endl;
            }

            break;
            system("CLS");
        }
        case 4:
        {
            system("CLS");
            for (i = 0; i < 5; i++)
            {
                if (coursecode[i] != "null")
                {
                    cout << setw(15) << " Course code " << left << setw(50) << " \t \t Course name " << setw(15) << "Credit hour" << setw(10) << "Semester" << endl;
                    for (i = 0; i < 5; i++)
                    {
                        cout << setw(15) << coursecode[i] << left << setw(50) << coursename[i] << " \t \t " << setw(15) << credithour[i] << setw(10) << semester[i] << endl;
                        findcoursecode = true;
                    }
                }
                else
                {
                    findcoursecode = false;
                }
            }
            if (findcoursecode == false)
            {
                cout << "There are no cources added ...... press 1 in the main menu to add a new course " << endl;
            }

            getch();
            break;
        }
        case 5:
        {
            cout << "Enter the semester : ";
            cin >> usersemester;
            for (i = 0; i < 5; i++)
            {
                if (usersemester == semester[i])
                {
                    cout << setw(15) << " Course code " << left << setw(50) << " \t \t Course name " << setw(15) << "Credit hour" << endl;
                    cout << setw(15) << coursecode[i] << left << setw(50) << coursename[i] << setw(15) << credithour[i] << endl;
                    findsemester = true;
                }
                else
                {
                    findsemester = false;
                }
            }
            if (findsemester == false)
            {
                cout << "There are no subjects enrolled in " << usersemester << " semester" << endl;
            }
        }
        }
    } while (input != 0);
    return 0;
}
