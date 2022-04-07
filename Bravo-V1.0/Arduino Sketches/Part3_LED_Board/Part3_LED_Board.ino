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
#define B1 A9
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

void setup() {
  Serial.begin(115200);
  reset_pins();
  test_register_a_LED();
  test_register_b_LED();
  test_BUS_LED();
  test_flags_LED();
  test_ADD_LED();
  test_control_signals_LED();
  pinMode(_RST,INPUT);
  }

int dt=100;

void test_register_a_LED(){
  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(A3,OUTPUT);
  pinMode(A4,OUTPUT);
  pinMode(A5,OUTPUT);
  pinMode(A6,OUTPUT);
  pinMode(A7,OUTPUT);
  digitalWrite(A0, HIGH);
  delay(dt);
  digitalWrite(A1, HIGH);
  delay(dt);
  digitalWrite(A2, HIGH);
  delay(dt);
  digitalWrite(A3, HIGH);
  delay(dt);
  digitalWrite(A4, HIGH);
  delay(dt);
  digitalWrite(A5, HIGH);
  delay(dt);
  digitalWrite(A6, HIGH);
  delay(dt);
  digitalWrite(A7, HIGH);
  delay(dt);
  digitalWrite(A0, LOW);
  delay(dt);
  digitalWrite(A1, LOW);
  delay(dt);
  digitalWrite(A2, LOW);
  delay(dt);
  digitalWrite(A3, LOW);
  delay(dt);
  digitalWrite(A4, LOW);
  delay(dt);
  digitalWrite(A5, LOW);
  delay(dt);
  digitalWrite(A6, LOW);
  delay(dt);
  digitalWrite(A7, LOW);
  delay(dt);
}

void test_register_b_LED(){
  pinMode(B0,OUTPUT);
  pinMode(B1,OUTPUT);
  pinMode(B2,OUTPUT);
  pinMode(B3,OUTPUT);
  pinMode(B4,OUTPUT);
  pinMode(B5,OUTPUT);
  pinMode(B6,OUTPUT);
  pinMode(B7,OUTPUT);
  digitalWrite(B0, HIGH);
  delay(dt);
  digitalWrite(B1, HIGH);
  delay(dt);
  digitalWrite(B2, HIGH);
  delay(dt);
  digitalWrite(B3, HIGH);
  delay(dt);
  digitalWrite(B4, HIGH);
  delay(dt);
  digitalWrite(B5, HIGH);
  delay(dt);
  digitalWrite(B6, HIGH);
  delay(dt);
  digitalWrite(B7, HIGH);
  delay(dt);
  digitalWrite(B0, LOW);
  delay(dt);
  digitalWrite(B1, LOW);
  delay(dt);
  digitalWrite(B2, LOW);
  delay(dt);
  digitalWrite(B3, LOW);
  delay(dt);
  digitalWrite(B4, LOW);
  delay(dt);
  digitalWrite(B5, LOW);
  delay(dt);
  digitalWrite(B6, LOW);
  delay(dt);
  digitalWrite(B7, LOW);
  delay(dt);
}


void test_BUS_LED(){
  for (int n=0;n < 8;n+=1){
    pinMode(BUS [n], OUTPUT);
    digitalWrite(BUS[n],HIGH);
    delay(dt);
  }
  for (int n=0;n < 8;n+=1){
    digitalWrite(BUS[n],LOW);
    delay(dt);
  }
  
}

void test_flags_LED(){
  pinMode(CLK,OUTPUT);
  pinMode(FLC,OUTPUT);
  pinMode(FLN,OUTPUT);
  pinMode(FLZ,OUTPUT);
  digitalWrite(CLK, HIGH);
  delay(dt);
  digitalWrite(FLC, HIGH);
  delay(dt);
  digitalWrite(FLN, HIGH);
  delay(dt);
  digitalWrite(FLZ, HIGH);
  delay(dt);
  digitalWrite(CLK, LOW);
  delay(dt);
  digitalWrite(FLC, LOW);
  delay(dt);
  digitalWrite(FLN, LOW);
  delay(dt);
  digitalWrite(FLZ, LOW);
  delay(dt);
}

