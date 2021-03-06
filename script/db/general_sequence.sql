--cat general_sequence.sql |tr [a-z] [A-Z]| sed  's/DBACCNEW\.//g'|sed '/SYNONYM/d'>general_sequence.sql.new

--@SERV--14位
CREATE SEQUENCE SERV_ID
  START WITH 100000000
  MAXVALUE 99999999999999
  MINVALUE 100000000
  NOCYCLE
  CACHE 20
  ORDER;

--@ACCT--14位
CREATE SEQUENCE ACCT_ID
  START WITH 100000000
  MAXVALUE 99999999999999
  MINVALUE 100000000
  NOCYCLE
  CACHE 20
  ORDER;

--@CUST--14位
CREATE SEQUENCE CUST_ID
  START WITH 100000000
  MAXVALUE 99999999999999
  MINVALUE 100000000
  NOCYCLE
  CACHE 20
  ORDER;

--@AGREEMENT_ID--14位
CREATE SEQUENCE AGREEMENT_ID
  START WITH 100000000
  MAXVALUE 99999999999999
  MINVALUE 100000000
  NOCYCLE
  CACHE 20
  ORDER;

--生成序列
CREATE SEQUENCE SCARDVCSN
  START WITH 0
  MAXVALUE 99999999
  MINVALUE 0
  CYCLE
  CACHE 20
  ORDER;


--@SPE_PAYMENT_ID--专款专用标识--9位
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

--@BALANCE_TYPE_ID--余额类型标识--9位
CREATE SEQUENCE BALANCE_TYPE_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;

--@BALANCE_SOURCE_ID--来源类型标识--9位
CREATE SEQUENCE BALANCE_SOURCE_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;

--@PRIVILEGE_ID--权限标识--9位
CREATE SEQUENCE PRIVILEGE_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;

--@STAFF_ID--员工标识--9位
CREATE SEQUENCE STAFF_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;


--@BANK_BRANCH_ID--银行分行标识--9位
CREATE SEQUENCE BANK_BRANCH_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;

--@BANK_ID--银行标识--9位
CREATE SEQUENCE BANK_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;

--@PAYMENT_METHOD_ID--付款方式--9位
CREATE SEQUENCE PAYMENT_METHOD_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;

--@DELAY_RULE_ID--滞纳金计算规则标识--9位
CREATE SEQUENCE DELAY_RULE_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;

--@DERATE_RULE_ID--滞纳金减免规则标识--9位
CREATE SEQUENCE DERATE_RULE_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;

--@PRESENT_RULE_ID--优惠赠送规则标识--14位
CREATE SEQUENCE PRESENT_RULE_ID
  START WITH 10000
  MAXVALUE 999999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;

--@BILL_ITEM_TYPE_ID--帐单项标识--9位
CREATE SEQUENCE BILL_ITEM_TYPE_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;

--@BILL_FORMAT_ID--帐单格式标识--9位
CREATE SEQUENCE BILL_FORMAT_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;

--@BILL_REMARK_ID--可变文本标识--9位
CREATE SEQUENCE BILL_REMARK_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;


--@BILL_VARIABLE_ID--帐单变量标识--9位
CREATE SEQUENCE BILL_VARIABLE_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;
   	

--@OWE_TIME_INFO_ID--处理时间信息标识--9位
CREATE SEQUENCE OWE_TIME_INFO_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;
   	

--@DATE_TYPE_ID--欠费时间类型标识--9位
CREATE SEQUENCE DATE_TYPE_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;
   	
--@OWE_BUSINESS_TYPE_ID--欠费业务类型标识--9位
CREATE SEQUENCE OWE_BUSINESS_TYPE_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;

--@OWE_TYPE_LIMIT_ID--欠费类型限额标识--9位
CREATE SEQUENCE OWE_TYPE_LIMIT_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;
   	
--@ACCT_ITEM_GROUP_ID--帐目组标识--9位
CREATE SEQUENCE ACCT_ITEM_GROUP_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;
   	
