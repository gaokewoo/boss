#ifndef __DBSTRUCT__
#define __DBSTRUCT__
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <pthread.h>

using namespace std;

typedef struct {
	long	m_serv_acct_id;
	long	m_acct_id;
	long	m_serv_id;
	long	m_billing_cycle_type_id;
	long	m_acct_item_group_id;
	long	m_priority;
	long	m_payment_rule_id;
	string	m_payment_limit_type;
	long	m_payment_limit;
	string	m_state;
	string	m_state_date;
	long	m_pay_priority;
	string	m_eff_date;
	string	m_exp_date;
	string	m_dead_time;
	long	m_dead_staff_id;
	long	m_dead_optsn;
} ST_SERV_ACCT_DEAD;

typedef struct {
	long	m_instance_relation_id;
	long	m_product_offer_instance_id;
	string	m_instance_type;
	long	m_instance_id;
	string	m_state;
	string	m_eff_date;
	string	m_exp_date;
	long	m_rel_group_id;
	long	m_rel_prod_inst_id;
	long	m_rel_offer_inst_id;
	string	m_offer_mbr_role_cd;
} ST_PRODUCT_OFFER_INSTANCE_DETAIL;

typedef struct {
	long	m_region_id;
	string	m_begin_time;
	string	m_end_time;
	string	m_fee_name;
} ST_CDR_FEE_NAME;

typedef struct {
	long	m_charge_adjust_log_id;
	long	m_adjust_record_id;
	string	m_cause;
	string	m_date;
	long	m_staff_id;
} ST_CHARGE_ADJUST_LOG;

typedef struct {
	long	m_send_log_id;
	long	m_acct_id;
	long	m_pay_money;
	long	m_send_money;
	string	m_send_flag;
	long	m_staff_id;
	string	m_op_time;
	string	m_op_note;
	string	m_acc_nbr;
} ST_SEND_FEE_LOG;

typedef struct {
	long	m_discount_express_id;
	long	m_pricing_ref_object_id;
	long	m_repatition_type_id;
} ST_DISCOUNT_TARGET_OBJECT;

typedef struct {
	long	m_login_accept;
	long	m_serv_id;
	string	m_acc_nbr;
	string	m_attr_code;
	long	m_region_id;
	string	m_state_name;
	string	m_grade_name;
	string	m_band_name;
	string	m_offer_comments;
	string	m_region_name;
	string	m_district_name;
	string	m_is_valid;
	string	m_run_time;
	long	m_owe_fee;
	long	m_prepay_fee;
	long	m_acct_id;
	string	m_acct_name;
	long	m_cust_id;
	string	m_cust_name;
	long	m_staff_id;
	string	m_op_code;
	string	m_open_time;
	string	m_resv;
} ST_OWE_PREDELMID;

typedef struct {
	long	m_acct_balance_id;
	long	m_acct_id;
	long	m_balance_type_id;
	long	m_balance;
	long	m_reserve_balance;
	long	m_cycle_upper;
	long	m_cycle_lower;
	string	m_cycle_upper_type;
	string	m_cycle_lower_type;
	string	m_payment_date;
	string	m_bill_month_flag;
	string	m_eff_date;
	string	m_exp_date;
	string	m_state;
	string	m_state_date;
} ST_ACCT_BALANCE;

typedef struct {
	long	m_share_rule_id;
	long	m_acct_balance_id;
	long	m_share_rule_type_id;
	long	m_share_rule_type_pri;
	string	m_object_type;
	long	m_object_id;
	long	m_upper_amount;
	long	m_lower_amount;
	string	m_eff_date;
	string	m_exp_date;
	string	m_calc_method;
} ST_BALANCE_SHARE_RULE;

typedef struct {
	long	m_serv_id;
	long	m_agreement_id;
	string	m_acc_nbr;
	string	m_eff_date;
	string	m_exp_date;
	string	m_dead_time;
	long	m_dead_staff_id;
	long	m_dead_optsn;
} ST_SERV_IDENTIFICATION_DEAD;

typedef struct {
	long	m_seq_no;
	string	m_group_id;
	string	m_parent_group_id;
	long	m_parent_level;
	long	m_current_level;
	string	m_boss_org_code;
	string	m_toll_no;
	string	m_begin_region;
	string	m_op_type;
	string	m_deal_flag;
	string	m_deal_time;
} ST_CHN_GROUP_INFO_CHG;

typedef struct {
	long	m_present_id;
	long	m_serv_id;
	string	m_acc_nbr;
	long	m_acct_id;
	long	m_cust_id;
	long	m_region_id;
	long	m_band_id;
	long	m_staff_id;
	long	m_present_rule_id;
	string	m_present_code;
	string	m_present_type;
	long	m_present_money;
	long	m_present_month;
	long	m_present_balance_type_id;
	long	m_balance;
	long	m_present_rate;
	long	m_month_fee;
	long	m_favour_fee;
	string	m_eff_date;
	string	m_exp_date;
	string	m_state;
	string	m_state_date;
	string	m_present_desc;
	long	m_update_staff_id;
	string	m_update_state_date;
} ST_PRESENT_INFO;

typedef struct {
	string	m_agt_accept;
	long	m_pay_id;
	string	m_agt_code;
	string	m_agt_date;
	string	m_acc_nbr;
	long	m_staff_id;
	string	m_op_code;
	string	m_op_time;
	long	m_op_money;
	string	m_unpay_flag;
	string	m_repay_flag;
	string	m_collate_flag;
	string	m_collate_time;
	long	m_band_id;
	long	m_payment_method;
	string	m_acnt_code;
} ST_TRANS_LOG;

typedef struct {
	long	m_balance_present_id;
	long	m_serv_id;
	long	m_billing_cycle_id;
	long	m_present_rule_id;
	string	m_present_type;
	long	m_priority;
	string	m_op_code;
	long	m_present_id;
	long	m_balance_type_id;
	long	m_balance_fee;
	long	m_continue_fee;
	string	m_eff_date;
	string	m_exp_date;
	string	m_state;
	string	m_state_date;
} ST_BALANCE_PRESENT_INFO;

typedef struct {
	long	m_bill_format_customize_id;
	long	m_acct_id;
	long	m_bill_format_id;
	string	m_bill_post_cycle;
	long	m_address_id;
	string	m_bill_post_method;
	string	m_state;
	string	m_state_date;
	string	m_format_type;
	long	m_serv_id;
	long	m_cust_id;
} ST_BILL_FORMAT_CUSTOMIZE;

typedef struct {
	long	m_oper_payout_id;
	long	m_acct_item_id;
	long	m_balance;
	long	m_serv_id;
	long	m_acct_item_type_id;
	long	m_item_source_id;
	string	m_state;
	string	m_state_date;
} ST_BALANCE_ACCT_ITEM_PAYED;

typedef struct {
	long	m_logout_op_sn;
	long	m_acct_item_id;
	long	m_acct_id;
	long	m_cust_id;
	long	m_agreement_id;
	string	m_owe_status;
	string	m_owe_begin_time;
	string	m_post_type;
	long	m_post_addr;
	long	m_staff_id;
	string	m_oper_time;
	string	m_logout_reason;
	long	m_logout_amount;
} ST_ACCT_LOGOUT;

typedef struct {
	long	m_command_id;
	long	m_login_accept;
	long	m_msg_level;
	string	m_acc_nbr;
	string	m_msg;
	long	m_order_code;
	long	m_back_code;
	string	m_dx_op_code;
	string	m_staff_code;
	string	m_op_time;
} ST_MONTH_PAY_SHORT_MSG;

typedef struct {
	long	m_region_id;
	string	m_begin_time;
	string	m_end_time;
	string	m_roam_name;
} ST_CDR_ROAM_NAME;

typedef struct {
	long	m_element_id;
	long	m_ratable_object_id;
} ST_RATABLE_OBJECT;

typedef struct {
	long	m_a_section_id;
	long	m_z_section_id;
	string	m_relation_type;
} ST_PRICING_SECTION_RELATION;

typedef struct {
	string	m_table_name;
	string	m_field_name;
	string	m_domain;
	long	m_serial;
	string	m_domain_exp;
	long	m_alarm_threshold;
	string	m_alarm_exp;
} ST_BILLING_TABLE_MONITOR;

typedef struct {
	long	m_payment_id;
	long	m_acct_id;
	long	m_serv_id;
	string	m_op_code;
	long	m_staff_id;
	long	m_payment_method;
	string	m_payment_date;
	long	m_online_flag;
	string	m_state;
	string	m_state_date;
	string	m_op_note;
	long	m_bill_beg_ym;
	long	m_bill_end_ym;
	string	m_bill_month_flag;
	long	m_serv_pay_flag;
} ST_BILL_INTERFACE;

typedef struct {
	long	m_balance_type_id;
	string	m_eff_date;
	string	m_exp_date;
	string	m_send_flag;
	long	m_min_pay;
	long	m_max_pay;
	long	m_send_value;
	string	m_op_note;
} ST_SEND_FEE_RULE;

typedef struct {
	long	m_pricing_plan_id;
	string	m_pricing_plan_name;
	string	m_pricing_desc;
	string	m_param_desc;
} ST_PRICING_PLAN;

typedef struct {
	long	m_owe_task_id;
	long	m_time_info_id;
	long	m_owe_business_type_id;
	string	m_owe_task_name;
	string	m_unit;
	long	m_offset;
	string	m_time;
} ST_OWE_TASK;

typedef struct {
	long	m_bill_format_id;
	long	m_bill_item_type_id;
	long	m_print_order;
} ST_BILL_FORMAT_ITEM;

typedef struct {
	long	m_staff_id;
	long	m_operate_org_id;
	string	m_staff_code;
	string	m_passwd;
	string	m_scope_level;
	string	m_staff_desc;
	long	m_parent_partyroleid;
	string	m_staff_type;
} ST_STAFF;

typedef struct {
	long	m_bill_parse_id;
	long	m_parse_sn;
	long	m_attr_grp_id;
	string	m_parse_method;
	string	m_fee_method;
	long	m_acct_item_type_id;
	long	m_sp_item_id;
} ST_BILL_PARSE;

typedef struct {
	string	m_acc_nbr;
	long	m_acct_id;
	long	m_bill_month;
	long	m_acct_item_type_id;
	long	m_adj_fee;
	long	m_staff_id;
	long	m_serv_id;
	long	m_return_code;
	string	m_op_note;
	string	m_op_time;
	string	m_sign_time;
	long	m_payment_method;
} ST_ADJUST_APPROVAL_ERR;

typedef struct {
	string	m_status;
	string	m_status_name;
	string	m_bill_flag;
	string	m_flag;
	string	m_status_desc;
} ST_SZ_STATUS;

typedef struct {
	long	m_command_id;
	long	m_login_accept;
	long	m_msg_level;
	string	m_acc_nbr;
	string	m_msg;
	long	m_order_code;
	long	m_back_code;
	string	m_dx_op_code;
	string	m_staff_code;
	string	m_op_time;
} ST_COMMON_SHORT_CJ;

typedef struct {
	long	m_zone_item_id;
	long	m_zone_id;
	long	m_parent_zone_item_id;
	string	m_zone_item_name;
} ST_ZONE_ITEM;

typedef struct {
	long	m_bill_id;
	long	m_ai_total_id;
	long	m_payment_id;
	long	m_payment_method;
	long	m_billing_cycle_id;
	long	m_party_role_id;
	long	m_acct_id;
	long	m_serv_id;
	string	m_acc_nbr;
	long	m_bill_amount;
	long	m_late_fee;
	long	m_derate_late_fee;
	long	m_balance;
	long	m_last_change;
	long	m_cur_change;
	string	m_created_date;
	string	m_payment_date;
	long	m_use_derate_blance;
	long	m_invoice_id;
	string	m_state;
	string	m_state_date;
} ST_BILL;

typedef struct {
	string	m_deposit_type;
	string	m_deposit_name;
	string	m_expire_time;
	long	m_valid_month;
	string	m_band_type;
} ST_DEPOSIT_TYPE;

typedef struct {
	long	m_ai_total_id;
	long	m_acct_id;
	long	m_serv_id;
	string	m_acc_nbr;
	long	m_billing_cycle_id;
	long	m_should_pay;
	long	m_favour_fee;
	long	m_times;
	long	m_duration;
	long	m_amount;
	string	m_created_date;
	string	m_state;
	string	m_state_date;
	long	m_month_wrtoff_fee;
	long	m_pay_wrtoff_fee;
	string	m_dead_time;
	long	m_dead_staff_id;
	long	m_dead_optsn;
} ST_ACCT_ITEM_TOTAL_DEAD;

