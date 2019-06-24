#include "cpmv.hpp"

int main()
{
    Cpmv a;
    a.Display();

    Cpmv b("bq", "bz");
    b.Display();

    Cpmv c(b);
    c.Display();

    Cpmv d(b+b);
    d.Display();

    Cpmv e = a;
    e.Display();

    Cpmv f = b + b;
    f.Display();

    return 0;
}