--@ACCT_ITEM_TYPE_ID--帐目类型标识--9位
CREATE SEQUENCE ACCT_ITEM_TYPE_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;

--@ITEM_SOURCE_ID--帐目来源标识--9位
CREATE SEQUENCE ITEM_SOURCE_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;
   	
--@ACCT_ITEM_CLASS_ID--帐目类型归类标识--9位
CREATE SEQUENCE ACCT_ITEM_CLASS_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;
   	
--@ATTR_GRP_ID--详单属性集合标识--9位
CREATE SEQUENCE ATTR_GRP_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;
   	
--@BILL_PARSE_ID--帐务解析标识--9位
CREATE SEQUENCE BILL_PARSE_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;
   	

--@BALANCE_RELATION_ID--余额对象账本关系标识--9位
CREATE SEQUENCE BALANCE_RELATION_ID
  START WITH 100000000
  MAXVALUE 999999999
  MINVALUE 100000000
  NOCYCLE
  CACHE 20
  ORDER;


--@ADDRESS_ID--地址标识--9位
CREATE SEQUENCE ADDRESS_ID
  START WITH 100000000
  MAXVALUE 999999999
  MINVALUE 100000000
  NOCYCLE
  CACHE 20
  ORDER;


--@BILL_RECORD_ID--帐单记录标识--9位
CREATE SEQUENCE BILL_RECORD_ID
  START WITH 100000000
  MAXVALUE 999999999
  MINVALUE 100000000
  NOCYCLE
  CACHE 20
  ORDER;


--@FAVOUR_PRESENT_ID--优惠赠送信息标识--14位
CREATE SEQUENCE FAVOUR_PRESENT_ID
  START WITH 100000000
  MAXVALUE 99999999999999
  MINVALUE 100000000
  NOCYCLE
  CACHE 20
  ORDER;


--@PRESENT_ID--赠送信息标识--14位
CREATE SEQUENCE PRESENT_ID
  START WITH 100000000
  MAXVALUE 99999999999999
  MINVALUE 100000000
  NOCYCLE
  CACHE 20
  ORDER;

--@BALANCE_PRESENT_ID--预存赠送信息标识--14位
CREATE SEQUENCE BALANCE_PRESENT_ID
  START WITH 100000000
  MAXVALUE 99999999999999
  MINVALUE 100000000
  NOCYCLE
  CACHE 20
  ORDER;

--@OWE_OBJECT_ID--欠费处理对象标识--9位
CREATE SEQUENCE OWE_OBJECT_ID
  START WITH 100000000
  MAXVALUE 999999999
  MINVALUE 100000000
  NOCYCLE
  CACHE 20
  ORDER;

--@CHARGE_ADJUST_LOG_ID--调帐日志标识--9位  
CREATE SEQUENCE CHARGE_ADJUST_LOG_ID
  START WITH 100000000
  MAXVALUE 999999999
  MINVALUE 100000000
  NOCYCLE
  CACHE 20
  ORDER;

--@ADJUST_RECORD_ID--调帐帐目标识--9位
CREATE SEQUENCE ADJUST_RECORD_ID
  START WITH 100000000
  MAXVALUE 999999999
  MINVALUE 100000000
  NOCYCLE
  CACHE 20
  ORDER;



--@REGION_ID--区域标识--10位
CREATE SEQUENCE REGION_ID
  START WITH 10000
  MAXVALUE 9999999999
  MINVALUE 10000
  NOCYCLE
  CACHE 20
  ORDER;


--@INTEGRAL_REAULT_ID--积分评估结果--12位
CREATE SEQUENCE INTEGRAL_REAULT_ID
  START WITH 100000000000
  MAXVALUE 999999999999
  MINVALUE 100000000000
  NOCYCLE
  CACHE 20
  ORDER;
  	

