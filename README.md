Projeto de Semáforo com Raspberry Pi Pico W
Este README detalha o projeto de um semáforo utilizando o Raspberry Pi Pico W, implementando a função add_repeating_timer_ms() do Pico SDK para controlar a temporização dos sinais.

Componentes
Microcontrolador: Raspberry Pi Pico W
LEDs: 3 LEDs (vermelho, amarelo e verde)
Resistores: 3 resistores de 330 Ω
Ferramenta de Simulação: Wokwi 
Descrição do Projeto
O semáforo simula o comportamento de um semáforo real, alternando entre as cores vermelha, amarela e verde com um intervalo de 3 segundos para cada alteração de sinal. O fluxo de operação é definido no fluxograma da Figura 1.

Implementação
Acionamento dos LEDs:
O semáforo inicia com o LED vermelho aceso.
Após 3 segundos, o LED vermelho é apagado e o LED amarelo é aceso.
Após mais 3 segundos, o LED amarelo é apagado e o LED verde é aceso.
Após 3 segundos, o LED verde é apagado e o ciclo se repete, reiniciando com o LED vermelho.
Temporização:

A função add_repeating_timer_ms() é utilizada para criar um temporizador com período de 3000 ms (3 segundos).
A função de callback do temporizador é responsável por alterar o estado dos LEDs a cada intervalo de 3 segundos.
Função de Callback:

A função de callback é executada a cada 3 segundos e implementa a lógica de mudança de estado dos LEDs, seguindo a sequência vermelho → amarelo → verde.
