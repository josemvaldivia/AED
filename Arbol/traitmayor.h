#ifndef TRAITMAYOR_H
#define TRAITMAYOR_H
#include"Mayor.h"
template <typename T>
class TraitMayor
{
    public:
        typedef T Tipo;
        typedef Mayor<T> C;
        TraitMayor() {}
        virtual ~TraitMayor() {}
    protected:
    private:
};

#endif // TRAITMAYOR_H