--@PAYMENT_PLAN_ID--支付方案标识--12位
CREATE SEQUENCE PAYMENT_PLAN_ID
  START WITH 100000000000
  MAXVALUE 999999999999
  MINVALUE 100000000000
  NOCYCLE
  CACHE 20
  ORDER;

--@INVOICE_ID--发票记录号--12位
CREATE SEQUENCE INVOICE_ID
  START WITH 100000000000
  MAXVALUE 999999999999
  MINVALUE 100000000000
  NOCYCLE
  CACHE 20
  ORDER;

--@BILL_FORMAT_CUSTOMIZE_ID--帐单定制标识--12位
CREATE SEQUENCE BILL_FORMAT_CUSTOMIZE_ID
  START WITH 100000000000
  MAXVALUE 999999999999
  MINVALUE 100000000000
  NOCYCLE
  CACHE 20
  ORDER;

--@BILL_FORMAT_SELECTOR_ID--帐单选择标识--12位
CREATE SEQUENCE BILL_FORMAT_SELECTOR_ID
  START WITH 100000000000
  MAXVALUE 999999999999
  MINVALUE 100000000000
  NOCYCLE
  CACHE 20
  ORDER;

--@OWE_TASK_ID--欠费处理任务标识--12位
CREATE SEQUENCE OWE_TASK_ID
  START WITH 100000000000
  MAXVALUE 999999999999
  MINVALUE 100000000000
  NOCYCLE
  CACHE 20
  ORDER;


--@LOGOUT_OP_SN--核销流水号--12位
CREATE SEQUENCE LOGOUT_OP_SN
  START WITH 100000000000
  MAXVALUE 999999999999
  MINVALUE 100000000000
  NOCYCLE
  CACHE 20
  ORDER;

--@ACCT_ITEM_ID--帐目标识--12位
CREATE SEQUENCE ACCT_ITEM_ID
  START WITH 100000000000
  MAXVALUE 999999999999
  MINVALUE 100000000000
  NOCYCLE
  CACHE 20
  ORDER;

--@AI_TOTAL_ID--帐目综合标识--14位
CREATE SEQUENCE AI_TOTAL_ID
  START WITH 100000000000
  MAXVALUE 99999999999999
  MINVALUE 100000000000
  NOCYCLE
  CACHE 20
  ORDER;

--@SERV_ACCT_ID--帐务定制关系标识--12位
CREATE SEQUENCE SERV_ACCT_ID
  START WITH 100004254882
  MAXVALUE 999999999999
  MINVALUE 100004254882
  NOCYCLE
  CACHE 20
  ORDER;



--@ACCT_BALANCE_ID--余额账本标识--14位
CREATE SEQUENCE ACCT_BALANCE_ID
  START WITH 10000000000000
  MAXVALUE 99999999999999
  MINVALUE 10000000000000
  NOCYCLE
  CACHE 20
  ORDER;

--@BATCH_OPER_SN--批量操作日志流水--14位
CREATE SEQUENCE BATCH_OPER_SN
  START WITH 10000000000000
  MAXVALUE 99999999999999
  MINVALUE 10000000000000
  NOCYCLE
  CACHE 20
  ORDER;


--@BILL_ID--销帐流水--14位
CREATE SEQUENCE BILL_ID
  START WITH 10000000000000
  MAXVALUE 99999999999999
  MINVALUE 10000000000000
  NOCYCLE
  CACHE 20
  ORDER;
  	
--@PAY_SN--付款/缴费流水--14位
CREATE SEQUENCE PAY_SN
  START WITH 10000000000000
  MAXVALUE 99999999999999
  MINVALUE 10000000000000
  NOCYCLE
  CACHE 20
  ORDER;

--@OPER_PAYOUT_ID--余额支出操作流水--14位
CREATE SEQUENCE OPER_PAYOUT_ID
  START WITH 10000000000000
  MAXVALUE 99999999999999
  MINVALUE 10000000000000
  NOCYCLE
  CACHE 20
  ORDER;
  	
