void print_graph()
{
    graph.background(25);
    graph.noStroke();
    
    graph.text(inString.replaceAll("\\|", "\n"), 30, 30);
    
    graph.strokeWeight(4);        
    strokeCap(ROUND);                     //line ending
    
    
    graph.stroke(255,255,255);
    graph.line(10, 37, 20, 37); 
    
    graph.stroke(0,50,150);
    graph.line(10, 53, 20, 53);
    
    graph.stroke(255,0,0);
    graph.line(10, 67, 20, 67); 
    
    graph.stroke(0,255,0);
    graph.line(10, 80, 20, 80); 
    
    graph.stroke(255,0,255);
    graph.line(10, 93, 20, 93);
    
    graph.stroke(0,255,255);
    graph.line(10, 107, 20, 107);
      
  /*    
    graph.strokeWeight(line_width);        //line width
    for(i = 1; i < width -1 ; i ++)
    {
      graph.stroke(255,255,255);
      graph.line(i*graph_speed-1*graph_speed, height - numbers[1][i]+1, i*graph_speed, height - numbers[1][i]); 
      
      graph.stroke(0,50,150);
      graph.line(i*graph_speed-1*graph_speed, height - numbers[2][i]+1, i*graph_speed, height - numbers[2][i]); 
      
      graph.stroke(255,0,0);
      graph.line(i*graph_speed-1*graph_speed, height - numbers[3][i]+1, i*graph_speed, height - numbers[3][i]); 
      
      graph.stroke(0,255,0);
      graph.line(i*graph_speed-1*graph_speed, height - numbers[4][i]+1, i*graph_speed, height - numbers[4][i]); 
      
      graph.stroke(255,0,255);
      graph.line(i*graph_speed-1*graph_speed, height - numbers[5][i]+1, i*graph_speed, height - numbers[5][i]);
      
      graph.stroke(0,255,255);
      graph.line(i*graph_speed-1*graph_speed, height - numbers[6][i]+1, i*graph_speed, height - numbers[6][i]); 
    }
    
    */
    
    for(u = 1; u < 7; u++)
    {
      for(i = 1; i < width; i++)
      {
        numbers[u][i] = numbers[u][i+1];
      }
    }
    
    
}
