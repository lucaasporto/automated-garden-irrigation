// Parâmetros Blynk
#define BLYNK_AUTH_TOKEN "SEU_AUTH_TOKEN"
#define BLYNK_TEMPLATE_ID "SEU_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "Seu_Template_Name"

#define BLYNK_PRINT Serial

// Bibliotecas
#include <DHT.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Rede Wi-Fi
char ssid[] = "SUA_REDE_WIFI";
char auth[] = BLYNK_AUTH_TOKEN;
char pass[] = "SUA_SENHA_WIFI";

// Pinos de dados
#define dado_rele D7
#define dado_umidade_solo A0

// Variáveis auxiliares
bool botao_bomba = false;
bool modo_automatico = false;

int limite_umidade_solo = 50;
int umidade_solo = 0;

BlynkTimer timer;

// Sensor DHT11 no pino D5
DHT dht(D5, DHT11);

void setup()
{
  pinMode(dado_rele, OUTPUT);
  pinMode(dado_umidade_solo, INPUT);

  // Relé ativo em LOW:
  // LOW  -> bomba ligada
  // HIGH -> bomba desligada
  digitalWrite(dado_rele, HIGH);

  dht.begin();

  Serial.begin(9600);
  Serial.println("Setup iniciado");

  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);

  // Timers
  timer.setInterval(1000L, ler_mapear_e_enviar_dado_umidade_solo);
  timer.setInterval(1000L, ler_e_enviar_dados_DHT);
  timer.setInterval(1000L, controlar_bomba_de_agua);
}

// Sincronização ao conectar no Blynk
BLYNK_CONNECTED()
{
  Blynk.syncVirtual(V1);  // Controle manual da bomba
  Blynk.syncVirtual(V11); // Modo automático
  Blynk.syncVirtual(V8);  // Limite de umidade

}

// Controle do modo automático
BLYNK_WRITE(V11)
{
  modo_automatico = param.asInt();
}

// Controle do limite de umidade
BLYNK_WRITE(V8)
{
  limite_umidade_solo = param.asInt();
}

// Controle manual da bomba
BLYNK_WRITE(V1)
{
  botao_bomba = param.asInt();
}

// Leitura e envio da umidade do solo
void ler_mapear_e_enviar_dado_umidade_solo()
{
  int valor = analogRead(dado_umidade_solo);

  if(valor >= 1023)
    umidade_solo = 0;

  else
    umidade_solo = map(valor, 0, 1023, 100, 0);

  // Garante que fique entre 0 e 100%
  umidade_solo = constrain(umidade_solo, 0, 100);

  Blynk.virtualWrite(V0, umidade_solo);
}

// Leitura do DHT11
void ler_e_enviar_dados_DHT()
{
  float umidade_ar = dht.readHumidity();
  float temperatura = dht.readTemperature();

  if(isnan(umidade_ar) || isnan(temperatura))
  {
    Serial.println("Falha na leitura do sensor DHT!");
    return;
  }

  Blynk.virtualWrite(V5, umidade_ar);
  Blynk.virtualWrite(V6, temperatura);
}

// Controle da bomba
void controlar_bomba_de_agua()
{
  if(modo_automatico)
  {
    // Solo seco -> liga bomba
    if(umidade_solo < limite_umidade_solo)
    {
      digitalWrite(dado_rele, LOW);
      Blynk.virtualWrite(V4, 1);
    }

    // Solo úmido + histerese -> desliga bomba
    else if(umidade_solo > limite_umidade_solo + 5)
    {
      digitalWrite(dado_rele, HIGH);
      Blynk.virtualWrite(V4, 0);
    }
  }

  // Controle manual
  else
  {
    if(botao_bomba)
    {
      digitalWrite(dado_rele, LOW);
      Blynk.virtualWrite(V4, 1);
    }

    else
    {
      digitalWrite(dado_rele, HIGH);
      Blynk.virtualWrite(V4, 0);
    }
  }
}

void loop()
{
  Blynk.run();
  timer.run();
}
