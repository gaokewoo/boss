#!/usr/bin/env python  
import sys
import ConfigParser
sys.path.append('../thrift/gen-py/')
from query import FetchNbr
from query.ttypes import *
from thrift import Thrift
from thrift.transport import TSocket
from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol

# Read configuration file
config = ConfigParser.ConfigParser()
config.readfp(open("../conf/boss.cfg","rb"))

ip = config.get("FetchNbr","ip")
port = config.get("FetchNbr","port")

# Make socket
transport = TSocket.TSocket(ip, port)
# Buffering is critical. Raw sockets are very slow
transport = TTransport.TBufferedTransport(transport)
# Wrap in a protocol
protocol = TBinaryProtocol.TBinaryProtocol(transport)
# Create a client to use the protocol encoder
client = FetchNbr.Client(protocol)
# Connect!
transport.open()
# Call Server services
phoneNbr = client.fetchNbr()

print "Phone Nbr: "+phoneNbr
