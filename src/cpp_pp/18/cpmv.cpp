#include "cpmv.hpp"
#include <iostream>

using namespace std;

Cpmv::Cpmv()
{
    pi = new Info();
}

Cpmv::Cpmv(std::string q, std::string z)
{
    pi = new Info({q,z});
}

Cpmv::Cpmv(const Cpmv &cp)
{
    pi = new Info({cp.pi->qcode, cp.pi->zcode});
}

Cpmv::Cpmv(Cpmv &&mv)
{
    pi = mv.pi;
    mv.pi = nullptr;
}

Cpmv::~Cpmv()
{
    delete pi;
}

Cpmv& Cpmv::operator=(const Cpmv &cp)
{
    pi = new Info({cp.pi->qcode, cp.pi->zcode});
    return *this;
}

Cpmv& Cpmv::operator=(Cpmv &&cp)
{
    pi = cp.pi;
    cp.pi = nullptr;
    return *this;
}

Cpmv Cpmv::operator+(const Cpmv &obj) const
{
    Cpmv rv(*this);
    rv.pi->qcode += obj.pi->qcode;
    rv.pi->zcode += obj.pi->zcode;
    return rv;
}

void Cpmv::Display() const
{
    cout << pi->qcode << " " << pi->zcode << endl;
}