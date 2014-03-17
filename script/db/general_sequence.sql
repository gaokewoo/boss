--cat general_sequence.sql |tr [a-z] [A-Z]| sed  's/DBACCNEW\.//g'|sed '/SYNONYM/d'>general_sequence.sql.new

--@SERV--14λ
CREATE SEQUENCE SERV_ID
  START WITH 100000000
  MAXVALUE 99999999999999
  MINVALUE 100000000
  NOCYCLE
  CACHE 20
  ORDER;

--@ACCT--14λ
CREATE SEQUENCE ACCT_ID
  START WITH 100000000
  MAXVALUE 99999999999999
  MINVALUE 100000000
  NOCYCLE
  CACHE 20
  ORDER;

--@CUST--14λ
CREATE SEQUENCE CUST_ID
  START WITH 100000000
  MAXVALUE 99999999999999
  MINVALUE 100000000
  NOCYCLE
  CACHE 20
  ORDER;

--@AGREEMENT_ID--14λ
CREATE SEQUENCE AGREEMENT_ID
  START WITH 100000000
  MAXVALUE 99999999999999
  MINVALUE 100000000
  NOCYCLE
  CACHE 20
  ORDER;

--��������
CREATE SEQUENCE SCARDVCSN
  START WITH 0
  MAXVALUE 99999999
  MINVALUE 0
  CYCLE
  CACHE 20
  ORDER;


--@SPE_PAYMENT_ID--ר��ר�ñ�ʶ--9λ
CREATE SEQUENCE SPE_PAYMENT_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;

CREATE SEQUENCE SBATCHACCEPT
  START WITH 143475
  MAXVALUE 99999999999999
  MINVALUE 1
  NOCYCLE
  CACHE 20
  NOORDER; 

--@BALANCE_TYPE_ID--������ͱ�ʶ--9λ
CREATE SEQUENCE BALANCE_TYPE_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;

--@BALANCE_SOURCE_ID--��Դ���ͱ�ʶ--9λ
CREATE SEQUENCE BALANCE_SOURCE_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;

--@PRIVILEGE_ID--Ȩ�ޱ�ʶ--9λ
CREATE SEQUENCE PRIVILEGE_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;

--@STAFF_ID--Ա����ʶ--9λ
CREATE SEQUENCE STAFF_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;


--@BANK_BRANCH_ID--���з��б�ʶ--9λ
CREATE SEQUENCE BANK_BRANCH_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;

--@BANK_ID--���б�ʶ--9λ
CREATE SEQUENCE BANK_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;

--@PAYMENT_METHOD_ID--���ʽ--9λ
CREATE SEQUENCE PAYMENT_METHOD_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;

--@DELAY_RULE_ID--���ɽ��������ʶ--9λ
CREATE SEQUENCE DELAY_RULE_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;

--@DERATE_RULE_ID--���ɽ��������ʶ--9λ
CREATE SEQUENCE DERATE_RULE_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;

--@PRESENT_RULE_ID--�Ż����͹����ʶ--14λ
CREATE SEQUENCE PRESENT_RULE_ID
  START WITH 10000
  MAXVALUE 999999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;

--@BILL_ITEM_TYPE_ID--�ʵ����ʶ--9λ
CREATE SEQUENCE BILL_ITEM_TYPE_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;

--@BILL_FORMAT_ID--�ʵ���ʽ��ʶ--9λ
CREATE SEQUENCE BILL_FORMAT_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;

--@BILL_REMARK_ID--�ɱ��ı���ʶ--9λ
CREATE SEQUENCE BILL_REMARK_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;


--@BILL_VARIABLE_ID--�ʵ�������ʶ--9λ
CREATE SEQUENCE BILL_VARIABLE_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;
   	

--@OWE_TIME_INFO_ID--����ʱ����Ϣ��ʶ--9λ
CREATE SEQUENCE OWE_TIME_INFO_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;
   	

--@DATE_TYPE_ID--Ƿ��ʱ�����ͱ�ʶ--9λ
CREATE SEQUENCE DATE_TYPE_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;
   	
--@OWE_BUSINESS_TYPE_ID--Ƿ��ҵ�����ͱ�ʶ--9λ
CREATE SEQUENCE OWE_BUSINESS_TYPE_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;

