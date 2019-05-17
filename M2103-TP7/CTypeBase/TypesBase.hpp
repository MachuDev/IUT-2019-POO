#ifndef TYPESBASE_HPP
#define TYPESBASE_HPP

#include <cstdint>


namespace std {

    template<class T>
    class CTypeBase
    {
    private:
        T myVal;

    public:
        explicit CTypeBase(const T & val = T()) noexcept : myVal(val) {}
        operator T & () noexcept { return myVal; }
    };

    typedef CTypeBase <int16_t> Short;
    typedef CTypeBase <int32_t> Integer;
    typedef CTypeBase <uint8_t> Character;

}

#endif // TYPESBASE_HPP
