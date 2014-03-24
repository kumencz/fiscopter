import processing.opengl.*;
import processing.serial.*;
Serial myPort;        // The serial port

import javax.swing.JFrame;
PFrame f;
secondApplet graph;

float input[] = new float [7];
float input_3D[] = new float [7];
float input_graph[] = new float [7];
float select[] = new float [7];

int min_input =  -180;
int max_input =  180;

float min_3D_output =  1.5;
float max_3D_output =  -1.5;

float min_graph_output =  0;
float max_graph_output =  650;

float xmag, ymag = 0;
float newXmag, newYmag = 0; 
 

float[][] numbers = new float[7][1205];
//int [][] line_col = { {0,0,255}, {0,255,0}, {255,0,0}};

int line_width = 1;
int w_width = 1200;
int w_height = 800;

int graph_speed = 5;

int u, i;
String inString;



void setup()  { 
  float xmag, ymag = 0;
  float newXmag, newYmag = 0;
  size(1100, 650, OPENGL); 
  PFrame f = new PFrame();
  colorMode(RGB, 255);
  println(Serial.list());
  //myPort = new Serial(this, "/dev/ttyUSB0", 115200);
  myPort = new Serial(this, "COM5", 115200); 
  myPort.stop() ;
  myPort = new Serial(this, "COM5", 115200); 
  myPort.bufferUntil('\n');
  textFont(loadFont("LiberationSerif-40.vlw"), 40);
} 
public class PFrame extends JFrame {
    public PFrame() {
        setBounds(1500,100,w_width,w_height);
        graph = new secondApplet();
        add(graph);
        graph.init();
        show();
    }
}

public class secondApplet extends PApplet {
    public void setup() {
        size(w_width, w_height);
        background(25);
        noSmooth();
    }
   
}
