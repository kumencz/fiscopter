
void draw()  { 
  /*newXmag = mouseX/float(width) * TWO_PI;
  newYmag = mouseY/float(height) * TWO_PI;
  
  float diff = xmag-newXmag;
  if (abs(diff) >  0.01) { 
    xmag -= diff/4.0; 
  }
  
  diff = ymag-newYmag;
  if (abs(diff) >  0.01) { 
    ymag -= diff/4.0; 
  }
  input_3D[1] = ymag;
  input_3D[2] = xmag;
  
  */
  background(25);
  ortho();
  textSize(30);
  fill(100,150,200);
  text("YAW: " + input[1], 30, 30);
  text("ROLL: " + input[2], 30, 55);
  text("PITCH: " + input[3], 30, 80);
  
  pushMatrix(); 
    translate(150, 200, 0); 
    
    rotateX(input_3D[1]+1.5); 
    rotateY(input_3D[2]);
    rotateZ(input_3D[3]);

    scale(100);
    draw_quad(); 
  popMatrix();
  
  pushMatrix(); 
    fill(0,150,180);
    rect(10,370,352,260);
  popMatrix();
  
  pushMatrix(); 
    translate(11, 630, 0); 
    scale(175);
    draw_meter(input_3D[1],input_3D[2]);
  popMatrix();
  
  pushMatrix(); 
    translate(11, 500, 0); 
    draw_scale();
  popMatrix();
  
  pushMatrix(); 
    translate(380, 500, 0); 
    draw_bars(input_3D[1]*150+200,input_3D[2]*150+200,input_3D[3]*150+200,input_3D[4]);
  popMatrix();
  
  delay(50);
} 
