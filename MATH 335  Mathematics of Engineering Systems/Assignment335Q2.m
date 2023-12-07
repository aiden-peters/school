% Define the values of N and N1
N1_vals = [1, 5, 20, 1];
N_vals = [2, 20, 20, 20];

% Loop over the different values of N and N1
for i = 1:length(N1_vals)
    % Construct the signal x
    N1 = N1_vals(i);
    N = N_vals(i);
    x = zeros(2*N+1, 1);
    for n = -N:N
        x(n+N+1) = (abs(n)<=N1);
    end
    
    % Compute the Fourier series coefficients
    ak = FourSeries(x, N, N1);
    
    % Plot the coefficients
    figure;
    subplot(3,1,1)
    plot(-N:N,ak);
    
    xlabel('k');
    ylabel('|ak|');
    title(sprintf('Fourier series coefficients for N=%d, N1=%d', N, N1));
    
    % Reconstruct the signal from the Fourier series coefficients
    x_tilde = zeros(1, 2*N+1);
    for n = -N:N
        for k = -N:N
            x_tilde(n+N+1) = x_tilde(n+N+1) + ak(k+N+1)*exp(1i*k*2*pi*(n)/(2*N+1));
        end
        x_tilde(n+N+1) = x_tilde(n+N+1)/sqrt(2*N+1);
    end
    
    % Plot the reconstructed signal
    subplot(3,1,2);
    plot((-N:N), x_tilde);
    xlabel('n');
    ylabel('x_(tilde)(n)');
    title(sprintf('Reconstructed signal for N=%d, N1=%d', N, N1));
    
    % Plot the original signal
    subplot(3,1,3);
    plot(-N:N, x);
    xlabel('n');
    ylabel('x(n)');
    title(sprintf('Original signal for N=%d, N1=%d', N, N1));
    
end

function [ak] = FourSeries(x, N, N1)
% Computes the Fourier series coefficients for a given signal x with period 2N+1

% Compute the coefficients
ak = zeros(2*N+1,1);
for k = -N:N
    for n = -N:N
        ak(k+N+1) = ak(k+N+1) + x(n+N+1)*exp(-i*k*2*pi*(n)/(2*N+1));
    end
    ak(k+N+1) = ak(k+N+1)/sqrt(2*N+1);
end

end

