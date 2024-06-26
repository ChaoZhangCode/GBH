/*
 *Andrew Sullivan
 *Montana State University
 *Newton-Rapson method for solving PDE BVP in 2D as coupled system
 *Procedure:
 *Notes:
 *precision - double
 */

#include "BVP_header.h"

int main(int argc, char *argv[])
{
	int i,j,k,l, status;
	//External Input
	const int p = atoi(argv[1]); //Number of field equations. Will always be twice the number of fields due to mixed derivatives
	int n = atoi(argv[2]); //x grid size
	int m = atoi(argv[3]); //theta grid size
	const int r = atoi(argv[4]); //Newton polynomial order
	const double tol = pow(10.0,atof(argv[5])); //absolute tolerance of solver
	const double r_H = atof(argv[6]); //rH value
	const double chi = atof(argv[7]); //dimensionless spin parameter
	const double ICchi = atof(argv[8]); //spin of intial guess
	const int plotvar = atoi(argv[9]); //1 to output each iteration. 0 for only solution

	//const double M = r_H/2.0/sqrt(1.0-pow(chi,2.0)); //bare mass calculated from spin and rH
	const int linsolvar = 0;//atoi(argv[7]); //Linear solver type. See BVP_LSsolver.c
	const double M = 2.0*r_H/sqrt(1.0-pow(chi,2.0)); //bare mass calculated from spin and rH
	const double a = chi*M; //spin
	int N = n*m*p; //total grid size

	//Print statements
	printf("\nRunning BVP with tol = %8.1e, order r = %2i.\n",tol,r);
	printf("Grid size nxm = %3i x %3i. Total pts = %i.\n",n,m,N);
	printf("Black hole parameters are r_H = %5.2f [Msun]. M = %5.2f [Msun].\n",r_H,M);
	printf("Chi = a/M = %5.2f []. a = %5.2f [Msun].\n",chi,a);
	printf("ICchi = %.3f.\n",ICchi);


	//Executable
	status = BVP_main(plotvar, linsolvar, r, n, m, p, N, tol, chi, r_H, M, ICchi);
	if (status != 0)
	{
		printf("ERROR in BVP. status = %i.\n",status);
	}
	printf("End of BVP.\n");

	return 0;
}