--@OPER_INCOME_ID--余额来源操作流水--14位
CREATE SEQUENCE OPER_INCOME_ID
  START WITH 10000000000000
  MAXVALUE 99999999999999
  MINVALUE 10000000000000
  NOCYCLE
  CACHE 20
  ORDER;


--@ZT_OWE_TOTAL_ID--在途资料表--14位
CREATE SEQUENCE ZT_OWE_TOTAL_ID
  START WITH 10000000000000
  MAXVALUE 99999999999999
  MINVALUE 10000000000000
  NOCYCLE
  CACHE 20
  ORDER;

--@DELAY_FAV_ID--滞纳金优惠记录标识--14位
CREATE SEQUENCE DELAY_FAV_ID
  START WITH 10000000000000
  MAXVALUE 99999999999999
  MINVALUE 10000000000000
  NOCYCLE
  CACHE 20
  ORDER;


--@PAY_INTERFACE_ID--缴费接口操作流水--14位
CREATE SEQUENCE PAY_INTERFACE_ID
  START WITH 10000000000000
  MAXVALUE 99999999999999
  MINVALUE 10000000000000
  NOCYCLE
  CACHE 20
  ORDER;

--@SEND_MSG_SN--发短信流水--14位
CREATE SEQUENCE SEND_MSG_SN
  START WITH 10000000000000
  MAXVALUE 99999999999999
  MINVALUE 10000000000000
  NOCYCLE
  CACHE 20
  ORDER;


--@CREDIT_RESULT_ID--信誉评估结果主键--12位
CREATE SEQUENCE CREDIT_RESULT_ID
  START WITH 100000000000
  MAXVALUE 999999999999
  MINVALUE 100000000000
  NOCYCLE
  CACHE 20
  ORDER;

--@PARTY_ID--合作伙伴主键流水--9位
CREATE SEQUENCE PARTY_ID
  START WITH 100000000
  MAXVALUE 999999999
  MINVALUE 100000000
  NOCYCLE
  CACHE 20
  ORDER;

--@PAYINFO_ID--CRM缴费业务接口表流水--14位
CREATE SEQUENCE PAYINFO_ID
  START WITH 10000000000000
  MAXVALUE 99999999999999
  MINVALUE 10000000000000
  NOCYCLE
  CACHE 20
  ORDER;

--@TRANSFER_ACCOUNT_ID--付费计划变更业务接口表流水--14位
CREATE SEQUENCE TRANSFER_ACCOUNT_ID
  START WITH 10000000000000
  MAXVALUE 99999999999999
  MINVALUE 10000000000000
  NOCYCLE
  CACHE 20
  ORDER;

--@BILL_UNOWNER_ID--无主流水--14位
CREATE SEQUENCE BILL_UNOWNER_ID
  START WITH 10000000000000
  MAXVALUE 99999999999999
  MINVALUE 10000000000000
  NOCYCLE
  CACHE 20
  ORDER;  

--@LOGICAL_ADDRESS_ID--无主流水--9位
CREATE SEQUENCE LOGICAL_ADDRESS_ID
  START WITH 100000000
  MAXVALUE 999999999
  MINVALUE 100000000
  NOCYCLE
  CACHE 20
  ORDER;  

--@SERV_ADD_ACC_NBR--主产品实例附加号码流水--14位
CREATE SEQUENCE SERV_ADD_ACC_NBR_ID
  START WITH 10000000000000
  MAXVALUE 99999999999999
  MINVALUE 10000000000000
  NOCYCLE
  CACHE 20
  ORDER;  

--@BATCH_OPER_SN--余额账本操作流水--14位
CREATE SEQUENCE MMDB_ACCT_BALANCE_INC_OPSN
  START WITH 10000000000000
  MAXVALUE 99999999999999
  MINVALUE 10000000000000
  NOCYCLE
  CACHE 20
  ORDER;
