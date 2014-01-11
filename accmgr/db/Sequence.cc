#include "Sequence.hh"

long long Sequence::getServId()
{
    setSQL("select SERV_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getAcctId()
{
    setSQL("select ACCT_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getCustId()
{
    setSQL("select CUST_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getAgreementId()
{
    setSQL("select AGREEMENT_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getScardvcsn()
{
    setSQL("select SCARDVCSN.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getSpePaymentId()
{
    setSQL("select SPE_PAYMENT_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getSbatchaccept()
{
    setSQL("select SBATCHACCEPT.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getBalanceTypeId()
{
    setSQL("select BALANCE_TYPE_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getBalanceSourceId()
{
    setSQL("select BALANCE_SOURCE_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getPrivilegeId()
{
    setSQL("select PRIVILEGE_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getStaffId()
{
    setSQL("select STAFF_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getBankBranchId()
{
    setSQL("select BANK_BRANCH_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getBankId()
{
    setSQL("select BANK_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getPaymentMethodId()
{
    setSQL("select PAYMENT_METHOD_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getDelayRuleId()
{
    setSQL("select DELAY_RULE_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getDerateRuleId()
{
    setSQL("select DERATE_RULE_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getPresentRuleId()
{
    setSQL("select PRESENT_RULE_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getBillItemTypeId()
{
    setSQL("select BILL_ITEM_TYPE_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getBillFormatId()
{
    setSQL("select BILL_FORMAT_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getBillRemarkId()
{
    setSQL("select BILL_REMARK_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getBillVariableId()
{
    setSQL("select BILL_VARIABLE_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getOweTimeInfoId()
{
    setSQL("select OWE_TIME_INFO_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getDateTypeId()
{
    setSQL("select DATE_TYPE_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getOweBusinessTypeId()
{
    setSQL("select OWE_BUSINESS_TYPE_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getOweTypeLimitId()
{
    setSQL("select OWE_TYPE_LIMIT_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getAcctItemGroupId()
{
    setSQL("select ACCT_ITEM_GROUP_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getAcctItemTypeId()
{
    setSQL("select ACCT_ITEM_TYPE_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getItemSourceId()
{
    setSQL("select ITEM_SOURCE_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getAcctItemClassId()
{
    setSQL("select ACCT_ITEM_CLASS_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getAttrGrpId()
{
    setSQL("select ATTR_GRP_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getBillParseId()
{
    setSQL("select BILL_PARSE_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getBalanceRelationId()
{
    setSQL("select BALANCE_RELATION_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getAddressId()
{
    setSQL("select ADDRESS_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getBillRecordId()
{
    setSQL("select BILL_RECORD_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getFavourPresentId()
{
    setSQL("select FAVOUR_PRESENT_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getPresentId()
{
    setSQL("select PRESENT_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getBalancePresentId()
{
    setSQL("select BALANCE_PRESENT_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getOweObjectId()
{
    setSQL("select OWE_OBJECT_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getChargeAdjustLogId()
{
    setSQL("select CHARGE_ADJUST_LOG_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getAdjustRecordId()
{
    setSQL("select ADJUST_RECORD_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getRegionId()
{
    setSQL("select REGION_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getIntegralReaultId()
{
    setSQL("select INTEGRAL_REAULT_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getPaymentPlanId()
{
    setSQL("select PAYMENT_PLAN_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getInvoiceId()
{
    setSQL("select INVOICE_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getBillFormatCustomizeId()
{
    setSQL("select BILL_FORMAT_CUSTOMIZE_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getBillFormatSelectorId()
{
    setSQL("select BILL_FORMAT_SELECTOR_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getOweTaskId()
{
    setSQL("select OWE_TASK_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getLogoutOpSn()
{
    setSQL("select LOGOUT_OP_SN.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getAcctItemId()
{
    setSQL("select ACCT_ITEM_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getAiTotalId()
{
    setSQL("select AI_TOTAL_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getServAcctId()
{
    setSQL("select SERV_ACCT_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getAcctBalanceId()
{
    setSQL("select ACCT_BALANCE_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getBatchOperSn()
{
    setSQL("select BATCH_OPER_SN.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getBillId()
{
    setSQL("select BILL_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getPaySn()
{
    setSQL("select PAY_SN.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getOperPayoutId()
{
    setSQL("select OPER_PAYOUT_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getOperIncomeId()
{
    setSQL("select OPER_INCOME_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getZtOweTotalId()
{
    setSQL("select ZT_OWE_TOTAL_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getDelayFavId()
{
    setSQL("select DELAY_FAV_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getPayInterfaceId()
{
    setSQL("select PAY_INTERFACE_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getSendMsgSn()
{
    setSQL("select SEND_MSG_SN.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getCreditResultId()
{
    setSQL("select CREDIT_RESULT_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getPartyId()
{
    setSQL("select PARTY_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getPayinfoId()
{
    setSQL("select PAYINFO_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getTransferAccountId()
{
    setSQL("select TRANSFER_ACCOUNT_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getBillUnownerId()
{
    setSQL("select BILL_UNOWNER_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getLogicalAddressId()
{
    setSQL("select LOGICAL_ADDRESS_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getServAddAccNbrId()
{
    setSQL("select SERV_ADD_ACC_NBR_ID.nextval from dual");
    executeQurey();

    return id;
}

long long Sequence::getMmdbAcctBalanceIncOpsn()
{
    setSQL("select MMDB_ACCT_BALANCE_INC_OPSN.nextval from dual");
    executeQurey();

    return id;
}

void Sequence::doParse()
{
    id=(double)rset->getNumber(1);
}
