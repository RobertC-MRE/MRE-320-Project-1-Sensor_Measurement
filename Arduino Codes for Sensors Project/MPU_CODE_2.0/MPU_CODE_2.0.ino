#define ACCELE_RANGE 4   // ±4g

#include <Wire.h>

const int MPU_addr = 0x68; // I2C address of the MPU-6050

float AcX, AcY, AcZ;

void setup() {
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // Wake up MPU-6050
  Wire.endTransmission(true);

  Serial.begin(9600);
}

void loop() {
  // Only run if the time since start is less than 3000ms
  if (millis() < 60000) {            // Can change the time here
    Wire.beginTransmission(MPU_addr);
    Wire.write(0x3B);  // ACCEL_XOUT_H
    Wire.endTransmission(false);
    Wire.requestFrom(MPU_addr, 6, true); // Only accel registers

    AcX = Wire.read() << 8 | Wire.read();
    AcY = Wire.read() << 8 | Wire.read();
    AcZ = Wire.read() << 8 | Wire.read();

    // Convert raw values to g units
    float ax = (AcX / 16384.0) * ACCELE_RANGE;
    float ay = (AcY / 16384.0) * ACCELE_RANGE;
    float az = (AcZ / 16384.0) * ACCELE_RANGE;

    // Arduino Serial Plotter friendly format
    Serial.print("X:"); Serial.print(ax);
    Serial.print(" Y:"); Serial.print(ay);
    Serial.print(" Z:"); Serial.println(az);

    delay(50);
  }
}