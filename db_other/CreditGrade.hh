#ifndef __CREDITGRADE__
#define __CREDITGRADE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class CreditGrade:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_CREDIT_GRADE credit_grade;

private:
    static string insSQL;
};
#endif
