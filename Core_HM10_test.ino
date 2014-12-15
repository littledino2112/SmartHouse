void setup()
{
	Serial1.begin(9600); // Initialize UART func of the Core for communicating with HM-10 master module

	Spark.function("control", HM10_Control);

	// Any set-up needed for the master HM-10?
}

void loop()
{
	
}

int HM10_Control(String command){
    if (command=="1"){
    	// Send AT command: AT+PIO31 to turn attached LED ON
    	Serial1.print("AT+PIO31");
    }
    else if (command=="0"){
    	// Send AT command: AT+PIO30 to turn attached LED OFF
    	Serial1.print("AT+PIO30");
    }
    return 1;
}