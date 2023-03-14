classdef ClSphere < handle
    properties (GetAccess = private)
      X;
      Y;
      Z;
      r;
      vx; # velocity xyz
      vy;
      vz;
      af; # air friction
      g;  # gravity
     end
     methods
       function obj = ClSphere(r = 10)
         [obj.X, obj.Y, obj.Z] = sphere(r);
         obj.r = 10;
         obj.vx = 5;
         obj.vy = 5;
         obj.vz = 30;
         obj.af = 0.25;
         obj.g  = 3;
       end
       
       function up_down(obj)
         if obj.vz > 0;
           obj.vz = obj.vz - obj.g - obj.af;
         else
           obj.vz = obj.vz - obj.g + obj.af;
         end
         if (min(min(obj.Z + obj.vz))) < 0;
           [obj.X, obj.Y, obj.Z] = sphere(obj.r);
           obj.vz = obj.vz * -1;       
          else
            obj.Z = obj.Z + obj.vz;
         end
       end
       
       function oplot(obj)
        surf(obj.X, obj.Y, obj.Z, 'FaceAlpha', 0.2, 'FaceColor', 'interp')
        hold on
        #plot3([0; 0], [0;0], [0; 2*obj.r])
        r1 = obj.r;
        x = [-r1*10, -r1*9; -r1*10, -r1*9];
        y = [r1*10, r1*10;r1*10, r1*10];
        z = [0, 0; r1*20, r1*20];
        surf(x,y,z)
        x = [-r1*10, -r1*10;r1*10, r1*10];
        y = [-r1*10, -r1*9;-r1*10, -r1*9];
        z = [0,0;0,0];
        surf(x,y,z)
        pbaspect([1 1 1])
        xlabel('cos(x)');
        ylabel('sin(y)');
        zlabel('sin(z)');
        view([67 45])
        #view([0 0])
        grid on
        #axis off
        hold off
       end
                    
       function make_gif(obj)
         filename = 'sphere.gif';
         DelayTime = 1/25;
         f = figure;
         for n = [1:1:110]
           obj.up_down;
           obj.oplot
           obj.Z(1,1)
           title(['Sphere| vz=' ; num2str(obj.vz)], "fontsize", 16)
           drawnow
           frame = getframe(f);
           im = frame2im(frame);
           [imind, cm] = rgb2ind(im);
           if n == 1;
             imwrite(imind,cm,filename,'gif','DelayTime', DelayTime , 'Compression' , 'lzw');
           else
             imwrite(imind,cm,filename,'gif','WriteMode','append','DelayTime', DelayTime , 'Compression' , 'lzw');
           end
         end
       end
           
     endmethods
 end
 