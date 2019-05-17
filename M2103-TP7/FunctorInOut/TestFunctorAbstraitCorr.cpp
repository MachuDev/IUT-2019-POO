/**
 *
 * @file    TestFunctorAbstraitCorr.cpp
 *
 * @authors M. Laporte
 *
 * @date    07/05/2018
 *
 * @version V1.0
 *
 * @brief   functor abstrait
 *
 **/
#include <string>
#include <iostream>
#include <cctype>    // ispunct(), islower(), isalpha()
                     // tolower(), toupper()
#include <cassert>

using namespace std;

namespace
{
    class ITraitCar
    {
    private:
        mutable int myCpt;
    public :
        ITraitCar() {
            myCpt = 0;
        }
        int getCpt() const { return myCpt; }
        void setCpt(int cpt) const { myCpt = cpt; }
        virtual ~ITraitCar (void) {}
        virtual int operator () (int caract) const = 0;
    }; // ITraitCar

    class ToLower  : public ITraitCar
    {
      public :
        virtual ~ToLower (void) {}
        virtual int operator () (int caract) const noexcept
        {
            this->setCpt(this->getCpt()+1);
            return tolower (caract);

        } // operateur()

    }; // ToLower

    class ToUpper : public ITraitCar
    {
      public :
        virtual ~ToUpper (void) {}
        virtual int operator () (int caract) const noexcept
        {
            this->setCpt(this->getCpt()+1);
            return toupper (caract);

        } // operateur()

    }; // ToUpper

    class IgnPunct : public ITraitCar
    {
      public :
        virtual ~IgnPunct (void) {}
        virtual int operator () (int caract) const noexcept
        {
            if(ispunct (caract)){
                this->setCpt(this->getCpt()+1);
                return ' ';
            }else return caract;

        } // operateur()

    }; // IgnPunct

    string & moulinette (string & str, const ITraitCar & transf)
    {
        for (string::size_type i (str.size()); i--; )
            str [i] = transf (str [i]);

        return str;

    } // moulinette()

    void testFunctor (void)
    {
        cout << "Functor abstrait : ";

        string ligne     ("azert:;,.?GFDSQ");
        string minusc    ("azert:;,.?gfdsq");
        string majusc    ("AZERT:;,.?GFDSQ");
        string sansPunct ("AZERT     GFDSQ");

        ToLower tolower;
        assert (minusc    == moulinette (ligne, tolower));
        assert(tolower.getCpt() == 15);

        ToUpper toupper;
        assert (majusc    == moulinette (ligne, toupper));
        assert(toupper.getCpt() == 15);

        IgnPunct ignpunct;
        assert (sansPunct == moulinette (ligne, ignpunct));
        assert(ignpunct.getCpt() == 5);

        cout << "OK\n";

    } // testFunctor()

} // namespace

int main (void)
{
    /*      */    testFunctor ();     /*           */

    return 0;

} // main()
