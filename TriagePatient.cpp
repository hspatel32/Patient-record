//Name:-Harsh Shaileshkumar Patel
// Project: Milestone-4

#define _CRT_SECURE_NO_WARNINGS
#include "TriagePatient.h"
#include <iostream>
#include <string>
#include <cstring>
#include "IOAble.h"

namespace sdds
{
   int nextTriageTicket = 1;
   //------------------------------------------------------------------------------
   TriagePatient::TriagePatient() : Patient(nextTriageTicket)
   {
      symptoms = nullptr;
      nextTriageTicket++;
   }
   //------------------------------------------------------------------------------
   TriagePatient::~TriagePatient()
   {
      delete[] symptoms;
   }
   //------------------------------------------------------------------------------
   char TriagePatient::type() const
   {
      return 'T';
   }
   //------------------------------------------------------------------------------
   std::istream &TriagePatient::read(std::istream &istr)
   {
      if (!fileIO())
      {
         delete[] symptoms;
         Patient::read(istr);
         std::cout << "Symptoms: ";
         std::string str;
         std::getline(istr, str);
         int length = str.length();
         symptoms = new char[length + 1];
         strcpy(symptoms, str.c_str());
         symptoms[length] = '\0';
      }
      else
      {
         csvRead(istr);
      }
      return istr;
   }
   //------------------------------------------------------------------------------
   std::ostream &TriagePatient::write(std::ostream &ostr) const
   {
      if (!fileIO())
      {
         ostr << "TRIAGE" << std::endl;
         Patient::write(ostr);
         ostr << std::endl;
         ostr << "Symptoms: " << symptoms << std::endl;
      }
      else
      {
         csvWrite(ostr);
      }
      return ostr;
   }
   //------------------------------------------------------------------------------
   std::istream &TriagePatient::csvRead(std::istream &istr)
   {
      delete[] symptoms;
      Patient::csvRead(istr);
      istr.ignore();
      std::string str;
      std::getline(istr, str, '\n');
      int length = str.length();
      symptoms = new char[length + 1];
      strcpy(symptoms, str.c_str());
      symptoms[length] = '\0';
      nextTriageTicket = Patient::number() + 1;
      return istr;
   }
   //------------------------------------------------------------------------------
   std::ostream &TriagePatient::csvWrite(std::ostream &ostr) const
   {
      Patient::csvWrite(ostr);
      return ostr << ',' << symptoms;
   }
}