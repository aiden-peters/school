package a3;

import ca.queensu.cs.cisc124.notes.basics.geometry.Vector2;

/**
 * A 2x2 matrix. This class provides basic mathematical operations such
 * as matrix-vector and matrix-matrix products, determinant, and inverse.
 *
 */
public class Matrix2 {
	
	private double a;
	private double b;
	private double c;
	private double d;
	
	/**
	 * Initializes this matrix to the identity matrix.
	 */
	public Matrix2() {
		this.a = 1.0;
		this.b = 0.0;
		this.c = 0.0;
		this.d = 1.0;
		
	}
	/**
	 * Initializes this matrix so that its entries are equal to the specified
	 * values. The matrix entries are defined to be:
	 * 
	 * <pre>
	 * a b
	 * c d
	 * </pre>
	 * 
	 * @param a the value of the upper left element
	 * @param b the value of the upper right element
	 * @param c the value of the lower left element
	 * @param d the value of the lower right element
	 */
	public Matrix2(double a, double b, double c, double d) {
		this.a = a;
		this.b = b;
		this.c = c;
		this.d = d;
		
	}
	
	/**
	 * Initializes this matrix so that it is equal to the specified matrix.
	 * @param other a matrix to copy
	 */
	public Matrix2(Matrix2 other) {
		this(other.a,other.b,other.c,other.d);
	}
	

	/**
	 * Returns the entry of this matrix located at the given one-based row and column indexes.
	 * 
	 * @param row the row index of the element
	 * @param col the column index of the element
	 * @return the element at the specified row and column indexes
	 * @throws IndexOutOfBoundsException if row is not 1 and not 2
	 * @throws IndexOutOfBoundsException if col is not 1 and not 2
	 */
	public double get(int row, int col) {
		if((row!=2&&row!=1)||(col!=1&&col!=2)) {
			throw new IndexOutOfBoundsException();
		}
		if(row == 1) {
			if(col==1) {
				return this.a;
			} else {
				return this.b;
			}
		} else {
			if(col==1) {
				return this.c;
			} else {
				return this.d;
			}
		}
		
	}
	/**
	 * Sets the entry of this matrix located at the given zero-based
	 * row and column indexes to the specified value
	 * 
	 * @param row the row index of the element
	 * @param col the column index of the element
	 * @param val the element to store in this matrix
	 * @return a reference to this matrix
	 * @throws IndexOutOfBoundsException if row is not 0 and not 1
	 * @throws IndexOutOfBoundsException if col is not 0 and not 1
	 */
	public Matrix2 set(int row, int col, double val) {
		if((row!=1&&row!=0)||(col!=0&&col!=1)) {
			throw new IndexOutOfBoundsException();
		}
		if(row == 0) {
			if(col==0) {
				this.a = val;
			} else {
				this.b = val;
			}
		} else {
			if(col==0) {
				this.c = val;
			} else {
				this.d = val;
			}
		}
		return this;
	}
	/**
	 * Postmultiply this matrix with the specified column vector returning a new vector.
	 * 
	 * <p>
	 * {@code w = A.mult(v)} is equivalent to the mathematical equation {@code w = Av}
	 * where {@code v} and {@code w} are 2x1 column vectors.
	 * 
	 * @param v a 2x1 vector
	 * @return a 2x1 vector equal to this matrix times {@code v}
	 */
	public Vector2 mult(Vector2 v) {
		Vector2 w = new Vector2();
		w.set(this.a*v.x()+this.b*v.y(), this.c*v.x()+this.d*v.y());
		return w;
	}
	/**
	 * Postmultiply this matrix with the specified matrix returning a new matrix.
	 * 
	 * <p>
	 * {@code C = A.mult(B)} is equivalent to the mathematical equation {@code C = AB}
	 * 
	 * @param m a 2x2 matrix
	 * @return a 2x2 matrix equal to this matrix times {@code m}
	 */
	public Matrix2 mult(Matrix2 m) {
		Matrix2 C = new Matrix2();
		C.set(0, 0, this.a*m.get(1,1)+this.b*m.get(2, 1));
		C.set(0, 1, this.a*m.get(1,2)+this.b*m.get(2, 2));
		C.set(1, 0, this.c*m.get(1,1)+this.d*m.get(2, 1));
		C.set(1, 1, this.c*m.get(1,2)+this.d*m.get(2, 2));
		return C;
	}
	/**
	 * Returns the determinant of this matrix.
	 * 
	 * @return the determinant of this matrix
	 */
	public double det() {
		double det = this.a*this.d-this.b*this.c;
		return det;
	}
	/**
	 * Returns the inverse of this matrix if the determinant of this matrix is not
	 * exactly zero.
	 * 
	 * @return a string representation of this matrix
	 * 
	 * @throws ArithmeticException if the determinant of this matrix is exactly zero
	 */
	public Matrix2 inv() {
		if(this.det()==0) {
			throw new ArithmeticException();
		}
		double d = 1/(this.det());
		Matrix2 inv = new Matrix2();
		inv.set(0, 0, this.d*d);
		inv.set(0, 1, -this.b*d);
		inv.set(1, 0, -this.c*d);
		inv.set(1, 1, this.a*d);
		return inv;
	}
	/**
	 * Returns a string representation of this matrix. The returned string
	 * has the following form:
	 * 
	 * <pre>
	 * [a, b]
	 * [c, d]
	 * </pre>
	 * 
	 * <p>
	 * where {@code a}, {@code b}, {@code c}, and {@code d} are the {@code double}
	 * values of the entries of this matrix.
	 * 
	 * @return a string representation of this matrix
	 */
	@Override
	public String toString() {
		String str = "["+this.a+", "+this.b+"]\n["+this.c+", "+this.d+"]";
		return str;
	}
} 

