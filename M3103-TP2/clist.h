#ifndef CLIST_H
#define CLIST_H
#include <iostream>
#include "cnode.h"

template <typename T>
class CList
{
private:
    CNode<T>*  m_fictionaHead;
public:
    CList () :  m_fictionaHead(nullptr) {}
    ~CList () {delete  m_fictionaHead;}
   //ajout en tête de liste
    void push_front (const T & val)
    {
         m_fictionaHead = new CNode<T> (val,  m_fictionaHead);
    }
   //affichage
    void Show () const
    {
        for (CNode<T>* ptr ( m_fictionaHead); ptr != nullptr; ptr = ptr->GetNextNode ())
            std::cout << ptr->GetData () << "; ";
    }
    //recherche d'un élément dans la liste, renvoie le pointeur du maillon si l'élément est présent, nullptr sinon
    CNode<T>* Find (const T & val) const
    {
        CNode<T>* ptr ( m_fictionaHead);
        for ( ; ptr != nullptr && ptr->GetData () != val ; ptr = ptr->GetNextNode ());
        return ptr;
    }
    //ajout d'une valeur après un maillon de la liste
    void Add (const T & val, CNode<T>* ptr)
    {
        if (nullptr == ptr) return;
        CNode<T>* ptrTmp = new CNode<T> (val, ptr->GetNextNode ());
        ptr->SetNextNode (ptrTmp);
    }
    //détache un maillon de la liste et le supprime
    void Delete (CNode<T>* pDelete)
    {
        CNode<T>* pFind ( m_fictionaHead);
        for ( ; pFind->GetNextNode () != pDelete ; pFind = pFind->GetNextNode ())
            if (pFind->GetNextNode () == nullptr) return;
        pFind->SetNextNode (pDelete->GetNextNode ());
        pDelete->SetNextNode (nullptr);

        delete pDelete;
    }

    void push_back (const T & val){
        CNode<T>* pTmp = new CNode<T> (val, nullptr);
         m_fictionaHead->SetNextNode (pTmp);
         m_fictionaHead = pTmp;
    }
};

#endif // CLIST_H
