#define micIn A0

// Maintainence function for trimming the microphone DC offset
uint16_t estimateDCoffset(int numSamples) {
  float total = 0.0; // Variable to accumulate the total sum of samples
  int sensorValue; // Variable to store the sensor reading

  for (int i = 0; i < numSamples; i++) {
    sensorValue = analogRead(micIn); // Read the sensor value
    total += sensorValue; // Add the sensor value to the total
    delay(10); // Delay between samples
  }

  float average = total / numSamples;
  Serial.print("Microphone signal DC offset: ");
  Serial.print(average / 1024 * 5); // Print the average
  Serial.println("V");

  return uint16_t (average); 
}