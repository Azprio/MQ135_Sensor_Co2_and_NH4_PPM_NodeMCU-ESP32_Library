#include<MQ135.h>
#define esp32_sample_rate 4096
#define arduino_sample_rate 1024
#define esp32_pin_no 25
#define arduino_pin A4


void setup() {
  Serial.begin(115200);
  int avg = 0;
  for(int i=0; i<10;i++){
  avg += analogRead(esp32_pin_no);
  delay(2000);
  }
  avg = avg/10;
  MQ135_init(esp32_sample_rate,avg);
}

void loop() {

  int adc = analogRead(esp32_pin_no);
  int CO2 = read_CO2(esp32_sample_rate,adc);
  int NH4 = read_NH4(esp32_sample_rate,adc);

  Serial.println(adc);
  Serial.print("CO2_PPM:  ");
  Serial.println(CO2);
  Serial.print("NH4_PPM:  ");
  Serial.println(NH4);
  delay(2000);

}
