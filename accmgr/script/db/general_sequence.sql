--生成序列
CREATE SEQUENCE dbaccnew.sCardVcSn
  START WITH 0
  MAXVALUE 99999999
  MINVALUE 0
  CYCLE
  CACHE 20
  ORDER;

CREATE PUBLIC SYNONYM sCardVcSn FOR DBACCNEW.sCardVcSn;

--@SPE_PAYMENT_ID--专款专用标识--9位
CREATE SEQUENCE DBACCNEW.SPE_PAYMENT_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;
CREATE  OR REPLACE PUBLIC SYNONYM SPE_PAYMENT_ID For DBACCNEW.SPE_PAYMENT_ID;

CREATE SEQUENCE DBACCNEW.SBATCHACCEPT
  START WITH 143475
  MAXVALUE 99999999999999
  MINVALUE 1
  NOCYCLE
  CACHE 20
  NOORDER; 
CREATE OR REPLACE PUBLIC SYNONYM SBATCHACCEPT FOR DBACCNEW.SBATCHACCEPT;

--@BALANCE_TYPE_ID--余额类型标识--9位
CREATE SEQUENCE DBACCNEW.BALANCE_TYPE_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM BALANCE_TYPE_ID For DBACCNEW.BALANCE_TYPE_ID;

--@BALANCE_SOURCE_ID--来源类型标识--9位
CREATE SEQUENCE DBACCNEW.BALANCE_SOURCE_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM BALANCE_SOURCE_ID For DBACCNEW.BALANCE_SOURCE_ID;

--@PRIVILEGE_ID--权限标识--9位
CREATE SEQUENCE DBACCNEW.PRIVILEGE_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM PRIVILEGE_ID For DBACCNEW.PRIVILEGE_ID;

--@STAFF_ID--员工标识--9位
CREATE SEQUENCE DBACCNEW.STAFF_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM STAFF_ID For DBACCNEW.STAFF_ID;


--@BANK_BRANCH_ID--银行分行标识--9位
CREATE SEQUENCE DBACCNEW.BANK_BRANCH_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM BANK_BRANCH_ID For DBACCNEW.BANK_BRANCH_ID;

--@BANK_ID--银行标识--9位
CREATE SEQUENCE DBACCNEW.BANK_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM BANK_ID For DBACCNEW.BANK_ID;

--@PAYMENT_METHOD_ID--付款方式--9位
CREATE SEQUENCE DBACCNEW.PAYMENT_METHOD_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM PAYMENT_METHOD_ID For DBACCNEW.PAYMENT_METHOD_ID;

--@DELAY_RULE_ID--滞纳金计算规则标识--9位
CREATE SEQUENCE DBACCNEW.DELAY_RULE_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM DELAY_RULE_ID For DBACCNEW.DELAY_RULE_ID;

--@DERATE_RULE_ID--滞纳金减免规则标识--9位
CREATE SEQUENCE DBACCNEW.DERATE_RULE_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM DERATE_RULE_ID For DBACCNEW.DERATE_RULE_ID;

--@PRESENT_RULE_ID--优惠赠送规则标识--14位
CREATE SEQUENCE DBACCNEW.PRESENT_RULE_ID
  START WITH 10000
  MAXVALUE 999999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM PRESENT_RULE_ID For DBACCNEW.PRESENT_RULE_ID;

--@BILL_ITEM_TYPE_ID--帐单项标识--9位
CREATE SEQUENCE DBACCNEW.BILL_ITEM_TYPE_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM BILL_ITEM_TYPE_ID For DBACCNEW.BILL_ITEM_TYPE_ID;

--@BILL_FORMAT_ID--帐单格式标识--9位
CREATE SEQUENCE DBACCNEW.BILL_FORMAT_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM BILL_FORMAT_ID For DBACCNEW.BILL_FORMAT_ID;

--@BILL_REMARK_ID--可变文本标识--9位
CREATE SEQUENCE DBACCNEW.BILL_REMARK_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM BILL_REMARK_ID For DBACCNEW.BILL_REMARK_ID;


