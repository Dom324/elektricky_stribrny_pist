#define WRITE_START 10
#define READ_START 2
#define F 15
#define PAUZA 3000
#define PAUZA2 100


#define BUSY 6
int Stop = 8;
int Reset = 9;

int IN_0 = 13;
int IN_1 = 12;
int IN_2 = 11;
int IN_3 = 10;



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
//int posNow[4];
int poloha;
void Pos(int a);
void Read();

void setup() {
  Serial.begin(9600);
  Serial.println("OK");

  pinMode(BUSY, INPUT);
  pinMode(Stop, OUTPUT);
  pinMode(Reset, OUTPUT);
  pinMode(A5,INPUT);//alarm


  for(int i=READ_START;i<=READ_START+4;i++){
    pinMode(i,INPUT);
  }
  for(int i=WRITE_START;i<=WRITE_START+4;i++){
    pinMode(i,OUTPUT);
  }
  digitalWrite(Reset,HIGH);
  delay(PAUZA2);
  digitalWrite(Reset,LOW);
  delay(PAUZA2);
  
  Pos(F);
  
 
  
  
 }

void loop() {
if(Serial.available()>0){
    poloha=Serial.parseInt();
    //poloha--;
    Serial.println(poloha);
    delay(500);
    Pos(poloha);
    Cekej();
    //delay(PAUZA);
    Read();

    //delay(500);
  //Serial.print("Poloha je :");
  //delay(500);
  //int x=ReadPoloha();
  //Serial.println(x);
  //delay(500);
  Serial.println("--------------------------\n--------------------------");
  Serial.parseInt();
  //delay(500);
  }
  //delay(500);
}
void Pos(int a){
  int y=0;
  for(int i=WRITE_START;i<=WRITE_START+4;i++){
    if(pozice[a][y]==0){
       digitalWrite(i,LOW);
    } 
    else {
      digitalWrite(i,HIGH);
    } 
   
    y++;
  }
}

void Read(){
 bool posNow[4]={!digitalRead(READ_START+3),!digitalRead(READ_START+2),!digitalRead(READ_START+1),!digitalRead(READ_START)};
  
  for(int i=0;i<4;i++){
    Serial.print(posNow[i]);
    Serial.print("\t");
  }
  Serial.println("");
}
void Cekej(){
  delay(PAUZA2);
  while(!digitalRead(BUSY)){
    Serial.println("CEKAM!");
    delay(PAUZA2);
  }
  
}
