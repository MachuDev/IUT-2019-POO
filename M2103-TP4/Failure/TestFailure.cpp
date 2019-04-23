/**
 *
 * \file   : TestFailure.cpp
 *
 * \author :
 *
 * \date   :
 *
**/

#include "cstcoderr.h"
#include "cexception.h"
#include "fstream"

using namespace std;
using namespace nsUtil;

namespace
{
    void testFailure (void)
    {
        ifstream s ("test.txt");
        if(!s.is_open())
            exit(1);
        try {
            string a;
            while (getline(s, a)) {
                cout << a << endl;
            }
        } catch (const ios_base & e) {
        }

    } // TestFailure  ()

} // namespace

int main (void)
{
    try
    {
        testFailure ();

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
