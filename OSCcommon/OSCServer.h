/*
 
 ArdOSC 2.1 - OSC Library for Arduino.
 
 (RoboCore v_1.0)
 
 -------- License -----------------------------------------------------------
 
 ArdOSC
 
 The MIT License
 
 Copyright (c) 2009 - 2011 recotana( http://recotana.com )　All right reserved
 
 + updates by RoboCore ( http://www.RoboCore.net/ )
 
 */

#ifndef ArdOSC_OSCServer2_h
#define ArdOSC_OSCServer2_h

#include "OSCDecoder.h"
#include "Pattern.h"

//options for availableCheck() (bitwise)
#define CALL_GENERAL_CALLBACK (1 << 0)
#define CALL_SPECIFIC_CALLBACK (1 << 1)

class OSCServer{    
private:
  int16_t _sock;
  uint16_t _port;
  uint8_t _rcvData[kMaxReceiveData];
  OSCDecoder::OSCDecoder _decoder;
  Pattern::Pattern _adrMatch;
  
  uint8_t _useGeneralCallback;
  Pattern::AdrFunc _generalCallback;

  void rcvFlush(void);
    
public:
  OSCServer(void);
  ~OSCServer(void);
  
  //_adr osc address string pointer - "/ard/aaa"
  //_func callback function pointer
  void addCallback(char *_adr , Pattern::AdrFunc _func );
  void addGeneralCallback(Pattern::AdrFunc function);
  int16_t availableCheck(void); //default to call GENERAL + SPECIFIC
  int16_t availableCheck(uint8_t options, uint8_t flush = 0);
  int16_t begin(uint16_t _receivePort);
  void stop(void);

};

#endif
