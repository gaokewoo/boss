#ifndef __SERVGRADECODE__
#define __SERVGRADECODE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class ServGradeCode:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_SERV_GRADE_CODE serv_grade_code;

private:
    static string insSQL;
};
#endif
