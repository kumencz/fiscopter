import processing.serial.*;
Serial myPort;        // The serial port

float input[] = new float [4];
float select[] = new float [10];

int min_input =  -90;
int max_input =  90;

float min_output =  1.5;
float max_output =  -1.5;

float xmag, ymag = 0;
float newXmag, newYmag = 0;

int u, i;
void setup()  {
  size(1280, 720, P3D);
  noStroke();
  colorMode(RGB, 1);
  myPort = new Serial(this, Serial.list()[0], 115200);
  myPort.bufferUntil('\n');
  textFont(createFont("Georgia", 36));
}

void draw()  {
  background(0.5);
  ortho();
  textSize(14);
  text("YAW: " + select[1], 50, 15);
  text("ROLL: " + select[2], 50, 35);
  text("PITCH: " + select[3], 50, 55);

  pushMatrix();
  translate(100, 100, 0);

  rotateX(input[1]+1.5);
  rotateY(input[2]);
  rotateZ(input[3]);
  //rotateZ(input[3]);


 // translate(width/2, height/2, -30);



  scale(80);
  beginShape(QUADS);


//======================================= + config start
  /*

  vertex(-0.1, 0.1, -0.05);
  vertex(-0.1, 1, -0.05);
  vertex(0.1, 1, -0.05);
  vertex(0.1, 0.1, -0.05);
  vertex(1, 0.1, -0.05);
  vertex(1, -0.1, -0.05);
  vertex(0.1, -0.1, -0.05);
  vertex(-0.1, 0.1, -0.05);//1/2

  vertex(0.1, -0.1, -0.05);//2/2
  vertex(0.1, -1, -0.05);
  vertex(-0.1, -1, -0.05);
  vertex(-0.1, -0.1, -0.05);
  vertex(-1, -0.1, -0.05);
  vertex(-1, 0.1, -0.05);
  vertex(-0.1, 0.1, -0.05);
  vertex(0.1, -0.1, -0.05);

   vertex(-0.1, 0.1, 0.05);
  vertex(-0.1, 1, 0.05);
  vertex(0.1, 1, 0.05);
  vertex(0.1, 0.1, 0.05);
  vertex(1, 0.1, 0.05);
  vertex(1, -0.1, 0.05);
  vertex(0.1, -0.1, 0.05);
  vertex(-0.1, 0.1, 0.05);//1/2

  vertex(0.1, -0.1, 0.05);//2/2
  vertex(0.1, -1, 0.05);
  vertex(-0.1, -1, 0.05);
  vertex(-0.1, -0.1, 0.05);
  vertex(-1, -0.1, 0.05);
  vertex(-1, 0.1, 0.05);
  vertex(-0.1, 0.1, 0.05);
  vertex(0.1, -0.1, 0.05);
  */
//======================================= + config end

//======================================= X config start

  fill(0, 0, 0);
  vertex(0, 0.1, -0.05);
  vertex(0.9, 1, -0.05);
  vertex(1, 0.9, -0.05);
  vertex(0.1, 0, -0.05);
  vertex(1, -0.9, -0.05);
  vertex(0.9, -1, -0.05);
  vertex(0, -0.1, -0.05);
  vertex(0, 0.1, -0.05); // 1/4

  fill(1, 0, 0);
  vertex(0, -0.1, -0.05);
  vertex(-0.9, -1, -0.05);
  vertex(-1, -0.9, -0.05);
  vertex(-0.1, 0, -0.05);
  vertex(-1, 0.9, -0.05);
  vertex(-0.9, 1, -0.05);
  vertex(0, 0.1, -0.05);
  vertex(0, -0.1, -0.05); // 2/4

  fill(0, 0, 0);
  vertex(0, 0.1, 0.05);
  vertex(0.9, 1, 0.05);
  vertex(1, 0.9, 0.05);
  vertex(0.1, 0, 0.05);
  vertex(1, -0.9, 0.05);
  vertex(0.9, -1, 0.05);
  vertex(0, -0.1, 0.05);
  vertex(0, 0.1, 0.05); // 3/4

  fill(1, 0, 0);
  vertex(0, -0.1, 0.05);
  vertex(-0.9, -1, 0.05);
  vertex(-1, -0.9, 0.05);
  vertex(-0.1, 0, 0.05);
  vertex(-1, 0.9, 0.05);
  vertex(-0.9, 1, 0.05);
  vertex(0, 0.1, 0.05);
  vertex(0, -0.1, 0.05); // 4/4

endShape();

//------------plast
  beginShape(QUADS);
  fill(0, 0, 0);
  vertex(0, 0.1, -0.05);
  vertex(0, 0.1, 0.05);
  vertex(0.9, 1, 0.05);
  vertex(0.9, 1, -0.05);
  vertex(0, 0.1, -0.05);
  endShape();
  beginShape(QUADS);
  fill(0, 0, 0);
  vertex(1, 0.9, -0.05);
  vertex(1, 0.9, 0.05);
  vertex(0.1, 0, 0.05);
  vertex(0.1, 0, -0.05);
  vertex(1, 0.9, -0.05);
  endShape();
  beginShape(QUADS);
  fill(0, 0, 0);
  vertex(0.9, 1, -0.05);
  vertex(0.9, 1, 0.05);
  vertex(1, 0.9, 0.05);
  vertex(1, 0.9, -0.05);
  vertex(0.9, 1, -0.05);
  endShape();


  beginShape(QUADS);
  fill(1, 0, 0);
  vertex(0, -0.1, -0.05);
  vertex(0, -0.1, 0.05);
  vertex(-0.9, -1, 0.05);
  vertex(-0.9, -1, -0.05);
  vertex(0, -0.1, -0.05);
  endShape();
  beginShape(QUADS);
  fill(1, 0, 0);
  vertex(-1, -0.9, -0.05);
  vertex(-1, -0.9, 0.05);
  vertex(-0.1, 0, 0.05);
  vertex(-0.1, 0, -0.05);
  vertex(-1, -0.9, -0.05);
  endShape();
  beginShape(QUADS);
  fill(1, 0, 0);
  vertex(-0.9, -1, -0.05);
  vertex(-0.9, -1, 0.05);
  vertex(-1, -0.9, 0.05);
  vertex(-1, -0.9, -0.05);
  vertex(-0.9, -1, -0.05);
  endShape();


  beginShape(QUADS);
  fill(1, 0, 0);
  vertex(0, 0.1, -0.05);
  vertex(0, 0.1, 0.05);
  vertex(-0.9, 1, 0.05);
  vertex(-0.9, 1, -0.05);
  vertex(0, 0.1, -0.05);
  endShape();
  beginShape(QUADS);
  fill(1, 0, 0);
  vertex(-1, 0.9, -0.05);
  vertex(-1, 0.9, 0.05);
  vertex(-0.1, 0, 0.05);
  vertex(-0.1, 0, -0.05);
  vertex(-1, 0.9, -0.05);
  endShape();
  beginShape(QUADS);
  fill(1, 0, 0);
  vertex(-0.9, 1, -0.05);
  vertex(-0.9, 1, 0.05);
  vertex(-1, 0.9, 0.05);
  vertex(-1, 0.9, -0.05);
  vertex(-0.9, 1, -0.05);
  endShape();



    beginShape(QUADS);
  fill(0, 0, 0);
  vertex(0, -0.1, -0.05);
  vertex(0, -0.1, 0.05);
  vertex(0.9, -1, 0.05);
  vertex(0.9, -1, -0.05);
  vertex(0, -0.1, -0.05);
  endShape();
  beginShape(QUADS);
  fill(0, 0, 0);
  vertex(1, -0.9, -0.05);
  vertex(1, -0.9, 0.05);
  vertex(0.1, 0, 0.05);
  vertex(0.1, 0, -0.05);
  vertex(-1, -0.9, -0.05);
  endShape();
  beginShape(QUADS);
  fill(0, 0, 0);
  vertex(0.9, -1, -0.05);
  vertex(0.9, -1, 0.05);
  vertex(1, -0.9, 0.05);
  vertex(1, -0.9, -0.05);
  vertex(0.9, -1, -0.05);
  endShape();


//======================================= + config end

popMatrix();


}

void serialEvent (Serial myPort) {
  // get the ASCII string:
  String inString = myPort.readStringUntil('\n');
 // println(inString);
  select = float(split(inString,"|"));


  input[1] = select[1];
  input[2] = select[2];
  input[3] = select[3];



  if (!Float.isNaN(input[1]))
  {
    for(i = 1; i < input.length ; i++)
    {
      input[i] = map(input[i], min_input, max_input, min_output, max_output); //map to the screen height.
    }
  }
}
