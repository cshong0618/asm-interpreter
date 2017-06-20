//
// Created by shaong on 6/18/17.
//

#ifndef ASMINTER_TYPE_H
#define ASMINTER_TYPE_H
namespace ASMI
{
    enum Type
    {
        S32,
        U32,
        S64,
        U64,
        D32,
        D64,
        P32,
    };

    template <typename T>
    Type deduce_type(T val)
    {
        std::cout << "Value of val is: " << val << " . Type id of val is " << typeid(val).name() << "\n";

        if(typeid(val) == typeid(int)) return S32;
        if(typeid(val) == typeid(unsigned int)) return U32;
        if(typeid(val) == typeid(long)) return S64;
        if(typeid(val) == typeid(unsigned long)) return U64;
        if(typeid(val) == typeid(float)) return D32;
        if(typeid(val) == typeid(double)) return D64;
        if(typeid(val) == typeid(int*)) return P32;
    }
}
#endif //ASMINTER_TYPE_H
