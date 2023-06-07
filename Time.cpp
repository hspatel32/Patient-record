//Name:-Harsh Shaileshkumar Patel

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "Time.h"
#include "utils.h"

using namespace std;
namespace sdds
{
    Time& Time::setToNow()
    {
        m_min = getTime();
        return *this;
    }

    Time::Time(unsigned int min)
    {
        m_min = min;
    }

    std::ostream& Time::write(std::ostream& ostr) const
    {
        int h = m_min / 60;
        int mins = m_min % 60;
        ostr << setw(2) << setfill('0') << h << ":" << setw(2) << setfill('0') << mins;
        return ostr;
    }

    std::istream& Time::read(std::istream& istr)
    {
        int mins = 0;
        int hours = 0;
        char delimiter = ' ';
        istr >> hours;
        istr >> delimiter;
        if (delimiter == ':' && hours >= 0 && mins >= 0)
        {
            istr >> mins;
            if (mins >= 0)
            {
                m_min = hours * 60 + mins;
            }
            else
            {
                istr.setstate(ios::failbit);
            }
        }
        else
        {
            istr.setstate(ios::failbit);
        }
        return istr;
    }

    Time& Time::operator-=(const Time& D)
    {
        if ((unsigned)int(D) > m_min)
        {
            m_min += 24 * 60;
            m_min -= int(D);
        }
        else
        {
            m_min -= int(D);
        }
        return *this;
    }

    Time Time::operator-(const Time& D)const
    {
        Time M = *this;
        M += 24 * 60;
        M -= int(D);
        return M;
    }

    Time& Time::operator+=(const Time& D)
    {
        m_min += int(D);
        return *this;
    }

    Time Time::operator+(const Time& D)const
    {
        Time M = *this;
        M = m_min + int(D);
        return M;
    }

    Time& Time::operator=(unsigned int val)
    {
        m_min = val;
        return *this;
    }

    Time& Time::operator *= (unsigned int val)
    {
        m_min = m_min * val;
        return *this;
    }

    Time& Time::operator /= (unsigned int val)
    {
        m_min = m_min / val;
        return *this;
    }

    Time Time::operator *(unsigned int val)const
    {
        Time M = *this;
        M = m_min * val;
        return M;
    }

    Time Time::operator /(unsigned int val)const
    {
        Time M = *this;
        M = m_min / val;
        return M;
    }

    Time::operator unsigned int()const
    {
        return m_min;
    }

    Time::operator int()const
    {
        return m_min;
    }

    std::ostream& operator<<(std::ostream& ostr, const Time& D)
    {
        D.write(ostr);
        return ostr;
    }

    std::istream& operator>>(std::istream& istr, Time& D)
    {
        D.read(istr);
        return istr;
    }
}