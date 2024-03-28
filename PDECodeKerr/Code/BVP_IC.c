#include "BVP_header.h"

int BVP_GENIC(struct param_type *params, double x[], double y[], double Psi[], double GRIDdx[], double GRIDdy[])
{
	int i,j,k,l, status;
	const int n = (*params).nparam;
	const int m = (*params).mparam;
	const int p = (*params).pparam;
	const int N = (*params).Nparam;
	const int r = (*params).rparam;
	const int nnzJac = (*params).nnzparam;
	const double tol = (*params).tolparam;
	const double r_H = (*params).r_Hparam;
	const double M = (*params).Mparam;
	const double chi = (*params).chiparam;
	const double ICchi = (*params).ICchiparam;

	int pn;
	double xk, yk;

	FILE *infile;
	double temp0,temp1,temp2,temp3,temp4,temp5;
	double *xGrid;
	xGrid = (double*)calloc(n*m, sizeof(double));
	if (!xGrid)
		status = -1;
  double *yGrid;
  yGrid = (double*)calloc(n*m, sizeof(double));
	if (!yGrid)
		status = -1;


		//Generate IC
		printf("Generating IC with delta = %.4f.\n",ICchi);
		for (i = 0; i < m; ++i)
		{
			y[i] = ((double) i/(m-1)) * (M_PI/2.0); //0 < y < M_PI/2
			yk = y[i];
			for (j = 0; j < n; ++j)
			{
				x[j] = ((double) j/(n-1));
				xk = x[j];
				k = (i*n+j)*p;
				pn = 0;
				Psi[k +pn] = IC0out(xk, yk, r_H, M,  ICchi);

				pn = 1;
				Psi[k +pn] = IC1out(xk, yk, r_H, M,  ICchi);

				pn = 2;
				Psi[k +pn] = IC2out(xk, yk, r_H, M, ICchi);

				pn = 3;
				Psi[k +pn] = IC3out(xk, yk, r_H, M,  ICchi);

				pn = 4;
				Psi[k +pn] = IC4out(xk, yk, r_H, M, ICchi);

				pn = 5;
				Psi[k +pn] = IC5out(xk, yk, r_H, M, ICchi);

				pn = 6;
				Psi[k +pn] = IC6out(xk, yk, r_H, M, ICchi);

				pn = 7;
				Psi[k +pn] = IC7out(xk, yk, r_H, M,ICchi);

			}
		}


	//Calculate uniform grid x dimension
	for (j = 0; j < n; ++j)
	{
		if (j == 0)
		{
			GRIDdx[j] = (x[j+1] - x[j]);
		}
		else if (j == n-1)
		{
			GRIDdx[j] = (x[j] - x[j-1]);
		}
		else
		{
			GRIDdx[j] = (x[j+1] - x[j-1])/2.0;
		}
	}
	//Calculate uniform grid y dimension
	for (i = 0; i < m; ++i)
	{
		if (i == 0)
		{
			GRIDdy[i] = (y[i+1] - y[i]);
		}
		else if (i == m-1)
		{
			GRIDdy[i] = (y[i] - y[i-1]);
		}
		else
		{
			GRIDdy[i] = (y[i+1] - y[i-1])/2.0;
		}
	}


	//Cleanup
	free(xGrid);
	free(yGrid);


	return 0;
}