typedef struct {
	long	m_offer_id;
	long	m_acct_item_type_id;
	string	m_acc_detail;
} ST_OFFER_ITEM_RELATION;

typedef struct {
	string	m_region_code;
	string	m_plan_code;
	string	m_crectrl_rule;
	string	m_crectrl_type;
	long	m_crectrl_order;
} ST_OWE_BUSINESS_RELA;

typedef struct {
	long	m_cust_id;
	long	m_party_role_id;
	string	m_cust_name;
	string	m_cust_type;
	long	m_cust_location;
	string	m_is_vip;
	long	m_parent_id;
	string	m_cust_code;
	string	m_state;
	string	m_eff_date;
	string	m_exp_date;
	string	m_dead_time;
	long	m_dead_staff_id;
	long	m_dead_optsn;
} ST_CUST_DEAD;

typedef struct {
	long	m_bill_variable_id;
	string	m_bill_variable_name;
} ST_BILL_VARIABLE;

typedef struct {
	long	m_acct_item_id;
	long	m_item_source_id;
	long	m_bill_id;
	long	m_acct_item_type_id;
	long	m_billing_cycle_id;
	long	m_acct_id;
	long	m_serv_id;
	long	m_amount;
	string	m_created_date;
	long	m_fee_cycle_id;
	long	m_payment_method;
	string	m_state;
	string	m_state_date;
	long	m_latn_id;
	long	m_ai_total_id;
	string	m_acc_nbr;
	long	m_should_pay;
	long	m_favour_fee;
	long	m_times;
	long	m_duration;
	long	m_month_wrtoff_fee;
	long	m_pay_wrtoff_fee;
	string	m_dead_time;
	long	m_dead_staff_id;
	long	m_dead_optsn;
} ST_ACCT_ITEM_DEAD;

typedef struct {
	long	m_delay_rule_id;
	string	m_rule_desc;
	long	m_owe_due_months;
	long	m_owe_due_days;
	long	m_owe_upper_days;
	long	m_owe_step_fee;
	long	m_calc_rate;
	long	m_max_delay_fee;
	string	m_object_type;
	string	m_object_value;
	long	m_region_id;
} ST_DELAY_CACL_RULE;

typedef struct {
	string	m_acc_nbr;
	string	m_imsi_no;
	string	m_eff_date;
	string	m_exp_date;
} ST_NBR_IMSI;

typedef struct {
	long	m_tariff_calc_id;
	string	m_tariff_calc_name;
} ST_TARIFF_CALC_DESC;

typedef struct {
	long	m_billing_cycle_type_id;
	string	m_billing_cycle_type_name;
	string	m_app_type;
	string	m_cycle_unit;
	long	m_unit_count;
	long	m_cycle_duration;
	long	m_cycle_duration_days;
} ST_BILLING_CYCLE_TYPE;

typedef struct {
	long	m_repatition_type_id;
	string	m_repatition_type_name;
	long	m_pricing_ref_object_id;
} ST_DISCOUNT_REPATITION_TYPE;

typedef struct {
	string	m_region_code;
	string	m_crectrl_rule;
	long	m_min_owe_fee;
	long	m_max_owe_fee;
	long	m_min_owe_days;
	long	m_max_owe_days;
	long	m_run_hour;
	long	m_prepay_flag;
	long	m_owe_flag;
	long	m_unbill_flag;
	long	m_limit_flag;
	long	m_bind_flag;
	long	m_operate_times;
	long	m_intervalflag;
	long	m_intervaltime;
} ST_OWE_BUSINESS_RULE;

typedef struct {
	long	m_login_accept;
	long	m_acct_item_id;
	long	m_acct_item_type_id;
	string	m_acc_nbr;
	long	m_acct_id;
	long	m_bill_month;
	long	m_adj_fee;
	long	m_staff_id;
	long	m_serv_id;
	string	m_op_note;
	string	m_op_time;
	long	m_payment_method;
	string	m_sign_state;
	string	m_op_code;
	long	m_sign_staff_id;
	string	m_sign_time;
} ST_ADJUST_APPROVAL;

typedef struct {
	string	m_check_nbr;
	long	m_balance;
	string	m_op_time;
	long	m_bank_branch_id;
	string	m_bank_acct_nbr;
	string	m_bank_acct_name;
	string	m_check_state;
	string	m_assure_state;
	string	m_assure_time;
} ST_CHECK_INFO;

typedef struct {
	string	m_acct_type;
	long	m_flag;
	string	m_type_name;
} ST_ACCT_TYPE;

typedef struct {
	long	m_balance_present_id;
	long	m_serv_id;
	long	m_billing_cycle_id;
	long	m_present_rule_id;
	string	m_present_type;
	long	m_priority;
	string	m_op_code;
	long	m_present_id;
	long	m_balance_type_id;
	long	m_balance_fee;
	long	m_continue_fee;
	string	m_eff_date;
	string	m_exp_date;
	string	m_state;
	string	m_state_date;
	string	m_update_state_date;
} ST_BALANCE_PRESENT_INFO_HIS;

typedef struct {
	long	m_send_log_id;
	long	m_acct_id;
	long	m_pay_money;
	long	m_send_money;
	string	m_send_flag;
	long	m_staff_id;
	string	m_op_time;
	string	m_op_note;
	string	m_acc_nbr;
	string	m_his_date;
	long	m_his_staff_id;
	long	m_his_optsn;
} ST_SEND_FEE_LOG_HIS;

typedef struct {
	long	m_present_rule_id;
	long	m_pay_balance_type_id;
	long	m_present_balance_type_id;
	string	m_present_rule_desc;
	long	m_ref_ceil;
	long	m_ref_floor;
	long	m_base_value;
	string	m_calc_method;
	long	m_calc_value;
	long	m_calc_rate;
	long	m_calc_precision;
	long	m_max_value;
	string	m_eff_offset_unit;
	long	m_eff_offset_value;
	string	m_state;
	string	m_state_date;
	string	m_eff_date;
	string	m_exp_date;
	long	m_region_id;
	long	m_band_id;
	string	m_present_code;
	string	m_present_name;
	string	m_present_type;
	string	m_continue_flag;
	long	m_continue_month;
	long	m_acct_item_group_id;
	long	m_delay_month;
	long	m_present_count;
} ST_BALANCE_PRESENT_RULE;

typedef struct {
	long	m_offer_object_id;
	long	m_offer_id;
	string	m_object_type;
	long	m_object_id;
	long	m_object_amount_start;
	long	m_object_amount_end;
	long	m_priority;
} ST_PRODUCT_OFFER_OBJECT;

typedef struct {
	long	m_acct_id;
	long	m_credit_grade;
	long	m_credit_amount;
	long	m_exception_amount;
	string	m_eff_date;
} ST_ACCT_CREDIT;

typedef struct {
	long	m_serv_id;
	long	m_min_owe_ym;
	long	m_max_owe_ym;
	long	m_owe_fee;
	long	m_acct_id;
	string	m_acc_nbr;
	string	m_belong_code;
	long	m_product_id;
	string	m_month_detail;
	long	m_offer_id;
	string	m_user_flag;
	string	m_action_time;
} ST_STOP_SERV_OWE;

typedef struct {
	long	m_owe_task_id;
	long	m_owe_object_id;
	string	m_owe_object_type;
	long	m_task_order;
	string	m_acc_nbr;
	long	m_acct_id;
	long	m_cust_id;
	string	m_old_run;
	long	m_prepay_fee;
	long	m_limit_owe;
	long	m_owe_fee;
	long	m_unbill_fee;
	string	m_crectrl_type;
	long	m_op_order;
	long	m_interval_time;
	long	m_op_times;
	string	m_status;
	string	m_op_date;
	string	m_state;
	string	m_state_date;
	long	m_staff_id;
	long	m_payment_id;
} ST_OWE_TASK_OBJECT_HIS;

typedef struct {
	long	m_oper_income_id;
	long	m_payment_id;
	long	m_acct_balance_id;
	string	m_oper_type;
	long	m_staff_id;
	string	m_oper_date;
	long	m_amount;
	long	m_cur_amount;
	long	m_balance_relation_id;
	long	m_balance_source_id;
	string	m_allow_draw;
	string	m_inv_offer;
	string	m_cur_status;
	string	m_cur_status_date;
	string	m_state_date;
	string	m_state;
} ST_BALANCE_SOURCE;

typedef struct {
	long	m_bank_branch_id;
	long	m_bank_id;
	string	m_bank_branch_name;
	string	m_bank_acct;
	string	m_bank_acct_name;
	string	m_bank_branch_phone;
	string	m_bank_branch_addr;
	long	m_region_id;
	string	m_bank_code;
} ST_BANK_BRANCH;

typedef struct {
	long	m_ref_value_id;
	string	m_ref_value_type;
	string	m_value_type;
	long	m_pricing_ref_object_id;
	string	m_value_string;
	long	m_pricing_prarm_id;
	long	m_rate_precision;
	long	m_calc_precision;
} ST_REF_VALUE;

typedef struct {
	long	m_serv_id;
	long	m_action_type_id;
	string	m_new_status;
	string	m_reason_id;
	string	m_staff_code;
	long	m_cust_order_origin;
	string	m_create_date;
	long	m_create_accept;
	long	m_deal_status;
	string	m_function_code;
	string	m_op_note;
} ST_OWE_STOP_INTERFACE;

typedef struct {
	long	m_product_offer_instance_id;
	long	m_cust_id;
	long	m_cust_agreement_id;
	long	m_offer_id;
	string	m_state;
	string	m_state_date;
	string	m_eff_date;
	string	m_exp_date;
	long	m_priority;
	long	m_handle_staff_id;
	long	m_develop_staff_id;
	string	m_channel_id;
	long	m_rel_offer_inst_id;
	long	m_group_id;
	long	m_serv_id;
} ST_PRODUCT_OFFER_INSTANCE;

typedef struct {
	long	m_property_define_id;
	string	m_default_value;
	string	m_property_desc;
} ST_PROPERTY_DEFINE;

typedef struct {
	long	m_owe_task_id;
	long	m_owe_object_id;
	string	m_owe_object_type;
	long	m_task_order;
	string	m_acc_nbr;
	long	m_acct_id;
	long	m_cust_id;
	string	m_old_run;
	long	m_prepay_fee;
	long	m_limit_owe;
	long	m_owe_fee;
	long	m_unbill_fee;
	string	m_crectrl_type;
	long	m_op_order;
	long	m_interval_time;
	long	m_op_times;
	string	m_status;
	string	m_op_date;
	string	m_state;
	string	m_state_date;
	long	m_staff_id;
	long	m_payment_id;
} ST_OWE_TASK_OBJECT;

typedef struct {
	long	m_login_accept;
	long	m_acct_id;
	long	m_serv_id;
	string	m_acc_nbr;
	long	m_payment_method;
	long	m_pay_money;
	string	m_pay_note;
	long	m_staff_id;
	string	m_insert_date;
} ST_PAY_INTERFACE;

typedef struct {
	long	m_bill_unowner_id;
	string	m_acc_nbr;
	string	m_unowner_type;
	string	m_region_code;
	string	m_imsi_no;
	long	m_unowner_fee;
	long	m_unowner_count;
	string	m_unowner_begin_time;
	string	m_unowner_last_time;
	string	m_insert_time;
	string	m_state;
	string	m_state_date;
	string	m_op_type;
	string	m_deal_flag;
} ST_BILL_UNOWNER_CHG;

typedef struct {
	long	m_pricing_section_id;
	long	m_section_type_id;
	string	m_section_calc_type;
	string	m_pricing_section_name;
	long	m_parent_section_id;
	long	m_pricing_ref_object_id;
	long	m_zone_item_id;
	long	m_cycle_section_begin;
	long	m_cycle_section_duration;
	long	m_start_ref_value_id;
	long	m_end_ref_value_id;
	string	m_judge_result;
	long	m_event_pricing_strategy_id;
	long	m_calc_priority;
} ST_PRICING_SECTION;

typedef struct {
	long	m_serv_id;
	long	m_agreement_id;
	string	m_eff_date;
	string	m_exp_date;
	string	m_billing_mode;
} ST_SERV_BILLING_MODE;

typedef struct {
	long	m_login_accept;
	long	m_acct_id;
	long	m_serv_id;
	long	m_billing_cycle_id;
	long	m_invoice_item_id;
	string	m_item_name;
	long	m_should_pay;
	long	m_favour_fee;
	string	m_item_value;
	string	m_insert_time;
	string	m_resv;
} ST_ZT_INVOICE_DETAIL;

