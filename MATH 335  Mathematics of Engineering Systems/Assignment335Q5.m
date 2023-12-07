% Example usage
n_vals = linspace(-100, 100, 1000);
x1 = zeros(1, length(n_vals));
for i = 1:length(n_vals)
    x1(i) = cos(0.16*pi*n_vals(i));
end
y1 = dnsample(x1, 4);
ny1 = dnsample(n_vals, 4);

figure;
subplot(2,1,1);
plot(n_vals, x1);
title('Signal x(n) and down-sampled signal y(n), frequency = 0.16');
xlabel('n');
ylabel('x(n)');
subplot(2,1,2);
plot(ny1, y1);
xlabel('n');
ylabel('y(n)');

n_vals = linspace(-100, 100, 1000);
x2 = zeros(1, length(n_vals));
for i = 1:length(n_vals)
    x2(i) = cos(0.8*pi*n_vals(i));
end
y2 = dnsample(x2, 4);
ny2 = dnsample(n_vals, 4);

figure;
subplot(2,1,1);
plot(n_vals, x2);
title('Signal x(n) and down-sampled signal y(n), frequency = 0.8');
xlabel('n');
ylabel('x(n)');
subplot(2,1,2);
plot(ny2, y2);
xlabel('n');
ylabel('y(n)');

xf1 = fft(x1);
yf1 = fft(y1);

figure;
subplot(2,1,1);
f = (0:length(xf1)-1)/length(xf1);
plot(f, xf1);
title('Fourier Transform of b)');
xlabel('Frequency (Hz)');
ylabel('Magnitude');
f = (0:length(yf1)-1)/length(yf1);
subplot(2,1,2);
plot(f, yf1);
xlabel('Frequency (Hz)');
ylabel('Magnitude');

xf2 = fft(x2);
yf2 = fft(y2);

figure;
subplot(2,1,1);
f = (0:length(xf2)-1)/length(xf2);
plot(f, xf2);
title('Fourier Transform of c)');
xlabel('Frequency (Hz)');
ylabel('Magnitude');
subplot(2,1,2);
f = (0:length(yf2)-1)/length(yf2);
plot(f, yf2);
xlabel('Frequency (Hz)');
ylabel('Magnitude');

function y = dnsample(x, M)
% Down-sample the input signal x by a factor of M

% Length of input signal
N = length(x);

% Length of output signal
L = ceil(N/M);

% Initialize output signal
y = zeros(1, L);

% Down-sample the signal
for n = 0:L-1
    y(n+1) = x(n*M+1);
end
end
