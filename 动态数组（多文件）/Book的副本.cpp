//
//  Book.cpp
//  多文件
//
//  Created by 李李李anl on 2020/4/16.
//  Copyright © 2020 李李李anl. All rights reserved.
//

#include "Book.hpp"


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
Book::~Book() {}
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
