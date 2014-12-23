/*  This Arduino module is used to control a Spark Core which in turn controls a HM-10 module
to set up a star network formed by multiple slave HM10 modules.

    Written by Hoang Nguyen
*/


bool DEBUG = true;
void setup()
{
	Serial1.begin(9600); // Initialize UART func of the Core for communicating with HM-10 master module

	Spark.function("control", HM10_Control);

	// Any set-up needed for the master HM-10?
    // Reset master HM-10 to factory setting so it doesn't connect to slave modules incidentally
    Serial1.print("AT+RENEW");
    delay(2000);    // Wait for 2 secs for the module to stablize
    Serial1.print("AT+ROLE1");  // Set the module as master, default after factory reset is ROLE0
    delay(100);
    Serial1.print("AT+IMME1");  // After restart, the module just sit there waiting for AT+START or AT+CON commands
    delay(100);
    Serial1.print("AT+NOTI1");
    delay(100);

    if (DEBUG) {
        delay(5000);
        Serial1.print("AT+CONB4994C715302");
        delay(5000);
        Serial1.print("AT"); // Will disconnect from slave with this command 
    }
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