typedef struct {
	long	m_staff_id;
	long	m_staff_org_id;
	long	m_login_accept;
	long	m_acct_id;
	string	m_zt_method;
	long	m_serv_id;
	string	m_cycle_flag;
	long	m_billing_cycle_id;
	string	m_acc_nbr;
	long	m_region_id;
	string	m_acct_name;
	long	m_should_pay;
	long	m_favour_fee;
	long	m_payed_prepay;
	long	m_payed_later;
	long	m_prepay_fee;
	long	m_amount;
	long	m_delay_rate;
	long	m_delay_fee;
	long	m_other_fee;
	long	m_should_fee;
	long	m_payment_id;
	string	m_bill_flag;
	string	m_status;
	string	m_status_flag;
	string	m_status_time;
	string	m_insert_time;
	string	m_resv;
	string	m_new_status;
	string	m_operate_time;
	string	m_note;
	long	m_syn_id;
} ST_ZT_OPR_LOG;

typedef struct {
	long	m_group_id;
	long	m_group_type_id;
	string	m_group_desc;
	long	m_cust_id;
	long	m_cust_agreement_id;
	long	m_offer_id;
	string	m_state;
	string	m_state_date;
	string	m_eff_date;
	string	m_exp_date;
	string	m_grp_attr;
} ST_GROUP_INSTANCE;

typedef struct {
	long	m_invoice_id;
	long	m_invoice_item_id;
	string	m_item_name;
	string	m_item_value;
} ST_INVOICE_DETAIL;

typedef struct {
	long	m_party_id;
	string	m_pard_code;
	string	m_pard_type;
	string	m_pard_desc;
} ST_PARTNER;

typedef struct {
	long	m_eval_rule_id;
	string	m_eval_rule_name;
	long	m_target_id;
	long	m_eval_plan_id;
	long	m_factor_catg_id;
	long	m_default_value;
	long	m_percentage;
	string	m_comments;
} ST_EVAL_RULE;

typedef struct {
	long	m_serv_id;
	long	m_group_id;
	string	m_favour_type;
	long	m_billing_cycle_id;
	long	m_discount_express_id;
	long	m_pricing_plan_id;
	long	m_discount_strategy_id;
	long	m_acct_item_type_id;
	long	m_discount;
	string	m_deal_time;
} ST_DISCOUNT_RESULT;

typedef struct {
	string	m_query_type;
	string	m_fee_name;
	string	m_title_name;
} ST_CDR_QUERY_TYPE;

typedef struct {
	string	m_region_code;
	string	m_plan_code;
	string	m_plan_name;
	string	m_state;
	string	m_state_date;
	string	m_plan_desc;
} ST_OWE_BUSINESS_PLAN;

typedef struct {
	long	m_bill_item_type_id;
	long	m_item_source_id;
	long	m_acct_item_type_id;
} ST_BILL_ACCT_ITEM;

typedef struct {
	long	m_serv_id;
	string	m_acc_nbr;
	long	m_acct_id;
	string	m_delay_time;
	long	m_staff_id;
	string	m_op_code;
	string	m_op_time;
	string	m_reason_desc;
	string	m_state;
	string	m_state_date;
} ST_OWE_BUSINESS_INTERFACE_HIS;

typedef struct {
	long	m_serv_product_id;
	long	m_serv_id;
	long	m_agreement_id;
	long	m_product_id;
	string	m_created_date;
	string	m_eff_date;
	string	m_exp_date;
	string	m_state;
	string	m_stop_rent_time;
	string	m_begin_rent_time;
} ST_SERV_PRODUCT;

typedef struct {
	long	m_offer_param_instance_id;
	long	m_product_offer_instance_id;
	long	m_life_cycle_id;
	long	m_offer_param_id;
	string	m_param_value;
	string	m_param_attr_id;
} ST_PRODUCT_OFFER_PARAM_INSTANCE;

typedef struct {
	long	m_bill_unowner_id;
	string	m_acc_nbr;
	string	m_unowner_type;
	string	m_region_code;
	string	m_imsi_no;
	long	m_unowner_fee;
	long	m_unowner_count;
	string	m_unowner_begin_time;
	string	m_unowner_last_time;
	string	m_insert_time;
	string	m_state;
	string	m_state_date;
} ST_BILL_UNOWNER_INFO_HIS;

typedef struct {
	long	m_pricing_combine_id;
	long	m_pricing_plan_id;
	long	m_event_pricing_strategy_id;
	long	m_life_cycle_id;
	long	m_offer_object_id;
	long	m_calc_priority;
} ST_PRICING_COMBINE;

typedef struct {
	long	m_acct_id;
	long	m_rel_acct_id;
	string	m_acct_rel_type;
	long	m_valid_amount;
} ST_ACCT_RELATIONSHIP;

typedef struct {
	long	m_serv_id;
	long	m_agreement_id;
	string	m_eff_date;
	string	m_exp_date;
	string	m_billing_mode;
	string	m_dead_time;
	long	m_dead_staff_id;
	long	m_dead_optsn;
} ST_SERV_BILLING_MODE_DEAD;

typedef struct {
	long	m_serv_id;
	long	m_ob_scheme_id;
	string	m_acc_nbr;
	long	m_awake_step;
	long	m_awake_times;
	string	m_begin_hm;
	string	m_end_hm;
	string	m_effect_mark;
	long	m_limit_call_step;
	long	m_staff_id;
	string	m_oper_time;
	string	m_state;
	string	m_eff_date;
	string	m_exp_date;
	string	m_comments;
} ST_PERSONAL_OWE_SCHEME;

typedef struct {
	long	m_ai_total_id;
	long	m_acct_id;
	long	m_serv_id;
	string	m_acc_nbr;
	long	m_billing_cycle_id;
	long	m_should_pay;
	long	m_favour_fee;
	long	m_times;
	long	m_duration;
	long	m_amount;
	string	m_created_date;
	string	m_state;
	string	m_state_date;
	long	m_month_wrtoff_fee;
	long	m_pay_wrtoff_fee;
} ST_ACCT_ITEM_TOTAL;

typedef struct {
	long	m_balance_relation_id;
	long	m_acct_balance_id;
	string	m_object_type;
	long	m_object_id;
	long	m_priority;
	string	m_attached;
	string	m_dead_time;
	long	m_dead_staff_id;
	long	m_dead_optsn;
	string	m_state;
	string	m_state_date;
} ST_BALANCE_RELATION_DEAD;

typedef struct {
	long	m_bill_unowner_id;
	string	m_acc_nbr;
	string	m_unowner_type;
	string	m_region_code;
	string	m_imsi_no;
	long	m_unowner_fee;
	long	m_unowner_count;
	string	m_unowner_begin_time;
	string	m_unowner_last_time;
	string	m_insert_time;
	string	m_state;
	string	m_state_date;
} ST_BILL_UNOWNER_INFO;

typedef struct {
	long	m_product_id;
	long	m_event_type_id;
	string	m_eff_date;
	string	m_exp_date;
} ST_PRODUCT_USAGE_EVENT_TYPE;

typedef struct {
	long	m_member_type_id;
	string	m_member_type_name;
	string	m_member_type_desc;
} ST_GROUP_MEMBER_TYPE;

typedef struct {
	long	m_acct_id;
	long	m_serv_id;
	string	m_deposit_type;
	long	m_deposit_fee;
	string	m_valid_begin;
	string	m_valid_end;
	string	m_unpay_begin;
	string	m_unpay_end;
	long	m_last_deposit;
	long	m_add_deposit;
} ST_DEPOSIT_FEE;

typedef struct {
	long	m_acct_balance_id;
	long	m_acct_id;
	long	m_balance_type_id;
	long	m_balance;
	long	m_reserve_balance;
	long	m_cycle_upper;
	long	m_cycle_lower;
	string	m_cycle_upper_type;
	string	m_cycle_lower_type;
	string	m_payment_date;
	string	m_bill_month_flag;
	string	m_eff_date;
	string	m_exp_date;
	string	m_state;
	string	m_state_date;
	string	m_his_date;
} ST_ACCT_BALANCE_HIS;

typedef struct {
	string	m_order_id;
	long	m_command_id;
	string	m_hlr_code;
	string	m_command_code;
	long	m_command_order;
	long	m_serv_id;
	string	m_belong_code;
	string	m_sm_code;
	string	m_acc_nbr;
	string	m_new_acc_nbr;
	string	m_imsi_no;
	string	m_new_imsi;
	string	m_other_char;
	string	m_op_code;
	long	m_total_date;
	string	m_op_time;
	string	m_staff_code;
	string	m_org_code;
	long	m_login_accept;
	string	m_request_time;
	string	m_business_status;
	string	m_send_status;
	string	m_send_time;
	string	m_group_id;
	string	m_org_id;
	string	m_succ_flag;
	string	m_err_msg;
	string	m_city_id;
} ST_UNOWNER_INFO_INTERFACE;

typedef struct {
	long	m_member_id;
	long	m_group_id;
	string	m_acc_nbr;
	string	m_short_num;
	long	m_serv_id;
	string	m_member_desc;
	long	m_member_type_id;
	long	m_member_role_id;
	long	m_life_cycle_id;
	long	m_member_object_id;
	string	m_state;
	string	m_state_date;
	string	m_exp_date;
	string	m_eff_date;
	string	m_grp_meb_attr;
	long	m_up_group_id;
} ST_GROUP_INSTANCE_MEMBER;

typedef struct {
	long	m_belong_calc_object_id;
	long	m_sub_calc_object_id;
	string	m_calc_direction;
} ST_AGGREGATE_OBJECT;

typedef struct {
	long	m_favour_present_id;
	long	m_serv_id;
	long	m_present_rule_id;
	string	m_present_type;
	long	m_priority;
	string	m_op_code;
	long	m_present_id;
	long	m_acct_item_group_id;
	long	m_favour_fee;
	long	m_present_rate;
	string	m_eff_date;
	string	m_exp_date;
	string	m_state;
	string	m_state_date;
	long	m_op_sn;
	string	m_op_type;
	string	m_op_time;
} ST_FAVOUR_PRESENT_INFO_ADD;

typedef struct {
	long	m_bank_id;
	string	m_bank_name;
} ST_BANK;

typedef struct {
	long	m_favour_present_id;
	long	m_serv_id;
	long	m_present_rule_id;
	string	m_present_type;
	long	m_priority;
	string	m_op_code;
	long	m_present_id;
	long	m_acct_item_group_id;
	long	m_favour_fee;
	long	m_present_rate;
	string	m_eff_date;
	string	m_exp_date;
	string	m_state;
	string	m_state_date;
} ST_FAVOUR_PRESENT_INFO;

typedef struct {
	long	m_payment_method;
	string	m_payment_method_name;
	long	m_balance_type_id;
} ST_PAYMENT_METHOD;

typedef struct {
	long	m_bill_record_id;
	long	m_bill_format_customize_id;
	long	m_bill_amount;
	string	m_acc_nbr;
	string	m_bill_type;
	string	m_name;
	long	m_address_id;
	string	m_post_date;
	long	m_party_role_id;
	long	m_billing_cycle_id;
} ST_BILL_RECORD;

typedef struct {
	long	m_collect_oper_sn;
	string	m_collect_nbr;
	long	m_acct_id;
	long	m_payment_plan_id;
	long	m_bank_branch_id;
	long	m_collect_ym;
	string	m_collect_oper_type;
	string	m_refuse_type;
	long	m_staff_id;
	string	m_op_time;
	string	m_comments;
} ST_COLLECT_OPRT;

typedef struct {
	long	m_bill_remark_id;
	long	m_bill_variable_id;
	string	m_print_condition;
	string	m_print_format;
	string	m_content;
	long	m_print_line;
	long	m_print_position;
	long	m_print_length;
} ST_BILL_REMARK;

typedef struct {
	string	m_acc_nbr;
	long	m_item_source_id;
	long	m_acct_item_type_id;
	string	m_region_code;
	long	m_unowner_fee;
	string	m_insert_time;
	string	m_state;
	string	m_state_date;
} ST_ACCT_UNOWNER_INFO_HIS;

typedef struct {
	long	m_credit_grade_id;
	string	m_credit_grade_name;
} ST_CREDIT_GRADE;

typedef struct {
	long	m_group_id;
	long	m_z_group_id;
	long	m_agreement_id;
	string	m_relation_type;
	long	m_pricing_plan_id;
	string	m_eff_date;
	string	m_exp_date;
} ST_GROUP_INSTANCE_RELATION;

