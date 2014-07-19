create table detail_item_cmsg
(
 system_type VARCHAR(2) not null,
 sm_type VARCHAR(2) not null,
 record_type VARCHAR(2) not null,
 service_type VARCHAR(2) not null,
 seg_num VARCHAR(10) not null,
 imsi VARCHAR(15) not null,
 imei VARCHAR(20) not null,
 msisdn VARCHAR(15) not null,
 other_party VARCHAR(24) not null,
 start_datetime date not null,
 end_datetime date not null,
 call_duration  NUMBER(6) not null,
 times  NUMBER(10) not null,
 down_flow  NUMBER(10) not null,
 up_flow    NUMBER(10) not null,
 total_flow NUMBER(10) not null,
 nai    VARCHAR(32) not null,
 ip_address VARCHAR(15) not null,
 sp_code    VARCHAR(20) not null,
 serv_code  VARCHAR(30) not null,
 oper_code  VARCHAR(30) not null,
 billing_type   VARCHAR(2) not null,
 rate_unit  VARCHAR(2) not null,
 status VARCHAR(7) not null,
 sys_id VARCHAR(8) not null,
 sys_intra_key  VARCHAR(30) not null,
 service_attr   VARCHAR(20) not null,
 home_area_code VARCHAR(4) not null,
 chat_type  VARCHAR(3) not null,
 user_type  VARCHAR(1) not null,
 fee1   NUMBER(10) not null,
 fee2   NUMBER(10) not null,
 old_fee1   NUMBER(10) not null,
 old_fee2   NUMBER(10) not null,
 info_fee1  VARCHAR(60) not null,
 info_fee2  VARCHAR(60) not null,
 file_name  VARCHAR(40) not null,
 deal_time  VARCHAR(12) not null,
 group_id   VARCHAR(15) not null,
 product_code   VARCHAR(8) not null,
 brand_code VARCHAR(2) not null,
 dealfile   VARCHAR(40) not null
);