--@BILL_VARIABLE_ID--帐单变量标识--9位
CREATE SEQUENCE DBACCNEW.BILL_VARIABLE_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM BILL_VARIABLE_ID For DBACCNEW.BILL_VARIABLE_ID;
   	

--@OWE_TIME_INFO_ID--处理时间信息标识--9位
CREATE SEQUENCE DBACCNEW.OWE_TIME_INFO_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM OWE_TIME_INFO_ID For DBACCNEW.OWE_TIME_INFO_ID;
   	

--@DATE_TYPE_ID--欠费时间类型标识--9位
CREATE SEQUENCE DBACCNEW.DATE_TYPE_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM DATE_TYPE_ID For DBACCNEW.DATE_TYPE_ID;
   	
--@OWE_BUSINESS_TYPE_ID--欠费业务类型标识--9位
CREATE SEQUENCE DBACCNEW.OWE_BUSINESS_TYPE_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM OWE_BUSINESS_TYPE_ID For DBACCNEW.OWE_BUSINESS_TYPE_ID;

--@OWE_TYPE_LIMIT_ID--欠费类型限额标识--9位
CREATE SEQUENCE DBACCNEW.OWE_TYPE_LIMIT_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM OWE_TYPE_LIMIT_ID For DBACCNEW.OWE_TYPE_LIMIT_ID;
   	
--@ACCT_ITEM_GROUP_ID--帐目组标识--9位
CREATE SEQUENCE DBACCNEW.ACCT_ITEM_GROUP_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM ACCT_ITEM_GROUP_ID For DBACCNEW.ACCT_ITEM_GROUP_ID;
   	
--@ACCT_ITEM_TYPE_ID--帐目类型标识--9位
CREATE SEQUENCE DBACCNEW.ACCT_ITEM_TYPE_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM ACCT_ITEM_TYPE_ID For DBACCNEW.ACCT_ITEM_TYPE_ID;

--@ITEM_SOURCE_ID--帐目来源标识--9位
CREATE SEQUENCE DBACCNEW.ITEM_SOURCE_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM ITEM_SOURCE_ID For DBACCNEW.ITEM_SOURCE_ID;
   	
--@ACCT_ITEM_CLASS_ID--帐目类型归类标识--9位
CREATE SEQUENCE DBACCNEW.ACCT_ITEM_CLASS_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM ACCT_ITEM_CLASS_ID For DBACCNEW.ACCT_ITEM_CLASS_ID;
   	
--@ATTR_GRP_ID--详单属性集合标识--9位
CREATE SEQUENCE DBACCNEW.ATTR_GRP_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM ATTR_GRP_ID For DBACCNEW.ATTR_GRP_ID;
   	
--@BILL_PARSE_ID--帐务解析标识--9位
CREATE SEQUENCE DBACCNEW.BILL_PARSE_ID
  START WITH 100
  MAXVALUE 999999999
  MINVALUE 100
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM BILL_PARSE_ID For DBACCNEW.BILL_PARSE_ID;
   	

--@BALANCE_RELATION_ID--余额对象账本关系标识--9位
CREATE SEQUENCE DBACCNEW.BALANCE_RELATION_ID
  START WITH 100000000
  MAXVALUE 999999999
  MINVALUE 100000000
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM BALANCE_RELATION_ID For DBACCNEW.BALANCE_RELATION_ID;


--@ADDRESS_ID--地址标识--9位
CREATE SEQUENCE DBACCNEW.ADDRESS_ID
  START WITH 100000000
  MAXVALUE 999999999
  MINVALUE 100000000
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM ADDRESS_ID For DBACCNEW.ADDRESS_ID;


--@BILL_RECORD_ID--帐单记录标识--9位
CREATE SEQUENCE DBACCNEW.BILL_RECORD_ID
  START WITH 100000000
  MAXVALUE 999999999
  MINVALUE 100000000
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM BILL_RECORD_ID For DBACCNEW.BILL_RECORD_ID;


--@FAVOUR_PRESENT_ID--优惠赠送信息标识--14位
CREATE SEQUENCE DBACCNEW.FAVOUR_PRESENT_ID
  START WITH 100000000
  MAXVALUE 99999999999999
  MINVALUE 100000000
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM FAVOUR_PRESENT_ID For DBACCNEW.FAVOUR_PRESENT_ID;


