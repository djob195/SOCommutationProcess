extern "C"
{
        node::node(pcb* element, int _priority )
        {
            this->priority = _priority;
	        this->data = element;
	        this->leftChild = 0;
	        this->rightChild = 0;
        }
        node::~node(){}
        
    void node::cmpHeap(PCB* &element, int &_priority)
    {
            if (_priority >this->priority)
            {
                this->changeValues(element, _priority);
            }
    }
    node node::foundChildren(int isLeft, PCB*& element, int& _priority)
    {
        cmpHeap(element, _priority, ord);
        if (isLeft == 1)
        {
            return this->leftChild;
        }
        else
        {
            return this->rightChild;
        }
    }
    void node::changeValues(PCB* &element, int & _priority)
    {
        int auxPriority = this->priority;
        this->priority = _priority;
        _priority = auxPriority;
        PCB* auxData = this->data;
        this->data = element;
        element = auxData;
    }
    void node::restructure()
    {
        int isChange = 1;
        node* nowNode = this;
        while (isChange == 1)
        {
            if ((nowNode->leftChild != 0) && (nowNode->rightChild != 0))
            {
                if (nowNode->leftChild->priority > nowNode->rightChild->priority)
                {
                    nowNode = nowNode->changeLeft(nowNode->leftChild, isChange);
                }
                else
                {
                    nowNode = nowNode->changeRight(nowNode->rightChild, isChange);
                }
            }
            else if (nowNode->leftChild != 0)
            {
                nowNode = nowNode->changeLeft(nowNode->leftChild, isChange);
            }
            else if (nowNode->rightChild != 0)
            {
                nowNode = nowNode->changeRight(nowNode->rightChild, isChange);
            }
            else
            {
                isChange = 0;
            }
        }
    }
    node* node::changeRight(node* sRightChild, int & isChange)
    {
        if (sRightChild->priority > this->priority)
         {
            isChange = 1;
            changeValues(sRightChild);
        }
        else
        {
            isChange = 0;
        }
        return sRightChild;
    }
    node* node::changeLeft(node* sLeftChild, int & isChange)
    {
         if (sLeftChild->priority > this->priority)
        {
            isChange = 1;
            changeValues(sLeftChild);
         }
        else
        {
            isChange = 0;
        }
        return sLeftChild;
    }
    void node::changeValues(node* sor)
    {
        int auxPriority = this->priority;
        this->priority = sor->priority;
        sor->priority = auxPriority;
        PCB* auxData = this->data;
        this->data = sor->data;
        sor->data = auxData;
    }
}