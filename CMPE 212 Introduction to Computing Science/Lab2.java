package lab2;

public class Lab2 {

	/**
	 * Returns the maximum of two values using an unusual algorithm.
	 * 
	 * @param a a value
	 * @param b a value
	 * @return the maximum of the two argument values
	 */
	public static int max2(int a, int b) {
		long twiceMax = 0L + a + b;
		twiceMax += Math.abs(0L + a - b);
		return (int)(twiceMax / 2);
	}

	/**
	 * Swaps the values of the arguments {@code x} and {@code y}?
	 * 
	 * @param x a value to swap
	 * @param y the other value to swap
	 */
	public static void swap(int x, int y) {
		int tmp = x;
		x = y;
		y = tmp;
	}

	/**
	 * Swaps the values of the arguments {@code s} and {@code t}?
	 * 
	 * @param s a string to swap
	 * @param t the other string to swap
	 */
	public static void swap(String s, String t) {
		String tmp = s;
		s = t;
		t = tmp;
	}

	/**
	 * Swaps the values of the elements of the array {@code arr} at indexes
	 * {@code i} and {@code j}?
	 * 
	 * @param arr an array in which to swap elements
	 * @param i   the index of one element to be swapped
	 * @param j   the index of other element to be swapped
	 */
	public static void swap(int[] arr, int i, int j) {
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}


	/**
	 * Returns the number of iterations for the Collatz
	 * sequence to reach the value 1 when starting from the
	 * specified positive value {@code n}.
	 * 
	 * @param n the starting value of the sequence
	 * @return the number of iterations required to reach a value of 1
	 */
	public static long collatz(long n) {
		if (n < 1) {
			throw new IllegalArgumentException("n < 1");
		}
		int count = 0;
		while (n != 1) {
			if (n % 2 == 0) {
				n = n / 2;
			}
			else {
				n = 3 * n + 1;
			}
			count++;
		}
		return count;
	}
	
	
	/**
	 * Complete this method for Exercise 1. 
	 */
	public static void ex1() {
		System.out.println(Lab2.max2(0, 1073741823));
	}
	
	
	/**
	 * Complete this method for Exercise 2.
	 * 
	 * <p>
	 * Swaps the coordinates of the two input points.
	 * 
	 * @param p a point to swap coordinates with
	 * @param q the other point to swap coordinates with
	 */
	public static void swap(Point2 p, Point2 q) {
		lab2.Point2 tmp;
		tmp = q;
		q = p;
		p = tmp;
	}
	
	
	/**
	 * Complete this method for Exercise 3.
	 */
	public static void ex3() {
		Lab2.collatz(20220695);
		final int N = 90993130;
	}
	
	
	
	public static void main(String[] args) {
		int x = 5;
		int y = 7;
		int max = Lab2.max2(x, y);
		System.out.println(max);
	}

}
