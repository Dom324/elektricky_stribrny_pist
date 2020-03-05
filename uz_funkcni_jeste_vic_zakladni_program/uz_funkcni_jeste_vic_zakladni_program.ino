#define BUSY 6
#define STOP 8
#define RESET 9
#define READ_START 2
#define WRITE_START 10

int pozice[16][4]={{0,0,0,0},//0 - NIC
                  {0,0,0,1},//1
                  {0,0,1,0}, //2
                  {0,0,1,1},//3
                  {0,1,0,0},//4
                  {0,1,0,1},//5
                  {0,1,1,0},//6
                  {0,1,1,1},//7
                  {1,0,0,0},//8
                  {1,0,0,1},//9
                  {1,0,1,0},//10-A
                  {1,0,1,1},//11-B
                  {1,1,0,0},//12-C
                  {1,1,0,1},//13-D
                  {1,1,1,0},//14-E
                  {1,1,1,1}};//15-F-reset

void setup() {

  pinMode(BUSY, INPUT);
  pinMode(READ_START, INPUT);
  pinMode(READ_START + 1, INPUT);
  pinMode(READ_START + 2, INPUT);
  pinMode(READ_START + 3, INPUT);

  pinMode(WRITE_START, OUTPUT);
  pinMode(WRITE_START + 1, OUTPUT);
  pinMode(WRITE_START + 2, OUTPUT);
  pinMode(WRITE_START + 3, OUTPUT);
  pinMode(STOP, OUTPUT);
  pinMode(RESET, OUTPUT);
        

  digitalWrite(RESET, HIGH);
  delay(200);
  digitalWrite(RESET, LOW);
  delay(200);

  digitalWrite(WRITE_START, HIGH);
  digitalWrite(WRITE_START + 1, HIGH);
  digitalWrite(WRITE_START + 2, HIGH);
  digitalWrite(WRITE_START + 3, HIGH);
 Serial.begin(9600);
  delay(200);
    digitalWrite(STOP,0);
}

void loop() {


  
  digitalWrite(WRITE_START, 0);
  digitalWrite(WRITE_START + 1, LOW);
  digitalWrite(WRITE_START + 2, 0);
  digitalWrite(WRITE_START + 3, 1);
delay(50);
  while(!digitalRead(BUSY)){

delay(200);
    
  }
delay(200);
int poloha=!digitalRead(READ_START);
  poloha=poloha+2*!digitalRead(READ_START + 1);
  poloha=poloha+4*!digitalRead(READ_START + 2);
  poloha=poloha+8*!digitalRead(READ_START + 3);
  Serial.println("poloha: ");
  Serial.println(poloha );
  
  digitalWrite(WRITE_START, 1);
  digitalWrite(WRITE_START + 1, HIGH);
  digitalWrite(WRITE_START + 2, LOW);
  digitalWrite(WRITE_START + 3, HIGH);

delay(50);
    while(!digitalRead(BUSY)){

delay(200);
    
  }
  delay(200);
  poloha=!digitalRead(READ_START);
  poloha=poloha+2*!digitalRead(READ_START + 1);
  poloha=poloha+4*!digitalRead(READ_START + 2);
  poloha=poloha+8*!digitalRead(READ_START + 3);
  Serial.println("poloha: ");
  Serial.println(poloha);
  
}