--@PRESENT_ID--赠送信息标识--14位
CREATE SEQUENCE DBACCNEW.PRESENT_ID
  START WITH 100000000
  MAXVALUE 99999999999999
  MINVALUE 100000000
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM PRESENT_ID For DBACCNEW.PRESENT_ID;

--@BALANCE_PRESENT_ID--预存赠送信息标识--14位
CREATE SEQUENCE DBACCNEW.BALANCE_PRESENT_ID
  START WITH 100000000
  MAXVALUE 99999999999999
  MINVALUE 100000000
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM BALANCE_PRESENT_ID For DBACCNEW.BALANCE_PRESENT_ID;

--@OWE_OBJECT_ID--欠费处理对象标识--9位
CREATE SEQUENCE DBACCNEW.OWE_OBJECT_ID
  START WITH 100000000
  MAXVALUE 999999999
  MINVALUE 100000000
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM OWE_OBJECT_ID For DBACCNEW.OWE_OBJECT_ID;

--@CHARGE_ADJUST_LOG_ID--调帐日志标识--9位  
CREATE SEQUENCE DBACCNEW.CHARGE_ADJUST_LOG_ID
  START WITH 100000000
  MAXVALUE 999999999
  MINVALUE 100000000
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM CHARGE_ADJUST_LOG_ID For DBACCNEW.CHARGE_ADJUST_LOG_ID;

--@ADJUST_RECORD_ID--调帐帐目标识--9位
CREATE SEQUENCE DBACCNEW.ADJUST_RECORD_ID
  START WITH 100000000
  MAXVALUE 999999999
  MINVALUE 100000000
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM ADJUST_RECORD_ID For DBACCNEW.ADJUST_RECORD_ID;  	



--@REGION_ID--区域标识--10位
CREATE SEQUENCE DBACCNEW.REGION_ID
  START WITH 10000
  MAXVALUE 9999999999
  MINVALUE 10000
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM REGION_ID For DBACCNEW.REGION_ID;  	  	


--@INTEGRAL_REAULT_ID--积分评估结果--12位
CREATE SEQUENCE DBACCNEW.INTEGRAL_REAULT_ID
  START WITH 100000000000
  MAXVALUE 999999999999
  MINVALUE 100000000000
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM INTEGRAL_REAULT_ID For DBACCNEW.INTEGRAL_REAULT_ID;  	  	  	
  	

--@PAYMENT_PLAN_ID--支付方案标识--12位
CREATE SEQUENCE DBACCNEW.PAYMENT_PLAN_ID
  START WITH 100000000000
  MAXVALUE 999999999999
  MINVALUE 100000000000
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM PAYMENT_PLAN_ID For DBACCNEW.PAYMENT_PLAN_ID; 

--@INVOICE_ID--发票记录号--12位
CREATE SEQUENCE DBACCNEW.INVOICE_ID
  START WITH 100000000000
  MAXVALUE 999999999999
  MINVALUE 100000000000
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM INVOICE_ID For DBACCNEW.INVOICE_ID; 

--@BILL_FORMAT_CUSTOMIZE_ID--帐单定制标识--12位
CREATE SEQUENCE DBACCNEW.BILL_FORMAT_CUSTOMIZE_ID
  START WITH 100000000000
  MAXVALUE 999999999999
  MINVALUE 100000000000
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM BILL_FORMAT_CUSTOMIZE_ID For DBACCNEW.BILL_FORMAT_CUSTOMIZE_ID; 

--@BILL_FORMAT_SELECTOR_ID--帐单选择标识--12位
CREATE SEQUENCE DBACCNEW.BILL_FORMAT_SELECTOR_ID
  START WITH 100000000000
  MAXVALUE 999999999999
  MINVALUE 100000000000
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM BILL_FORMAT_SELECTOR_ID For DBACCNEW.BILL_FORMAT_SELECTOR_ID;

