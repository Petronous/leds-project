#ifndef LED_WRITER_H
#define LED_WRITER_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class ledList {
public:
  int get_led(int x, int y) {
    return leds[(x - (x%8))*8 + x%8  +  y*8];
  }

  void set_led(int x, int y, int val) {
    // cout << x << " " << y << " " << val <<endl;
    // cout << (x - (x%8))*8 + x%8  +  y*8 << " " << leds.size() << endl;
    leds[(x - (x%8))*8 + x%8  +  y*8] = val;
    // cout << "SUCCESSSS" << endl;
  }

  std::vector<int> get_all() {
    return leds;
  }

  void print() {
    cout << "print \n";

    string lines[8];
    string _add;
    bool led;
    cout << leds.size() << "SIZE OF LEDS \n";
    for (int i = 0; i < leds.size(); i++) {
      led = leds[i];
      // cout << led;
      // cout << endl;

      if (led) {_add = "X";} else {_add = ".";}
      if (i%8 == 7) {_add += " ";}
      lines[(i%64)/8] += _add;
    }
    for (auto i:lines) {
      for (auto j:i) {cout << j;}
      cout << endl;
    }
  }

  ledList(int len) {
    for (int i = 0; i < len; i++) {
      leds.push_back(0);
    }
    cout << "CONSTRUCTED";
  }

  void tell() {
    cout << "Hallo!" << endl;
  }
private:
  std::vector<int> leds;
};

#endif
