//
//  Store.cpp
//  多文件
//
//  Created by 李李李anl on 2020/4/16.
//  Copyright © 2020 李李李anl. All rights reserved.
//

#include "Store.hpp"
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
    m_Count = n;
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
    m_Count = other.m_Count;
    m_pBook = new Book[m_Count];
    for(int i=0;i<m_Count;i++)
        m_pBook[i]=other.m_pBook[i];
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
