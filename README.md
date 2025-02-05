Projeto de Temporização de LEDs com Botão e Alarme no Raspberry Pi Pico W

Este README detalha o projeto de um sistema de temporização para acionamento de LEDs controlado por um botão (pushbutton) no Raspberry Pi Pico W, utilizando a função add_alarm_in_ms() do Pico SDK.

Componentes

Microcontrolador: Raspberry Pi Pico W

LEDs: 3 LEDs (azul, vermelho e verde)

Resistores: 3 resistores de 330 Ω

Botão: Pushbutton

Ferramenta de Simulação: Wokwi 



Descrição do Projeto

O projeto implementa um sistema de controle de LEDs acionado por um botão. Ao pressionar o botão, os três LEDs acendem simultaneamente. Em seguida, um sistema de temporização, utilizando alarmes, controla o desligamento sequencial dos LEDs, com intervalos de 3 segundos entre cada transição. O botão fica inativo durante o ciclo de temporização, evitando interrupções.

Implementação

Acionamento Inicial:

Ao pressionar o botão, os três LEDs (azul, vermelho e verde) são acesos.
Temporização com Alarmes:

A função add_alarm_in_ms() é utilizada para configurar alarmes com um período de 3000 ms (3 segundos).

Funções de callback são associadas a cada alarme, responsáveis por desligar os LEDs sequencialmente.

Funções de Callback:

A primeira função de callback desliga um dos LEDs após 3 segundos.
A segunda função de callback, agendada após 3 segundos do primeiro alarme, desliga outro LED.
A terceira função de callback, agendada após 3 segundos do segundo alarme, desliga o último LED.
Controle do Botão:

O botão é monitorado para evitar acionamentos durante o ciclo de temporização.
Após o último LED ser desligado, o botão é reativado, permitindo um novo ciclo.
