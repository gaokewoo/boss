#include "PersonalOweScheme.hh"

string PersonalOweScheme::insSQL="INSERT INTO PERSONAL_OWE_SCHEME(SERV_ID,OB_SCHEME_ID,ACC_NBR,AWAKE_STEP,AWAKE_TIMES,BEGIN_HM,END_HM,EFFECT_MARK,LIMIT_CALL_STEP,STAFF_ID,OPER_TIME,STATE,EFF_DATE,EXP_DATE,COMMENTS)VALUES (:SERV_ID,:OB_SCHEME_ID,:ACC_NBR,:AWAKE_STEP,:AWAKE_TIMES,:BEGIN_HM,:END_HM,:EFFECT_MARK,:LIMIT_CALL_STEP,:STAFF_ID,SYSDATE,:STATE,SYSDATE,SYSDATE,:COMMENTS)";

void PersonalOweScheme::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void PersonalOweScheme::prepareSQL()
{
    stmt->setNumber(1,personal_owe_scheme.m_serv_id);
    stmt->setNumber(2,personal_owe_scheme.m_ob_scheme_id);
    stmt->setString(3,personal_owe_scheme.m_acc_nbr);
    stmt->setNumber(4,personal_owe_scheme.m_awake_step);
    stmt->setNumber(5,personal_owe_scheme.m_awake_times);
    stmt->setString(6,personal_owe_scheme.m_begin_hm);
    stmt->setString(7,personal_owe_scheme.m_end_hm);
    stmt->setString(8,personal_owe_scheme.m_effect_mark);
    stmt->setNumber(9,personal_owe_scheme.m_limit_call_step);
    stmt->setNumber(10,personal_owe_scheme.m_staff_id);
    stmt->setString(11,personal_owe_scheme.m_state);
    stmt->setString(12,personal_owe_scheme.m_comments);
}

