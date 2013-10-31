#ifndef TRAITMENOR_H
#define TRAITMENOR_H
#include "Menor.h"
template <typename T>
class TraitMenor
{
    public:
        typedef T Tipo;
        typedef Menor<T> C;
        TraitMenor() {}
        virtual ~TraitMenor() {}
    protected:
    private:
};

#endif // TRAITMENOR_H
