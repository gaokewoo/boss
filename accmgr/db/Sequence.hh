#ifndef __DBSTRUCT__
#define __DBSTRUCT__
#include "SQLInterface.hh"

class Sequence:public SQLInterface
{
public:
    long long getScardvcsn();
    long long getSpePaymentId();
    long long getSbatchaccept();
    long long getBalanceTypeId();
    long long getBalanceSourceId();
    long long getPrivilegeId();
    long long getStaffId();
    long long getBankBranchId();
    long long getBankId();
    long long getPaymentMethodId();
    long long getDelayRuleId();
    long long getDerateRuleId();
    long long getPresentRuleId();
    long long getBillItemTypeId();
    long long getBillFormatId();
    long long getBillRemarkId();
    long long getBillVariableId();
    long long getOweTimeInfoId();
    long long getDateTypeId();
    long long getOweBusinessTypeId();
    long long getOweTypeLimitId();
    long long getAcctItemGroupId();
    long long getAcctItemTypeId();
    long long getItemSourceId();
    long long getAcctItemClassId();
    long long getAttrGrpId();
    long long getBillParseId();
    long long getBalanceRelationId();
    long long getAddressId();
    long long getBillRecordId();
    long long getFavourPresentId();
    long long getPresentId();
    long long getBalancePresentId();
    long long getOweObjectId();
    long long getChargeAdjustLogId();
    long long getAdjustRecordId();
    long long getRegionId();
    long long getIntegralReaultId();
    long long getPaymentPlanId();
    long long getInvoiceId();
    long long getBillFormatCustomizeId();
    long long getBillFormatSelectorId();
    long long getOweTaskId();
    long long getLogoutOpSn();
    long long getAcctItemId();
    long long getAiTotalId();
    long long getServAcctId();
    long long getAcctBalanceId();
    long long getBatchOperSn();
    long long getBillId();
    long long getPaySn();
    long long getOperPayoutId();
    long long getOperIncomeId();
    long long getZtOweTotalId();
    long long getDelayFavId();
    long long getPayInterfaceId();
    long long getSendMsgSn();
    long long getCreditResultId();
    long long getPartyId();
    long long getPayinfoId();
    long long getTransferAccountId();
    long long getBillUnownerId();
    long long getLogicalAddressId();
    long long getServAddAccNbrId();
    long long getMmdbAcctBalanceIncOpsn();
    virtual void doParse();

private:
    long long id;
};
#endif
