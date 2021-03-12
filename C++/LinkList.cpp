#include <iostream>
using namespace std;

/**
*这里设置了两个类，一个是表示链表结点的ListNode类，一个是表示链表整体的LinkList类。
*在ListNode中我们将LinkList类设为ListNode的友元类，这样可以方便链表类对结点的内部成员变量和成员方法的访问。
*/

/*************定义链表结点****************/
template <typename DataType> class ListNode
{
public:
	ListNode()
	{
		next = NULL;
	}
	ListNode(DataType item, ListNode<DataType>* nextNode=NULL)
	{
		data = item;
		next = nextNode;
	}
	~ListNode()
	{
		next = NULL;
	}

	DataType getData()
	{
		return data;
	}

	ListNode* getNext()
	{
		return next;
	}
private:
	friend typename LinkList<DataType>;//将LinkList设为友元类，方便其对node的成员数据和方法的访问
	DataType* next;
	DataType data;
};

/**************链表结构***************/
template <typename DataType> class LinkList
{
public:
	LinkList()
	{
        head = new ListNode();
	}
    LinkList(ListNode* node)
	{
        head = node;
	}
	~LinkList()
	{
        delete head;
	}

    bool insertNode(DataType newData); //尾部插入结点
    bool insertNode(int i, DataType newData); //i位置插入结点
    bool removeNode(ListNode<DataType> *q);   //删除结点
    ListNode<DataType>* findNode(DataType value); //查找指定值的结点并返回地址
    bool cleanLink();                                               //清空链表
    DataType getNodeData(ListNode<DataType> *p);                      //获取结点数据

private:
	ListNode* head; // 头结点
};

//*************在链表的尾部插入结点***************/
template <typename DataType>
bool LinkList<DataType>::insertNode(DataType newData)
{
    ListNode<DataType>* p = head;
    ListNode<DataType>* newNode = new ListNode<DataType>(newData);
    if (newNode == nullptr)
    {
        return false;
    }
    
    while (p->next != NULL)
    {
        p = p->next;
    }
    
    p->next = newNode;

    return true;
}


//*************在链表的第i个结点后插入新结点***************/
template <typename DataType>
bool LinkList<DataType>::insertNode(int i, DataType newData)
{
    ListNode<DataType>* p = head;

    int j;
    for (j = 1; j < i - 1; j++)
    {
        p = p->next;
        if (p == NULL)
        {
            break;
        }
    }
    
    if (p == NULL && (j < (i-1)))//指针为空且没有到第i个位置，说明不存在第i个结点
    {
        std::cout<<"插入位置无效！"<<endl;
        return false;
    }
    
    ListNode<DataType>* newNode = new ListNode<DataType>(newData);
    newNode->next = p->next; //将newNode的next指针赋值为p的后继结点地址
    p->next = newNode; //p的后继指针指向node

    return true;
}


/*******************删除指定结点*******************/
template <typename DataType>
bool LinkList<DataType>::removeNode(ListNode<DataType>* q)
{
    if (q == NULL)
    {
        cout << "错误参数" << endl;
        return false;
    }
    
    // 单链表要删除指定节点 就要找到他的前驱节点
    ListNode<DataType>* tempPoint = head;
    while (tempPoint->next != q)
    {
        tempPoint = tempPoint->next;
    }
    
    tempPoint->next = q->next;
    q->next = NULL;

    delete q;

    return true;
}


/*********************查找指定值的结点***************/
template<typename DataType>
ListNode<DataType>* LinkList<DataType>::findNode(DataType value)
{
    ListNode<DataType>* p = head;

    //判定游标指针所指结点的值是否与value相等
    while (p != NULL && p->data != value)
    {
        p = p->next;
    }
    if (p == NULL)
    {
        std::cout<<"没有找到该结点！程序异常退出！"<<endl;
        exit(1);
    }
    else
    {
        return p;
    }
}

/********************清空链表***********************/
template<typename DataType>
bool LinkList<DataType>::cleanLink()
{
    ListNode<DataType>* current = head;
    while(head->next != NULL)
    {
        current = head->next;  //将current指向head的后继结点
        head->next = current->next; //将current的后继地址赋值给head的next域
        delete current;        
    }
    return true;
}

template<typename DataType>
DataType LinkList<DataType>::getNodeData(ListNode<DataType> *p)
{
    if (p == NULL)
    {
        return NULL;
    }
    return p->data;
}