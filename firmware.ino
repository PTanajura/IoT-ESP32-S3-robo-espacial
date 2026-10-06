// DEFINIÇÃO DOS PINOS DO ESP32-S3
#define PIN_JOYSTICK_HORZ 4  
#define PIN_JOYSTICK_VERT 5  
#define PIN_BTN 12 
#define LED_VERDE 2 
#define LED_VERMELHO 1 

const int ADC_CENTRO = 2048;
const int MARGEM_MORTA = 600;

const int LIMITE_SUP_Y = ADC_CENTRO + MARGEM_MORTA; // ~2648
const int LIMITE_INF_Y = ADC_CENTRO - MARGEM_MORTA; // ~1448
const int LIMITE_SUP_X = ADC_CENTRO + MARGEM_MORTA; // ~2648
const int LIMITE_INF_X = ADC_CENTRO - MARGEM_MORTA; // ~1448

bool roboLigado = true;
String ultimoComando = "";

void setup() {
  Serial.begin(115200);

  pinMode(PIN_BTN, INPUT_PULLUP);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);
  digitalWrite(LED_VERDE, HIGH);
  digitalWrite(LED_VERMELHO, LOW);

  Serial.println("CONTROLE REMOTO INICIALIZADO");
}

void loop() {
  // VERIFICAÇÃO DO ESTADO DO BOTÃO 
  if (digitalRead(PIN_BTN) == LOW) {
    delay(50); 
    if (digitalRead(PIN_BTN) == LOW) {
      if (roboLigado) {
        roboLigado = false;
        
        // Atualiza os LEDs 
        digitalWrite(LED_VERDE, LOW);
        digitalWrite(LED_VERMELHO, HIGH);

        // Feedback no Serial
        Serial.println("Status: Robô DESLIGADO");

        // Loop de espera para soltar o botão antes de continuar
        while (digitalRead(PIN_BTN) == LOW) {
          delay(10);
        }
      } else {
        // Se já estiver desligado, um novo clique religa o controle/robô
        roboLigado = true;
        digitalWrite(LED_VERDE, HIGH);
        digitalWrite(LED_VERMELHO, LOW);

        Serial.println("Status: Robô LIGADO");

        while (digitalRead(PIN_BTN) == LOW) {
          delay(10);
        }
      }
    }
  }

  // PROCESSAMENTO DO JOYSTICK 
  if (roboLigado) {
    int valorX = analogRead(PIN_JOYSTICK_HORZ);
    int valorY = analogRead(PIN_JOYSTICK_VERT);

    String comandoAtual = "PARADO";

    // Determina a direção com base nos limites analógicos
    if (valorY > LIMITE_SUP_Y) {
      comandoAtual = "Frente";
    } 
    else if (valorY < LIMITE_INF_Y) {
      comandoAtual = "Trás";
    } 
    else if (valorX > LIMITE_SUP_X) {
      comandoAtual = "Esquerda";
    } 
    else if (valorX < LIMITE_INF_X) {
      comandoAtual = "Direita";
    }

    // Atualiza a exibição no Serial continuamente
    Serial.print("Status: LIGADO (LED Verde) | Joystick (X:");
    Serial.print(valorX);
    Serial.print(", Y:");
    Serial.print(valorY);
    Serial.print(") | Comando: ");
    Serial.println(comandoAtual);

    ultimoComando = comandoAtual;
  } else {
    // Caso o robô esteja desligado remotamente
    Serial.println("Status: DESLIGADO (LED Vermelho) | Envio suspenso.");
  }

  delay(250); // Taxa de atualização das leituras e logs no Serial
}