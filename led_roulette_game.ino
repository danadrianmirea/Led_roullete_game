#define LED_1 13
#define LED_2 12
#define LED_3 10
#define LED_4 8
#define LED_5 9
#define LED_6 11
#define BUTTON 2
#define BUZZER 7

#define WINNER LED LED_3
#define BUZZER_TIME 200
#define LED_CANT 6
int leds[LED_CANT] = {LED_1, LED_2, LED_3, LED_4, LED_5, LED_6};

int time_on = 1000;
unsigned long turned_on;


void setup() {
  pinMode(BOTON, INPUT_PULLUP);
  for(int i = 0; i < LED_CANT; i++) pinMode(leds[i], OUTPUT);
  pinMode(BUZZER, OUTPUT);


}

void check_button(int on_led){

  if(!digitalRead(BUTTON)){

    if(on_led == WINNER_LED){
      time_on -= 100;
      digitalWrite(BUZZER, HIGH);
      delay(BUZZER_TIME);
      digitalWrite(BUZZER, LOW);
      
    }
    
  }

}

void loop() {

  
  for(int i = 0; i < LED_CANT; i++){

    turned_on = millis();

    while(turned_on + time_on > millis()){
      digitalWrite(leds[i], HIGH);
      check_button(leds[i]);
    } 
    digitalWrite(leds[i], LOW);
    
  }

}
