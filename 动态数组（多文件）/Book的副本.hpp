//
//  Book.hpp
//  多文件
//
//  Created by 李李李anl on 2020/4/16.
//  Copyright © 2020 李李李anl. All rights reserved.
//

#ifndef Book_hpp
#define Book_hpp

#include <stdio.h>
#include <iostream>
using namespace std;
#endif /* Book_hpp */


class Book
{
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