--@OWE_TYPE_LIMIT_ID--Ƿ�������޶��ʶ--9λ
CREATE SEQUENCE OWE_TYPE_LIMIT_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;
   	
--@ACCT_ITEM_GROUP_ID--��Ŀ���ʶ--9λ
CREATE SEQUENCE ACCT_ITEM_GROUP_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;
   	
--@ACCT_ITEM_TYPE_ID--��Ŀ���ͱ�ʶ--9λ
CREATE SEQUENCE ACCT_ITEM_TYPE_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;

--@ITEM_SOURCE_ID--��Ŀ��Դ��ʶ--9λ
CREATE SEQUENCE ITEM_SOURCE_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;
   	
--@ACCT_ITEM_CLASS_ID--��Ŀ���͹����ʶ--9λ
CREATE SEQUENCE ACCT_ITEM_CLASS_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;
   	
--@ATTR_GRP_ID--�굥���Լ��ϱ�ʶ--9λ
CREATE SEQUENCE ATTR_GRP_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;
   	
--@BILL_PARSE_ID--���������ʶ--9λ
CREATE SEQUENCE BILL_PARSE_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;
   	

--@BALANCE_RELATION_ID--�������˱���ϵ��ʶ--9λ
CREATE SEQUENCE BALANCE_RELATION_ID
  START WITH 100000000
  MAXVALUE 999999999
  MINVALUE 100000000
  NOCYCLE
  CACHE 20
  ORDER;


--@ADDRESS_ID--��ַ��ʶ--9λ
CREATE SEQUENCE ADDRESS_ID
  START WITH 100000000
  MAXVALUE 999999999
  MINVALUE 100000000
  NOCYCLE
  CACHE 20
  ORDER;


--@BILL_RECORD_ID--�ʵ���¼��ʶ--9λ
CREATE SEQUENCE BILL_RECORD_ID
  START WITH 100000000
  MAXVALUE 999999999
  MINVALUE 100000000
  NOCYCLE
  CACHE 20
  ORDER;


--@FAVOUR_PRESENT_ID--�Ż�������Ϣ��ʶ--14λ
CREATE SEQUENCE FAVOUR_PRESENT_ID
  START WITH 100000000
  MAXVALUE 99999999999999
  MINVALUE 100000000
  NOCYCLE
  CACHE 20
  ORDER;


--@PRESENT_ID--������Ϣ��ʶ--14λ
CREATE SEQUENCE PRESENT_ID
  START WITH 100000000
  MAXVALUE 99999999999999
  MINVALUE 100000000
  NOCYCLE
  CACHE 20
  ORDER;

--@BALANCE_PRESENT_ID--Ԥ��������Ϣ��ʶ--14λ
CREATE SEQUENCE BALANCE_PRESENT_ID
  START WITH 100000000
  MAXVALUE 99999999999999
  MINVALUE 100000000
  NOCYCLE
  CACHE 20
  ORDER;

--@OWE_OBJECT_ID--Ƿ�Ѵ��������ʶ--9λ
CREATE SEQUENCE OWE_OBJECT_ID
  START WITH 100000000
  MAXVALUE 999999999
  MINVALUE 100000000
  NOCYCLE
  CACHE 20
  ORDER;

--@CHARGE_ADJUST_LOG_ID--������־��ʶ--9λ  
CREATE SEQUENCE CHARGE_ADJUST_LOG_ID
  START WITH 100000000
  MAXVALUE 999999999
  MINVALUE 100000000
  NOCYCLE
  CACHE 20
  ORDER;

--@ADJUST_RECORD_ID--������Ŀ��ʶ--9λ
CREATE SEQUENCE ADJUST_RECORD_ID
  START WITH 100000000
  MAXVALUE 999999999
  MINVALUE 100000000
  NOCYCLE
  CACHE 20
  ORDER;



--@REGION_ID--�����ʶ--10λ
CREATE SEQUENCE REGION_ID
  START WITH 10000
  MAXVALUE 9999999999
  MINVALUE 10000
  NOCYCLE
  CACHE 20
  ORDER;


