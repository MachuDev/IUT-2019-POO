#include <iostream>
#include "cexception.h"
using namespace std;
using namespace nsUtil;

void testExceptionsInMain()
{
    char c;
    cin >> c;
    if(c == '1'){
        string("qsdsd").at(1);
        throw runtime_error("ee");
    }else if (c == '2'){
        throw unsigned(1);
    }else if (c == '3'){

    }else if (c == '4'){

    }
}

int main()
{
    try {
        testExceptionsInMain();
    } catch (const string& e) {
        cout << e << endl;
    } catch (const CException & e2) {
        e2.display();
        cout << e2.what() << endl;
    //} catch (const runtime_error & e3){
      //  cout << e3.what() << endl;
    } catch (const int & e4){
        cout << e4 << endl;
 } catch (const exception & e5){
    cout << e5.what() << endl;
}
    return 0;
}
