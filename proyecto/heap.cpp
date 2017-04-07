extern "C"
{
    heap::heap()
    {
        this->Length = 0;
    }
    heap::~heap() {}
    int heap::isEmpty()
    {
        if (this->Length==0)
        {
            return 0;
        }
        return 1;
    }
    void heap::add(PCB* element, int priority)
    {
        if(this->isEmpty()==1)
        {
            this->root = new node(element,priority);
        }
        else
        {
            long way = Length+1;
            node* father = root;
            while (way>3)
            {
                if (way % 2 == 0)
                {
                    father = father->foundChildren(1, element, priority);
                }
                else
                {
                    father = father->foundChildren(0, element, priority);
                }
                way /= 2;
            }
            if (way % 2 == 0)
            {
                father->leftChild = new node(element, priority);
            }
            else
            {
                father->rightChild = new node(element, priority);
            }
        }
        Length++;
    }
    PCB* heap::peek()
    {
        return this->root->data;
    }
    PCB* pool::()
    {
        if (this->isEmpty==1)
        {
            return 0;
        }
        else if (this->Length == 1)
        {
            T data = this->root->data;
            this->Length--;
            return data;
        }
        PCB* data = this->root->data;
        long way = Length;
        node* father = this->root;
        int isLeft = 1;
        while (way > 3)
        {
            if (way % 2 == 0)
            {
                father = father->leftChild;
            }
            else
            {
                father = father->rightChild;
            }
            way /= 2;
        }
        if (way%2==0)
        {
            this->root->priority = father->leftChild->priority;
            this->root->data = father->leftChild->data;
            father->leftChild = 0;
        }
        else
        {
            this->root->priority = father->rightChild->priority;
            this->root->data = father->rightChild->data;
            father->rightChild = 0;
        }
        this->root->restructure();
        this->Length--;
        return data;
    }
    int heap::getPriority()
    {
        if (this->isEmpty())
        {
            return 0;
        }
        return this->root->priority;
    }
}