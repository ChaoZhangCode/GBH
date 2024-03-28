#include "Decl_JSFuncs.c"

int CodeGen_JacNNZ(FILE *outfile, int FEn, int maxderiv, int i)
{
	int j,k, status;
	
	//----- Jacobian structure -----
	int dFE0d0dX0, dFE0d0d0X;
	int dFE0d1dX0, dFE0d1d0X;
	int dFE0d2dX0, dFE0d2d0X;
	int dFE0d3dX0, dFE0d3d0X;
	int dFE0d4dX0, dFE0d4d0X;
	int dFE0d5dX0, dFE0d5d0X;
	int dFE0d6dX0, dFE0d6d0X;
	int dFE0d7dX0, dFE0d7d0X;
	
	int dFE1d0dX0, dFE1d0d0X;
	int dFE1d1dX0, dFE1d1d0X;
	int dFE1d2dX0, dFE1d2d0X;
	int dFE1d3dX0, dFE1d3d0X;
	int dFE1d4dX0, dFE1d4d0X;
	int dFE1d5dX0, dFE1d5d0X;
	int dFE1d6dX0, dFE1d6d0X;
	int dFE1d7dX0, dFE1d7d0X;
	
	int dFE2d0dX0, dFE2d0d0X;
	int dFE2d1dX0, dFE2d1d0X;
	int dFE2d2dX0, dFE2d2d0X;
	int dFE2d3dX0, dFE2d3d0X;
	int dFE2d4dX0, dFE2d4d0X;
	int dFE2d5dX0, dFE2d5d0X;
	int dFE2d6dX0, dFE2d6d0X;
	int dFE2d7dX0, dFE2d7d0X;
	
	int dFE3d0dX0, dFE3d0d0X;
	int dFE3d1dX0, dFE3d1d0X;
	int dFE3d2dX0, dFE3d2d0X;
	int dFE3d3dX0, dFE3d3d0X;
	int dFE3d4dX0, dFE3d4d0X;
	int dFE3d5dX0, dFE3d5d0X;
	int dFE3d6dX0, dFE3d6d0X;
	int dFE3d7dX0, dFE3d7d0X;
	
	int dFE4d0dX0, dFE4d0d0X;
	int dFE4d1dX0, dFE4d1d0X;
	int dFE4d2dX0, dFE4d2d0X;
	int dFE4d3dX0, dFE4d3d0X;
	int dFE4d4dX0, dFE4d4d0X;
	int dFE4d5dX0, dFE4d5d0X;
	int dFE4d6dX0, dFE4d6d0X;
	int dFE4d7dX0, dFE4d7d0X;
	
	int dFE5d0dX0, dFE5d0d0X;
	int dFE5d1dX0, dFE5d1d0X;
	int dFE5d2dX0, dFE5d2d0X;
	int dFE5d3dX0, dFE5d3d0X;
	int dFE5d4dX0, dFE5d4d0X;
	int dFE5d5dX0, dFE5d5d0X;
	int dFE5d6dX0, dFE5d6d0X;
	int dFE5d7dX0, dFE5d7d0X;
	
	int dFE6d0dX0, dFE6d0d0X;
	int dFE6d1dX0, dFE6d1d0X;
	int dFE6d2dX0, dFE6d2d0X;
	int dFE6d3dX0, dFE6d3d0X;
	int dFE6d4dX0, dFE6d4d0X;
	int dFE6d5dX0, dFE6d5d0X;
	int dFE6d6dX0, dFE6d6d0X;
	int dFE6d7dX0, dFE6d7d0X;
	
	int dFE7d0dX0, dFE7d0d0X;
	int dFE7d1dX0, dFE7d1d0X;
	int dFE7d2dX0, dFE7d2d0X;
	int dFE7d3dX0, dFE7d3d0X;
	int dFE7d4dX0, dFE7d4d0X;
	int dFE7d5dX0, dFE7d5d0X;
	int dFE7d6dX0, dFE7d6d0X;
	int dFE7d7dX0, dFE7d7d0X;
	
	//-------------------- i = 0 --------------------
	if (i == 0)
	{
		dFE0d0dX0 = dFE0d0dX0out();
		dFE0d0d0X = dFE0d0d0Xout();
		
		dFE0d1dX0 = dFE0d1dX0out();
		dFE0d1d0X = dFE0d1d0Xout();
		
		dFE0d2dX0 = dFE0d2dX0out();
		dFE0d2d0X = dFE0d2d0Xout();
		
		dFE0d3dX0 = dFE0d3dX0out();
		dFE0d3d0X = dFE0d3d0Xout();
		
		dFE0d4dX0 = dFE0d4dX0out();
		dFE0d4d0X = dFE0d4d0Xout();
		
		dFE0d5dX0 = dFE0d5dX0out();
		dFE0d5d0X = dFE0d5d0Xout();
		
		dFE0d6dX0 = dFE0d6dX0out();
		dFE0d6d0X = dFE0d6d0Xout();
		
		dFE0d7dX0 = dFE0d7dX0out();
		dFE0d7d0X = dFE0d7d0Xout();
		
		fprintf(outfile,"			//-------------------------------------------------------\n");
		fprintf(outfile,"			pn = %i;\n",0);
		fprintf(outfile,"			\n");
		
		fprintf(outfile,"			for (a = 0; a <= r+onexside; ++a)\n");
		fprintf(outfile,"			{\n");
		if (dFE0d0dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",0,0,k,0,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",0);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE0d1dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",0,1,k,1,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",1);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE0d2dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",0,2,k,2,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",2);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE0d3dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",0,3,k,3,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",3);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE0d4dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",0,4,k,4,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",4);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE0d5dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",0,5,k,5,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",5);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE0d6dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",0,6,k,6,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",6);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE0d7dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",0,7,k,7,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",7);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		fprintf(outfile,"			}\n");
		
		fprintf(outfile,"			for (b = 0; b <= r+oneyside; ++b)\n");
		fprintf(outfile,"			{\n");
		if (dFE0d0d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",0,0,k,0,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",0);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE0d1d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",0,1,k,1,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",1);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE0d2d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",0,2,k,2,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",2);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE0d3d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",0,3,k,3,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",3);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE0d4d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",0,4,k,4,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",4);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE0d5d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",0,5,k,5,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",5);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE0d6d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",0,6,k,6,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",6);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE0d7d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",0,7,k,7,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",7);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		fprintf(outfile,"			}\n");
		fprintf(outfile,"			\n");
		
	}
	//-------------------- i = 1 --------------------
	else if (i == 1)
	{
		dFE1d0dX0 = dFE1d0dX0out();
		dFE1d0d0X = dFE1d0d0Xout();
		
		dFE1d1dX0 = dFE1d1dX0out();
		dFE1d1d0X = dFE1d1d0Xout();
		
		dFE1d2dX0 = dFE1d2dX0out();
		dFE1d2d0X = dFE1d2d0Xout();
		
		dFE1d3dX0 = dFE1d3dX0out();
		dFE1d3d0X = dFE1d3d0Xout();
		
		dFE1d4dX0 = dFE1d4dX0out();
		dFE1d4d0X = dFE1d4d0Xout();
		
		dFE1d5dX0 = dFE1d5dX0out();
		dFE1d5d0X = dFE1d5d0Xout();
		
		dFE1d6dX0 = dFE1d6dX0out();
		dFE1d6d0X = dFE1d6d0Xout();
		
		dFE1d7dX0 = dFE1d7dX0out();
		dFE1d7d0X = dFE1d7d0Xout();
		
		fprintf(outfile,"			//-------------------------------------------------------\n");
		fprintf(outfile,"			pn = %i;\n",1);
		fprintf(outfile,"			\n");
		
		fprintf(outfile,"			for (a = 0; a <= r+onexside; ++a)\n");
		fprintf(outfile,"			{\n");
		if (dFE1d0dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",1,0,k,0,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",0);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE1d1dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",1,1,k,1,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",1);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE1d2dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",1,2,k,2,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",2);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE1d3dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",1,3,k,3,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",3);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE1d4dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",1,4,k,4,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",4);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE1d5dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",1,5,k,5,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",5);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE1d6dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",1,6,k,6,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",6);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE1d7dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",1,7,k,7,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",7);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		fprintf(outfile,"			}\n");
		
		fprintf(outfile,"			for (b = 0; b <= r+oneyside; ++b)\n");
		fprintf(outfile,"			{\n");
		if (dFE1d0d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",1,0,k,0,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",0);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE1d1d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",1,1,k,1,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",1);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE1d2d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",1,2,k,2,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",2);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE1d3d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",1,3,k,3,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",3);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE1d4d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",1,4,k,4,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",4);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE1d5d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",1,5,k,5,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",5);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE1d6d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",1,6,k,6,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",6);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE1d7d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",1,7,k,7,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",7);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		fprintf(outfile,"			}\n");
		fprintf(outfile,"			\n");
		
	}
	//-------------------- i = 2 --------------------
	else if (i == 2)
	{
		dFE2d0dX0 = dFE2d0dX0out();
		dFE2d0d0X = dFE2d0d0Xout();
		
		dFE2d1dX0 = dFE2d1dX0out();
		dFE2d1d0X = dFE2d1d0Xout();
		
		dFE2d2dX0 = dFE2d2dX0out();
		dFE2d2d0X = dFE2d2d0Xout();
		
		dFE2d3dX0 = dFE2d3dX0out();
		dFE2d3d0X = dFE2d3d0Xout();
		
		dFE2d4dX0 = dFE2d4dX0out();
		dFE2d4d0X = dFE2d4d0Xout();
		
		dFE2d5dX0 = dFE2d5dX0out();
		dFE2d5d0X = dFE2d5d0Xout();
		
		dFE2d6dX0 = dFE2d6dX0out();
		dFE2d6d0X = dFE2d6d0Xout();
		
		dFE2d7dX0 = dFE2d7dX0out();
		dFE2d7d0X = dFE2d7d0Xout();
		
		fprintf(outfile,"			//-------------------------------------------------------\n");
		fprintf(outfile,"			pn = %i;\n",2);
		fprintf(outfile,"			\n");
		
		fprintf(outfile,"			for (a = 0; a <= r+onexside; ++a)\n");
		fprintf(outfile,"			{\n");
		if (dFE2d0dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",2,0,k,0,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",0);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE2d1dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",2,1,k,1,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",1);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE2d2dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",2,2,k,2,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",2);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE2d3dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",2,3,k,3,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",3);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE2d4dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",2,4,k,4,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",4);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE2d5dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",2,5,k,5,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",5);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE2d6dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",2,6,k,6,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",6);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE2d7dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",2,7,k,7,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",7);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		fprintf(outfile,"			}\n");
		
		fprintf(outfile,"			for (b = 0; b <= r+oneyside; ++b)\n");
		fprintf(outfile,"			{\n");
		if (dFE2d0d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",2,0,k,0,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",0);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE2d1d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",2,1,k,1,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",1);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE2d2d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",2,2,k,2,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",2);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE2d3d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",2,3,k,3,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",3);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE2d4d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",2,4,k,4,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",4);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE2d5d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",2,5,k,5,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",5);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE2d6d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",2,6,k,6,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",6);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE2d7d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",2,7,k,7,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",7);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		fprintf(outfile,"			}\n");
		fprintf(outfile,"			\n");
		
	}
	//-------------------- i = 3 --------------------
	else if (i == 3)
	{
		dFE3d0dX0 = dFE3d0dX0out();
		dFE3d0d0X = dFE3d0d0Xout();
		
		dFE3d1dX0 = dFE3d1dX0out();
		dFE3d1d0X = dFE3d1d0Xout();
		
		dFE3d2dX0 = dFE3d2dX0out();
		dFE3d2d0X = dFE3d2d0Xout();
		
		dFE3d3dX0 = dFE3d3dX0out();
		dFE3d3d0X = dFE3d3d0Xout();
		
		dFE3d4dX0 = dFE3d4dX0out();
		dFE3d4d0X = dFE3d4d0Xout();
		
		dFE3d5dX0 = dFE3d5dX0out();
		dFE3d5d0X = dFE3d5d0Xout();
		
		dFE3d6dX0 = dFE3d6dX0out();
		dFE3d6d0X = dFE3d6d0Xout();
		
		dFE3d7dX0 = dFE3d7dX0out();
		dFE3d7d0X = dFE3d7d0Xout();
		
		fprintf(outfile,"			//-------------------------------------------------------\n");
		fprintf(outfile,"			pn = %i;\n",3);
		fprintf(outfile,"			\n");
		
		fprintf(outfile,"			for (a = 0; a <= r+onexside; ++a)\n");
		fprintf(outfile,"			{\n");
		if (dFE3d0dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",3,0,k,0,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",0);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE3d1dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",3,1,k,1,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",1);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE3d2dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",3,2,k,2,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",2);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE3d3dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",3,3,k,3,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",3);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE3d4dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",3,4,k,4,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",4);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE3d5dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",3,5,k,5,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",5);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE3d6dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",3,6,k,6,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",6);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE3d7dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",3,7,k,7,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",7);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		fprintf(outfile,"			}\n");
		
		fprintf(outfile,"			for (b = 0; b <= r+oneyside; ++b)\n");
		fprintf(outfile,"			{\n");
		if (dFE3d0d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",3,0,k,0,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",0);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE3d1d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",3,1,k,1,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",1);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE3d2d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",3,2,k,2,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",2);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE3d3d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",3,3,k,3,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",3);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE3d4d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",3,4,k,4,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",4);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE3d5d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",3,5,k,5,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",5);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE3d6d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",3,6,k,6,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",6);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE3d7d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",3,7,k,7,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",7);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		fprintf(outfile,"			}\n");
		fprintf(outfile,"			\n");
		
	}
	//-------------------- i = 4 --------------------
	else if (i == 4)
	{
		dFE4d0dX0 = dFE4d0dX0out();
		dFE4d0d0X = dFE4d0d0Xout();
		
		dFE4d1dX0 = dFE4d1dX0out();
		dFE4d1d0X = dFE4d1d0Xout();
		
		dFE4d2dX0 = dFE4d2dX0out();
		dFE4d2d0X = dFE4d2d0Xout();
		
		dFE4d3dX0 = dFE4d3dX0out();
		dFE4d3d0X = dFE4d3d0Xout();
		
		dFE4d4dX0 = dFE4d4dX0out();
		dFE4d4d0X = dFE4d4d0Xout();
		
		dFE4d5dX0 = dFE4d5dX0out();
		dFE4d5d0X = dFE4d5d0Xout();
		
		dFE4d6dX0 = dFE4d6dX0out();
		dFE4d6d0X = dFE4d6d0Xout();
		
		dFE4d7dX0 = dFE4d7dX0out();
		dFE4d7d0X = dFE4d7d0Xout();
		
		fprintf(outfile,"			//-------------------------------------------------------\n");
		fprintf(outfile,"			pn = %i;\n",4);
		fprintf(outfile,"			\n");
		
		fprintf(outfile,"			for (a = 0; a <= r+onexside; ++a)\n");
		fprintf(outfile,"			{\n");
		if (dFE4d0dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",4,0,k,0,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",0);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE4d1dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",4,1,k,1,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",1);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE4d2dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",4,2,k,2,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",2);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE4d3dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",4,3,k,3,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",3);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE4d4dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",4,4,k,4,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",4);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE4d5dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",4,5,k,5,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",5);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE4d6dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",4,6,k,6,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",6);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE4d7dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",4,7,k,7,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",7);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		fprintf(outfile,"			}\n");
		
		fprintf(outfile,"			for (b = 0; b <= r+oneyside; ++b)\n");
		fprintf(outfile,"			{\n");
		if (dFE4d0d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",4,0,k,0,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",0);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE4d1d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",4,1,k,1,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",1);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE4d2d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",4,2,k,2,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",2);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE4d3d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",4,3,k,3,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",3);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE4d4d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",4,4,k,4,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",4);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE4d5d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",4,5,k,5,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",5);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE4d6d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",4,6,k,6,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",6);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE4d7d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",4,7,k,7,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",7);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		fprintf(outfile,"			}\n");
		fprintf(outfile,"			\n");
		
	}
	//-------------------- i = 5 --------------------
	else if (i == 5)
	{
		dFE5d0dX0 = dFE5d0dX0out();
		dFE5d0d0X = dFE5d0d0Xout();
		
		dFE5d1dX0 = dFE5d1dX0out();
		dFE5d1d0X = dFE5d1d0Xout();
		
		dFE5d2dX0 = dFE5d2dX0out();
		dFE5d2d0X = dFE5d2d0Xout();
		
		dFE5d3dX0 = dFE5d3dX0out();
		dFE5d3d0X = dFE5d3d0Xout();
		
		dFE5d4dX0 = dFE5d4dX0out();
		dFE5d4d0X = dFE5d4d0Xout();
		
		dFE5d5dX0 = dFE5d5dX0out();
		dFE5d5d0X = dFE5d5d0Xout();
		
		dFE5d6dX0 = dFE5d6dX0out();
		dFE5d6d0X = dFE5d6d0Xout();
		
		dFE5d7dX0 = dFE5d7dX0out();
		dFE5d7d0X = dFE5d7d0Xout();
		
		fprintf(outfile,"			//-------------------------------------------------------\n");
		fprintf(outfile,"			pn = %i;\n",5);
		fprintf(outfile,"			\n");
		
		fprintf(outfile,"			for (a = 0; a <= r+onexside; ++a)\n");
		fprintf(outfile,"			{\n");
		if (dFE5d0dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",5,0,k,0,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",0);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE5d1dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",5,1,k,1,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",1);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE5d2dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",5,2,k,2,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",2);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE5d3dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",5,3,k,3,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",3);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE5d4dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",5,4,k,4,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",4);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE5d5dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",5,5,k,5,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",5);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE5d6dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",5,6,k,6,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",6);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE5d7dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",5,7,k,7,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",7);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		fprintf(outfile,"			}\n");
		
		fprintf(outfile,"			for (b = 0; b <= r+oneyside; ++b)\n");
		fprintf(outfile,"			{\n");
		if (dFE5d0d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",5,0,k,0,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",0);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE5d1d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",5,1,k,1,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",1);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE5d2d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",5,2,k,2,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",2);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE5d3d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",5,3,k,3,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",3);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE5d4d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",5,4,k,4,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",4);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE5d5d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",5,5,k,5,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",5);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE5d6d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",5,6,k,6,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",6);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE5d7d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",5,7,k,7,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",7);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		fprintf(outfile,"			}\n");
		fprintf(outfile,"			\n");
		
	}
	//-------------------- i = 6 --------------------
	else if (i == 6)
	{
		dFE6d0dX0 = dFE6d0dX0out();
		dFE6d0d0X = dFE6d0d0Xout();
		
		dFE6d1dX0 = dFE6d1dX0out();
		dFE6d1d0X = dFE6d1d0Xout();
		
		dFE6d2dX0 = dFE6d2dX0out();
		dFE6d2d0X = dFE6d2d0Xout();
		
		dFE6d3dX0 = dFE6d3dX0out();
		dFE6d3d0X = dFE6d3d0Xout();
		
		dFE6d4dX0 = dFE6d4dX0out();
		dFE6d4d0X = dFE6d4d0Xout();
		
		dFE6d5dX0 = dFE6d5dX0out();
		dFE6d5d0X = dFE6d5d0Xout();
		
		dFE6d6dX0 = dFE6d6dX0out();
		dFE6d6d0X = dFE6d6d0Xout();
		
		dFE6d7dX0 = dFE6d7dX0out();
		dFE6d7d0X = dFE6d7d0Xout();
		
		fprintf(outfile,"			//-------------------------------------------------------\n");
		fprintf(outfile,"			pn = %i;\n",6);
		fprintf(outfile,"			\n");
		
		fprintf(outfile,"			for (a = 0; a <= r+onexside; ++a)\n");
		fprintf(outfile,"			{\n");
		if (dFE6d0dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",6,0,k,0,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",0);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE6d1dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",6,1,k,1,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",1);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE6d2dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",6,2,k,2,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",2);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE6d3dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",6,3,k,3,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",3);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE6d4dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",6,4,k,4,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",4);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE6d5dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",6,5,k,5,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",5);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE6d6dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",6,6,k,6,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",6);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE6d7dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",6,7,k,7,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",7);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		fprintf(outfile,"			}\n");
		
		fprintf(outfile,"			for (b = 0; b <= r+oneyside; ++b)\n");
		fprintf(outfile,"			{\n");
		if (dFE6d0d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",6,0,k,0,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",0);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE6d1d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",6,1,k,1,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",1);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE6d2d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",6,2,k,2,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",2);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE6d3d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",6,3,k,3,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",3);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE6d4d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",6,4,k,4,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",4);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE6d5d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",6,5,k,5,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",5);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE6d6d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",6,6,k,6,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",6);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE6d7d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",6,7,k,7,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",7);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		fprintf(outfile,"			}\n");
		fprintf(outfile,"			\n");
		
	}
	//-------------------- i = 7 --------------------
	else if (i == 7)
	{
		dFE7d0dX0 = dFE7d0dX0out();
		dFE7d0d0X = dFE7d0d0Xout();
		
		dFE7d1dX0 = dFE7d1dX0out();
		dFE7d1d0X = dFE7d1d0Xout();
		
		dFE7d2dX0 = dFE7d2dX0out();
		dFE7d2d0X = dFE7d2d0Xout();
		
		dFE7d3dX0 = dFE7d3dX0out();
		dFE7d3d0X = dFE7d3d0Xout();
		
		dFE7d4dX0 = dFE7d4dX0out();
		dFE7d4d0X = dFE7d4d0Xout();
		
		dFE7d5dX0 = dFE7d5dX0out();
		dFE7d5d0X = dFE7d5d0Xout();
		
		dFE7d6dX0 = dFE7d6dX0out();
		dFE7d6d0X = dFE7d6d0Xout();
		
		dFE7d7dX0 = dFE7d7dX0out();
		dFE7d7d0X = dFE7d7d0Xout();
		
		fprintf(outfile,"			//-------------------------------------------------------\n");
		fprintf(outfile,"			pn = %i;\n",7);
		fprintf(outfile,"			\n");
		
		fprintf(outfile,"			for (a = 0; a <= r+onexside; ++a)\n");
		fprintf(outfile,"			{\n");
		if (dFE7d0dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",7,0,k,0,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",0);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE7d1dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",7,1,k,1,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",1);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE7d2dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",7,2,k,2,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",2);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE7d3dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",7,3,k,3,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",3);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE7d4dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",7,4,k,4,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",4);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE7d5dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",7,5,k,5,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",5);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE7d6dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",7,6,k,6,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",6);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE7d7dX0 != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 0; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id%i0*a%id%i[a]",7,7,k,7,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",7);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		fprintf(outfile,"			}\n");
		
		fprintf(outfile,"			for (b = 0; b <= r+oneyside; ++b)\n");
		fprintf(outfile,"			{\n");
		if (dFE7d0d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",7,0,k,0,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",0);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE7d1d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",7,1,k,1,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",1);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE7d2d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",7,2,k,2,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",2);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE7d3d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",7,3,k,3,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",3);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE7d4d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",7,4,k,4,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",4);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE7d5d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",7,5,k,5,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",5);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE7d6d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",7,6,k,6,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",6);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		if (dFE7d7d0X != 0)
		{
			fprintf(outfile,"				JacVal[nnztemp] = ");
			for (k = 1; k <= maxderiv; ++k)
			{
				fprintf(outfile,"dFE%id%id0%i*b%id%i[b]",7,7,k,7,k);
				if (k != maxderiv)
				{
					fprintf(outfile," + ");
				}
			}
			fprintf(outfile,";\n");
			fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
			fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",7);
			fprintf(outfile,"				nnztemp += 1;\n");
			fprintf(outfile,"				\n");
		}
		fprintf(outfile,"			}\n");
		fprintf(outfile,"			\n");
		
	}
	else
	{
		printf("ERROR!! In CodeGen_NNZ.c, %i does not match number of field equations.\n",i);
		return -1;
	}
	
	
	return 0;
}

