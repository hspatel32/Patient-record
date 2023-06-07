//Name:-Harsh Shaileshkumar Patel

#define _CRT_SECURE_NO_WARNINGS
#include "CovidPatient.h"
#include <iostream>
#include "IOAble.h"

namespace sdds
{
   int nextCovidTicket = 1;
   //------------------------------------------------------------------------------
   CovidPatient::CovidPatient() : Patient(nextCovidTicket)
   {
      nextCovidTicket++;
   }
   //------------------------------------------------------------------------------
   char CovidPatient::type() const
   {
      return 'C';
   }
   //------------------------------------------------------------------------------
   std::istream &CovidPatient::read(std::istream &istr)
   {
      return fileIO() ? csvRead(istr) : Patient::read(istr);
   }
   //------------------------------------------------------------------------------
   std::ostream &CovidPatient::write(std::ostream &ostr) const
   {
      if (!fileIO())
      {
         ostr << "COVID TEST" << std::endl;
         Patient::write(ostr);
         ostr << std::endl;
      }
      else
      {
         csvWrite(ostr);
      }
      return ostr;
   }
   //------------------------------------------------------------------------------
   std::istream &CovidPatient::csvRead(std::istream &istr)
   {
      Patient::csvRead(istr);
      nextCovidTicket = Patient::number() + 1;
      return istr;
   }
}