package a3;

import static org.junit.Assert.*;
import ca.queensu.cs.cisc124.notes.basics.geometry.Vector2;
import org.junit.Test;

public class Matrix2Test {

	@Test
	public void test01_ctor() {
		// expected matrix values
		double expA = 1.5;
		double expB = -1.5;
		double expC = 2.5;
		double expD = 3.0;

		// call constructor
		Matrix2 mat = new Matrix2(expA, expB, expC, expD);

		// test for equality
		double tol = 1e-9;
		assertEquals(expA, mat.get(1, 1), tol);
		assertEquals(expB, mat.get(1, 2), tol);
		assertEquals(expC, mat.get(2, 1), tol);
		assertEquals(expD, mat.get(2, 2), tol);
	}

	@Test
	public void test02_copyCtor() {
		// expected matrix values
		double expA = 1.5;
		double expB = -1.5;
		double expC = 2.5;
		double expD = 3.0;

		// matrix to copy
		Matrix2 mat = new Matrix2(expA, expB, expC, expD);

		// call copy constructor to make a copy of mat
		Matrix2 matCopy = new Matrix2(mat);

		// test for equality
		double tol = 1e-9;
		assertEquals(mat.get(1, 1), matCopy.get(1,1), tol);
		assertEquals(mat.get(1, 2), matCopy.get(1,2), tol);
		assertEquals(mat.get(2, 1), matCopy.get(2,1), tol);
		assertEquals(mat.get(2, 2), matCopy.get(2,2), tol);
	}

	@Test
	public void test03a_set() {
		// expected matrix values
		double expA = 1.5;
		double expB = -1.5;
		double expC = 2.5;
		double expD = 3.0;

		// matrix on which to call set
		Matrix2 mat = new Matrix2(expA, expB, expC, 100.0);

		// call set to set bottom-right matrix entry to expD
		mat.set(1, 1, expD);

		// test for equality
		double tol = 1e-9;
		assertEquals(mat.get(2, 2),expD,tol);
	}

	@Test
	public void test03b_set() {
		// matrix on which to call set
		Matrix2 mat = new Matrix2();
		
		// call set setting any entry or entries of mat
		Matrix2 matC = mat.set(0, 0, 0);
		
		// test that reference returned by set points to the same object as mat
		assertEquals(mat,matC);
	}

	@Test
	public void test04_multVector2() {
		// expected vector result
		Vector2 vexp = new Vector2(2,2);
		
		// vector and matrix to call
		Matrix2 mat = new Matrix2(1,1,1,1);
		Vector2 v = new Vector2(1,1);
		
		// call mult and record returned vector
		Vector2 vfin = mat.mult(v);
		
		// test if returned value is the same as expected
		assertEquals(vfin,vexp);
		
	}

}
