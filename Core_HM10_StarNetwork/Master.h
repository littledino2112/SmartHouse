/* This class represents the Master HM10 module
Class members:
uint32_t iNumSlave: number of discovered slaves
String Slave[50]: store Slave's addresses

Class methods:
connectSlave(String address):  Connect to a slave with provided address
config(): Self-config the master module: RENEW -> ROLE1 -> IMME1
String getSlaveResponse():	Get reponses from the connected slave
 */

#ifndef __MASTER_H
#define __MASTER_H

 class Master
 {
 public:
 	Master();

 	// uint8_t connectSlave(String address);
 	uint8_t config();
 	// String getSlaveResponse();
 public:
 	uint32_t iNumSlave;
 	String Slave[50]; // store discovered Slave's addresses
 };

 #endif