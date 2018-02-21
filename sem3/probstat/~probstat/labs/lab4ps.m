x0=input('x0= ');
x1=input('x1= ');
x2=input('x2= ');
alpha=input('Alpha (0,1)= ');
beta=input('Beta (0,1)= ');
option=input('1 for Normal \n 2 for Student(T)= ');
switch option
    case 1
        %Normal distr
        miu=input('miu(in R)= ');
        sigma=input('sigma(>0)= ');
        %a
        a=normcdf(x0,miu,sigma);
        %b
        b=1-a;
        %c
        c=normcdf(x2,miu,sigma)-normcdf(x1,miu,sigma);
        %d
        d=1-c;
        %e
        e=norminv(alpha,miu,sigma);
        %f
        f=norminv(1-beta,miu,sigma);
    case 2
        df = input('df = ');
        %a
        ta=tcdf(x0,df);
        %b
        tb=1-ta;
        %c
        tc=tcdf(x2,df)-tcdf(x1,df);
        %d
        td=1-tc;
        %e
        te=tinv(alpha,df);
        %f
        tf=tinv(1-beta,df);
    otherwise
        error('Invalid option')
end    
fprintf('Answer for a) = %f\n',a)
fprintf('Answer for b) = %f\n',b)
fprintf('Answer for c) = %f\n',c)
fprintf('Answer for d) = %f\n',d)
fprintf('Answer for e) = %f\n',e)
fprintf('Answer for f) = %f\n',f)
