#ifndef MENOR_H
#define MENOR_H

template <typename T>
class Menor
{
    public:
        Menor() {}
        virtual ~Menor() {}
        bool operator() ( T a, T b)
    protected:
    private:
};

template<typename T>
bool Menor <T>::operator() ( T a, T b)
{
    return a<b;
}


#endif // MENOR_H
