#define RESET_PIN 11
#define FLASH_PIN 13
#define A0_PIN 10
#define A1_PIN 12
#define A2_PIN 6
#define A3_PIN 7
#define A4_PIN 26
#define WR_PIN 31
#define CE_PIN 14
#define RD_PIN 27
#define D0_PIN 17
#define D1_PIN 18
#define D2_PIN 4
#define D3_PIN 3
#define D4_PIN 1
#define D5_PIN 0
#define D6_PIN 22
#define D7_PIN 28

byte addressPins[] = {A0_PIN, A1_PIN, A2_PIN, A3_PIN, A4_PIN};
byte dataPins[] = {D0_PIN, D1_PIN, D2_PIN, D3_PIN, D4_PIN, D5_PIN, D6_PIN, D7_PIN};

void dataAddressOutput(byte data, byte address){
  for( int i = 0; i < 8; i++ ) digitalWrite(dataPins[i], (data >> i) & 0x01 ? HIGH : LOW);
  for( int i = 0; i < 5; i++ ) digitalWrite(addressPins[i], (address >> i) & 0x01 ? HIGH : LOW);
  digitalWrite(WR_PIN, LOW);
  delay(1);
  digitalWrite(WR_PIN, HIGH);
}

void initializeCustomChars(){
  
  //2
  dataAddressOutput(0x02, 0x00);
  dataAddressOutput(0x09, 0x08);
  dataAddressOutput(0x15, 0x09);
  dataAddressOutput(0x15, 0x0A);
  dataAddressOutput(0x15, 0x0B);
  dataAddressOutput(0x15, 0x0C);
  dataAddressOutput(0x15, 0x0D);
  dataAddressOutput(0x13, 0x0E);
  dataAddressOutput(0x82, 0x1A);
}

void setup() {
  pinMode(RESET_PIN, OUTPUT);
  pinMode(FLASH_PIN, OUTPUT);
  pinMode(WR_PIN, OUTPUT);
  pinMode(CE_PIN, OUTPUT);
  pinMode(RD_PIN, OUTPUT);
  for(int i = 0; i < 5; i++) pinMode(addressPins[i], OUTPUT);
  for(int i = 0; i < 8; i++) pinMode(dataPins[i], OUTPUT);
  digitalWrite(WR_PIN, HIGH);
  digitalWrite(CE_PIN, LOW);
  digitalWrite(RD_PIN, HIGH);
  digitalWrite(FLASH_PIN, HIGH);
  digitalWrite(RESET_PIN, LOW);
  delay(1);
  digitalWrite(RESET_PIN, HIGH);
  
  dataAddressOutput(0x53, 0x18);
  initializeCustomChars();

}

void loop() {
  // put your main code here, to run repeatedly:

}
