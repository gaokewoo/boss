#include "DBStruct.hh"
#include <iostream>
using namespace std;
int main(int argc,char* argv[])
{
	ST_SERV_ACCT_DEAD serv_acct_dead;
	ST_PRODUCT_OFFER_INSTANCE_DETAIL product_offer_instance_detail;
	ST_CDR_FEE_NAME cdr_fee_name;
	ST_CHARGE_ADJUST_LOG charge_adjust_log;
	ST_SEND_FEE_LOG send_fee_log;
	ST_DISCOUNT_TARGET_OBJECT discount_target_object;
	ST_OWE_PREDELMID owe_predelmid;
	ST_ACCT_BALANCE acct_balance;
	ST_BALANCE_SHARE_RULE balance_share_rule;
	ST_SERV_IDENTIFICATION_DEAD serv_identification_dead;
	ST_CHN_GROUP_INFO_CHG chn_group_info_chg;
	ST_PRESENT_INFO present_info;
	ST_TRANS_LOG trans_log;
	ST_BALANCE_PRESENT_INFO balance_present_info;
	ST_BILL_FORMAT_CUSTOMIZE bill_format_customize;
	ST_BALANCE_ACCT_ITEM_PAYED balance_acct_item_payed;
	ST_ACCT_LOGOUT acct_logout;
	ST_MONTH_PAY_SHORT_MSG month_pay_short_msg;
	ST_CDR_ROAM_NAME cdr_roam_name;
	ST_RATABLE_OBJECT ratable_object;
	ST_PRICING_SECTION_RELATION pricing_section_relation;
	ST_BILLING_TABLE_MONITOR billing_table_monitor;
	ST_BILL_INTERFACE bill_interface;
	ST_SEND_FEE_RULE send_fee_rule;
	ST_PRICING_PLAN pricing_plan;
	ST_OWE_TASK owe_task;
	ST_BILL_FORMAT_ITEM bill_format_item;
	ST_STAFF staff;
	ST_BILL_PARSE bill_parse;
	ST_ADJUST_APPROVAL_ERR adjust_approval_err;
	ST_SZ_STATUS sz_status;
	ST_COMMON_SHORT_CJ common_short_cj;
	ST_ZONE_ITEM zone_item;
	ST_BILL bill;
	ST_DEPOSIT_TYPE deposit_type;
	ST_ACCT_ITEM_TOTAL_DEAD acct_item_total_dead;
	ST_OFFER_ITEM_RELATION offer_item_relation;
	ST_OWE_BUSINESS_RELA owe_business_rela;
	ST_CUST_DEAD cust_dead;
	ST_BILL_VARIABLE bill_variable;
	ST_ACCT_ITEM_DEAD acct_item_dead;
	ST_DELAY_CACL_RULE delay_cacl_rule;
	ST_NBR_IMSI nbr_imsi;
	ST_TARIFF_CALC_DESC tariff_calc_desc;
	ST_BILLING_CYCLE_TYPE billing_cycle_type;
	ST_DISCOUNT_REPATITION_TYPE discount_repatition_type;
	ST_OWE_BUSINESS_RULE owe_business_rule;
	ST_ADJUST_APPROVAL adjust_approval;
	ST_CHECK_INFO check_info;
	ST_ACCT_TYPE acct_type;
	ST_BALANCE_PRESENT_INFO_HIS balance_present_info_his;
	ST_SEND_FEE_LOG_HIS send_fee_log_his;
	ST_BALANCE_PRESENT_RULE balance_present_rule;
	ST_PRODUCT_OFFER_OBJECT product_offer_object;
	ST_ACCT_CREDIT acct_credit;
	ST_STOP_SERV_OWE stop_serv_owe;
	ST_OWE_TASK_OBJECT_HIS owe_task_object_his;
	ST_BALANCE_SOURCE balance_source;
	ST_BANK_BRANCH bank_branch;
	ST_REF_VALUE ref_value;
	ST_OWE_STOP_INTERFACE owe_stop_interface;
	ST_PRODUCT_OFFER_INSTANCE product_offer_instance;
	ST_PROPERTY_DEFINE property_define;
	ST_OWE_TASK_OBJECT owe_task_object;
	ST_PAY_INTERFACE pay_interface;
	ST_BILL_UNOWNER_CHG bill_unowner_chg;
	ST_PRICING_SECTION pricing_section;
	ST_SERV_BILLING_MODE serv_billing_mode;
	ST_ZT_INVOICE_DETAIL zt_invoice_detail;
	ST_ZT_OPR_LOG zt_opr_log;
	ST_GROUP_INSTANCE group_instance;
	ST_INVOICE_DETAIL invoice_detail;
	ST_PARTNER partner;
	ST_EVAL_RULE eval_rule;
	ST_DISCOUNT_RESULT discount_result;
	ST_CDR_QUERY_TYPE cdr_query_type;
	ST_OWE_BUSINESS_PLAN owe_business_plan;
	ST_BILL_ACCT_ITEM bill_acct_item;
	ST_OWE_BUSINESS_INTERFACE_HIS owe_business_interface_his;
	ST_SERV_PRODUCT serv_product;
	ST_PRODUCT_OFFER_PARAM_INSTANCE product_offer_param_instance;
	ST_BILL_UNOWNER_INFO_HIS bill_unowner_info_his;
	ST_PRICING_COMBINE pricing_combine;
	ST_ACCT_RELATIONSHIP acct_relationship;
	ST_SERV_BILLING_MODE_DEAD serv_billing_mode_dead;
	ST_PERSONAL_OWE_SCHEME personal_owe_scheme;
	ST_ACCT_ITEM_TOTAL acct_item_total;
	ST_BALANCE_RELATION_DEAD balance_relation_dead;
	ST_BILL_UNOWNER_INFO bill_unowner_info;
	ST_PRODUCT_USAGE_EVENT_TYPE product_usage_event_type;
	ST_GROUP_MEMBER_TYPE group_member_type;
	ST_DEPOSIT_FEE deposit_fee;
	ST_ACCT_BALANCE_HIS acct_balance_his;
	ST_UNOWNER_INFO_INTERFACE unowner_info_interface;
	ST_GROUP_INSTANCE_MEMBER group_instance_member;
	ST_AGGREGATE_OBJECT aggregate_object;
	ST_FAVOUR_PRESENT_INFO_ADD favour_present_info_add;
	ST_BANK bank;
	ST_FAVOUR_PRESENT_INFO favour_present_info;
	ST_PAYMENT_METHOD payment_method;
	ST_BILL_RECORD bill_record;
	ST_COLLECT_OPRT collect_oprt;
	ST_BILL_REMARK bill_remark;
	ST_ACCT_UNOWNER_INFO_HIS acct_unowner_info_his;
	ST_CREDIT_GRADE credit_grade;
	ST_GROUP_INSTANCE_RELATION group_instance_relation;
	ST_OWE_BUSINESS_TYPE owe_business_type;
	ST_STOP_SERV_OWE_CJ stop_serv_owe_cj;
	ST_BAND band;
	ST_OPEN_INTERFACE_HIS open_interface_his;
	ST_PRODUCT_OFFER product_offer;
	ST_BALANCE_RELATION balance_relation;
	ST_CHN_GROUP_MSG_CHG chn_group_msg_chg;
	ST_OWE_TYPE_ACCTTYPE owe_type_accttype;
	ST_BUSI_ORDER_INTERFACE busi_order_interface;
	ST_SERV_GRADE_CODE serv_grade_code;
	ST_SERV_STATE_DESC serv_state_desc;
	ST_PAY_INFO_HIS pay_info_his;
	ST_REGION region;
	ST_ACCT_ADD_ACC_NBR_HIS acct_add_acc_nbr_his;
	ST_BILL_RECORD_DATA bill_record_data;
	ST_DISCOUNT_CALC_OBJECT discount_calc_object;
	ST_OWE_NOTIFICATION_INFO owe_notification_info;
	ST_OWE_BUSINESS_ATTR owe_business_attr;
	ST_INTEREST_RESPOND interest_respond;
	ST_BALANCE_SHARE_RULE_DEAD balance_share_rule_dead;
	ST_CREDIT_RESULT credit_result;
	ST_OWE_BALANCE_INFO owe_balance_info;
	ST_TABLE_SYNC_RELATION table_sync_relation;
	ST_STOP_SERV_OWE_BC stop_serv_owe_bc;
	ST_SERV_ADD_ACC_NBR serv_add_acc_nbr;
	ST_SERV_ACCT serv_acct;
	ST_ADDRESS address;
	ST_BILL_ITEM bill_item;
	ST_OWE_PLAN_CUSTOMIZE owe_plan_customize;
	ST_LOGOUT_STATE logout_state;
	ST_RATABLE_CYCLE ratable_cycle;
	ST_BILL_FORMAT_SELECTOR_RULE bill_format_selector_rule;
	ST_UNOWNER_DEAL_RULE unowner_deal_rule;
	ST_PHONE_COMM phone_comm;
	ST_ACCT_DEAD acct_dead;
	ST_PRODUCT_OFFER_INSTANCE_ATTR product_offer_instance_attr;
	ST_STOP_SERV_OWE_CJ_OK stop_serv_owe_cj_ok;
	ST_OWE_PLAN_SELECT_RULE owe_plan_select_rule;
	ST_SERV_LOCATION serv_location;
	ST_ACCT_ITEM_CLASS acct_item_class;
	ST_PAY_INFO pay_info;
	ST_DISCOUNT_METHOD discount_method;
	ST_INTEREST_BALANCE interest_balance;
	ST_PROPERTY_REF property_ref;
	ST_ACCT_ITEM_TYPE acct_item_type;
	ST_BALANCE_RELATION_HIS balance_relation_his;
	ST_PRODUCT_OFFER_DETAIL product_offer_detail;
	ST_DEPOSIT_OPR deposit_opr;
	ST_STAFF_OPR staff_opr;
	ST_RATABLE_CYCLE_TYPE ratable_cycle_type;
	ST_MMDB_ACCT_BALANCE_INC mmdb_acct_balance_inc;
	ST_FAVOUR_PRESENT_DETAIL favour_present_detail;
	ST_INVOICE invoice;
	ST_SERV_ATTR_DEAD serv_attr_dead;
	ST_LOGICAL_ADDRESS logical_address;
	ST_TARIFF_UNIT tariff_unit;
	ST_RATABLE_RESOURCE_ACCUMULATOR ratable_resource_accumulator;
	ST_BALANCE_SOURCE_TYPE balance_source_type;
	ST_ADJUST_APPROVAL_TOTAL adjust_approval_total;
	ST_ACTION action;
	ST_SERV_ATTR_TYPE serv_attr_type;
	ST_TIF_OWE_NOTIFICATION tif_owe_notification;
	ST_EVENT_PRICING_STRATEGY event_pricing_strategy;
	ST_PRICING_RULE pricing_rule;
	ST_CREDIT_GRADE_RULE credit_grade_rule;
	ST_SERV_IDENTIFICATION serv_identification;
	ST_CUST_OWE_TOTAL cust_owe_total;
	ST_PAY_CARD_OPR pay_card_opr;
	ST_CUST_PAY cust_pay;
	ST_BILL_FORMAT_SELECTOR bill_format_selector;
	ST_BILL_INTERFACE_HIS bill_interface_his;
	ST_ACCT_ADD_ACC_NBR acct_add_acc_nbr;
	ST_PRODUCT product;
	ST_COLLECT_TOTAL collect_total;
	ST_BALANCE_TYPE balance_type;
	ST_ZT_OWE_TOTAL_MID zt_owe_total_mid;
	ST_OWE_OBJECT owe_object;
	ST_MEASURE_METHOD measure_method;
	ST_PLUSMINUS plusminus;
	ST_BILLING_REGION billing_region;
	ST_DEST_EVENT_TYPE dest_event_type;
	ST_CUST cust;
	ST_PAYMENT_PLAN payment_plan;
	ST_ACCT_ITEM_ADJUSTED acct_item_adjusted;
	ST_GROUP_TYPE group_type;
	ST_FAVOUR_PRESENT_RULE favour_present_rule;
	ST_CHECK_OPR check_opr;
	ST_PRICING_SECTION_TYPE pricing_section_type;
	ST_COLLECT_DETAIL collect_detail;
	ST_OWE_TYPE_LIMIT owe_type_limit;
	ST_PRODUCT_OFFER_PARAM product_offer_param;
	ST_PRICING_PARAM_DEFINE pricing_param_define;
	ST_CHN_GROUP_FEE_ALERT chn_group_fee_alert;
	ST_TRANSFER_ACCOUNT transfer_account;
	ST_SYS_DOMAIN sys_domain;
	ST_SERV serv;
	ST_CDR_ATTR_GROUP cdr_attr_group;
	ST_STAFF_PRIVILEGE staff_privilege;
	ST_CUST_OWE cust_owe;
	ST_OPEN_INTERFACE open_interface;
	ST_SERV_DEAD serv_dead;
	ST_BATCH_LOG batch_log;
	ST_OWE_ITEM_INFO owe_item_info;
	ST_COMMON_SHORT_MSG common_short_msg;
	ST_ACCT_GROUP acct_group;
	ST_OWE_DATETYPE_INFO owe_datetype_info;
	ST_ACCT_ITEM_OFF acct_item_off;
	ST_OWE_BALANCE_TMP owe_balance_tmp;
	ST_SERV_STATE_ATTR serv_state_attr;
	ST_TRANSFER_ACCOUNT_HIS transfer_account_his;
	ST_OPERATOR myoperator;
	ST_ACCT_BALANCE_DEAD acct_balance_dead;
	ST_SERV_LOCATION_DEAD serv_location_dead;
	ST_SERV_STATE_ATTR_DEAD serv_state_attr_dead;
	ST_PAYMENT payment;
	ST_SPECIAL_PAYMENT_DESC special_payment_desc;
	ST_PRICING_ENUM_PARAM pricing_enum_param;
	ST_OWE_DATE_TYPE owe_date_type;
	ST_OWE_SHORTMSG_CODE owe_shortmsg_code;
	ST_ZONE_ITEM_VALUE zone_item_value;
	ST_CUST_IDENTIFICATION cust_identification;
	ST_CHN_ACC_MSG_LIST chn_acc_msg_list;
	ST_USER_ATTR_CHG user_attr_chg;
	ST_OWNER owner;
	ST_STOP_SERV_STATE stop_serv_state;
	ST_BILL_FORMAT bill_format;
	ST_BILL_REPORT_ATTR bill_report_attr;
	ST_CERTIFICATE_TYPE certificate_type;
	ST_ACCT_GROUP_MEMBER acct_group_member;
	ST_CUST_CONTACT_INFO cust_contact_info;
	ST_OWE_TOTAL_SHORT_MSG owe_total_short_msg;
	ST_PRIVILEGE privilege;
	ST_DELAY_DERATE_RULE delay_derate_rule;
	ST_OWE_BUSINESS_INTERFACE owe_business_interface;
	ST_PAYMENT_PLAN_DEAD payment_plan_dead;
	ST_CDR_QUERY_CODE cdr_query_code;
	ST_ACCT_ITEM acct_item;
	ST_ACCT_ITEM_GROUP acct_item_group;
	ST_CHN_ACC_CREDIT_DET chn_acc_credit_det;
	ST_ACCT_ADD_ACC_NBR_DEAD acct_add_acc_nbr_dead;
	ST_CDR_CALL_NAME cdr_call_name;
	ST_BALANCE_PAYOUT balance_payout;
	ST_PAYMENT_RULE payment_rule;
	ST_SPECIAL_PAYMENT special_payment;
	ST_DISCOUNT_TIME_LIMIT discount_time_limit;
	ST_SHARE_RULE_TYPE share_rule_type;
	ST_PAY_INTERFACE_HIS pay_interface_his;
	ST_PRODUCT_OFFER_ATTR product_offer_attr;
	ST_ZT_STAFF_LOG zt_staff_log;
	ST_CUST_POST_CHG cust_post_chg;
	ST_ACCT_ITEM_GROUP_MEMBER acct_item_group_member;
	ST_OWE_PLAN_SELECT owe_plan_select;
	ST_DISCOUNT_EXPRESS discount_express;
	ST_DELAY_FAVOUR delay_favour;
	ST_PAYMENT_PLAN_TYPE payment_plan_type;
	ST_GROUP_INSTANCE_ROLE group_instance_role;
	ST_BILLING_CYCLE billing_cycle;
	ST_ADJUST_APPROVAL_HIS adjust_approval_his;
	ST_BATCH_LOG_DET batch_log_det;
	ST_BALANCE_STATE balance_state;
	ST_SERV_ATTR serv_attr;
	ST_ACCT_ITEM_TOTAL_OFF acct_item_total_off;
	ST_ACCT_ITEM_SOURCE acct_item_source;
	ST_LIFE_CYCLE life_cycle;
	ST_EVAL_PLAN eval_plan;
	ST_OWE_SHORTMSG_CONTENT owe_shortmsg_content;
	ST_INTEGRAL_RESULT integral_result;
	ST_SERV_ADD_ACC_NBR_DEAD serv_add_acc_nbr_dead;
	ST_TARIFF tariff;
	ST_PAY_CARD_OPR_HIS pay_card_opr_his;
	ST_ACCT_UNOWNER_INFO acct_unowner_info;
	ST_ZT_OWE_TOTAL zt_owe_total;
	ST_ACCT_BALANCE_LOG acct_balance_log;
	ST_ZONE zone;
	ST_PRICING_REF_OBJECT pricing_ref_object;
	ST_STOP_ACCT_SERV_OWE stop_acct_serv_owe;
	ST_SUB_BILLING_CYCLE sub_billing_cycle;
	ST_ACCT acct;
	ST_ROUTE_CONTROL_TABLE route_control_table;
	ST_INTEREST_RATE interest_rate;
	ST_AGREEMENT agreement;
	ST_ACCT_BALANCE_MONTH acct_balance_month;
	ST_PRICING_COMBINE_RELATION pricing_combine_relation;
	ST_RATABLE_RESOURCE ratable_resource;
	ST_TARIFF_REF_TYPE tariff_ref_type;

    return 0;
}