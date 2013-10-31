#ifndef DESCIENDE_H
#define DESCIENDE_H

template<typename T>
class Desciende
{
    public:
         inline bool  comp (T primero, T segundo);
    protected:
    private:
};

template <typename T>
 inline bool Desciende<T>:: comp  (T primero, T segundo)
{
    return primero>segundo;

}

#endif // DESCIENDE_H
