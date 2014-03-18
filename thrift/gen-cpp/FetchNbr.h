/**
 * Autogenerated by Thrift Compiler (0.9.1)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef FetchNbr_H
#define FetchNbr_H

#include <thrift/TDispatchProcessor.h>
#include "FetchNbr_types.h"

namespace BossInterface {

class FetchNbrIf {
 public:
  virtual ~FetchNbrIf() {}
  virtual void fetchNbr(std::string& _return) = 0;
};

class FetchNbrIfFactory {
 public:
  typedef FetchNbrIf Handler;

  virtual ~FetchNbrIfFactory() {}

  virtual FetchNbrIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(FetchNbrIf* /* handler */) = 0;
};

class FetchNbrIfSingletonFactory : virtual public FetchNbrIfFactory {
 public:
  FetchNbrIfSingletonFactory(const boost::shared_ptr<FetchNbrIf>& iface) : iface_(iface) {}
  virtual ~FetchNbrIfSingletonFactory() {}

  virtual FetchNbrIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(FetchNbrIf* /* handler */) {}

 protected:
  boost::shared_ptr<FetchNbrIf> iface_;
};

class FetchNbrNull : virtual public FetchNbrIf {
 public:
  virtual ~FetchNbrNull() {}
  void fetchNbr(std::string& /* _return */) {
    return;
  }
};


class FetchNbr_fetchNbr_args {
 public:

  FetchNbr_fetchNbr_args() {
  }

  virtual ~FetchNbr_fetchNbr_args() throw() {}


  bool operator == (const FetchNbr_fetchNbr_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const FetchNbr_fetchNbr_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const FetchNbr_fetchNbr_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class FetchNbr_fetchNbr_pargs {
 public:


  virtual ~FetchNbr_fetchNbr_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _FetchNbr_fetchNbr_result__isset {
  _FetchNbr_fetchNbr_result__isset() : success(false) {}
  bool success;
} _FetchNbr_fetchNbr_result__isset;

class FetchNbr_fetchNbr_result {
 public:

  FetchNbr_fetchNbr_result() : success() {
  }

  virtual ~FetchNbr_fetchNbr_result() throw() {}

  std::string success;

  _FetchNbr_fetchNbr_result__isset __isset;

  void __set_success(const std::string& val) {
    success = val;
  }

  bool operator == (const FetchNbr_fetchNbr_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const FetchNbr_fetchNbr_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const FetchNbr_fetchNbr_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _FetchNbr_fetchNbr_presult__isset {
  _FetchNbr_fetchNbr_presult__isset() : success(false) {}
  bool success;
} _FetchNbr_fetchNbr_presult__isset;

class FetchNbr_fetchNbr_presult {
 public:


  virtual ~FetchNbr_fetchNbr_presult() throw() {}

  std::string* success;

  _FetchNbr_fetchNbr_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class FetchNbrClient : virtual public FetchNbrIf {
 public:
  FetchNbrClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    piprot_(prot),
    poprot_(prot) {
    iprot_ = prot.get();
    oprot_ = prot.get();
  }
  FetchNbrClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
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
  void fetchNbr(std::string& _return);
  void send_fetchNbr();
  void recv_fetchNbr(std::string& _return);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class FetchNbrProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<FetchNbrIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (FetchNbrProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_fetchNbr(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  FetchNbrProcessor(boost::shared_ptr<FetchNbrIf> iface) :
    iface_(iface) {
    processMap_["fetchNbr"] = &FetchNbrProcessor::process_fetchNbr;
  }

  virtual ~FetchNbrProcessor() {}
};

class FetchNbrProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  FetchNbrProcessorFactory(const ::boost::shared_ptr< FetchNbrIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< FetchNbrIfFactory > handlerFactory_;
};

class FetchNbrMultiface : virtual public FetchNbrIf {
 public:
  FetchNbrMultiface(std::vector<boost::shared_ptr<FetchNbrIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~FetchNbrMultiface() {}
 protected:
  std::vector<boost::shared_ptr<FetchNbrIf> > ifaces_;
  FetchNbrMultiface() {}
  void add(boost::shared_ptr<FetchNbrIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void fetchNbr(std::string& _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->fetchNbr(_return);
    }
    ifaces_[i]->fetchNbr(_return);
    return;
  }

};

} // namespace

#endif