--@INTEGRAL_REAULT_ID--�����������--12λ
CREATE SEQUENCE INTEGRAL_REAULT_ID
  START WITH 100000000000
  MAXVALUE 999999999999
  MINVALUE 100000000000
  NOCYCLE
  CACHE 20
  ORDER;
  	

--@PAYMENT_PLAN_ID--֧��������ʶ--12λ
CREATE SEQUENCE PAYMENT_PLAN_ID
  START WITH 100000000000
  MAXVALUE 999999999999
  MINVALUE 100000000000
  NOCYCLE
  CACHE 20
  ORDER;

--@INVOICE_ID--��Ʊ��¼��--12λ
CREATE SEQUENCE INVOICE_ID
  START WITH 100000000000
  MAXVALUE 999999999999
  MINVALUE 100000000000
  NOCYCLE
  CACHE 20
  ORDER;

--@BILL_FORMAT_CUSTOMIZE_ID--�ʵ����Ʊ�ʶ--12λ
CREATE SEQUENCE BILL_FORMAT_CUSTOMIZE_ID
  START WITH 100000000000
  MAXVALUE 999999999999
  MINVALUE 100000000000
  NOCYCLE
  CACHE 20
  ORDER;

--@BILL_FORMAT_SELECTOR_ID--�ʵ�ѡ���ʶ--12λ
CREATE SEQUENCE BILL_FORMAT_SELECTOR_ID
  START WITH 100000000000
  MAXVALUE 999999999999
  MINVALUE 100000000000
  NOCYCLE
  CACHE 20
  ORDER;

--@OWE_TASK_ID--Ƿ�Ѵ��������ʶ--12λ
CREATE SEQUENCE OWE_TASK_ID
  START WITH 100000000000
  MAXVALUE 999999999999
  MINVALUE 100000000000
  NOCYCLE
  CACHE 20
  ORDER;


--@LOGOUT_OP_SN--������ˮ��--12λ
CREATE SEQUENCE LOGOUT_OP_SN
  START WITH 100000000000
  MAXVALUE 999999999999
  MINVALUE 100000000000
  NOCYCLE
  CACHE 20
  ORDER;

--@ACCT_ITEM_ID--��Ŀ��ʶ--12λ
CREATE SEQUENCE ACCT_ITEM_ID
  START WITH 100000000000
  MAXVALUE 999999999999
  MINVALUE 100000000000
  NOCYCLE
  CACHE 20
  ORDER;

--@AI_TOTAL_ID--��Ŀ�ۺϱ�ʶ--14λ
CREATE SEQUENCE AI_TOTAL_ID
  START WITH 100000000000
  MAXVALUE 99999999999999
  MINVALUE 100000000000
  NOCYCLE
  CACHE 20
  ORDER;

--@SERV_ACCT_ID--�����ƹ�ϵ��ʶ--12λ
CREATE SEQUENCE SERV_ACCT_ID
  START WITH 100004254882
  MAXVALUE 999999999999
  MINVALUE 100004254882
  NOCYCLE
  CACHE 20
  ORDER;



--@ACCT_BALANCE_ID--����˱���ʶ--14λ
CREATE SEQUENCE ACCT_BALANCE_ID
  START WITH 10000000000000
  MAXVALUE 99999999999999
  MINVALUE 10000000000000
  NOCYCLE
  CACHE 20
  ORDER;

--@BATCH_OPER_SN--����������־��ˮ--14λ
CREATE SEQUENCE BATCH_OPER_SN
  START WITH 10000000000000
  MAXVALUE 99999999999999
  MINVALUE 10000000000000
  NOCYCLE
  CACHE 20
  ORDER;


--@BILL_ID--������ˮ--14λ
CREATE SEQUENCE BILL_ID
  START WITH 10000000000000
  MAXVALUE 99999999999999
  MINVALUE 10000000000000
  NOCYCLE
  CACHE 20
  ORDER;
  	
--@PAY_SN--����/�ɷ���ˮ--14λ
CREATE SEQUENCE PAY_SN
  START WITH 10000000000000
  MAXVALUE 99999999999999
  MINVALUE 10000000000000
  NOCYCLE
  CACHE 20
  ORDER;

