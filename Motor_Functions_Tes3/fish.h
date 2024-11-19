void fish() {
  while(digitalRead(10) == false)
  {
    digitalWrite(9,0);
    xmotion.StopMotors(1);  // 100ms Stop Both Motors
  }
  xmotion.Backward(100,100);
  xmotion.Right0(30,300);  // %51 Speed, 1 second Right 0 Turn. (Left Motor Forward, Right Backward)
}
