//necessary library to allow Arduino communicate with MPU6050 Using I2C
#include <Wire.h> 

//Gyroscope Variables
float elapsed_time, time, prev_time;  //variables to track time to calc. the elapsed time between readings
int gyro_error = 0;                   // flag to ensure the gyroscope's error calculation is performed only once
float gyro_raw_Z;                     // stores the raw gyroscope data for Z-axis (yaw)
float gyro_angle_Z;                   // stores the integrated angle for Z-axis
float gyro_raw_error_Z;               // stores the initial error in the gyroscope's Z-axis

void setup() {

  Wire.begin();                      // initialize the I2C communication
  Wire.beginTransmission(0x68);      // start communication with the MPU6050 which has the address '0x68'
  Wire.write(0x6B);                  // reset the MPU6050 by writing '0x00' to the power management '0x6B' to take MPU6050 out of sleep mode
  Wire.write(0x00);
  Wire.endTransmission(true);        // end the communication

// Gyroscope Configuration
  Wire.beginTransmission(0x68);     // start communication with the MPU6050 which has the address '0x68'
  Wire.write(0x1B);                 // to specify that next data sent will configure the gyroscope by addressing the 'GYRO_CONFIG' register '0x1B'
  Wire.write(0x10);                 // set the gyroscope's full-scale range to 1000/s. the bits '00010000' (0x10 in hex) configure this range
  Wire.endTransmission(true);       // end transmission

  Serial.begin(9600);             
  time = millis();                 // records the current time in milliseconds since the program started

//Gyroscope Error Calculation
  if (gyro_error == 0){                              // check if the gyroscope error has been calculated or not
    for(int i = 0; i < 200; i++){                    // for loop to get enough data and averaging it to get the error
      Wire.beginTransmission(0x68);
      Wire.write(0x47);                              // request data from Z-axis gyroscope register '0x47'
      Wire.endTransmission(false);                   // end the transmission but keep I2C connection open
      Wire.requestFrom (0x68, 2 , true);             // request 2 bytes from MPU6050 of the Z-axis gyroscope data

      gyro_raw_Z = Wire.read() << 8 | Wire.read();   
      gyro_raw_error_Z += gyro_raw_Z / 32.8;         // convert the raw data to degrees per sec (from datasheet) and accumulates it to calc the avg. error
      if (i == 199){                                 // detect the 200th iteration
        gyro_raw_error_Z /= 200;                     // calc avg. error by dividing by 200
        gyro_error = 1;                              // set the flag to indicate that error calc is complete
      }
    }
  }

}

void loop() {
  prev_time = time;                                         // stores previous time
  time = millis();                                          // update current time
  elapsed_time = (time - prev_time) / 1000.0;               // calc. the time elapsed in seconds since last loop iteration

  // Reading the Gyroscope Data 
  Wire.beginTransmission(0x68);                             
  Wire.write(0x47);                                         
  Wire.endTransmission(false);
  Wire.requestFrom (0x68, 2, true);

  gyro_raw_Z = Wire.read() << 8 | Wire.read();
  gyro_raw_Z = (gyro_raw_Z /  32.8) - gyro_raw_error_Z;     // Converts the raw data to degrees per second and subtracts the previously calculated error to correct the data

// Integrating to Get the Yaw Angle
  gyro_angle_Z += gyro_raw_Z * elapsed_time;                // multiplying the angular velocity (gyr_raw_Z) by the elapsed_time to get the change in angle, which is then added to the previous yaw angle (gyro_angle_z)
  
  Serial.print("Yaw (Zº): ");
  Serial.println(gyro_angle_Z);                             // printing the Yaw angle in degrees

  delay(200);
}
