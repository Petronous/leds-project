#define DISPLAYS 5
#define WIDTH 8*DISPLAYS
#define NUMCHAR 27

#include <iostream>
#include <string>
#include "ledList.h"

using namespace std;

ledList mainLeds{WIDTH*8};
// int setup(){
//     int mainLeds[WIDTH*8];
//     for (int i = 0; i < WIDTH*8; i++) {
//         mainLeds[i] = 0;
//     }
//     // for (auto i:mainLeds) {
//     //     cout << i;
//     // }
//     return 0;
// }

int main() {
    // setup();
    mainLeds.tell();
    string text = {"000011100001011110010111100010001110100110011110000001101001100010010110000100010111100110010111000001101001111010000111001101001111010001000100000001110101001100010110100010001110100110011001000000100000001000100010000000010001000110010110100010001010010010101001011000100010001000100010000010011111100110011001000010011101101110011001000001101001100110010110000011001010110010001000000000110101001100010001000010111100100010001000000001101001010010100110010011100100010001000111000010011001100110010111000010011001011001100110000010011111111101100110000010011001011010011001000010011001011000100010000011110001001001001111000000000000000000000000"};

    // for(int i = 0; i < NUM_mainLeds; i++) {
    //     mainLeds[i] = CRGB(0,0,1);

    string letters[NUMCHAR];
    for(int i = 0; i < NUMCHAR; i++) {
        letters[i] = "";
        for(int j = 0; j < 24; j++) {
            letters[i] = letters[i] + text[i*24 + j];
        }
    }
    // for(int i = 0; i < NUM_mainLeds;i++){
    //     mainLeds[i] = CRGB(0,0,0);
    // }

    text = "abcdefghi";
    int x = 0;
    string alphabet = "abcdefghijklmnopqrstuvwxyz ";
    cout << alphabet << endl;
    for(int i = 0; i < text.length(); i++){
        cout << i << " " << x << " " << text.length() << " " << endl;
      if (x+4 < WIDTH) {
        char ch = text[i];
        int index = alphabet.find(ch);
        cout <<index<< " INDEX OF LETTER " << ch << endl;

        int xx = 0;
        int y  = 0;

        for(int j = 0; j < 24; j++) {
            char ledVal = letters[index][j];
            if (ledVal == '1') {
                xx = x + j%4;
                y  = j/4 + 1;
                // cout << "WRITING AT LED" << endl;
                mainLeds.set_led(xx, y, 1);
            }
        }
        cout << "\n FINISHED LETTER \n";
        x += 5;
      }
    }

    cout << "PRINTING!!" << endl;
    mainLeds.print();
    // string lines[8];
    // string add;
    // bool led;
    // for (int i = 0; i < WIDTH*8; i++) {
    //   led = mainLeds[i];
    //
    //   if (led) {add = "X";} else {add = ".";}
    //   if (i%8 == 7) {add += " ";}
    //   lines[(i%64)/8] += add;
    // }
    // for (auto i:lines) {
    //   for (auto j:i) {cout << j;}
    //   cout << endl;
    // }

    return 0;
}
