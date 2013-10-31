#ifndef MAYOR_H
#define MAYOR_H

template <typename T>
class Mayor
{
    public:
        Mayor() {}
        virtual ~Mayor() {}
        bool operator () (T a, T b);
    protected:
    private:

};

template<typename T>
bool Mayor <T>::operator() ( T a, T b)
{
    return a>b;
}


#endif // MAYOR_H
