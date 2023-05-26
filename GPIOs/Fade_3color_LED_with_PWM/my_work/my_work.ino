  uint8_t led_gpio_blue=12;
  uint8_t led_gpio_red =10;
  uint8_t  led_gpio_green =14;
  int brightness = 0;
  int fadeAmountModify= 1;

void setup() {

  Serial.begin(115200);
  // put your setup code here, to run once:
  ledcAttachPin(led_gpio_blue, 0);
  ledcSetup(0, 12000, 8); // it means we are going to use 2^8 possible states of brightness during the waveform

  ledcAttachPin(led_gpio_red, 1);
  ledcSetup(1, 4000, 8); // it means we are going to use 2^8 possible states of brightness during the waveform

  ledcAttachPin(led_gpio_green, 2);
  ledcSetup(2, 2000, 8); // it means we are going to use 2^8 possible states of brightness during the waveform


}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Light LED");
  ledcWrite(0, brightness);
  delay(50);
  ledcWrite(1,brightness);
  delay(50);
  ledcWrite(2,brightness);

  brightness += fadeAmountModify;

  if(brightness<=0 || brightness>=256)
  {
    fadeAmountModify = - fadeAmountModify;
  }

  delay(50);
}
