#include <iostream>

using namespace std;


#include "cstcoderr.h"
#include "cexception.h"
#include "rationnel.h"
using namespace std;
using namespace nsUtil;

namespace
{
    void testDivisionParZero (void)
    {
        nsMath::Rationnel r1 (10, 20);
        nsMath::Rationnel r2 (3, 0);
        (r1/r2).display();

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

