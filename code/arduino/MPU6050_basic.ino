#include <Wire.h>
#include <MPU6050.h>


MPU6050 mpu;

double accel_x = 0;
double accel_y = 0;
double accel_z = 0;

double gyro_x = 0;
double gyro_y = 0;
double gyro_z = 0;

unsigned long last_time = 0;
unsigned long sample_time = 100;


void setup() {

  Serial.begin(9600);

  // Wait until accel/gyro starts
  while ( !mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G) ) {
    Serial.println("Trying to connect...");
    delay(500);
  }

}

void loop() {

  if ( millis() - last_time >= sample_time ) {
    last_time = millis();

    // Normalize values from sensor
    Vector norm_accel = mpu.readNormalizeAccel();
    Vector norm_gyro = mpu.readNormalizeGyro();

    // Grab normalized values from accelerometer
    accel_x = norm_accel.XAxis;
    accel_y = norm_accel.YAxis;
    accel_z = norm_accel.ZAxis;

    // Grab normalized values from gyroscope
    gyro_x = norm_gyro.XAxis;
    gyro_y = norm_gyro.YAxis;
    gyro_z = norm_gyro.ZAxis;

    // Print accelerometer results
    Serial.print("X value from accelerometer: ");
    Serial.println(accel_x);
    Serial.print("Y value from accelerometer: ");
    Serial.println(accel_y);
    Serial.print("z value from accelerometer: ");
    Serial.println(accel_z);

    // Print gyroscope results
    Serial.print("X value from gyroscope: ");
    Serial.println(gyro_x);
    Serial.print("Y value from gyroscope: ");
    Serial.println(gyro_y);
    Serial.print("z value from gyroscope: ");
    Serial.println(gyro_z);

    Serial.println();
  }

}
