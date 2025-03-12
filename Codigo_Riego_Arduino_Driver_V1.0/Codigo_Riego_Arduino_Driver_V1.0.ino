// Producto de ZACETREX TECHNOLOGIES S.A.C
// Este código se hizo con fin de compartirlo con la comunidad y tiene fines educativos

//Declaramos nuestras variables para el driver
int ENA = 3;
int IN1 = 5;
int IN2 = 6;

void setup() {
Serial.begin(9600);//Configuramos la velocidad
//Declaramos a todos como salida

pinMode(ENA, OUTPUT);
pinMode(IN1, OUTPUT);
pinMode(IN2, OUTPUT);
}

void loop() {
int valor = analogRead(A0);//Leemos el voltaje analógico del pin A0
//Y almacenamos el resultado en nuestra variable "valor"
//Convertiendo el voltaje analógico en un valor digital
//Valor =
if (valor >= 1000){//Si el valor es mayor/igual a 1000
  Serial.println("El sensor esta fuera");//Se mostrará en pantalla
  bomba();//Se ejecutará las funciones que están dentro de bomba
}
else if(valor <1000 && valor >= 600){//Si valor es menor o mayor/igual que 600
  bomba();//Se ejecutará las funciones que están dentro de bomba
  Serial.println("Seco");//Se mostrará en el monitor serial
}
else if(valor < 600 && valor >= 370){//Si valor es menor o mayor/igual que 370
  bombastop();//Se ejecutará las funciones que están dentro de bombastop
  Serial.println("humedo");
}
else if (valor < 370){//Si valor es menor que 370
  Serial.println("Está en agua");//Se mostrará en el monitor serial
  bombastop();//Se ejecutará las funciones que están dentro de bombastop
}
delay(1000);//Damos un tiempo de 1sg
}

void bomba(){//Declaramos un función "bomba" en void (no tiene retorno)
  digitalWrite(IN1,1);//Prendemos IN1
  digitalWrite(IN2,0);//Apagamos IN2
  analogWrite(ENA,100);//Configuramos el pwm
}

void bombastop(){//Declaramos un función "bomba" en void (no tiene retorno)
  digitalWrite(IN1,0);//Apagamos IN1
  digitalWrite(IN2,0);//Apagamos IN2
  analogWrite(ENA,100);//Configuramos el pwm
}