--@OWE_TASK_ID--欠费处理任务标识--12位
CREATE SEQUENCE DBACCNEW.OWE_TASK_ID
  START WITH 100000000000
  MAXVALUE 999999999999
  MINVALUE 100000000000
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM OWE_TASK_ID For DBACCNEW.OWE_TASK_ID;


--@LOGOUT_OP_SN--核销流水号--12位
CREATE SEQUENCE DBACCNEW.LOGOUT_OP_SN
  START WITH 100000000000
  MAXVALUE 999999999999
  MINVALUE 100000000000
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM LOGOUT_OP_SN For DBACCNEW.LOGOUT_OP_SN;

--@ACCT_ITEM_ID--帐目标识--12位
CREATE SEQUENCE DBACCNEW.ACCT_ITEM_ID
  START WITH 100000000000
  MAXVALUE 999999999999
  MINVALUE 100000000000
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM ACCT_ITEM_ID For DBACCNEW.ACCT_ITEM_ID;

--@AI_TOTAL_ID--帐目综合标识--14位
CREATE SEQUENCE DBACCNEW.AI_TOTAL_ID
  START WITH 100000000000
  MAXVALUE 99999999999999
  MINVALUE 100000000000
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM AI_TOTAL_ID For DBACCNEW.AI_TOTAL_ID;

--@SERV_ACCT_ID--帐务定制关系标识--12位
CREATE SEQUENCE DBACCNEW.SERV_ACCT_ID
  START WITH 100004254882
  MAXVALUE 999999999999
  MINVALUE 100004254882
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM SERV_ACCT_ID For DBACCNEW.SERV_ACCT_ID;



--@ACCT_BALANCE_ID--余额账本标识--14位
CREATE SEQUENCE DBACCNEW.ACCT_BALANCE_ID
  START WITH 10000000000000
  MAXVALUE 99999999999999
  MINVALUE 10000000000000
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM ACCT_BALANCE_ID For DBACCNEW.ACCT_BALANCE_ID;

--@BATCH_OPER_SN--批量操作日志流水--14位
CREATE SEQUENCE DBACCNEW.BATCH_OPER_SN
  START WITH 10000000000000
  MAXVALUE 99999999999999
  MINVALUE 10000000000000
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM BATCH_OPER_SN For DBACCNEW.BATCH_OPER_SN;


--@BILL_ID--销帐流水--14位
CREATE SEQUENCE DBACCNEW.BILL_ID
  START WITH 10000000000000
  MAXVALUE 99999999999999
  MINVALUE 10000000000000
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM BILL_ID For DBACCNEW.BILL_ID;
  	
--@PAY_SN--付款/缴费流水--14位
CREATE SEQUENCE DBACCNEW.PAY_SN
  START WITH 10000000000000
  MAXVALUE 99999999999999
  MINVALUE 10000000000000
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM PAY_SN For DBACCNEW.PAY_SN;

--@OPER_PAYOUT_ID--余额支出操作流水--14位
CREATE SEQUENCE DBACCNEW.OPER_PAYOUT_ID
  START WITH 10000000000000
  MAXVALUE 99999999999999
  MINVALUE 10000000000000
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM OPER_PAYOUT_ID For DBACCNEW.OPER_PAYOUT_ID;
  	
--@OPER_INCOME_ID--余额来源操作流水--14位
CREATE SEQUENCE DBACCNEW.OPER_INCOME_ID
  START WITH 10000000000000
  MAXVALUE 99999999999999
  MINVALUE 10000000000000
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM OPER_INCOME_ID For DBACCNEW.OPER_INCOME_ID;	


--@ZT_OWE_TOTAL_ID--在途资料表--14位
CREATE SEQUENCE DBACCNEW.ZT_OWE_TOTAL_ID
  START WITH 10000000000000
  MAXVALUE 99999999999999
  MINVALUE 10000000000000
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM ZT_OWE_TOTAL_ID For DBACCNEW.ZT_OWE_TOTAL_ID;	

--@DELAY_FAV_ID--滞纳金优惠记录标识--14位
CREATE SEQUENCE DBACCNEW.DELAY_FAV_ID
  START WITH 10000000000000
  MAXVALUE 99999999999999
  MINVALUE 10000000000000
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM DELAY_FAV_ID For DBACCNEW.DELAY_FAV_ID;	


