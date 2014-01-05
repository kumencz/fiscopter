void print_graph()
{
    graph.background(25);
    graph.noStroke();
    graph.strokeWeight(line_width);        //stroke wider
    
    for(i = 1; i < width -1 ; i ++)
    {
      graph.stroke(255,255,255);
      graph.line(i*graph_speed-1*graph_speed, height - numbers[1][i-1]+1, i*graph_speed, height - numbers[1][i]); 
      
      graph.stroke(0,50,150);
      graph.line(i*graph_speed-1*graph_speed, height - numbers[2][i-1]+1, i*graph_speed, height - numbers[2][i]); 
      
      graph.stroke(255,0,0);
      graph.line(i*graph_speed-1*graph_speed, height - numbers[3][i-1]+1, i*graph_speed, height - numbers[3][i]); 
      
      graph.stroke(0,255,0);
      graph.line(i*graph_speed-1*graph_speed, height - numbers[4][i-1]+1, i*graph_speed, height - numbers[4][i]); 
      
      graph.stroke(255,0,255);
      graph.line(i*graph_speed-1*graph_speed, height - numbers[5][i-1]+1, i*graph_speed, height - numbers[5][i]); 
    }
    
    
    
    for(u = 1; u < 6; u++)
    {
      for(i = 1; i < width; i++)
      {
        numbers[u][i] = numbers[u][i+1];
      }
    }
}