int CodeGen_BCNNZ(FILE *outfile, int FEn, int maxderiv, int i, int bc)
{
	int j,k, status;
	const char BCdim[5] = "XXYY";
	const int BCloc[4] = {0,1,1,0};
	const int BClength = 4;
	
	//----- Boundary structure -----
	//BC X0
	int dBC0X0d0dX0, dBC0X0d0d0X;
	int dBC0X0d1dX0, dBC0X0d1d0X;
	int dBC0X0d2dX0, dBC0X0d2d0X;
	int dBC0X0d3dX0, dBC0X0d3d0X;
	int dBC0X0d4dX0, dBC0X0d4d0X;
	int dBC0X0d5dX0, dBC0X0d5d0X;
	int dBC0X0d6dX0, dBC0X0d6d0X;
	int dBC0X0d7dX0, dBC0X0d7d0X;
	
	int dBC1X0d0dX0, dBC1X0d0d0X;
	int dBC1X0d1dX0, dBC1X0d1d0X;
	int dBC1X0d2dX0, dBC1X0d2d0X;
	int dBC1X0d3dX0, dBC1X0d3d0X;
	int dBC1X0d4dX0, dBC1X0d4d0X;
	int dBC1X0d5dX0, dBC1X0d5d0X;
	int dBC1X0d6dX0, dBC1X0d6d0X;
	int dBC1X0d7dX0, dBC1X0d7d0X;
	
	int dBC2X0d0dX0, dBC2X0d0d0X;
	int dBC2X0d1dX0, dBC2X0d1d0X;
	int dBC2X0d2dX0, dBC2X0d2d0X;
	int dBC2X0d3dX0, dBC2X0d3d0X;
	int dBC2X0d4dX0, dBC2X0d4d0X;
	int dBC2X0d5dX0, dBC2X0d5d0X;
	int dBC2X0d6dX0, dBC2X0d6d0X;
	int dBC2X0d7dX0, dBC2X0d7d0X;
	
	int dBC3X0d0dX0, dBC3X0d0d0X;
	int dBC3X0d1dX0, dBC3X0d1d0X;
	int dBC3X0d2dX0, dBC3X0d2d0X;
	int dBC3X0d3dX0, dBC3X0d3d0X;
	int dBC3X0d4dX0, dBC3X0d4d0X;
	int dBC3X0d5dX0, dBC3X0d5d0X;
	int dBC3X0d6dX0, dBC3X0d6d0X;
	int dBC3X0d7dX0, dBC3X0d7d0X;
	
	int dBC4X0d0dX0, dBC4X0d0d0X;
	int dBC4X0d1dX0, dBC4X0d1d0X;
	int dBC4X0d2dX0, dBC4X0d2d0X;
	int dBC4X0d3dX0, dBC4X0d3d0X;
	int dBC4X0d4dX0, dBC4X0d4d0X;
	int dBC4X0d5dX0, dBC4X0d5d0X;
	int dBC4X0d6dX0, dBC4X0d6d0X;
	int dBC4X0d7dX0, dBC4X0d7d0X;
	
	int dBC5X0d0dX0, dBC5X0d0d0X;
	int dBC5X0d1dX0, dBC5X0d1d0X;
	int dBC5X0d2dX0, dBC5X0d2d0X;
	int dBC5X0d3dX0, dBC5X0d3d0X;
	int dBC5X0d4dX0, dBC5X0d4d0X;
	int dBC5X0d5dX0, dBC5X0d5d0X;
	int dBC5X0d6dX0, dBC5X0d6d0X;
	int dBC5X0d7dX0, dBC5X0d7d0X;
	
	int dBC6X0d0dX0, dBC6X0d0d0X;
	int dBC6X0d1dX0, dBC6X0d1d0X;
	int dBC6X0d2dX0, dBC6X0d2d0X;
	int dBC6X0d3dX0, dBC6X0d3d0X;
	int dBC6X0d4dX0, dBC6X0d4d0X;
	int dBC6X0d5dX0, dBC6X0d5d0X;
	int dBC6X0d6dX0, dBC6X0d6d0X;
	int dBC6X0d7dX0, dBC6X0d7d0X;
	
	int dBC7X0d0dX0, dBC7X0d0d0X;
	int dBC7X0d1dX0, dBC7X0d1d0X;
	int dBC7X0d2dX0, dBC7X0d2d0X;
	int dBC7X0d3dX0, dBC7X0d3d0X;
	int dBC7X0d4dX0, dBC7X0d4d0X;
	int dBC7X0d5dX0, dBC7X0d5d0X;
	int dBC7X0d6dX0, dBC7X0d6d0X;
	int dBC7X0d7dX0, dBC7X0d7d0X;
	
	//BC X1
	int dBC0X1d0dX0, dBC0X1d0d0X;
	int dBC0X1d1dX0, dBC0X1d1d0X;
	int dBC0X1d2dX0, dBC0X1d2d0X;
	int dBC0X1d3dX0, dBC0X1d3d0X;
	int dBC0X1d4dX0, dBC0X1d4d0X;
	int dBC0X1d5dX0, dBC0X1d5d0X;
	int dBC0X1d6dX0, dBC0X1d6d0X;
	int dBC0X1d7dX0, dBC0X1d7d0X;
	
	int dBC1X1d0dX0, dBC1X1d0d0X;
	int dBC1X1d1dX0, dBC1X1d1d0X;
	int dBC1X1d2dX0, dBC1X1d2d0X;
	int dBC1X1d3dX0, dBC1X1d3d0X;
	int dBC1X1d4dX0, dBC1X1d4d0X;
	int dBC1X1d5dX0, dBC1X1d5d0X;
	int dBC1X1d6dX0, dBC1X1d6d0X;
	int dBC1X1d7dX0, dBC1X1d7d0X;
	
	int dBC2X1d0dX0, dBC2X1d0d0X;
	int dBC2X1d1dX0, dBC2X1d1d0X;
	int dBC2X1d2dX0, dBC2X1d2d0X;
	int dBC2X1d3dX0, dBC2X1d3d0X;
	int dBC2X1d4dX0, dBC2X1d4d0X;
	int dBC2X1d5dX0, dBC2X1d5d0X;
	int dBC2X1d6dX0, dBC2X1d6d0X;
	int dBC2X1d7dX0, dBC2X1d7d0X;
	
	int dBC3X1d0dX0, dBC3X1d0d0X;
	int dBC3X1d1dX0, dBC3X1d1d0X;
	int dBC3X1d2dX0, dBC3X1d2d0X;
	int dBC3X1d3dX0, dBC3X1d3d0X;
	int dBC3X1d4dX0, dBC3X1d4d0X;
	int dBC3X1d5dX0, dBC3X1d5d0X;
	int dBC3X1d6dX0, dBC3X1d6d0X;
	int dBC3X1d7dX0, dBC3X1d7d0X;
	
	int dBC4X1d0dX0, dBC4X1d0d0X;
	int dBC4X1d1dX0, dBC4X1d1d0X;
	int dBC4X1d2dX0, dBC4X1d2d0X;
	int dBC4X1d3dX0, dBC4X1d3d0X;
	int dBC4X1d4dX0, dBC4X1d4d0X;
	int dBC4X1d5dX0, dBC4X1d5d0X;
	int dBC4X1d6dX0, dBC4X1d6d0X;
	int dBC4X1d7dX0, dBC4X1d7d0X;
	
	int dBC5X1d0dX0, dBC5X1d0d0X;
	int dBC5X1d1dX0, dBC5X1d1d0X;
	int dBC5X1d2dX0, dBC5X1d2d0X;
	int dBC5X1d3dX0, dBC5X1d3d0X;
	int dBC5X1d4dX0, dBC5X1d4d0X;
	int dBC5X1d5dX0, dBC5X1d5d0X;
	int dBC5X1d6dX0, dBC5X1d6d0X;
	int dBC5X1d7dX0, dBC5X1d7d0X;
	
	int dBC6X1d0dX0, dBC6X1d0d0X;
	int dBC6X1d1dX0, dBC6X1d1d0X;
	int dBC6X1d2dX0, dBC6X1d2d0X;
	int dBC6X1d3dX0, dBC6X1d3d0X;
	int dBC6X1d4dX0, dBC6X1d4d0X;
	int dBC6X1d5dX0, dBC6X1d5d0X;
	int dBC6X1d6dX0, dBC6X1d6d0X;
	int dBC6X1d7dX0, dBC6X1d7d0X;
	
	int dBC7X1d0dX0, dBC7X1d0d0X;
	int dBC7X1d1dX0, dBC7X1d1d0X;
	int dBC7X1d2dX0, dBC7X1d2d0X;
	int dBC7X1d3dX0, dBC7X1d3d0X;
	int dBC7X1d4dX0, dBC7X1d4d0X;
	int dBC7X1d5dX0, dBC7X1d5d0X;
	int dBC7X1d6dX0, dBC7X1d6d0X;
	int dBC7X1d7dX0, dBC7X1d7d0X;
	
	//BC Y1
	int dBC0Y1d0dX0, dBC0Y1d0d0X;
	int dBC0Y1d1dX0, dBC0Y1d1d0X;
	int dBC0Y1d2dX0, dBC0Y1d2d0X;
	int dBC0Y1d3dX0, dBC0Y1d3d0X;
	int dBC0Y1d4dX0, dBC0Y1d4d0X;
	int dBC0Y1d5dX0, dBC0Y1d5d0X;
	int dBC0Y1d6dX0, dBC0Y1d6d0X;
	int dBC0Y1d7dX0, dBC0Y1d7d0X;
	
	int dBC1Y1d0dX0, dBC1Y1d0d0X;
	int dBC1Y1d1dX0, dBC1Y1d1d0X;
	int dBC1Y1d2dX0, dBC1Y1d2d0X;
	int dBC1Y1d3dX0, dBC1Y1d3d0X;
	int dBC1Y1d4dX0, dBC1Y1d4d0X;
	int dBC1Y1d5dX0, dBC1Y1d5d0X;
	int dBC1Y1d6dX0, dBC1Y1d6d0X;
	int dBC1Y1d7dX0, dBC1Y1d7d0X;
	
	int dBC2Y1d0dX0, dBC2Y1d0d0X;
	int dBC2Y1d1dX0, dBC2Y1d1d0X;
	int dBC2Y1d2dX0, dBC2Y1d2d0X;
	int dBC2Y1d3dX0, dBC2Y1d3d0X;
	int dBC2Y1d4dX0, dBC2Y1d4d0X;
	int dBC2Y1d5dX0, dBC2Y1d5d0X;
	int dBC2Y1d6dX0, dBC2Y1d6d0X;
	int dBC2Y1d7dX0, dBC2Y1d7d0X;
	
	int dBC3Y1d0dX0, dBC3Y1d0d0X;
	int dBC3Y1d1dX0, dBC3Y1d1d0X;
	int dBC3Y1d2dX0, dBC3Y1d2d0X;
	int dBC3Y1d3dX0, dBC3Y1d3d0X;
	int dBC3Y1d4dX0, dBC3Y1d4d0X;
	int dBC3Y1d5dX0, dBC3Y1d5d0X;
	int dBC3Y1d6dX0, dBC3Y1d6d0X;
	int dBC3Y1d7dX0, dBC3Y1d7d0X;
	
	int dBC4Y1d0dX0, dBC4Y1d0d0X;
	int dBC4Y1d1dX0, dBC4Y1d1d0X;
	int dBC4Y1d2dX0, dBC4Y1d2d0X;
	int dBC4Y1d3dX0, dBC4Y1d3d0X;
	int dBC4Y1d4dX0, dBC4Y1d4d0X;
	int dBC4Y1d5dX0, dBC4Y1d5d0X;
	int dBC4Y1d6dX0, dBC4Y1d6d0X;
	int dBC4Y1d7dX0, dBC4Y1d7d0X;
	
	int dBC5Y1d0dX0, dBC5Y1d0d0X;
	int dBC5Y1d1dX0, dBC5Y1d1d0X;
	int dBC5Y1d2dX0, dBC5Y1d2d0X;
	int dBC5Y1d3dX0, dBC5Y1d3d0X;
	int dBC5Y1d4dX0, dBC5Y1d4d0X;
	int dBC5Y1d5dX0, dBC5Y1d5d0X;
	int dBC5Y1d6dX0, dBC5Y1d6d0X;
	int dBC5Y1d7dX0, dBC5Y1d7d0X;
	
	int dBC6Y1d0dX0, dBC6Y1d0d0X;
	int dBC6Y1d1dX0, dBC6Y1d1d0X;
	int dBC6Y1d2dX0, dBC6Y1d2d0X;
	int dBC6Y1d3dX0, dBC6Y1d3d0X;
	int dBC6Y1d4dX0, dBC6Y1d4d0X;
	int dBC6Y1d5dX0, dBC6Y1d5d0X;
	int dBC6Y1d6dX0, dBC6Y1d6d0X;
	int dBC6Y1d7dX0, dBC6Y1d7d0X;
	
	int dBC7Y1d0dX0, dBC7Y1d0d0X;
	int dBC7Y1d1dX0, dBC7Y1d1d0X;
	int dBC7Y1d2dX0, dBC7Y1d2d0X;
	int dBC7Y1d3dX0, dBC7Y1d3d0X;
	int dBC7Y1d4dX0, dBC7Y1d4d0X;
	int dBC7Y1d5dX0, dBC7Y1d5d0X;
	int dBC7Y1d6dX0, dBC7Y1d6d0X;
	int dBC7Y1d7dX0, dBC7Y1d7d0X;
	
	//BC Y0
	int dBC0Y0d0dX0, dBC0Y0d0d0X;
	int dBC0Y0d1dX0, dBC0Y0d1d0X;
	int dBC0Y0d2dX0, dBC0Y0d2d0X;
	int dBC0Y0d3dX0, dBC0Y0d3d0X;
	int dBC0Y0d4dX0, dBC0Y0d4d0X;
	int dBC0Y0d5dX0, dBC0Y0d5d0X;
	int dBC0Y0d6dX0, dBC0Y0d6d0X;
	int dBC0Y0d7dX0, dBC0Y0d7d0X;
	
	int dBC1Y0d0dX0, dBC1Y0d0d0X;
	int dBC1Y0d1dX0, dBC1Y0d1d0X;
	int dBC1Y0d2dX0, dBC1Y0d2d0X;
	int dBC1Y0d3dX0, dBC1Y0d3d0X;
	int dBC1Y0d4dX0, dBC1Y0d4d0X;
	int dBC1Y0d5dX0, dBC1Y0d5d0X;
	int dBC1Y0d6dX0, dBC1Y0d6d0X;
	int dBC1Y0d7dX0, dBC1Y0d7d0X;
	
	int dBC2Y0d0dX0, dBC2Y0d0d0X;
	int dBC2Y0d1dX0, dBC2Y0d1d0X;
	int dBC2Y0d2dX0, dBC2Y0d2d0X;
	int dBC2Y0d3dX0, dBC2Y0d3d0X;
	int dBC2Y0d4dX0, dBC2Y0d4d0X;
	int dBC2Y0d5dX0, dBC2Y0d5d0X;
	int dBC2Y0d6dX0, dBC2Y0d6d0X;
	int dBC2Y0d7dX0, dBC2Y0d7d0X;
	
	int dBC3Y0d0dX0, dBC3Y0d0d0X;
	int dBC3Y0d1dX0, dBC3Y0d1d0X;
	int dBC3Y0d2dX0, dBC3Y0d2d0X;
	int dBC3Y0d3dX0, dBC3Y0d3d0X;
	int dBC3Y0d4dX0, dBC3Y0d4d0X;
	int dBC3Y0d5dX0, dBC3Y0d5d0X;
	int dBC3Y0d6dX0, dBC3Y0d6d0X;
	int dBC3Y0d7dX0, dBC3Y0d7d0X;
	
	int dBC4Y0d0dX0, dBC4Y0d0d0X;
	int dBC4Y0d1dX0, dBC4Y0d1d0X;
	int dBC4Y0d2dX0, dBC4Y0d2d0X;
	int dBC4Y0d3dX0, dBC4Y0d3d0X;
	int dBC4Y0d4dX0, dBC4Y0d4d0X;
	int dBC4Y0d5dX0, dBC4Y0d5d0X;
	int dBC4Y0d6dX0, dBC4Y0d6d0X;
	int dBC4Y0d7dX0, dBC4Y0d7d0X;
	
	int dBC5Y0d0dX0, dBC5Y0d0d0X;
	int dBC5Y0d1dX0, dBC5Y0d1d0X;
	int dBC5Y0d2dX0, dBC5Y0d2d0X;
	int dBC5Y0d3dX0, dBC5Y0d3d0X;
	int dBC5Y0d4dX0, dBC5Y0d4d0X;
	int dBC5Y0d5dX0, dBC5Y0d5d0X;
	int dBC5Y0d6dX0, dBC5Y0d6d0X;
	int dBC5Y0d7dX0, dBC5Y0d7d0X;
	
	int dBC6Y0d0dX0, dBC6Y0d0d0X;
	int dBC6Y0d1dX0, dBC6Y0d1d0X;
	int dBC6Y0d2dX0, dBC6Y0d2d0X;
	int dBC6Y0d3dX0, dBC6Y0d3d0X;
	int dBC6Y0d4dX0, dBC6Y0d4d0X;
	int dBC6Y0d5dX0, dBC6Y0d5d0X;
	int dBC6Y0d6dX0, dBC6Y0d6d0X;
	int dBC6Y0d7dX0, dBC6Y0d7d0X;
	
	int dBC7Y0d0dX0, dBC7Y0d0d0X;
	int dBC7Y0d1dX0, dBC7Y0d1d0X;
	int dBC7Y0d2dX0, dBC7Y0d2d0X;
	int dBC7Y0d3dX0, dBC7Y0d3d0X;
	int dBC7Y0d4dX0, dBC7Y0d4d0X;
	int dBC7Y0d5dX0, dBC7Y0d5d0X;
	int dBC7Y0d6dX0, dBC7Y0d6d0X;
	int dBC7Y0d7dX0, dBC7Y0d7d0X;
	
	//:::::::::::::::::::: X0 ::::::::::::::::::::
	if (bc == 0)
	{
		//-------------------- i = 0 --------------------
		if (i == 0)
		{
			dBC0X0d0dX0 = dBC0X0d0dX0out();
			dBC0X0d0d0X = dBC0X0d0d0Xout();
			
			dBC0X0d1dX0 = dBC0X0d1dX0out();
			dBC0X0d1d0X = dBC0X0d1d0Xout();
			
			dBC0X0d2dX0 = dBC0X0d2dX0out();
			dBC0X0d2d0X = dBC0X0d2d0Xout();
			
			dBC0X0d3dX0 = dBC0X0d3dX0out();
			dBC0X0d3d0X = dBC0X0d3d0Xout();
			
			dBC0X0d4dX0 = dBC0X0d4dX0out();
			dBC0X0d4d0X = dBC0X0d4d0Xout();
			
			dBC0X0d5dX0 = dBC0X0d5dX0out();
			dBC0X0d5d0X = dBC0X0d5d0Xout();
			
			dBC0X0d6dX0 = dBC0X0d6dX0out();
			dBC0X0d6d0X = dBC0X0d6d0Xout();
			
			dBC0X0d7dX0 = dBC0X0d7dX0out();
			dBC0X0d7d0X = dBC0X0d7d0Xout();
			
			fprintf(outfile,"			//-------------------------------------------------------\n");
			fprintf(outfile,"			pn = %i;\n",0);
			fprintf(outfile,"			\n");
			
			fprintf(outfile,"			for (a = 0; a <= r+onexside; ++a)\n");
			fprintf(outfile,"			{\n");
			if (dBC0X0d0dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",0,'X',0,0,0,0,'X',0,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC0X0d1dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",0,'X',0,1,1,0,'X',0,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC0X0d2dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",0,'X',0,2,2,0,'X',0,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC0X0d3dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",0,'X',0,3,3,0,'X',0,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC0X0d4dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",0,'X',0,4,4,0,'X',0,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC0X0d5dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",0,'X',0,5,5,0,'X',0,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC0X0d6dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",0,'X',0,6,6,0,'X',0,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC0X0d7dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",0,'X',0,7,7,0,'X',0,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			fprintf(outfile,"			}\n");
			
			fprintf(outfile,"			for (b = 0; b <= r+oneyside; ++b)\n");
			fprintf(outfile,"			{\n");
			if (dBC0X0d0d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",0,'X',0,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC0X0d1d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",0,'X',0,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC0X0d2d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",0,'X',0,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC0X0d3d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",0,'X',0,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC0X0d4d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",0,'X',0,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC0X0d5d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",0,'X',0,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC0X0d6d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",0,'X',0,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC0X0d7d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",0,'X',0,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			fprintf(outfile,"			}\n");
			fprintf(outfile,"			\n");
			
		}
		//-------------------- i = 1 --------------------
		else if (i == 1)
		{
			dBC1X0d0dX0 = dBC1X0d0dX0out();
			dBC1X0d0d0X = dBC1X0d0d0Xout();
			
			dBC1X0d1dX0 = dBC1X0d1dX0out();
			dBC1X0d1d0X = dBC1X0d1d0Xout();
			
			dBC1X0d2dX0 = dBC1X0d2dX0out();
			dBC1X0d2d0X = dBC1X0d2d0Xout();
			
			dBC1X0d3dX0 = dBC1X0d3dX0out();
			dBC1X0d3d0X = dBC1X0d3d0Xout();
			
			dBC1X0d4dX0 = dBC1X0d4dX0out();
			dBC1X0d4d0X = dBC1X0d4d0Xout();
			
			dBC1X0d5dX0 = dBC1X0d5dX0out();
			dBC1X0d5d0X = dBC1X0d5d0Xout();
			
			dBC1X0d6dX0 = dBC1X0d6dX0out();
			dBC1X0d6d0X = dBC1X0d6d0Xout();
			
			dBC1X0d7dX0 = dBC1X0d7dX0out();
			dBC1X0d7d0X = dBC1X0d7d0Xout();
			
			fprintf(outfile,"			//-------------------------------------------------------\n");
			fprintf(outfile,"			pn = %i;\n",1);
			fprintf(outfile,"			\n");
			
			fprintf(outfile,"			for (a = 0; a <= r+onexside; ++a)\n");
			fprintf(outfile,"			{\n");
			if (dBC1X0d0dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",1,'X',0,0,0,1,'X',0,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC1X0d1dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",1,'X',0,1,1,1,'X',0,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC1X0d2dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",1,'X',0,2,2,1,'X',0,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC1X0d3dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",1,'X',0,3,3,1,'X',0,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC1X0d4dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",1,'X',0,4,4,1,'X',0,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC1X0d5dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",1,'X',0,5,5,1,'X',0,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC1X0d6dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",1,'X',0,6,6,1,'X',0,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC1X0d7dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",1,'X',0,7,7,1,'X',0,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			fprintf(outfile,"			}\n");
			
			fprintf(outfile,"			for (b = 0; b <= r+oneyside; ++b)\n");
			fprintf(outfile,"			{\n");
			if (dBC1X0d0d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",1,'X',0,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC1X0d1d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",1,'X',0,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC1X0d2d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",1,'X',0,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC1X0d3d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",1,'X',0,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC1X0d4d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",1,'X',0,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC1X0d5d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",1,'X',0,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC1X0d6d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",1,'X',0,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC1X0d7d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",1,'X',0,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			fprintf(outfile,"			}\n");
			fprintf(outfile,"			\n");
			
		}
		//-------------------- i = 2 --------------------
		else if (i == 2)
		{
			dBC2X0d0dX0 = dBC2X0d0dX0out();
			dBC2X0d0d0X = dBC2X0d0d0Xout();
			
			dBC2X0d1dX0 = dBC2X0d1dX0out();
			dBC2X0d1d0X = dBC2X0d1d0Xout();
			
			dBC2X0d2dX0 = dBC2X0d2dX0out();
			dBC2X0d2d0X = dBC2X0d2d0Xout();
			
			dBC2X0d3dX0 = dBC2X0d3dX0out();
			dBC2X0d3d0X = dBC2X0d3d0Xout();
			
			dBC2X0d4dX0 = dBC2X0d4dX0out();
			dBC2X0d4d0X = dBC2X0d4d0Xout();
			
			dBC2X0d5dX0 = dBC2X0d5dX0out();
			dBC2X0d5d0X = dBC2X0d5d0Xout();
			
			dBC2X0d6dX0 = dBC2X0d6dX0out();
			dBC2X0d6d0X = dBC2X0d6d0Xout();
			
			dBC2X0d7dX0 = dBC2X0d7dX0out();
			dBC2X0d7d0X = dBC2X0d7d0Xout();
			
			fprintf(outfile,"			//-------------------------------------------------------\n");
			fprintf(outfile,"			pn = %i;\n",2);
			fprintf(outfile,"			\n");
			
			fprintf(outfile,"			for (a = 0; a <= r+onexside; ++a)\n");
			fprintf(outfile,"			{\n");
			if (dBC2X0d0dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",2,'X',0,0,0,2,'X',0,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC2X0d1dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",2,'X',0,1,1,2,'X',0,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC2X0d2dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",2,'X',0,2,2,2,'X',0,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC2X0d3dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",2,'X',0,3,3,2,'X',0,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC2X0d4dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",2,'X',0,4,4,2,'X',0,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC2X0d5dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",2,'X',0,5,5,2,'X',0,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC2X0d6dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",2,'X',0,6,6,2,'X',0,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC2X0d7dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",2,'X',0,7,7,2,'X',0,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			fprintf(outfile,"			}\n");
			
			fprintf(outfile,"			for (b = 0; b <= r+oneyside; ++b)\n");
			fprintf(outfile,"			{\n");
			if (dBC2X0d0d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",2,'X',0,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC2X0d1d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",2,'X',0,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC2X0d2d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",2,'X',0,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC2X0d3d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",2,'X',0,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC2X0d4d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",2,'X',0,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC2X0d5d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",2,'X',0,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC2X0d6d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",2,'X',0,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC2X0d7d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",2,'X',0,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			fprintf(outfile,"			}\n");
			fprintf(outfile,"			\n");
			
		}
		//-------------------- i = 3 --------------------
		else if (i == 3)
		{
			dBC3X0d0dX0 = dBC3X0d0dX0out();
			dBC3X0d0d0X = dBC3X0d0d0Xout();
			
			dBC3X0d1dX0 = dBC3X0d1dX0out();
			dBC3X0d1d0X = dBC3X0d1d0Xout();
			
			dBC3X0d2dX0 = dBC3X0d2dX0out();
			dBC3X0d2d0X = dBC3X0d2d0Xout();
			
			dBC3X0d3dX0 = dBC3X0d3dX0out();
			dBC3X0d3d0X = dBC3X0d3d0Xout();
			
			dBC3X0d4dX0 = dBC3X0d4dX0out();
			dBC3X0d4d0X = dBC3X0d4d0Xout();
			
			dBC3X0d5dX0 = dBC3X0d5dX0out();
			dBC3X0d5d0X = dBC3X0d5d0Xout();
			
			dBC3X0d6dX0 = dBC3X0d6dX0out();
			dBC3X0d6d0X = dBC3X0d6d0Xout();
			
			dBC3X0d7dX0 = dBC3X0d7dX0out();
			dBC3X0d7d0X = dBC3X0d7d0Xout();
			
			fprintf(outfile,"			//-------------------------------------------------------\n");
			fprintf(outfile,"			pn = %i;\n",3);
			fprintf(outfile,"			\n");
			
			fprintf(outfile,"			for (a = 0; a <= r+onexside; ++a)\n");
			fprintf(outfile,"			{\n");
			if (dBC3X0d0dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",3,'X',0,0,0,3,'X',0,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC3X0d1dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",3,'X',0,1,1,3,'X',0,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC3X0d2dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",3,'X',0,2,2,3,'X',0,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC3X0d3dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",3,'X',0,3,3,3,'X',0,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC3X0d4dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",3,'X',0,4,4,3,'X',0,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC3X0d5dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",3,'X',0,5,5,3,'X',0,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC3X0d6dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",3,'X',0,6,6,3,'X',0,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC3X0d7dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",3,'X',0,7,7,3,'X',0,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			fprintf(outfile,"			}\n");
			
			fprintf(outfile,"			for (b = 0; b <= r+oneyside; ++b)\n");
			fprintf(outfile,"			{\n");
			if (dBC3X0d0d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",3,'X',0,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC3X0d1d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",3,'X',0,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC3X0d2d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",3,'X',0,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC3X0d3d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",3,'X',0,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC3X0d4d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",3,'X',0,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC3X0d5d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",3,'X',0,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC3X0d6d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",3,'X',0,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC3X0d7d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",3,'X',0,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			fprintf(outfile,"			}\n");
			fprintf(outfile,"			\n");
			
		}
		//-------------------- i = 4 --------------------
		else if (i == 4)
		{
			dBC4X0d0dX0 = dBC4X0d0dX0out();
			dBC4X0d0d0X = dBC4X0d0d0Xout();
			
			dBC4X0d1dX0 = dBC4X0d1dX0out();
			dBC4X0d1d0X = dBC4X0d1d0Xout();
			
			dBC4X0d2dX0 = dBC4X0d2dX0out();
			dBC4X0d2d0X = dBC4X0d2d0Xout();
			
			dBC4X0d3dX0 = dBC4X0d3dX0out();
			dBC4X0d3d0X = dBC4X0d3d0Xout();
			
			dBC4X0d4dX0 = dBC4X0d4dX0out();
			dBC4X0d4d0X = dBC4X0d4d0Xout();
			
			dBC4X0d5dX0 = dBC4X0d5dX0out();
			dBC4X0d5d0X = dBC4X0d5d0Xout();
			
			dBC4X0d6dX0 = dBC4X0d6dX0out();
			dBC4X0d6d0X = dBC4X0d6d0Xout();
			
			dBC4X0d7dX0 = dBC4X0d7dX0out();
			dBC4X0d7d0X = dBC4X0d7d0Xout();
			
			fprintf(outfile,"			//-------------------------------------------------------\n");
			fprintf(outfile,"			pn = %i;\n",4);
			fprintf(outfile,"			\n");
			
			fprintf(outfile,"			for (a = 0; a <= r+onexside; ++a)\n");
			fprintf(outfile,"			{\n");
			if (dBC4X0d0dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",4,'X',0,0,0,4,'X',0,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC4X0d1dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",4,'X',0,1,1,4,'X',0,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC4X0d2dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",4,'X',0,2,2,4,'X',0,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC4X0d3dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",4,'X',0,3,3,4,'X',0,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC4X0d4dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",4,'X',0,4,4,4,'X',0,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC4X0d5dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",4,'X',0,5,5,4,'X',0,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC4X0d6dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",4,'X',0,6,6,4,'X',0,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC4X0d7dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",4,'X',0,7,7,4,'X',0,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			fprintf(outfile,"			}\n");
			
			fprintf(outfile,"			for (b = 0; b <= r+oneyside; ++b)\n");
			fprintf(outfile,"			{\n");
			if (dBC4X0d0d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",4,'X',0,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC4X0d1d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",4,'X',0,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC4X0d2d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",4,'X',0,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC4X0d3d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",4,'X',0,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC4X0d4d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",4,'X',0,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC4X0d5d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",4,'X',0,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC4X0d6d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",4,'X',0,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC4X0d7d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",4,'X',0,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			fprintf(outfile,"			}\n");
			fprintf(outfile,"			\n");
			
		}
		//-------------------- i = 5 --------------------
		else if (i == 5)
		{
			dBC5X0d0dX0 = dBC5X0d0dX0out();
			dBC5X0d0d0X = dBC5X0d0d0Xout();
			
			dBC5X0d1dX0 = dBC5X0d1dX0out();
			dBC5X0d1d0X = dBC5X0d1d0Xout();
			
			dBC5X0d2dX0 = dBC5X0d2dX0out();
			dBC5X0d2d0X = dBC5X0d2d0Xout();
			
			dBC5X0d3dX0 = dBC5X0d3dX0out();
			dBC5X0d3d0X = dBC5X0d3d0Xout();
			
			dBC5X0d4dX0 = dBC5X0d4dX0out();
			dBC5X0d4d0X = dBC5X0d4d0Xout();
			
			dBC5X0d5dX0 = dBC5X0d5dX0out();
			dBC5X0d5d0X = dBC5X0d5d0Xout();
			
			dBC5X0d6dX0 = dBC5X0d6dX0out();
			dBC5X0d6d0X = dBC5X0d6d0Xout();
			
			dBC5X0d7dX0 = dBC5X0d7dX0out();
			dBC5X0d7d0X = dBC5X0d7d0Xout();
			
			fprintf(outfile,"			//-------------------------------------------------------\n");
			fprintf(outfile,"			pn = %i;\n",5);
			fprintf(outfile,"			\n");
			
			fprintf(outfile,"			for (a = 0; a <= r+onexside; ++a)\n");
			fprintf(outfile,"			{\n");
			if (dBC5X0d0dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",5,'X',0,0,0,5,'X',0,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC5X0d1dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",5,'X',0,1,1,5,'X',0,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC5X0d2dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",5,'X',0,2,2,5,'X',0,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC5X0d3dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",5,'X',0,3,3,5,'X',0,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC5X0d4dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",5,'X',0,4,4,5,'X',0,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC5X0d5dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",5,'X',0,5,5,5,'X',0,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC5X0d6dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",5,'X',0,6,6,5,'X',0,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC5X0d7dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",5,'X',0,7,7,5,'X',0,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			fprintf(outfile,"			}\n");
			
			fprintf(outfile,"			for (b = 0; b <= r+oneyside; ++b)\n");
			fprintf(outfile,"			{\n");
			if (dBC5X0d0d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",5,'X',0,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC5X0d1d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",5,'X',0,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC5X0d2d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",5,'X',0,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC5X0d3d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",5,'X',0,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC5X0d4d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",5,'X',0,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC5X0d5d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",5,'X',0,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC5X0d6d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",5,'X',0,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC5X0d7d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",5,'X',0,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			fprintf(outfile,"			}\n");
			fprintf(outfile,"			\n");
			
		}
		//-------------------- i = 6 --------------------
		else if (i == 6)
		{
			dBC6X0d0dX0 = dBC6X0d0dX0out();
			dBC6X0d0d0X = dBC6X0d0d0Xout();
			
			dBC6X0d1dX0 = dBC6X0d1dX0out();
			dBC6X0d1d0X = dBC6X0d1d0Xout();
			
			dBC6X0d2dX0 = dBC6X0d2dX0out();
			dBC6X0d2d0X = dBC6X0d2d0Xout();
			
			dBC6X0d3dX0 = dBC6X0d3dX0out();
			dBC6X0d3d0X = dBC6X0d3d0Xout();
			
			dBC6X0d4dX0 = dBC6X0d4dX0out();
			dBC6X0d4d0X = dBC6X0d4d0Xout();
			
			dBC6X0d5dX0 = dBC6X0d5dX0out();
			dBC6X0d5d0X = dBC6X0d5d0Xout();
			
			dBC6X0d6dX0 = dBC6X0d6dX0out();
			dBC6X0d6d0X = dBC6X0d6d0Xout();
			
			dBC6X0d7dX0 = dBC6X0d7dX0out();
			dBC6X0d7d0X = dBC6X0d7d0Xout();
			
			fprintf(outfile,"			//-------------------------------------------------------\n");
			fprintf(outfile,"			pn = %i;\n",6);
			fprintf(outfile,"			\n");
			
			fprintf(outfile,"			for (a = 0; a <= r+onexside; ++a)\n");
			fprintf(outfile,"			{\n");
			if (dBC6X0d0dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",6,'X',0,0,0,6,'X',0,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC6X0d1dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",6,'X',0,1,1,6,'X',0,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC6X0d2dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",6,'X',0,2,2,6,'X',0,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC6X0d3dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",6,'X',0,3,3,6,'X',0,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC6X0d4dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",6,'X',0,4,4,6,'X',0,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC6X0d5dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",6,'X',0,5,5,6,'X',0,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC6X0d6dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",6,'X',0,6,6,6,'X',0,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC6X0d7dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",6,'X',0,7,7,6,'X',0,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			fprintf(outfile,"			}\n");
			
			fprintf(outfile,"			for (b = 0; b <= r+oneyside; ++b)\n");
			fprintf(outfile,"			{\n");
			if (dBC6X0d0d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",6,'X',0,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC6X0d1d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",6,'X',0,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC6X0d2d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",6,'X',0,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC6X0d3d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",6,'X',0,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC6X0d4d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",6,'X',0,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC6X0d5d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",6,'X',0,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC6X0d6d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",6,'X',0,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC6X0d7d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",6,'X',0,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			fprintf(outfile,"			}\n");
			fprintf(outfile,"			\n");
			
		}
		//-------------------- i = 7 --------------------
		else if (i == 7)
		{
			dBC7X0d0dX0 = dBC7X0d0dX0out();
			dBC7X0d0d0X = dBC7X0d0d0Xout();
			
			dBC7X0d1dX0 = dBC7X0d1dX0out();
			dBC7X0d1d0X = dBC7X0d1d0Xout();
			
			dBC7X0d2dX0 = dBC7X0d2dX0out();
			dBC7X0d2d0X = dBC7X0d2d0Xout();
			
			dBC7X0d3dX0 = dBC7X0d3dX0out();
			dBC7X0d3d0X = dBC7X0d3d0Xout();
			
			dBC7X0d4dX0 = dBC7X0d4dX0out();
			dBC7X0d4d0X = dBC7X0d4d0Xout();
			
			dBC7X0d5dX0 = dBC7X0d5dX0out();
			dBC7X0d5d0X = dBC7X0d5d0Xout();
			
			dBC7X0d6dX0 = dBC7X0d6dX0out();
			dBC7X0d6d0X = dBC7X0d6d0Xout();
			
			dBC7X0d7dX0 = dBC7X0d7dX0out();
			dBC7X0d7d0X = dBC7X0d7d0Xout();
			
			fprintf(outfile,"			//-------------------------------------------------------\n");
			fprintf(outfile,"			pn = %i;\n",7);
			fprintf(outfile,"			\n");
			
			fprintf(outfile,"			for (a = 0; a <= r+onexside; ++a)\n");
			fprintf(outfile,"			{\n");
			if (dBC7X0d0dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",7,'X',0,0,0,7,'X',0,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC7X0d1dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",7,'X',0,1,1,7,'X',0,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC7X0d2dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",7,'X',0,2,2,7,'X',0,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC7X0d3dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",7,'X',0,3,3,7,'X',0,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC7X0d4dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",7,'X',0,4,4,7,'X',0,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC7X0d5dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",7,'X',0,5,5,7,'X',0,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC7X0d6dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",7,'X',0,6,6,7,'X',0,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC7X0d7dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",7,'X',0,7,7,7,'X',0,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			fprintf(outfile,"			}\n");
			
			fprintf(outfile,"			for (b = 0; b <= r+oneyside; ++b)\n");
			fprintf(outfile,"			{\n");
			if (dBC7X0d0d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",7,'X',0,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC7X0d1d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",7,'X',0,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC7X0d2d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",7,'X',0,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC7X0d3d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",7,'X',0,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC7X0d4d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",7,'X',0,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC7X0d5d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",7,'X',0,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC7X0d6d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",7,'X',0,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC7X0d7d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",7,'X',0,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			fprintf(outfile,"			}\n");
			fprintf(outfile,"			\n");
			
		}
		else
		{
			printf("ERROR!! In CodeGen_NNZ.c, %i does not match number of field equations.\n",i);
			return -1;
		}
		
	}
	//:::::::::::::::::::: X1 ::::::::::::::::::::
	else if (bc == 1)
	{
		//-------------------- i = 0 --------------------
		if (i == 0)
		{
			dBC0X1d0dX0 = dBC0X1d0dX0out();
			dBC0X1d0d0X = dBC0X1d0d0Xout();
			
			dBC0X1d1dX0 = dBC0X1d1dX0out();
			dBC0X1d1d0X = dBC0X1d1d0Xout();
			
			dBC0X1d2dX0 = dBC0X1d2dX0out();
			dBC0X1d2d0X = dBC0X1d2d0Xout();
			
			dBC0X1d3dX0 = dBC0X1d3dX0out();
			dBC0X1d3d0X = dBC0X1d3d0Xout();
			
			dBC0X1d4dX0 = dBC0X1d4dX0out();
			dBC0X1d4d0X = dBC0X1d4d0Xout();
			
			dBC0X1d5dX0 = dBC0X1d5dX0out();
			dBC0X1d5d0X = dBC0X1d5d0Xout();
			
			dBC0X1d6dX0 = dBC0X1d6dX0out();
			dBC0X1d6d0X = dBC0X1d6d0Xout();
			
			dBC0X1d7dX0 = dBC0X1d7dX0out();
			dBC0X1d7d0X = dBC0X1d7d0Xout();
			
			fprintf(outfile,"			//-------------------------------------------------------\n");
			fprintf(outfile,"			pn = %i;\n",0);
			fprintf(outfile,"			\n");
			
			fprintf(outfile,"			for (a = 0; a <= r+onexside; ++a)\n");
			fprintf(outfile,"			{\n");
			if (dBC0X1d0dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",0,'X',1,0,0,0,'X',1,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC0X1d1dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",0,'X',1,1,1,0,'X',1,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC0X1d2dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",0,'X',1,2,2,0,'X',1,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC0X1d3dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",0,'X',1,3,3,0,'X',1,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC0X1d4dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",0,'X',1,4,4,0,'X',1,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC0X1d5dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",0,'X',1,5,5,0,'X',1,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC0X1d6dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",0,'X',1,6,6,0,'X',1,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC0X1d7dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",0,'X',1,7,7,0,'X',1,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			fprintf(outfile,"			}\n");
			
			fprintf(outfile,"			for (b = 0; b <= r+oneyside; ++b)\n");
			fprintf(outfile,"			{\n");
			if (dBC0X1d0d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",0,'X',1,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC0X1d1d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",0,'X',1,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC0X1d2d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",0,'X',1,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC0X1d3d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",0,'X',1,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC0X1d4d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",0,'X',1,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC0X1d5d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",0,'X',1,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC0X1d6d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",0,'X',1,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC0X1d7d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",0,'X',1,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			fprintf(outfile,"			}\n");
			fprintf(outfile,"			\n");
			
		}
		//-------------------- i = 1 --------------------
		else if (i == 1)
		{
			dBC1X1d0dX0 = dBC1X1d0dX0out();
			dBC1X1d0d0X = dBC1X1d0d0Xout();
			
			dBC1X1d1dX0 = dBC1X1d1dX0out();
			dBC1X1d1d0X = dBC1X1d1d0Xout();
			
			dBC1X1d2dX0 = dBC1X1d2dX0out();
			dBC1X1d2d0X = dBC1X1d2d0Xout();
			
			dBC1X1d3dX0 = dBC1X1d3dX0out();
			dBC1X1d3d0X = dBC1X1d3d0Xout();
			
			dBC1X1d4dX0 = dBC1X1d4dX0out();
			dBC1X1d4d0X = dBC1X1d4d0Xout();
			
			dBC1X1d5dX0 = dBC1X1d5dX0out();
			dBC1X1d5d0X = dBC1X1d5d0Xout();
			
			dBC1X1d6dX0 = dBC1X1d6dX0out();
			dBC1X1d6d0X = dBC1X1d6d0Xout();
			
			dBC1X1d7dX0 = dBC1X1d7dX0out();
			dBC1X1d7d0X = dBC1X1d7d0Xout();
			
			fprintf(outfile,"			//-------------------------------------------------------\n");
			fprintf(outfile,"			pn = %i;\n",1);
			fprintf(outfile,"			\n");
			
			fprintf(outfile,"			for (a = 0; a <= r+onexside; ++a)\n");
			fprintf(outfile,"			{\n");
			if (dBC1X1d0dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",1,'X',1,0,0,1,'X',1,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC1X1d1dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",1,'X',1,1,1,1,'X',1,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC1X1d2dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",1,'X',1,2,2,1,'X',1,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC1X1d3dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",1,'X',1,3,3,1,'X',1,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC1X1d4dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",1,'X',1,4,4,1,'X',1,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC1X1d5dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",1,'X',1,5,5,1,'X',1,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC1X1d6dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",1,'X',1,6,6,1,'X',1,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC1X1d7dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",1,'X',1,7,7,1,'X',1,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			fprintf(outfile,"			}\n");
			
			fprintf(outfile,"			for (b = 0; b <= r+oneyside; ++b)\n");
			fprintf(outfile,"			{\n");
			if (dBC1X1d0d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",1,'X',1,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC1X1d1d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",1,'X',1,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC1X1d2d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",1,'X',1,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC1X1d3d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",1,'X',1,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC1X1d4d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",1,'X',1,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC1X1d5d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",1,'X',1,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC1X1d6d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",1,'X',1,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC1X1d7d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",1,'X',1,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			fprintf(outfile,"			}\n");
			fprintf(outfile,"			\n");
			
		}
		//-------------------- i = 2 --------------------
		else if (i == 2)
		{
			dBC2X1d0dX0 = dBC2X1d0dX0out();
			dBC2X1d0d0X = dBC2X1d0d0Xout();
			
			dBC2X1d1dX0 = dBC2X1d1dX0out();
			dBC2X1d1d0X = dBC2X1d1d0Xout();
			
			dBC2X1d2dX0 = dBC2X1d2dX0out();
			dBC2X1d2d0X = dBC2X1d2d0Xout();
			
			dBC2X1d3dX0 = dBC2X1d3dX0out();
			dBC2X1d3d0X = dBC2X1d3d0Xout();
			
			dBC2X1d4dX0 = dBC2X1d4dX0out();
			dBC2X1d4d0X = dBC2X1d4d0Xout();
			
			dBC2X1d5dX0 = dBC2X1d5dX0out();
			dBC2X1d5d0X = dBC2X1d5d0Xout();
			
			dBC2X1d6dX0 = dBC2X1d6dX0out();
			dBC2X1d6d0X = dBC2X1d6d0Xout();
			
			dBC2X1d7dX0 = dBC2X1d7dX0out();
			dBC2X1d7d0X = dBC2X1d7d0Xout();
			
			fprintf(outfile,"			//-------------------------------------------------------\n");
			fprintf(outfile,"			pn = %i;\n",2);
			fprintf(outfile,"			\n");
			
			fprintf(outfile,"			for (a = 0; a <= r+onexside; ++a)\n");
			fprintf(outfile,"			{\n");
			if (dBC2X1d0dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",2,'X',1,0,0,2,'X',1,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC2X1d1dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",2,'X',1,1,1,2,'X',1,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC2X1d2dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",2,'X',1,2,2,2,'X',1,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC2X1d3dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",2,'X',1,3,3,2,'X',1,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC2X1d4dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",2,'X',1,4,4,2,'X',1,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC2X1d5dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",2,'X',1,5,5,2,'X',1,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC2X1d6dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",2,'X',1,6,6,2,'X',1,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC2X1d7dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",2,'X',1,7,7,2,'X',1,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			fprintf(outfile,"			}\n");
			
			fprintf(outfile,"			for (b = 0; b <= r+oneyside; ++b)\n");
			fprintf(outfile,"			{\n");
			if (dBC2X1d0d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",2,'X',1,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC2X1d1d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",2,'X',1,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC2X1d2d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",2,'X',1,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC2X1d3d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",2,'X',1,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC2X1d4d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",2,'X',1,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC2X1d5d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",2,'X',1,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC2X1d6d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",2,'X',1,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC2X1d7d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",2,'X',1,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			fprintf(outfile,"			}\n");
			fprintf(outfile,"			\n");
			
		}
		//-------------------- i = 3 --------------------
		else if (i == 3)
		{
			dBC3X1d0dX0 = dBC3X1d0dX0out();
			dBC3X1d0d0X = dBC3X1d0d0Xout();
			
			dBC3X1d1dX0 = dBC3X1d1dX0out();
			dBC3X1d1d0X = dBC3X1d1d0Xout();
			
			dBC3X1d2dX0 = dBC3X1d2dX0out();
			dBC3X1d2d0X = dBC3X1d2d0Xout();
			
			dBC3X1d3dX0 = dBC3X1d3dX0out();
			dBC3X1d3d0X = dBC3X1d3d0Xout();
			
			dBC3X1d4dX0 = dBC3X1d4dX0out();
			dBC3X1d4d0X = dBC3X1d4d0Xout();
			
			dBC3X1d5dX0 = dBC3X1d5dX0out();
			dBC3X1d5d0X = dBC3X1d5d0Xout();
			
			dBC3X1d6dX0 = dBC3X1d6dX0out();
			dBC3X1d6d0X = dBC3X1d6d0Xout();
			
			dBC3X1d7dX0 = dBC3X1d7dX0out();
			dBC3X1d7d0X = dBC3X1d7d0Xout();
			
			fprintf(outfile,"			//-------------------------------------------------------\n");
			fprintf(outfile,"			pn = %i;\n",3);
			fprintf(outfile,"			\n");
			
			fprintf(outfile,"			for (a = 0; a <= r+onexside; ++a)\n");
			fprintf(outfile,"			{\n");
			if (dBC3X1d0dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",3,'X',1,0,0,3,'X',1,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC3X1d1dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",3,'X',1,1,1,3,'X',1,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC3X1d2dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",3,'X',1,2,2,3,'X',1,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC3X1d3dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",3,'X',1,3,3,3,'X',1,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC3X1d4dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",3,'X',1,4,4,3,'X',1,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC3X1d5dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",3,'X',1,5,5,3,'X',1,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC3X1d6dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",3,'X',1,6,6,3,'X',1,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC3X1d7dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",3,'X',1,7,7,3,'X',1,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			fprintf(outfile,"			}\n");
			
			fprintf(outfile,"			for (b = 0; b <= r+oneyside; ++b)\n");
			fprintf(outfile,"			{\n");
			if (dBC3X1d0d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",3,'X',1,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC3X1d1d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",3,'X',1,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC3X1d2d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",3,'X',1,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC3X1d3d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",3,'X',1,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC3X1d4d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",3,'X',1,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC3X1d5d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",3,'X',1,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC3X1d6d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",3,'X',1,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC3X1d7d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",3,'X',1,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			fprintf(outfile,"			}\n");
			fprintf(outfile,"			\n");
			
		}
		//-------------------- i = 4 --------------------
		else if (i == 4)
		{
			dBC4X1d0dX0 = dBC4X1d0dX0out();
			dBC4X1d0d0X = dBC4X1d0d0Xout();
			
			dBC4X1d1dX0 = dBC4X1d1dX0out();
			dBC4X1d1d0X = dBC4X1d1d0Xout();
			
			dBC4X1d2dX0 = dBC4X1d2dX0out();
			dBC4X1d2d0X = dBC4X1d2d0Xout();
			
			dBC4X1d3dX0 = dBC4X1d3dX0out();
			dBC4X1d3d0X = dBC4X1d3d0Xout();
			
			dBC4X1d4dX0 = dBC4X1d4dX0out();
			dBC4X1d4d0X = dBC4X1d4d0Xout();
			
			dBC4X1d5dX0 = dBC4X1d5dX0out();
			dBC4X1d5d0X = dBC4X1d5d0Xout();
			
			dBC4X1d6dX0 = dBC4X1d6dX0out();
			dBC4X1d6d0X = dBC4X1d6d0Xout();
			
			dBC4X1d7dX0 = dBC4X1d7dX0out();
			dBC4X1d7d0X = dBC4X1d7d0Xout();
			
			fprintf(outfile,"			//-------------------------------------------------------\n");
			fprintf(outfile,"			pn = %i;\n",4);
			fprintf(outfile,"			\n");
			
			fprintf(outfile,"			for (a = 0; a <= r+onexside; ++a)\n");
			fprintf(outfile,"			{\n");
			if (dBC4X1d0dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",4,'X',1,0,0,4,'X',1,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC4X1d1dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",4,'X',1,1,1,4,'X',1,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC4X1d2dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",4,'X',1,2,2,4,'X',1,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC4X1d3dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",4,'X',1,3,3,4,'X',1,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC4X1d4dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",4,'X',1,4,4,4,'X',1,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC4X1d5dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",4,'X',1,5,5,4,'X',1,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC4X1d6dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",4,'X',1,6,6,4,'X',1,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC4X1d7dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",4,'X',1,7,7,4,'X',1,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			fprintf(outfile,"			}\n");
			
			fprintf(outfile,"			for (b = 0; b <= r+oneyside; ++b)\n");
			fprintf(outfile,"			{\n");
			if (dBC4X1d0d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",4,'X',1,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC4X1d1d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",4,'X',1,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC4X1d2d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",4,'X',1,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC4X1d3d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",4,'X',1,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC4X1d4d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",4,'X',1,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC4X1d5d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",4,'X',1,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC4X1d6d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",4,'X',1,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC4X1d7d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",4,'X',1,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			fprintf(outfile,"			}\n");
			fprintf(outfile,"			\n");
			
		}
		//-------------------- i = 5 --------------------
		else if (i == 5)
		{
			dBC5X1d0dX0 = dBC5X1d0dX0out();
			dBC5X1d0d0X = dBC5X1d0d0Xout();
			
			dBC5X1d1dX0 = dBC5X1d1dX0out();
			dBC5X1d1d0X = dBC5X1d1d0Xout();
			
			dBC5X1d2dX0 = dBC5X1d2dX0out();
			dBC5X1d2d0X = dBC5X1d2d0Xout();
			
			dBC5X1d3dX0 = dBC5X1d3dX0out();
			dBC5X1d3d0X = dBC5X1d3d0Xout();
			
			dBC5X1d4dX0 = dBC5X1d4dX0out();
			dBC5X1d4d0X = dBC5X1d4d0Xout();
			
			dBC5X1d5dX0 = dBC5X1d5dX0out();
			dBC5X1d5d0X = dBC5X1d5d0Xout();
			
			dBC5X1d6dX0 = dBC5X1d6dX0out();
			dBC5X1d6d0X = dBC5X1d6d0Xout();
			
			dBC5X1d7dX0 = dBC5X1d7dX0out();
			dBC5X1d7d0X = dBC5X1d7d0Xout();
			
			fprintf(outfile,"			//-------------------------------------------------------\n");
			fprintf(outfile,"			pn = %i;\n",5);
			fprintf(outfile,"			\n");
			
			fprintf(outfile,"			for (a = 0; a <= r+onexside; ++a)\n");
			fprintf(outfile,"			{\n");
			if (dBC5X1d0dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",5,'X',1,0,0,5,'X',1,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC5X1d1dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",5,'X',1,1,1,5,'X',1,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC5X1d2dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",5,'X',1,2,2,5,'X',1,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC5X1d3dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",5,'X',1,3,3,5,'X',1,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC5X1d4dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",5,'X',1,4,4,5,'X',1,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC5X1d5dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",5,'X',1,5,5,5,'X',1,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC5X1d6dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",5,'X',1,6,6,5,'X',1,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC5X1d7dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",5,'X',1,7,7,5,'X',1,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			fprintf(outfile,"			}\n");
			
			fprintf(outfile,"			for (b = 0; b <= r+oneyside; ++b)\n");
			fprintf(outfile,"			{\n");
			if (dBC5X1d0d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",5,'X',1,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC5X1d1d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",5,'X',1,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC5X1d2d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",5,'X',1,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC5X1d3d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",5,'X',1,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC5X1d4d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",5,'X',1,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC5X1d5d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",5,'X',1,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC5X1d6d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",5,'X',1,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC5X1d7d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",5,'X',1,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			fprintf(outfile,"			}\n");
			fprintf(outfile,"			\n");
			
		}
		//-------------------- i = 6 --------------------
		else if (i == 6)
		{
			dBC6X1d0dX0 = dBC6X1d0dX0out();
			dBC6X1d0d0X = dBC6X1d0d0Xout();
			
			dBC6X1d1dX0 = dBC6X1d1dX0out();
			dBC6X1d1d0X = dBC6X1d1d0Xout();
			
			dBC6X1d2dX0 = dBC6X1d2dX0out();
			dBC6X1d2d0X = dBC6X1d2d0Xout();
			
			dBC6X1d3dX0 = dBC6X1d3dX0out();
			dBC6X1d3d0X = dBC6X1d3d0Xout();
			
			dBC6X1d4dX0 = dBC6X1d4dX0out();
			dBC6X1d4d0X = dBC6X1d4d0Xout();
			
			dBC6X1d5dX0 = dBC6X1d5dX0out();
			dBC6X1d5d0X = dBC6X1d5d0Xout();
			
			dBC6X1d6dX0 = dBC6X1d6dX0out();
			dBC6X1d6d0X = dBC6X1d6d0Xout();
			
			dBC6X1d7dX0 = dBC6X1d7dX0out();
			dBC6X1d7d0X = dBC6X1d7d0Xout();
			
			fprintf(outfile,"			//-------------------------------------------------------\n");
			fprintf(outfile,"			pn = %i;\n",6);
			fprintf(outfile,"			\n");
			
			fprintf(outfile,"			for (a = 0; a <= r+onexside; ++a)\n");
			fprintf(outfile,"			{\n");
			if (dBC6X1d0dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",6,'X',1,0,0,6,'X',1,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC6X1d1dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",6,'X',1,1,1,6,'X',1,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC6X1d2dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",6,'X',1,2,2,6,'X',1,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC6X1d3dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",6,'X',1,3,3,6,'X',1,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC6X1d4dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",6,'X',1,4,4,6,'X',1,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC6X1d5dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",6,'X',1,5,5,6,'X',1,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC6X1d6dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",6,'X',1,6,6,6,'X',1,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC6X1d7dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",6,'X',1,7,7,6,'X',1,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			fprintf(outfile,"			}\n");
			
			fprintf(outfile,"			for (b = 0; b <= r+oneyside; ++b)\n");
			fprintf(outfile,"			{\n");
			if (dBC6X1d0d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",6,'X',1,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC6X1d1d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",6,'X',1,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC6X1d2d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",6,'X',1,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC6X1d3d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",6,'X',1,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC6X1d4d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",6,'X',1,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC6X1d5d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",6,'X',1,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC6X1d6d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",6,'X',1,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC6X1d7d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",6,'X',1,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			fprintf(outfile,"			}\n");
			fprintf(outfile,"			\n");
			
		}
		//-------------------- i = 7 --------------------
		else if (i == 7)
		{
			dBC7X1d0dX0 = dBC7X1d0dX0out();
			dBC7X1d0d0X = dBC7X1d0d0Xout();
			
			dBC7X1d1dX0 = dBC7X1d1dX0out();
			dBC7X1d1d0X = dBC7X1d1d0Xout();
			
			dBC7X1d2dX0 = dBC7X1d2dX0out();
			dBC7X1d2d0X = dBC7X1d2d0Xout();
			
			dBC7X1d3dX0 = dBC7X1d3dX0out();
			dBC7X1d3d0X = dBC7X1d3d0Xout();
			
			dBC7X1d4dX0 = dBC7X1d4dX0out();
			dBC7X1d4d0X = dBC7X1d4d0Xout();
			
			dBC7X1d5dX0 = dBC7X1d5dX0out();
			dBC7X1d5d0X = dBC7X1d5d0Xout();
			
			dBC7X1d6dX0 = dBC7X1d6dX0out();
			dBC7X1d6d0X = dBC7X1d6d0Xout();
			
			dBC7X1d7dX0 = dBC7X1d7dX0out();
			dBC7X1d7d0X = dBC7X1d7d0Xout();
			
			fprintf(outfile,"			//-------------------------------------------------------\n");
			fprintf(outfile,"			pn = %i;\n",7);
			fprintf(outfile,"			\n");
			
			fprintf(outfile,"			for (a = 0; a <= r+onexside; ++a)\n");
			fprintf(outfile,"			{\n");
			if (dBC7X1d0dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",7,'X',1,0,0,7,'X',1,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC7X1d1dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",7,'X',1,1,1,7,'X',1,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC7X1d2dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",7,'X',1,2,2,7,'X',1,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC7X1d3dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",7,'X',1,3,3,7,'X',1,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC7X1d4dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",7,'X',1,4,4,7,'X',1,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC7X1d5dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",7,'X',1,5,5,7,'X',1,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC7X1d6dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",7,'X',1,6,6,7,'X',1,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC7X1d7dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",7,'X',1,7,7,7,'X',1,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			fprintf(outfile,"			}\n");
			
			fprintf(outfile,"			for (b = 0; b <= r+oneyside; ++b)\n");
			fprintf(outfile,"			{\n");
			if (dBC7X1d0d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",7,'X',1,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC7X1d1d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",7,'X',1,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC7X1d2d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",7,'X',1,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC7X1d3d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",7,'X',1,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC7X1d4d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",7,'X',1,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC7X1d5d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",7,'X',1,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC7X1d6d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",7,'X',1,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC7X1d7d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",7,'X',1,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			fprintf(outfile,"			}\n");
			fprintf(outfile,"			\n");
			
		}
		else
		{
			printf("ERROR!! In CodeGen_NNZ.c, %i does not match number of field equations.\n",i);
			return -1;
		}
		
	}
	//:::::::::::::::::::: Y1 ::::::::::::::::::::
	else if (bc == 2)
	{
		//-------------------- i = 0 --------------------
		if (i == 0)
		{
			dBC0Y1d0dX0 = dBC0Y1d0dX0out();
			dBC0Y1d0d0X = dBC0Y1d0d0Xout();
			
			dBC0Y1d1dX0 = dBC0Y1d1dX0out();
			dBC0Y1d1d0X = dBC0Y1d1d0Xout();
			
			dBC0Y1d2dX0 = dBC0Y1d2dX0out();
			dBC0Y1d2d0X = dBC0Y1d2d0Xout();
			
			dBC0Y1d3dX0 = dBC0Y1d3dX0out();
			dBC0Y1d3d0X = dBC0Y1d3d0Xout();
			
			dBC0Y1d4dX0 = dBC0Y1d4dX0out();
			dBC0Y1d4d0X = dBC0Y1d4d0Xout();
			
			dBC0Y1d5dX0 = dBC0Y1d5dX0out();
			dBC0Y1d5d0X = dBC0Y1d5d0Xout();
			
			dBC0Y1d6dX0 = dBC0Y1d6dX0out();
			dBC0Y1d6d0X = dBC0Y1d6d0Xout();
			
			dBC0Y1d7dX0 = dBC0Y1d7dX0out();
			dBC0Y1d7d0X = dBC0Y1d7d0Xout();
			
			fprintf(outfile,"			//-------------------------------------------------------\n");
			fprintf(outfile,"			pn = %i;\n",0);
			fprintf(outfile,"			\n");
			
			fprintf(outfile,"			for (a = 0; a <= r+onexside; ++a)\n");
			fprintf(outfile,"			{\n");
			if (dBC0Y1d0dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",0,'Y',1,0,0,0,'Y',1,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC0Y1d1dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",0,'Y',1,1,1,0,'Y',1,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC0Y1d2dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",0,'Y',1,2,2,0,'Y',1,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC0Y1d3dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",0,'Y',1,3,3,0,'Y',1,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC0Y1d4dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",0,'Y',1,4,4,0,'Y',1,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC0Y1d5dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",0,'Y',1,5,5,0,'Y',1,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC0Y1d6dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",0,'Y',1,6,6,0,'Y',1,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC0Y1d7dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",0,'Y',1,7,7,0,'Y',1,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			fprintf(outfile,"			}\n");
			
			fprintf(outfile,"			for (b = 0; b <= r+oneyside; ++b)\n");
			fprintf(outfile,"			{\n");
			if (dBC0Y1d0d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",0,'Y',1,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC0Y1d1d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",0,'Y',1,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC0Y1d2d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",0,'Y',1,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC0Y1d3d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",0,'Y',1,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC0Y1d4d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",0,'Y',1,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC0Y1d5d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",0,'Y',1,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC0Y1d6d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",0,'Y',1,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC0Y1d7d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",0,'Y',1,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			fprintf(outfile,"			}\n");
			fprintf(outfile,"			\n");
			
		}
		//-------------------- i = 1 --------------------
		else if (i == 1)
		{
			dBC1Y1d0dX0 = dBC1Y1d0dX0out();
			dBC1Y1d0d0X = dBC1Y1d0d0Xout();
			
			dBC1Y1d1dX0 = dBC1Y1d1dX0out();
			dBC1Y1d1d0X = dBC1Y1d1d0Xout();
			
			dBC1Y1d2dX0 = dBC1Y1d2dX0out();
			dBC1Y1d2d0X = dBC1Y1d2d0Xout();
			
			dBC1Y1d3dX0 = dBC1Y1d3dX0out();
			dBC1Y1d3d0X = dBC1Y1d3d0Xout();
			
			dBC1Y1d4dX0 = dBC1Y1d4dX0out();
			dBC1Y1d4d0X = dBC1Y1d4d0Xout();
			
			dBC1Y1d5dX0 = dBC1Y1d5dX0out();
			dBC1Y1d5d0X = dBC1Y1d5d0Xout();
			
			dBC1Y1d6dX0 = dBC1Y1d6dX0out();
			dBC1Y1d6d0X = dBC1Y1d6d0Xout();
			
			dBC1Y1d7dX0 = dBC1Y1d7dX0out();
			dBC1Y1d7d0X = dBC1Y1d7d0Xout();
			
			fprintf(outfile,"			//-------------------------------------------------------\n");
			fprintf(outfile,"			pn = %i;\n",1);
			fprintf(outfile,"			\n");
			
			fprintf(outfile,"			for (a = 0; a <= r+onexside; ++a)\n");
			fprintf(outfile,"			{\n");
			if (dBC1Y1d0dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",1,'Y',1,0,0,1,'Y',1,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC1Y1d1dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",1,'Y',1,1,1,1,'Y',1,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC1Y1d2dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",1,'Y',1,2,2,1,'Y',1,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC1Y1d3dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",1,'Y',1,3,3,1,'Y',1,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC1Y1d4dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",1,'Y',1,4,4,1,'Y',1,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC1Y1d5dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",1,'Y',1,5,5,1,'Y',1,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC1Y1d6dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",1,'Y',1,6,6,1,'Y',1,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC1Y1d7dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",1,'Y',1,7,7,1,'Y',1,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			fprintf(outfile,"			}\n");
			
			fprintf(outfile,"			for (b = 0; b <= r+oneyside; ++b)\n");
			fprintf(outfile,"			{\n");
			if (dBC1Y1d0d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",1,'Y',1,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC1Y1d1d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",1,'Y',1,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC1Y1d2d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",1,'Y',1,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC1Y1d3d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",1,'Y',1,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC1Y1d4d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",1,'Y',1,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC1Y1d5d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",1,'Y',1,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC1Y1d6d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",1,'Y',1,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC1Y1d7d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",1,'Y',1,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			fprintf(outfile,"			}\n");
			fprintf(outfile,"			\n");
			
		}
		//-------------------- i = 2 --------------------
		else if (i == 2)
		{
			dBC2Y1d0dX0 = dBC2Y1d0dX0out();
			dBC2Y1d0d0X = dBC2Y1d0d0Xout();
			
			dBC2Y1d1dX0 = dBC2Y1d1dX0out();
			dBC2Y1d1d0X = dBC2Y1d1d0Xout();
			
			dBC2Y1d2dX0 = dBC2Y1d2dX0out();
			dBC2Y1d2d0X = dBC2Y1d2d0Xout();
			
			dBC2Y1d3dX0 = dBC2Y1d3dX0out();
			dBC2Y1d3d0X = dBC2Y1d3d0Xout();
			
			dBC2Y1d4dX0 = dBC2Y1d4dX0out();
			dBC2Y1d4d0X = dBC2Y1d4d0Xout();
			
			dBC2Y1d5dX0 = dBC2Y1d5dX0out();
			dBC2Y1d5d0X = dBC2Y1d5d0Xout();
			
			dBC2Y1d6dX0 = dBC2Y1d6dX0out();
			dBC2Y1d6d0X = dBC2Y1d6d0Xout();
			
			dBC2Y1d7dX0 = dBC2Y1d7dX0out();
			dBC2Y1d7d0X = dBC2Y1d7d0Xout();
			
			fprintf(outfile,"			//-------------------------------------------------------\n");
			fprintf(outfile,"			pn = %i;\n",2);
			fprintf(outfile,"			\n");
			
			fprintf(outfile,"			for (a = 0; a <= r+onexside; ++a)\n");
			fprintf(outfile,"			{\n");
			if (dBC2Y1d0dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",2,'Y',1,0,0,2,'Y',1,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC2Y1d1dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",2,'Y',1,1,1,2,'Y',1,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC2Y1d2dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",2,'Y',1,2,2,2,'Y',1,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC2Y1d3dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",2,'Y',1,3,3,2,'Y',1,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC2Y1d4dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",2,'Y',1,4,4,2,'Y',1,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC2Y1d5dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",2,'Y',1,5,5,2,'Y',1,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC2Y1d6dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",2,'Y',1,6,6,2,'Y',1,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC2Y1d7dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",2,'Y',1,7,7,2,'Y',1,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			fprintf(outfile,"			}\n");
			
			fprintf(outfile,"			for (b = 0; b <= r+oneyside; ++b)\n");
			fprintf(outfile,"			{\n");
			if (dBC2Y1d0d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",2,'Y',1,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC2Y1d1d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",2,'Y',1,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC2Y1d2d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",2,'Y',1,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC2Y1d3d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",2,'Y',1,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC2Y1d4d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",2,'Y',1,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC2Y1d5d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",2,'Y',1,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC2Y1d6d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",2,'Y',1,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC2Y1d7d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",2,'Y',1,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			fprintf(outfile,"			}\n");
			fprintf(outfile,"			\n");
			
		}
		//-------------------- i = 3 --------------------
		else if (i == 3)
		{
			dBC3Y1d0dX0 = dBC3Y1d0dX0out();
			dBC3Y1d0d0X = dBC3Y1d0d0Xout();
			
			dBC3Y1d1dX0 = dBC3Y1d1dX0out();
			dBC3Y1d1d0X = dBC3Y1d1d0Xout();
			
			dBC3Y1d2dX0 = dBC3Y1d2dX0out();
			dBC3Y1d2d0X = dBC3Y1d2d0Xout();
			
			dBC3Y1d3dX0 = dBC3Y1d3dX0out();
			dBC3Y1d3d0X = dBC3Y1d3d0Xout();
			
			dBC3Y1d4dX0 = dBC3Y1d4dX0out();
			dBC3Y1d4d0X = dBC3Y1d4d0Xout();
			
			dBC3Y1d5dX0 = dBC3Y1d5dX0out();
			dBC3Y1d5d0X = dBC3Y1d5d0Xout();
			
			dBC3Y1d6dX0 = dBC3Y1d6dX0out();
			dBC3Y1d6d0X = dBC3Y1d6d0Xout();
			
			dBC3Y1d7dX0 = dBC3Y1d7dX0out();
			dBC3Y1d7d0X = dBC3Y1d7d0Xout();
			
			fprintf(outfile,"			//-------------------------------------------------------\n");
			fprintf(outfile,"			pn = %i;\n",3);
			fprintf(outfile,"			\n");
			
			fprintf(outfile,"			for (a = 0; a <= r+onexside; ++a)\n");
			fprintf(outfile,"			{\n");
			if (dBC3Y1d0dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",3,'Y',1,0,0,3,'Y',1,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC3Y1d1dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",3,'Y',1,1,1,3,'Y',1,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC3Y1d2dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",3,'Y',1,2,2,3,'Y',1,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC3Y1d3dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",3,'Y',1,3,3,3,'Y',1,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC3Y1d4dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",3,'Y',1,4,4,3,'Y',1,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC3Y1d5dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",3,'Y',1,5,5,3,'Y',1,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC3Y1d6dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",3,'Y',1,6,6,3,'Y',1,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC3Y1d7dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",3,'Y',1,7,7,3,'Y',1,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			fprintf(outfile,"			}\n");
			
			fprintf(outfile,"			for (b = 0; b <= r+oneyside; ++b)\n");
			fprintf(outfile,"			{\n");
			if (dBC3Y1d0d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",3,'Y',1,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC3Y1d1d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",3,'Y',1,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC3Y1d2d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",3,'Y',1,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC3Y1d3d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",3,'Y',1,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC3Y1d4d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",3,'Y',1,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC3Y1d5d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",3,'Y',1,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC3Y1d6d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",3,'Y',1,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC3Y1d7d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",3,'Y',1,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			fprintf(outfile,"			}\n");
			fprintf(outfile,"			\n");
			
		}
		//-------------------- i = 4 --------------------
		else if (i == 4)
		{
			dBC4Y1d0dX0 = dBC4Y1d0dX0out();
			dBC4Y1d0d0X = dBC4Y1d0d0Xout();
			
			dBC4Y1d1dX0 = dBC4Y1d1dX0out();
			dBC4Y1d1d0X = dBC4Y1d1d0Xout();
			
			dBC4Y1d2dX0 = dBC4Y1d2dX0out();
			dBC4Y1d2d0X = dBC4Y1d2d0Xout();
			
			dBC4Y1d3dX0 = dBC4Y1d3dX0out();
			dBC4Y1d3d0X = dBC4Y1d3d0Xout();
			
			dBC4Y1d4dX0 = dBC4Y1d4dX0out();
			dBC4Y1d4d0X = dBC4Y1d4d0Xout();
			
			dBC4Y1d5dX0 = dBC4Y1d5dX0out();
			dBC4Y1d5d0X = dBC4Y1d5d0Xout();
			
			dBC4Y1d6dX0 = dBC4Y1d6dX0out();
			dBC4Y1d6d0X = dBC4Y1d6d0Xout();
			
			dBC4Y1d7dX0 = dBC4Y1d7dX0out();
			dBC4Y1d7d0X = dBC4Y1d7d0Xout();
			
			fprintf(outfile,"			//-------------------------------------------------------\n");
			fprintf(outfile,"			pn = %i;\n",4);
			fprintf(outfile,"			\n");
			
			fprintf(outfile,"			for (a = 0; a <= r+onexside; ++a)\n");
			fprintf(outfile,"			{\n");
			if (dBC4Y1d0dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",4,'Y',1,0,0,4,'Y',1,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC4Y1d1dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",4,'Y',1,1,1,4,'Y',1,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC4Y1d2dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",4,'Y',1,2,2,4,'Y',1,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC4Y1d3dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",4,'Y',1,3,3,4,'Y',1,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC4Y1d4dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",4,'Y',1,4,4,4,'Y',1,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC4Y1d5dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",4,'Y',1,5,5,4,'Y',1,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC4Y1d6dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",4,'Y',1,6,6,4,'Y',1,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC4Y1d7dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",4,'Y',1,7,7,4,'Y',1,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			fprintf(outfile,"			}\n");
			
			fprintf(outfile,"			for (b = 0; b <= r+oneyside; ++b)\n");
			fprintf(outfile,"			{\n");
			if (dBC4Y1d0d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",4,'Y',1,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC4Y1d1d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",4,'Y',1,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC4Y1d2d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",4,'Y',1,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC4Y1d3d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",4,'Y',1,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC4Y1d4d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",4,'Y',1,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC4Y1d5d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",4,'Y',1,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC4Y1d6d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",4,'Y',1,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC4Y1d7d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",4,'Y',1,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			fprintf(outfile,"			}\n");
			fprintf(outfile,"			\n");
			
		}
		//-------------------- i = 5 --------------------
		else if (i == 5)
		{
			dBC5Y1d0dX0 = dBC5Y1d0dX0out();
			dBC5Y1d0d0X = dBC5Y1d0d0Xout();
			
			dBC5Y1d1dX0 = dBC5Y1d1dX0out();
			dBC5Y1d1d0X = dBC5Y1d1d0Xout();
			
			dBC5Y1d2dX0 = dBC5Y1d2dX0out();
			dBC5Y1d2d0X = dBC5Y1d2d0Xout();
			
			dBC5Y1d3dX0 = dBC5Y1d3dX0out();
			dBC5Y1d3d0X = dBC5Y1d3d0Xout();
			
			dBC5Y1d4dX0 = dBC5Y1d4dX0out();
			dBC5Y1d4d0X = dBC5Y1d4d0Xout();
			
			dBC5Y1d5dX0 = dBC5Y1d5dX0out();
			dBC5Y1d5d0X = dBC5Y1d5d0Xout();
			
			dBC5Y1d6dX0 = dBC5Y1d6dX0out();
			dBC5Y1d6d0X = dBC5Y1d6d0Xout();
			
			dBC5Y1d7dX0 = dBC5Y1d7dX0out();
			dBC5Y1d7d0X = dBC5Y1d7d0Xout();
			
			fprintf(outfile,"			//-------------------------------------------------------\n");
			fprintf(outfile,"			pn = %i;\n",5);
			fprintf(outfile,"			\n");
			
			fprintf(outfile,"			for (a = 0; a <= r+onexside; ++a)\n");
			fprintf(outfile,"			{\n");
			if (dBC5Y1d0dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",5,'Y',1,0,0,5,'Y',1,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC5Y1d1dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",5,'Y',1,1,1,5,'Y',1,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC5Y1d2dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",5,'Y',1,2,2,5,'Y',1,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC5Y1d3dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",5,'Y',1,3,3,5,'Y',1,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC5Y1d4dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",5,'Y',1,4,4,5,'Y',1,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC5Y1d5dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",5,'Y',1,5,5,5,'Y',1,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC5Y1d6dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",5,'Y',1,6,6,5,'Y',1,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC5Y1d7dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",5,'Y',1,7,7,5,'Y',1,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			fprintf(outfile,"			}\n");
			
			fprintf(outfile,"			for (b = 0; b <= r+oneyside; ++b)\n");
			fprintf(outfile,"			{\n");
			if (dBC5Y1d0d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",5,'Y',1,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC5Y1d1d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",5,'Y',1,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC5Y1d2d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",5,'Y',1,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC5Y1d3d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",5,'Y',1,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC5Y1d4d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",5,'Y',1,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC5Y1d5d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",5,'Y',1,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC5Y1d6d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",5,'Y',1,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC5Y1d7d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",5,'Y',1,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			fprintf(outfile,"			}\n");
			fprintf(outfile,"			\n");
			
		}
		//-------------------- i = 6 --------------------
		else if (i == 6)
		{
			dBC6Y1d0dX0 = dBC6Y1d0dX0out();
			dBC6Y1d0d0X = dBC6Y1d0d0Xout();
			
			dBC6Y1d1dX0 = dBC6Y1d1dX0out();
			dBC6Y1d1d0X = dBC6Y1d1d0Xout();
			
			dBC6Y1d2dX0 = dBC6Y1d2dX0out();
			dBC6Y1d2d0X = dBC6Y1d2d0Xout();
			
			dBC6Y1d3dX0 = dBC6Y1d3dX0out();
			dBC6Y1d3d0X = dBC6Y1d3d0Xout();
			
			dBC6Y1d4dX0 = dBC6Y1d4dX0out();
			dBC6Y1d4d0X = dBC6Y1d4d0Xout();
			
			dBC6Y1d5dX0 = dBC6Y1d5dX0out();
			dBC6Y1d5d0X = dBC6Y1d5d0Xout();
			
			dBC6Y1d6dX0 = dBC6Y1d6dX0out();
			dBC6Y1d6d0X = dBC6Y1d6d0Xout();
			
			dBC6Y1d7dX0 = dBC6Y1d7dX0out();
			dBC6Y1d7d0X = dBC6Y1d7d0Xout();
			
			fprintf(outfile,"			//-------------------------------------------------------\n");
			fprintf(outfile,"			pn = %i;\n",6);
			fprintf(outfile,"			\n");
			
			fprintf(outfile,"			for (a = 0; a <= r+onexside; ++a)\n");
			fprintf(outfile,"			{\n");
			if (dBC6Y1d0dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",6,'Y',1,0,0,6,'Y',1,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC6Y1d1dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",6,'Y',1,1,1,6,'Y',1,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC6Y1d2dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",6,'Y',1,2,2,6,'Y',1,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC6Y1d3dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",6,'Y',1,3,3,6,'Y',1,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC6Y1d4dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",6,'Y',1,4,4,6,'Y',1,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC6Y1d5dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",6,'Y',1,5,5,6,'Y',1,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC6Y1d6dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",6,'Y',1,6,6,6,'Y',1,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC6Y1d7dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",6,'Y',1,7,7,6,'Y',1,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			fprintf(outfile,"			}\n");
			
			fprintf(outfile,"			for (b = 0; b <= r+oneyside; ++b)\n");
			fprintf(outfile,"			{\n");
			if (dBC6Y1d0d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",6,'Y',1,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC6Y1d1d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",6,'Y',1,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC6Y1d2d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",6,'Y',1,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC6Y1d3d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",6,'Y',1,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC6Y1d4d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",6,'Y',1,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC6Y1d5d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",6,'Y',1,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC6Y1d6d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",6,'Y',1,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC6Y1d7d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",6,'Y',1,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			fprintf(outfile,"			}\n");
			fprintf(outfile,"			\n");
			
		}
		//-------------------- i = 7 --------------------
		else if (i == 7)
		{
			dBC7Y1d0dX0 = dBC7Y1d0dX0out();
			dBC7Y1d0d0X = dBC7Y1d0d0Xout();
			
			dBC7Y1d1dX0 = dBC7Y1d1dX0out();
			dBC7Y1d1d0X = dBC7Y1d1d0Xout();
			
			dBC7Y1d2dX0 = dBC7Y1d2dX0out();
			dBC7Y1d2d0X = dBC7Y1d2d0Xout();
			
			dBC7Y1d3dX0 = dBC7Y1d3dX0out();
			dBC7Y1d3d0X = dBC7Y1d3d0Xout();
			
			dBC7Y1d4dX0 = dBC7Y1d4dX0out();
			dBC7Y1d4d0X = dBC7Y1d4d0Xout();
			
			dBC7Y1d5dX0 = dBC7Y1d5dX0out();
			dBC7Y1d5d0X = dBC7Y1d5d0Xout();
			
			dBC7Y1d6dX0 = dBC7Y1d6dX0out();
			dBC7Y1d6d0X = dBC7Y1d6d0Xout();
			
			dBC7Y1d7dX0 = dBC7Y1d7dX0out();
			dBC7Y1d7d0X = dBC7Y1d7d0Xout();
			
			fprintf(outfile,"			//-------------------------------------------------------\n");
			fprintf(outfile,"			pn = %i;\n",7);
			fprintf(outfile,"			\n");
			
			fprintf(outfile,"			for (a = 0; a <= r+onexside; ++a)\n");
			fprintf(outfile,"			{\n");
			if (dBC7Y1d0dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",7,'Y',1,0,0,7,'Y',1,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC7Y1d1dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",7,'Y',1,1,1,7,'Y',1,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC7Y1d2dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",7,'Y',1,2,2,7,'Y',1,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC7Y1d3dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",7,'Y',1,3,3,7,'Y',1,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC7Y1d4dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",7,'Y',1,4,4,7,'Y',1,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC7Y1d5dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",7,'Y',1,5,5,7,'Y',1,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC7Y1d6dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",7,'Y',1,6,6,7,'Y',1,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC7Y1d7dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",7,'Y',1,7,7,7,'Y',1,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			fprintf(outfile,"			}\n");
			
			fprintf(outfile,"			for (b = 0; b <= r+oneyside; ++b)\n");
			fprintf(outfile,"			{\n");
			if (dBC7Y1d0d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",7,'Y',1,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC7Y1d1d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",7,'Y',1,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC7Y1d2d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",7,'Y',1,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC7Y1d3d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",7,'Y',1,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC7Y1d4d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",7,'Y',1,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC7Y1d5d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",7,'Y',1,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC7Y1d6d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",7,'Y',1,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC7Y1d7d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",7,'Y',1,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			fprintf(outfile,"			}\n");
			fprintf(outfile,"			\n");
			
		}
		else
		{
			printf("ERROR!! In CodeGen_NNZ.c, %i does not match number of field equations.\n",i);
			return -1;
		}
		
	}
	//:::::::::::::::::::: Y0 ::::::::::::::::::::
	else if (bc == 3)
	{
		//-------------------- i = 0 --------------------
		if (i == 0)
		{
			dBC0Y0d0dX0 = dBC0Y0d0dX0out();
			dBC0Y0d0d0X = dBC0Y0d0d0Xout();
			
			dBC0Y0d1dX0 = dBC0Y0d1dX0out();
			dBC0Y0d1d0X = dBC0Y0d1d0Xout();
			
			dBC0Y0d2dX0 = dBC0Y0d2dX0out();
			dBC0Y0d2d0X = dBC0Y0d2d0Xout();
			
			dBC0Y0d3dX0 = dBC0Y0d3dX0out();
			dBC0Y0d3d0X = dBC0Y0d3d0Xout();
			
			dBC0Y0d4dX0 = dBC0Y0d4dX0out();
			dBC0Y0d4d0X = dBC0Y0d4d0Xout();
			
			dBC0Y0d5dX0 = dBC0Y0d5dX0out();
			dBC0Y0d5d0X = dBC0Y0d5d0Xout();
			
			dBC0Y0d6dX0 = dBC0Y0d6dX0out();
			dBC0Y0d6d0X = dBC0Y0d6d0Xout();
			
			dBC0Y0d7dX0 = dBC0Y0d7dX0out();
			dBC0Y0d7d0X = dBC0Y0d7d0Xout();
			
			fprintf(outfile,"			//-------------------------------------------------------\n");
			fprintf(outfile,"			pn = %i;\n",0);
			fprintf(outfile,"			\n");
			
			fprintf(outfile,"			for (a = 0; a <= r+onexside; ++a)\n");
			fprintf(outfile,"			{\n");
			if (dBC0Y0d0dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",0,'Y',0,0,0,0,'Y',0,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC0Y0d1dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",0,'Y',0,1,1,0,'Y',0,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC0Y0d2dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",0,'Y',0,2,2,0,'Y',0,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC0Y0d3dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",0,'Y',0,3,3,0,'Y',0,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC0Y0d4dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",0,'Y',0,4,4,0,'Y',0,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC0Y0d5dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",0,'Y',0,5,5,0,'Y',0,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC0Y0d6dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",0,'Y',0,6,6,0,'Y',0,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC0Y0d7dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",0,'Y',0,7,7,0,'Y',0,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			fprintf(outfile,"			}\n");
			
			fprintf(outfile,"			for (b = 0; b <= r+oneyside; ++b)\n");
			fprintf(outfile,"			{\n");
			if (dBC0Y0d0d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",0,'Y',0,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC0Y0d1d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",0,'Y',0,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC0Y0d2d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",0,'Y',0,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC0Y0d3d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",0,'Y',0,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC0Y0d4d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",0,'Y',0,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC0Y0d5d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",0,'Y',0,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC0Y0d6d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",0,'Y',0,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC0Y0d7d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",0,'Y',0,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			fprintf(outfile,"			}\n");
			fprintf(outfile,"			\n");
			
		}
		//-------------------- i = 1 --------------------
		else if (i == 1)
		{
			dBC1Y0d0dX0 = dBC1Y0d0dX0out();
			dBC1Y0d0d0X = dBC1Y0d0d0Xout();
			
			dBC1Y0d1dX0 = dBC1Y0d1dX0out();
			dBC1Y0d1d0X = dBC1Y0d1d0Xout();
			
			dBC1Y0d2dX0 = dBC1Y0d2dX0out();
			dBC1Y0d2d0X = dBC1Y0d2d0Xout();
			
			dBC1Y0d3dX0 = dBC1Y0d3dX0out();
			dBC1Y0d3d0X = dBC1Y0d3d0Xout();
			
			dBC1Y0d4dX0 = dBC1Y0d4dX0out();
			dBC1Y0d4d0X = dBC1Y0d4d0Xout();
			
			dBC1Y0d5dX0 = dBC1Y0d5dX0out();
			dBC1Y0d5d0X = dBC1Y0d5d0Xout();
			
			dBC1Y0d6dX0 = dBC1Y0d6dX0out();
			dBC1Y0d6d0X = dBC1Y0d6d0Xout();
			
			dBC1Y0d7dX0 = dBC1Y0d7dX0out();
			dBC1Y0d7d0X = dBC1Y0d7d0Xout();
			
			fprintf(outfile,"			//-------------------------------------------------------\n");
			fprintf(outfile,"			pn = %i;\n",1);
			fprintf(outfile,"			\n");
			
			fprintf(outfile,"			for (a = 0; a <= r+onexside; ++a)\n");
			fprintf(outfile,"			{\n");
			if (dBC1Y0d0dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",1,'Y',0,0,0,1,'Y',0,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC1Y0d1dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",1,'Y',0,1,1,1,'Y',0,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC1Y0d2dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",1,'Y',0,2,2,1,'Y',0,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC1Y0d3dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",1,'Y',0,3,3,1,'Y',0,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC1Y0d4dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",1,'Y',0,4,4,1,'Y',0,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC1Y0d5dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",1,'Y',0,5,5,1,'Y',0,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC1Y0d6dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",1,'Y',0,6,6,1,'Y',0,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC1Y0d7dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",1,'Y',0,7,7,1,'Y',0,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			fprintf(outfile,"			}\n");
			
			fprintf(outfile,"			for (b = 0; b <= r+oneyside; ++b)\n");
			fprintf(outfile,"			{\n");
			if (dBC1Y0d0d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",1,'Y',0,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC1Y0d1d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",1,'Y',0,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC1Y0d2d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",1,'Y',0,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC1Y0d3d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",1,'Y',0,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC1Y0d4d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",1,'Y',0,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC1Y0d5d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",1,'Y',0,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC1Y0d6d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",1,'Y',0,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC1Y0d7d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",1,'Y',0,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			fprintf(outfile,"			}\n");
			fprintf(outfile,"			\n");
			
		}
		//-------------------- i = 2 --------------------
		else if (i == 2)
		{
			dBC2Y0d0dX0 = dBC2Y0d0dX0out();
			dBC2Y0d0d0X = dBC2Y0d0d0Xout();
			
			dBC2Y0d1dX0 = dBC2Y0d1dX0out();
			dBC2Y0d1d0X = dBC2Y0d1d0Xout();
			
			dBC2Y0d2dX0 = dBC2Y0d2dX0out();
			dBC2Y0d2d0X = dBC2Y0d2d0Xout();
			
			dBC2Y0d3dX0 = dBC2Y0d3dX0out();
			dBC2Y0d3d0X = dBC2Y0d3d0Xout();
			
			dBC2Y0d4dX0 = dBC2Y0d4dX0out();
			dBC2Y0d4d0X = dBC2Y0d4d0Xout();
			
			dBC2Y0d5dX0 = dBC2Y0d5dX0out();
			dBC2Y0d5d0X = dBC2Y0d5d0Xout();
			
			dBC2Y0d6dX0 = dBC2Y0d6dX0out();
			dBC2Y0d6d0X = dBC2Y0d6d0Xout();
			
			dBC2Y0d7dX0 = dBC2Y0d7dX0out();
			dBC2Y0d7d0X = dBC2Y0d7d0Xout();
			
			fprintf(outfile,"			//-------------------------------------------------------\n");
			fprintf(outfile,"			pn = %i;\n",2);
			fprintf(outfile,"			\n");
			
			fprintf(outfile,"			for (a = 0; a <= r+onexside; ++a)\n");
			fprintf(outfile,"			{\n");
			if (dBC2Y0d0dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",2,'Y',0,0,0,2,'Y',0,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC2Y0d1dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",2,'Y',0,1,1,2,'Y',0,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC2Y0d2dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",2,'Y',0,2,2,2,'Y',0,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC2Y0d3dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",2,'Y',0,3,3,2,'Y',0,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC2Y0d4dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",2,'Y',0,4,4,2,'Y',0,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC2Y0d5dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",2,'Y',0,5,5,2,'Y',0,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC2Y0d6dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",2,'Y',0,6,6,2,'Y',0,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC2Y0d7dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",2,'Y',0,7,7,2,'Y',0,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			fprintf(outfile,"			}\n");
			
			fprintf(outfile,"			for (b = 0; b <= r+oneyside; ++b)\n");
			fprintf(outfile,"			{\n");
			if (dBC2Y0d0d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",2,'Y',0,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC2Y0d1d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",2,'Y',0,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC2Y0d2d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",2,'Y',0,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC2Y0d3d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",2,'Y',0,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC2Y0d4d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",2,'Y',0,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC2Y0d5d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",2,'Y',0,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC2Y0d6d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",2,'Y',0,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC2Y0d7d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",2,'Y',0,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			fprintf(outfile,"			}\n");
			fprintf(outfile,"			\n");
			
		}
		//-------------------- i = 3 --------------------
		else if (i == 3)
		{
			dBC3Y0d0dX0 = dBC3Y0d0dX0out();
			dBC3Y0d0d0X = dBC3Y0d0d0Xout();
			
			dBC3Y0d1dX0 = dBC3Y0d1dX0out();
			dBC3Y0d1d0X = dBC3Y0d1d0Xout();
			
			dBC3Y0d2dX0 = dBC3Y0d2dX0out();
			dBC3Y0d2d0X = dBC3Y0d2d0Xout();
			
			dBC3Y0d3dX0 = dBC3Y0d3dX0out();
			dBC3Y0d3d0X = dBC3Y0d3d0Xout();
			
			dBC3Y0d4dX0 = dBC3Y0d4dX0out();
			dBC3Y0d4d0X = dBC3Y0d4d0Xout();
			
			dBC3Y0d5dX0 = dBC3Y0d5dX0out();
			dBC3Y0d5d0X = dBC3Y0d5d0Xout();
			
			dBC3Y0d6dX0 = dBC3Y0d6dX0out();
			dBC3Y0d6d0X = dBC3Y0d6d0Xout();
			
			dBC3Y0d7dX0 = dBC3Y0d7dX0out();
			dBC3Y0d7d0X = dBC3Y0d7d0Xout();
			
			fprintf(outfile,"			//-------------------------------------------------------\n");
			fprintf(outfile,"			pn = %i;\n",3);
			fprintf(outfile,"			\n");
			
			fprintf(outfile,"			for (a = 0; a <= r+onexside; ++a)\n");
			fprintf(outfile,"			{\n");
			if (dBC3Y0d0dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",3,'Y',0,0,0,3,'Y',0,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC3Y0d1dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",3,'Y',0,1,1,3,'Y',0,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC3Y0d2dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",3,'Y',0,2,2,3,'Y',0,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC3Y0d3dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",3,'Y',0,3,3,3,'Y',0,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC3Y0d4dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",3,'Y',0,4,4,3,'Y',0,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC3Y0d5dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",3,'Y',0,5,5,3,'Y',0,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC3Y0d6dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",3,'Y',0,6,6,3,'Y',0,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC3Y0d7dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",3,'Y',0,7,7,3,'Y',0,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			fprintf(outfile,"			}\n");
			
			fprintf(outfile,"			for (b = 0; b <= r+oneyside; ++b)\n");
			fprintf(outfile,"			{\n");
			if (dBC3Y0d0d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",3,'Y',0,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC3Y0d1d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",3,'Y',0,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC3Y0d2d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",3,'Y',0,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC3Y0d3d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",3,'Y',0,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC3Y0d4d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",3,'Y',0,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC3Y0d5d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",3,'Y',0,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC3Y0d6d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",3,'Y',0,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC3Y0d7d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",3,'Y',0,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			fprintf(outfile,"			}\n");
			fprintf(outfile,"			\n");
			
		}
		//-------------------- i = 4 --------------------
		else if (i == 4)
		{
			dBC4Y0d0dX0 = dBC4Y0d0dX0out();
			dBC4Y0d0d0X = dBC4Y0d0d0Xout();
			
			dBC4Y0d1dX0 = dBC4Y0d1dX0out();
			dBC4Y0d1d0X = dBC4Y0d1d0Xout();
			
			dBC4Y0d2dX0 = dBC4Y0d2dX0out();
			dBC4Y0d2d0X = dBC4Y0d2d0Xout();
			
			dBC4Y0d3dX0 = dBC4Y0d3dX0out();
			dBC4Y0d3d0X = dBC4Y0d3d0Xout();
			
			dBC4Y0d4dX0 = dBC4Y0d4dX0out();
			dBC4Y0d4d0X = dBC4Y0d4d0Xout();
			
			dBC4Y0d5dX0 = dBC4Y0d5dX0out();
			dBC4Y0d5d0X = dBC4Y0d5d0Xout();
			
			dBC4Y0d6dX0 = dBC4Y0d6dX0out();
			dBC4Y0d6d0X = dBC4Y0d6d0Xout();
			
			dBC4Y0d7dX0 = dBC4Y0d7dX0out();
			dBC4Y0d7d0X = dBC4Y0d7d0Xout();
			
			fprintf(outfile,"			//-------------------------------------------------------\n");
			fprintf(outfile,"			pn = %i;\n",4);
			fprintf(outfile,"			\n");
			
			fprintf(outfile,"			for (a = 0; a <= r+onexside; ++a)\n");
			fprintf(outfile,"			{\n");
			if (dBC4Y0d0dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",4,'Y',0,0,0,4,'Y',0,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC4Y0d1dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",4,'Y',0,1,1,4,'Y',0,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC4Y0d2dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",4,'Y',0,2,2,4,'Y',0,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC4Y0d3dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",4,'Y',0,3,3,4,'Y',0,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC4Y0d4dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",4,'Y',0,4,4,4,'Y',0,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC4Y0d5dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",4,'Y',0,5,5,4,'Y',0,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC4Y0d6dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",4,'Y',0,6,6,4,'Y',0,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC4Y0d7dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",4,'Y',0,7,7,4,'Y',0,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			fprintf(outfile,"			}\n");
			
			fprintf(outfile,"			for (b = 0; b <= r+oneyside; ++b)\n");
			fprintf(outfile,"			{\n");
			if (dBC4Y0d0d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",4,'Y',0,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC4Y0d1d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",4,'Y',0,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC4Y0d2d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",4,'Y',0,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC4Y0d3d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",4,'Y',0,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC4Y0d4d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",4,'Y',0,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC4Y0d5d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",4,'Y',0,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC4Y0d6d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",4,'Y',0,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC4Y0d7d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",4,'Y',0,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			fprintf(outfile,"			}\n");
			fprintf(outfile,"			\n");
			
		}
		//-------------------- i = 5 --------------------
		else if (i == 5)
		{
			dBC5Y0d0dX0 = dBC5Y0d0dX0out();
			dBC5Y0d0d0X = dBC5Y0d0d0Xout();
			
			dBC5Y0d1dX0 = dBC5Y0d1dX0out();
			dBC5Y0d1d0X = dBC5Y0d1d0Xout();
			
			dBC5Y0d2dX0 = dBC5Y0d2dX0out();
			dBC5Y0d2d0X = dBC5Y0d2d0Xout();
			
			dBC5Y0d3dX0 = dBC5Y0d3dX0out();
			dBC5Y0d3d0X = dBC5Y0d3d0Xout();
			
			dBC5Y0d4dX0 = dBC5Y0d4dX0out();
			dBC5Y0d4d0X = dBC5Y0d4d0Xout();
			
			dBC5Y0d5dX0 = dBC5Y0d5dX0out();
			dBC5Y0d5d0X = dBC5Y0d5d0Xout();
			
			dBC5Y0d6dX0 = dBC5Y0d6dX0out();
			dBC5Y0d6d0X = dBC5Y0d6d0Xout();
			
			dBC5Y0d7dX0 = dBC5Y0d7dX0out();
			dBC5Y0d7d0X = dBC5Y0d7d0Xout();
			
			fprintf(outfile,"			//-------------------------------------------------------\n");
			fprintf(outfile,"			pn = %i;\n",5);
			fprintf(outfile,"			\n");
			
			fprintf(outfile,"			for (a = 0; a <= r+onexside; ++a)\n");
			fprintf(outfile,"			{\n");
			if (dBC5Y0d0dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",5,'Y',0,0,0,5,'Y',0,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC5Y0d1dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",5,'Y',0,1,1,5,'Y',0,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC5Y0d2dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",5,'Y',0,2,2,5,'Y',0,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC5Y0d3dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",5,'Y',0,3,3,5,'Y',0,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC5Y0d4dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",5,'Y',0,4,4,5,'Y',0,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC5Y0d5dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",5,'Y',0,5,5,5,'Y',0,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC5Y0d6dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",5,'Y',0,6,6,5,'Y',0,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC5Y0d7dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",5,'Y',0,7,7,5,'Y',0,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			fprintf(outfile,"			}\n");
			
			fprintf(outfile,"			for (b = 0; b <= r+oneyside; ++b)\n");
			fprintf(outfile,"			{\n");
			if (dBC5Y0d0d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",5,'Y',0,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC5Y0d1d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",5,'Y',0,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC5Y0d2d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",5,'Y',0,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC5Y0d3d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",5,'Y',0,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC5Y0d4d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",5,'Y',0,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC5Y0d5d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",5,'Y',0,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC5Y0d6d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",5,'Y',0,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC5Y0d7d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",5,'Y',0,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			fprintf(outfile,"			}\n");
			fprintf(outfile,"			\n");
			
		}
		//-------------------- i = 6 --------------------
		else if (i == 6)
		{
			dBC6Y0d0dX0 = dBC6Y0d0dX0out();
			dBC6Y0d0d0X = dBC6Y0d0d0Xout();
			
			dBC6Y0d1dX0 = dBC6Y0d1dX0out();
			dBC6Y0d1d0X = dBC6Y0d1d0Xout();
			
			dBC6Y0d2dX0 = dBC6Y0d2dX0out();
			dBC6Y0d2d0X = dBC6Y0d2d0Xout();
			
			dBC6Y0d3dX0 = dBC6Y0d3dX0out();
			dBC6Y0d3d0X = dBC6Y0d3d0Xout();
			
			dBC6Y0d4dX0 = dBC6Y0d4dX0out();
			dBC6Y0d4d0X = dBC6Y0d4d0Xout();
			
			dBC6Y0d5dX0 = dBC6Y0d5dX0out();
			dBC6Y0d5d0X = dBC6Y0d5d0Xout();
			
			dBC6Y0d6dX0 = dBC6Y0d6dX0out();
			dBC6Y0d6d0X = dBC6Y0d6d0Xout();
			
			dBC6Y0d7dX0 = dBC6Y0d7dX0out();
			dBC6Y0d7d0X = dBC6Y0d7d0Xout();
			
			fprintf(outfile,"			//-------------------------------------------------------\n");
			fprintf(outfile,"			pn = %i;\n",6);
			fprintf(outfile,"			\n");
			
			fprintf(outfile,"			for (a = 0; a <= r+onexside; ++a)\n");
			fprintf(outfile,"			{\n");
			if (dBC6Y0d0dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",6,'Y',0,0,0,6,'Y',0,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC6Y0d1dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",6,'Y',0,1,1,6,'Y',0,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC6Y0d2dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",6,'Y',0,2,2,6,'Y',0,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC6Y0d3dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",6,'Y',0,3,3,6,'Y',0,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC6Y0d4dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",6,'Y',0,4,4,6,'Y',0,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC6Y0d5dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",6,'Y',0,5,5,6,'Y',0,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC6Y0d6dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",6,'Y',0,6,6,6,'Y',0,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC6Y0d7dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",6,'Y',0,7,7,6,'Y',0,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			fprintf(outfile,"			}\n");
			
			fprintf(outfile,"			for (b = 0; b <= r+oneyside; ++b)\n");
			fprintf(outfile,"			{\n");
			if (dBC6Y0d0d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",6,'Y',0,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC6Y0d1d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",6,'Y',0,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC6Y0d2d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",6,'Y',0,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC6Y0d3d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",6,'Y',0,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC6Y0d4d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",6,'Y',0,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC6Y0d5d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",6,'Y',0,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC6Y0d6d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",6,'Y',0,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC6Y0d7d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",6,'Y',0,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			fprintf(outfile,"			}\n");
			fprintf(outfile,"			\n");
			
		}
		//-------------------- i = 7 --------------------
		else if (i == 7)
		{
			dBC7Y0d0dX0 = dBC7Y0d0dX0out();
			dBC7Y0d0d0X = dBC7Y0d0d0Xout();
			
			dBC7Y0d1dX0 = dBC7Y0d1dX0out();
			dBC7Y0d1d0X = dBC7Y0d1d0Xout();
			
			dBC7Y0d2dX0 = dBC7Y0d2dX0out();
			dBC7Y0d2d0X = dBC7Y0d2d0Xout();
			
			dBC7Y0d3dX0 = dBC7Y0d3dX0out();
			dBC7Y0d3d0X = dBC7Y0d3d0Xout();
			
			dBC7Y0d4dX0 = dBC7Y0d4dX0out();
			dBC7Y0d4d0X = dBC7Y0d4d0Xout();
			
			dBC7Y0d5dX0 = dBC7Y0d5dX0out();
			dBC7Y0d5d0X = dBC7Y0d5d0Xout();
			
			dBC7Y0d6dX0 = dBC7Y0d6dX0out();
			dBC7Y0d6d0X = dBC7Y0d6d0Xout();
			
			dBC7Y0d7dX0 = dBC7Y0d7dX0out();
			dBC7Y0d7d0X = dBC7Y0d7d0Xout();
			
			fprintf(outfile,"			//-------------------------------------------------------\n");
			fprintf(outfile,"			pn = %i;\n",7);
			fprintf(outfile,"			\n");
			
			fprintf(outfile,"			for (a = 0; a <= r+onexside; ++a)\n");
			fprintf(outfile,"			{\n");
			if (dBC7Y0d0dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",7,'Y',0,0,0,7,'Y',0,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC7Y0d1dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",7,'Y',0,1,1,7,'Y',0,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC7Y0d2dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",7,'Y',0,2,2,7,'Y',0,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC7Y0d3dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",7,'Y',0,3,3,7,'Y',0,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC7Y0d4dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",7,'Y',0,4,4,7,'Y',0,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC7Y0d5dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",7,'Y',0,5,5,7,'Y',0,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC7Y0d6dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",7,'Y',0,6,6,7,'Y',0,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			if (dBC7Y0d7dX0 != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id00*a%id0[a] + dBC%i%c%id%id10*a%id1[a];\n",7,'Y',0,7,7,7,'Y',0,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = (I*n +J+sx[a])*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
				fprintf(outfile,"				\n");
			}
			fprintf(outfile,"			}\n");
			
			fprintf(outfile,"			for (b = 0; b <= r+oneyside; ++b)\n");
			fprintf(outfile,"			{\n");
			if (dBC7Y0d0d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",7,'Y',0,0,0);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",0);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC7Y0d1d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",7,'Y',0,1,1);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",1);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC7Y0d2d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",7,'Y',0,2,2);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",2);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC7Y0d3d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",7,'Y',0,3,3);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",3);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC7Y0d4d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",7,'Y',0,4,4);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",4);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC7Y0d5d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",7,'Y',0,5,5);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",5);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC7Y0d6d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",7,'Y',0,6,6);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",6);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			if (dBC7Y0d7d0X != 0)
			{
				fprintf(outfile,"				JacVal[nnztemp] = dBC%i%c%id%id01*b%id1[b];\n",7,'Y',0,7,7);
				fprintf(outfile,"				JacRow[nnztemp] = (k +pn);\n");
				fprintf(outfile,"				JacCol[nnztemp] = ((I+sy[b])*n +J)*p +%i;\n",7);
				fprintf(outfile,"				nnztemp += 1;\n");
			}
			fprintf(outfile,"			}\n");
			fprintf(outfile,"			\n");
			
		}
		else
		{
			printf("ERROR!! In CodeGen_NNZ.c, %i does not match number of field equations.\n",i);
			return -1;
		}
		
	}
	else
	{
		printf("ERROR!! In CodeGen_NNZ.c, %i does not match number of boundary conditions.\n",bc);
		return -1;
	}
	
	
	return 0;
}




