# Sistema de Monitoramento Ambiental com Sensores e LEDs RGB

### Environmental Monitoring System with Sensors and RGB LEDs

## 📌 Descrição | Description

Este projeto utiliza sensores de **luminosidade (LDR)**, **umidade do solo** e **temperatura (LM35)** para monitorar o ambiente em tempo real. Os dados são exibidos em um **Display LCD 16x2**, atualizados a cada segundo com contador reiniciado a cada 60s. Três **LEDs RGB** representam visualmente os níveis das variáveis, conforme valores mapeados.

This project uses **light (LDR)**, **soil moisture**, and **temperature (LM35)** sensors to monitor environmental conditions in real time. Data is displayed on a **16x2 LCD Display**, updated every second with a counter reset every 60s. Three **RGB LEDs** visually represent the variable levels based on mapped values.

---

## 🧰 Componentes Utilizados | Components Used

- Arduino UNO
- Sensor de Temperatura LM35
- Sensor de Umidade do Solo
- Fotoresistor (LDR)
- Display LCD 16x2 (com potenciômetro para contraste)
- 3 LEDs RGB (com resistores de 220Ω)
- Jumpers e Protoboard
- Resistor de 10kΩ para o LDR

---

## 🧠 Lógica do Projeto | Project Logic

- Leitura dos sensores analógicos (`A0`, `A1`, `A2`);
- Mapeamento dos valores para escala de 0 a 99;
- LEDs RGB indicam os níveis:
  - **Verde**: 0–33 (bom)
  - **Amarelo**: 34–66 (moderado)
  - **Vermelho**: 67–99 (crítico)
- LCD exibe os dados e contador de segundos reiniciado a cada 60s.

---

## 📋 Exemplo do Display | LCD Example
- Umid: 45% Temp: 22°C
- Lum: 200 Atual: 15s

---

## 🚀 Como Usar | How to Use

- 1. **Clone o repositório / Clone the repository**

- git clone https://github.com/seu-usuario/seu-repositorio.git

- 2. Abra o arquivo .ino no Arduino IDE / Open the .ino file in Arduino IDE

- 3. Monte o circuito no Tinkercad ou fisicamente / Build the circuit (Tinkercad or real)

- 4. Conecte os pinos conforme abaixo / Connect the pins as follows:

- Componente	Pino Arduino
- LDR	A0
- Umidade Solo	A1
- Temperatura (LM35)	A2
- LCD	7,6,5,4,3,2
- LED RGB 1	9,10,11
- LED RGB 2	10,11,12
- LED RGB 3	11,12,13

- 5. Faça o upload para o Arduino / Upload to Arduino

---

🏁 Futuras Melhorias | Future Improvements

Adicionar comunicação Wi-Fi com ESP8266
Registrar os dados em nuvem ou cartão SD
Enviar alertas via e-mail ou Telegram

---

## 📄 Licença

Este projeto está sob a licença [MIT License]

---

