import processing.serial.*;

/*PrintWriter ::https://ws.tetsuakibaba.jp/doku.php?id=processing:csv書出 */
PrintWriter output;
boolean flg_start = false;
boolean WriteToFile = false;
boolean flg_done = false;
String str_format = "x,y,z";
int count = 0;
/**/

Serial myPort;
String COM_PORT = "COM5";
int time = 0;
int ax = 0, ay = 0, az = 0;

final int WINSIZE = 700;

void settings(){
  size(WINSIZE, WINSIZE);
}

void setup(){
  frameRate(60);
  //シリアルポートに接続。速度は115.2kbps
  myPort = new Serial(this, COM_PORT, 921600);
  myPort.bufferUntil(0xFF);
  
  /*PrintWriter*/
  String filename = nf(year(), 4) + nf(month(), 2) + nf(day(), 2) + nf(hour(), 2) + nf(minute(), 2);
  output = createWriter( filename + ".csv"); 
  output.println( str_format );
}

void serialEvent(Serial p){
  ax = p.read() * 64;
  ax = ax + p.read();
  ay = p.read() * 64;
  ay = ay + p.read();
  az = p.read() * 64;
  az = az + p.read();
  while(p.read() != 0xFF){
    if(WriteToFile==true){
      output.println(ax+","+ay+","+az);
    }
  }
}


void draw(){
  color cx = color(255, 0, 0);
  color cy = color(0, 255, 0);
  color cz = color(0, 0, 255);
  
  //描画
  time = (time+1)%WINSIZE;
  fill(cx); ellipse(time, ax/16, 5, 5);
  fill(cy); ellipse(time, ay/16, 5, 5);
  fill(cz); ellipse(time, az/16, 5, 5);
  
  
  if(flg_start){
    output.println(ax+","+ay+","+az);
    count++;
  } else if(!WriteToFile && flg_done){
    output.flush(); 
    output.close();
    exit();
  }
  
  if(count > 100){
    WriteToFile = !WriteToFile;
    flg_done = true;
  }
  

  println(ax, " ", ay, " ", az);
}


void keyPressed() {
  if ( key == 's' ) {
    WriteToFile  = !WriteToFile;
  }
}
