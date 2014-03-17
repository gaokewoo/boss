#include "OracleDB.hh"
#include "Sequence.hh"

int main()
{
   OracleDB *db = new OracleDB();
   db->connectToDB();
   Sequence seq;
   seq.setConnection(db->getConnection());
   cout<<seq.getScardvcsn()<<endl;
   cout<<seq.getSpePaymentId()<<endl;
   cout<<seq.getSbatchaccept()<<endl;
   cout<<seq.getBalanceTypeId()<<endl;
   cout<<seq.getBalanceSourceId()<<endl;
   cout<<seq.getPrivilegeId()<<endl;
   cout<<seq.getStaffId()<<endl;
   cout<<seq.getBankBranchId()<<endl;
   cout<<seq.getBankId()<<endl;
   cout<<seq.getPaymentMethodId()<<endl;
   cout<<seq.getDelayRuleId()<<endl;
   cout<<seq.getDerateRuleId()<<endl;
   cout<<seq.getPresentRuleId()<<endl;
   cout<<seq.getBillItemTypeId()<<endl;
   cout<<seq.getBillFormatId()<<endl;
   cout<<seq.getBillRemarkId()<<endl;
   cout<<seq.getBillVariableId()<<endl;
   cout<<seq.getOweTimeInfoId()<<endl;
   cout<<seq.getDateTypeId()<<endl;
   cout<<seq.getOweBusinessTypeId()<<endl;
   cout<<seq.getOweTypeLimitId()<<endl;
   cout<<seq.getAcctItemGroupId()<<endl;
   cout<<seq.getAcctItemTypeId()<<endl;
   cout<<seq.getItemSourceId()<<endl;
   cout<<seq.getAcctItemClassId()<<endl;
   cout<<seq.getAttrGrpId()<<endl;
   cout<<seq.getBillParseId()<<endl;
   cout<<seq.getBalanceRelationId()<<endl;
   cout<<seq.getAddressId()<<endl;
   cout<<seq.getBillRecordId()<<endl;
   cout<<seq.getFavourPresentId()<<endl;
   cout<<seq.getPresentId()<<endl;
   cout<<seq.getBalancePresentId()<<endl;
   cout<<seq.getOweObjectId()<<endl;
   cout<<seq.getChargeAdjustLogId()<<endl;
   cout<<seq.getAdjustRecordId()<<endl;
   cout<<seq.getRegionId()<<endl;
   cout<<seq.getIntegralReaultId()<<endl;
   cout<<seq.getPaymentPlanId()<<endl;
   cout<<seq.getInvoiceId()<<endl;
   cout<<seq.getBillFormatCustomizeId()<<endl;
   cout<<seq.getBillFormatSelectorId()<<endl;
   cout<<seq.getOweTaskId()<<endl;
   cout<<seq.getLogoutOpSn()<<endl;
   cout<<seq.getAcctItemId()<<endl;
   cout<<seq.getAiTotalId()<<endl;
   cout<<seq.getServAcctId()<<endl;
   cout<<seq.getAcctBalanceId()<<endl;
   cout<<seq.getBatchOperSn()<<endl;
   cout<<seq.getBillId()<<endl;
   cout<<seq.getPaySn()<<endl;
   cout<<seq.getOperPayoutId()<<endl;
   cout<<seq.getOperIncomeId()<<endl;
   cout<<seq.getZtOweTotalId()<<endl;
   cout<<seq.getDelayFavId()<<endl;
   cout<<seq.getPayInterfaceId()<<endl;
   cout<<seq.getSendMsgSn()<<endl;
   cout<<seq.getCreditResultId()<<endl;
   cout<<seq.getPartyId()<<endl;
   cout<<seq.getPayinfoId()<<endl;
   cout<<seq.getTransferAccountId()<<endl;
   cout<<seq.getBillUnownerId()<<endl;
   cout<<seq.getLogicalAddressId()<<endl;
   cout<<seq.getServAddAccNbrId()<<endl;
   cout<<seq.getMmdbAcctBalanceIncOpsn()<<endl;

   db->disConnectFromDB();
   return 0;
}
