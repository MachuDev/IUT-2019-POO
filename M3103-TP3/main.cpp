#include <iostream>
#include <memory>
#include "node.hpp"
#include "list.hpp"
using namespace std;

#define CNodeInt CNode<unsigned>

void ListeSimple (void)
{
    std::cout << "ListeSimple : \n\n";

    shared_ptr<CNodeInt> Tete = nullptr;

    // Le dernier element cree est toujours le premier de la liste


    for (unsigned i (0); i < 5; ) {
        Tete = shared_ptr<CNodeInt> (new CNode<unsigned>(++i, Tete));
        std::cout << Tete << endl;
    }

    for (shared_ptr<CNodeInt> Ptr (Tete); Ptr; Ptr = Ptr->GetNextNode ())
        std::cout << Ptr->GetData() << "; ";

    std::cout << '\n';

    // Dans cette version, le destructeur de C1Link detruit son
    //   suivant donc la destruction de la liste est recursive

}// ListeSimple ()


void ListeSimpleV2 ()
{
    cout << "ListeSimpleV2 : \n\n";

    CList<unsigned> AList;

    // Le dernier element cree est toujours le premier de la liste

    for (unsigned i = 8; i; i -= 2) AList.AddAfter (AList.Begin (), i);

    for (unsigned i (0); i < 5; ) {
        AList.push_front (i++);
    }

    //AList.AddBefore(AList.Begin(), 54);

    AList.push_front (100);
    AList.push_back(101);

//	AList.Show ();
/*	int i;
    cin >>i;
    CNodeInt* ptr = AList.Find (i);
    AList.Add (3*i, ptr);
    AList.Show ();

    cout << ((ptr != NULL)?  " " : "non ") << "trouve" << endl;
*/
    //cout << "valeur trouvée" << ptr . GetData () << endl;

    //delete AList;

    /*CNodeInt* ptr = AList.Find (2);
    cout << ((ptr != NULL)?  " " : "non ") << "trouve" << endl;
    AList.Delete (ptr);
    AList.Show ();*/

    //AList.Delete (AList.Find (0));

    AList.push_back (6);
    AList.push_back (7);
    AList.AddBefore(AList.Find (2), 10);


    AList.Delete (AList.Find (10));
    AList.Delete (AList.Find (101));
    AList.Delete (AList.Find (100));

    AList.Delete (AList.Find (889));

    AList.Show ();
    //delete ptr;
    cout << endl;

}

int main(void)
{
    //std::cout << "Hello World!" << std::endl;
    //ListeSimple();
    ListeSimpleV2 ();
    return 0;
}
