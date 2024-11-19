//  if (t == 1) {
//    while(true){
//      xmotion.Forward(30,30); // %100 Speed, both motor forward 100mS.
//      if (analogRead(A5) < 500) {
//        break;
//      } else if (analogRead(A4) < 500) {
//        break;
//      } else {
//      }
//    }
//    xmotion.StopMotors(100);  // 100ms Stop Both Motors
//  }
//  else
//  {
//  }
void fish(){
  xmotion.Backward(100,100);
  xmotion.Right0(30,300);  // %51 Speed, 1 second Right 0 Turn. (Left Motor Forward, Right Backward)
}
