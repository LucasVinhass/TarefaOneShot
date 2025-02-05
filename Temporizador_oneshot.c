#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"

#define led_pin_verde 11     // Define o pino do LED verde.
#define led_pin_azul 12     // Define o pino do LED azul
#define led_pin_vermelho 13    // Define o pino do LED vermelho
#define BUTTON_PIN 5    // Define o pino GPIO 5 para ler o estado do botão.

int count = 0;  // Somado ao pino base (led_pin_verde) indica qual led deve ser desligado.

bool leds_active = false;    // Indica se o LED está atualmente aceso, evitando várias ativações.


// Função de callback para desligar os LEDs um por um a cada 3 segundos.
int64_t turn_off_callback(alarm_id_t id, void *user_data) {
    // Desliga o LED atual usando led_pin_verde como base.
    // Com count=0 desliga o LED verde, count=1 desliga o LED azul e count=2 desliga o LED vermelho.
    gpio_put(led_pin_verde + count, false);

    count++;  // Avança para o próximo LED

    // Se ainda há LEDs para desligar, reagenda o alarme.
    if(count < 3) {
        add_alarm_in_ms(3000, turn_off_callback, NULL, false);
    } else {
        // Todos os LEDs foram desligados, reseta a contagem e sinaliza que a rotina acabou.
        count = 0;
        leds_active = false;
    }
    return 0;  
}

int main()
{
     // Iniciação todos os pinos
    stdio_init_all();

    // Configura os pinos dos LEDs
    gpio_init(led_pin_vermelho);                // Inicializa o pino vermelho
    gpio_init(led_pin_verde);                // Inicializa o pino verde
    gpio_init(led_pin_azul);                // Inicializa o pino azul
    gpio_set_dir(led_pin_vermelho, GPIO_OUT);   // Define o pino vermelho como saída
    gpio_set_dir(led_pin_verde, GPIO_OUT);   // Define o pino verde como saída
    gpio_set_dir(led_pin_azul, GPIO_OUT);   // Define o pino azul como saída
    
    // Configura o pino do botão
    gpio_init(BUTTON_PIN);              // Inicializa o pino do botão      
    gpio_set_dir(BUTTON_PIN, GPIO_IN);  // Define o botão como entrada
    gpio_pull_up(BUTTON_PIN);           // Habilita o resistor pull-up interno para o pino do botão.


    while (true) {
    
    // Verifica se o botão foi pressionado e se o LED não está ativo.
    if (gpio_get(BUTTON_PIN) == 0 && !leds_active) {
            
      sleep_ms(50);// Atraso para debounce
 
        // Verifica novamente o estado do botão após o debounce.
        if (gpio_get(BUTTON_PIN) == 0) {
                          
          // Liga o LED configurado.
          gpio_put(led_pin_azul, 1);
          gpio_put(led_pin_verde, 1);
          gpio_put(led_pin_vermelho, 1);
            
          leds_active = true;  
           
          // Agenda um alarme para desligar cada LED após 3 segundo após o último ter sido apagado
          add_alarm_in_ms(3000, turn_off_callback, NULL, false);
          
          
        }
      }

        sleep_ms(10);
    }

    return 0;
}
