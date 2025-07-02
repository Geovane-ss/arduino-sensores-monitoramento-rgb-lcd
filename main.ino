#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2); // Pinos RS, E, D4, D5, D6, D7
int oldLdrValue = 0;
int oldUmidadeValue = 0;
int oldTemperaturaValue = 0;
void setup() {
 lcd.begin(16, 2); // Inicializa o display LCD 16x2
 
 pinMode(A0, INPUT); // Define o pino A0 como entrada (LDR)
 pinMode(A1, INPUT); // Define o pino A1 como entrada (Sensor de Umidade)
 pinMode(A2, INPUT); // Define o pino A2 como entrada (LM35)
}
void loop() {
 // Leitura dos sensores
 int ldrValue = analogRead(A0); // Lê o valor do LDR (0-1023)
 int umidadeValue = analogRead(A1); // Lê o valor do sensor de umidade (0-1023)
 int temperaturaValue = analogRead(A2); // Lê o valor do LM35 (0-1023)
 // Verifica se houve uma mudança significativa nos valores dos sensores
 if (abs(ldrValue - oldLdrValue) > 10 || abs(umidadeValue - oldUmidadeValue) > 10 || 
abs(temperaturaValue - oldTemperaturaValue) > 10) {
 // Mapeamento dos valores para o intervalo desejado
 int ledLdrValue = map(ldrValue, 0, 1023, 0, 99); 
 int ledUmidadeValue = map(umidadeValue, 0, 1023, 0, 99); 
 int ledTemperaturaValue = map(temperaturaValue, 0, 1023, 0, 99); 
 int displayLdrValue = map(ldrValue, 0, 1023, 0, 100); 
 int displayUmidadeValue = map(umidadeValue, 0, 1023, 0, 100); 
 float voltage = temperaturaValue * (5.0 / 1023.0);
 int displayTemperaturaValue = voltage * 100; 
 // Exibição dos valores no display LCD
 lcd.clear(); 
 lcd.setCursor(0, 0); 
 lcd.print("Umid:"); 
 lcd.print(displayUmidadeValue); 
 lcd.print("% Temp:"); 
 lcd.print(displayTemperaturaValue); 
 lcd.print("C"); 
 
 lcd.setCursor(0, 1); 
 lcd.print("Lum: "); 
 lcd.print(displayLdrValue); 
 lcd.print(" Atual:"); 
 lcd.print(millis() / 1000); 
 // Controle dos LEDs RGB com base nos valores dos sensores
 controlarLEDs(ledLdrValue, ledUmidadeValue, ledTemperaturaValue);
 
 // Atualiza os valores antigos dos sensores
 oldLdrValue = ldrValue;
 oldUmidadeValue = umidadeValue;
 oldTemperaturaValue = temperaturaValue;
 }
 // Adicione um atraso de 500 milissegundos (0.5 segundo)
 delay(500);
}
// Função para controlar os LEDs RGB com base nos valores dos sensores
void controlarLEDs(int valorLDR, int valorUmidade, int valorTemperatura) {
 // LED RGB 1 (Luminosidade - LDR)
 if (valorLDR <= 33) {
 setColor(9, 0, 255, 0); 
 } else if (valorLDR <= 66) {
 setColor(9, 255, 255, 0); 
 } else {
 setColor(9, 255, 0, 0); 
 }
 
 // LED RGB 2 (Umidade de Solo)
 if (valorUmidade <= 33) {
 setColor(10, 0, 255, 0); 
 } else if (valorUmidade <= 66) {
 setColor(10, 255, 255, 0); 
 } else {
 setColor(10, 255, 0, 0); 
 }
 
 // LED RGB 3 (Temperatura - LM35)
 if (valorTemperatura <= 33) {
 setColor(11, 0, 255, 0); 
 } else if (valorTemperatura <= 66) {
 setColor(11, 255, 255, 0); 
 } else {
 setColor(11, 255, 0, 0); 
 }
}
// Função para definir a cor de um LED RGB específico
void setColor(int pino, int red, int green, int blue) {
 analogWrite(pino, red); 
 analogWrite(pino + 1, green); 
 analogWrite(pino + 2, blue); 
}