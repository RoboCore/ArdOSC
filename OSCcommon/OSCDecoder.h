/*
 
 ArdOSC 2.1 - OSC Library for Arduino.
 
 (RoboCore v_1.0)
 
 -------- License -----------------------------------------------------------
 
 ArdOSC
 
 The MIT License
 
 Copyright (c) 2009 - 2011 recotana( http://recotana.com )　All right reserved
 
 + updates by RoboCore ( http://www.RoboCore.net/ )
 
 */

#ifndef OSCDecoder_h
#define OSCDecoder_h


#include "OSCMessage.h"

class OSCDecoder{
private:
  int16_t decode( OSCMessage::OSCMessage *_mes ,const uint8_t *_binData );
    
public:
  
  friend class OSCServer;
};

#endif




