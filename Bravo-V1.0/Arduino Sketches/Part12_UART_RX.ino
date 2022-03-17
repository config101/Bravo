const char BUS[]={23,25,27,29,31,33,35,37};
const char ADD[]={22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52};

#define CLK 2
#define CLK_in 3
#define HI 4
#define CEME 5
#define CI 6
#define CO 7
#define MI 8
#define RI 9
#define _RO 10
#define FLN 11
#define FLZ 12
#define FLC 13
#define TI 14
#define TO 15
#define TR 16
#define _HI 17
#define RX 18
#define TX 19
#define manual_clock 20
#define _RST 21
#define _AI 39
#define _AO 41
#define _BI 43
#define _BO 45
#define EC 47
#define ES 49
#define _EO 51
#define _IC 53
#define A0 A0
#define A1 A1
#define A2 A2
#define A3 A3
#define A4 A4
#define A5 A5
#define A6 A6
#define A7 A7
#define B0 A8
#define B1 A0
#define B2 A10
#define B3 A11
#define B4 A12
#define B5 A13
#define B6 A14
#define B7 A15

void reset_pins(){
    set_bus_pins_input();
    set_add_pins_input();    
    pinMode(CLK,OUTPUT);
    pinMode(CLK_in,INPUT);
    pinMode(HI,OUTPUT);
    pinMode(CEME,OUTPUT);
    pinMode(CI,OUTPUT);
    pinMode(CO,OUTPUT);
    pinMode(MI,OUTPUT);
    pinMode(RI,OUTPUT);
    pinMode(_RO,OUTPUT);
    pinMode(FLN,INPUT);
    pinMode(FLZ,INPUT);
    pinMode(FLC,INPUT);    
    pinMode(TI,OUTPUT);
    pinMode(TO,OUTPUT);
    pinMode(TR,OUTPUT);
    pinMode(_HI,OUTPUT);
    pinMode(RX,INPUT);
    pinMode(TX,INPUT);
    pinMode(manual_clock,INPUT);
    pinMode(_RST,OUTPUT);
    pinMode(_AI,OUTPUT);
    pinMode(_AO,OUTPUT);
    pinMode(_BI,OUTPUT);
    pinMode(_BO,OUTPUT);
    pinMode(EC,OUTPUT);
    pinMode(ES,OUTPUT);
    pinMode(_EO,OUTPUT);
    pinMode(_IC,OUTPUT);
    pinMode(A0,INPUT);
    pinMode(A1,INPUT);
    pinMode(A2,INPUT);
    pinMode(A3,INPUT);
    pinMode(A4,INPUT);
    pinMode(A5,INPUT);
    pinMode(A6,INPUT);
    pinMode(A7,INPUT);
    pinMode(B1,INPUT);
    pinMode(B2,INPUT);
    pinMode(B3,INPUT);
    pinMode(B4,INPUT);
    pinMode(B5,INPUT);
    pinMode(B6,INPUT);
    pinMode(B7,INPUT);

    digitalWrite(CLK, LOW);
    digitalWrite(HI, LOW);
    digitalWrite(CEME, LOW);
    digitalWrite(CI, LOW);
    digitalWrite(CO, LOW);
    digitalWrite(MI, LOW);
    digitalWrite(RI, LOW);
    digitalWrite(_RO, HIGH);
    digitalWrite(TI, LOW);
    digitalWrite(TO, LOW);
    digitalWrite(TR, LOW);
    digitalWrite(_HI, HIGH);
    digitalWrite(_RST, HIGH);
    digitalWrite(_AI, HIGH);
    digitalWrite(_AO, HIGH);
    digitalWrite(_BI, HIGH);
    digitalWrite(_BO, HIGH);
    digitalWrite(EC, LOW);
    digitalWrite(ES, LOW);
    digitalWrite(_EO, HIGH);
    digitalWrite(_IC, HIGH);       
}

void set_bus_pins_input(){
  for (int i = 0 ; i < 8; ++i) {  
       pinMode(BUS [i], INPUT);
    }
}

void set_bus_pins_output(){
  for (int i = 0 ; i < 8; ++i) {  
       pinMode(BUS [i], OUTPUT);
    }
}

void set_add_pins_input(){
  for (int i = 0 ; i < 16; ++i) {  
       pinMode(ADD [i], INPUT);
    }
}

void set_add_pins_output(){
  for (int i = 0 ; i < 16; ++i) {  
       pinMode(ADD [i], OUTPUT);
    }
}

//##################  Module Test Functions ######################
int dt=10;  //delay time in Miliseconds

void setup() {
  reset_pins();
  set_bus_pins_input();
  tone(CLK, 4800);
  digitalWrite(TO, HIGH);
}

void loop() {
  check_receive();
}

void check_receive(){
  int bus_value= read_bus();
  if (bus_value !=0){
   noTone(CLK); 
   digitalWrite(_BI, LOW);
   pulse_clock(dt);
   digitalWrite(_BI, HIGH);
   tone(CLK, 4800);
   transmit();
  }
}

void pulse_clock(int clock_delay){
   digitalWrite(CLK, HIGH);
   delayMicroseconds(100);
   digitalWrite(CLK, LOW);
   delayMicroseconds(100);
}

void transmit(){
  digitalWrite(_BO, LOW);
  digitalWrite(TI, HIGH);
  delay(dt);
  digitalWrite(TI, LOW);
  digitalWrite(_BO, HIGH);
}

unsigned int read_bus(){
  char output[64];
  unsigned int data =0;
  for (int n=7;n>=0;n-=1){
    int bit = digitalRead(BUS[n]) ? 1 : 0;
    data = (data << 1) + bit;
  }
  return data;
}

