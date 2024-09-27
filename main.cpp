

// Programmable frequency generator for Arduino and SI5351
// By IU1BOT - Lorenzo - iu1bot@vashradio.org

//---------------------------------------------------------------------------------------------------------

#include "si5351.h"


#define PIN_TX 13 //Monitor LED pin


Si5351 si5351(0x60);


uint32_t tx = 13000000; // Insert TX frequency in Hz 

//---------------------------------------------------------------------------------------------------------

void setup() {

  pinMode(PIN_TX, OUTPUT);


  si5351.init(SI5351_CRYSTAL_LOAD_8PF, 25000000, 0);

  si5351.set_freq(tx * SI5351_FREQ_MULT, SI5351_CLK1); //Define SI5351 output connector (CLK1)

  si5351.output_enable(SI5351_CLK1, 0);

  si5351.drive_strength(SI5351_CLK1,SI5351_DRIVE_2MA); //Power output settings in mA on 50ohm load (Maximum value = 8MA)

}

//---------------------------------------------------------------------------------------------------------

void loop() {                                  

    si5351.output_enable(SI5351_CLK1, 1); //working loop

    digitalWrite(PIN_TX, HIGH);

}
