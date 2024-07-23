#include <SimpleFOC.h>

MagneticSensorI2C sensor0 = MagneticSensorI2C(AS5600_I2C);

void setup() {

  Serial.begin(115200);
  _delay(750); //foc内置delay

  Wire.setClock(400000);

  // GPIO_2(SDA)、GPIO_14(SCL)
  Wire.begin(2, 14, (uint32_t)400000);

  sensor0.init(&Wire);
}

void loop() {
  sensor0.update();
  _delay(20);
  Serial.print(sensor0.getAngle()); 
  Serial.print("-"); 
  Serial.print(sensor0.getVelocity()); 
  Serial.println();
}
