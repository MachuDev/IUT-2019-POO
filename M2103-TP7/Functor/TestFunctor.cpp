/**
 *
 * @file   TestFunctor.cpp
 *
 * @authors M. Laporte, D. Mathieu
 *
 * @date    27/04/2010
 *
 * @version V1.0
 *
 * @brief   Premier functor
 *
 **/
#include <iostream>
#include <cassert>
#include <cctype>  // tolower(), toupper()
#include <string>

using namespace std;

namespace
{
    class ToLower
    {
        // ToDo
    public:
        virtual ~ToLower(){}
        virtual int operator() (int val) const {
            return tolower(val);
        }
    }; // ToLower

    string & moulinette (string & str, const ToLower & tolow)
    {
        for (string::size_type i (str.size ()); i--; )
            str [i] = tolow (str [i]);

        return str;

    } // moulinette()

    void testFunctor (void)
    {
        cout << "Functor : ";

        string ligne  ("AZECv qrgWSg wrV  wfdgWFDHG  wdfGWXCV");
        string minusc ("azecv qrgwsg wrv  wfdgwfdhg  wdfgwxcv");

        ToLower tolow;
        assert (minusc == moulinette (ligne, tolow));

        cout << "OK\n";

    } // testFunctor()

} // namespace anonyme

int main (void)
{
    /*      */    testFunctor ();     /*           */

    return 0;

} // main()
