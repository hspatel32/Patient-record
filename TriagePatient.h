//Name:- Harsh Shaileshkumar Patel
// Project: Milestone-4
#ifndef SDDS_TRIAGEPATIENT_H
#define SDDS_TRIAGEPATIENT_H
#include "Patient.h"

namespace sdds
{
    //------------------------------------------------------------------------------
    class TriagePatient : public Patient
    {
    private:
        char *symptoms;

    public:
        TriagePatient();
        ~TriagePatient();
        char type() const;
        std::istream &read(std::istream &istr);
        std::ostream &write(std::ostream &ostr) const;
        std::istream &csvRead(std::istream &istr);
        std::ostream &csvWrite(std::ostream &ostr) const;
    };
}
//------------------------------------------------------------------------------
#endif // !SDDS_TRIAGEPATIENT_H