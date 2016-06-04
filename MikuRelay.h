#ifndef _MIKU_RELAY_H_
#define _MIKU_RELAY_H_

class Miku_Relay {
 public:
  Miku_Relay();
  Miku_Relay(int on, int off);
  void setOn(void);
  void setOff(void);
 private:
  int onPin, offPin;
};

#endif