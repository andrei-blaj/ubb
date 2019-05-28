clf;
hold on;
axis equal;
X=[];
Y=[];
axis([0 2, 0 1]) %limite in care sunt  vizibile axele x si y
while 1
    [x,y] = ginput(1);
    if x<0 || x>2 || y < 0 || y > 1
        break
    else 
        plot(x,y,'o', 'MarkerSize', 10);
        X=[X,x];
        Y=[Y,y];
    end
end

hold on

t = linspace(0,1,length(X));
tt= 0:0.01:1;
xt = ppval(spline(t,[1,X,1]), tt)
yt = ppval(spline(t,[1,Y,1]),tt)
plot(xt,yt)

%fplot(@(T) polyval(polyfit(X,Y,3),T),[0,2])
%fplot(@(T) ppval(spline(X,[1,Y,1]),T),[0,2])
%plot(X,Y,'*r')
hold off
