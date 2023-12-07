t_vals = linspace(0,2,1000); 
%N values 
N_vals = [5, 10, 15];

x_xN = zeros(1, length(N_vals));

P = 2; 

xn = zeros(1, length(t_vals));
 % for-loop for time-value
 for j = 1:length(t_vals)
      xn(j) = x(t_vals(j)); 
 end

%plot
figure; 
hold on; 

for N = N_vals
    %xN = arrayfun(@(t) FourSeries(t, N, P), t);
    xN = FourSeries(t_vals, N, P);
    plot(t_vals, real(xN), 'DisplayName', sprintf('N = %d', N));
    for t = 1:length(t_vals)
        x_xN(N/5) = x_xN(N/5) + (x(t)-xN(t))^2;
    end
end 
hold off; 

%x = @(t) x(t); 
%plot(t, x(t), 'k', 'linewidth', 1, 'DisplayName', 'x(t)');
xlabel('t');
ylabel('x_N');
title('Plot of Signal x_{N}(t) for N = 5,10,15');
legend('show'); 

hold on; 
plot(t_vals, xn, 'k', 'DisplayName', 'x_{n}');
xlabel('t');
ylabel('x(t)');
disp(x_xN);

function xt = x(t)
    xt = (t<=1).*t + (1<=t).*(t<=2).*(1-t);
end

function xN = FourSeries(t, N, P)
    x_caret = zeros(1,2*N+1);
    xN = 0; 
    for k = -N:N
        %to integrate over 0-1 when t<=1 
        x_caret(k+N+1) = integral(@(t) x(t).*exp(-1i*2*pi*(k/P)*t)*(1/sqrt(P)),0,1);
        %to integrate over 1-2 when t<=2 
        x_caret(k+N+1) = x_caret(k+N+1) + integral(@(t) x(t).*exp(-1i*2*pi*(k/P)*t)*(1/sqrt(P)),1,2);

        xN = xN + x_caret(k+N+1)*(1/sqrt(P)).*exp(1i*2*pi*(k/P)*t); 
    end
end 


