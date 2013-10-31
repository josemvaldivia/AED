#include <iostream>

using namespace std;

/*! A test class */
class Test
{
  public:
    /** An enum type.
     *  The documentation block cannot be put after the enum!
     */
    enum EnumType{ EVal1,    /**< enum value 1 */  EVal2    /**< enum value 2 */};
    void member();   //!< a member function.

  protected:

};

int main()
{

    int x=3; /**<este es un entero x que vale 3 */

    return 0;
}
