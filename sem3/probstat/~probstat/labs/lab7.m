%Parameters
%a = input('a= ');
%b = input('b(>a)= ');
lambda = input('Lambda (>0): ');
N = input('sample size= '); %sample
x = exprnd(lambda,1,N);
n = 1 + 10/3 * log10(N); %nr of classes Sturge's Rule
i = 1:n;
limits = min(x):((max(x)-min(x))/n):max(x);
left_l = limits(i);
right_l = limits(i+1);
[fr, mark] = hist(x,n);
relfr = fr/N;
res = [i; left_l;right_l; mark;fr;relfr];
fprintf(' NO | Class | Mark | Freq | Rel Freq | \n');
fprintf('%3d | [%3.4f, %3.4f] | %3.4f | %3d | %3.4f\n',res);

clf;
hist(x,n) %histogram
hold on
plot(mark, fr,'r','LineWidth',3);
imode = find(fr == max(fr));
resmode = [imode; left_l(imode); right_l(imode); mark(imode); fr(imode); relfr(imode)];
fprintf('Mode \n');
fprintf(' NO | Class | Mark | Freq | Rel Freq | \n');
fprintf('%3d | [%3.4f, %3.4f] | %3.4f | %3d | %3.4f\n',resmode);

Q = prctile(x,[25,50,75]);
fprintf('Quartiles Q1= %3.4f, Q2= %3.4f, Q3= %3.4f \n',Q)




