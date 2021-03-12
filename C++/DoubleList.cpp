template<typename DataType> class DoubleList; // 前向声明

/***************双向链表结点定义****************/
template<typename DataType> class DoubleListNode
{
public:
	DataType getData()
	{
		return this->m_data;
	}
private:
	friend class DoubleList<DataType>;
	DoubleListNode():m_pprior(NULL), m_pnext(NULL){}
	//带参数构造函数初始化数据域和指针域
	DoubleListNode(const DataType item, DoubleListNode<DataType>* prior = NULL, DoubleListNode<DataType>* next = NULL)
		:m_data(item),m_pprior(prior),m_pnext(next)
	{}

	// 析构函数
	~DoubleListNode()
	{
		m_pprior = NULL;
		m_pnext = NULL;
	}

private:
	DataType m_data;
	DataType* m_pprior;
	DataType* m_pnext;
};

/***********************双向链表定义**********************/
template<typename DataType> class DoubleList
{
public:
	DoubleList()
	{
		head = new DoubleListNode<DataType>();
	}
	~DoubleList()
	{
		cleanDoubleLink();
		delete head;
	}
public:
	void cleanDoubleLink();
	int getLength();
	DoubleListNode<DataType>* findNode(int i = 0);
	DoubleListNode<DataType>* findData(DataType item); //寻找具有给定值数据的结点
	bool insertNode(DataType item, int i = 0); //在第i个结点后插入新结点
	bool removeNode(int i=0);　                                         //删除第i个结点
	DataType getData(int i=0);　                                        //获取第i个结点的数据
private:
	DoubleListNode<DataType>* head;
};


/*********************清空链表*****************/
template<typename DataType> void DoubleList<DataType>::cleanDoubleLink()
{
	DoubleListNode<DataType>* pmove = head->m_pnext, *pdel;
	while(pmove != NULL)
	{
		pdel = pmove;
		pmove = pdel->m_pnext;
		delete pdel;
	}
	head->m_pnext = NULL;
}

/*******************获取链表长度********************/
template<typename DataType> int DoubleList<DataType>::getLength()
{
	int count = 0;
	DoubleListNode<DataType>* pmove = head->m_pnext;
	while(pmove != NULL)
	{
		pmove = pmove->m_pnext;
		count++;
	}
	return count;
}

/***************************获取第i个结点***********************/
template<typename DataType> DoubleListNode<DataType>* DoubleList
<DataType>::findNode(int n=1)
{
	if (n < 1 || n > getLength())
	{
        cout<<"非有效位置"<<endl;
        return NULL;
	}

	DoubleListNode<DataType>* pmove = head->m_pnext;
	for (int i = 1; i < n; i++)
	{
		pmove = pmove->next;

		if (pmove == NULL)
		{
            cout<<"不存在指定结点"<<endl;
            return NULL;
		}
	}
	return pmove;
}

/**********************在第i个结点之后插入新结点****************/