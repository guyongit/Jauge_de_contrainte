
	int i;
	int value;
	float V,Vo,Vcal;
	float Sum=0;

void setup()
{
	Serial.begin(9600);
	Serial.println("start");
	
	//Calibration :
	delay(3000);
	Serial.println("Calibration");
	for(i=0;i<50;i++)
	{
		value=analogRead(0);
		V=value*5.00/1023;
		Sum+=V;
		delay(10);
		Vcal=Sum/50;
	}
	
}

void loop()
{	
	float Sum=0;

	for(i=0;i<20;i++)
	{
		value=analogRead(0);
		V=value*5.00/1023;
		Sum+=V;
		delay(10);
	}
	Vo=Sum/20;
	Vo=(Vo-Vcal);
	Vo=Vo/0.20;
	Serial.print("Mesure en Kg:");
	Serial.println(Vo);
	delay(1000);
}