void draw_quad()
{
  strokeWeight(0.01);
  stroke(100,100,100);
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
  
  fill(255, 0, 0); 
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
  
  fill(255, 0, 0); 
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
  fill(255, 0, 0);  
  vertex(0, -0.1, -0.05);
  vertex(0, -0.1, 0.05);
  vertex(-0.9, -1, 0.05);
  vertex(-0.9, -1, -0.05);
  vertex(0, -0.1, -0.05);
  endShape();
  beginShape(QUADS);
  fill(255, 0, 0); 
  vertex(-1, -0.9, -0.05);
  vertex(-1, -0.9, 0.05);
  vertex(-0.1, 0, 0.05);
  vertex(-0.1, 0, -0.05);
  vertex(-1, -0.9, -0.05);
  endShape();
  beginShape(QUADS);
  fill(255, 0, 0); 
  vertex(-0.9, -1, -0.05);
  vertex(-0.9, -1, 0.05);
  vertex(-1, -0.9, 0.05);
  vertex(-1, -0.9, -0.05);
  vertex(-0.9, -1, -0.05);
  endShape();
  
  
  beginShape(QUADS);
  fill(255, 0, 0); 
  vertex(0, 0.1, -0.05);
  vertex(0, 0.1, 0.05);
  vertex(-0.9, 1, 0.05);
  vertex(-0.9, 1, -0.05);
  vertex(0, 0.1, -0.05);
  endShape();
  beginShape(QUADS);
  fill(255, 0, 0); 
  vertex(-1, 0.9, -0.05);
  vertex(-1, 0.9, 0.05);
  vertex(-0.1, 0, 0.05);
  vertex(-0.1, 0, -0.05);
  vertex(-1, 0.9, -0.05);
  endShape();
  beginShape(QUADS);
  fill(255, 0, 0); 
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
  

//======================================= X config end
}

void draw_meter(float pitch, float roll)
{
  
  float left = pitch - 0.75 + roll;
  float right = pitch - 0.75 - roll;
  strokeWeight(0.01);
  fill(0,110,0);
  quad(0, 0, 0, left, 2, right, 2, 0);
}

void draw_scale()
{
  stroke(200,20,20);
  strokeWeight(3);
  line(50, 0, 135, 0);
  line(170, 0, 180, 0);
  line(215, 0, 300, 0);
  
  line(135, 20, 215, 20);
  
  stroke(200);
  
  
  
  line(120, 120, 230, 120);
  line(140, 105, 210, 105);
  line(120, 90, 230, 90);
  line(140, 75, 210, 75);
  line(120, 60, 230, 60);
  line(140, 45, 210, 45);
  line(120, 30, 230, 30);

 
  line(140, -15, 210, -15);
  line(120, -30, 230, -30);
  line(140, -45, 210, -45);
  line(120, -60, 230, -60);
  line(140, -75, 210, -75);
  line(120, -90, 230, -90);
  line(140, -105, 210, -105);
  line(120, -120, 230, -120);

  
  
  /*beginShape(QUADS);
  fill(0, 0, 255); 
  vertex(0,0,0);
  vertex(0,1,0);
  vertex(1,1,0);
  vertex(1,0,0);
  
  endShape();*/
  
}

void draw_bars(float first,float second, float third, float fourth)
{
  fill(0,0,255);
  strokeWeight(1);
  stroke(100,100,100);
  rect(380 + 0,120,20,-first);
  rect(380 + 40,120,20,-second);
  rect(380 + 80,120,20,-third);
  rect(380 + 120,120,20,-fourth);
  
  rect(0,-20,first,20);
  rect(0,20,second,20);
  rect(0,60,third,20);
  rect(0,100,fourth,20);
  
  
  
}
