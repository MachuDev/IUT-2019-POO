#include <iostream>
#include <vector>
#include "cstcoderr.h"
#include "cexception.h"

using namespace std;
using namespace nsUtil;

namespace
{
    int divisionEntiere(const int & i1, const int & i2) throw (CException)
    {
        if(i2 == 0) throw CException("éDivion par 0 erreur", CstExcDivZero);
        return i1/i2;
    }

    void testDivisionParZero (void)
    {
        vector<int> num {52, 45, 2, 1, 0, 78, 54, 76};
        vector<int> den {12, 82, 2, 1, 0, 98, 4, 99};
        //
        for(const int & n : num){
            for(const int & d : den){
                cout << divisionEntiere(n,d) <<endl;
            }
        }

    } // testDivisionParZero ()

} // namespace

int main (void)
{
    try
    {
        testDivisionParZero ();

        return KNoExc;
    }
    catch (const CException & e)
    {
        cerr << "Erreur        : " << e.getLibelle () << '\n'
             << "Code d'erreur = " << e.getCodErr ()  << '\n';
        return e.getCodErr();
    }
    catch (const exception & e)
    {
        cerr << "Exception standard : " << e.what () << '\n';
        return KExcStd;
    }
    catch (...)
    {
        cerr << "Exception inconnue\n";
        return KExcInconnue;
    }

} // main()
