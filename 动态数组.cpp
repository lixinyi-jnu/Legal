#include <iostream>
using namespace std;
class Book
{
//请在此处补充Book类的定义
public:
    unsigned int GetID();
    void SetID(unsigned int a);
    string GetName();
    void SetName(string a);
    string GetIntroduction();
    void SetIntroduction(string a);
    string GetAuthor();
    void SetAuthor(string a);
    string GetDate();
    void SetDate(string a);
    unsigned int GetPage();
    void SetPage(unsigned int a);
    Book();
    virtual ~Book();
    Book(const Book &other);
private:
    unsigned int m_ID;
    string m_Name;
    string m_Introduction;
    string m_Author;
    string m_Date;
    unsigned int m_Page;

};
//请在此处补充Book类的成员函数实现
Book::Book()
{
    m_ID = 0;
}
Book::Book(const Book& other)
{
    this->m_ID = other.m_ID;
    this->m_Name = other.m_Name;
    this->m_Introduction = other.m_Introduction;
    this->m_Author = other.m_Author;
    this->m_Date = other.m_Date;
    this->m_Page = other.m_Page;
}
Book::~Book()
{
    
}
unsigned int Book::GetID(){return m_ID;}
void Book::SetID(unsigned int a){m_ID = a;}
string Book::GetName(){return m_Name;}
void Book::SetName(string a){m_Name = a;}
string Book::GetIntroduction(){return m_Introduction;}
void Book::SetIntroduction(string a){m_Introduction = a;}
string Book:: GetAuthor(){return m_Author;}
void Book:: SetAuthor(string a){m_Author = a;}
string Book:: GetDate(){return m_Date;}
void Book::SetDate(string a){m_Date = a;}
unsigned int Book::GetPage(){return m_Page;}
void Book::SetPage(unsigned int a){m_Page = a;}

class Store
{
public:
    unsigned int GetCount();
    void SetCount(unsigned int a);
    Store();
    Store(int n);
    virtual ~Store();
    Store(const Store&other);
    void in(Book &b);
    void out(string name);
    Book findbyID(int ID);
    Book findbyName(string name);
    void printList();
private:
    Book *m_pBook;
    unsigned int m_Count;
};


unsigned int Store::GetCount()
{
    return m_Count;
}
void Store::SetCount(unsigned int a)
{
    m_Count = a;
}
Store::Store()
{
    m_Count = 0;
    m_pBook = 0;
    cout<<"Store default constructor called!"<<endl;
}
Store:: Store(int n)
{
    m_pBook = new Book[n];
    cout<<"Store constructor with (int n) called!"<<endl;
}
Store:: ~Store()
{
    m_Count = 0;
    if(m_pBook!=0)
        delete []m_pBook;
    cout<<"Store destructor called!"<<endl;
}
Store:: Store(const Store&other)
{
    m_pBook = other.m_pBook;
    m_Count = other.m_Count;
    cout<<"Store copy constructor called!"<<endl;
}
void Store::in(Book &b)
{
    m_Count++;
    Book *temp = new Book[m_Count];
    for(int i=0;i<int(m_Count-1);i++)
        temp[i]=m_pBook[i];
    temp[m_Count-1] = b;
    delete []m_pBook;
    m_pBook = temp;
}
void Store::out(string name)
{
    m_Count--;
    int i,k=0;
    Book *temp = new Book[m_Count];
    for(i=0;i<int(m_Count+1);i++)
    {
        if(m_pBook[i].GetName()==name)
            continue;
        else
            temp[k++]=m_pBook[i];
    }
    delete[] m_pBook;
    m_pBook = temp;
}
Book Store:: findbyID(int ID)
{
    int i;
    for(i=0;i<int(m_Count);i++)
        if(int(m_pBook[i].GetID())==ID)
            break;
    if(i<int(m_Count))
        return m_pBook[i];
    else
    {
        Book b;
        return b;
    }
}
Book Store:: findbyName(string name)
{
    int i;
    for(i=0;i<int(m_Count);i++)
        if(m_pBook[i].GetName()==name)
            break;
    if(i<int(m_Count))
        return m_pBook[i];
    else
    {
        Book b;
        return b;
    }
}
void Store:: printList()
{
    cout<<"There are totally "<<int(GetCount())<<" Books:"<<endl;
    int i;
    for(i=0;i<int(GetCount());i++)
            cout<<"ID="<<m_pBook[i].GetID()<<";"<<"  Name:"<<m_pBook[i].GetName()<<";"<<"  Author:"<<m_pBook[i].GetAuthor()<<";"<<"  Date:"<<m_pBook[i].GetDate()<<";"<<endl;
}


int main()
{
    Store s;
    Book b1,b2,b3;
    b1.SetID(1);
    b1.SetName("C++ 语言程序设计(第4版)");
    b1.SetAuthor("郑莉");
    b1.SetIntroduction("介绍C++及面向对象的知识");
    b1.SetDate("201007");
    b1.SetPage(529);
    b2.SetID(2);
    b2.SetName("离散数学");
    b2.SetAuthor("左孝凌");
    b2.SetIntroduction("介绍命题逻辑、谓词逻辑、集合论、代数系统和图论");
    b2.SetDate("198209");
    b2.SetPage(305);
    b3.SetID(3);
    b3.SetName("c程序设计");
    b3.SetAuthor("谭浩强");
    b3.SetIntroduction("介绍C程序设计中的基本知识，如语句格式、语法等");
    b3.SetDate("201006");
    b3.SetPage(355);

    cout<<"第一本书入库"<<endl;
    s.in(b1);
    cout<<"第二本书入库"<<endl;
    s.in(b2);
    cout<<"第三本书入库"<<endl;
    s.in(b3);
    cout <<"现有库存书籍数量："<<s.GetCount() << endl;
    cout <<"查找并出库图书：离散数学" << endl;
    Book tmpbook=s.findbyName("离散数学");
    if(tmpbook.GetID()!=0)
    {
        s.out("离散数学");
        cout <<"离散数学 已成功出库" << endl;
    }
    else
        cout<<"没有找到name为离散数学的书"<<endl;
    cout <<"现有库存书籍数量："<<s.GetCount() << endl;

    cout <<"查找图书 ID：3" << endl;
    tmpbook=s.findbyID(3);
    if(tmpbook.GetID()!=0)
        cout<<"找到ID为"<<3<<"的书，书名："<<tmpbook.GetName()<<endl;
    else
        cout<<"没有找到ID为"<<3<<"的书"<<endl;

    cout <<"查找图书 name：离散数学" << endl;
    tmpbook=s.findbyName("离散数学");
    if(tmpbook.GetID()!=0)
        cout<<"找到name为离散数学的书，ID："<<tmpbook.GetID()<<endl;
    else
        cout<<"没有找到name为离散数学的书"<<endl;

    cout<<"输出所有库存图书的信息"<<endl;
    s.printList();
    cout<<"程序运行结束"<<endl;
    return 0;
}