--@OPER_PAYOUT_ID--���֧��������ˮ--14λ
CREATE SEQUENCE OPER_PAYOUT_ID
  START WITH 10000000000000
  MAXVALUE 99999999999999
  MINVALUE 10000000000000
  NOCYCLE
  CACHE 20
  ORDER;
  	
--@OPER_INCOME_ID--�����Դ������ˮ--14λ
CREATE SEQUENCE OPER_INCOME_ID
  START WITH 10000000000000
  MAXVALUE 99999999999999
  MINVALUE 10000000000000
  NOCYCLE
  CACHE 20
  ORDER;


--@ZT_OWE_TOTAL_ID--��;���ϱ�--14λ
CREATE SEQUENCE ZT_OWE_TOTAL_ID
  START WITH 10000000000000
  MAXVALUE 99999999999999
  MINVALUE 10000000000000
  NOCYCLE
  CACHE 20
  ORDER;

--@DELAY_FAV_ID--���ɽ��Żݼ�¼��ʶ--14λ
CREATE SEQUENCE DELAY_FAV_ID
  START WITH 10000000000000
  MAXVALUE 99999999999999
  MINVALUE 10000000000000
  NOCYCLE
  CACHE 20
  ORDER;


--@PAY_INTERFACE_ID--�ɷѽӿڲ�����ˮ--14λ
CREATE SEQUENCE PAY_INTERFACE_ID
  START WITH 10000000000000
  MAXVALUE 99999999999999
  MINVALUE 10000000000000
  NOCYCLE
  CACHE 20
  ORDER;

--@SEND_MSG_SN--��������ˮ--14λ
CREATE SEQUENCE SEND_MSG_SN
  START WITH 10000000000000
  MAXVALUE 99999999999999
  MINVALUE 10000000000000
  NOCYCLE
  CACHE 20
  ORDER;


--@CREDIT_RESULT_ID--���������������--12λ
CREATE SEQUENCE CREDIT_RESULT_ID
  START WITH 100000000000
  MAXVALUE 999999999999
  MINVALUE 100000000000
  NOCYCLE
  CACHE 20
  ORDER;

--@PARTY_ID--�������������ˮ--9λ
CREATE SEQUENCE PARTY_ID
  START WITH 100000000
  MAXVALUE 999999999
  MINVALUE 100000000
  NOCYCLE
  CACHE 20
  ORDER;

--@PAYINFO_ID--CRM�ɷ�ҵ��ӿڱ���ˮ--14λ
CREATE SEQUENCE PAYINFO_ID
  START WITH 10000000000000
  MAXVALUE 99999999999999
  MINVALUE 10000000000000
  NOCYCLE
  CACHE 20
  ORDER;

--@TRANSFER_ACCOUNT_ID--���Ѽƻ����ҵ��ӿڱ���ˮ--14λ
CREATE SEQUENCE TRANSFER_ACCOUNT_ID
  START WITH 10000000000000
  MAXVALUE 99999999999999
  MINVALUE 10000000000000
  NOCYCLE
  CACHE 20
  ORDER;

--@BILL_UNOWNER_ID--������ˮ--14λ
CREATE SEQUENCE BILL_UNOWNER_ID
  START WITH 10000000000000
  MAXVALUE 99999999999999
  MINVALUE 10000000000000
  NOCYCLE
  CACHE 20
  ORDER;  

--@LOGICAL_ADDRESS_ID--������ˮ--9λ
CREATE SEQUENCE LOGICAL_ADDRESS_ID
  START WITH 100000000
  MAXVALUE 999999999
  MINVALUE 100000000
  NOCYCLE
  CACHE 20
  ORDER;  

--@SERV_ADD_ACC_NBR--����Ʒʵ�����Ӻ�����ˮ--14λ
CREATE SEQUENCE SERV_ADD_ACC_NBR_ID
  START WITH 10000000000000
  MAXVALUE 99999999999999
  MINVALUE 10000000000000
  NOCYCLE
  CACHE 20
  ORDER;  

--@BATCH_OPER_SN--����˱�������ˮ--14λ
CREATE SEQUENCE MMDB_ACCT_BALANCE_INC_OPSN
  START WITH 10000000000000
  MAXVALUE 99999999999999
  MINVALUE 10000000000000
  NOCYCLE
  CACHE 20
  ORDER;