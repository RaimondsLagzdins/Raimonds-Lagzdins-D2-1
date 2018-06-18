#ifndef KAULINS_H
#define KAULINS_H

#include <stdlib.h>
#include <time.h>
class Kaulins
{
    public:
        Kaulins();
        virtual ~Kaulins();
        int mest();
        int getVertiba();
    protected:

    private:
        int vertiba;
};

#endif // KAULINS_H