typedef struct {
	long	m_owe_business_type_id;
	string	m_owe_business_type_name;
	string	m_standard_code;
	string	m_level;
	string	m_old_run;
	string	m_new_run;
	string	m_awake_type;
	long	m_op_times;
	long	m_interval_time;
	string	m_op_code;
} ST_OWE_BUSINESS_TYPE;

typedef struct {
	long	m_serv_id;
	long	m_min_owe_ym;
	long	m_max_owe_ym;
	long	m_owe_fee;
	long	m_acct_id;
	string	m_acc_nbr;
	string	m_belong_code;
	long	m_product_id;
	string	m_month_detail;
	long	m_offer_id;
	string	m_user_flag;
	string	m_action_time;
} ST_STOP_SERV_OWE_CJ;

typedef struct {
	long	m_band_id;
	long	m_ban_band_id;
	string	m_band_type;
	string	m_band_name;
	string	m_band_desc;
	string	m_idea;
	string	m_slogan;
	string	m_created_dat;
	string	m_sm_code;
} ST_BAND;

typedef struct {
	long	m_payment_id;
	long	m_acct_id;
	long	m_serv_id;
	string	m_op_code;
	long	m_staff_id;
	string	m_open_type;
	string	m_state;
	string	m_state_date;
	string	m_op_note;
	string	m_his_date;
} ST_OPEN_INTERFACE_HIS;

typedef struct {
	long	m_offer_id;
	long	m_band_id;
	long	m_pricing_plan_id;
	string	m_offer_attr_type;
	string	m_offer_name;
	string	m_offer_comments;
	string	m_can_be_buy_alone;
	string	m_offer_code;
	long	m_priority;
	string	m_state;
	string	m_eff_date;
	string	m_exp_date;
	string	m_begin_date;
	string	m_end_date;
	string	m_redoflag;
	long	m_min_num;
	long	m_max_num;
	long	m_exp_date_offset;
	long	m_exp_date_offset_unit;
	string	m_user_range;
	long	m_offer_type;
	string	m_state_chg_date;
	string	m_offer_crt_date;
	long	m_group_type_id;
	long	m_group_limit_rule;
	string	m_prod_offer_publisher;
	string	m_custom_request;
	string	m_operation_modle;
	string	m_eff_type;
	string	m_exp_type;
	long	m_min_order_num;
	long	m_max_order_num;
	string	m_if_cust_price;
} ST_PRODUCT_OFFER;

typedef struct {
	long	m_balance_relation_id;
	long	m_acct_balance_id;
	string	m_object_type;
	long	m_object_id;
	long	m_priority;
	string	m_attached;
	string	m_state;
	string	m_state_date;
} ST_BALANCE_RELATION;

typedef struct {
	long	m_seq_no;
	string	m_group_id;
	string	m_boss_org_code;
	string	m_group_name;
	long	m_root_distance;
	string	m_class_code;
	string	m_is_active;
	string	m_active_time;
	string	m_op_type;
	string	m_deal_flag;
	string	m_deal_time;
} ST_CHN_GROUP_MSG_CHG;

typedef struct {
	long	m_acct_item_type_id;
	long	m_owe_business_type_id;
} ST_OWE_TYPE_ACCTTYPE;

typedef struct {
	long	m_order_accept;
	string	m_serv_order_id;
	string	m_login_no;
	string	m_op_code;
	string	m_insert_time;
	long	m_id_no;
	long	m_contract_no;
	string	m_deal_flag;
	string	m_deal_time;
} ST_BUSI_ORDER_INTERFACE;

typedef struct {
	long	m_region_id;
	string	m_owner_code;
	string	m_type_name;
	string	m_vip_flag;
	string	m_stop_flag;
} ST_SERV_GRADE_CODE;

typedef struct {
	string	m_state;
	long	m_region_id;
	string	m_state_name;
} ST_SERV_STATE_DESC;

typedef struct {
	string	m_serv_order_id;
	long	m_payinfo_id;
	string	m_login_no;
	string	m_op_code;
	long	m_contract_no;
	string	m_phone_no;
	string	m_pay_type;
	string	m_fee_type;
	string	m_fee_code;
	string	m_acc_fee_code;
	string	m_out_fee_code;
	long	m_pay_money;
	string	m_deal_time;
	string	m_deal_result;
} ST_PAY_INFO_HIS;

typedef struct {
	long	m_region_id;
	string	m_region_name;
	string	m_region_desc;
	string	m_region_level;
	string	m_region_class;
	string	m_state;
	string	m_state_date;
} ST_REGION;

typedef struct {
	long	m_acct_id;
	string	m_add_acc_nbr_type;
	string	m_add_acc_nbr;
	string	m_state;
	string	m_state_date;
	string	m_his_date;
	long	m_his_staff_id;
	long	m_his_optsn;
} ST_ACCT_ADD_ACC_NBR_HIS;

typedef struct {
	long	m_serv_id;
	string	m_acc_nbr;
	long	m_acct_id;
	long	m_cust_id;
	long	m_billing_cycle_id;
	long	m_bill_record_id;
	string	m_bill_record_name;
	long	m_should_pay;
	long	m_favour_fee;
	string	m_bill_post_method;
	long	m_region_id;
	long	m_staff_id;
	string	m_insert_time;
} ST_BILL_RECORD_DATA;

typedef struct {
	long	m_discont_express_id;
	long	m_pricing_ref_object_id;
} ST_DISCOUNT_CALC_OBJECT;

typedef struct {
	long	m_serv_id;
	string	m_notification_type;
	string	m_first_date;
	string	m_last_date;
	long	m_times;
	long	m_month_times;
	long	m_durations;
} ST_OWE_NOTIFICATION_INFO;

typedef struct {
	string	m_op_code;
	long	m_attr_id;
	long	m_attr_val;
	string	m_note;
} ST_OWE_BUSINESS_ATTR;

typedef struct {
	long	m_interest_info_id;
	long	m_acct_balance_id;
	long	m_charge;
	string	m_date;
	string	m_state;
} ST_INTEREST_RESPOND;

typedef struct {
	long	m_share_rule_id;
	long	m_acct_balance_id;
	long	m_share_rule_type_id;
	long	m_share_rule_type_pri;
	string	m_object_type;
	long	m_object_id;
	long	m_upper_amount;
	long	m_lower_amount;
	string	m_eff_date;
	string	m_exp_date;
	string	m_calc_method;
	string	m_dead_date;
} ST_BALANCE_SHARE_RULE_DEAD;

typedef struct {
	long	m_credit_result_id;
	long	m_credit_grade_id;
	string	m_object_type;
	long	m_object_id;
	long	m_credit_amount;
	long	m_exception_amount;
	string	m_eff_date;
} ST_CREDIT_RESULT;

typedef struct {
	long	m_acct_id;
	long	m_serv_id;
	string	m_acc_nbr;
	long	m_prepay_fee;
	long	m_limit_owe;
	long	m_owe_fee;
	long	m_unbill_fee;
	string	m_op_time;
} ST_OWE_BALANCE_INFO;

typedef struct {
	string	m_source_table;
	string	m_source_column;
	string	m_dest_table;
	string	m_dest_column;
	string	m_data_type;
	string	m_data_value;
	string	m_index_flag;
	string	m_comb_flag;
} ST_TABLE_SYNC_RELATION;

typedef struct {
	long	m_serv_id;
	long	m_action_type_id;
	string	m_new_status;
	string	m_staff_code;
	string	m_old_status;
	string	m_acc_nbr;
	string	m_billing_mode;
	long	m_product_id;
} ST_STOP_SERV_OWE_BC;

typedef struct {
	long	m_serv_add_acc_nbr_id;
	long	m_serv_id;
	long	m_agreement_id;
	string	m_add_acc_nbr;
	string	m_state;
	string	m_state_date;
	string	m_add_acc_nbr_type;
} ST_SERV_ADD_ACC_NBR;

typedef struct {
	long	m_serv_acct_id;
	long	m_acct_id;
	long	m_serv_id;
	long	m_billing_cycle_type_id;
	long	m_acct_item_group_id;
	long	m_priority;
	long	m_payment_rule_id;
	string	m_payment_limit_type;
	long	m_payment_limit;
	string	m_state;
	string	m_state_date;
	long	m_pay_priority;
	string	m_eff_date;
	string	m_exp_date;
} ST_SERV_ACCT;

typedef struct {
	long	m_address_id;
	string	m_province_name;
	string	m_city_name;
	string	m_street_name;
	string	m_street_nbr;
	string	m_detail;
	string	m_postcode;
} ST_ADDRESS;

typedef struct {
	long	m_bill_item_type_id;
	string	m_classify;
	long	m_bill_parent_id;
	long	m_bill_remark_id;
	long	m_product_offer_id;
	long	m_print_order;
} ST_BILL_ITEM;

typedef struct {
	long	m_serv_id;
	string	m_acc_nbr;
	string	m_plan_code;
	string	m_begin_time;
	string	m_end_time;
	long	m_staff_id;
	string	m_op_type;
	string	m_op_time;
	string	m_op_note;
} ST_OWE_PLAN_CUSTOMIZE;

typedef struct {
	string	m_owe_status;
	string	m_name;
} ST_LOGOUT_STATE;

typedef struct {
	long	m_ratable_cycle_id;
	long	m_ratable_cycle_type_id;
	string	m_cycle_begin_date;
	string	m_cycle_end_date;
	string	m_state;
	string	m_state_date;
} ST_RATABLE_CYCLE;

typedef struct {
	long	m_rule_condition_id;
	string	m_op_code;
	long	m_region_id;
	string	m_condition_type;
	string	m_condition_value;
	string	m_condition_desc;
	string	m_constraint;
} ST_BILL_FORMAT_SELECTOR_RULE;

typedef struct {
	string	m_region_code;
	string	m_unowner_type;
	long	m_unowner_day;
	long	m_unowner_count;
	long	m_unowner_money;
	string	m_state;
	string	m_state_date;
	string	m_rule_desc;
} ST_UNOWNER_DEAL_RULE;

typedef struct {
	string	m_phone_head;
	string	m_region_code;
	string	m_deal_time;
	string	m_deal_flag;
} ST_PHONE_COMM;

typedef struct {
	long	m_acct_id;
	long	m_cust_id;
	string	m_acct_name;
	long	m_address_id;
	string	m_state;
	string	m_state_date;
	string	m_acct_pwd;
	long	m_region_id;
	string	m_acct_type;
	long	m_owe_min_ym;
	long	m_owe_fee;
	string	m_dead_time;
	long	m_dead_staff_id;
	long	m_dead_optsn;
} ST_ACCT_DEAD;

typedef struct {
	long	m_serv_id;
	long	m_attr_id;
	long	m_agreement_id;
	long	m_offer_id;
	string	m_attr_val;
	string	m_eff_date;
	string	m_exp_date;
	string	m_create_date;
	string	m_state_cd;
	string	m_state_date;
} ST_PRODUCT_OFFER_INSTANCE_ATTR;

typedef struct {
	string	m_acc_nbr;
	long	m_serv_id;
} ST_STOP_SERV_OWE_CJ_OK;

typedef struct {
	string	m_op_type;
	string	m_op_code;
	string	m_operate_type;
	long	m_operate_order;
	long	m_type_flag;
	string	m_type_name;
} ST_OWE_PLAN_SELECT_RULE;

typedef struct {
	long	m_serv_id;
	long	m_agreement_id;
	long	m_address_id;
	long	m_bureau_id;
	long	m_exchange_id;
	long	m_stat_region_id;
	string	m_eff_date;
	string	m_exp_date;
} ST_SERV_LOCATION;

typedef struct {
	long	m_acct_item_class_id;
	string	m_comments;
	string	m_acct_item_class_code;
} ST_ACCT_ITEM_CLASS;

typedef struct {
	string	m_serv_order_id;
	long	m_payinfo_id;
	string	m_login_no;
	string	m_op_code;
	long	m_contract_no;
	string	m_phone_no;
	string	m_pay_type;
	string	m_fee_type;
	string	m_fee_code;
	string	m_acc_fee_code;
	string	m_out_fee_code;
	long	m_pay_money;
} ST_PAY_INFO;

typedef struct {
	long	m_discount_method_id;
	string	m_discount_method_name;
} ST_DISCOUNT_METHOD;

typedef struct {
	long	m_acct_balance_id;
	long	m_interest_balance_total;
	long	m_interest_balance_amount;
	long	m_interest_change_value;
	long	m_calc_begin_ymd;
	long	m_calc_end_ymd;
	long	m_curr_balance;
	long	m_interest_rate_id;
	long	m_staff_id;
	string	m_oper_time;
} ST_INTEREST_BALANCE;

