#include <iostream>
#include <cmath>


using namespace std;


// Fatoração A = LU
void fatorarMatriz(float *a, float *l, float *u, int t)
{
	float pivo;
	float m;

	// coloca 1 em toda a diagonal de L
	for(int c=0; c<t; c++)
	{
		l[t*c+c] = 1;
	}

	for(int k=0; k<=2; k++)
	{
		pivo = u[t*k+k];

		for(int c=k+1; c<t; c++)
		{
			m = u[t*c+k] / pivo;

		//	atualiza a linha da forma lk = lk - mk*l(k-1)
			for(int d=0; d<t; d++)
			{
				u[t*c+d] = u[t*c+d] - m*(u[t*k+d]);
			}

		//	adiciona o multiplicador a matriz L
			l[t*c+k] = m;
		}
	}
	
}

	/****************************

		representando uma matriz como um vetor:

		sendo t:= tamanho da matriz quadrada, i:= linha, j:= coluna
		A:= matriz, a:= vetor:

		A[i,j] = a[ t*i + j ] 

	****************************/
int main(int argc, char const *argv[])
{
	float *l, *u, *a;
	int size = 3;

	l = (float*)calloc(pow(size,2), sizeof(float));
	u = (float*)calloc(pow(size,2), sizeof(float));
	a = (float*)calloc(pow(size,2), sizeof(float));

	a[size*0+0]= 20 ; a[size*0+1] = 7 ; a[size*0+2] = 9;
	a[size*1+0] = 7 ; a[size*1+1] = 30; a[size*1+2] = 8;
	a[size*2+0] = 9 ; a[size*2+1] = 8 ; a[size*2+2] = 30;


	/*a = { {20,7 ,9 } ,
	  	  	{7 ,30,8 } ,
		  	{9 ,8 ,30} };*/

	// u = a
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			u[size*i + j] = a[size*i + j];
		}
	}

	fatorarMatriz(a,l,u,size);

	cout<<"matriz A:"<<endl;
	for(int c=0; c<size; c++)
	{
		cout<< a[3*c + 0] << " | " << a[3*c + 1] << " | " << a[3*c + 2] << endl; 
	}
	cout<<"======"<<endl;

	cout<<"matriz U:"<<endl;
	for(int c=0; c<size; c++)
	{
		cout<< u[3*c + 0] << " | " << u[3*c + 1] << " | " << u[3*c + 2] << endl; 
	}
	cout<<"======"<<endl;

	cout<<"matriz L:"<<endl;
	for(int c=0; c<size; c++)
	{
		cout<< l[3*c + 0] << " | " << l[3*c + 1] << " | " << l[3*c + 2] << endl; 
	}
	cout<<"======"<<endl;
	
}