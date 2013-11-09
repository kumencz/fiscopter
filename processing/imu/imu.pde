import processing.serial.*;

Serial myPort;        // The serial port

float input[] = new float [4];
float select[] = new float [4];


int speed = 3;
int min_input = -10;
int max_input = 150;
int line_width = 1;
int w_width = 1200;
int w_height = 800;


int u, i;
float[][] numbers = new float[15][1201];
int [][] line_col = { {0,0,255}, {0,255,0}, {255,0,0}};



void setup () {
  // set the window size:
  size(w_width, w_height);        
  // List all the available serial ports
  println(Serial.list());
  // Check the listed serial ports in your machine
  // and use the correct index number in Serial.list()[].

  myPort = new Serial(this, Serial.list()[0], 115200);  //

  // A serialEvent() is generated when a newline character is received :
  myPort.bufferUntil('\n');
  background(0);      // set inital background:
  noSmooth();
}
void draw () {
  // everything happens in the serialEvent()
}

void serialEvent (Serial myPort) {
  // get the ASCII string:
  String inString = myPort.readStringUntil('\n');
  println(inString);
  select = float(split(inString,"|"));
  
  
  input[1] = select[1];
  input[2] = select[2];
  input[3] = select[3];

  
  
  if (!Float.isNaN(input[1])) {
    for(i = 1; i < input.length ; i++)
    {
      input[i] = map(input[i], min_input, max_input, 0, height); //map to the screen height.
      numbers[i][width/speed -1] = input[i];
     // println( numbers[7][width/speed -1]);
    }
    background(0);
    
    noStroke();
    strokeWeight(line_width);        //stroke wider
    
     
    for(i = 1; i < width -1 ; i ++)
    {
      stroke(255,255,255);
      line(i*speed-1*speed, height - numbers[1][i-1], i*speed, height - numbers[1][i]); 
      
      stroke(0,50,150);
      line(i*speed-1*speed, height - numbers[2][i-1], i*speed, height - numbers[2][i]); 
      
      stroke(255,0,0);
      line(i*speed-1*speed, height - numbers[3][i-1], i*speed, height - numbers[3][i]); 
    }
    
    
    
    for(u = 1; u < 4; u++)
    {
      for(i = 1; i < width; i++)
      {
        numbers[u][i] = numbers[u][i+1];
      }
    }
  }
}
