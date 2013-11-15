#include <iostream>
#include "BitVector.h"
using namespace std;

int main()
{
    BitVector a(20);
    a.SetBit(8,true);
    a.SetBit(16,false);
    a.SetBit(19,true);
    a.SetBit(19,false);
    a.SetBit(4,true);
    a.SetBit(5,true);
    a.SetBit(3,true);
    a.SetBit(4,false);

    for(int i=19; i>=0;i--)
    {
        cout<<a.getBit(i);
    }

    cout<<endl;
    a.ShowRow();

    return 0;
}
