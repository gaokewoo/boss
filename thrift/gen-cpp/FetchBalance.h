/**
 * Autogenerated by Thrift Compiler (0.9.1)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef FetchBalance_H
#define FetchBalance_H

#include <thrift/TDispatchProcessor.h>
#include "query_types.h"

namespace BossInterface {

class FetchBalanceIf {
 public:
  virtual ~FetchBalanceIf() {}
  virtual double fetchBalance(const std::string& nbr) = 0;
};

class FetchBalanceIfFactory {
 public:
  typedef FetchBalanceIf Handler;

  virtual ~FetchBalanceIfFactory() {}

  virtual FetchBalanceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(FetchBalanceIf* /* handler */) = 0;
};

class FetchBalanceIfSingletonFactory : virtual public FetchBalanceIfFactory {
 public:
  FetchBalanceIfSingletonFactory(const boost::shared_ptr<FetchBalanceIf>& iface) : iface_(iface) {}
  virtual ~FetchBalanceIfSingletonFactory() {}

  virtual FetchBalanceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(FetchBalanceIf* /* handler */) {}

 protected:
  boost::shared_ptr<FetchBalanceIf> iface_;
};

class FetchBalanceNull : virtual public FetchBalanceIf {
 public:
  virtual ~FetchBalanceNull() {}
  double fetchBalance(const std::string& /* nbr */) {
    double _return = (double)0;
    return _return;
  }
};

typedef struct _FetchBalance_fetchBalance_args__isset {
  _FetchBalance_fetchBalance_args__isset() : nbr(false) {}
  bool nbr;
} _FetchBalance_fetchBalance_args__isset;

class FetchBalance_fetchBalance_args {
 public:

  FetchBalance_fetchBalance_args() : nbr() {
  }

  virtual ~FetchBalance_fetchBalance_args() throw() {}

  std::string nbr;

  _FetchBalance_fetchBalance_args__isset __isset;

  void __set_nbr(const std::string& val) {
    nbr = val;
  }

  bool operator == (const FetchBalance_fetchBalance_args & rhs) const
  {
    if (!(nbr == rhs.nbr))
      return false;
    return true;
  }
  bool operator != (const FetchBalance_fetchBalance_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const FetchBalance_fetchBalance_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class FetchBalance_fetchBalance_pargs {
 public:


  virtual ~FetchBalance_fetchBalance_pargs() throw() {}

  const std::string* nbr;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _FetchBalance_fetchBalance_result__isset {
  _FetchBalance_fetchBalance_result__isset() : success(false) {}
  bool success;
} _FetchBalance_fetchBalance_result__isset;

class FetchBalance_fetchBalance_result {
 public:

  FetchBalance_fetchBalance_result() : success(0) {
  }

  virtual ~FetchBalance_fetchBalance_result() throw() {}

  double success;

  _FetchBalance_fetchBalance_result__isset __isset;

  void __set_success(const double val) {
    success = val;
  }

  bool operator == (const FetchBalance_fetchBalance_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const FetchBalance_fetchBalance_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const FetchBalance_fetchBalance_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _FetchBalance_fetchBalance_presult__isset {
  _FetchBalance_fetchBalance_presult__isset() : success(false) {}
  bool success;
} _FetchBalance_fetchBalance_presult__isset;

class FetchBalance_fetchBalance_presult {
 public:


  virtual ~FetchBalance_fetchBalance_presult() throw() {}

  double* success;

  _FetchBalance_fetchBalance_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class FetchBalanceClient : virtual public FetchBalanceIf {
 public:
  FetchBalanceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    piprot_(prot),
    poprot_(prot) {
    iprot_ = prot.get();
    oprot_ = prot.get();
  }
  FetchBalanceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
    piprot_(iprot),
    poprot_(oprot) {
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  double fetchBalance(const std::string& nbr);
  void send_fetchBalance(const std::string& nbr);
  double recv_fetchBalance();
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class FetchBalanceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<FetchBalanceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (FetchBalanceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_fetchBalance(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  FetchBalanceProcessor(boost::shared_ptr<FetchBalanceIf> iface) :
    iface_(iface) {
    processMap_["fetchBalance"] = &FetchBalanceProcessor::process_fetchBalance;
  }

  virtual ~FetchBalanceProcessor() {}
};

class FetchBalanceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  FetchBalanceProcessorFactory(const ::boost::shared_ptr< FetchBalanceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< FetchBalanceIfFactory > handlerFactory_;
};

class FetchBalanceMultiface : virtual public FetchBalanceIf {
 public:
  FetchBalanceMultiface(std::vector<boost::shared_ptr<FetchBalanceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~FetchBalanceMultiface() {}
 protected:
  std::vector<boost::shared_ptr<FetchBalanceIf> > ifaces_;
  FetchBalanceMultiface() {}
  void add(boost::shared_ptr<FetchBalanceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  double fetchBalance(const std::string& nbr) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->fetchBalance(nbr);
    }
    return ifaces_[i]->fetchBalance(nbr);
  }

};

} // namespace

#endif
