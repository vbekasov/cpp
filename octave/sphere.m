function sphere(r1 = 10)
  seg = 6;
  l = [-pi:pi/seg:pi];
  
  seg = 4;
  l = repmat(l, 1, seg);
  l = reshape(l, [], seg);
  # h - hight, responsible for z-axis 
  h = [0:pi/2/3:pi/2];
  
  x = ((ones(size(l)(1),4).*cos(l)*r1).*cos(h))';
  y = ((ones(size(l)(1),4).*sin(l)*r1).*cos(h))';
  z = (ones(size(l)(1),1).*(sin(h)*r1))';
  
  hold on
  surf(x, y, z, 'FaceAlpha', 0.2, 'FaceColor', 'interp')
  surf(x, y, z*(-1), 'FaceAlpha', 0.2, 'FaceColor', 'interp')
  plot3([0; 0], [0;0], [10; -10])
  pbaspect([1 1 1])
  xlabel('cos(x)');
  ylabel('sin(y)');
  zlabel('ring z');
  view([67 45])
  grid on
  hold off
end
  