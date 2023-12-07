% Define the trigonometric function f(t)
f = @(t) 2*sin((1/4)*pi*t)+3*cos((1/2)*pi*t);

% Define the range of t
t = linspace(0, 1, 1000);

% Define the values of n for the Bernstein approximations
n_values = [5, 10, 20];

% Initialize a vector to store the maximum differences for each n
max_diff = zeros(length(n_values), 1);

% Compute the Bernstein approximations for each value of n
figure;
plot(t, f(t), 'k-', 'LineWidth', 2);
hold on;
for i = 1:length(n_values)
    n = n_values(i);
    Bn = zeros(size(t));
    for k = 0:n
        Bn = Bn + nchoosek(n, k) * t.^k .* (1-t).^(n-k) .* f(k/n);
    end
    plot(t, Bn, '-', 'LineWidth', 1);
    
    % Compute the maximum difference between f(t) and Bn,f(t)
    diff = abs(f(t) - Bn);
    max_diff(i) = max(diff);
end

% Plot the results
legend('f(t)', ['B', num2str(n_values(1)), ',f(t)'], ['B', num2str(n_values(2)), ',f(t)'], ['B', num2str(n_values(3)), ',f(t)']);
xlabel('t');
ylabel('f(t) / Bn,f(t)');

% Print the maximum differences for each value of n
disp(['Max differences: ', num2str(max_diff')]);

