# IoT-ESP32-S3-robo-espacial

# Objetivo da Etapa
Programar e simular o controle remoto de um robô móvel utilizando o microcontrolador ESP32-S3 no Wokwi. O sistema realiza a leitura de um joystick de dois eixos para envio de comandos de movimentação, possui um botão de desligamento remoto de emergência e LEDs para sinalização do status de comunicação.

# Lista de Componentes do Circuito

| Componente            | Quantidade  | Pino no ESP32-S3                | Função                                           |
| --------------------- | ----------- | ------------------------------- | ------------------------------------------------ |
| ESP32-S3              | 1           | -                               | Microcontrolador do controle                     |
| Joystick Analógico    | 1           | X -> GPIO 4 / Y -> GPIO 5       | Direcionamento (Frente, Trás, Esquerda, Direita) |
| Botão                 | 1           | GPIO 12                         | Botão de desligar/ligar controle remoto          |
| LED Verde             | 1           | GPIO 2                          | Indica controle ligado e conectado               |
| LED Vermelho          | 1           | GPIO 1                          | Indica controle desligado e desconectado         |
| Resistores (220 Ohms) | 2           | -                               | Proteção dos LEDs                                |

# Como Rodar no Wokwi

1. Acesse o projeto no simulador: https://wokwi.com/projects/477143979700745217
2. Clique no botão Play para iniciar a simulação).
3. Abra o monitor serial para visualizar os comandos.
4. Mova o Joystick para ver as leituras dos eixos X/Y e os comandos de direção (Frente, Trás, Esquerda, Direita).
5. Pressione o botão para alternar o estado do robô entre: Desligado - LED Vermelho acende, LED Verde apaga e o terminal exibe "Status: DESLIGADO" e Ligado - LED Verde acende, LED Vermelho apaga e a transmissão de dados é retomada.
