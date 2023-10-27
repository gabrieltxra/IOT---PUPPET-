# IOT---PUPPET-

Este projeto foi desenvolvido em C++ na IDE do Arduino. Sua principal função é controlar o funcionamento dos olhos de um animatrônico, mas ele pode ser personalizado para realizar diversas outras tarefas. Ele se conecta a uma placa chamada ESP32, que é conhecida por sua capacidade de se conectar a internet, graças a biblioteca WiFi.h que ajuda ( Já vem incluso o WebSever nela), que já está disponível na IDE do Arduino.

Para que a IDE reconheça o ESP32, é importante adicionar o seguinte URL JSON nas configurações/propriedades da IDE: https://dl.espressif.com/dl/package_esp32_index.json.

Lembre-se de que o endereço IP da placa pode mudar sempre que você enviar informações diferentes para ela. Portanto, é necessário abrir o terminal na IDE sempre que precisar realizar testes de depuração e configuração.

O código pode ser aprimorado e personalizado de diversas maneiras. O site é simples, com apenas três botões para interagir com um servidor na internet e enviar comandos para a placa.

O projeto oferece a possibilidade de criar diversas funções com base no código fornecido. já que a função digitalWrite pode ser utilizada para controlar uma variedade de dispositivos, incluindo servo-motores. Embora existam bibliotecas específicas para esse propósito, o digitalWrite pode ser uma solução mais fácil, especialmente para aqueles que desejam evitar a busca por bibliotecas adicionais.

Para tirar o máximo proveito deste projeto, é aconselhável ter algum conhecimento prévio em IoT e eletrônica. Isso facilitará a configuração e personalização do projeto de acordo com suas necessidades específicas. Divirtam-se explorando e experimentando o código !

Não esqueça de instalar a placa ESP32 na IDE ( ESP32 by Espressif Systems ) e escolher a opção ESP32 Dev Module.

# FEITO POR GABRIEL TEIXEIRA