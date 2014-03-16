/**
 * Autogenerated by Thrift Compiler (0.9.1)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef BossData_TYPES_H
#define BossData_TYPES_H

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/cxxfunctional.h>


namespace BossData {

typedef struct _OpenAccount__isset {
  _OpenAccount__isset() : nbr(true), name(true), gender(true), idNo(true), address(true) {}
  bool nbr;
  bool name;
  bool gender;
  bool idNo;
  bool address;
} _OpenAccount__isset;

class OpenAccount {
 public:

  static const char* ascii_fingerprint; // = "BFF0E21728CB005F9AA5774A41542B8D";
  static const uint8_t binary_fingerprint[16]; // = {0xBF,0xF0,0xE2,0x17,0x28,0xCB,0x00,0x5F,0x9A,0xA5,0x77,0x4A,0x41,0x54,0x2B,0x8D};

  OpenAccount() : nbr(""), name(""), gender(""), idNo(""), address("") {
  }

  virtual ~OpenAccount() throw() {}

  std::string nbr;
  std::string name;
  std::string gender;
  std::string idNo;
  std::string address;

  _OpenAccount__isset __isset;

  void __set_nbr(const std::string& val) {
    nbr = val;
  }

  void __set_name(const std::string& val) {
    name = val;
  }

  void __set_gender(const std::string& val) {
    gender = val;
  }

  void __set_idNo(const std::string& val) {
    idNo = val;
  }

  void __set_address(const std::string& val) {
    address = val;
  }

  bool operator == (const OpenAccount & rhs) const
  {
    if (!(nbr == rhs.nbr))
      return false;
    if (!(name == rhs.name))
      return false;
    if (!(gender == rhs.gender))
      return false;
    if (!(idNo == rhs.idNo))
      return false;
    if (!(address == rhs.address))
      return false;
    return true;
  }
  bool operator != (const OpenAccount &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const OpenAccount & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(OpenAccount &a, OpenAccount &b);

typedef struct _BossMonitor__isset {
  _BossMonitor__isset() : id(false), name(false), ip(false), port(false), status(false) {}
  bool id;
  bool name;
  bool ip;
  bool port;
  bool status;
} _BossMonitor__isset;

class BossMonitor {
 public:

  static const char* ascii_fingerprint; // = "3DEA490DCFDBF7F9065EFB84569A610F";
  static const uint8_t binary_fingerprint[16]; // = {0x3D,0xEA,0x49,0x0D,0xCF,0xDB,0xF7,0xF9,0x06,0x5E,0xFB,0x84,0x56,0x9A,0x61,0x0F};

  BossMonitor() : id(0), name(), ip(), port(0), status() {
  }

  virtual ~BossMonitor() throw() {}

  int32_t id;
  std::string name;
  std::string ip;
  int32_t port;
  std::string status;

  _BossMonitor__isset __isset;

  void __set_id(const int32_t val) {
    id = val;
  }

  void __set_name(const std::string& val) {
    name = val;
  }

  void __set_ip(const std::string& val) {
    ip = val;
  }

  void __set_port(const int32_t val) {
    port = val;
  }

  void __set_status(const std::string& val) {
    status = val;
  }

  bool operator == (const BossMonitor & rhs) const
  {
    if (!(id == rhs.id))
      return false;
    if (!(name == rhs.name))
      return false;
    if (!(ip == rhs.ip))
      return false;
    if (!(port == rhs.port))
      return false;
    if (!(status == rhs.status))
      return false;
    return true;
  }
  bool operator != (const BossMonitor &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const BossMonitor & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(BossMonitor &a, BossMonitor &b);

typedef struct _Payment__isset {
  _Payment__isset() : nbr(true), fee(true) {}
  bool nbr;
  bool fee;
} _Payment__isset;

class Payment {
 public:

  static const char* ascii_fingerprint; // = "C712EF0DA8599E55DF4D0F13415232EF";
  static const uint8_t binary_fingerprint[16]; // = {0xC7,0x12,0xEF,0x0D,0xA8,0x59,0x9E,0x55,0xDF,0x4D,0x0F,0x13,0x41,0x52,0x32,0xEF};

  Payment() : nbr(""), fee(0) {
  }

  virtual ~Payment() throw() {}

  std::string nbr;
  double fee;

  _Payment__isset __isset;

  void __set_nbr(const std::string& val) {
    nbr = val;
  }

  void __set_fee(const double val) {
    fee = val;
  }

  bool operator == (const Payment & rhs) const
  {
    if (!(nbr == rhs.nbr))
      return false;
    if (!(fee == rhs.fee))
      return false;
    return true;
  }
  bool operator != (const Payment &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Payment & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(Payment &a, Payment &b);

} // namespace

#endif
