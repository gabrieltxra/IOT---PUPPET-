#include <WiFi.h>
#include <WebServer.h>

const char *ssid = "ssid"; // aqui você vai colocar o nome da rede que deseja conectar
const char *password = "password"; // e aqui irá colocar a senha da rede
const int led = 12; // alterar os pinos conforme necessidade
const int led2 = 13; // alterar os pinos conforme necessidade

WebServer server(80);

void setup() {

  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);

  pinMode(led2, OUTPUT);
  digitalWrite(led2, LOW);

  Serial.begin(115200);
  WiFi.begin(ssid, password);

// ATENÇÃO !! pegar o endereço de ip do terminal da IDE e entrar pelo navegador para poder controlar o robô
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando ao WiFi...");
  }
  Serial.println("Conectado com sucesso ao WiFi");

  Serial.print("Endereço IP:");
  Serial.println(WiFi.localIP());

  server.on("/", HTTP_GET, []() {
    String html = "<html><body>";
    html += "<!DOCTYPE html><html><head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">";
    html += "<link rel=\"icon\" href=\"data:,\">";

    html += "<style>html { font-family: Helvetica; display; inline-block; margin: 0px auto; text-align: center;}";
    html += "text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}";
    html += ".body { color: #ffffff; background-color: rgb(27, 26, 26); }";
    html += ".button {background-color: #a52a2a; border: none; padding: 16px 40px; text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}";
    html += ".button2 { background-color: #ffd68f;}</style> </head>";

    html += "<br> <br> <body> <h1>SENAI - IOT - PUPPET</h1>";
    html += "<p>OLHOS</p>";
    html += "<p><a href=\"/ligar/on\"><button class=\"button\">ON</button></a></p>";
    html += "<p><a href=\"/desligar/off\"><button class=\"button button2\">OFF</button></a></p>";
    html += "<p><a href=\"/piscar\"><button class=\"button button2\">PISCAR</button></a></p>";
	  
    html += "<img src=\"https://i.pinimg.com/564x/d1/fe/7e/d1fe7e0090f89e5a0d8e740700be73fb.jpg\" width=\"564\" height=\"564\" align=\"center\"/>";
    html += "</body></html>";
    server.send(200, "text/html", html);
  });

  // liga os olhos
  server.on("/ligar/on", HTTP_GET, []() {
    digitalWrite(led, HIGH);
    digitalWrite(led2, HIGH);
    server.send(200, "text/html", "LED LIGADO");
  });

  // desliga os olhos
  server.on("/desligar/off", HTTP_GET, []() {
    digitalWrite(led, LOW);
    digitalWrite(led2, LOW);
    server.send(200, "text/html", "LED DESLIGADO");
  });

	server.on("/piscar", HTTP_GET, []() {

// o olho vai piscar 20 vezes e após isso irá desligar sozinho ( não precisa desligar pelo botão do site)
	for(int i = 0; i <20; i++){ 
	digitalWrite(led,HIGH);
	digitalWrite(led2,HIGH);
	delay (800);
	digitalWrite(led,LOW);
	digitalWrite(led2,LOW);
	delay (800);
	}

    server.send(200, "text/html", "PISCANDO");
  });


  server.begin();
}

void loop() {
  server.handleClient(); // vai chamar todas as funções do server.on pro loop
}
