// Project Simple Bulb Circuit
#include<iostream>
#include<graphics.h>
int main()
{ 
    initwindow(750,400,"Simple Glow Bulb Circuit by Code4xU");
    
    //<!-------Wires------->
    line(50,50,500,50);     //top
    line(50,50,50,300);     //left
    line(50,300,180,300);   // left-bottom 
    line(180,300,180,280);  // battery connection1
    line(220,300,220,280);  // battery connection2
    line(220,300,350,300);  // battery to bulb
    line(350,290,500,290);  // bulb to right-bottom
    line(500,50,500,150);   // switch to top
    line(500,220,500,290);  // right-bottom to switch on/off
    
    
     
     
     //<!-------Battery-------------->
     rectangle(150,130,250,270);  // battery body
     bar(205,140,240,260);        // battery status bar  
     rectangle(170,270,190,280);  // battery terminal1
     rectangle(210,270,230,280);  // battery terminal2
     line(195,130,195,270);       // battery partion line
    
    //<!---------Switch------------>
     rectangle(480,150,520,220);  // switch box
     rectangle(485,160,515,210);  // switch inside box
     line(485,185,515,185);      // switch partion line
     
     //<!-------------Text---------->
     
      outtextxy(490,165,"On");  // Switch on
      outtextxy(490,190,"Off");  //switch off
      outtextxy(50,10,"Press Esc To Exit"); // Esc on top-left side
      settextstyle(4,1,3);   // text styling
      outtextxy(160,260,"Battery"); //written inside battery
      settextstyle(3,0,1);  //text styling  
      
      //<!----------Bulb----------------->
     
      readimagefile("pic_bulboff.gif",320,200,400,300);//default bulb-off image printing
      
      //<!-------------Working -------------------->
      
     int flag,battery_per=105,h=0,hh=12;char msg[20]; // variables needed
     
     while(1){                                        //infinite while loop
              delay(300);                             // delay of 300 milli seconds
              
              //Condition for switch-On Button and bulb glow
              if( GetAsyncKeyState(VK_LBUTTON) && mousex()>=485 && mousex()<=515 && mousey()>=160 && mousey()<=184){
                          setfillstyle(1,3);
                           floodfill(489,164,WHITE);
                           setfillstyle(1,3);
                           floodfill(494,165,WHITE);
                            setfillstyle(1,0);
                            floodfill(489,189,WHITE);
                           if( battery_per>0 ){
                              
                           readimagefile("pic_bulbon.gif",320,200,400,300);
                           }
                           flag=1; // flag value for battery percentage
                          
                          }
                          
              //Condition for switch off button and bulb off
              if(GetAsyncKeyState(VK_LBUTTON) && mousex()>=485 && mousex()<=515 && mousey()>=186 && mousey()<=209){
                  setfillstyle(1,0);
                  bar(320,200,400,285);
                  
                 readimagefile("pic_bulboff.gif",320,200,400,300);
                           setfillstyle(1,3);
                           floodfill(489,189,WHITE);
                            setfillstyle(1,0);
                            floodfill(489,164,WHITE);
                 flag=0; // flag value for battery percentage
              }
              
              // flag value 1 bulb glow but when out of power bulb off
              if(flag==1){
                          if(battery_per==0)
                          {
                             flag=0;
                             setfillstyle(1,0);
                             bar(320,200,400,285);
                             readimagefile("pic_bulboff.gif",320,200,400,300);
                             outtextxy(250,80,"Out of Power");
                            
                           }
                         else{
                            battery_per =battery_per-5  ;  
                            sprintf(msg,"! battery Percentage %d%c ",battery_per,'%');
                            outtextxy(550,h,msg);
                            h=h+18;
                            setfillstyle(1,0);
                            bar(205,140,240,140+hh);
                            hh=hh+5;
                            }
                   
                   }
              
              // For Exit Purpose
              if(GetAsyncKeyState(VK_ESCAPE))
              break;
            
              
              }
              
    getch();
    closegraph();
     return 0;
}
