uint8_t LED = D7;
void setup() {
    pinMode(LED, OUTPUT);
    digitalWrite(LED, LOW);
    Spark.function("control",LEDcontrol);
}

void loop() {

}

int LEDcontrol(String command){
    if (command=="1"){
        digitalWrite(LED, HIGH);
    }
    else if (command=="0"){
        digitalWrite(LED, LOW);
    }
    return 1;
}