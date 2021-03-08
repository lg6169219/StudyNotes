#include <iostream>
#include <string.h>
using namespace std;

/******线性表数据结构*********/
const int defalutSize = 10;     //设置默认顺序表大小
template<typename DataType> class SeqList
{
public:
    SeqList(int size = defalutSize)
    {
        if (size > 0)   //检查赋予的顺序表大小，如果合法则分配相应大小的内存
        {
            maxSize = size;
            length = 0;
            elements = new DataType[maxSize];
            memset(elements, 0, sizeof(DataType)*maxSize);
        }
        
    }
    ~SeqList()
    {
        delete[] elements;
    }
    bool resize(); // 扩容
    bool insertElement(DataType data);  //向表尾插入新元素
    bool deleteElement(int location);   //删除指定位置的元素
    DataType getElement(int location);  //返回指定位置的元素
    bool changeElement(int location, DataType newData); //修改指定位置的元素值
    void printAll();
    int getLength()
    {
        return length;
    }
private:
    DataType *elements;
    int maxSize;    //顺序表最大大小
    int length; //顺序表的有效长度
};

/**************扩容********************/
template <typename DataType>
bool SeqList<DataType>::resize()
{
    int newSize = maxSize * 1.5;
    DataType* newList = new DataType[newSize];
    if(!newList)
        return false;

    for(int i = 0; i < length; ++i)
    {
        newList[i] = elements[i];
    }

    maxSize = newSize;
    delete[] elements;

    elements = newList;

    return true;
}


/***************顺序表插入操作********************/
/*
顺序表的插入操作就是向顺序表的表尾插入新的元素，可以分为两个步骤来进行。
（1）检查顺序表是否已满，如果已满则进行提示并拒绝执行插入操作
    或者给表扩容，分配1.5~2倍的新空间，将老数据拷贝过去，并插入新数据
（2）如果顺序表未满，则将新元素插入表尾空间中，并将顺序表的有效大小加1。
*/
template <typename DataType>
bool SeqList<DataType>::insertElement(DataType data)
{
    if (length >= maxSize)
    {
        bool bRes = resize();
        if (!bRes)
        {
           return false;
        }
    }
    
    elements[length++] = data;
    
    return true;
}

/**************删除指定位置的元素********************/
template <typename DataType>
bool SeqList<DataType>::deleteElement(int location)
{
    // 1、传入参数检查
    if (location < 0 || location >= length)
    {
        return false;
    }
    
    // 2、将从location开始，之后的数据前移1位
    for (size_t i = location; i < length; i++)
    {
        elements[i] = elements[i+1];
    }
    // 3、长度减1
    length--;
    return true;
}

/**************获取指定位置的元素*********************/
template <typename DataType>
DataType SeqList<DataType>::getElement(int location)
{
    if (location < 0 || location >= length)
    {
        return NULL;
    }

    return elements[location];
}

/**************修改指定位置的元素值********************/
template <typename DataType>
bool SeqList<DataType>::changeElement(int location, DataType newData)
{
    if (location < 0 || location >= length)
    {
        return false;
    }

    elements[location] = newData;

    return true;
}


/*************************实际应用************************/
/**
 * 1.1用C++实现一个顺序表，使其可存储10个整型数据，
 * 并可实现插入、修改元素、删除元素和输出整个顺序表的功能。
 * */ 
template <typename DataType>
void SeqList<DataType>::printAll()
{
    cout << "printAll: ";
    for (int i = 0; i < length; i++)
    {
        cout << elements[i] << " ";
    }
    cout << endl;
}


int main()
{
    SeqList<int> list(10);//建立顺序表
    for (int i = 0; i < list.getLength(); i++)
    {
        list.insertElement(i*10);
    }
    //输出初始化后的顺序表
    list.printAll();
    //删除索引为3的元素
    list.deleteElement(3);
    //输出删除元素后的顺序表
    list.printAll();
    //将顺序表索引为5的元素值修改为44
    list.changeElement(5, 44);
    //输出修改后的顺序表
    list.printAll();

    return 0;
}