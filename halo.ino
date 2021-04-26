// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------

#include <NewPing.h>

#define TRIGGER_PIN  2  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     3  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 50 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
#define TRIGGER_PIN2  4  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN2     5  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE2 50 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
#define TRIGGER_PIN3  6  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN3     7  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE3 50 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
NewPing sonar2(TRIGGER_PIN2, ECHO_PIN2, MAX_DISTANCE2); // NewPing setup of pins and maximum distance.
NewPing sonar3(TRIGGER_PIN3, ECHO_PIN3, MAX_DISTANCE3); // NewPing setup of pins and maximum distance.



void setup() {
  int m=8;
  int m2=9;
  int m3=10;
  int B=11;
  pinMode(11,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  Serial.begin(9600); // Open serial monitor at 115200 baud to see ping results.

}

void loop() {
  delay(500);                      // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
  unsigned int uS2 = sonar2.ping(); // Send ping, get ping time in microseconds (uS).
  unsigned int uS3 = sonar3.ping(); // Send ping, get ping time in microseconds (uS).
  
  if(uS/US_ROUNDTRIP_CM!=0)
  {
  digitalWrite(8,HIGH);
  digitalWrite(11,HIGH);
  
  Serial.print("Ping: ");
  Serial.print(uS / US_ROUNDTRIP_CM); // Convert ping time to distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");
  }
  else
  {
     digitalWrite(8,LOW);
    
  }
  if(uS2/US_ROUNDTRIP_CM!=0)
  {
  digitalWrite(9,HIGH );
  digitalWrite(11,HIGH);
  Serial.print("Ping2: ");
  Serial.print(uS2 / US_ROUNDTRIP_CM); // Convert ping time to distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");
  }
  else
  {
     digitalWrite(9,LOW);
    
  }
  if(uS3/US_ROUNDTRIP_CM!=0)
  {
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
  Serial.print("Ping: ");
  Serial.print(uS3 / US_ROUNDTRIP_CM); // Convert ping time to distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");
  }
  else
  {
     digitalWrite(10,LOW);
    
  }
  
  
  }

