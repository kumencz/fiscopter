import processing.serial.*;
Serial myPort;        // The serial port

float input[] = new float [4];
float select[] = new float [4];

int min_input =  -90;
int max_input =  90;

int min_output =  0;
int max_output =  3;

float xmag, ymag = 0;
float newXmag, newYmag = 0; 
 
int u, i;
void setup()  { 
  size(640, 360, P3D); 
  noStroke(); 
  colorMode(RGB, 1);
  myPort = new Serial(this, Serial.list()[0], 115200); 
  myPort.bufferUntil('\n');
} 
 
void draw()  { 
  background(0.5);
  
 // pushMatrix(); 
  translate(width/2, height/2, -30); 
  
  
 
   
  
  
  println(input[3]);
  println(input[2]);
  /*scale(60);
  beginShape(QUADS);

  fill(0, 1, 1); vertex(-1,  1,  1);
  fill(1, 1, 1); vertex( 1,  1,  1);
  fill(1, 0, 1); vertex( 1, -1,  1);
  fill(0, 0, 1); vertex(-1, -1,  1);

  fill(1, 1, 1); vertex( 1,  1,  1);
  fill(1, 1, 0); vertex( 1,  1, -1);
  fill(1, 0, 0); vertex( 1, -1, -1);
  fill(1, 0, 1); vertex( 1, -1,  1);

  fill(1, 1, 0); vertex( 1,  1, -1);
  fill(0, 1, 0); vertex(-1,  1, -1);
  fill(0, 0, 0); vertex(-1, -1, -1);
  fill(1, 0, 0); vertex( 1, -1, -1);

  fill(0, 1, 0); vertex(-1,  1, -1);
  fill(0, 1, 1); vertex(-1,  1,  1);
  fill(0, 0, 1); vertex(-1, -1,  1);
  fill(0, 0, 0); vertex(-1, -1, -1);

  fill(0, 1, 0); vertex(-1,  1, -1);
  fill(1, 1, 0); vertex( 1,  1, -1);
  fill(1, 1, 1); vertex( 1,  1,  1);
  fill(0, 1, 1); vertex(-1,  1,  1);

  fill(0, 0, 0); vertex(-1, -1, -1);
  fill(1, 0, 0); vertex( 1, -1, -1);
  fill(1, 0, 1); vertex( 1, -1,  1);
  fill(0, 0, 1); vertex(-1, -1,  1);

  endShape();
  
  popMatrix(); */
  pushMatrix();
fill(255, 0, 0);
rotateX(input[2]); 
  rotateY(input[1]);
  rotateZ(input[3]); 
box(30, 200, 30);
popMatrix();

} 

void serialEvent (Serial myPort) {
  // get the ASCII string:
  String inString = myPort.readStringUntil('\n');
 // println(inString);
  select = float(split(inString,"|"));
  
  
  input[1] = select[1];
  input[2] = select[2];
  input[3] = select[9];

  
  
  if (!Float.isNaN(input[1])) 
  {
    for(i = 1; i < input.length ; i++)
    {
      input[i] = map(input[i], min_input, max_input, min_output, max_output); //map to the screen height.
    }
  }
}