typedef struct {
	long	m_property_ref_id;
	long	m_property_define_id;
	string	m_ref_type;
	string	m_value_type;
	string	m_value_string;
	string	m_ref_fee_type;
} ST_PROPERTY_REF;

typedef struct {
	long	m_acct_item_type_id;
	long	m_acct_item_class_id;
	long	m_party_role_id;
	long	m_priority;
	string	m_name;
	string	m_charge_mark;
	string	m_total_mark;
	string	m_acct_item_type_code;
	long	m_parent_item_type_id;
} ST_ACCT_ITEM_TYPE;

typedef struct {
	long	m_balance_relation_id;
	long	m_acct_balance_id;
	string	m_object_type;
	long	m_object_id;
	long	m_priority;
	string	m_attached;
	string	m_his_date;
	string	m_state;
	string	m_state_date;
} ST_BALANCE_RELATION_HIS;

typedef struct {
	long	m_offer_id;
	string	m_element_type;
	long	m_element_id;
	long	m_element_code;
	string	m_offer_detail_role_cd;
	string	m_element_desc;
	long	m_object_amount_start;
	long	m_object_amount_end;
	long	m_order_deal_flag;
	long	m_bill_flag;
	long	m_mem_priority;
	string	m_is_pricing_obj;
	string	m_state;
	string	m_create_date;
	string	m_state_date;
	long	m_rule_id;
	string	m_sel_flag;
} ST_PRODUCT_OFFER_DETAIL;

typedef struct {
	long	m_deposit_opr_sn;
	long	m_acct_id;
	long	m_serv_id;
	string	m_deposit_type;
	long	m_deposit_fee;
	string	m_op_code;
	long	m_staff_id;
	string	m_op_time;
	string	m_note;
} ST_DEPOSIT_OPR;

typedef struct {
	long	m_login_accept;
	long	m_total_date;
	string	m_op_code;
	long	m_payment_method;
	long	m_pay_money;
	long	m_band_id;
	long	m_serv_id;
	string	m_acc_nbr;
	string	m_op_time;
	string	m_op_note;
	string	m_ip_addr;
	long	m_staff_org_id;
	long	m_nbr_org_id;
	long	m_staff_id;
} ST_STAFF_OPR;

typedef struct {
	long	m_ratable_cycle_type_id;
	string	m_ratable_cycle_type_name;
	string	m_cycle_unit;
	long	m_unit_count;
	long	m_cycle_duration;
	long	m_cycle_duration_days;
	long	m_offset_time;
} ST_RATABLE_CYCLE_TYPE;

typedef struct {
	long	m_op_sn;
	string	m_op_type;
	string	m_op_time;
	long	m_acct_balance_id;
	long	m_acct_id;
	long	m_balance_type_id;
	long	m_balance;
	long	m_reserve_balance;
	long	m_cycle_upper;
	long	m_cycle_lower;
	string	m_cycle_upper_type;
	string	m_cycle_lower_type;
	string	m_payment_date;
	string	m_bill_month_flag;
	string	m_eff_date;
	string	m_exp_date;
	string	m_state;
	string	m_state_date;
} ST_MMDB_ACCT_BALANCE_INC;

typedef struct {
	long	m_favour_present_id;
	long	m_ratable_cycle_id;
	long	m_old_favour_fee;
	long	m_curr_favour_fee;
	string	m_deal_date;
} ST_FAVOUR_PRESENT_DETAIL;

typedef struct {
	long	m_invoice_id;
	long	m_payment_id;
	long	m_billing_cycle_id;
	string	m_name;
	long	m_party_role_id;
	long	m_bill_format_customize_id;
	string	m_acc_nbr;
	long	m_amount;
	long	m_count;
	long	m_print_count;
	string	m_print_flag;
	string	m_invoice_type;
	string	m_oper_time;
} ST_INVOICE;

typedef struct {
	long	m_serv_id;
	long	m_agreement_id;
	long	m_attr_id;
	string	m_attr_val;
	string	m_eff_date;
	string	m_exp_date;
	string	m_dead_time;
	long	m_dead_staff_id;
	long	m_dead_optsn;
} ST_SERV_ATTR_DEAD;

typedef struct {
	long	m_logical_address_id;
	long	m_address_id;
	string	m_logical_address_type;
	string	m_logical_address_detail;
} ST_LOGICAL_ADDRESS;

typedef struct {
	long	m_tariff_unit_id;
	long	m_measure_method_id;
	string	m_tariff_unit_name;
	long	m_standard_conversion_rate;
} ST_TARIFF_UNIT;

typedef struct {
	long	m_ratable_resource_id;
	string	m_owner_type;
	long	m_owner_id;
	long	m_ratable_cycle_id;
	long	m_balance;
	long	m_origin_balance;
	long	m_ratable_object_id;
} ST_RATABLE_RESOURCE_ACCUMULATOR;

typedef struct {
	long	m_balance_source_id;
	string	m_balance_source_desc;
} ST_BALANCE_SOURCE_TYPE;

typedef struct {
	long	m_login_accept;
	long	m_staff_id;
	string	m_op_time;
	long	m_adj_fee;
	string	m_state;
	string	m_op_reason;
	string	m_op_note;
	string	m_op_code;
} ST_ADJUST_APPROVAL_TOTAL;

typedef struct {
	long	m_action_id;
	long	m_action_type_id;
	string	m_action_name;
} ST_ACTION;

typedef struct {
	long	m_attr_id;
	string	m_attr_desc;
} ST_SERV_ATTR_TYPE;

typedef struct {
	long	m_intid;
	string	m_acct_id;
	string	m_serv_type_id;
	string	m_area_code;
	string	m_serv_nbr;
	long	m_action_type;
	long	m_sum_charge;
	string	m_month_detail;
	string	m_action_time;
	string	m_start_date;
	string	m_end_date;
	string	m_created_date;
	long	m_tsucccnt;
	long	m_dsucccnt;
	long	m_tfailcnt;
	long	m_dfailcnt;
	long	m_ntsucccnt;
	long	m_ndsucccnt;
	long	m_ntfailcnt;
	long	m_ndfailcnt;
	long	m_nfailreason;
	string	m_first_succ_date;
	long	m_ncjjfflag;
	long	m_updateflag;
	string	m_updatetime_cc;
	string	m_updatetime_kf;
	long	m_do_flag;
} ST_TIF_OWE_NOTIFICATION;

typedef struct {
	long	m_event_pricing_strategy_id;
	long	m_event_type_id;
	string	m_event_pricing_strategy_name;
	string	m_event_pricing_strategy_desc;
	string	m_event_pricing_feetypes;
	string	m_event_pricing_billtype;
	string	m_vpnflag;
} ST_EVENT_PRICING_STRATEGY;

typedef struct {
	long	m_pricing_rule_id;
	long	m_pricing_section_id;
	long	m_pricing_ref_object_id;
	long	m_operator_id;
	long	m_result_ref_value_id;
	long	m_group_id;
} ST_PRICING_RULE;

typedef struct {
	long	m_credit_grade_rule_id;
	long	m_credit_grade_id;
	long	m_credit_ceil;
	long	m_credit_floor;
	string	m_credit_grade_name;
	string	m_eff_date;
	string	m_exp_date;
} ST_CREDIT_GRADE_RULE;

typedef struct {
	long	m_serv_id;
	long	m_agreement_id;
	string	m_acc_nbr;
	string	m_eff_date;
	string	m_exp_date;
} ST_SERV_IDENTIFICATION;

typedef struct {
	long	m_pay_id;
	long	m_login_accept;
	long	m_cust_id;
	long	m_acct_id;
	long	m_serv_id;
	long	m_amount;
	long	m_delay_fee;
	long	m_prepay_fee;
	long	m_other_fee;
	long	m_should_fee;
	long	m_balance_fee;
	long	m_pay_money;
	string	m_acc_nbr;
	string	m_deal_flag;
	long	m_staff_id;
	string	m_op_time;
} ST_CUST_OWE_TOTAL;

typedef struct {
	long	m_payment_id;
	string	m_card_type;
	string	m_card_nbr;
	long	m_card_fee;
} ST_PAY_CARD_OPR;

typedef struct {
	long	m_login_accept;
	long	m_cust_id;
	long	m_cust_location;
	string	m_cust_name;
	string	m_state;
	string	m_eff_date;
	string	m_cust_type;
	string	m_certificate_type;
	string	m_certificate_no;
	string	m_contact_addr;
	long	m_cust_value;
	long	m_pay_money;
	string	m_op_time;
	long	m_print_num;
	string	m_acc_nbr;
} ST_CUST_PAY;

typedef struct {
	long	m_bill_format_selector_id;
	long	m_bill_format_customize_id;
	long	m_bill_format_id;
} ST_BILL_FORMAT_SELECTOR;

typedef struct {
	long	m_payment_id;
	long	m_acct_id;
	long	m_serv_id;
	string	m_op_code;
	long	m_staff_id;
	long	m_payment_method;
	string	m_payment_date;
	long	m_online_flag;
	string	m_state;
	string	m_state_date;
	string	m_op_note;
	long	m_bill_beg_ym;
	long	m_bill_end_ym;
	string	m_his_date;
	string	m_bill_month_flag;
	long	m_serv_pay_flag;
} ST_BILL_INTERFACE_HIS;

typedef struct {
	long	m_acct_id;
	string	m_add_acc_nbr_type;
	string	m_add_acc_nbr;
	string	m_state;
	string	m_state_date;
} ST_ACCT_ADD_ACC_NBR;

typedef struct {
	long	m_product_id;
	long	m_product_provider_id;
	long	m_pricing_plan_id;
	long	m_product_family_id;
	string	m_product_name;
	string	m_product_comments;
	string	m_product_type;
	string	m_product_classification;
	string	m_product_code;
	string	m_state;
	string	m_eff_date;
	string	m_exp_date;
} ST_PRODUCT;

typedef struct {
	string	m_collect_nbr;
	long	m_bill_ym;
	string	m_collect_op_mark;
	long	m_collect_money;
	long	m_refuse_count;
	long	m_collect_count;
	long	m_refuse_money;
} ST_COLLECT_TOTAL;

typedef struct {
	long	m_balance_type_id;
	long	m_priority;
	long	m_spe_payment_id;
	long	m_measure_method_id;
	string	m_balance_type_name;
	string	m_action_mark;
	string	m_pay_type;
} ST_BALANCE_TYPE;

typedef struct {
	long	m_staff_id;
	long	m_staff_org_id;
	long	m_login_accept;
	long	m_acct_id;
	string	m_zt_method;
	long	m_serv_id;
	string	m_cycle_flag;
	long	m_billing_cycle_id;
	string	m_acc_nbr;
	long	m_region_id;
	string	m_acct_name;
	long	m_should_pay;
	long	m_favour_fee;
	long	m_payed_prepay;
	long	m_payed_later;
	long	m_prepay_fee;
	long	m_amount;
	long	m_delay_rate;
	long	m_delay_fee;
	long	m_other_fee;
	long	m_should_fee;
	long	m_payment_id;
	string	m_bill_flag;
	string	m_status;
	string	m_status_flag;
	string	m_status_time;
	string	m_insert_time;
	string	m_resv;
} ST_ZT_OWE_TOTAL_MID;

typedef struct {
	long	m_owe_object_id;
	string	m_owe_object_type;
	string	m_owe_object_desc;
} ST_OWE_OBJECT;

typedef struct {
	long	m_measure_method_id;
	string	m_measure_method_name;
} ST_MEASURE_METHOD;

typedef struct {
	long	m_plus_seq_nbr;
	string	m_acc_nbr;
	long	m_billing_cycle_id;
	long	m_acct_item_type_id;
	long	m_amount;
	string	m_merge_flag;
	string	m_reason;
	long	m_merge_balance;
	long	m_fee_cycle_id;
	long	m_party_role_id;
	string	m_create_date;
	string	m_state;
	string	m_state_date;
} ST_PLUSMINUS;

typedef struct {
	long	m_region_id;
	long	m_parent_region_id;
	string	m_parent_region_level;
	string	m_region_level;
	string	m_region_code;
	string	m_district_num;
	string	m_inter_region_code;
} ST_BILLING_REGION;

typedef struct {
	long	m_event_type_id;
	string	m_name;
	string	m_sum_event_type;
	string	m_event_type_code;
	string	m_state;
	string	m_eff_date;
	string	m_exp_date;
	string	m_event_type_desc;
	string	m_sum_event_flag;
} ST_DEST_EVENT_TYPE;

