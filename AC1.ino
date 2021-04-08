//variaveis da led
const int vermelho = 5;
const int verde = 6;
const int azul = 7;

bool estadoLedVermelho = false;
bool estadoLedAzul = false;
bool estadoLedVerde = false;

const int botao1 = 2;
const int botao2 = 3;

unsigned long lastDebounceTime1 = 0;
unsigned long lastDebounceTime2 = 0;

const int botaoDelay = 100;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  
  pinMode(vermelho, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
  
  Serial.begin(9600);
	
  Serial.println("AC1 - Meu Primeiro Projeto 2021");
  Serial.println("                           V1.0");
  Serial.println("Grupo: FURIA               ");
}

void loop()
{
  if((millis() - lastDebounceTime1) > botaoDelay && digitalRead(botao1)){
  	Serial.println("producao iniciada ");
    digitalWrite(vermelho, HIGH);
  	lastDebounceTime1 = millis();
  }
  if((millis() - lastDebounceTime1) > botaoDelay && digitalRead(botao2)){
  	Serial.println("producao encerrada ");
    digitalWrite(vermelho, LOW);
  	lastDebounceTime2 = millis();
  }
  if(getLuminosidade() > 5){
    digitalWrite (verde, HIGH);
  }else{
  	digitalWrite (verde, LOW); 
  }
  if(getTemperatura() >= 15){
    digitalWrite (azul, HIGH);
    Serial.println("a luminosidade do ambiemte esta muito alta"); }else{
    
    digitalWrite(azul, LOW);
    Serial.println("a luminosidade do ambiemte esta adequada"); }
  
  Serial.println("a temperatura e de ");
  Serial.println(getTemperatura ());
  Serial.println(" graus");
  Serial.println("a luminosidade do ambiente esta em ");
  Serial.println(getLuminosidade());
    
  delay(10);
}

void ledVermelho(bool estado){
  estadoLedVermelho = !estadoLedVermelho;
  digitalWrite(vermelho,estadoLedVermelho);
}
void ledVerde(bool estado){
  estadoLedVerde = !estadoLedVerde;
  digitalWrite(verde,estadoLedVerde);
}
void ledAzul(bool estado){
  estadoLedAzul = !estadoLedAzul;
	digitalWrite(azul,estadoLedAzul);
  
}

int getTemperatura(){
  	int temperaturaC;
	temperaturaC = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);     
  	return temperaturaC;
} 

int getLuminosidade(){
  	int luminosidade;
	luminosidade = map(analogRead(A1), 6, 619, -3, 10);
  	return luminosidade;
}
