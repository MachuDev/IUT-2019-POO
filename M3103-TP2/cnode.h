#ifndef CNODE_H
#define CNODE_H


template <typename T>
class CNode
{
private:
    T m_Data;
    CNode* m_Next;
public:
    //constructor
    CNode (const T & Data = T(), CNode* Next = nullptr) : m_Data(Data), m_Next(Next) {}
    //destructor
    ~CNode () {delete this->m_Next;}

    T GetData () const {return this->m_Data;}
    void SetData(const T & m_Data) {this->m_Data = m_Data;}

    CNode* GetNextNode () const {return this->m_Next;}
    void SetNextNode (CNode* Next) {m_Next = Next;}

};

#endif // CNODE_H