void test_ADD_LED(){
  for (int n=0;n < 16;n+=1){
    pinMode(ADD [n], OUTPUT);
    digitalWrite(ADD[n],HIGH);
    delay(dt);
  }
  for (int n=0;n < 16;n+=1){
    digitalWrite(ADD[n],LOW);
    delay(dt);
  }
}

void test_control_signals_LED(){
    
    pinMode(_BO,OUTPUT);
    pinMode(_BI,OUTPUT);
    pinMode(_AO,OUTPUT);
    pinMode(_AI,OUTPUT);
    pinMode(_RO,OUTPUT);
    pinMode(RI,OUTPUT);
    pinMode(MI,OUTPUT);
    pinMode(HI,OUTPUT);
    pinMode(_EO,OUTPUT);
    pinMode(ES,OUTPUT);
    pinMode(EC,OUTPUT);
    pinMode(_IC,OUTPUT);
    pinMode(TR,OUTPUT);
    pinMode(CEME,OUTPUT);
    pinMode(CO,OUTPUT);
    pinMode(CI,OUTPUT);

    digitalWrite(_BO,LOW);
    delay(dt);
    digitalWrite(_BI,LOW);
    delay(dt);
    digitalWrite(_AO,LOW);
    delay(dt);
    digitalWrite(_AI,LOW);
    delay(dt);
    digitalWrite(_RO,LOW);
    delay(dt);
    digitalWrite(RI,HIGH);
    delay(dt);
    digitalWrite(MI,HIGH);
    delay(dt);
    digitalWrite(HI,HIGH);
    delay(dt);
    digitalWrite(_EO,LOW);
    delay(dt);
    digitalWrite(ES,HIGH);
    delay(dt);
    digitalWrite(EC,HIGH);
    delay(dt);
    digitalWrite(_IC,LOW);
    delay(dt);
    digitalWrite(TR,HIGH);
    delay(dt);
    digitalWrite(CEME,HIGH);
    delay(dt);
    digitalWrite(CO,HIGH);
    delay(dt);
    digitalWrite(CI,HIGH);
    delay(dt);

    digitalWrite(_BO,HIGH);
    delay(dt);
    digitalWrite(_BI,HIGH);
    delay(dt);
    digitalWrite(_AO,HIGH);
    delay(dt);
    digitalWrite(_AI,HIGH);
    delay(dt);
    digitalWrite(_RO,HIGH);
    delay(dt);
    digitalWrite(RI,LOW);
    delay(dt);
    digitalWrite(MI,LOW);
    delay(dt);
    digitalWrite(HI,LOW);
    delay(dt);
    digitalWrite(_EO,HIGH);
    delay(dt);
    digitalWrite(ES,LOW);
    delay(dt);
    digitalWrite(EC,LOW);
    delay(dt);
    digitalWrite(_IC,HIGH);
    delay(dt);
    digitalWrite(TR,LOW);
    delay(dt);
    digitalWrite(CEME,LOW);
    delay(dt);
    digitalWrite(CO,LOW);
    delay(dt);
    digitalWrite(CI,LOW);
    delay(dt);
  }


void pulse_clock(int clock_delay){
   digitalWrite(CLK, HIGH);
   delay(clock_delay);
   digitalWrite(CLK, LOW);
}

void manual_clock_check(){
    bool clock_pressed = digitalRead(manual_clock);
   if (clock_pressed == true){
     Serial.println("Manual Clock Pressed");
   }
}

void System_reset_check(){
   
   bool reset_pressed = digitalRead(_RST);
   if (reset_pressed == false){
    Serial.println("System Reset Pressed");
   }
}

void loop() {
  manual_clock_check();
  System_reset_check();
}
