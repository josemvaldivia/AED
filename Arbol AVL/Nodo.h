#ifndef NODO_H
#define NODO_H

template <typename T>
class Nodo
{
    public:
        typedef Nodo<T> nodo;
        int altura[2];
        Nodo(T d) {
            dato = d;
            altura[0]=0;
            altura[1]=0;
            rama[0]=NULL;
            rama[1]=NULL;
        }
        virtual ~Nodo() {}
        Nodo <T> * rama [2];
        T dato;

    protected:
    private:
};

#endif // NODO_H
