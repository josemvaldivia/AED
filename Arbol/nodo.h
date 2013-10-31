#ifndef NODO_H
#define NODO_H

template <typename T>
class Nodo
{
    public:
        Nodo(T d) {
            dato = d;
        }
        virtual ~Nodo() {}
        Nodo <T> * rama [2];
        T dato;
    protected:
    private:
};

#endif // NODO_H
