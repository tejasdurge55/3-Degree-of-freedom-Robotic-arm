%program for robot in matlab
clear all;
clear a;
a = arduino('COM10', 'Uno');
writeDigitalPin(a, 'D9', 0);%base motor pulse
writeDigitalPin(a, 'D5', 0);%base motor direction
writeDigitalPin(a, 'D10', 0);%middle motor pulse
writeDigitalPin(a, 'D6', 0);%middle motor direction
writeDigitalPin(a, 'D11', 0);%gripper motor pulse
writeDigitalPin(a, 'D7', 0);%gripper motor direction



b1=5000;
b2=-5000;
m1=500;
m2=-500;
g1=5000;
g2=-5000;

pulsetimeb1=abs(b1)/1000;
pulsetimeb2=abs(b2)/1000;
pulsetimem1=abs(m1)/1000;
pulsetimem2=abs(m2)/1000;
pulsetimeg1=abs(g1)/1000;
pulsetimeg2=abs(g2)/1000;

% base motor program start----------------------------
    if (b1<0)
        writeDigitalPin(a, 'D5', 1);
    pause(0.01);
    else
    writeDigitalPin(a, 'D5', 0);
    pause(0.01);
    end    
   writePWMDutyCycle(a, 'D9', 0.5);
     pause(pulsetimeb1);
     writePWMDutyCycle(a, 'D9', 0);
     pause(3);
     
    if (b2<0)
        writeDigitalPin(a, 'D5', 1);
    pause(0.01);
    else
    writeDigitalPin(a, 'D5', 0);
    pause(0.01);
    end
    writePWMDutyCycle(a, 'D9', 0.5);
     pause(pulsetimeb2);
     writePWMDutyCycle(a, 'D9', 0);
% base motor program end----------------------------end

pause(2);

% middle motor program start----------------------------
    if (m1<0)
        writeDigitalPin(a, 'D6', 1);
    pause(0.01);
    else
    writeDigitalPin(a, 'D6', 0);
    pause(0.01);
    end    
   writePWMDutyCycle(a, 'D10', 0.5);
     pause(pulsetimem1);
     writePWMDutyCycle(a, 'D10', 0);
     pause(3);
     
    if (m2<0)
        writeDigitalPin(a, 'D6', 1);
    pause(0.01);
    else
    writeDigitalPin(a, 'D6', 0);
    pause(0.01);
    end
    writePWMDutyCycle(a, 'D10', 0.5);
     pause(pulsetimem2);
     writePWMDutyCycle(a, 'D10', 0);
% middle motor program end----------------------------end

pause(2);

% gripper motor program start----------------------------
    if (g1<0)
        writeDigitalPin(a, 'D7', 1);
    pause(0.01);
    else
    writeDigitalPin(a, 'D7', 0);
    pause(0.01);
    end    
   writePWMDutyCycle(a, 'D11', 0.5);
     pause(pulsetimeg1);
     writePWMDutyCycle(a, 'D11', 0);
     pause(3);
     
    if (g2<0)
        writeDigitalPin(a, 'D7', 1);
    pause(0.01);
    else
    writeDigitalPin(a, 'D7', 0);
    pause(0.01);
    end
    writePWMDutyCycle(a, 'D11', 0.5);
     pause(pulsetimeg2);
     writePWMDutyCycle(a, 'D11', 0);
% gripper motor program end----------------------------end


disp("program end")






%{
function mot1=motor1(g)
    if (g<0)
        writeDigitalPin(a, 'D5', 1);
    pause(0.1);

    else
    writeDigitalPin(a, 'D5', 0)
    pause(0.1);
    end
     for z = 1 : abs(g)
  writeDigitalPin(a, 'D6', 1);
    pause(0.01);
    writeDigitalPin(a, 'D6', 0);
    pause(0.01);
         
    end
%}