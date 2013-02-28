/*
 
 ArdOSC 2.1 - OSC Library for Arduino.
 
 (RoboCore v_1.0)
 
 -------- License -----------------------------------------------------------
 
 ArdOSC
 
 The MIT License
 
 Copyright (c) 2009 - 2011 recotana( http://recotana.com )　All right reserved
 
 + updates by RoboCore ( http://www.RoboCore.net/ )
 
 */




#ifndef OSCMessage_h
#define OSCMessage_h


#include "OSCcommon.h"
#include "OSCArg.h"

#define kTagInt32   'i'
#define kTagFloat   'f'
#define kTagString  's'
#define kTagBlob    'b'

#define kTagMidi    'm'
#define kTagRgba    'r'

#define kTagTrue    'T'
#define kTagFalse   'F'



class OSCMessage{
private:
  uint8_t _ip[4];	
  uint16_t _port;
  
  char* _oscAddress;	
  uint16_t _oscAdrSize;
  uint16_t _oscAdrAlignmentSize;
  
  uint16_t _typeTagAlignmentSize;
  uint16_t _argsAlignmentSize;
  
  uint16_t _argsNum;
  OSCArg* _args[kMaxAugument];
  
  uint16_t getArgAlignmentSize(uint8_t _index);
  uint16_t getMessageSize(void);
  int16_t setArgData( char _type , void *_value , uint8_t _byte,  bool _enableAlignment );
  void swap(uint8_t *data1, uint8_t *data2);
//  void get4ByteData(int16_t _index , uint8_t *_data);

public:
  OSCMessage(void);
  OSCMessage(const char *_oscAddr);
  ~OSCMessage(void);
  
  int16_t beginMessage( const char *_addr);
  void flush(void);
  
  int16_t getArgsNum(void);
  char    getArgTypeTag(uint16_t _index);		
  uint8_t* getIpAddress(void);
  char *  getOSCAddress(void);
  uint16_t getPortNumber(void);
  
  void setAddress(uint8_t *_ip , uint16_t _port);
  void setIpAddress( uint8_t *_ip );
  void setPortNumber(uint16_t _port);
  int16_t setOSCAddress(const char *_addr);

  int16_t addArgInt32(int32_t _value);
  int32_t getArgInt32(uint16_t _index);

#ifdef _USE_FLOAT_
  int16_t addArgFloat(float _value);
  float getArgFloat(uint16_t _index);
#endif

#ifdef _USE_STRING_
  int16_t addArgString(const char* _value);
  int16_t getArgString(uint16_t _index, char *_rcvstr);
  int16_t getArgStringSize(uint16_t _index);
#endif

	
  friend class OSCServer;
  friend class OSCClient;
  friend class OSCDecoder;
  friend class OSCEncoder;
  friend class Pattern;
	
};


#endif
