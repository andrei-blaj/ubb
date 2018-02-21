%MEAN - MIU, X BARAT
%variance - sigma patrat, s patrat
%std. dev. - sigma, s

X = [20*ones(1,2),21,22*ones(1,3),23*ones(1,6),24*ones(1,5),25*ones(1,9),26*ones(1,2),27*ones(1,2)];
Y = [75*ones(1,3),76*ones(1,2),77*ones(1,2),78*ones(1,5),79*ones(1,8),80*ones(1,8),81,82];

% a) the means
mX = mean(X);  
mY = mean(Y);
fprintf('The mean of X = %3.4f \nThe mean of Y = %3.4f\n',mX,mY)

%t b) the variance
vX = var(X,1);
vY = var(Y,1);
fprintf('The variance of X = %3.4f \nThe variance of Y = %3.4f\n',vX,vY)

% c) covariances of X and Y
mycov = cov(X,Y,1);
fprintf('The covariance of X and Y: %f\n',mycov(1,2))

% d) the correlation coeff
myCorrCoeff = corrcoef(X,Y);
fprintf('The correlation coeff of X and Y: %f\n',myCorrCoeff(1,2))

% e) scattergram and the line of regression
scatter(X,Y) %scatterplot
hold on
% line of regression
xregr = X;
yregr = mY + myCorrCoeff(1,2)*(sqrt(vY/vX))*(xregr - mX);
plot(xregr,yregr,'r')