typedef struct {
	long	m_cust_id;
	long	m_party_role_id;
	string	m_cust_name;
	string	m_cust_type;
	long	m_cust_location;
	string	m_is_vip;
	long	m_parent_id;
	string	m_cust_code;
	string	m_state;
	string	m_eff_date;
	string	m_exp_date;
} ST_CUST;

typedef struct {
	long	m_payment_plan_id;
	long	m_acct_id;
	long	m_payment_method;
	long	m_priority;
	string	m_payment_plan_type;
	long	m_payment_supplie_id;
	string	m_payment_acct_no;
	string	m_payment_acct_cust_name;
	string	m_payment_acct_type;
	string	m_state;
	string	m_state_date;
} ST_PAYMENT_PLAN;

typedef struct {
	long	m_adjust_record_id;
	long	m_acct_item_id;
	long	m_adjust_acct_item_id;
	long	m_charge_adjust;
} ST_ACCT_ITEM_ADJUSTED;

typedef struct {
	long	m_group_type_id;
	string	m_group_type_name;
	string	m_group_type_desc;
	string	m_group_meb_flag;
} ST_GROUP_TYPE;

typedef struct {
	long	m_present_rule_id;
	long	m_region_id;
	long	m_band_id;
	long	m_pay_balance_type_id;
	long	m_amount;
	string	m_present_code;
	string	m_present_name;
	string	m_present_type;
	long	m_present_money;
	long	m_present_month;
	string	m_continue_flag;
	long	m_continue_month;
	long	m_acct_item_group_id;
	long	m_present_rate;
	long	m_delay_month;
	long	m_present_count;
	string	m_eff_date;
	string	m_exp_date;
	string	m_state;
	string	m_state_date;
	string	m_present_rule_desc;
} ST_FAVOUR_PRESENT_RULE;

typedef struct {
	long	m_check_oper_sn;
	long	m_payment_id;
	long	m_bank_branch_id;
	string	m_bank_acct_nbr;
	string	m_bank_acct_name;
	string	m_check_nbr;
	long	m_check_money;
	string	m_check_state;
	string	m_assure_state;
	string	m_assure_time;
	long	m_cust_id;
} ST_CHECK_OPR;

typedef struct {
	long	m_section_type_id;
	string	m_section_type_name;
} ST_PRICING_SECTION_TYPE;

typedef struct {
	string	m_collect_nbr;
	long	m_bill_ym;
	long	m_acct_id;
	long	m_serv_id;
	string	m_acc_nbr;
	long	m_acct_item_type_id;
	long	m_owe_fee;
	string	m_owe_begin_time;
	string	m_owe_end_time;
} ST_COLLECT_DETAIL;

typedef struct {
	long	m_owe_type_limit_id;
	long	m_owe_business_type_id;
	long	m_credit_ceil;
	long	m_credit_floor;
	long	m_quantity;
} ST_OWE_TYPE_LIMIT;

typedef struct {
	long	m_offer_param_id;
	long	m_offer_id;
	long	m_param_attr_id;
	string	m_param_name;
	string	m_default_value;
} ST_PRODUCT_OFFER_PARAM;

typedef struct {
	long	m_pricing_param_id;
	string	m_pricing_param_name;
	string	m_default_value;
} ST_PRICING_PARAM_DEFINE;

typedef struct {
	long	m_org_id;
	long	m_alert_value;
	string	m_update_time;
	long	m_staff_id;
	string	m_note;
} ST_CHN_GROUP_FEE_ALERT;

typedef struct {
	long	m_transfer_account_id;
	string	m_login_no;
	string	m_op_code;
	long	m_id_no;
	long	m_out_crontact_no;
	long	m_in_crontact_no;
	string	m_pay_type;
	long	m_money;
} ST_TRANSFER_ACCOUNT;

typedef struct {
	string	m_table_name;
	string	m_field_name;
	string	m_domain;
	string	m_name;
} ST_SYS_DOMAIN;

typedef struct {
	long	m_serv_id;
	long	m_agreement_id;
	long	m_cust_id;
	long	m_product_id;
	long	m_billing_cycle_type_id;
	long	m_product_family_id;
	string	m_create_date;
	string	m_rent_date;
	string	m_completed_date;
	string	m_state;
	string	m_state_date;
	long	m_region_id;
	long	m_band_id;
	string	m_open_time;
	string	m_bill_start_time;
} ST_SERV;

typedef struct {
	long	m_attr_grp_id;
	string	m_attr_type;
	long	m_sub_sn;
	string	m_group_value;
} ST_CDR_ATTR_GROUP;

typedef struct {
	long	m_staff_id;
	long	m_privilege_id;
} ST_STAFF_PRIVILEGE;

typedef struct {
	long	m_login_accept;
	long	m_cust_id;
	long	m_acct_id;
	long	m_serv_id;
	long	m_billing_cycle_id;
	long	m_amount;
	long	m_delay_fee;
	string	m_acc_nbr;
	long	m_staff_id;
	string	m_op_time;
} ST_CUST_OWE;

typedef struct {
	long	m_payment_id;
	long	m_acct_id;
	long	m_serv_id;
	string	m_op_code;
	long	m_staff_id;
	string	m_open_type;
	string	m_state;
	string	m_state_date;
	string	m_op_note;
} ST_OPEN_INTERFACE;

typedef struct {
	long	m_serv_id;
	long	m_agreement_id;
	long	m_cust_id;
	long	m_product_id;
	long	m_billing_cycle_type_id;
	long	m_product_family_id;
	string	m_create_date;
	string	m_rent_date;
	string	m_completed_date;
	string	m_state;
	string	m_state_date;
	long	m_region_id;
	long	m_band_id;
	string	m_open_time;
	string	m_bill_start_time;
	string	m_dead_time;
	long	m_dead_staff_id;
	long	m_dead_optsn;
} ST_SERV_DEAD;

typedef struct {
	long	m_login_accept;
	string	m_op_code;
	long	m_staff_id;
	string	m_begin_time;
	string	m_end_time;
	long	m_deal_num;
	long	m_succ_num;
	string	m_err_no;
	string	m_err_msg;
} ST_BATCH_LOG;

typedef struct {
	long	m_acct_item_id;
	long	m_item_source_id;
	long	m_bill_id;
	long	m_acct_item_type_id;
	long	m_billing_cycle_id;
	long	m_acct_id;
	long	m_serv_id;
	long	m_amount;
	string	m_created_date;
	long	m_fee_cycle_id;
	long	m_payment_method;
	string	m_state;
	string	m_state_date;
	long	m_latn_id;
	long	m_ai_total_id;
	string	m_acc_nbr;
	long	m_should_pay;
	long	m_favour_fee;
	long	m_times;
	long	m_duration;
	long	m_month_wrtoff_fee;
	long	m_pay_wrtoff_fee;
	string	m_attr_code;
} ST_OWE_ITEM_INFO;

typedef struct {
	long	m_command_id;
	long	m_login_accept;
	long	m_msg_level;
	string	m_acc_nbr;
	string	m_msg;
	long	m_order_code;
	long	m_back_code;
	string	m_dx_op_code;
	string	m_staff_code;
	string	m_op_time;
	string	m_send_time;
} ST_COMMON_SHORT_MSG;

typedef struct {
	long	m_acct_group_id;
	string	m_acct_group_desc;
} ST_ACCT_GROUP;

typedef struct {
	long	m_owe_time_info_id;
	long	m_date_type_id;
	long	m_billing_cycle_id;
	long	m_region_id;
	string	m_date;
} ST_OWE_DATETYPE_INFO;

typedef struct {
	long	m_acct_item_id;
	long	m_item_source_id;
	long	m_bill_id;
	long	m_acct_item_type_id;
	long	m_billing_cycle_id;
	long	m_acct_id;
	long	m_serv_id;
	long	m_amount;
	string	m_created_date;
	long	m_fee_cycle_id;
	long	m_payment_method;
	string	m_state;
	string	m_state_date;
	long	m_latn_id;
	long	m_ai_total_id;
	string	m_acc_nbr;
	long	m_should_pay;
	long	m_favour_fee;
	long	m_times;
	long	m_duration;
	long	m_month_wrtoff_fee;
	long	m_pay_wrtoff_fee;
	string	m_off_time;
	string	m_off_state;
	string	m_off_note;
} ST_ACCT_ITEM_OFF;

typedef struct {
	long	m_acct_id;
	long	m_serv_id;
} ST_OWE_BALANCE_TMP;

typedef struct {
	long	m_serv_id;
	long	m_billing_cycle_type_id;
	long	m_agreement_id;
	long	m_owe_business_type_id;
	string	m_state;
	string	m_eff_date;
	string	m_exp_date;
} ST_SERV_STATE_ATTR;

typedef struct {
	long	m_transfer_account_id;
	string	m_login_no;
	string	m_op_code;
	long	m_id_no;
	long	m_out_crontact_no;
	long	m_in_crontact_no;
	string	m_pay_type;
	long	m_money;
	string	m_deal_time;
	string	m_deal_result;
} ST_TRANSFER_ACCOUNT_HIS;

typedef struct {
	long	m_operator_id;
	string	m_operator_name;
} ST_OPERATOR;

typedef struct {
	long	m_acct_balance_id;
	long	m_acct_id;
	long	m_balance_type_id;
	long	m_balance;
	long	m_reserve_balance;
	long	m_cycle_upper;
	long	m_cycle_lower;
	string	m_cycle_upper_type;
	string	m_cycle_lower_type;
	string	m_payment_date;
	string	m_bill_month_flag;
	string	m_eff_date;
	string	m_exp_date;
	string	m_state;
	string	m_state_date;
	string	m_dead_time;
	long	m_dead_staff_id;
	long	m_dead_optsn;
} ST_ACCT_BALANCE_DEAD;

typedef struct {
	long	m_serv_id;
	long	m_agreement_id;
	long	m_address_id;
	long	m_bureau_id;
	long	m_exchange_id;
	long	m_stat_region_id;
	string	m_eff_date;
	string	m_exp_date;
	string	m_dead_time;
	long	m_dead_staff_id;
	long	m_dead_optsn;
} ST_SERV_LOCATION_DEAD;

typedef struct {
	long	m_serv_id;
	long	m_billing_cycle_type_id;
	long	m_agreement_id;
	long	m_owe_business_type_id;
	string	m_state;
	string	m_eff_date;
	string	m_exp_date;
	string	m_dead_time;
	long	m_dead_staff_id;
	long	m_dead_optsn;
} ST_SERV_STATE_ATTR_DEAD;

typedef struct {
	long	m_payment_id;
	long	m_payment_method;
	long	m_party_role_id;
	long	m_payed_method;
	string	m_operation_type;
	string	m_op_code;
	long	m_operated_payment_serial_nbr;
	long	m_amount;
	string	m_payment_date;
	string	m_state;
	string	m_state_date;
	string	m_created_date;
	long	m_invoice_id;
	long	m_acct_id;
	long	m_staff_org_id;
	long	m_nbr_org_id;
	long	m_serv_id;
} ST_PAYMENT;

typedef struct {
	long	m_spe_payment_id;
	string	m_spe_payment_desc;
} ST_SPECIAL_PAYMENT_DESC;

typedef struct {
	long	m_enum_id;
	long	m_pricing_param_id;
	string	m_param_value;
} ST_PRICING_ENUM_PARAM;

typedef struct {
	long	m_date_type_id;
	string	m_date_type_code;
	string	m_date_type_name;
} ST_OWE_DATE_TYPE;

typedef struct {
	string	m_region_code;
	string	m_shortmsg_code;
	string	m_shortmsg_name;
	long	m_shortmsg_level;
	long	m_subsection_num;
} ST_OWE_SHORTMSG_CODE;

typedef struct {
	long	m_item_ref_id;
	long	m_zone_item_id;
	string	m_item_ref_value;
} ST_ZONE_ITEM_VALUE;

typedef struct {
	long	m_cust_id;
	long	m_agreement_id;
	string	m_certificate_type;
	string	m_certificate_no;
	string	m_eff_date;
	string	m_exp_date;
	string	m_attest_type;
	string	m_attest_passwd;
	string	m_secrecy_level;
} ST_CUST_IDENTIFICATION;

typedef struct {
	long	m_org_id;
	string	m_prepay_type;
	long	m_prepay_fee;
	long	m_op_accept;
	long	m_staff_id;
	string	m_op_time;
	string	m_op_code;
	string	m_note;
} ST_CHN_ACC_MSG_LIST;

