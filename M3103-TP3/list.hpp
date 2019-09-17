#ifndef LIST_HPP
#define LIST_HPP
#include <iostream>
#include <memory>
#include "node.hpp"


template <typename T>
class CList
{
private:
    std::shared_ptr<CNode<T>> m_fictionaHead;
    std::shared_ptr<CNode<T>> m_fictionaTail;

public:
    CList ();
    ~CList (){}
    void push_front (const T & val);
    void Show () const;
     std::shared_ptr<CNode<T>> Find (const T & val) const;
    void Add (const T & val, const std::shared_ptr<CNode<T>>&);
    void Delete (std::shared_ptr<CNode<T>>);
    void push_back (const T & val);
    std::shared_ptr<CNode<T>> Begin () const;
    void AddAfter (const std::shared_ptr<CNode<T>> &, const T & val);
    void AddBefore (const std::shared_ptr < CNode < T>> &, const T & val);
};

template <typename T>
std::shared_ptr<CNode<T>> CList<T>::Begin () const
{
    return m_fictionaHead;
}

template <typename T>
void CList<T>::AddAfter (const std::shared_ptr<CNode<T>>& ptr, const T & val)
{
    ptr -> SetNextNode (std::shared_ptr<CNode<T>> (new CNode<T> (val,
                                                                 ptr-> GetNextNode(),
                                                                 ptr)));
    ptr->GetNextNode ()->GetNextNode ()->SetPrevNode ( ptr->GetNextNode ());
}

template <typename T>
void CList<T>::AddBefore (const std::shared_ptr < CNode < T>> & ptr, const T & val)
{
    ptr -> SetPrevNode (std::shared_ptr<CNode<T>> (new CNode<T> (val,
                                                                 ptr,
                                                                     ptr-> GetPrevNode())));
    ptr->GetPrevNode ()->GetPrevNode ()->SetNextNode ( ptr->GetPrevNode ());
}

template <typename T>
void CList<T>::Add (const T & val, const std::shared_ptr<CNode<T>>& ptr)
{
    std::shared_ptr<CNode<T>> ptrTmp = std::shared_ptr<CNode<T>>(new CNode<T> (val, ptr -> GetNextNode (), ptr));
    ptr -> SetNextNode (ptrTmp);
    if (ptr == m_fictionaTail) m_fictionaTail = ptr->GetPrevNode ();
}

/*Ptr_t AjoutApres (Ptr_t Tete, int NewVal, Ptr_t PtrElem)
{
    if (! PtrElem) PtrElem = Tete;

    PtrElem->SetSuivant
           (new C1Link (NewVal, PtrElem->GetSuivant()));

    return PtrElem->GetSuivant();

} // AjoutApres()
*/

template <typename T>
CList<T>::CList () : m_fictionaHead (std::shared_ptr<CNode<T>> (new CNode<T>())),
                     m_fictionaTail (std::shared_ptr<CNode<T>> (new CNode<T>()))
{
    m_fictionaHead->SetNextNode(m_fictionaTail);
    m_fictionaTail->SetPrevNode(m_fictionaHead);
}

template <typename T>
std::shared_ptr<CNode<T>> CList<T>::Find (const T & val) const
{
    std::shared_ptr<CNode<T>> Ptr (m_fictionaHead->GetNextNode ());
    for (; Ptr != m_fictionaTail && Ptr -> GetData () != val ; Ptr = Ptr->GetNextNode ());
    return m_fictionaTail == Ptr ? nullptr : Ptr;
}



template <typename T>
void CList<T>::push_front (const T & val)
{
    m_fictionaHead->SetNextNode (std::shared_ptr<CNode<T>>
                                 (new CNode<T> (val,
                                  m_fictionaHead->GetNextNode(), m_fictionaHead)));
    m_fictionaHead->GetNextNode()->GetNextNode()->SetPrevNode(m_fictionaHead->GetNextNode());
}

template <typename T>
void CList<T>::Show () const
{
    //for (CNodeInt* Ptr (m_Head); Ptr; ++*Ptr)
    for (std::shared_ptr<CNode<T>> Ptr (m_fictionaHead -> GetNextNode()); Ptr!= m_fictionaTail; Ptr = Ptr->GetNextNode ())
            std::cout << Ptr->GetData() << "; ";
    std::cout << std::endl;
}

template <typename T>
void CList<T>::Delete (std::shared_ptr<CNode<T>> pDelete)
{
    std::shared_ptr<CNode<T>> pFind (m_fictionaHead);
    for ( ; pFind -> GetNextNode () != pDelete ; pFind = pFind -> GetNextNode ());
    if (pFind == m_fictionaTail) return;
    pFind -> SetNextNode (pDelete -> GetNextNode ());
    pDelete -> SetNextNode (nullptr);
}

template <typename T>
void CList<T>::push_back (const T & val)
{
    m_fictionaTail->SetPrevNode (std::shared_ptr<CNode<T>>
                                 (new CNode<T> (val,
                                                m_fictionaTail,
                                                m_fictionaTail->GetPrevNode())));
    m_fictionaTail->GetPrevNode()->GetPrevNode()->SetNextNode(m_fictionaTail->GetPrevNode());
}


#endif // LIST_HPP
