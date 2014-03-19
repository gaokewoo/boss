#!/usr/bin/env python  
import sys  
sys.path.append('./gen-py/')
from query import FetchNbr
from query.ttypes import *
from thrift import Thrift
from thrift.transport import TSocket
from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol

# Make socket  
transport = TSocket.TSocket('localhost', 9093)  
# Buffering is critical. Raw sockets are very slow  
transport = TTransport.TBufferedTransport(transport)  
# Wrap in a protocol  
protocol = TBinaryProtocol.TBinaryProtocol(transport)  
# Create a client to use the protocol encoder  
client = FetchNbr.Client(protocol)
# Connect!
transport.open()  
# Call Server services    
print "Phone Nbr:"+client.fetchNbr() 
