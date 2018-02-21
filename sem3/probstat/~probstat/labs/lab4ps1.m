p=input('p (0.05<=p<=0.95) = ');
for n=1:3:100
    xpdf=0:n;
    ypdf=binopdf(xpdf,n,p);
    plot(xpdf,ypdf)
    pause(0.5)
end