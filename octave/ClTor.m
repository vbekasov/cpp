classdef ClTor < handle
  properties (GetAccess = private)
    X
    Y
    Z
    r1
  end
  properties
  end
  methods
    function obj = ClTor(r = 10)
      [obj.X, obj.Y, obj.Z, obj.r1] = tor(r, false);
    end
    function move_up(obj, z1 = 1)
      obj.Z  = obj.Z + z1;
    end
    function [X, Y, Z, r] = return_xyz(obj)
      X = obj.X;
      Y = obj.Y;
      Z = obj.Z;
      r = obj.r1;
    end
    function oplot(obj)
      r1 = obj.r1;
      surf(obj.X, obj.Y, obj.Z)
      hold on
      x = [-r1*4, -r1*3; -r1*4, -r1*3];
      y = [r1*4, r1*4;r1*4, r1*4];
      z = [0, 0; r1*8, r1*8];
      surf(x,y,z)
      x = [-r1*4, -r1*4;r1*4, r1*4];
      y = [-r1*4, -r1*3;-r1*4, -r1*3];
      z = [0,0;0,0];
      surf(x,y,z)
      pbaspect([1 1 1])
      xlabel('cos(x)');
      ylabel('sin(y)');
      zlabel('cos(z)');
      view([67 45])
      grid on
      hold off
    end
    function make_gif(obj)
      filename = 'tor.gif';
      DelayTime = 1/25;
      f = figure;
      for n = [1:1:45]
        obj.move_up
        obj.oplot
        title('Tor', "fontsize", 16)
        drawnow
        frame = getframe(f);
        im = frame2im(frame);
        [imind, cm] = rgb2ind(im);
        if n == 1;
          imwrite(imind,cm,filename,'gif','DelayTime', DelayTime , 'Compression' , 'lzw');
        else
          imwrite(imind,cm,filename,'gif','WriteMode','append','DelayTime', DelayTime , 'Compression' , 'lzw');
        endif
      end
    end
  end
end
















