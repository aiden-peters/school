t_vals = linspace(-5, 5, 1000); % define time interval
x = 10*exp(-(t_vals.^2)/2); % define x(t)
n = 20*cos(8*pi*t_vals) + 2*sin(8*pi*t_vals); % define n(t)
y = x + n; % define y(t)

% plot x(t) and y(t)
figure;
plot(t_vals, x, 'b', t_vals, y, 'r');
xlabel('t');
ylabel('Amplitude');
title('Signal x(t) and received signal y(t)');
legend('x(t)', 'y(t)');

fs = 55; % define sampling frequency

Ts = 1/fs; % define sampling interval
t_vals_sampled = -5:Ts:5; % define time interval for sampled signal
y_sampled = interp1(t_vals, y, t_vals_sampled); % sample y(t) at the desired rate
Y = fft(y_sampled);

% apply ideal low-pass filter
fc = 1; % define cutoff frequency
Wn = fc/fs;

N = length(Y);
n = round(fc/(fs/2)*N);
Yf = [Y(1:n), zeros(1, N - 2*n), Y(N-n+1:N)];%Y filtered
yf = real(ifft(Yf)); 
% plot the filtered signal
figure;
plot(t_vals_sampled, yf, 'b');
xlabel('t');
ylabel('Amplitude');
title('Filtered signal y(t)');

n = 3; 
[b, a] = butter(n, Wn);
yb = filter(b,a,y_sampled); %butterworth
ybb = interp1(t_vals_sampled, yb, t_vals); %butterworth back

figure;
disp(yb);
plot(t_vals, ybb, 'b');
xlabel('t');
ylabel('Amplitude');
title('Butter Filtered signal y(t)');

