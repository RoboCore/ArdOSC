/*
 
 ArdOSC 2.1 - OSC Library for Arduino.
 
 (RoboCore v_1.0)
 
 -------- License -----------------------------------------------------------
 
 ArdOSC
 
 The MIT License
 
 Copyright (c) 2009 - 2011 recotana( http://recotana.com )　All right reserved
 
 + updates by RoboCore (www.RoboCore.net)
 
 */



#ifndef OSCcommon_h
#define OSCcommon_h

extern "C" {
#include <inttypes.h>
}

#define kMaxAugument 16
#define kMaxReceiveData 100
#define kMaxOSCAdrCharactor 255

#define CULC_ALIGNMENT(x) (x+4)&0xfffc


//======== user defined ==============

#define _USE_FLOAT_
#define _USE_STRING_

//======== user defined end  ========


#endif






