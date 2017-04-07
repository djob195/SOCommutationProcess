#include "pcb.h"
#include "node.h"
extern "C"
{
    class heap
    {
    public:
        int Length;
        heap();
        ~heap();
        int isEmpty();
        void add(PCB* element, int priority = 0);
        PCB* peek();
        PCB* pool();
        int getPriority();
    private:
        node* root;
    };
}