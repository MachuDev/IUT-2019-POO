#include <iostream>
#include "cnode.h"
#include "clist.h"


using namespace std;

void ListeSimple (void)
{
    std::cout << "ListeSimple : \n\n";

    CNode<unsigned>* Tete = nullptr;

    // Le dernier element cree est toujours le premier de la liste


    for (unsigned i (0); i < 5; ) {
        Tete = new CNode<unsigned> (i++, Tete);
        std::cout << Tete << endl;
    }

    for (CNode<unsigned>* Ptr (Tete); Ptr; Ptr = Ptr->GetNextNode ())
        std::cout << Ptr->GetData() << "; ";

    std::cout << '\n';

    // Dans cette version, le destructeur de C1Link detruit son
    //   suivant donc la destruction de la liste est recursive

    delete Tete;

}// ListeSimple ()

void ListeSimpleV2 ()
{
    cout << "ListeSimpleV2 : \n\n";

    CList<unsigned> AList;

    // Le dernier element cree est toujours le premier de la liste


    for (unsigned i (0); i < 5; )
    {
        AList.push_front (i++);
    }

    //AList.push_front(9);
    AList.push_back(5);
    //  AList.AddAfter (AList.Begin (), 8);
    AList.Show ();

    unsigned i;
    cin >>i;
    CNode<unsigned>* ptr = AList.Find (i);
    AList.Add (3*i, ptr);

    AList.Show ();

    cout << ((ptr != nullptr)?  " " : "non ") << "trouve" << endl;

}

int main()
{
    ListeSimpleV2();
    return 0;
}
