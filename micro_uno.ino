
int ledPin = 7; //pin del arduino del buzzer y el led

char* letters[] = {
".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", //A-I
".--", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", //J-R
"...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."       //S-Z
};

char* numbers [ ] = {"-----", ".----", " ..---", "...--", "....-", ".....", "-....", "--...", "---..", "----." }; //0-9
int dotDelay = 200;     //tiempo estandar de espera del codigo morse, 200ms

void setup(){
pinMode(ledPin, OUTPUT);
Serial.begin(9600);
}

void loop(){

char ch;

if (Serial.available()) // consulta el puerto serie
 {
ch = Serial.read(); // leer la letra del puerto
if (ch >= 'a' && ch <= 'z')
{
flashSequence(letters[ch - 'a']);
}
else if (ch >= 'A' && ch <= 'Z')
{
flashSequence(letters[ch - 'A']);
}
else if (ch >= '0' && ch <= '9')
{
flashSequence(numbers[ch - '0']);
}
else if (ch == ' ')
{
delay(dotDelay * 4); // espacio entre palabras
}
 }

}
void flashSequence(char* sequence)
{
int i = 0;
while (sequence[i] != NULL)
{
flashDotOrDash(sequence[i]);
i++;
}
delay(dotDelay * 3 ) ; // espacio entre letras
}
void flashDotOrDash(char dotOrDash)
{
digitalWrite(ledPin, HIGH);
if (dotOrDash == '.')
{
delay(dotDelay);
}
else // quiza es una -
{
delay(dotDelay * 3 ) ;
}
digitalWrite(ledPin, LOW);
delay(dotDelay); // espacio entre destellos
}