typedef struct {
	long	m_id_no;
	string	m_attr_code;
	long	m_limit_owe;
	string	m_deal_flag;
	string	m_deal_time;
} ST_USER_ATTR_CHG;

typedef struct {
	long	m_owner_id;
	string	m_owner_object_type;
	string	m_charge_party_id;
} ST_OWNER;

typedef struct {
	long	m_serv_id;
	long	m_cust_id;
	long	m_product_id;
	string	m_state;
	string	m_state_date;
	string	m_acc_nbr;
	string	m_group_id;
	string	m_eff_date;
	string	m_exp_date;
	string	m_billing_mode;
} ST_STOP_SERV_STATE;

typedef struct {
	long	m_bill_format_id;
	long	m_bill_remark_id;
	string	m_format_name;
} ST_BILL_FORMAT;

typedef struct {
	string	m_function_name;
	string	m_dest_table;
	string	m_src_table;
	string	m_id_flag;
	string	m_billing_cycle_id;
	string	m_op_flag;
	long	m_ctr_flag;
	string	m_src_table_space;
	string	m_dest_table_space;
	string	m_index_space;
	string	m_table_owner;
	string	m_note;
} ST_BILL_REPORT_ATTR;

typedef struct {
	string	m_certificate_type;
	string	m_certificate_type_name;
	long	m_certificate_length;
} ST_CERTIFICATE_TYPE;

typedef struct {
	long	m_acct_group_id;
	long	m_acct_id;
	string	m_role;
} ST_ACCT_GROUP_MEMBER;

typedef struct {
	long	m_cust_id;
	long	m_agreement_id;
	string	m_contact_name;
	string	m_contact_gender;
	string	m_contact_addr;
	string	m_contact_company;
	string	m_duty_desc;
	string	m_telephone;
	string	m_mobile;
	string	m_post_code;
	string	m_email_address;
	string	m_fax;
	string	m_comments;
	string	m_eff_date;
	string	m_exp_date;
} ST_CUST_CONTACT_INFO;

typedef struct {
	long	m_command_id;
	long	m_login_accept;
	long	m_msg_level;
	string	m_acc_nbr;
	string	m_msg;
	long	m_order_code;
	long	m_back_code;
	string	m_dx_op_code;
	string	m_staff_code;
	string	m_op_time;
} ST_OWE_TOTAL_SHORT_MSG;

typedef struct {
	long	m_privilege_id;
	long	m_parent_privilegeid;
	string	m_privilege_name;
	string	m_privilege_type;
	string	m_app_code;
	string	m_privilege_desc;
} ST_PRIVILEGE;

typedef struct {
	long	m_derate_rule_id;
	string	m_rule_desc;
	long	m_region_id;
	string	m_derate_object_type;
	string	m_derate_object_value;
	string	m_derate_type;
	long	m_derate_fee;
} ST_DELAY_DERATE_RULE;

typedef struct {
	long	m_serv_id;
	string	m_acc_nbr;
	long	m_acct_id;
	string	m_delay_time;
	long	m_staff_id;
	string	m_op_code;
	string	m_op_time;
	string	m_reason_desc;
	string	m_state;
	string	m_state_date;
} ST_OWE_BUSINESS_INTERFACE;

typedef struct {
	long	m_payment_plan_id;
	long	m_acct_id;
	long	m_payment_method;
	long	m_priority;
	string	m_payment_plan_type;
	long	m_payment_supplie_id;
	string	m_payment_acct_no;
	string	m_payment_acct_cust_name;
	string	m_payment_acct_type;
	string	m_state;
	string	m_state_date;
	string	m_dead_time;
	long	m_dead_staff_id;
	long	m_dead_optsn;
} ST_PAYMENT_PLAN_DEAD;

typedef struct {
	long	m_query_code;
	string	m_query_type;
} ST_CDR_QUERY_CODE;

typedef struct {
	long	m_acct_item_id;
	long	m_item_source_id;
	long	m_bill_id;
	long	m_acct_item_type_id;
	long	m_billing_cycle_id;
	long	m_acct_id;
	long	m_serv_id;
	long	m_amount;
	string	m_created_date;
	long	m_fee_cycle_id;
	long	m_payment_method;
	string	m_state;
	string	m_state_date;
	long	m_latn_id;
	long	m_ai_total_id;
	string	m_acc_nbr;
	long	m_should_pay;
	long	m_favour_fee;
	long	m_times;
	long	m_duration;
	long	m_month_wrtoff_fee;
	long	m_pay_wrtoff_fee;
	string	m_attr_code;
} ST_ACCT_ITEM;

typedef struct {
	long	m_acct_item_group_id;
	string	m_acct_item_group_name;
	long	m_priority;
	string	m_state;
	string	m_state_date;
	string	m_acct_item_group_type;
} ST_ACCT_ITEM_GROUP;

typedef struct {
	long	m_org_id;
	string	m_credit_code;
	long	m_credit_value;
	long	m_used_credit;
	long	m_op_accept;
	long	m_staff_id;
	string	m_op_time;
	string	m_op_code;
	string	m_note;
} ST_CHN_ACC_CREDIT_DET;

typedef struct {
	long	m_acct_id;
	string	m_add_acc_nbr_type;
	string	m_add_acc_nbr;
	string	m_state;
	string	m_state_date;
	string	m_dead_time;
	long	m_dead_staff_id;
	long	m_dead_optsn;
} ST_ACCT_ADD_ACC_NBR_DEAD;

typedef struct {
	long	m_region_id;
	string	m_begin_time;
	string	m_end_time;
	string	m_call_name;
} ST_CDR_CALL_NAME;

typedef struct {
	long	m_oper_payout_id;
	long	m_acct_balance_id;
	long	m_billing_cycle_id;
	long	m_bill_id;
	string	m_oper_type;
	string	m_oper_date;
	long	m_amount;
	long	m_balance;
	long	m_prn_count;
	long	m_balance_relation_id;
	long	m_staff_id;
	string	m_state;
	string	m_state_date;
} ST_BALANCE_PAYOUT;

typedef struct {
	long	m_payment_rule_id;
	long	m_cust_agreement_id;
	string	m_name;
	string	m_comments;
} ST_PAYMENT_RULE;

typedef struct {
	long	m_spe_payment_id;
	long	m_partner_id;
	long	m_product_id;
	long	m_acct_item_group_id;
} ST_SPECIAL_PAYMENT;

typedef struct {
	long	m_discount_time_limit_id;
	long	m_discount_express_id;
	string	m_discount_cycle_type;
	string	m_begin_time_type;
	long	m_begin_calc_object;
	long	m_begin_time_duration;
	string	m_end_time_type;
	long	m_end_calc_object;
	long	m_end_time_duration;
} ST_DISCOUNT_TIME_LIMIT;

typedef struct {
	long	m_share_rule_type_id;
	string	m_share_rule_type_name;
} ST_SHARE_RULE_TYPE;

typedef struct {
	long	m_login_accept;
	long	m_acct_id;
	long	m_serv_id;
	string	m_acc_nbr;
	long	m_payment_method;
	long	m_pay_money;
	string	m_pay_note;
	long	m_staff_id;
	string	m_insert_date;
	string	m_state;
	string	m_state_date;
	long	m_payment_id;
	string	m_payment_date;
} ST_PAY_INTERFACE_HIS;

typedef struct {
	long	m_offer_attr_seq;
	long	m_offer_id;
	long	m_attr_value_type_id;
	long	m_attr_value_unit_id;
	string	m_offer_attr_character;
	string	m_offer_attr_value;
	string	m_allow_customized_flag;
	string	m_excluablity;
	string	m_if_default_value;
	string	m_element_type;
	long	m_element_id;
	long	m_min_value;
	long	m_max_value;
	string	m_create_date;
	string	m_state;
	string	m_state_date;
	long	m_attr_value_res;
	long	m_showorder;
} ST_PRODUCT_OFFER_ATTR;

typedef struct {
	long	m_staff_id;
	long	m_staff_org_id;
	long	m_login_accept;
	string	m_operate_type;
	string	m_operate_code;
	string	m_operate_time;
	string	m_ztperson_name;
	string	m_note;
} ST_ZT_STAFF_LOG;

typedef struct {
	long	m_seq_no;
	long	m_contract_no;
	string	m_post_flag;
	string	m_post_type;
	string	m_post_address;
	string	m_post_zip;
	string	m_fax_no;
	string	m_mail_address;
	long	m_id_no;
	string	m_post_name;
	long	m_postno_flag;
	string	m_content_type;
	long	m_post_cyc;
	string	m_op_type;
	string	m_deal_flag;
	string	m_deal_time;
} ST_CUST_POST_CHG;

typedef struct {
	long	m_item_source_id;
	long	m_acct_item_type_id;
	long	m_acct_item_group_id;
	string	m_state;
	string	m_state_date;
} ST_ACCT_ITEM_GROUP_MEMBER;

typedef struct {
	string	m_region_code;
	string	m_sm_code;
	string	m_operate_type;
	string	m_operate_code;
	string	m_plan_code;
	string	m_state;
	string	m_state_date;
} ST_OWE_PLAN_SELECT;

typedef struct {
	long	m_discount_express_id;
	long	m_discount_method_id;
	long	m_ratable_resource_id;
	long	m_start_ref_value_id;
	long	m_end_ref_value_id;
	long	m_pricing_section_id;
	long	m_discount_rate_value_id;
	long	m_fixed_value_id;
	long	m_calc_priority;
} ST_DISCOUNT_EXPRESS;

typedef struct {
	long	m_delay_fav_id;
	long	m_acct_id;
	long	m_serv_id;
	long	m_year_month;
	long	m_delay_fee;
	long	m_favour_fee;
	long	m_favour_rate;
	string	m_favour_type;
	long	m_total_date;
	long	m_staff_id;
	long	m_region_id;
	string	m_validity_date;
	string	m_audit_flag;
} ST_DELAY_FAVOUR;

typedef struct {
	long	m_region_id;
	string	m_payment_plan_type;
	string	m_payment_plan_type_name;
	string	m_highfee_flag;
	long	m_predel_month;
	long	m_del_month;
} ST_PAYMENT_PLAN_TYPE;

typedef struct {
	long	m_member_role_id;
	string	m_member_role_name;
	string	m_member_role_desc;
} ST_GROUP_INSTANCE_ROLE;

typedef struct {
	long	m_billing_cycle_id;
	long	m_billing_cycle_type_id;
	string	m_cycle_begin_date;
	string	m_cycle_end_date;
	string	m_due_date;
	string	m_block_date;
	long	m_last_billing_cycle_id;
	string	m_state;
	string	m_state_date;
	string	m_bill_month_flag;
} ST_BILLING_CYCLE;

typedef struct {
	long	m_login_accept;
	long	m_acct_item_id;
	long	m_acct_item_type_id;
	string	m_acc_nbr;
	long	m_acct_id;
	long	m_bill_month;
	long	m_adj_fee;
	long	m_staff_id;
	long	m_serv_id;
	string	m_op_note;
	string	m_op_time;
	long	m_payment_method;
	string	m_sign_state;
	string	m_op_code;
	long	m_sign_staff_id;
	string	m_sign_time;
	string	m_ins_time;
	long	m_ins_staff_id;
	string	m_ins_op_code;
	long	m_ins_accept;
} ST_ADJUST_APPROVAL_HIS;

typedef struct {
	long	m_total_date;
	long	m_login_accept;
	string	m_op_code;
	string	m_acc_nbr;
	long	m_serv_id;
	long	m_band_id;
	long	m_staff_id;
	long	m_region_id;
	string	m_op_time;
	string	m_op_flag;
	string	m_op_note;
	long	m_data1;
	string	m_name1;
	long	m_data2;
	string	m_name2;
	long	m_data3;
	string	m_name3;
	long	m_data4;
	string	m_name4;
	long	m_data5;
	string	m_name5;
} ST_BATCH_LOG_DET;

typedef struct {
	string	m_state_type;
	string	m_note;
	string	m_trig_type;
} ST_BALANCE_STATE;

typedef struct {
	long	m_serv_id;
	long	m_agreement_id;
	long	m_attr_id;
	string	m_attr_val;
	string	m_eff_date;
	string	m_exp_date;
} ST_SERV_ATTR;