--@PAY_INTERFACE_ID--缴费接口操作流水--14位
CREATE SEQUENCE DBACCNEW.PAY_INTERFACE_ID
  START WITH 10000000000000
  MAXVALUE 99999999999999
  MINVALUE 10000000000000
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM PAY_INTERFACE_ID For DBACCNEW.PAY_INTERFACE_ID;

--@SEND_MSG_SN--发短信流水--14位
CREATE SEQUENCE DBACCNEW.SEND_MSG_SN
  START WITH 10000000000000
  MAXVALUE 99999999999999
  MINVALUE 10000000000000
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM SEND_MSG_SN For DBACCNEW.SEND_MSG_SN;


--@CREDIT_RESULT_ID--信誉评估结果主键--12位
CREATE SEQUENCE DBACCNEW.CREDIT_RESULT_ID
  START WITH 100000000000
  MAXVALUE 999999999999
  MINVALUE 100000000000
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM CREDIT_RESULT_ID For DBACCNEW.CREDIT_RESULT_ID;

--@PARTY_ID--合作伙伴主键流水--9位
CREATE SEQUENCE DBACCNEW.PARTY_ID
  START WITH 100000000
  MAXVALUE 999999999
  MINVALUE 100000000
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM PARTY_ID For DBACCNEW.PARTY_ID;

--@PAYINFO_ID--CRM缴费业务接口表流水--14位
CREATE SEQUENCE DBACCNEW.PAYINFO_ID
  START WITH 10000000000000
  MAXVALUE 99999999999999
  MINVALUE 10000000000000
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM PAYINFO_ID For DBACCNEW.PAYINFO_ID;

--@TRANSFER_ACCOUNT_ID--付费计划变更业务接口表流水--14位
CREATE SEQUENCE DBACCNEW.TRANSFER_ACCOUNT_ID
  START WITH 10000000000000
  MAXVALUE 99999999999999
  MINVALUE 10000000000000
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM TRANSFER_ACCOUNT_ID For DBACCNEW.TRANSFER_ACCOUNT_ID;

--@BILL_UNOWNER_ID--无主流水--14位
CREATE SEQUENCE DBACCNEW.BILL_UNOWNER_ID
  START WITH 10000000000000
  MAXVALUE 99999999999999
  MINVALUE 10000000000000
  NOCYCLE
  CACHE 20
  ORDER;  
CREATE OR REPLACE PUBLIC SYNONYM BILL_UNOWNER_ID For DBACCNEW.BILL_UNOWNER_ID;

--@LOGICAL_ADDRESS_ID--无主流水--9位
CREATE SEQUENCE DBACCNEW.LOGICAL_ADDRESS_ID
  START WITH 100000000
  MAXVALUE 999999999
  MINVALUE 100000000
  NOCYCLE
  CACHE 20
  ORDER;  
CREATE OR REPLACE PUBLIC SYNONYM LOGICAL_ADDRESS_ID For DBACCNEW.LOGICAL_ADDRESS_ID;

--@SERV_ADD_ACC_NBR--主产品实例附加号码流水--14位
CREATE SEQUENCE DBACCNEW.SERV_ADD_ACC_NBR_ID
  START WITH 10000000000000
  MAXVALUE 99999999999999
  MINVALUE 10000000000000
  NOCYCLE
  CACHE 20
  ORDER;  
CREATE OR REPLACE PUBLIC SYNONYM SERV_ADD_ACC_NBR_ID For DBACCNEW.SERV_ADD_ACC_NBR_ID;

--@BATCH_OPER_SN--余额账本操作流水--14位
CREATE SEQUENCE DBACCNEW.MMDB_ACCT_BALANCE_INC_OPSN
  START WITH 10000000000000
  MAXVALUE 99999999999999
  MINVALUE 10000000000000
  NOCYCLE
  CACHE 20
  ORDER;
CREATE OR REPLACE PUBLIC SYNONYM MMDB_ACCT_BALANCE_INC_OPSN For DBACCNEW.MMDB_ACCT_BALANCE_INC_OPSN;