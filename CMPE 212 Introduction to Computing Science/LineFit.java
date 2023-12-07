package a3;

import java.awt.Color;
import java.util.ArrayList;
import java.util.List;

import ca.queensu.cs.cisc124.notes.basics.geometry.Vector2;

import princeton.introcs.StdDraw;

public class LineFit {

	/**
	 * Finds the line of best fit to a sequence of points using ordinary least
	 * squares. The returned array consists of the y-intercept followed by
	 * the slope of the best fit line. If {@code a} is the returned array,
	 * then the equation of the line is given by:
	 * 
	 * <pre>
	 * y = a[0] + a[1] * x;
	 * </pre>
	 * 
	 * @param p a list of points to fit a line to
	 * @return an array containing the y-intercept and slope of the best fit line
	 * @throws IllegalArgumentException if {@code p} has fewer than two points
	 * @throws ArithmeticException if the line of best fit is exactly vertical
	 */
	public static double[] lsfit(List<Vector2> p) {
		if(p.size()<2) {
			throw new IllegalArgumentException();
		}
		double[] y = {0,0};
		Matrix2 m = new Matrix2();
		Vector2 v = new Vector2();
		m.set(0, 0, p.size());
		double xi = 0.0;
		double xi2 = 0.0;
		double yi = 0.0;
		double xiyi = 0.0;
		for(int i = 0;i<p.size();i++) {
			xi = xi + p.get(i).x();
			xi2 = xi2 + p.get(i).x()*p.get(i).x();
			yi = yi + p.get(i).y();
			xiyi = xiyi + p.get(i).x()*p.get(i).y();
		}
		m.set(0, 1, xi);
		m.set(1, 0, xi);
		m.set(1, 1, xi2);
		v.set(yi, xiyi);
		Matrix2 minv = m.inv();
		Vector2 ab = new Vector2();
		ab = minv.mult(v);
		y[0] = ab.x();
		y[1] = ab.y();
		if(y[1]==0) {
			throw new ArithmeticException();
		}
		return y;
		
		
	}

	/**
	 * Plots the specified sequence of points and line.
	 * 
	 * @param p a list of points to plot
	 * @param line the y-intercept and slope of the line to plot
	 */
	public static void plot(List<Vector2> p, double[] line) {
		StdDraw.clear();
		for (Vector2 v : p) {
			StdDraw.setPenColor(Color.BLACK);
			StdDraw.filledCircle(v.x(), v.y(), 0.25);
		}
		double x1 = -10.0;
		double y1 = line[1] * x1 + line[0];
		double x2 = 10.0;
		double y2 = line[1] * x2 + line[0];
		StdDraw.setPenColor(Color.RED);
		StdDraw.line(x1, y1, x2, y2);
	}

	/**
	 * Plots 10 points randomly displaced vertically from the line
	 * {@code y = 0.0 + x} and the line of the best fit. Prints the
	 * slope and intercept of the best fit line to standard output. 
	 * 
	 * @param args not used
	 */
	public static void main(String[] args) {
		StdDraw.setScale(-11, 11);
		List<Vector2> p = new ArrayList<>();
		for (int i = 0; i < 10; i++) {
			double x = i * 2 - 10;
			double y = x + (Math.random() - 0.5) * 4;
			p.add(new Vector2(x, y));
		}
		double[] params = lsfit(p);
		System.out.println("slope : " + params[1] + ", intercept : " + params[0]);
		plot(p, params);
	}
}
