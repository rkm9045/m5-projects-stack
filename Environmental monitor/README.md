----ainda em elaboração. É necessário colocar os links e refinar o texto.----
--colocar mais fotos dos equipamentos --

Como baixar as placas no board manager arduino IDE:
https://static-cdn.m5stack.com/resource/arduino/package_m5stack_index.json


Building a Smart Environmental Monitoring System with M5StickC Plus and M5Stack ENV IV Module

The M5StickC Plus, with its compact design and powerful capabilities, is a versatile IoT development kit. When paired with the M5Stack ENV IV module, it becomes a formidable tool for creating an advanced environmental monitoring system. This article will guide you through building a smart environmental monitoring system that can track temperature, humidity, atmospheric pressure, and CO2 levels.

Components Needed
M5StickC Plus
M5Stack ENV IV Module
Connecting cables
A cloud service for data logging (optional)
Step 1: Setting Up the Hardware
1.1 Connecting the M5Stack ENV IV Module

The M5Stack ENV IV module is designed to be easily integrated with the M5StickC Plus. It includes sensors for temperature, humidity, atmospheric pressure, and CO2 levels. Connect the ENV IV module to the M5StickC Plus using the provided cables. The module uses I2C communication, so ensure the connections align with the I2C pins on the M5StickC Plus.

Step 2: Programming the M5StickC Plus
2.1 Installing Required Libraries

Before you start coding, you need to install the necessary libraries for the M5StickC Plus and the ENV IV module. Open the Arduino IDE and install the following libraries:

M5StickC library
ENV IV library (usually part of the M5Stack library bundle)
2.2 Writing the Code

Here’s a sample code to get you started with reading data from the ENV IV module and displaying it on the M5StickC Plus screen:


#include <M5StickC.h>
#include <M5_ENV.h>

SHT3X sht30;
QMP6988 qmp6988;
SGP30 sgp30;

void setup() {
  M5.begin();
  M5.Lcd.setRotation(3);
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setTextSize(2);

  Wire.begin();
  if (!sht30.begin(0x44)) {
    M5.Lcd.println("SHT30 Error");
  }
  if (!qmp6988.init()) {
    M5.Lcd.println("QMP6988 Error");
  }
  if (!sgp30.begin()) {
    M5.Lcd.println("SGP30 Error");
  }
}

void loop() {
  float temp = sht30.getTemperature();
  float hum = sht30.getHumidity();
  float pres = qmp6988.calcPressure();
  uint16_t co2 = sgp30.getCO2();
  uint16_t tvoc = sgp30.getTVOC();

  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setCursor(0, 10);
  M5.Lcd.printf("Temp: %.2f C\n", temp);
  M5.Lcd.printf("Humidity: %.2f %%\n", hum);
  M5.Lcd.printf("Pressure: %.2f hPa\n", pres / 100.0);
  M5.Lcd.printf("CO2: %d ppm\n", co2);
  M5.Lcd.printf("TVOC: %d ppb\n", tvoc);

  delay(2000);
}

By following these steps, you can create a powerful environmental monitoring system using the M5StickC Plus and the M5Stack ENV IV module. This system can provide valuable insights into your surroundings, whether for personal use, research, or contributing to larger environmental data collection efforts. The portability and versatility of the M5StickC Plus make it an ideal choice for such projects, enabling you to innovate and build smart IoT solutions with ease.

<!---
rkm9045/rkm9045 is a ✨ special ✨ repository because its `README.md` (this file) appears on your GitHub profile.
You can click the Preview link to take a look at your changes.
--->
----- Em Português: -----

## Construindo um Sistema de Monitoramento Ambiental Inteligente com M5StickC Plus e Módulo M5Stack ENV IV

O M5StickC Plus, com seu design compacto e capacidades poderosas, é um kit de desenvolvimento IoT versátil. Quando combinado com o módulo M5Stack ENV IV, torna-se uma ferramenta formidável para criar um sistema avançado de monitoramento ambiental. Este artigo guiará você na construção de um sistema de monitoramento ambiental inteligente que pode rastrear temperatura, umidade, pressão atmosférica e níveis de CO2.

### Componentes Necessários
- M5StickC Plus
- Módulo M5Stack ENV IV
- Cabos de conexão
- Um serviço de nuvem para registro de dados (opcional)

### Passo 1: Configurando o Hardware

#### 1.1 Conectando o Módulo M5Stack ENV IV
O módulo M5Stack ENV IV é projetado para ser facilmente integrado com o M5StickC Plus. Ele inclui sensores para temperatura, umidade, pressão atmosférica e níveis de CO2. Conecte o módulo ENV IV ao M5StickC Plus usando os cabos fornecidos. O módulo usa comunicação I2C, então certifique-se de que as conexões estejam alinhadas com os pinos I2C no M5StickC Plus.

