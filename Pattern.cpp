/*
 
 ArdOSC 2.1 - OSC Library for Arduino.
 
 (RoboCore v_1.0)
 
 -------- License -----------------------------------------------------------
 
 ArdOSC
 
 The MIT License
 
 Copyright (c) 2009 - 2011 recotana( http://recotana.com )　All right reserved
 
 + updates by RoboCore (www.RoboCore.net)
 
 */

#include <stdlib.h>
#include <string.h>
#include "OSCCommon/OSCServer.h"
#include "OSCCommon/OSCcommon.h"
#include "OSCCommon/OSCMessage.h"

#include "OSCCommon/Pattern.h"

#ifdef USE_WILDCARD
#include <String_Functions.h> //instead of using the String class (used by djspark)
#endif

//----------------------------------------------------------------------------

Pattern::Pattern(){
  patternNum = 0;
}

//----------------------------------------------------------------------------

Pattern::~Pattern(){    
}

//----------------------------------------------------------------------------

void Pattern::addOscAddress(char *_adr ,  AdrFunc _func){
  adrFunc[patternNum] = _func;
  addr[patternNum] = _adr;
  patternNum++;
}

//----------------------------------------------------------------------------

void Pattern::execFunc(uint8_t _index,OSCMessage *_mes){
  adrFunc[_index](_mes);
}

//----------------------------------------------------------------------------

void Pattern::paternComp(OSCMessage *_mes){
  for (uint8_t i=0 ; i < patternNum ; i++) {
#ifdef USE_WILDCARD
//supports calls to addresses with wildcard at the end
//  uses <String_Functions.h> instead of String class, supposedly with
//  bugs and to avoid memory allocation
//      (based on code written by djspark - https://github.com/djspark)
  int pos = StrFind(addr[i], '^');
  int addr_len = StrLength(addr[i]) - 1; //subtract the last character ('^')
  if(pos == addr_len){ //found valid address with wildcard
    int comparison = StrCompare(_mes->_oscAddress, addr[i], 0, addr_len);
    if(comparison == addr_len) //addresses are equal
      execFunc(i, _mes);
  } else {
    if(strcmp(addr[i], _mes->_oscAddress) == 0)
      execFunc(i, _mes);
  }
#else
  if(strcmp(addr[i], _mes->_oscAddress) == 0)
    execFunc( i , _mes );
#endif
  }
}

//----------------------------------------------------------------------------


