//Name:-Harsh Shaileshkumar Patel
// Project: Milestone-4

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds
{
    bool debug = false; 
    int getTime()
    {
        int mins = -1;
        if (debug)
        {
            Time t(0);
            cout << "Enter current time: ";
            do
            {
                cin.clear();
                cin >> t;   
                if (!cin)
                {
                    cout << "Invlid time, try agian (HH:MM): ";
                    cin.clear();
                }
                else
                {
                    mins = int(t);
                }
                cin.ignore(1000, '\n');
            } while (mins < 0);
        }
        else
        {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            mins = lt.tm_hour * 60 + lt.tm_min;
        }
        return mins;
    }

    int getInt(const char* prompt)
    {
        int num;
        bool valid = false;
        if (prompt != nullptr)
        {
            cout << prompt;
        }
        while (!valid)
        {
            cin >> num;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(3000, '\n');
                cout << "Bad integer value, try again: ";
            }
            else if (char(cin.get()) != '\n')
            {
                cout << "Enter only an integer, try again: ";
                cin.ignore(2000, '\n');

            }
            else
            {
                valid = true;
            }
        }
        return num;
    }

    int getInt(int min,int max, const char* prompt, const char* errorMessage, bool showRangeAtError)
    {
        if (prompt != nullptr)
        {
            cout << prompt;
        }
        int num;
        bool valid = false;
        while (!valid)
        {
            num = getInt();
            if (num >= min && num <= max)
            {
                valid = true;
            }
            if (!valid && errorMessage)
            {
                cout << errorMessage;
                if (showRangeAtError)
                {
                    cout << "[" << min << " <= value <= " << max << "]: ";
                }
            }
        }
        return num;
    }

    char* getcstr(const char* prompt, std::istream& istr, char delimiter)
    {
        if (prompt)
        {
            cout << prompt;
        }
        char* strng = nullptr;
        string temp;
        getline(istr, temp);
        strng = new char[strlen(temp.c_str()) + 1];
        strcpy(strng, temp.c_str());
        return strng;
    }
}