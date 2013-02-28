/*
 
 ArdOSC 2.1 - OSC Library for Arduino.
 
 (RoboCore v_1.0)
 
 -------- License -----------------------------------------------------------
 
 ArdOSC
 
 The MIT License
 
 Copyright (c) 2009 - 2011 recotana( http://recotana.com )　All right reserved
 
 + updates by RoboCore ( http://www.RoboCore.net/ )
 
 */


#ifndef OSCEncoder_h
#define OSCEncoder_h

#include "OSCMessage.h"

class OSCEncoder{
private:
  int16_t encode( OSCMessage::OSCMessage *mes ,uint8_t *_binData );
  
public:

    friend class OSCClient;
};

#endif





