#ifndef BITVECTOR_H
#define BITVECTOR_H
#include <math.h>
#include <iostream>
using namespace std;

class BitVector
{
    public:
        BitVector(int x) {
            if(x%8==0){
                vector=new unsigned char[x/8];
                tam=x/8;
            }
            else{
                vector=new unsigned char[(x/8)+1];
                tam=(x/8)+1;
            }

            for(int i=0;i<tam;i++)
            {
                vector[i]=0;
            }
        }
        virtual ~BitVector() {

            delete [] vector;
        }

        void SetBit(int pos, bool def);
        bool getBit(int pos);
        void ShowRow();
    protected:
    private:

        unsigned char * vector;
        int tam;
};

void BitVector::SetBit(int pos, bool def)
{
    int part=pos/8;
    int pos_part=pos%8;
    unsigned char adolfo=1<<pos_part;

    if(def)
    {
        vector[part]=vector[part]|adolfo;
    }
    else
    {
        int tmp= ~adolfo;
        vector[part]=vector[part]&tmp;
    }

}

bool BitVector::getBit(int pos)
{

    int part=pos/8;
    int pos_part=pos%8;
    unsigned char adolfo=1<<pos_part;
    return (vector[part]&adolfo);

}

void BitVector::ShowRow()
{
    for(int i=0;i<tam;i++)
    {
        cout<<(int)vector[i]<<endl;
    }
    cout<<endl;
}

#endif // BITVECTOR_H
