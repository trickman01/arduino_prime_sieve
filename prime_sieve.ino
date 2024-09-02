//Prime sieve using arduino.  Just trying to make it work.  
//Will not be saving individual prime number as there are 78,498 primes below 1,000,000
//and the arduino has limited ram
#define LED_pin 13
bool led_state = false;
int known_primes = 1;         //will be starting with 2 as the first known prime
int test_num = 3;             //will test only odd numbers
int max_num = 1000000;        //testing to 1,000,000 should give 78,498 prime numbers

bool test_number(int number){
  float limit = sqrt(number); //if a number is not prime, one of it's divisors will be less than or equal to its square root.
  int div_num = 3;
  while(div_num <= limit){
    if (number % div_num == 0){
      return false;
    }
    else{
      div_num += 2;
    }
  }
  return true;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_pin, OUTPUT);
  Serial.begin(9600);
  int start_time = millis();
  while(test_num < max_num){
    if(test_number(test_num) == true){
      known_primes++;
    }
    test_num += 2;
  }
  int elapsed = millis() - start_time;
  Serial.println(known_primes);
  Serial.println(elapsed);
}

void loop() {
  // put your main code here, to run repeatedly:
  led_state = !led_state;
  digitalWrite(LED_pin, led_state);
  delay(500);

}
