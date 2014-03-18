/**
 * Autogenerated by Thrift Compiler (0.9.1)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "BossData_types.h"

#include <algorithm>

namespace BossData {

const char* OpenAccount::ascii_fingerprint = "BFF0E21728CB005F9AA5774A41542B8D";
const uint8_t OpenAccount::binary_fingerprint[16] = {0xBF,0xF0,0xE2,0x17,0x28,0xCB,0x00,0x5F,0x9A,0xA5,0x77,0x4A,0x41,0x54,0x2B,0x8D};

uint32_t OpenAccount::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->nbr);
          this->__isset.nbr = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->name);
          this->__isset.name = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->gender);
          this->__isset.gender = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->idNo);
          this->__isset.idNo = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->address);
          this->__isset.address = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t OpenAccount::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("OpenAccount");

  xfer += oprot->writeFieldBegin("nbr", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->nbr);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("name", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->name);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("gender", ::apache::thrift::protocol::T_STRING, 3);
  xfer += oprot->writeString(this->gender);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("idNo", ::apache::thrift::protocol::T_STRING, 4);
  xfer += oprot->writeString(this->idNo);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("address", ::apache::thrift::protocol::T_STRING, 5);
  xfer += oprot->writeString(this->address);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(OpenAccount &a, OpenAccount &b) {
  using ::std::swap;
  swap(a.nbr, b.nbr);
  swap(a.name, b.name);
  swap(a.gender, b.gender);
  swap(a.idNo, b.idNo);
  swap(a.address, b.address);
  swap(a.__isset, b.__isset);
}

const char* BossMonitor::ascii_fingerprint = "3DEA490DCFDBF7F9065EFB84569A610F";
const uint8_t BossMonitor::binary_fingerprint[16] = {0x3D,0xEA,0x49,0x0D,0xCF,0xDB,0xF7,0xF9,0x06,0x5E,0xFB,0x84,0x56,0x9A,0x61,0x0F};

uint32_t BossMonitor::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->id);
          this->__isset.id = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->name);
          this->__isset.name = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->ip);
          this->__isset.ip = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->port);
          this->__isset.port = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->status);
          this->__isset.status = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t BossMonitor::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("BossMonitor");

  xfer += oprot->writeFieldBegin("id", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->id);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("name", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->name);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("ip", ::apache::thrift::protocol::T_STRING, 3);
  xfer += oprot->writeString(this->ip);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("port", ::apache::thrift::protocol::T_I32, 4);
  xfer += oprot->writeI32(this->port);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("status", ::apache::thrift::protocol::T_STRING, 5);
  xfer += oprot->writeString(this->status);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(BossMonitor &a, BossMonitor &b) {
  using ::std::swap;
  swap(a.id, b.id);
  swap(a.name, b.name);
  swap(a.ip, b.ip);
  swap(a.port, b.port);
  swap(a.status, b.status);
  swap(a.__isset, b.__isset);
}

const char* PayFee::ascii_fingerprint = "C712EF0DA8599E55DF4D0F13415232EF";
const uint8_t PayFee::binary_fingerprint[16] = {0xC7,0x12,0xEF,0x0D,0xA8,0x59,0x9E,0x55,0xDF,0x4D,0x0F,0x13,0x41,0x52,0x32,0xEF};

uint32_t PayFee::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->nbr);
          this->__isset.nbr = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_DOUBLE) {
          xfer += iprot->readDouble(this->fee);
          this->__isset.fee = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t PayFee::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("PayFee");

  xfer += oprot->writeFieldBegin("nbr", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->nbr);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("fee", ::apache::thrift::protocol::T_DOUBLE, 2);
  xfer += oprot->writeDouble(this->fee);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(PayFee &a, PayFee &b) {
  using ::std::swap;
  swap(a.nbr, b.nbr);
  swap(a.fee, b.fee);
  swap(a.__isset, b.__isset);
}

} // namespace
