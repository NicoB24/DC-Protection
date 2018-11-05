//Se eligen los pines del micro a utilizar
int ADC3=2; // El pin 2 se usa como ADC3.
int ADC2=3; // El pin 3 se usa como ADC2.
int control=1; // El pin 1 se usa como señal para activar/desactivar rele.
int val1=0; // Variable donde se cargara lo leido de ADC3
int val2=0; // Variable donde se cargara lo leido de ADC4
int max_value=19; // Maximo valor que puede tomar la tension entre terminales (5V=1023 => 92mV=19)
int read_value=0; //Variable donde se cargara el valor leido entre terminales

void setup() {
  // Se configuran los pines a utilizar como entradas/salidas
  pinMode(ADC2,INPUT); 
  pinMode(ADC3,INPUT);
  pinMode(control,OUTPUT);
  digitalWrite(control,LOW);  
}

void loop() {
  //Delay inicial
  delay(4000);
  //Se lee el valor de los ADC
  val1=analogRead(ADC2); 
  delay(500);
  val2=analogRead(ADC3);
  delay(500);
  //Comienza la comparacion
  read_value=val1-val2;
  //Si el valor entre los terminales del parlante es mayor a 92mV entonces desconecta la carga, enciende un LED avisando y finaliza la operacion.
  if ((abs(read_value))>max_value){
    digitalWrite(control,HIGH);
    delay(3000);
 }
      
}
