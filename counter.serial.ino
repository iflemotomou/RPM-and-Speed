int ledPin = 13; // ενσωματωμένο LED
int switchPin =2; // είσοδος από έναν αισθητήρα
int val = 0; // μεταβλητή που διαβάζει την είσοδο
int counter = 0;
int currentState = 0;
int previousState = 0;

void setup() {
pinMode(ledPin, OUTPUT); // δήλωση της LED ως έξοδος
pinMode(switchPin, INPUT); // δήλωση του αισθητήρα ως είσοδος
Serial.begin(9600);
}

void loop(){
val = digitalRead(switchPin); // διαβάσει την είσοδο
if (val == HIGH) { // έλεγχος για λογικό HIGH
digitalWrite(ledPin, HIGH); // ανάβει το LED
currentState = 1;
}
else {
digitalWrite(ledPin, LOW); // σβήνει το LED
currentState = 0;
}
if(currentState != previousState){
if(currentState == 1){
counter = counter + 1;
Serial.print("Μετρητής: ");
Serial.println(counter);
}
}
previousState = currentState;
delay(10);
}
