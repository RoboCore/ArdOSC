/*
 
 ArdOSC 2.1 - OSC Library for Arduino.
 
 (RoboCore v_1.0)
 
 -------- License -----------------------------------------------------------
 
 ArdOSC
 
 The MIT License
 
 Copyright (c) 2009 - 2011 recotana( http://recotana.com )　All right reserved
 
 + updates by RoboCore ( http://www.RoboCore.net/ )
 
 */

#ifndef ArdOSC_patternmatch_h
#define ArdOSC_patternmatch_h

#include "OSCMessage.h"

#define kMaxPatternMatch    20  //previously 50
#define USE_WILDCARD //wildcard = '^'
//  NOTE: the wildcard MUST be replaced by another character
//          ex: address to match : /RoboCore/wild/^
//              /RoboCore/wild/ >> won't work
//              /RoboCore/wild/t >> works
//              /RoboCore/wild/test >> works

//----------------------------------------------------------------------------

class Pattern{
public:
  typedef void (*AdrFunc)(OSCMessage*);
  
  Pattern();
  ~Pattern();
                
  void addOscAddress(char *_adr , AdrFunc _func );
  void execFunc(uint8_t _index,OSCMessage *_mes);
  void paternComp(OSCMessage *_mes);

  friend class OSCServer;
  
private:
  AdrFunc adrFunc[kMaxPatternMatch];
  char *addr[kMaxPatternMatch];
  uint8_t patternNum;

};


#endif




