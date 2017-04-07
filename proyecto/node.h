#include "pcb.h"

extern "C"
{
    class node
    {
    public:
        node(pcb* element,int _priority);
        ~node();
        int priority;
        pcb data;
        node* leftChild;
        node* rightChild;
        void cmpHeap(pcb* & element, int & _priority);
        node* foundChildren(int isLeft, PCB*& element, int& _priority);
        void restructure();
    private:
        node* changeRight(node*sRightChild, int &isChange);
        node* changeLeft(node*sLeftChild, int &isChange);
        void changeValues(node* sor);
        void changeValues(PCB* &element, int & _priority);
    };
}