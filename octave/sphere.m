function [x, y, z] = sphere(r1 = 10, prnt = false)
  if 1 == isempty(r1)
    r1 = 10;
  end
  seg = 6;
  l = [-pi:pi/seg:pi];
  l = repmat(l, 1, seg+1);
  l = reshape(l, [], seg+1);
  h = [0:pi/2/(seg):pi/2];
  
  x = ((ones(size(l)(1),size(h)(2)).*cos(l)*r1).*cos(h))';
  x = cat(1, flip(x), x);
  y = ((ones(size(l)(1),size(h)(2)).*sin(l)*r1).*cos(h))';
  y = cat(1, flip(y), y);
  z = (ones(size(l)(1),size(h)(2)).*(sin(h)*r1))';
  z = cat(1, flip(z)*-1, z) + r1;

  if prnt == true  
      hold on
      surf(x, y, z, 'FaceAlpha', 0.2, 'FaceColor', 'interp')
      plot3([0; 0], [0;0], [0; 2*r1])
      pbaspect([1 1 1])
      #xlabel('cos(x)');
      #ylabel('sin(y)');
      #zlabel('ring z');
      view([67 45])
      #grid on
      axis off
      hold off
  end
end
  