typedef struct {
	long	m_ai_total_id;
	long	m_acct_id;
	long	m_serv_id;
	string	m_acc_nbr;
	long	m_billing_cycle_id;
	long	m_should_pay;
	long	m_favour_fee;
	long	m_times;
	long	m_duration;
	long	m_amount;
	string	m_created_date;
	string	m_state;
	string	m_state_date;
	long	m_month_wrtoff_fee;
	long	m_pay_wrtoff_fee;
	string	m_off_time;
	string	m_off_state;
	string	m_off_note;
} ST_ACCT_ITEM_TOTAL_OFF;

typedef struct {
	long	m_item_source_id;
	long	m_acct_item_type_id;
	string	m_item_source_type;
	string	m_name;
	string	m_comments;
} ST_ACCT_ITEM_SOURCE;

typedef struct {
	long	m_life_cycle_id;
	string	m_state;
	string	m_eff_type;
	string	m_eff_date;
	string	m_exp_date;
	string	m_eff_value;
	string	m_exp_value;
	string	m_group_id;
	string	m_constraint;
} ST_LIFE_CYCLE;

typedef struct {
	long	m_eval_plan_id;
	string	m_eval_plan_name;
	string	m_eval_type;
	string	m_eval_object_type;
	string	m_eval_desc;
} ST_EVAL_PLAN;

typedef struct {
	string	m_region_code;
	string	m_shortmsg_code;
	long	m_serial_no;
	long	m_parameter_no;
	string	m_shortmsg_content;
} ST_OWE_SHORTMSG_CONTENT;

typedef struct {
	long	m_integral_reault_id;
	string	m_object_type;
	long	m_object_id;
	long	m_current_integral_value;
	long	m_acc_amount;
	long	m_present_value;
	long	m_exception_amount;
} ST_INTEGRAL_RESULT;

typedef struct {
	long	m_serv_add_acc_nbr_id;
	long	m_serv_id;
	long	m_agreement_id;
	string	m_add_acc_nbr;
	string	m_state;
	string	m_state_date;
	string	m_add_acc_nbr_type;
	string	m_dead_time;
	long	m_dead_staff_id;
	long	m_dead_optsn;
} ST_SERV_ADD_ACC_NBR_DEAD;

typedef struct {
	long	m_tariff_id;
	string	m_tariff_type;
	long	m_pricing_section_id;
	long	m_resource_id;
	long	m_action_id;
	long	m_acct_item_type_id;
	long	m_sub_product_id;
	long	m_tariff_unit_id;
	long	m_calc_method_id;
	long	m_rate_unit;
	long	m_fixed_rate_value_id;
	long	m_scaled_rate_value_id;
	long	m_calc_priority;
	long	m_belong_cycle_duration;
	string	m_charge_party_id;
} ST_TARIFF;

typedef struct {
	long	m_payment_id;
	string	m_card_type;
	string	m_card_nbr;
	long	m_card_fee;
	string	m_his_date;
} ST_PAY_CARD_OPR_HIS;

typedef struct {
	string	m_acc_nbr;
	long	m_item_source_id;
	long	m_acct_item_type_id;
	string	m_region_code;
	long	m_unowner_fee;
	string	m_insert_time;
	string	m_state;
	string	m_state_date;
} ST_ACCT_UNOWNER_INFO;

typedef struct {
	long	m_login_accept;
	long	m_acct_id;
	string	m_zt_method;
	long	m_serv_id;
	string	m_cycle_flag;
	long	m_billing_cycle_id;
	string	m_acc_nbr;
	long	m_region_id;
	string	m_acct_name;
	long	m_should_pay;
	long	m_favour_fee;
	long	m_payed_prepay;
	long	m_payed_later;
	long	m_prepay_fee;
	long	m_amount;
	long	m_delay_rate;
	long	m_delay_fee;
	long	m_other_fee;
	long	m_should_fee;
	long	m_payment_id;
	string	m_bill_flag;
	string	m_status;
	string	m_status_flag;
	string	m_status_time;
	string	m_insert_time;
	string	m_resv;
} ST_ZT_OWE_TOTAL;

typedef struct {
	long	m_balance_log_id;
	long	m_acct_balance_id;
	long	m_oper_income_id;
	long	m_src_amount;
	long	m_oper_payout_id;
	long	m_payout_amount;
	long	m_billing_cycle_id;
	string	m_state;
	string	m_state_date;
} ST_ACCT_BALANCE_LOG;

typedef struct {
	long	m_zone_id;
	long	m_pricing_ref_object_id;
	string	m_zone_name;
} ST_ZONE;

typedef struct {
	long	m_pricing_ref_object_id;
	long	m_owner_id;
	string	m_property_type;
	long	m_property_define_id;
	string	m_extern_property_string;
	long	m_measure_method_id;
	string	m_history_time_type;
	long	m_history_time_duration;
	long	m_history_time_quantity;
} ST_PRICING_REF_OBJECT;

typedef struct {
	long	m_ai_total_id;
	long	m_acct_id;
	long	m_serv_id;
	string	m_acc_nbr;
	long	m_billing_cycle_id;
	long	m_amount;
	long	m_should_pay;
	long	m_favour_fee;
	long	m_times;
	long	m_duration;
	string	m_created_date;
	string	m_state;
	string	m_state_date;
	long	m_month_wrtoff_fee;
	long	m_pay_wrtoff_fee;
} ST_STOP_ACCT_SERV_OWE;

typedef struct {
	long	m_sub_billing_cycle_id;
	long	m_billing_cycle_id;
	string	m_sub_billing_cycle_type;
	string	m_eff_date;
	string	m_sub_billing_cycle_desc;
	string	m_exp_date;
} ST_SUB_BILLING_CYCLE;

typedef struct {
	long	m_acct_id;
	long	m_cust_id;
	string	m_acct_name;
	long	m_address_id;
	string	m_state;
	string	m_state_date;
	string	m_acct_pwd;
	long	m_region_id;
	string	m_acct_type;
	long	m_owe_min_ym;
	long	m_owe_fee;
} ST_ACCT;

typedef struct {
	string	m_route_name;
	string	m_system_type;
	string	m_route_type;
	string	m_route_group;
	string	m_route_flag;
	string	m_route_ip;
	long	m_route_port;
	string	m_query_ip;
	long	m_query_port;
	string	m_change_date;
	string	m_system_type_new;
	string	m_route_group_new;
	string	m_route_ip_new;
	long	m_route_port_new;
	string	m_query_ip_new;
	long	m_query_port_new;
	string	m_instance;
	string	m_sync_id;
	string	m_note;
	string	m_audit_flag;
} ST_ROUTE_CONTROL_TABLE;

typedef struct {
	long	m_interest_rate_id;
	long	m_latn_id;
	long	m_rate;
} ST_INTEREST_RATE;

typedef struct {
	long	m_agreement_id;
	long	m_cust_id;
	string	m_agreement_type;
	string	m_sign_date;
	string	m_completed_date;
	long	m_accept_staff_id;
	string	m_state;
	string	m_comments;
} ST_AGREEMENT;

typedef struct {
	long	m_acct_balance_id;
	long	m_acct_id;
	long	m_balance_type_id;
	long	m_balance;
	long	m_reserve_balance;
	long	m_cycle_upper;
	long	m_cycle_lower;
	string	m_cycle_upper_type;
	string	m_cycle_lower_type;
	string	m_payment_date;
	string	m_bill_month_flag;
	string	m_eff_date;
	string	m_exp_date;
	string	m_state;
	string	m_state_date;
} ST_ACCT_BALANCE_MONTH;

typedef struct {
	long	m_a_pricing_combine_id;
	long	m_z_pricing_combine_id;
	string	m_relation_type;
} ST_PRICING_COMBINE_RELATION;

typedef struct {
	long	m_ratable_resource_id;
	long	m_org_tariff_unit_id;
	string	m_ratable_resource_name;
	long	m_default_ratable_cycle_type_id;
	string	m_can_be_negative;
	string	m_durative_type;
} ST_RATABLE_RESOURCE;

typedef struct {
	long	m_tariff_id;
	string	m_ref_value_type;
} ST_TARIFF_REF_TYPE;

typedef struct {
    string  m_system_type;
    string  m_record_type;
    string  m_call_type;
    string  m_imsi;
    string  m_imei;
    string  m_msisdn;
    string  m_other_party;
    long    m_call_duration;
    string  m_msc;
    string  m_msrn;
    string  m_lac;
    string  m_cell_id;
    string  m_other_lac;
    string  m_other_cell_id;
    string  m_trunk_groupout;
    string  m_trunk_groupin;
    string  m_service_type;
    string  m_service_code;
    string  m_hot_flag;
    string  m_status;
    string  m_service_attr;
    string  m_info_num;
    string  m_calling_group_num;
    string  m_calling_short_num;
    string  m_called_group_num;
    string  m_called_short_num;
    string  m_block_flag;
    string  m_call_flag;
    string  m_home_area_code;
    string  m_visit_area_code;
    string  m_other_home_code;
    string  m_other_visit_code;
    string  m_called_code;
    string  m_user_type;
    string  m_roam_type;
    string  m_fee_type;
    string  m_dial_type;
    string  m_chat_type;
    long    m_fee1;
    long    m_fee2;
    long    m_fee3;
    long    m_old_fee1;
    long    m_old_fee2;
    long    m_old_fee3;
    string  m_info_fee1;
    string  m_info_fee2;
    string  m_info_fee3;
    string  m_file_name;
    string  m_group_id;
    string  m_product_code;
    string  m_a_number;
    string  m_brand_code;
    string  m_roam_type_query;
    string  m_fee_type_query;
    string  m_dealfile;
    string  m_error_code;
    string  m_favour_fee1;
    string  m_favour_fee2;
    string  m_favour_fee3;
    string  m_favour_flag;
} ST_DETAIL_ITEM_VOICE;

typedef struct {
	string	m_create;
	string	m_system_type;
	string	m_ism_type;
	string	m_sm_type;
	string	m_msg_id;
	string	m_imsi;
	string	m_imei;
	string	m_msisdn;
	string	m_other_party;
	string	m_start_datetime;
	string	m_end_datetime;
	long	m_msg_length;
	string	m_status;
	string	m_priority;
	string	m_gateway_code;
	string	m_f_gateway_code;
	string	m_serv_code;
	string	m_sm_center_code;
	string	m_billing_flag;
	string	m_service_attr;
	string	m_home_area_code;
	string	m_user_type;
	long	m_fee1;
	long	m_old_fee1;
	string	m_info_fee1;
	string	m_file_name;
	string	m_group_id;
	string	m_product_code;
	string	m_chat_type;
	string	m_brand_code;
	string	m_dealfile;
} ST_DETAIL_ITEM_MSG;


typedef struct {
	string	m_create;
	string	m_system_type;
	string	m_record_type;
	string	m_call_type;
	string	m_msisdn;
	string	m_other_party;
	string	m_call_duration;
	string	m_record_gen_type;
	string	m_service_key;
	string	m_service_id;
	string	m_sp_code;
	string	m_serv_code;
	string	m_oper_code;
	string	m_home_area_code;
	string	m_billing_type;
	string	m_user_level;
	string	m_user_type;
	string	m_brand_code;
	string	m_roam_type;
	string	m_fee_type;
	string	m_fee1;
	string	m_fee2;
	string	m_fee3;
	string	m_old_fee1;
	string	m_old_fee2;
	string	m_old_fee3;
	string	m_info_fee1;
	string	m_info_fee2;
	string	m_info_fee3;
	string	m_file_name;
	string	m_group_id;
	string	m_product_code;
	string	m_dealfile;
} ST_DETAIL_ITEM_CRING;

typedef struct {
	string	m_create;
	string	m_system_type;
	string	m_sm_type;
	string	m_record_type;
	string	m_service_type;
	string	m_seg_num;
	string	m_imsi;
	string	m_imei;
	string	m_msisdn;
	string	m_other_party;
	long	m_call_duration;
	long	m_times;
	long	m_down_flow;
	long	m_up_flow;
	long	m_total_flow;
	string	m_nai;
	string	m_ip_address;
	string	m_sp_code;
	string	m_serv_code;
	string	m_oper_code;
	string	m_billing_type;
	string	m_rate_unit;
	string	m_status;
	string	m_sys_id;
	string	m_sys_intra_key;
	string	m_service_attr;
	string	m_home_area_code;
	string	m_chat_type;
	string	m_user_type;
	long	m_fee1;
	long	m_fee2;
	long	m_old_fee1;
	long	m_old_fee2;
	string	m_info_fee1;
	string	m_info_fee2;
	string	m_file_name;
	string	m_group_id;
	string	m_product_code;
	string	m_brand_code;
	string	m_dealfile;
} ST_DETAIL_ITEM_CMSG;

#endif
