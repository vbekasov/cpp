function m = tor(r1 = 10)
  # number of segments on XY surface = seg * 2 
  # horizontal points are defined by l
  seg = 10;
  #l = [-pi:pi/seg:pi+pi/seg];
  l = [-pi:pi/seg:pi];
  # number of segments on vertical section = seg * 2
  # for clear represintation seg should be one of 2 power
  # vertical points are defined by lk 
  seg = 8;
   l = repmat(l, 1, seg*2+1);
  l = reshape(l, [], seg*2+1);
  lk = sin([-pi/2:pi/seg:pi+pi/2])+2;
  
  x = ((ones(size(l)(1), size(lk)(1)).*cos(l)*r1).*lk)';
  y = ((ones(size(l)(1), size(lk)(1)).*sin(l)*r1).*lk)';
  z = (zeros(size(l)(1), size(lk)(1))+(cos([-pi/2:pi/seg:pi+pi/2])*r1+r1))';
  
  surf(x, y, z, 'FaceAlpha', 0.2, 'FaceColor', 'interp')
  hold on
  plot3(0, 0, r1*6)
  pbaspect([1 1 1])
  xlabel('cos(x)');
  ylabel('sin(y)');
  zlabel('ring z');
  grid on
  hold off
end
