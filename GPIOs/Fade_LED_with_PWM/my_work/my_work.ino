  const byte my_led_gpio=12;
  int brightness = 0;
  int fadeAmountModify= 1;

void setup() {
  // put your setup code here, to run once:
  ledcAttachPin(my_led_gpio, 0);
  ledcSetup(0, 12000, 8); // it means we are going to use 2^8 possible states of brightness during the waveform

}

void loop() {
  // put your main code here, to run repeatedly:
  ledcWrite(0, brightness);

  brightness += fadeAmountModify;

  if(brightness<=0 || brightness>=256)
  {
    fadeAmountModify = - fadeAmountModify;
  }

  delay(50);
}
