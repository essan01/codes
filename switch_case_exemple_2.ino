/*
ici je fait un exemple simple de l'utilisation de la fonction switch,elle utilise 3 led (pins 8, 9 et 10) et 2 boutons pin 11 et 12.
l'exemple 2 est la meme chose que l'exemple 1, seulement il ajoute aussi un bouton qui permet de revenir en arriere
*/
int led1 = 8; // premiere led pin 8
int led2 = 9; // deuxieme led pin 9
int led3 = 10;// 3 eme led, pin 10

int bouton = 11;// le bouton, pin 11
int bouton2 = 12;//le deuxieme bouton, il permet de revenir en arriere
int compteur; //ici la variable qui va comptabiliser le nombre d'appui sur le bouton
int etatBouton; //la  variable d'état du bouton
int etatBouton2;//la variable d'etat du bouton 2

int attendre = 250 ;//le delay minimum entre chaque appui sur le bouton (en milisecondes)

void setup() {
  Serial.begin(9600);//on va demander au port serie de communiquer certaines chose donc on dit a l'arduino qu'on va avoir besoin du moniteur serie
pinMode(led1,OUTPUT);//on declare la led1 comme une sortie
pinMode(led2,OUTPUT);//on declare la led2 comme une sortie
pinMode(led3,OUTPUT);//on declare la led3 comme une sortie
pinMode(bouton,INPUT_PULLUP);// on declare le boutton comme une entré pull up (comme un bouton enfaite)
pinMode(bouton2,INPUT_PULLUP);//on declare egalement que le bouton2 est un bouton  
}

void loop() {
etatBouton = digitalRead(bouton);//la variable etat bouton recupere l'etat du bouton
etatBouton2 = digitalRead(bouton2);//la variable etatbouton2 recupere l'etat du bouton2
if (etatBouton == LOW) { //si le bouton est appuyer alors...
  compteur = compteur+1 ; //on ajoute 1 a la variable compteur
    Serial.println(compteur);
delay(attendre);
}
if (etatBouton2 == LOW) {
  compteur = compteur -1;
  Serial.println(compteur);
delay(attendre);

  }


  switch (compteur){
  case 1: //si elle vaut 1 alors ...
  digitalWrite(led1,HIGH); //on allume led 1
  digitalWrite(led2,LOW);//on eteint led2
  digitalWrite(led3,LOW)  ; //et on eteint aussi led3
  delay(attendre);//on attend le temps definit par la variable attendre
break;
  case 2://si elle vaut 2 alors...
  digitalWrite(led1,LOW); //on eteint led 1
  digitalWrite(led2,HIGH); //on allume led 2
  digitalWrite(led3,LOW)  ; //on eteint led 3
  delay(attendre);//on attend le temps definit par la variable attendre
break;
  case 3://si elle vaut 2 alors...
  digitalWrite(led1,LOW);//on eteint led 1
  digitalWrite(led2,LOW);//on eteint led 2
  digitalWrite(led3,HIGH);//on allume led3

    delay(attendre);//on attend le temps definit par la variable attendre
break;
case 4: 
    compteur = 1; //c'est la derniere case du tableau, la variable compteur est remise a 0
    Serial.print(compteur);
break;
  }
  

}
