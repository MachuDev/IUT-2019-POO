#ifndef CLIST_H
#define CLIST_H
#include <iostream>
#include "cnode.h"

template <typename T>
class CList
{
private:
    CNode<T>*  m_Head;
    CNode<T>*  m_Queue;
public:
    CList () :  m_Head(new CNode<T>()), m_Queue(m_Head) {}
    ~CList () {delete  m_Head; }
   //ajout en tête de liste
    void push_front (const T & val)
    {
         m_Head = new CNode<T> (val,  m_Head);
         if(m_Head->GetNextNode () == nullptr)
             m_Queue = m_Head;
    }
   //affichage
    void Show () const
    {
        for (CNode<T>* Ptr (m_Head -> GetNextNode());
                 Ptr != m_Queue; Ptr = Ptr->GetNextNode ())
                    std::cout << Ptr->GetData() << "; ";
            std::cout << std::endl;
    }
    //recherche d'un élément dans la liste, renvoie le pointeur du maillon si l'élément est présent, nullptr sinon
    CNode<T>* Find (const T & val) const
    {
        CNode<T>* ptr ( m_Head);
        for ( ; ptr != nullptr && ptr->GetData () != val ; ptr = ptr->GetNextNode ());
        return ptr;
    }
    //ajout d'une valeur après un maillon de la liste
    void Add (const T & val, CNode<T>* ptr)
    {
        if (nullptr == ptr) return;
        CNode<T>* ptrTmp = new CNode<T> (val, ptr->GetNextNode ());
        ptr->SetNextNode (ptrTmp);
        if(ptr->GetNextNode() == nullptr)
            m_Queue = ptr;
    }
    //détache un maillon de la liste et le supprime
    void Delete (CNode<T>* pDelete)
    {
        CNode<T>* pFind ( m_Head);
        for ( ; pFind->GetNextNode () != pDelete ; pFind = pFind->GetNextNode ())
            if (pFind->GetNextNode () == nullptr) return;
        pFind->SetNextNode (pDelete->GetNextNode ());
        pDelete->SetNextNode (nullptr);

        if(pDelete->GetNextNode() == nullptr)
            m_Queue = pDelete;

        delete pDelete;
    }

    void push_back (const T & val){
        CNode<T>* pTmp = new CNode<T> (val, nullptr);
        if(m_Queue != nullptr)
            m_Queue->SetNextNode (pTmp);
        else {
            m_Head = pTmp;
        }
         m_Queue = pTmp;
    }

    void AddAfter (CNode<T>* ptr, int Val)
    {
        ptr->SetNextNode (new
              CNode<T> (Val, ptr->GetNextNode()));
    }
};

#endif // CLIST_H