### Passo 2: Programando o M5StickC Plus

#### 2.1 Instalando as Bibliotecas Necessárias
Antes de começar a programar, você precisa instalar as bibliotecas necessárias para o M5StickC Plus e o módulo ENV IV. Abra o Arduino IDE e instale as seguintes bibliotecas:
- Biblioteca M5StickC
- Biblioteca ENV IV (geralmente parte do pacote de bibliotecas M5Stack)

#### 2.2 Escrevendo o Código
Aqui está um exemplo de código para começar a ler dados do módulo ENV IV e exibi-los na tela do M5StickC Plus:

```cpp
#include <M5StickC.h>
#include <M5_ENV.h>

SHT3X sht30;
QMP6988 qmp6988;
SGP30 sgp30;

void setup() {
  M5.begin();
  M5.Lcd.setRotation(3);
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setTextSize(2);

  Wire.begin();
  if (!sht30.begin(0x44)) {
    M5.Lcd.println("Erro SHT30");
  }
  if (!qmp6988.init()) {
    M5.Lcd.println("Erro QMP6988");
  }
  if (!sgp30.begin()) {
    M5.Lcd.println("Erro SGP30");
  }
}

void loop() {
  float temp = sht30.getTemperature();
  float hum = sht30.getHumidity();
  float pres = qmp6988.calcPressure();
  uint16_t co2 = sgp30.getCO2();
  uint16_t tvoc = sgp30.getTVOC();

  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setCursor(0, 10);
  M5.Lcd.printf("Temp: %.2f C\n", temp);
  M5.Lcd.printf("Umidade: %.2f %%\n", hum);
  M5.Lcd.printf("Pressão: %.2f hPa\n", pres / 100.0);
  M5.Lcd.printf("CO2: %d ppm\n", co2);
  M5.Lcd.printf("TVOC: %d ppb\n", tvoc);

  delay(2000);
}
```

Este código inicializa os sensores e lê os dados deles. Os dados são então exibidos na tela do M5StickC Plus.

### Passo 3: Opcional - Enviando Dados para a Nuvem
Para tornar seu sistema de monitoramento ambiental ainda mais inteligente, você pode enviar os dados coletados para um serviço de nuvem como ThingSpeak ou Adafruit IO. Isso permite o monitoramento remoto e a análise dos dados.

#### 3.1 Configurando o Serviço de Nuvem
Cadastre-se em uma conta de serviço de nuvem e crie um novo canal de dados. Obtenha a chave API para seu canal.

#### 3.2 Modificando o Código para Envio à Nuvem
Adicione o seguinte código ao seu programa existente para enviar dados à nuvem:

```cpp
#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "sua_SSID";
const char* password = "sua_SENHA";
const char* serverName = "http://api.thingspeak.com/update";
String apiKey = "sua_CHAVE_API";

void setup() {
  // Código de configuração existente...
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    M5.Lcd.println("Conectando ao WiFi...");
  }
  M5.Lcd.println("Conectado ao WiFi");
}

void uploadData(float temp, float hum, float pres, uint16_t co2, uint16_t tvoc) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String url = serverName + "?api_key=" + apiKey +
                 "&field1=" + String(temp) +
                 "&field2=" + String(hum) +
                 "&field3=" + String(pres / 100.0) +
                 "&field4=" + String(co2) +
                 "&field5=" + String(tvoc);
    http.begin(url);
    int httpCode = http.GET();
    if (httpCode > 0) {
      String payload = http.getString();
      M5.Lcd.println("Dados enviados: " + payload);
    } else {
      M5.Lcd.println("Erro na requisição HTTP");
    }
    http.end();
  }
}

void loop() {
  // Código do loop existente...
  uploadData(temp, hum, pres, co2, tvoc);
  delay(2000);
}
```

Este código conecta o M5StickC Plus à sua rede WiFi e envia os dados dos sensores para o serviço de nuvem.

### Conclusão
Seguindo estes passos, você pode criar um poderoso sistema de monitoramento ambiental usando o M5StickC Plus e o módulo M5Stack ENV IV. Este sistema pode fornecer informações valiosas sobre seu ambiente, seja para uso pessoal, pesquisa ou para contribuir com esforços maiores de coleta de dados ambientais. A portabilidade e versatilidade do M5StickC Plus o tornam uma escolha ideal para tais projetos, permitindo que você inove e construa soluções IoT inteligentes com facilidade.
