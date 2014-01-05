import processing.serial.*;
Serial myPort;        // The serial port

import javax.swing.JFrame;
PFrame f;
secondApplet graph;

float input[] = new float [4];
float input_3D[] = new float [4];
float select[] = new float [4];

int min_input =  -90;
int max_input =  90;

float min_3D_output =  1.5;
float max_3D_output =  -1.5;

float min_graph_output =  1.5;
float max_graph_output =  -1.5;

float xmag, ymag = 0;
float newXmag, newYmag = 0; 
 
int u, i;
float[][] numbers = new float[15][1201];
int [][] line_col = { {0,0,255}, {0,255,0}, {255,0,0}};

int line_width = 1;
int w_width = 1200;
int w_height = 800;

int graph_speed = 3;


void setup()  { 
  
  size(1280, 720, P3D); 
  PFrame f = new PFrame();
  noStroke(); 
  colorMode(RGB, 1);
 // myPort = new Serial(this, Serial.list()[0], 115200); 
  //myPort.bufferUntil('\n');
  textFont(createFont("Georgia", 36));
} 
public class PFrame extends JFrame {
    public PFrame() {
        setBounds(100,100,400,300);
        graph = new secondApplet();
        add(graph);
        graph.init();
        show();
    }
}

public class secondApplet extends PApplet {
    public void setup() {
        size(w_width, w_height);
        background(0);
        noSmooth();
    }

    public void draw() {
    }
}
