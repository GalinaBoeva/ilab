#include <stdio.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
const int S = 1;          
const int L1 = 20;        
const int L2 = 30;       
const int L3 = 50;        
const int NMeas1 = 12;   
const int NMeas2 = 24;    
const int NMeas3 = 36;    
const int Imax = 300;     
const int Imin = 0;       
const int Umax = 600;     
const int Umin = 0;       


int calcul ();
void Reader (float U[], float I[], int num, FILE* input);

int main ()
    {
    printf (" laba 1.1.1 - measurement of resistivity \n");
    printf (" Data is written to a file ''laba1.txt'' \n");
    int correct = calcul ();
    if (correct !=0)
		{
		printf ("ERROR in file in line %d\n",correct);
		}
    }
//=============================================================================

int calcul ()
    {
    int size = NMeas3;
     
    float* U = (float*)calloc (size,sizeof(float));
	float* I = (float*)calloc (size,sizeof(float));
	
    

	

    FILE*  input = fopen ("laba1.txt",  "r");
    FILE*  output = fopen ("labka.txt", "w");

   int num = NMeas3;

    Reader (U, I, num, input);
    for (int line = 0; line < NMeas3; line++)
        {

        if ((U[line] <= 0) || (I[line] <= 0) || (U[line] > Umax) || (I[line] > Imax))
            {
            return (line + 1);
            }
        }

    fprintf (output, " Resistivity for %dcm\n", L1);
    for (int i = 1; i <= NMeas1; i++)
        {

        float resistivity = (U[i] * S) / (I[i] * L1);
        fprintf (output, "%d)  ", i);
        fprintf (output, "%4.2f", resistivity);
        fprintf (output, " * 10^(-3) Om*cm^2\n");

        }


    fprintf (output, "\n Resistivity for %dcm\n", L2);
    for (int i = 13; i <= NMeas2; i++)
        {

        float resistivity = (U[i] * S) / (I[i] * L2);
        fprintf (output, "%d)  ", i);
        fprintf (output, "%4.2f", resistivity);
        fprintf (output, " * 10^(-3) Om*cm^2\n");

        }


    fprintf (output, "\n Resistivity for %dcm\n", L3);
    for (int i = 25; i <= NMeas3; i++)
        {

        float resistivity = (U[i] * S) / (I[i] * L3);
        fprintf (output, "%d)  ", i);
        fprintf (output, "%4.2f", resistivity);
        fprintf (output, " * 10^(-3) Om*cm^2\n");

        }

    return (0);

    }
 
void Reader (float U[], float I[], int num, FILE* input)
    {
    for (int line = 0; line < num; line++)
        {
        assert ((0 <= line) && (line <= num));

        fscanf (input, "%f %f", &U[line], &I[line]);
        }
    }


