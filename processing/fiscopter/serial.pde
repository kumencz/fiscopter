void serialEvent (Serial myPort) {
  // get the ASCII string:
  String inString = myPort.readStringUntil('\n');
 // println(inString);
  select = float(split(inString,"|"));
  println(split(inString,"|"));
  
  if (select[0] == 0 && !(Float.isNaN(select[1])) && !(Float.isNaN(select[2])) && !(Float.isNaN(select[3])) && !(Float.isNaN(select[4])) && !(Float.isNaN(select[5])))
  {
    input[1] = select[1];
    input[2] = select[2];
    input[3] = select[3];
    input[4] = select[4];
    input[5] = select[5];
  }
  
  if (select[0] == 0 && !(Float.isNaN(select[1])) && !(Float.isNaN(select[2])) && !(Float.isNaN(select[3])))
  {
    for(i = 1; i < input.length ; i++)
    {
      input_3D[i] = map(input[i], min_input, max_input, min_3D_output, max_3D_output); //map to the screen height.
      input_graph[i] = map(input[i], min_input, max_input, min_graph_output, max_graph_output); //map to the screen height.
      numbers[i][w_width/graph_speed -1] = input_graph[i];
    }
    print_graph();
  }
}
