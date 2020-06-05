void loop() {
  StopIt=false;
      if(showType==15)
      {
        if(RandomTime==0)
        {
        RandomTime=millis();
        }
        if(millis()-RandomTime > 10000)
        {
          RandomTime=millis();
          a=random(1,15);
        } 
        
      startShow(a);
      }
      
      else{
       RandomTime=0;
        startShow(showType);
        
      }

}
