//
//  Store.hpp
//  多文件
//
//  Created by 李李李anl on 2020/4/16.
//  Copyright © 2020 李李李anl. All rights reserved.
//

#ifndef Store_hpp
#define Store_hpp

#include <stdio.h>

#endif /* Store_hpp */

using namespace std;
#include "Book.hpp"

class Store
{
//请在此处补充Store类的定义
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
